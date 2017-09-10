///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoCubeEntity.h"
using namespace IDreamSky;

MacDemoCubeEntity::MacDemoCubeEntity()
: cubeRenderer(*this)
, cube(*this)
{
	cubeRenderer.add(cube);
}

MacDemoCubeEntity::~MacDemoCubeEntity()
{
	cubeRenderer.remove(cube);
}

bool MacDemoCubeEntity::onConstruct()
{
	return true;
}

void MacDemoCubeEntity::onStart()
{
}

void MacDemoCubeEntity::onPause()
{
}

void MacDemoCubeEntity::onResume()
{
}

void MacDemoCubeEntity::onUpdate(float dt)
{
}

void MacDemoCubeEntity::onStop()
{
}

void MacDemoCubeEntity::onDestruct()
{
}