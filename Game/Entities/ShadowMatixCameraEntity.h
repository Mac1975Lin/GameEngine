///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#ifndef _ShadowMatixCameraEntity_h_
#define _ShadowMatixCameraEntity_h_

#include <MagnumEngine.h>
using namespace IDreamSky;

class ShadowMatixCameraEntity : public Entity
{
public:
	ShadowMatixCameraEntity();
	virtual ~ShadowMatixCameraEntity();

	DECLARE_ENTITY(ShadowMatixCameraEntity);

	PROPERTY(bool, FullScreenMode);
public:
	/////////////////////////////////////////////////////
	// method
	PerspectiveCameraComponent &getCamera();
protected:
private:
	void updateViewport(const Vector4& rect_);
protected:
private:
	virtual bool onConstruct();
	virtual void onStart();
	virtual void onPause();
	virtual void onResume();
	virtual void onUpdate(float dt);
	virtual void onStop();
	virtual void onDestruct();

	void touchpadEvent(const Input::TouchpadEvent &evt);
	void keypadEvent(const Input::GamepadEvent &evt);
	void acceleratorEvent(const Input::AcceleratorEvent &evt);
/////////////////////////////////////////////////////
public:
protected:
private:
	Input::TouchpadMethod<ShadowMatixCameraEntity>		touchpadMethod;
	Input::GamepadMethod<ShadowMatixCameraEntity>		keypadMethod;
	Input::AcceleratorMethod<ShadowMatixCameraEntity>	acceleratorMethod;

	PerspectiveCameraComponent								perspCamera;
	//OrthographicCameraComponent							orthoCamera;
	bool													touchDown;
	Vector4													rect;
	Vector2													touchDownPos;
};

#endif