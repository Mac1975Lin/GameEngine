///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "HelpMenuState.h"
#include "ProjectModel.h"
using namespace IDreamSky;

#if defined(WIN32_PLATFORM)

HelpMenuState::HelpMenuState() : State<ProjectModel>(){}
HelpMenuState::~HelpMenuState(){}
void HelpMenuState::onEnter(ProjectModel &projectModel){}
void HelpMenuState::onExit(ProjectModel &projectModel){}
void HelpMenuState::onUpdate(ProjectModel &projectModel, float dt){}
void HelpMenuState::onPause(ProjectModel &projectModel){}
void HelpMenuState::onResume(ProjectModel &projectModel){}
void HelpMenuState::onTouchpad(ProjectModel &projectModel, const Input::TouchpadEvent &evt){}
void HelpMenuState::onKeypad(ProjectModel &projectModel, const Input::GamepadEvent &evt){}
void HelpMenuState::onAccelerator(ProjectModel &projectModel, const Input::AcceleratorEvent &evt){}
void HelpMenuState::onGUI(ProjectModel &projectModel, const Input::GUIEvent &evt){}

#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif