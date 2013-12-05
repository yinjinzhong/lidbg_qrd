source ../../dbg_cfg.sh
LOCATE_PATH=`pwd`
cd ../../build && source env_entry.sh && ./build_cfg.sh $BOARD_VERSION $BUILD_VERSION $DBG_SOC
cd $DBG_SYSTEM_DIR/&&source build/envsetup.sh&&choosecombo release $DBG_PLATFORM eng
mkdir -p $DBG_ANDROID_OUT_PATH
cp -u $DBG_ANDROID_PATH/$DBG_SOC/*.conf    $DBG_ANDROID_OUT_PATH/
for each_dir in `ls -l $LOCATE_PATH | grep "^d" | awk '{print $NF}'`

do
	dir=$LOCATE_PATH/$each_dir
	mmm $dir -B  && cp -u $DBG_ANDROID_OUT_PATH/*  $DBG_OUT_PATH/
done

cd $DBG_SHELL_PATH && ./copy_out_release.sh

















