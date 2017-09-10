///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoAudioListenerEntity.h"
using namespace IDreamSky;

MacDemoAudioListenerEntity::MacDemoAudioListenerEntity()
: audioListener(*this)
{
}

MacDemoAudioListenerEntity::~MacDemoAudioListenerEntity()
{
}

bool MacDemoAudioListenerEntity::onConstruct()
{
	return true;
}

void MacDemoAudioListenerEntity::onStart()
{
}

void MacDemoAudioListenerEntity::onPause()
{
}

void MacDemoAudioListenerEntity::onResume()
{
}

void MacDemoAudioListenerEntity::onUpdate(float dt)
{
}

void MacDemoAudioListenerEntity::onStop()
{
}

void MacDemoAudioListenerEntity::onDestruct()
{
}

void MacDemoAudioListenerEntity::disableAudio()
{
	//audioListener.disable();
}

void MacDemoAudioListenerEntity::enableAudio()
{
	//audioListener.enable();
}

bool MacDemoAudioListenerEntity::isAudioEnable() const
{
	//return audioListener.isEnable();
	return true;
}