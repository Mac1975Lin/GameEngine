///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoDiffuseMapSpecularMapCubeEntity.h"
using namespace IDreamSky;

MacDemoDiffuseMapSpecularMapCubeEntity::MacDemoDiffuseMapSpecularMapCubeEntity()
: diffuseMapSpecularMapCubeRenderer(*this)
, diffuseMapSpecularMapCube(*this)
{
	diffuseMapSpecularMapCubeRenderer.add(diffuseMapSpecularMapCube);
}

MacDemoDiffuseMapSpecularMapCubeEntity::~MacDemoDiffuseMapSpecularMapCubeEntity()
{
	diffuseMapSpecularMapCubeRenderer.remove(diffuseMapSpecularMapCube);
}

bool MacDemoDiffuseMapSpecularMapCubeEntity::onConstruct()
{
	return true;
}

void MacDemoDiffuseMapSpecularMapCubeEntity::onStart()
{
}

void MacDemoDiffuseMapSpecularMapCubeEntity::onStop()
{
}

void MacDemoDiffuseMapSpecularMapCubeEntity::onUpdate(float dt)
{
}

void MacDemoDiffuseMapSpecularMapCubeEntity::onPause()
{
}

void MacDemoDiffuseMapSpecularMapCubeEntity::onResume()
{
}

void MacDemoDiffuseMapSpecularMapCubeEntity::onDestruct()
{
}