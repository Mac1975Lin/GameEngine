///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "StartState.h"
#include "ProjectModel.h"
using namespace IDreamSky;

#if defined(WIN32_PLATFORM)
//#define QUICK_TEST

StartState::StartState()
: State<ProjectModel>()
{
}

StartState::~StartState()
{
}

void StartState::onEnter(ProjectModel &projectModel)
{
	projectModel.initClassIndexMap();
	projectModel.initEntityCreators();
	Entity::create("EditorEntity", "EditorEntity");

	projectModel.notifyViews();

#ifdef QUICK_TEST
#else
	projectModel.setChanged(ProjectModelBase::PROJECT_DIALOG);
	projectModel.notifyViews();
#endif
}

void StartState::onExit(ProjectModel &projectModel)
{
}

void StartState::onUpdate(ProjectModel &projectModel, float dt)
{
#ifdef QUICK_TEST
	projectModel.changeState("OperationSelectEntity");
#else
	if(projectModel.getOpenFlag())
	{
		projectModel.changeState("FileProjectOpen");
	}
	else
	{
		projectModel.changeState("FileProjectNew");
	}
#endif
}

void StartState::onPause(ProjectModel &projectModel)
{
}

void StartState::onResume(ProjectModel &projectModel)
{
}

void StartState::onTouchpad(ProjectModel &projectModel, const Input::TouchpadEvent &evt)
{
}

void StartState::onKeypad(ProjectModel &projectModel, const Input::GamepadEvent &evt)
{
}

void StartState::onAccelerator(ProjectModel &projectModel, const Input::AcceleratorEvent &evt)
{
}

void StartState::onGUI(ProjectModel &projectModel, const Input::GUIEvent &evt)
{
}

#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif