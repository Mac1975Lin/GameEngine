///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "BuildMenuState.h"
#include "ProjectModel.h"
using namespace IDreamSky;

#if defined(WIN32_PLATFORM)

BuildMenuState::BuildMenuState()
: State<ProjectModel>()
{
}

BuildMenuState::~BuildMenuState()
{
}

void BuildMenuState::onEnter(ProjectModel &projectModel)
{
}

void BuildMenuState::onExit(ProjectModel &projectModel)
{
}

void BuildMenuState::onUpdate(ProjectModel &projectModel, float dt)
{
}

void BuildMenuState::onPause(ProjectModel &projectModel)
{
}

void BuildMenuState::onResume(ProjectModel &projectModel)
{
}

void BuildMenuState::onTouchpad(ProjectModel &projectModel, const Input::TouchpadEvent &evt)
{
}

void BuildMenuState::onKeypad(ProjectModel &projectModel, const Input::GamepadEvent &evt)
{
}

void BuildMenuState::onAccelerator(ProjectModel &projectModel, const Input::AcceleratorEvent &evt)
{
}

void BuildMenuState::onGUI(ProjectModel &projectModel, const Input::GUIEvent &evt)
{
}

#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif