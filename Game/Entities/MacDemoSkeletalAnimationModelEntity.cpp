///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoSkeletalAnimationModelEntity.h"
using namespace IDreamSky;

MacDemoSkeletalAnimationModelEntity::MacDemoSkeletalAnimationModelEntity()
: skeletalAnimationModelRenderer(*this)
, skeletalAnimationModelComponent(*this)
{
	skeletalAnimationModelRenderer.add(skeletalAnimationModelComponent);
}

MacDemoSkeletalAnimationModelEntity::~MacDemoSkeletalAnimationModelEntity()
{
	skeletalAnimationModelRenderer.remove(skeletalAnimationModelComponent);
}

bool MacDemoSkeletalAnimationModelEntity::onConstruct()
{
	skeletalAnimationModelComponent.getSkeletalAnimationBase()->play();

	return true;
}

void MacDemoSkeletalAnimationModelEntity::onStart()
{
}

void MacDemoSkeletalAnimationModelEntity::onPause()
{
}

void MacDemoSkeletalAnimationModelEntity::onResume()
{
}

void MacDemoSkeletalAnimationModelEntity::onUpdate(float dt)
{
}

void MacDemoSkeletalAnimationModelEntity::onStop()
{
}

void MacDemoSkeletalAnimationModelEntity::onDestruct()
{
}
