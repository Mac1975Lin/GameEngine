///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#ifndef _MacDemoDiffuseMapSpecularMapCubeEntity_h_
#define _MacDemoDiffuseMapSpecularMapCubeEntity_h_

#include <MagnumEngine.h>
using namespace IDreamSky;

class MacDemoDiffuseMapSpecularMapCubeEntity : public Entity
{
public:
	MacDemoDiffuseMapSpecularMapCubeEntity();
	virtual ~MacDemoDiffuseMapSpecularMapCubeEntity();
	
	DECLARE_ENTITY(MacDemoDiffuseMapSpecularMapCubeEntity);
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
	DiffuseMapSpecularMapCubeRenderer	diffuseMapSpecularMapCubeRenderer;
	DiffuseMapSpecularMapCube				diffuseMapSpecularMapCube;
};

#endif