LOCAL_PATH := $(call my-dir)

############################################################################################################
# fmod
include $(CLEAR_VARS)

LOCAL_MODULE                    := fmod

LOCAL_EXPORT_C_INCLUDES         := ../../../../../MagnumEngineLib/SDK/FMOD/Android/inc

LOCAL_SRC_FILES                 := ../../../../../MagnumEngineLib/SDK/FMOD/Android/lib/$(TARGET_ARCH_ABI)/libfmodL.so

include $(PREBUILT_SHARED_LIBRARY)

############################################################################################################
# zlib
include $(CLEAR_VARS)

LOCAL_MODULE                      :=  zlib

LOCAL_CPP_FEATURES                :=  exceptions rtti

LOCAL_C_INCLUDES                  :=  ../../../../../MagnumEngineLib/SDK/zlib

LOCAL_SRC_FILES                   =   $(wildcard ../../../../../MagnumEngineLib/SDK/zlib/*.c)

include $(BUILD_STATIC_LIBRARY)

############################################################################################################
# unzip
include $(CLEAR_VARS)

LOCAL_MODULE                      :=  unzip

LOCAL_CPP_FEATURES                :=  exceptions rtti

LOCAL_C_INCLUDES                  :=  ../../../../../MagnumEngineLib/SDK/unzip

LOCAL_SRC_FILES                   =   $(wildcard ../../../../../MagnumEngineLib/SDK/unzip/*.c)

include $(BUILD_STATIC_LIBRARY)

############################################################################################################
# XML
include $(CLEAR_VARS)

LOCAL_MODULE                      :=  XML

LOCAL_CPP_FEATURES                :=  exceptions rtti

LOCAL_C_INCLUDES                  :=  ../../../../../MagnumEngineLib/SDK/XML

LOCAL_SRC_FILES                   =   $(wildcard ../../../../../MagnumEngineLib/SDK/XML/*.cpp)

include $(BUILD_STATIC_LIBRARY)

############################################################################################################
# spine
include $(CLEAR_VARS)

LOCAL_MODULE                      :=  spine

LOCAL_CPP_FEATURES                :=  exceptions rtti

LOCAL_C_INCLUDES                  :=  ../../../../../MagnumEngineLib/SDK/spine/include

LOCAL_SRC_FILES                   =   $(wildcard ../../../../../MagnumEngineLib/SDK/spine/src/**/*.c)

include $(BUILD_STATIC_LIBRARY)


############################################################################################################
# jpeg
include $(CLEAR_VARS)

LOCAL_MODULE                      :=  jpeg

LOCAL_CPP_FEATURES                :=  exceptions rtti

LOCAL_C_INCLUDES                  :=  ../../../../../MagnumEngineLib/SDK/libjpeg

LOCAL_SRC_FILES                   =   $(wildcard ../../../../../MagnumEngineLib/SDK/libjpeg/*.c)

include $(BUILD_STATIC_LIBRARY)

############################################################################################################
# bullet
include $(CLEAR_VARS)

LOCAL_MODULE                      :=  bullet

LOCAL_CPP_FEATURES                :=  exceptions rtti

LOCAL_C_INCLUDES                  :=  ../../../../../MagnumEngineLib/SDK/Bullet

LOCAL_SRC_FILES                   =   $(wildcard ../../../../../MagnumEngineLib/SDK/Bullet/BulletCollision/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Bullet/BulletCollision/**/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Bullet/BulletDynamics/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Bullet/BulletDynamics/**/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Bullet/BulletSoftBody/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Bullet/BulletSoftBody/**/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Bullet/LinearMath/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Bullet/LinearMath/**/*.cpp)

include $(BUILD_STATIC_LIBRARY)

############################################################################################################
# box2d
include $(CLEAR_VARS)

LOCAL_MODULE                      :=  box2d

LOCAL_CPP_FEATURES                :=  exceptions rtti

LOCAL_C_INCLUDES                  :=  ../../../../../MagnumEngineLib/SDK

LOCAL_SRC_FILES                   =   $(wildcard ../../../../../MagnumEngineLib/SDK/Box2D/Common/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Box2D/Common/**/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Box2D/Collision/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Box2D/Collision/**/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Box2D/Dynamics/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Box2D/Dynamics/**/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Box2D/Rope/*.cpp) \
                                      $(wildcard ../../../../../MagnumEngineLib/SDK/Box2D/Rope/**/*.cpp)

include $(BUILD_STATIC_LIBRARY)

############################################################################################################
# magnumEngineLib
include $(CLEAR_VARS)

LOCAL_MODULE                      :=  magnumEngineLib

LOCAL_CPPFLAGS                    += -Wno-parentheses -Wno-undefined-var-template

LOCAL_SHORT_COMMANDS              := true

LOCAL_CPP_FEATURES                :=  exceptions rtti

LOCAL_C_INCLUDES                  :=  ../../../../../MagnumEngineLib/MagnumCore \
                                      ../../../../../MagnumEngineLib/SDK/zlib \
                                      ../../../../../MagnumEngineLib/SDK/unzip \
                                      ../../../../../MagnumEngineLib/SDK/XML \
                                      ../../../../../MagnumEngineLib/SDK/spine/include \
                                      ../../../../../MagnumEngineLib/SDK/libjpeg \
                                      ../../../../../MagnumEngineLib/SDK/Bullet \
                                      ../../../../../MagnumEngineLib/SDK/Box2D \
                                      ../../../../../MagnumEngineLib/SDK/FMOD/Android/inc

LOCAL_SRC_FILES                   =   $(wildcard ../../../../../MagnumEngineLib/MagnumCore/*.cpp)

include $(BUILD_STATIC_LIBRARY)

############################################################################################################
# game shared library
include $(CLEAR_VARS)

LOCAL_MODULE            :=  game

LOCAL_CPPFLAGS          += -Wno-parentheses -Wno-undefined-var-template

LOCAL_CPP_FEATURES      :=  exceptions rtti

LOCAL_C_INCLUDES        :=  $(LOCAL_PATH)/include \
                            ../../../../../MagnumEngineLib/MagnumCore \
                            ../../../../../Game/Entities \
                            ../../../../../Game/EntryPoint \
                            ../../../../../Game/Scenes

LOCAL_SRC_FILES         :=  $(wildcard $(LOCAL_PATH)/*.cpp) \
                            $(wildcard ../../../../../Game/**/*.cpp)

LOCAL_STATIC_LIBRARIES  :=  magnumEngineLib unzip zlib XML spine jpeg bullet box2d

LOCAL_SHARED_LIBRARIES  := fmod

LOCAL_LDLIBS            := -ldl -lGLESv2 -llog -landroid

include $(BUILD_SHARED_LIBRARY)