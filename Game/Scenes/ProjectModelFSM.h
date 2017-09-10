///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2016, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 14/Jun/2016											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#ifndef _ProjectModelFSM_h_
#define _ProjectModelFSM_h_

#include "Stage.h"
#include "StateMachine.h"
#include "GlobalState.h"
#include "StartState.h"
#include "UpdateAssetsState.h"
#include "FileMenuState.h"
#include "EditMenuState.h"
#include "DebugMenuState.h"
#include "OperationMenuState.h"
using namespace IDreamSky;

#if defined(WIN32_PLATFORM)


namespace IDreamSky
{
	
class ProjectModel;

class ProjectModelFSM : public StateMachine<ProjectModel>
{
public:
	ProjectModelFSM(ProjectModel &projectModel);
	virtual ~ProjectModelFSM();
protected:
private:
	/////////////////////////////////////////////////////
	// GlobalState
	GlobalState						globalState;

	/////////////////////////////////////////////////////
	// Initialization
	StartState						startState;
	CheckingRawAssetsState			checkingRawAssetsState;
	UpdatingAssetsState				updatingAssetsState;
	ValidateEntitiesState			validateEntitiesState;

	/////////////////////////////////////////////////////
	// File Menu
	FileProjectNewState				fileProjectNewState;
	FileProjectOpenState			fileProjectOpenState;
	FileProjectSaveState			fileProjectSaveState;
	FileSceneNewState				fileSceneNewState;
	FileSceneOpenState				fileSceneOpenState;
	FileSceneSaveState				fileSceneSaveState;
	FileSceneSaveAsState			fileSceneSaveAsState;
	FileSceneDeleteState			fileSceneDeleteState;
	FilePrefabOpenState				filePrefabOpenState;
	FilePrefabSaveState				filePrefabSaveState;
	FileExitState					fileExitState;

	/////////////////////////////////////////////////////
	// Edit Menu
	EditCutState					editCutState;
	EditCopyState					editCopyState;
	EditPasteState					editPasteState;
	EditDuplicateState				editDuplicateState;
	EditDeleteState					editDeleteState;

	/////////////////////////////////////////////////////
	// Operation Menu
	SelectEntityState				operationSelectEntityState;
	MoveSelectedState				operationMoveSelectedState;
	RotateSelectedState				operationRotateSelectedState;
	ScaleSelectedState				operationScaleSelectedState;
	OperationFrameSelectedState		operationFrameSelectedState;
	OperationFindState				operationFindState;
	OperationSelectAllState			operationSelectAllState;
	ZoomState						operationZoomState;
	ZoomExtentState					operationZoomExtentState;
	ZoomExtentSelectedState			operationZoomExtentSelectedState;
	ZoomRegionState					operationZoomRegionState;
	FovState						operationFovState;
	PanState						operationPanState;
	OrbitState						operationOrbitState;
	OrbitSelectedState				operationOrbitSelectedState;

	/////////////////////////////////////////////////////
	// Debug Menu
	DebugRunState					debugRunState;
	DebugStopState					debugStopState;
};

};

#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif

#endif