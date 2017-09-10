///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoTestReflectionEntity.h"
using namespace IDreamSky;

MacDemoTestReflectionEntity::MacDemoTestReflectionEntity()
: cubeRenderer(*this)
, cube(*this)
, boxCollider(*this)
{
	cubeRenderer.add(cube);
}

MacDemoTestReflectionEntity::~MacDemoTestReflectionEntity()
{
	/*
	float scale = getFLOAT();

	boxCollider.setExtent(scale*boxCollider.getExtent());
	cube.setExtent(scale*cube.getExtent());
	*/
	cubeRenderer.remove(cube);
}

bool MacDemoTestReflectionEntity::onConstruct()
{
	return true;
}

void MacDemoTestReflectionEntity::onStart()
{
}

void MacDemoTestReflectionEntity::onPause()
{
}

void MacDemoTestReflectionEntity::onResume()
{
}

void MacDemoTestReflectionEntity::onUpdate(float dt)
{
}

void MacDemoTestReflectionEntity::onStop()
{
}

void MacDemoTestReflectionEntity::onDestruct()
{
}