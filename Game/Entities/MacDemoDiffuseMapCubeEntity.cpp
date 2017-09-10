///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoDiffuseMapCubeEntity.h"
using namespace IDreamSky;

MacDemoDiffuseMapCubeEntity::MacDemoDiffuseMapCubeEntity()
: diffuseMapCubeRenderer(*this)
, diffuseMapCube(*this)
{
	diffuseMapCubeRenderer.add(diffuseMapCube);
}

MacDemoDiffuseMapCubeEntity::~MacDemoDiffuseMapCubeEntity()
{
	diffuseMapCubeRenderer.remove(diffuseMapCube);
}

bool MacDemoDiffuseMapCubeEntity::onConstruct()
{
	return true;
}

void MacDemoDiffuseMapCubeEntity::onStart()
{
}

void MacDemoDiffuseMapCubeEntity::onPause()
{
}

void MacDemoDiffuseMapCubeEntity::onResume()
{
}

void MacDemoDiffuseMapCubeEntity::onUpdate(float dt)
{
}

void MacDemoDiffuseMapCubeEntity::onStop()
{
}

void MacDemoDiffuseMapCubeEntity::onDestruct()
{
}