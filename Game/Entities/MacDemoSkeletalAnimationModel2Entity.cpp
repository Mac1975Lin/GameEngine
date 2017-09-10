///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoSkeletalAnimationModel2Entity.h"
using namespace IDreamSky;

MacDemoSkeletalAnimationModel2Entity::MacDemoSkeletalAnimationModel2Entity()
: skeletalAnimationModel2Renderer(*this)
, skeletalAnimationModel2Component(*this)
{
	skeletalAnimationModel2Renderer.add(skeletalAnimationModel2Component);
	skeletalAnimationModel2Component.setColor(ColorRGBA(1.0, 0.0f, 0.0f, 0.0f));
	//skeletalAnimationModel2Component.setColor(ColorRGBA(0.0, 1.0f, 0.0f, 0.0f));
	//skeletalAnimationModel2Component.setColor(ColorRGBA(0.0, 0.0f, 1.0f, 0.0f));
}

MacDemoSkeletalAnimationModel2Entity::~MacDemoSkeletalAnimationModel2Entity()
{
	skeletalAnimationModel2Renderer.remove(skeletalAnimationModel2Component);
}

bool MacDemoSkeletalAnimationModel2Entity::onConstruct()
{
	return true;
}

void MacDemoSkeletalAnimationModel2Entity::onStart()
{
}

void MacDemoSkeletalAnimationModel2Entity::onPause()
{
}

void MacDemoSkeletalAnimationModel2Entity::onResume()
{
}

void MacDemoSkeletalAnimationModel2Entity::onUpdate(float dt)
{
}

void MacDemoSkeletalAnimationModel2Entity::onStop()
{
}

void MacDemoSkeletalAnimationModel2Entity::onDestruct()
{
}
