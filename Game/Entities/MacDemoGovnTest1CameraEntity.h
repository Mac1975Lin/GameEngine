///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#ifndef _MacDemoGovnTest1CameraEntity_h_
#define _MacDemoGovnTest1CameraEntity_h_

#include <MagnumEngine.h>
using namespace IDreamSky;

class MacDemoGovnTest1CameraEntity : public Entity
{
public:
	MacDemoGovnTest1CameraEntity();
	virtual ~MacDemoGovnTest1CameraEntity();

	DECLARE_ENTITY(MacDemoGovnTest1CameraEntity);

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
	Input::TouchpadMethod<MacDemoGovnTest1CameraEntity>		touchpadMethod;
	Input::GamepadMethod<MacDemoGovnTest1CameraEntity>		keypadMethod;
	Input::AcceleratorMethod<MacDemoGovnTest1CameraEntity>	acceleratorMethod;

	PerspectiveCameraComponent								perspCamera;
	//OrthographicCameraComponent							orthoCamera;
	bool													touchDown;
	Vector4													rect;
	Vector2													touchDownPos;
};

#endif