LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	src/SmartPointer.cpp

LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES -DEGL_EGLEXT_PROTOTYPES

#LOCAL_CFLAGS += -DDEBUG_LOCAL
#LOCAL_SRC_FILES += src/utils/RefBase.cpp

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	liblog \
	libandroidfw \
	libutils \
	libbinder \
    libui \
    libgui \
    libtinyalsa \
    libmedia

LOCAL_MODULE:= smartpointerdemo

include $(BUILD_EXECUTABLE)