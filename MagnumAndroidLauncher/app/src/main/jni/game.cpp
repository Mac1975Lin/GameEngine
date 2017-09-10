/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// OpenGL ES 2.0 code
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <string>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <jni.h>
#include <android/log.h>

#include <MagnumEngine.h>
using namespace IDreamSky;

///////////////////////////////////////////////////////////////////////////////////
// Globals
ServiceManager				serviceManager;
Scene::Factory				sceneFactory;
#ifdef ENABLE_RESOURCE_IMPORT
ResourceImport::Factory		resourceImportFactory;
#endif
ResourceAccess::Factory		resourceAccessFactory;
Entity::Factory				entityFactory;
Physics3::Manager			physics3Manager;
Collision::Manager			collisionManager;
Selection3::Manager			selection3Manager;
Video::Manager				videoManager;
Audio::Manager				audioManager;

#ifdef ENABLE_RESOURCE_IMPORT
///////////////////////////////////////////////////////////////////////////////////
// Resources Importer
//ResourceImport::Creator<Font::ResourceImporter>						fontResourceImporterCreator;
//ResourceImport::Creator<SkyMapResourceImporter>						skyMapResourceImporterCreator;
//ResourceImport::Creator<SpriteAnimation::ResourceImporter>			spriteAnimationResourceImporterCreator;
ResourceImport::Creator<MagnumScene::ResourceImporter>					MagnumSceneResourceImporterCreator;
ResourceImport::Creator<MagnumPrefab::ResourceImporter>					MagnumPrefabResourceImporterCreator;
ResourceImport::Creator<Texture2DFile::ResourceImporter>				texture2DFileResourceImporterCreator;
ResourceImport::Creator<TextureCubeFile::ResourceImporter>				textureCubeFileResourceImporterCreator;
ResourceImport::Creator<AudioClip::ResourceImporter>					audioClipResourceImporterCreator;
ResourceImport::Creator<AudioStream::ResourceImporter>					audioStreamResourceImporterCreator;
//ResourceImport::Creator<SpriteSheet::ResourceImporter>					spriteSheetImporterCreator;
//ResourceImport::Creator<Font::ResourceImporter>							fontImporterCreator;
ResourceImport::Creator<SceneCollision::ResourceImporter>				sceneCollisionImporterCreator;
ResourceImport::Creator<HeightFieldShape3::ResourceImporter>			heightfieldshape3ImporterCreator;
ResourceImport::Creator<Material::ResourceImporter>						materialImporterCreator;
ResourceImport::Creator<SkeletalAnimationModel::ResourceImporter>		skeletalAnimationModelImporterCreator;
ResourceImport::Creator<SkeletalAnimationModel2::ResourceImporter>		skeletalAnimationModel2ImporterCreator;
ResourceImport::Creator<TriangleSceneShape3::ResourceImporter>			triangleSceneShape3ImporterCreator;
ResourceImport::Creator<TriangleScene::ResourceImporter>				triangleSceneImporterCreator;
#endif

///////////////////////////////////////////////////////////////////////////////////
// Resources
//ResourceAccess::Creator<Font::Resource>								fontResourceCreator;
//Resource::Creator<SkyMapResource>										skyMapResourceCreator;
//Resource::Creator<SpriteAnimationResource>							spriteAnimationResourceCreator;
ResourceAccess::Creator<Texture2DFile::Resource>						texture2DFileResourceCreator;
ResourceAccess::Creator<TextureCubeFile::Resource>						textureCubeFileResourceCreator;
ResourceAccess::Creator<AudioClip::Resource>							audioClipResourceCreator;
//ResourceAccess::Creator<SpriteSheet::Resource>							spriteSheetCreator;
//ResourceAccess::Creator<Font::Resource>									fontCreator;
ResourceAccess::Creator<SceneCollision::Resource>						sceneCollisionCreator;
ResourceAccess::Creator<HeightFieldShape3::Resource>					heightfieldshape3Creator;
ResourceAccess::Creator<Material::Resource>								materialResourceCreator;
ResourceAccess::Creator<SkeletalAnimationModel::Resource>				skeletalAnimationModelResourceCreator;
ResourceAccess::Creator<SkeletalAnimationModel2::Resource>				skeletalAnimationModel2ResourceCreator;
ResourceAccess::Creator<TriangleSceneShape3::Resource>					triangleSceneShape3Creator;
ResourceAccess::Creator<TriangleScene::Resource>						triangleSceneCreator;

///////////////////////////////////////////////////////////////////////////////////
// Services
Service<Scene::Service>				sceneSrv("Scene");
#ifdef ENABLE_RESOURCE_IMPORT
Service<ResourceImport::Service>	resourceImportSrv("ResourceImport");
#endif
Service<ResourceAccess::Service>	resourceAccessSrv("ResourceAccess");
Service<Input::Service>				inputSrv("Input");
Service<Physics3::Service>			physics3Srv("Physics3");
Service<Collision::Service>			collisionSrv("Collision");
Service<Selection3::Service>		selection3Srv("Selection3");
Service<Video::Service>				videoSrv("Video");
Service<Audio::Service>				audioSrv("Audio");

///////////////////////////////////////////////////////////////////////////////////
// SceneCreators
#include "SceneCreators.h"

///////////////////////////////////////////////////////////////////////////////////
// EntityCreators
#include "EntityCreators.h"

extern "C"
{

#define  LOG_TAG    "MagnumEngine"
#define  LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG  , LOG_TAG, __VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO   , LOG_TAG, __VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN   , LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR  , LOG_TAG, __VA_ARGS__)
#define  LOGF(...)  __android_log_print(ANDROID_LOG_FATAL  , LOG_TAG, __VA_ARGS__)

long long getCurrentTimeMSFuncAndroid()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void printInfoFuncAndroid(const char *buf_)
{
	LOGI("%s\n", buf_);
}

void printDebugFuncAndroid(int tabCount, const char *buf_)
{
	LOGI("%s\n", buf_);
}

void printPanicFuncAndroid(const char *buf_)
{
	LOGI("%s\n", buf_);
}

///////////////////////////////////////////////////////////////////////////////////
// GameDescriptor
void setRawAssetRootDirectory(const char *rawAssetRootDirectory_)
{
	Stage::setRawAssetRootDirectory(rawAssetRootDirectory_);
}

void setAssetRootDirectory(const char *assetRootDirectory_)
{
	Stage::setAssetRootDirectory(assetRootDirectory_);
}

void setDocumentDirectory(const char *documentDirectory_)
{
	Stage::setDocumentDirectory(documentDirectory_);
}

void setExternalDirectory(const char *externalDirectory_)
{
	Stage::setExternalDirectory(externalDirectory_);
}

void setInitialScene(const char *initialScene_)
{
	Stage::setInitialScene(initialScene_);
}

void setGetCurrentTimeMSFunc(long long (*getCurrentTimeMSFunc_)())
{
	Stage::setGetCurrentTimeMSFunc(getCurrentTimeMSFunc_);
}

void setPrintFunc(void (*printInfoFunc_)(const char *buf_),
				  void (*printDebugFunc_)(int i, const char *buf_),
				  void (*printPanicFunc_)(const char *buf_))
{
	Stage::setPrintFunc(printInfoFunc_, printDebugFunc_, printPanicFunc_);
}

bool onInitialize(int width_, int height_)
{
	Stage::setStartTime();
	Stage::setScreenSize(width_, height_);

	if( !ServiceManager::instance().initiate() )
		return false;

	Stage::beginCheckMemoryLeak(-1);
	Stage::_initiated = true;

	if( !Scene::Factory::instance().find(Stage::getInitialScene()) )
		return false;

	if( !Scene::Factory::instance().pushScene(Stage::getInitialScene()) )
		return false;

	return true;
}

void onProcess()
{
    debug("onProcess");

	Stage::slice();

	serviceManager.process();
}

void onPause()
{
	serviceManager.pause();
}

void onResume()
{
	serviceManager.resume();
}

void onTerminate()
{
	Stage::_aborting = true;

	Stage::endCheckMemoryLeak();

	serviceManager.terminate();

	Stage::_initiated = false;
}

void onMouseDown(int modifier, int fingerID, float x, float y)
{
	Input::onMouseEvent((Input::TouchpadEvent::Modifier)modifier, Input::EVENT_MOUSE_DOWN, fingerID, x, y);
}

void onMouseUp(int modifier, int fingerID, float x, float y)
{
    Input::onMouseEvent((Input::TouchpadEvent::Modifier)modifier, Input::EVENT_MOUSE_UP, fingerID, x, y);
}

void onMouseMoved(int modifier, int fingerID, float x, float y)
{
    Input::onMouseEvent((Input::TouchpadEvent::Modifier)modifier, Input::EVENT_MOUSE_MOVE, fingerID, x, y);
}

void onMouseWheel(int modifier, float x, float y, int axis, int rotation)
{
    Input::onMouseEvent((Input::TouchpadEvent::Modifier)modifier, Input::EVENT_MOUSE_WHEEL, x, y, axis, rotation);
}

void onGamePadKeyDown(int keyCode)
{
    Input::onKeyEvent(Input::EVENT_GAMEPAD_KEY_DOWN, keyCode);
}

void onGamePadKeyUp(int keyCode)
{
    Input::onKeyEvent(Input::EVENT_GAMEPAD_KEY_UP, keyCode);
}

void onAccelerationUpdate(float x, float y, float z)
{
    Input::onAcceleratorEvent(Input::EVENT_ACCELERATOR_UPDATE, x, y, z);
}

void onGUIEvent(const unsigned char *buffer, int len)
{
    Input::onGUIEvent(Input::EVENT_GUI, buffer, len);
}

void addEditorProjectView(void *view_)
{
	Stage::addEditorProjectView(view_);
}

JNIEXPORT void JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_setRawAssetRootDirectory(JNIEnv *env, jobject obj, jstring rawAssetRootDirectory_)
{
    const char* str = env->GetStringUTFChars(rawAssetRootDirectory_, 0);
    if(str != NULL)
    {
        setRawAssetRootDirectory(str);

        env->ReleaseStringUTFChars(rawAssetRootDirectory_, str);
    }
}

JNIEXPORT void JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_setAssetRootDirectory(JNIEnv *env, jobject obj, jstring assetRootDirectory_)
{
    const char* str = env->GetStringUTFChars(assetRootDirectory_, 0);
    if(str != NULL)
    {
        setAssetRootDirectory(str);

        env->ReleaseStringUTFChars(assetRootDirectory_, str);
    }
}

JNIEXPORT void JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_setDocumentDirectory(JNIEnv *env, jobject obj, jstring documentDirectory_)
{
    const char* str = env->GetStringUTFChars(documentDirectory_, 0);
    if(str != NULL)
    {
        setDocumentDirectory(str);

        env->ReleaseStringUTFChars(documentDirectory_, str);
    }
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_setExternalDirectory(JNIEnv *env, jobject obj, jstring externalDirectory_)
{
    const char* str = env->GetStringUTFChars(externalDirectory_, 0);
    if(str != NULL)
    {
        setExternalDirectory(str);

        env->ReleaseStringUTFChars(externalDirectory_, str);
    }
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_setInitialScene(JNIEnv *env, jobject obj, jstring initialScene_)
{
    const char* str = env->GetStringUTFChars(initialScene_, 0);
    if(str != NULL)
    {
        setInitialScene(str);

        env->ReleaseStringUTFChars(initialScene_, str);
    }
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_setGetCurrentTimeMSFunc(JNIEnv *env, jobject obj)
{
    setGetCurrentTimeMSFunc(getCurrentTimeMSFuncAndroid);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_setPrintFunc(JNIEnv *env, jobject obj)
{
    setPrintFunc(printInfoFuncAndroid, printDebugFuncAndroid, printPanicFuncAndroid);
}

JNIEXPORT jboolean JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onInitialize(JNIEnv *env, jobject obj, jint width_, jint height_)
{
    return onInitialize(width_, height_);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onProcess(JNIEnv *env, jobject obj)
{
    onProcess();
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onPause(JNIEnv *env, jobject obj)
{
    onPause();
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onResume(JNIEnv *env, jobject obj)
{
    onResume();
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onTerminate(JNIEnv *env, jobject obj)
{
    onTerminate();
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onMouseDown(JNIEnv *env, jobject obj, jint modifier, jint fingerID, jfloat x, jfloat y)
{
    onMouseDown(modifier, fingerID, x, y);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onMouseUp(JNIEnv *env, jobject obj, jint modifier, jint fingerID, jfloat x, jfloat y)
{
    onMouseUp(modifier, fingerID, x, y);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onMouseMoved(JNIEnv *env, jobject obj, jint modifier, jint fingerID, jfloat x, jfloat y)
{
    onMouseMoved(modifier, fingerID, x, y);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onMouseWheel(JNIEnv *env, jobject obj, jint modifier, jint fingerID, jfloat x, jfloat y, jfloat axis, jfloat rotation)
{
    onMouseWheel(modifier, x, y, axis, rotation);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onGamePadKeyDown(JNIEnv *env, jobject obj, jint keyCode)
{
    onGamePadKeyDown(keyCode);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onGamePadKeyUp(JNIEnv *env, jobject obj, jint keyCode)
{
    onGamePadKeyUp(keyCode);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onAccelerationUpdate(JNIEnv *env, jobject obj, jfloat x, jfloat y, jfloat z)
{
    onAccelerationUpdate(x, y, z);
}

/*
JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_onGUIEvent(JNIEnv *env, jobject obj, jstring buffer)
{
    const char* str;
    str = env->GetStringUTFChars(buffer, NULL);
    if(str == NULL)
        return;

	LOGI("Java_com_idreamsky_MagnumAndroidLauncher_JNI_onGUIEvent\n");

    onGUIEvent((const unsigned char* )str, len);

    env->ReleaseStringUTFChars(buffer, str);
}

JNIEXPORT void JNICALL JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_addEditorProjectView(JNIEnv *env, jobject obj, void *view_)
{
	LOGI("Java_com_idreamsky_MagnumAndroidLauncher_JNI_addEditorProjectView\n");

    addEditorProjectView(view_);
}
*/

};


extern "C"
{

///////////////////////////////////////////////////////////////////////////////////
#define  LOG1_TAG    "MagnumEngine"
#define  LOG1V(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG1_TAG, __VA_ARGS__)
#define  LOG1D(...)  __android_log_print(ANDROID_LOG_DEBUG  , LOG1_TAG, __VA_ARGS__)
#define  LOG1I(...)  __android_log_print(ANDROID_LOG_INFO   , LOG1_TAG, __VA_ARGS__)
#define  LOG1W(...)  __android_log_print(ANDROID_LOG_WARN   , LOG1_TAG, __VA_ARGS__)
#define  LOG1E(...)  __android_log_print(ANDROID_LOG_ERROR  , LOG1_TAG, __VA_ARGS__)
#define  LOG1F(...)  __android_log_print(ANDROID_LOG_FATAL  , LOG1_TAG, __VA_ARGS__)

static void printGLString(const char *name, GLenum s)
{
    const char *v = (const char *) glGetString(s);

    LOG1I("GL %s = %s\n", name, v);
}

static void checkGlError(const char* op)
{
    for (GLint error = glGetError(); error; error = glGetError())
    {
        LOG1I("after %s() glError (0x%x)\n", op, error);
    }
}

auto gVertexShader =
    "attribute vec4 vPosition;\n"
    "void main() {\n"
    "  gl_Position = vPosition;\n"
    "}\n";

auto gFragmentShader =
    "precision mediump float;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
    "}\n";

GLuint loadShader(GLenum shaderType, const char* pSource) {
    GLuint shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    LOG1E("Could not compile shader %d:\n%s\n",
                            shaderType, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint createProgram(const char* pVertexSource, const char* pFragmentSource) {
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, pVertexSource);
    if (!vertexShader) {
        return 0;
    }

    GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, pFragmentSource);
    if (!pixelShader) {
        return 0;
    }

    GLuint program = glCreateProgram();
    if (program) {
        glAttachShader(program, vertexShader);
        checkGlError("glAttachShader");
        glAttachShader(program, pixelShader);
        checkGlError("glAttachShader");
        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
        if (linkStatus != GL_TRUE) {
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength) {
                char* buf = (char*) malloc(bufLength);
                if (buf) {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    LOG1E("Could not link program:\n%s\n", buf);
                    free(buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    return program;
}

GLuint gProgram;
GLuint gvPositionHandle;

bool setupGraphics(int w, int h) {
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    LOG1I("Mac: setupGraphics(%d, %d)", w, h);
    gProgram = createProgram(gVertexShader, gFragmentShader);
    if (!gProgram) {
        LOG1E("Could not create program.");
        return false;
    }
    gvPositionHandle = glGetAttribLocation(gProgram, "vPosition");
    checkGlError("glGetAttribLocation");
    LOG1I("Mac: glGetAttribLocation(\"vPosition\") = %d\n",
            gvPositionHandle);

    glViewport(0, 0, w, h);
    checkGlError("glViewport");
    return true;
}

const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f,
        0.5f, -0.5f };

void renderFrame() {
    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }
    glClearColor(grey, grey, grey, 1.0f);
    checkGlError("glClearColor");
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    checkGlError("glClear");

    glUseProgram(gProgram);
    checkGlError("glUseProgram");

    glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);
    checkGlError("glVertexAttribPointer");

    glEnableVertexAttribArray(gvPositionHandle);
    checkGlError("glEnableVertexAttribArray");

    glDrawArrays(GL_TRIANGLES, 0, 3);
    checkGlError("glDrawArrays");
}

JNIEXPORT void JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
    LOG1I("Java_com_idreamsky_MagnumAndroidLauncher_JNI_init\n");
    setupGraphics(width, height);
}

JNIEXPORT void JNICALL Java_com_idreamsky_MagnumAndroidLauncher_JNI_update(JNIEnv * env, jobject obj)
{
    LOG1I("Java_com_idreamsky_MagnumAndroidLauncher_JNI_update\n");
    renderFrame();
}

};