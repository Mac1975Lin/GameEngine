///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#ifndef _GovenmentTestBVHColliderEntity_h_
#define _GovenmentTestBVHColliderEntity_h_

#include <MagnumEngine.h>
using namespace IDreamSky;

class GovenmentTestBVHColliderEntity : public Entity
{
public:
	GovenmentTestBVHColliderEntity();
	virtual ~GovenmentTestBVHColliderEntity();
	
	DECLARE_ENTITY(GovenmentTestBVHColliderEntity);
protected:
private:
	virtual bool onConstruct();
	virtual void onStart();
	virtual void onPause();
	virtual void onResume();
	virtual void onUpdate(float dt);
	virtual void onStop();
	virtual void onDestruct();

	/////////////////////////////////////////////////////
public:
protected:
private:
	TriangleScene				triangleScene;
	TriangleSceneRenderer		triangleSceneRenderer;
	TriangleSceneCollider		triangleSceneCollider;
};

#endif