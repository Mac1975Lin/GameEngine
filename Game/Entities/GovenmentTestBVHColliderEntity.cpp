///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "GovenmentTestBVHColliderEntity.h"
using namespace IDreamSky;

GovenmentTestBVHColliderEntity::GovenmentTestBVHColliderEntity()
: triangleSceneCollider(*this)
, triangleSceneRenderer(*this)
, triangleScene(*this)
{
	triangleSceneRenderer.add(triangleScene);
}

GovenmentTestBVHColliderEntity::~GovenmentTestBVHColliderEntity()
{
}

bool GovenmentTestBVHColliderEntity::onConstruct()
{
	return true;
}

void GovenmentTestBVHColliderEntity::onStart()
{
}

void GovenmentTestBVHColliderEntity::onPause()
{
}

void GovenmentTestBVHColliderEntity::onResume()
{
}

void GovenmentTestBVHColliderEntity::onUpdate(float dt)
{
}

void GovenmentTestBVHColliderEntity::onStop()
{
}

void GovenmentTestBVHColliderEntity::onDestruct()
{
}