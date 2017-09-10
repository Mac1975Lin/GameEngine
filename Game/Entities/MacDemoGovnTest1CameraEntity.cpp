///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoGovnTest1CameraEntity.h"
using namespace IDreamSky;

MacDemoGovnTest1CameraEntity::MacDemoGovnTest1CameraEntity()
: touchpadMethod(this, &MacDemoGovnTest1CameraEntity::touchpadEvent)
, keypadMethod(this, &MacDemoGovnTest1CameraEntity::keypadEvent)
, acceleratorMethod(this, &MacDemoGovnTest1CameraEntity::acceleratorEvent)
, perspCamera(*this)
, touchDown(false)
//, orthoCamera(*this)
//, isMainCamera(false)
{
	perspCamera.setProjection(Math::ONE_PI*45/180, 960.0f/640.0f, 0.1, 3000);

	//orthoCamera.setProjection(-20, 20, -10, 10, 1, 1000);
	//orthoCamera.setTargetLayer(0x01);
	//orthoCamera.setClearFlags(CameraComponent::CLEAR_COLOR | CameraComponent::CLEAR_DEPTH);
	if(getFullScreenMode())
	{
		updateViewport(Vector4(0, 0, 1, 1));
		perspCamera.setOrder(0);
	}
	else
	{
		updateViewport(Vector4(0, 0, 0.3, 0.3));
		perspCamera.setOrder(1);
	}
}

MacDemoGovnTest1CameraEntity::~MacDemoGovnTest1CameraEntity()
{
}

PerspectiveCameraComponent &MacDemoGovnTest1CameraEntity::getCamera()
{
	return perspCamera;
}

void MacDemoGovnTest1CameraEntity::updateViewport(const Vector4& rect_)
{
	Vector4 viewport = rect_;

	if(rect_.X()<rect_.Z())
	{
		viewport.X() = rect_.X();
		viewport.Z() = rect_.Z() - rect_.X();
	}
	else
	{
		viewport.X() = rect_.Z();
		viewport.Z() = rect_.X() - rect_.Z();
	}

	if(rect_.Y()<rect_.W())
	{
		viewport.Y() = rect_.Y();
		viewport.W() = rect_.W() - rect_.Y();
	}
	else
	{
		viewport.W() = rect_.Y();
		viewport.Y() = rect_.Y() - rect_.W();
	}

	perspCamera.setViewport(viewport);
}

bool MacDemoGovnTest1CameraEntity::onConstruct()
{
	return true;
}

void MacDemoGovnTest1CameraEntity::onStart()
{
}

void MacDemoGovnTest1CameraEntity::onPause()
{
}

void MacDemoGovnTest1CameraEntity::onResume()
{
}

void MacDemoGovnTest1CameraEntity::onUpdate(float dt)
{
}

void MacDemoGovnTest1CameraEntity::onStop()
{
}

void MacDemoGovnTest1CameraEntity::onDestruct()
{
}

void MacDemoGovnTest1CameraEntity::touchpadEvent(const Input::TouchpadEvent &evt)
{
	Vector2 pos =  (evt.position + Vector2(1, 1)) * 0.5;

	if(!getFullScreenMode())
	{
		if(evt.isAltDown())
		{
			if(evt.event==Input::Event::EVENT_MOUSE_DOWN)
			{
				touchDownPos = pos;
	
				touchDown =  true;
			}
			else if(evt.event==Input::Event::EVENT_MOUSE_MOVE)
			{
				if(touchDown)
				{
					Vector2 offset = pos - touchDownPos;
					updateViewport(rect + Vector4(offset.X(), offset.Y(), offset.X(), offset.Y()));
				}
			}
			else if(evt.event==Input::Event::EVENT_MOUSE_UP)
			{		
				Vector2 offset = pos - touchDownPos;
				rect = rect + Vector4(offset.X(), offset.Y(), offset.X(), offset.Y());
				updateViewport(rect);
		
				touchDown =  false;
			}
		}
		else
		{
			if(evt.event==Input::Event::EVENT_MOUSE_DOWN)
			{
				touchDownPos = evt.position;
	
				rect.X() = pos.X();
				rect.Y() = pos.Y();
				rect.Z() = rect.X();
				rect.W() = rect.Y();
	
				touchDown =  true;
			}
			else if(evt.event==Input::Event::EVENT_MOUSE_MOVE)
			{
				if(touchDown)
				{
					rect.Z() = pos.X();
					rect.W() = pos.Y();
		
					updateViewport(rect);
				}
			}
			else if(evt.event==Input::Event::EVENT_MOUSE_UP)
			{
				rect.Z() = pos.X();
				rect.W() = pos.Y();
		
				updateViewport(rect);
		
				touchDown =  false;
			}
		}
	}
}

void MacDemoGovnTest1CameraEntity::keypadEvent(const Input::GamepadEvent &evt)
{
	debug("MacDemoGovnTest1CameraEntity::keypadEvent(const Input::GamepadEvent &evt)");
}

void MacDemoGovnTest1CameraEntity::acceleratorEvent(const Input::AcceleratorEvent &evt)
{
	debug("MacDemoGovnTest1CameraEntity::acceleratorEvent(const Input::AcceleratorEvent &evt)");
}