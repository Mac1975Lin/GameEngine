# Uncomment this if you're using STL in your project
# See CPLUSPLUS-SUPPORT.html in the NDK documentation for more information
APP_STL := gnustl_shared

APP_CPPFLAGS += -std=c++11

APP_ABI := x86, armeabi-v7a, armeabi

# Min SDK level
APP_PLATFORM :=android-14