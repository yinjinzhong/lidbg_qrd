LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_MODULE := MobileRateFlow.apk
LOCAL_SRC_FILES := MobileRateFlow.apk
LOCAL_MODULE_CLASS := bin
LOCAL_MODULE_TAGS := optional debug eng tests samples
LOCAL_MODULE_PATH := $(DBG_OUT_PATH)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := FlySwitching.apk
LOCAL_SRC_FILES := FlySwitching.apk
LOCAL_MODULE_CLASS := bin
LOCAL_MODULE_TAGS := optional debug eng tests samples
LOCAL_MODULE_PATH := $(DBG_OUT_PATH)
include $(BUILD_PREBUILT)
