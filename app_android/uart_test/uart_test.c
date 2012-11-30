#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

/*******************************************
 *  获得端口名称
********************************************/
#define TTY_DEV "/dev/tcc-uart"

char *get_ptty(unsigned int port)
{
    char *ptty;

    switch(port)
    {
    case 0:
    {
        ptty = TTY_DEV"0";
    }
    break;
    case 1:
    {
        ptty = TTY_DEV"1";
    }
    break;
    case 2:
    {
        ptty = TTY_DEV"2";
    }
    break;
    case 3:
    {
        ptty = TTY_DEV"3";
    }
    break;
    case 4:
    {
        ptty = TTY_DEV"4";
    }
    break;
    case 5:
    {
        ptty = TTY_DEV"5";
    }
    break;
    }
    return(ptty);
}

/*******************************************
 *  波特率转换函数（请确认是否正确）
********************************************/
int convbaud(unsigned int baudrate)
{
    switch(baudrate)
    {
    case 2400:
        return B2400;
    case 4800:
        return B4800;
    case 9600:
        return B9600;
    case 19200:
        return B19200;
    case 38400:
        return B38400;
    case 57600:
        return B57600;
    case 115200:
        return B115200;
    default:
        return B9600;
    }
}



//./uart_test 3 38400

int main(int argc , char **argv)
{
    int fd, len = 0;
    unsigned char buff[1024];
    struct termios oldtio;
    unsigned int port, baud;
    char *ptty;

    printf("Uart Init -16-\n");
    //////////////////////////////
    port = strtoul(argv[1], 0, 0);
    baud = strtoul(argv[2], 0, 0);
    printf("port = %d\n", port);
    printf("baud = %d\n", baud);

    //if(!strcmp(argv[1]) ,"on")
    //////////////////////////////


    ptty = get_ptty(port);
    printf("ptty = %s\n", ptty);

    fd = open( ptty, O_RDWR | O_NOCTTY/*|O_NDELAY*/);
    if (fd == (-1))
    {
        perror("Can't Open Uart\n");
        return 0;
    }
    else
        printf("Open Uart Success !\n");


    if (tcgetattr(fd, &oldtio) != 0)
    {
        perror("tcgetattr fail!\n");
        return 0;
    }

    cfsetispeed(&oldtio, convbaud(baud));
    cfsetospeed(&oldtio, convbaud(baud));

    oldtio.c_cflag |= CS8;//8 bit
    oldtio.c_cflag &= ~CSTOPB;// 1 stop
    oldtio.c_cflag &= ~PARENB;//N
    oldtio.c_lflag &= ~(ICANON | ECHO | ECHOE);//


    tcflush(fd, TCIFLUSH);
    if((tcsetattr(fd, TCSANOW, &oldtio)) != 0)
    {
        perror("tcsetattr fail!\n");
        return 0;
    }



    while(1)
    {
        len = write(fd, buff, 1024);
        usleep(1000 * 100); //100ms
    }

    close(fd);
    return 0;
}
