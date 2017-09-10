///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "ModelViewEditorScene.h"
using namespace IDreamSky;

ModelViewEditorScene::ModelViewEditorScene()
: touchpadMethod(this, &ModelViewEditorScene::touchpadEvent, true)
, keypadMethod(this, &ModelViewEditorScene::keypadEvent, true)
, acceleratorMethod(this, &ModelViewEditorScene::acceleratorEvent, true)
, guiMethod(this, &ModelViewEditorScene::guiEvent, true)
{
#if defined(WIN32_PLATFORM)
	for(int i=0; i<Stage::getNumEditorProjectView(); i++)
	{
		ProjectViewBase *view = (ProjectViewBase *)(Stage::getEditorProjectView(i));
		projectModel.addView(view);
	}

	projectModel.changeState("Start");
#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif
}

ModelViewEditorScene::~ModelViewEditorScene()
{
}

void ModelViewEditorScene::onConstruct()
{
}

void ModelViewEditorScene::onEnter()
{
}

void ModelViewEditorScene::onExit()
{
}

void ModelViewEditorScene::onUpdate(float dt)
{
#if defined(WIN32_PLATFORM)
	projectModel.onUpdate(dt);
#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif
}

void ModelViewEditorScene::onPause()
{
#if defined(WIN32_PLATFORM)
	projectModel.onPause();
#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif
}

void ModelViewEditorScene::onResume()
{
#if defined(WIN32_PLATFORM)
	projectModel.onResume();
#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif
}

bool ModelViewEditorScene::onTransition(TransitionMode)
{
	return false;
}

void ModelViewEditorScene::touchpadEvent(const Input::TouchpadEvent &evt)
{
#if defined(WIN32_PLATFORM)
	projectModel.onTouchpad(evt);
#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif
}

void ModelViewEditorScene::keypadEvent(const Input::GamepadEvent &evt)
{
#if defined(WIN32_PLATFORM)
	projectModel.onKeypad(evt);
#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif
}

void ModelViewEditorScene::acceleratorEvent(const Input::AcceleratorEvent &evt)
{
#if defined(WIN32_PLATFORM)
	projectModel.onAccelerator(evt);
#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif
}

void ModelViewEditorScene::guiEvent(const Input::GUIEvent &evt)
{
#if defined(WIN32_PLATFORM)
	projectModel.onGUI(evt);
#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif
}