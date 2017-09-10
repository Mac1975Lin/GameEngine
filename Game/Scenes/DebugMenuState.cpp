///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "DebugMenuState.h"
#include "ProjectModel.h"
using namespace IDreamSky;

#if defined(WIN32_PLATFORM)

///////////////////////////////////////////////////////////////////////////////////////////////////
DebugRunState::DebugRunState() : State<ProjectModel>(){}
DebugRunState::~DebugRunState(){}
void DebugRunState::onEnter(ProjectModel &projectModel)
{
	projectModel.debugScenePlay();
}
void DebugRunState::onExit(ProjectModel &projectModel)
{
	projectModel.debugSceneStop();
}
void DebugRunState::onUpdate(ProjectModel &projectModel, float dt){}
void DebugRunState::onPause(ProjectModel &projectModel){}
void DebugRunState::onResume(ProjectModel &projectModel){}
void DebugRunState::onTouchpad(ProjectModel &projectModel, const Input::TouchpadEvent &evt){}
void DebugRunState::onKeypad(ProjectModel &projectModel, const Input::GamepadEvent &evt){}
void DebugRunState::onAccelerator(ProjectModel &projectModel, const Input::AcceleratorEvent &evt){}
void DebugRunState::onGUI(ProjectModel &projectModel, const Input::GUIEvent &evt){}

///////////////////////////////////////////////////////////////////////////////////////////////////
DebugStopState::DebugStopState() : State<ProjectModel>(){}
DebugStopState::~DebugStopState(){}
void DebugStopState::onEnter(ProjectModel &projectModel)
{
	projectModel.debugSceneStop();
}
void DebugStopState::onExit(ProjectModel &projectModel)
{
}
void DebugStopState::onUpdate(ProjectModel &projectModel, float dt)
{
	projectModel.changeState("OperationSelectEntity");
}
void DebugStopState::onPause(ProjectModel &projectModel){}
void DebugStopState::onResume(ProjectModel &projectModel){}
void DebugStopState::onTouchpad(ProjectModel &projectModel, const Input::TouchpadEvent &evt){}
void DebugStopState::onKeypad(ProjectModel &projectModel, const Input::GamepadEvent &evt){}
void DebugStopState::onAccelerator(ProjectModel &projectModel, const Input::AcceleratorEvent &evt){}
void DebugStopState::onGUI(ProjectModel &projectModel, const Input::GUIEvent &evt){}

#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif