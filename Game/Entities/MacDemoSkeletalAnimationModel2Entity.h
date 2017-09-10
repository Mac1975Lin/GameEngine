///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#ifndef _MacDemoSkeletalAnimationModel2Entity_h_
#define _MacDemoSkeletalAnimationModel2Entity_h_

#include <MagnumEngine.h>
using namespace IDreamSky;

class MacDemoSkeletalAnimationModel2Entity : public Entity
{
public:
	MacDemoSkeletalAnimationModel2Entity();
	virtual ~MacDemoSkeletalAnimationModel2Entity();

	DECLARE_ENTITY(MacDemoSkeletalAnimationModel2Entity);
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
	SkeletalAnimationModel2Component		skeletalAnimationModel2Component;
	SkeletalAnimationModel2Renderer			skeletalAnimationModel2Renderer;
};

#endif