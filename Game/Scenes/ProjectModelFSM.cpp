///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "ProjectModelFSM.h"
#include "ProjectModel.h"
using namespace IDreamSky;

#if defined(WIN32_PLATFORM)

ProjectModelFSM::ProjectModelFSM(ProjectModel &projectModel)
: StateMachine<ProjectModel>(projectModel)
{
	/////////////////////////////////////////////////////
	// GlobalState
	setGlobalState(&globalState);

	/////////////////////////////////////////////////////
	// Initialization
	addState("Start"					, &startState				);
	addState("CheckingRawAssets"		, &checkingRawAssetsState	);
	addState("UpdatingAssets"			, &updatingAssetsState		);
	addState("ValidateEntities"			, &validateEntitiesState	);

	/////////////////////////////////////////////////////
	// File Menu
	addState("FileProjectNew"			, &fileProjectNewState		);
	addState("FileProjectOpen"			, &fileProjectOpenState		);
	addState("FileProjectSave"			, &fileProjectSaveState		);
	addState("FileSceneNew"				, &fileSceneNewState		);	
	addState("FileSceneOpen"			, &fileSceneOpenState		);	
	addState("FileSceneSave"			, &fileSceneSaveState		);	
	addState("FileSceneSaveAs"			, &fileSceneSaveAsState		);	
	addState("FileSceneDelete"			, &fileSceneDeleteState		);
	addState("FilePrefabOpen"			, &filePrefabOpenState		);
	addState("FilePrefabSave"			, &filePrefabSaveState		);
	addState("FileExit"					, &fileExitState			);

	/////////////////////////////////////////////////////
	// Edit Menu
	addState("EditCut"					, &editCutState				);
	addState("EditCopy"					, &editCopyState			);
	addState("EditPaste"				, &editPasteState			);
	addState("EditDuplicate"			, &editDuplicateState		);
	addState("EditDelete"				, &editDeleteState			);

	/////////////////////////////////////////////////////
	// Debug Menu
	addState("DebugRun"					, &debugRunState			);
	addState("DebugStop"				, &debugStopState			);

	/////////////////////////////////////////////////////
	// Operation Menu
	addState("OperationSelectEntity"		, &operationSelectEntityState			);
	addState("OperationMoveSelected"		, &operationMoveSelectedState			);
	addState("OperationRotateSelected"		, &operationRotateSelectedState			);
	addState("OperationScaleSelected"		, &operationScaleSelectedState			);
	addState("OperationDuplicate"			, &operationFrameSelectedState			);
	addState("OperationFind"				, &operationFindState					);
	addState("OperationSelectAll"			, &operationSelectAllState				);
	addState("OperationZoom"				, &operationZoomState					);
	addState("OperationZoomExtent"			, &operationZoomExtentState				);
	addState("OperationZoomExtentSelected"	, &operationZoomExtentSelectedState		);
	addState("OperationZoomRegion"			, &operationZoomRegionState				);
	addState("OperationFov"					, &operationFovState					);
	addState("OperationPan"					, &operationPanState					);
	addState("OperationOrbit"				, &operationOrbitState					);
	addState("OperationOrbitSelected"		, &operationOrbitSelectedState			);
}

ProjectModelFSM::~ProjectModelFSM()
{
}


#elif defined(ANDROID_PLATFORM)
// ...
#elif defined(IOS_PLATFORM)
// ...
#endif