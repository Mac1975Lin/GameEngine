///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "EditorEntity.h"
using namespace IDreamSky;

EditorEntity::EditorEntity()
: touchpadMethod(this, &EditorEntity::touchpadEvent, true)
, keypadMethod(this, &EditorEntity::keypadEvent, true)
, acceleratorMethod(this, &EditorEntity::acceleratorEvent, true)
, cameraComponent(*this)
, editorGizmoRenderer(*this)
, editorGizmo(*this)
{
	initLookAt(Vector3(50, 50, 50), Vector3::ZERO, Vector3::UNIT_Y);

	cameraComponent.setProjection(Math::ONE_PI*45/180, 960.0f/640.0f, 1.0f, 10000.0f);
	
	editorGizmoRenderer.add(editorGizmo);
}

EditorEntity::~EditorEntity()
{
	editorGizmoRenderer.remove(editorGizmo);
}

EditorCameraComponent &EditorEntity::getCameraComponent()
{
	return cameraComponent;
}

EditorGizmo &EditorEntity::getEditorGizmo()
{
	return editorGizmo;
}

bool EditorEntity::onConstruct()
{
	return true;
}

void EditorEntity::onStart()
{
}

void EditorEntity::onPause()
{
}

void EditorEntity::onResume()
{
}

void EditorEntity::onUpdate(float dt)
{
}

void EditorEntity::onStop()
{
}

void EditorEntity::onDestruct()
{
}

void EditorEntity::touchpadEvent(const Input::TouchpadEvent &evt)
{
}

void EditorEntity::keypadEvent(const Input::GamepadEvent &evt)
{
}

void EditorEntity::acceleratorEvent(const Input::AcceleratorEvent &evt)
{
}