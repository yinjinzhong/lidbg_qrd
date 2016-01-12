#!/bin/bash
DATE=$(date +%Y%m%d_%H%M)
VERSION_DATE=$(date +-%Y-%m-%d-%H-%M)
BUILD_TYPE=700s_usbcamera

SOURCE_OUT_DIR=$RELEASE_REPOSITORY/out/8909-usbcamera-alpha
FLYTMP_OUT_DIR=$DBG_SYSTEM_DIR/flyaudio/out
TARGET_OUT_DIR=$DBG_SYSTEM_DIR/out/target/product/msm8909
TARGET_FLYAUDIO_DIR=$DBG_SYSTEM_DIR/out/target/product/msm8909/system/vendor/flyaudio

config_environment()
{
	cd $DBG_SYSTEM_DIR
	source build/envsetup.sh&&choosecombo release $DBG_PLATFORM $SYSTEM_BUILD_TYPE
}

get_ready()
{
	rm -rf $TARGET_FLYAUDIO_DIR/
	rm -rf $FLYTMP_OUT_DIR/
	mkdir $FLYTMP_OUT_DIR/
	mkdir $FLYTMP_OUT_DIR/flyupdate/
	mkdir $TARGET_FLYAUDIO_DIR/
}

copy_source()
{
	cd $RELEASE_REPOSITORY
	./tools/pull
	./make.sh
	cp -rf $RELEASE_REPOSITORY/systemlib/.   $TARGET_OUT_DIR/system/lib/
	cp -rf $SOURCE_OUT_DIR/flyupdate/flyaudio/. $TARGET_FLYAUDIO_DIR/
	cp $SOURCE_OUT_DIR/flyapdata.flp $FLYTMP_OUT_DIR/flyupdate/
}

make_full_package()
{
	cd $DBG_SYSTEM_DIR
	make -j16
	cp $TARGET_OUT_DIR/msm8909-ota-eng.*.zip $FLYTMP_OUT_DIR/flyupdate/baseqcom.flb
	cd $FLYTMP_OUT_DIR/flyupdate
	zip -r  $TARGET_OUT_DIR/flyupdate-$BUILD_TYPE-$DATE.fup .
	echo "output:"
	echo -e "\t\033[49;32;1m./out/target/product/msm8909/flyupdate-$BUILD_TYPE-$DATE.fup\033[0m"
}


clear

config_environment

get_ready

copy_source

make_full_package

#make_full_diff_package

echo ""

echo "done."



