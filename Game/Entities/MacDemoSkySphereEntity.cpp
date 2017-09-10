///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoSkySphereEntity.h"
using namespace IDreamSky;

MacDemoSkySphereEntity::MacDemoSkySphereEntity()
: skySphereRenderer(*this)
, skySphere(*this)
{
	skySphereRenderer.add(skySphere);
}

MacDemoSkySphereEntity::~MacDemoSkySphereEntity()
{
	skySphereRenderer.remove(skySphere);
}

bool MacDemoSkySphereEntity::onConstruct()
{
	return true;
}

void MacDemoSkySphereEntity::onStart()
{
}

void MacDemoSkySphereEntity::onPause()
{
}

void MacDemoSkySphereEntity::onResume()
{
}

void MacDemoSkySphereEntity::onUpdate(float dt)
{
}

void MacDemoSkySphereEntity::onStop()
{
}

void MacDemoSkySphereEntity::onDestruct()
{
}
