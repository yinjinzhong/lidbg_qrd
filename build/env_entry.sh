#=======================================================================================
#	FileName    : 
#	Description : 
#       Date:         2010/04/27
#=======================================================================================

source ../dbg_cfg.sh

DBG_ROOT_PATH=`cd ../ && pwd`
DBG_BUILD_PATH=$DBG_ROOT_PATH/build
DBG_TOOLS_PATH=$DBG_ROOT_PATH/tools
DBG_OUT_PATH=$DBG_ROOT_PATH/out
DBG_CORE_PATH=$DBG_ROOT_PATH/core
DBG_SOC_PATH=$DBG_ROOT_PATH/soc
DBG_DRIVERS_PATH=$DBG_ROOT_PATH/drivers
DBG_HAL_PATH=$DBG_ROOT_PATH/hal
DBG_PLATFORM_DIR=$DBG_SOC_DIR/$DBG_PLATFORM


case "$DBG_PLATFORM_ID" in
    	0)
	DBG_PLATFORM=msm7627a
	BOARD_VERSION=V2
	DBG_CROSS_COMPILE=$DBG_SYSTEM_DIR/prebuilt/linux-x86/toolchain/arm-eabi-4.4.3/bin/arm-eabi-
	SYSTEM_BUILD_TYPE=eng
	DBG_KERNEL_SRC_DIR=$DBG_SYSTEM_DIR/kernel
	DBG_KERNEL_OBJ_DIR=$DBG_SYSTEM_DIR/out/target/product/$DBG_PLATFORM/obj/KERNEL_OBJ
	DBG_VENDOR=VENDOR_QCOM
	DBG_SOC=msm8x25;;
    	1)
	DBG_PLATFORM=msm8625
	BOARD_VERSION=V4
	DBG_CROSS_COMPILE=$DBG_SYSTEM_DIR/prebuilt/linux-x86/toolchain/arm-eabi-4.4.3/bin/arm-eabi-
	SYSTEM_BUILD_TYPE=userdebug
	DBG_KERNEL_SRC_DIR=$DBG_SYSTEM_DIR/kernel
	DBG_KERNEL_OBJ_DIR=$DBG_SYSTEM_DIR/out/target/product/$DBG_PLATFORM/obj/KERNEL_OBJ
	UPDATA_BIN_DIR=$RELEASE_REPOSITORY/driver
	UPDATA_BASESYSTEM_DIR=$RELEASE_REPOSITORY/basesystem
	DBG_PASSWORD=git
	DBG_REPO_PASSWORD=git
	DBG_VENDOR=VENDOR_QCOM
	OTA_PACKAGE_NAME=msm8625-ota-eng.*_mmc.zip
	DBG_SOC=msm8x25;;
    	2)
	DBG_PLATFORM=msm8226
	BOARD_VERSION=V3
	DBG_CROSS_COMPILE=$DBG_SYSTEM_DIR/prebuilts/gcc/linux-x86/arm/arm-eabi-4.7/bin/arm-eabi-
	SYSTEM_BUILD_TYPE=userdebug
	DBG_KERNEL_SRC_DIR=$DBG_SYSTEM_DIR/kernel
	DBG_KERNEL_OBJ_DIR=$DBG_SYSTEM_DIR/out/target/product/$DBG_PLATFORM/obj/KERNEL_OBJ
	UPDATA_BIN_PLATFORM_DIR=$RELEASE_REPOSITORY
	UPDATA_BIN_DIR=$UPDATA_BIN_PLATFORM_DIR/driver
	UPDATA_BASESYSTEM_DIR=$UPDATA_BIN_PLATFORM_DIR/basesystem
	DBG_PASSWORD=git
	DBG_REPO_PASSWORD=git
	DBG_VENDOR=VENDOR_QCOM
	OTA_PACKAGE_NAME=msm8226-ota-eng.*.zip
	DBG_SOC=msm8x26
	TEST_PACKAGE_PATH=//192.168.128.128/8x28/升级包发布/专项测试包
	REPOSITORY_WORK_BRANCH=master
	SYSTEM_WORK_BRANCH=master
        MAKE_PAKG_NUM=1
	MPSS_BUILD_PATH=$BP_SOURCE_PATH/modem_proc/build/ms
	BOOT_IMAGE_PATH=$BP_SOURCE_PATH/boot_images/build/ms
	ADSP_PATH=$BP_SOURCE_PATH/adsp_proc/build
	RPM_PATH=$BP_SOURCE_PATH/rpm_proc/build
	TZ_PATH=$BP_SOURCE_PATH/trustzone_images/build/ms
	UPDATE_INFO=$BP_SOURCE_PATH/common/build
	DEBUG_IMAGE_PATH=$BP_SOURCE_PATH/debug_image/build/ms
	#以下命令用于bp v1.0.3
	MPSS_BUILD_CMD='./build.sh 8626.gen BUILD_ID=AAAAANAZ'
	BOOTLOADER_BUILD_CMD='./build.sh --prod TARGET_FAMILY=8x26'
	ADSP_BUILD_CMD='python build.py'
	RPM_BUILD_CMD='./rpm_proc/build/build_8x26.sh'
	DEBUG_IMAGE_CMD='./b8x26.sh TARGET_FAMILY=8x26 sdi BUILD_ID=AAAAANAZ BUILD_VER=54 BUILD_MIN=1 -j1'
	TZ_BUILD_CMD='./build.sh CHIPSET=msm8x26 tz'
	UPDATE_BUILD_CMD='python update_common_info.py';; 
	
    	3)
	DBG_PLATFORM=msm8226
	BOARD_VERSION=V4
	DBG_CROSS_COMPILE=$DBG_SYSTEM_DIR/prebuilts/gcc/linux-x86/arm/arm-eabi-4.7/bin/arm-eabi-
	SYSTEM_BUILD_TYPE=userdebug
	DBG_KERNEL_SRC_DIR=$DBG_SYSTEM_DIR/kernel
	DBG_KERNEL_OBJ_DIR=$DBG_SYSTEM_DIR/out/target/product/$DBG_PLATFORM/obj/KERNEL_OBJ
	UPDATA_BIN_PLATFORM_DIR=$RELEASE_REPOSITORY/others/8928
	UPDATA_BIN_DIR=$UPDATA_BIN_PLATFORM_DIR/driver
	UPDATA_BASESYSTEM_DIR=$UPDATA_BIN_PLATFORM_DIR/basesystem
	DBG_PASSWORD=git
	DBG_REPO_PASSWORD=git
	DBG_VENDOR=VENDOR_QCOM
	OTA_PACKAGE_NAME=msm8226-ota-eng.*.zip
	DBG_SOC=msm8x26
	TEST_PACKAGE_PATH=//192.168.128.128/8928/升级包发布/专项测试包
	REPOSITORY_WORK_BRANCH=master
	SYSTEM_WORK_BRANCH=master
        MAKE_PAKG_NUM=10;;
    	4)
	DBG_PLATFORM=msm8974
	BOARD_VERSION=V2
	DBG_CROSS_COMPILE=$DBG_SYSTEM_DIR/prebuilts/gcc/linux-x86/arm/arm-eabi-4.7/bin/arm-eabi-
	SYSTEM_BUILD_TYPE=userdebug
	DBG_KERNEL_SRC_DIR=$DBG_SYSTEM_DIR/kernel
	DBG_KERNEL_OBJ_DIR=$DBG_SYSTEM_DIR/out/target/product/$DBG_PLATFORM/obj/KERNEL_OBJ
	UPDATA_BIN_PLATFORM_DIR=$RELEASE_REPOSITORY/others/8974
	UPDATA_BIN_DIR=$UPDATA_BIN_PLATFORM_DIR/driver
	UPDATA_BASESYSTEM_DIR=$UPDATA_BIN_PLATFORM_DIR/basesystem
	DBG_PASSWORD=git
	DBG_REPO_PASSWORD=git
	DBG_VENDOR=VENDOR_QCOM
	OTA_PACKAGE_NAME=msm8974-ota-eng.*.zip
	DBG_SOC=msm8x26
	TEST_PACKAGE_PATH=//192.168.128.128/8974/升级包发布/专项测试包
	REPOSITORY_WORK_BRANCH=master
	SYSTEM_WORK_BRANCH=master
        MAKE_PAKG_NUM=6
	#for bp
	MPSS_BUILD_PATH=$BP_SOURCE_PATH/modem_proc/build/ms
	BOOT_IMAGE_PATH=$BP_SOURCE_PATH/boot_images/build/ms
	ADSP_PATH=$BP_SOURCE_PATH/adsp_proc/build
	RPM_PATH=$BP_SOURCE_PATH/rpm_proc/build
	WCNSS_PATH=$BP_SOURCE_PATH/wcnss_proc/Pronto/bsp/build
	TZ_PATH=$BP_SOURCE_PATH/trustzone_images/build/ms
	UPDATE_INFO=$BP_SOURCE_PATH/common/build
	MPSS_BUILD_CMD='./build.sh 8974.gen.prod -k'
	BOOTLOADER_BUILD_CMD='./build.sh TARGET_FAMILY=8974 BUILD_ID=AAAAANAZ'
	ADSP_BUILD_CMD='python build.py'
	RPM_BUILD_CMD='./rpm_proc/build/build_8974.sh'
	WCNSS_BUILD_CMD='./wcnss_build.sh 8974 pronto BUILD_ID=SCAQBAZ'
	TZ_BUILD_CMD='./build.sh CHIPSET=msm8974 tz sampleapp tzbsp_no_xpu'
	UPDATE_BUILD_CMD='python update_common_info.py';; 
	
   	5)
	DBG_PLATFORM=mt3360
	BOARD_VERSION=V1
	DBG_CROSS_COMPILE=$DBG_SYSTEM_DIR/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-
	SYSTEM_BUILD_TYPE=eng
	DBG_KERNEL_SRC_DIR=$DBG_SYSTEM_DIR/kernel
	DBG_KERNEL_OBJ_DIR=$DBG_SYSTEM_DIR/kernel
	UPDATA_BIN_DIR=$RELEASE_REPOSITORY/driver
	UPDATA_BASESYSTEM_DIR=$RELEASE_REPOSITORY/basesystem
	DBG_PASSWORD=gitac8317
	DBG_REPO_PASSWORD=gitac8317
	DBG_VENDOR=VENDOR_MTK
	DBG_SOC=mt3360
	REPOSITORY_WORK_BRANCH=master
	SYSTEM_WORK_BRANCH=master
        MAKE_PAKG_NUM=1;;
esac

export UPDATA_BIN_PLATFORM_DIR
export REPOSITORY_WORK_BRANCH
export TEST_PACKAGE_PATH
export OTA_PACKAGE_NAME
export DBG_VENDOR
export DBG_ROOT_PATH
export DBG_TOOLS_PATH
export DBG_BUILD_PATH
export DBG_OUT_PATH
export DBG_CORE_PATH
export DBG_SOC_PATH
export DBG_DRIVERS_PATH
export DBG_PLATFORM_DIR
export RELEASE_REPOSITORY

export DBG_SOC
export DBG_PLATFORM
export DBG_SYSTEM_DIR
export UPDATA_BIN_DIR
export UPDATA_BASESYSTEM_DIR
export DBG_KERNEL_SRC_DIR
export DBG_KERNEL_OBJ_DIR
export DBG_CROSS_COMPILE
export BOARD_VERSION
export BUILD_VERSION
export DBG_REPO_PASSWORD
export DBG_PASSWORD
export MAKE_PAKG_NUM
#for bp
export MPSS_BUILD_PATH
export BOOT_IMAGE_PATH
export ADSP_PATH
export RPM_PATH
export WCNSS_PATH
export TZ_PATH
export UPDATE_INFO
export MPSS_BUILD_CMD
export BOOTLOADER_BUILD_CMD
export ADSP_BUILD_CMD
export RPM_BUILD_CMD
export WCNSS_BUILD_CMD
export TZ_BUILD_CMD
export UPDATE_BUILD_CMD



