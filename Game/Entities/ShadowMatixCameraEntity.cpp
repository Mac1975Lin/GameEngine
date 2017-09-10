///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "ShadowMatixCameraEntity.h"
using namespace IDreamSky;

ShadowMatixCameraEntity::ShadowMatixCameraEntity()
: touchpadMethod(this, &ShadowMatixCameraEntity::touchpadEvent)
, keypadMethod(this, &ShadowMatixCameraEntity::keypadEvent)
, acceleratorMethod(this, &ShadowMatixCameraEntity::acceleratorEvent)
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

ShadowMatixCameraEntity::~ShadowMatixCameraEntity()
{
}

PerspectiveCameraComponent &ShadowMatixCameraEntity::getCamera()
{
	return perspCamera;
}

void ShadowMatixCameraEntity::updateViewport(const Vector4& rect_)
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

bool ShadowMatixCameraEntity::onConstruct()
{
	return true;
}

void ShadowMatixCameraEntity::onStart()
{
}

void ShadowMatixCameraEntity::onPause()
{
}

void ShadowMatixCameraEntity::onResume()
{
}

void ShadowMatixCameraEntity::onUpdate(float dt)
{
}

void ShadowMatixCameraEntity::onStop()
{
}

void ShadowMatixCameraEntity::onDestruct()
{
}

void ShadowMatixCameraEntity::touchpadEvent(const Input::TouchpadEvent &evt)
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

void ShadowMatixCameraEntity::keypadEvent(const Input::GamepadEvent &evt)
{
	debug("ShadowMatixCameraEntity::keypadEvent(const Input::GamepadEvent &evt)");
}

void ShadowMatixCameraEntity::acceleratorEvent(const Input::AcceleratorEvent &evt)
{
	debug("ShadowMatixCameraEntity::acceleratorEvent(const Input::AcceleratorEvent &evt)");
}