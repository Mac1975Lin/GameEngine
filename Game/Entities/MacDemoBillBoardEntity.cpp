///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "MacDemoBillBoardEntity.h"
using namespace IDreamSky;

MacDemoBillBoardEntity::MacDemoBillBoardEntity()
: billBoardRenderer(*this)
, billBoard(*this)
{
	billBoardRenderer.add(billBoard);
}

MacDemoBillBoardEntity::~MacDemoBillBoardEntity()
{
	billBoardRenderer.remove(billBoard);
}

bool MacDemoBillBoardEntity::onConstruct()
{
	//billBoard.setAlignmentMode(BillBoard::CAMERA_Z);
	//billBoard.setAlignmentMode(BillBoard::ROTATE_ABOUT_CAMERA);
	//billBoard.setAlignmentMode(BillBoard::ROTATE_ABOUT_AXIS);
	//billBoard.setAlignmentAxis(Vector3(0, 1, 0));
	//billBoard.setAlignmentMode(BillBoard::ROTATE_ABOUT_PIVOT);
	//billBoard.setRotationPivot(Vector3(10, 0, 10));

	return true;
}

void MacDemoBillBoardEntity::onStart()
{
}

void MacDemoBillBoardEntity::onPause()
{
}

void MacDemoBillBoardEntity::onResume()
{
}

void MacDemoBillBoardEntity::onUpdate(float dt)
{
}

void MacDemoBillBoardEntity::onStop()
{
}

void MacDemoBillBoardEntity::onDestruct()
{
}
