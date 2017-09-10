///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoSphereColliderCubeEntity.h"
using namespace IDreamSky;

MacDemoSphereColliderCubeEntity::MacDemoSphereColliderCubeEntity()
: cubeRenderer(*this)
, cube(*this)
, sphere3Collider(*this)
{
	cubeRenderer.add(cube);
}

MacDemoSphereColliderCubeEntity::~MacDemoSphereColliderCubeEntity()
{
	cubeRenderer.remove(cube);
}

bool MacDemoSphereColliderCubeEntity::onConstruct()
{
	return true;
}

void MacDemoSphereColliderCubeEntity::onStart()
{
}

void MacDemoSphereColliderCubeEntity::onPause()
{
}

void MacDemoSphereColliderCubeEntity::onResume()
{
}

void MacDemoSphereColliderCubeEntity::onUpdate(float dt)
{
}

void MacDemoSphereColliderCubeEntity::onStop()
{
}

void MacDemoSphereColliderCubeEntity::onDestruct()
{
}