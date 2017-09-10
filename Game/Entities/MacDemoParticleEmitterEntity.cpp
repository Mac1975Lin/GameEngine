///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoParticleEmitterEntity.h"
using namespace IDreamSky;

MacDemoParticleEmitterEntity::MacDemoParticleEmitterEntity()
: particleEmitterRenderer(*this)
, particleEmitter(*this)
, keypadMethod(this, &MacDemoParticleEmitterEntity::keypadEvent)
{
	particleEmitterRenderer.add(particleEmitter);
}

MacDemoParticleEmitterEntity::~MacDemoParticleEmitterEntity()
{
	particleEmitterRenderer.remove(particleEmitter);
}

bool MacDemoParticleEmitterEntity::onConstruct()
{
	return true;
}

void MacDemoParticleEmitterEntity::onStart()
{
}

void MacDemoParticleEmitterEntity::onPause()
{
}

void MacDemoParticleEmitterEntity::onResume()
{
}

void MacDemoParticleEmitterEntity::onUpdate(float dt)
{
}

void MacDemoParticleEmitterEntity::onStop()
{
}

void MacDemoParticleEmitterEntity::onDestruct()
{
}

void MacDemoParticleEmitterEntity::keypadEvent(const Input::GamepadEvent &evt)
{
	if(evt.event==Input::EVENT_GAMEPAD_KEY_DOWN)
	{
		if(evt.keyCode==Input::KEYPAD0_UP)
		{
			if(particleEmitter.getEmitting())
				particleEmitter.setEmitting(false);
			else
				particleEmitter.setEmitting(true);
		}
	}
}
