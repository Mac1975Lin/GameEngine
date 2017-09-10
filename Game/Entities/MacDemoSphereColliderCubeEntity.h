///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#ifndef _MacDemoSphereColliderCubeEntity_h_
#define _MacDemoSphereColliderCubeEntity_h_

#include <MagnumEngine.h>
using namespace IDreamSky;

class MacDemoSphereColliderCubeEntity : public Entity
{
public:
	MacDemoSphereColliderCubeEntity();
	virtual ~MacDemoSphereColliderCubeEntity();

	DECLARE_ENTITY(MacDemoSphereColliderCubeEntity);
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
	CubeRenderer		cubeRenderer;
	Cube				cube;

	Sphere3Collider		sphere3Collider;
};

#endif