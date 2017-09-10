///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoBGMEntity.h"
using namespace IDreamSky;

MacDemoBGMEntity::MacDemoBGMEntity()
: audioStream(*this)
{
}

MacDemoBGMEntity::~MacDemoBGMEntity()
{
}

bool MacDemoBGMEntity::onConstruct()
{
	return true;
}

void MacDemoBGMEntity::onStart()
{
	audioStream.play(true);
}

void MacDemoBGMEntity::onPause()
{
}

void MacDemoBGMEntity::onResume()
{
}

void MacDemoBGMEntity::onUpdate(float dt)
{
}

void MacDemoBGMEntity::onStop()
{
}

void MacDemoBGMEntity::onDestruct()
{
}

void MacDemoBGMEntity::disableAudio()
{
}

void MacDemoBGMEntity::enableAudio()
{
}

bool MacDemoBGMEntity::isAudioEnable() const
{
    return true;
}