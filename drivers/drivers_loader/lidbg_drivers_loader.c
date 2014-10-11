#include "lidbg.h"


static LIST_HEAD(lidbg_list);
static LIST_HEAD(flyaudio_list);

bool analyze_list_cmd(struct list_head *client_list)
{
    struct string_dev *pos;
    char *cmd[8] = {NULL};
    int cmd_num  = 0, tsleep = 0;

    if (list_empty(client_list))
    {
        LIDBG_ERR("<list_is_empty>\n");
        return false;
    }

    list_for_each_entry(pos, client_list, tmp_list)
    {
        if(pos->yourkey)
        {
            if(strlen(pos->yourkey) < 3)
                goto drop;

            if(strncmp(pos->yourkey, "msleep", sizeof("msleep") - 1) == 0)
            {
                cmd_num = lidbg_token_string(pos->yourkey, " ", cmd) ;
                if(cmd_num == 2)
                {
                    tsleep = simple_strtoul(cmd[1], 0, 0);
                    msleep(tsleep);
                    LIDBG_WARN("msleep<%d,%d>\n", cmd_num, tsleep);
                }
                else
                    goto drop;
            }
#ifdef SOC_msm8x25
            else if(strncmp(pos->yourkey, "cp", sizeof("cp") - 1) == 0)
            {
                cmd_num = lidbg_token_string(pos->yourkey, " ", cmd) ;
                if(cmd_num == 3)
                {
                    LIDBG_WARN("cp <%s,%s>\n", cmd[1], cmd[2]);
                    fs_copy_file(cmd[1], cmd[2]);
                }
                else
                    goto drop;
            }
#endif
            else
        	{
        		msleep(100);
        		lidbg_shell_cmd(pos->yourkey);
			}
                
            continue;
drop:
            LIDBG_WARN("bad cmd<%s>\n", pos->yourkey);
        }
    }

    return true;
}

static int thread_drivers_loader_analyze(void *data)
{
    char buff[50] = {0};

    if(fs_is_file_exist(FLY_MODE_FILE))
    {
        fs_fill_list(get_lidbg_file_path(buff, "flyaudio.init.rc.conf"), FS_CMD_FILE_LISTMODE, &flyaudio_list);
        analyze_list_cmd(&flyaudio_list);
    }
    else
    {
        fs_fill_list(get_lidbg_file_path(buff, "lidbg.init.rc.conf"), FS_CMD_FILE_LISTMODE, &lidbg_list);
        analyze_list_cmd(&lidbg_list);
    }
    ssleep(30);//later,exit
    return 0;
}
static int __init lidbg_drivers_loader_init(void)
{

    DUMP_FUN;
    LIDBG_WARN("<==IN==>\n");
    CREATE_KTHREAD(thread_drivers_loader_analyze, NULL);
    LIDBG_MODULE_LOG;
    LIDBG_WARN("<==OUT==>\n\n");
    return 0;
}
static void __exit lidbg_drivers_loader_exit(void)
{
}

module_init(lidbg_drivers_loader_init);
module_exit(lidbg_drivers_loader_exit);

MODULE_AUTHOR("futengfei");
MODULE_DESCRIPTION("for hal or other group to insmod their KO or something else,2014.5.12");
MODULE_LICENSE("GPL");

EXPORT_SYMBOL(analyze_list_cmd);


