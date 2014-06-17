#include "lidbg.h"

static int logcat_en;
static int reboot_delay_s = 0;
static int cp_data_to_udisk_en = 0;
static int update_lidbg_out_dir_en = 0;
static int delete_out_dir_after_update = 1;
static int dump_mem_log = 0;
static int loop_warning_en = 0;


#define ORIGIN_APP_PATH "/system/origin_app/"
#define ORIGIN_TMP_PATH "/system/origin_tmp/"

void lidbg_enable_logcat(void)
{
    char cmd[128] = {0};
    char logcat_file_name[256] = {0};
    char time_buf[32] = {0};

    lidbg("\n\n\nthread_enable_logcat:logcat+\n");

    lidbg_get_current_time(time_buf, NULL);
    sprintf(logcat_file_name, "logcat_%d_%s.txt", get_machine_id(), time_buf);

    sprintf(cmd, "date >/data/%s", logcat_file_name);
    lidbg_shell_cmd(cmd);
    memset(cmd, '\0', sizeof(cmd));
    ssleep(1);
    lidbg_shell_cmd("chmod 777 /data/logcat*");
    ssleep(1);
    sprintf(cmd, "logcat  -v time>> /data/%s &", logcat_file_name);
    lidbg_shell_cmd(cmd);
    lidbg("logcat-\n");

}

void lidbg_enable_kmsg(void)
{
    char cmd[128] = {0};
    char dmesg_file_name[256] = {0};
    char time_buf[32] = {0};

    lidbg("\n\n\nthread_enable_dmesg:kmsg+\n");

    lidbg_trace_msg_disable(1);
    lidbg_get_current_time(time_buf, NULL);
    sprintf(dmesg_file_name, "kmsg_%d_%s.txt", get_machine_id(), time_buf);

    sprintf(cmd, "date >/data/%s", dmesg_file_name);
    lidbg_shell_cmd(cmd);
    memset(cmd, '\0', sizeof(cmd));
    ssleep(1);
    lidbg_shell_cmd("chmod 777 /data/kmsg*");
    ssleep(1);
    sprintf(cmd, "cat /proc/kmsg >> /data/%s &", dmesg_file_name);
    lidbg_shell_cmd(cmd);
    lidbg("kmsg-\n");
}


bool set_wifi_adb_mode(bool on)
{
    LIDBG_WARN("<%d>\n", on);
    if(on)
        lidbg_setprop("service.adb.tcp.port", "5555");
    else
        lidbg_setprop("service.adb.tcp.port", "-1");
    lidbg_stop("adbd");
    lidbg_start("adbd");
    return true;
}
void cb_password_chmod(char *password )
{
    fs_mem_log("<called:%s>\n", __func__ );

    lidbg_chmod("/system/bin/mount");
    lidbg_mount("/system");
    lidbg_chmod("/data");
}
void cb_password_upload(char *password )
{
    fs_mem_log("<called:%s>\n", __func__ );
    fs_upload_machine_log();
}
void cb_password_clean_all(char *password )
{
    fs_mem_log("<called:%s>\n", __func__ );
    fs_clean_all();
}
void cb_password_update(char *password )
{
    analysis_copylist(USB_MOUNT_POINT"/conf/copylist.conf");
    fs_slient_level = 4;

    LIDBG_WARN("<===============UPDATE_INFO =================>\n" );

    if(fs_is_file_exist(USB_MOUNT_POINT"/out/release"))
    {
        if( fs_update(USB_MOUNT_POINT"/out/release", USB_MOUNT_POINT"/out", "/flysystem/lib/out") >= 0)
        {
            if(delete_out_dir_after_update)
                lidbg_rmdir(USB_MOUNT_POINT"/out");
            lidbg_launch_user(CHMOD_PATH, "777", "/flysystem/lib/out", "-R", NULL, NULL, NULL);
            lidbg_reboot();
        }
    }
    else
        LIDBG_ERR("<up>\n" );
}
void update_lidbg_out_dir(char *key, char *value )
{
    cb_password_update(NULL);
}

void cb_password_gui_kmsg(char *password )
{
    if(lidbg_exe("/flysystem/lib/out/lidbg_gui", "/proc/kmsg", "1", NULL, NULL, NULL, NULL) < 0)
        LIDBG_ERR("Exe lidbg_kmsg failed !\n");
}

void cb_password_gui_state(char *password )
{
    if(lidbg_exe("/flysystem/lib/out/lidbg_gui", "/dev/log/state.txt", "1", NULL, NULL, NULL, NULL) < 0)
        LIDBG_ERR("Exe status failed !\n");
}

void cb_password_mem_log(char *password )
{
    lidbg_fifo_get(glidbg_msg_fifo, LIDBG_LOG_DIR"lidbg_mem_log.txt", 0);
}
void cb_int_mem_log(char *key, char *value )
{
    cb_password_mem_log(NULL);
}
int thread_reboot(void *data)
{
    bool volume_find;
    if(!reboot_delay_s)
    {
        lidbg("<reb.exit.%d>\n", reboot_delay_s);
        return 0;
    }
    ssleep(reboot_delay_s);
    volume_find = !!find_mounted_volume_by_mount_point(USB_MOUNT_POINT) ;
    if(volume_find && !te_is_ts_touched())
    {
        lidbg("<lidbg:thread_reboot,call reboot,%d>\n", te_is_ts_touched());
        msleep(100);
        kernel_restart(NULL);
    }
    return 0;
}

void logcat_lunch(char *key, char *value )
{
#ifdef SOC_msm8x25
    k2u_write(LOG_LOGCAT);
#else
    lidbg_enable_logcat();
#endif
}
void cb_cp_data_to_udisk(char *key, char *value )
{
    fs_cp_data_to_udisk(false);
}
int loop_warnning(void *data)
{
    while(1)
    {
        lidbg_notifier_call_chain(NOTIFIER_VALUE(NOTIFIER_MAJOR_SIGNAL_EVENT, NOTIFIER_MINOR_SIGNAL_BAKLIGHT_ACK));
        msleep(1000);
    }
    return 0;
}

void lidbg_loop_warning(void)
{
    if(loop_warning_en)
    {
        DUMP_FUN;
        CREATE_KTHREAD(loop_warnning, NULL);
    }
}
void cb_kv_wifiadb(char *key, char *value)
{
    if(value && *value == '1')
        set_wifi_adb_mode(true);
    else
        set_wifi_adb_mode(false);
}
void cb_kv_app_install(char *key, char *value)
{
    if(value && *value == '1')
        lidbg_pm_install_dir("/mnt/media_rw/udisk/apps");
    else
        fs_mem_log("cb_kv_app_install:fail,%s\n", value);
}
void cb_kv_reboot_recovery(char *key, char *value)
{
    if(value && *value == '1')
        lidbg_shell_cmd("reboot recovery");
    else
        fs_mem_log("cb_kv_reboot_recovery:fail,%s\n", value);
}
void cb_kv_lidbg_origin_system(char *key, char *value)
{
    LIDBG_WARN("\n\n<------------------system switch -%s----------->\n\n", value[0] == '1' ? "origin system" : "flyaudio system");
    if(value && *value == '1')//origin
    {
        lidbg_toast_show("\"swtich to [origin system]\"", 0);
        lidbg_shell_cmd("mkdir -p /flyapdata/out/temp");
        lidbg_shell_cmd("mkdir -p /flysystem/out/temp");

        fs_remount_system();

        lidbg_shell_cmd("cp -rf "ORIGIN_APP_PATH"* /system/priv-app/ &");
        lidbg_shell_cmd("cp -rf "ORIGIN_TMP_PATH"NfcNci.apk /system/app/ &");
        lidbg_shell_cmd("cp -r /flyapdata/app/ESFileExplorer.apk /system/app/ &");
        lidbg_shell_cmd("cp -r /flysystem/app/FlyBootService.apk /system/app/ &");
        lidbg_shell_cmd("cp -r /flysystem/app/FastBoot.apk /system/app/ &");
        ssleep(10);//give sometime for cp
        if(!fs_is_file_exist("/system/priv-app/Launcher2.apk"))
        {
            lidbg_shell_cmd("cp -r "ORIGIN_APP_PATH"Launcher2.apk /system/priv-app/ &");
            ssleep(5);
        }

        lidbg_shell_cmd("mv /system/lib/modules/out1 system/lib/modules/out");
        lidbg_shell_cmd("mv /flyapdata/* /flyapdata/out/temp &");
        lidbg_shell_cmd("mv /flysystem/* /flysystem/out/temp &");

        lidbg_shell_cmd("rm -r /system/priv-app/Launcher3.apk");
        lidbg_shell_cmd("chmod 777 /system/app/F*");
        lidbg_shell_cmd("chmod 777 /system/app/ESFileExplorer.apk");
        lidbg_shell_cmd("chmod 777 /system/app/NfcNci.apk");
        lidbg_shell_cmd("mv /system/lib/modules/out1 system/lib/modules/out");
        goto suc;
    }
    else   if(value && *value == '2')//flyaudio
    {
        lidbg_toast_show("\"swtich to [flyaudio system]\"", 0);

        lidbg_shell_cmd("cp -rf  /flysystem/out/temp/app/sys-app1/* /system/priv-app &");

        ssleep(10);//give sometime for cp
        if(!fs_is_file_exist("/system/priv-app/Launcher3.apk"))
        {
            lidbg_shell_cmd("cp -r /flysystem/out/temp/app/sys-app1/Launcher3.apk /system/priv-app/ &");
            ssleep(5);
        }
        lidbg_shell_cmd("mv /flysystem/out/temp/* /flysystem &");
        lidbg_shell_cmd("mv /flyapdata/out/temp/* /flyapdata  &");
        ssleep(5);//give sometime for cp

        lidbg_shell_cmd("rm -r /system/app/ESFileExplorer.apk");
        lidbg_shell_cmd("rm -r /system/app/FlyBootService.apk");
        lidbg_shell_cmd("rm -r /system/app/FastBoot.apk");
        lidbg_shell_cmd("rm -r /system/app/NfcNci.apk ");
        lidbg_shell_cmd("mv /system/lib/modules/out system/lib/modules/out1");
        lidbg_shell_cmd("rm -r /system/priv-app/Launcher2.apk");
        goto suc;
    }

    LIDBG_WARN("<err>\n");
    return ;
suc:
    lidbg_shell_cmd("chmod 777 /system/priv-app/* &");
    ssleep(3);
    lidbg_shell_cmd("rm -r /data");
    ssleep(5);
    lidbg_reboot();
}

void cb_kv_cmd(char *key, char *value)
{
    if(value)
    {
        lidbg_shell_cmd(value);
        fs_mem_log("cb_kv_cmd:%s\n", value);
    }
}

int misc_init(void *data)
{
    LIDBG_WARN("<==IN==>\n");

    lidbg_shell_cmd("mkdir  "ORIGIN_APP_PATH);
    lidbg_shell_cmd("mkdir  "ORIGIN_TMP_PATH);
    lidbg_shell_cmd("mkdir  /system/lib/modules/out1");

    if(!fs_is_file_exist(ORIGIN_APP_PATH"SystemUI.apk"))
    {
        lidbg_shell_cmd("cp /system/priv-app/SystemUI.apk "ORIGIN_APP_PATH"SystemUI.apk" );
        lidbg_shell_cmd("cp /system/priv-app/Contacts.apk "ORIGIN_APP_PATH"Contacts.apk" );
        lidbg_shell_cmd("cp /system/priv-app/Dialer.apk "ORIGIN_APP_PATH"Dialer.apk" );
        lidbg_shell_cmd("cp /system/priv-app/Keyguard.apk "ORIGIN_APP_PATH"Keyguard.apk" );
        lidbg_shell_cmd("cp /system/priv-app/Mms.apk "ORIGIN_APP_PATH"Mms.apk" );
        lidbg_shell_cmd("cp /system/priv-app/Settings.apk "ORIGIN_APP_PATH"Settings.apk" );
        lidbg_shell_cmd("cp /system/priv-app/Launcher2.apk "ORIGIN_APP_PATH"Launcher2.apk &" );
        lidbg_shell_cmd("cp /system/app/NfcNci.apk "ORIGIN_TMP_PATH"NfcNci.apk" );
        lidbg_shell_cmd("chmod 777  "ORIGIN_APP_PATH"*" );
        lidbg_shell_cmd("chmod 777  "ORIGIN_TMP_PATH"*" );
    }
    if(is_out_updated || !fs_is_file_exist("/system/lib/modules/out1/build_time.conf"))
    {
        lidbg_shell_cmd("cp -rf /flysystem/lib/out/* /system/lib/modules/out1/ &");
        lidbg_shell_cmd("chmod 777 /system/lib/modules/out1/*");
    }

    te_regist_password("001101", cb_password_upload);
    te_regist_password("001110", cb_password_clean_all);
    te_regist_password("001111", cb_password_chmod);
    te_regist_password("001112", cb_password_update);
    te_regist_password("001120", cb_password_gui_kmsg);
    te_regist_password("001121", cb_password_gui_state);
    te_regist_password("011200", cb_password_mem_log);

    FS_REGISTER_INT(dump_mem_log, "dump_mem_log", 0, cb_int_mem_log);
    FS_REGISTER_INT(logcat_en, "logcat_en", 0, logcat_lunch);
    FS_REGISTER_INT(reboot_delay_s, "reboot_delay_s", 0, NULL);
    FS_REGISTER_INT(cp_data_to_udisk_en, "cp_data_to_udisk_en", 0, cb_cp_data_to_udisk);
    FS_REGISTER_INT(update_lidbg_out_dir_en, "update_lidbg_out_dir_en", 0, update_lidbg_out_dir);
    FS_REGISTER_INT(delete_out_dir_after_update, "delete_out_dir_after_update", 0, NULL);
    FS_REGISTER_INT(loop_warning_en, "loop_warning_en", 0, NULL);

    FS_REGISTER_KEY( "cmdstring", cb_kv_cmd);
    FS_REGISTER_KEY( "wifiadb_en", cb_kv_wifiadb);
    FS_REGISTER_KEY( "app_install_en", cb_kv_app_install);
    FS_REGISTER_KEY( "reboot_recovery", cb_kv_reboot_recovery);
    FS_REGISTER_KEY( "lidbg_origin_system", cb_kv_lidbg_origin_system);

    fs_register_filename_list("/data/kmsg.txt", true);
    fs_register_filename_list("/data/top.txt", true);
    fs_register_filename_list("/data/ps.txt", true);
    fs_register_filename_list("/data/df.txt", true);
    fs_register_filename_list("/data/machine.txt", true);
    fs_register_filename_list("/data/dumpsys.txt", true);
    fs_register_filename_list("/data/screenshot.png", true);
    fs_register_filename_list(LIDBG_LOG_DIR"lidbg_mem_log.txt", true);

    CREATE_KTHREAD(thread_reboot, NULL);

    LIDBG_WARN("<==OUT==>\n\n");
    LIDBG_MODULE_LOG;

    if(1 == logcat_en)
        logcat_lunch(NULL, NULL);

    return 0;
}


static int __init lidbg_misc_init(void)
{

    DUMP_FUN;
    CREATE_KTHREAD(misc_init, NULL);
    return 0;
}

static void __exit lidbg_misc_exit(void)
{
}

module_init(lidbg_misc_init);
module_exit(lidbg_misc_exit);

EXPORT_SYMBOL(lidbg_loop_warning);
EXPORT_SYMBOL(lidbg_enable_logcat);
EXPORT_SYMBOL(lidbg_enable_kmsg);


MODULE_AUTHOR("futengfei");
MODULE_DESCRIPTION("misc zone");
MODULE_LICENSE("GPL");

