#include "Localization.h"

wxString chineseText[] =
{
	 wxT("關卡編輯器"),
	 wxT("場景"),
	 wxT("資源"),
	 wxT("實體"),
	 wxT("信息"),
	 wxT("層次結構"),
	 wxT("屬性顯示"),
	 ////////////////////////////////////////////////
	 wxT("檔案"),
	 wxT("專案"),
	 wxT("新建.."),
	 wxT("打開.."),
	 wxT("存檔.."),
	 wxT("場景"),
	 wxT("新建.."),
	 wxT("打開.."),
	 wxT("存儲.."),
	 wxT("存檔為.."),
	 wxT("刪除.."),
	 wxT("預構件"),
	 wxT("打開.."),
	 wxT("存儲.."),
	 wxT("離開"),
	 ////////////////////////////////////////////////
	 wxT("編輯"),
	 wxT("復原"),
	 wxT("重做"),
	 wxT("剪取"),
	 wxT("復製"),
	 wxT("粘貼"),
	 wxT("復製粘貼"),
	 wxT("刪除"),
	 ////////////////////////////////////////////////
	 wxT("執行檔"),
	 wxT("WIN32.."),
	 wxT("IOS.."),
	 wxT("Android.."),
	 wxT("WINMobile.."),
	 wxT("PlayStation 3.."),
	 wxT("PlayStation Portable.."),
	 wxT("PlayStastion VITA.."),
	 wxT("Nintendo Wii.."),
	 wxT("Nintendo WiiU.."),
	 ////////////////////////////////////////////////
	 wxT("除錯"),
	 wxT("執行"),
	 wxT("停止"),
	 wxT("暫停"),
	 wxT("單步執行"),
	 ////////////////////////////////////////////////
	 wxT("帮助"),
	 wxT("帮助"),
	 wxT("關於"),
	 ////////////////////////////////////////////////
	 wxT("操作"),
	 wxT("選擇模式"),
	 wxT("移動"),
	 wxT("轉動"),
	 wxT("縮放"),
	 wxT("FrameSelected"),
	 wxT("Find"),
	 wxT("SelectAll"),
	 wxT("(Zoom)"),
	 wxT("(Zoom Extent)"),
	 wxT("(Zoom Extent Selected)"),
	 wxT("(Zoom Region)"),
	 wxT("(Fov)"),
	 wxT("(Pan)"),
	 wxT("(Orbit)"),
	 wxT("(Orbit Selected)"),
	 ////////////////////////////////////////////////
	 wxT("雜項 A"),
	 wxT("更新資源"),
	 wxT("資源壓縮模式切換"),
	 wxT("雜項 A 1"),
	 wxT("雜項 A 2"),
	 wxT("雜項 A 3"),
	 wxT("雜項 A 4"),
	 wxT("雜項 A 5"),
	 wxT("雜項 A 6"),
	 wxT("雜項 A 7"),
	 wxT("雜項 A 8"),
	 wxT("雜項 A 9"),
	 ////////////////////////////////////////////////
	 wxT("雜項 B"),
	 wxT("雜項 B 0"),
	 wxT("雜項 B 1"),
	 wxT("雜項 B 2"),
	 wxT("雜項 B 3"),
	 wxT("雜項 B 4"),
	 wxT("雜項 B 5"),
	 wxT("雜項 B 6"),
	 wxT("雜項 B 7"),
	 wxT("雜項 B 8"),
	 wxT("雜項 B 9"),
	 
	 ////////////////////////////////////////////////
	 wxT("準備"),

	 //////////////////////////////////////////////////////////////
	 wxT("局部座標"),
	 wxT("父座標"),
	 wxT("世界座標"),
	 wxT("視點座標"),

	 ////////////////////////////////////////////////
	 wxT("DreamEngine的關卡編輯器\n\n"), 
	 wxT("關於DreamEngine關卡編輯器"), 

	 ////////////////////////////////////////////////
	 wxT("無壓縮"),
	 wxT("壓縮等級 0"),
	 wxT("壓縮等級 1"),
	 wxT("壓縮等級 2")
};

wxString englishText[] =
{
	 wxT("Level Editor"),
	 wxT("Scene"),
	 wxT("Resource"),
	 wxT("Entity"),
	 wxT("Message"),
	 wxT("Hierachy"),
	 wxT("Inspector"),
	 ////////////////////////////////////////////////
	 wxT("File"),
	 wxT("Project"),
	 wxT("New.."),
	 wxT("Open.."),
	 wxT("Save.."),
	 wxT("Scene"),
	 wxT("New.."),
	 wxT("Open.."),
	 wxT("Save.."),
	 wxT("Save As.."),
	 wxT("Delete.."),
	 wxT("Prefab"),
	 wxT("Open.."),
	 wxT("Save.."),
	 wxT("Exit"),
	 ////////////////////////////////////////////////
	 wxT("Edit"),
	 wxT("Undo"),
	 wxT("Redo"),
	 wxT("Cut"),
	 wxT("Copy"),
	 wxT("Paste"),
	 wxT("Duplicate"),
	 wxT("Delete"),
	 ////////////////////////////////////////////////
	 wxT("Executable"),
	 wxT("WIN32.."),
	 wxT("IOS.."),
	 wxT("Android.."),
	 wxT("WINMobile.."),
	 wxT("PlayStation 3.."),
	 wxT("PlayStation Portable.."),
	 wxT("PlayStastion VITA.."),
	 wxT("Nintendo Wii.."),
	 wxT("Nintendo WiiU.."),
	 ////////////////////////////////////////////////
	 wxT("Debug"),
	 wxT("Run"),
	 wxT("Stop"),
	 wxT("Pause"),
	 wxT("Step"),
	 ////////////////////////////////////////////////
	 wxT("Help"),
	 wxT("Help"),
	 wxT("About..."),
	 ////////////////////////////////////////////////
	 wxT("Operation"),
	 wxT("Selection"),
	 wxT("Move Selected"),
	 wxT("Rotate Selected"),
	 wxT("Scale Selected"),
	 wxT("FrameSelected"),
	 wxT("Find"),
	 wxT("SelectAll"),
	 wxT("Zoom"),
	 wxT("Zoom Extent"),
	 wxT("Zoom Extent Selected"),
	 wxT("Zoom Region"),
	 wxT("Fov"),
	 wxT("Pan"),
	 wxT("Orbit"),
	 wxT("Orbit Selected"),
	 ////////////////////////////////////////////////
	 wxT("Misc A"),
	 wxT("Update Assets"),
	 wxT("Toggle Compress Mode"),
	 wxT("Misc A 1"),
	 wxT("Misc A 2"),
	 wxT("Misc A 3"),
	 wxT("Misc A 4"),
	 wxT("Misc A 5"),
	 wxT("Misc A 6"),
	 wxT("Misc A 7"),
	 wxT("Misc A 8"),
	 wxT("Misc A 9"),
	 ////////////////////////////////////////////////
	 wxT("Misc B"),
	 wxT("Misc B 0"),
	 wxT("Misc B 1"),
	 wxT("Misc B 2"),
	 wxT("Misc B 3"),
	 wxT("Misc B 4"),
	 wxT("Misc B 5"),
	 wxT("Misc B 6"),
	 wxT("Misc B 7"),
	 wxT("Misc B 8"),
	 wxT("Misc B 9"),
	 
	 ////////////////////////////////////////////////
	 wxT("Ready"),

	 ////////////////////////////////////////////////
	 wxT("Local"),
	 wxT("Parent"),
	 wxT("World"),
	 wxT("View"),

	 ////////////////////////////////////////////////
	 wxT("DreamEngine Lever Editor\n\n"), 
	 wxT("About"), 

	 ////////////////////////////////////////////////
	 wxT("Compressed Level0"),
	 wxT("Compressed Level1"),
	 wxT("Compressed Level2"),
	 wxT("Compressed Level3")
};

void Localization::setLangunage(Langunage lang)
{
	switch(lang)
	{
		case ENGLISH:
			texts = englishText;
			break;
		case CHINESE:
			texts = chineseText;			
			break;
	};
}

//wxString *Localization::texts	= englishText;
wxString *Localization::texts	= chineseText;

wxString &Localization::getTopWindowTitle					()	{ return texts[ 0]; };
wxString &Localization::getSceneViewTitle					()	{ return texts[ 1]; };
wxString &Localization::getResourceImporterViewTitle		()	{ return texts[ 2]; };
wxString &Localization::getEntityViewCreatorsTitle			()	{ return texts[ 3]; };
wxString &Localization::getDebugViewCreatorsTitle			()	{ return texts[ 4]; };
wxString &Localization::getHierachyViewTitle				()	{ return texts[ 5]; };
wxString &Localization::getInspectorViewCreatorsTitle		()	{ return texts[ 6]; };
wxString &Localization::getFileMenu							()	{ return texts[ 7]; };
wxString &Localization::getFileProject						()	{ return texts[ 8]; };
wxString &Localization::getFileProjectNew					()	{ return texts[ 9]; };
wxString &Localization::getFileProjectNewOpen				()	{ return texts[10]; };
wxString &Localization::getFileProjectNewSave				()	{ return texts[11]; };
wxString &Localization::getFileScene						()	{ return texts[12]; };
wxString &Localization::getFileSceneNew						()	{ return texts[13]; };
wxString &Localization::getFileSceneOpen					()	{ return texts[14]; };
wxString &Localization::getFileSceneSave					()	{ return texts[15]; };
wxString &Localization::getFileSceneSaveAs					()	{ return texts[16]; };
wxString &Localization::getFileSceneDelete					()	{ return texts[17]; };
wxString &Localization::getFilePrefab						()	{ return texts[18]; };
wxString &Localization::getFilePrefabOpen					()	{ return texts[19]; };
wxString &Localization::getFilePrefabSave					()	{ return texts[20]; };
wxString &Localization::getFileExit							()	{ return texts[21]; };
wxString &Localization::getEditMenu							()	{ return texts[22]; };
wxString &Localization::getEditUndo							()	{ return texts[23]; };
wxString &Localization::getEditRedo							()	{ return texts[24]; };
wxString &Localization::getEditCut							()	{ return texts[25]; };
wxString &Localization::getEditCopy							()	{ return texts[26]; };
wxString &Localization::getEditPaste						()	{ return texts[27]; };
wxString &Localization::getEditDuplicate					()	{ return texts[28]; };
wxString &Localization::getEditDelete						()	{ return texts[29]; };
wxString &Localization::getBuildMenu						()	{ return texts[30]; };
wxString &Localization::getBuildWIN32						()	{ return texts[31]; };
wxString &Localization::getBuildIOS							()	{ return texts[32]; };
wxString &Localization::getBuildANDROID						()	{ return texts[33]; };
wxString &Localization::getBuildWINMobile					()	{ return texts[34]; };
wxString &Localization::getBuildPS3							()	{ return texts[35]; };
wxString &Localization::getBuildPSP							()	{ return texts[36]; };
wxString &Localization::getBuildPSV							()	{ return texts[37]; };
wxString &Localization::getBuildWii							()	{ return texts[38]; };
wxString &Localization::getBuildWiiU						()	{ return texts[39]; };
wxString &Localization::getDebugMenu						()	{ return texts[40]; };
wxString &Localization::getDebugRun							()	{ return texts[41]; };
wxString &Localization::getDebugStop						()	{ return texts[42]; };
wxString &Localization::getDebugPause						()	{ return texts[43]; };
wxString &Localization::getDebugStep						()	{ return texts[44]; };
wxString &Localization::getHelpMenu							()	{ return texts[45]; };
wxString &Localization::getHelpHelp							()	{ return texts[46]; };
wxString &Localization::getHelpAbout						()	{ return texts[47]; };
wxString &Localization::getOperationMenu					()	{ return texts[48]; };
wxString &Localization::getOperationSelection				()	{ return texts[49]; };
wxString &Localization::getOperationMoveSelected			()	{ return texts[50]; };
wxString &Localization::getOperationRotateSelected			()	{ return texts[51]; };
wxString &Localization::getOperationScaleSelected			()	{ return texts[52]; };
wxString &Localization::getEditFrameSelected				()	{ return texts[53]; };
wxString &Localization::getEditFind							()	{ return texts[54]; };
wxString &Localization::getEditSelectAll					()	{ return texts[55]; };
wxString &Localization::getOperationZoom					()	{ return texts[56]; };
wxString &Localization::getOperationZoomExtent				()	{ return texts[57]; };
wxString &Localization::getOperationZoomExtentSelected		()	{ return texts[58]; };
wxString &Localization::getOperationZoomRegion				()	{ return texts[59]; };
wxString &Localization::getOperationFov						()	{ return texts[60]; };
wxString &Localization::getOperationPan						()	{ return texts[61]; };
wxString &Localization::getOperationOrbit					()	{ return texts[62]; };
wxString &Localization::getOperationOrbitSelected			()	{ return texts[63]; };

wxString &Localization::getMenuMiscA						()	{ return texts[64]; };
wxString &Localization::getMenuMiscAUpdateAssets			()	{ return texts[65]; };
wxString &Localization::getMenuMiscToggleCompressMode		()	{ return texts[66]; };
wxString &Localization::getMenuMiscA1						()	{ return texts[67]; };
wxString &Localization::getMenuMiscA2						()	{ return texts[68]; };
wxString &Localization::getMenuMiscA3						()	{ return texts[69]; };
wxString &Localization::getMenuMiscA4						()	{ return texts[70]; };
wxString &Localization::getMenuMiscA5						()	{ return texts[71]; };
wxString &Localization::getMenuMiscA6						()	{ return texts[72]; };
wxString &Localization::getMenuMiscA7						()	{ return texts[73]; };
wxString &Localization::getMenuMiscA8						()	{ return texts[74]; };
wxString &Localization::getMenuMiscA9						()	{ return texts[75]; };

wxString &Localization::getMenuMiscB						()	{ return texts[76]; };
wxString &Localization::getMenuMiscB0						()	{ return texts[77]; };
wxString &Localization::getMenuMiscB1						()	{ return texts[78]; };
wxString &Localization::getMenuMiscB2						()	{ return texts[79]; };
wxString &Localization::getMenuMiscB3						()	{ return texts[80]; };
wxString &Localization::getMenuMiscB4						()	{ return texts[81]; };
wxString &Localization::getMenuMiscB5						()	{ return texts[82]; };
wxString &Localization::getMenuMiscB6						()	{ return texts[83]; };
wxString &Localization::getMenuMiscB7						()	{ return texts[84]; };
wxString &Localization::getMenuMiscB8						()	{ return texts[85]; };
wxString &Localization::getMenuMiscB9						()	{ return texts[86]; };

wxString &Localization::getStatusBarReady					()	{ return texts[87]; };
wxString &Localization::getCoordSysLocal					()	{ return texts[88]; };
wxString &Localization::getCoordSysParent					()	{ return texts[89]; };
wxString &Localization::getCoordSysWorld					()	{ return texts[90]; };
wxString &Localization::getCoordSysView						()	{ return texts[91]; };
wxString &Localization::getAboutString1						()	{ return texts[92]; };
wxString &Localization::getAboutString2						()	{ return texts[93]; };

//////////////////////////////////////////////////////////////
wxString &Localization::getUnCompressed						()	{ return texts[94]; };
wxString &Localization::getCompressedLevel0					()	{ return texts[95]; };
wxString &Localization::getCompressedLevel1					()	{ return texts[96]; };
wxString &Localization::getCompressedLevel2					()	{ return texts[97]; };