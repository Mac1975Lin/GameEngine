#include "MiscAToolBarView.h"
#include "ProjectView.h"

#include "updateassets_png.h"
#include "compressedMode_png.h"
#include "misca1_png.h"
#include "misca2_png.h"
#include "misca3_png.h"
#include "misca4_png.h"
#include "misca5_png.h"
#include "misca6_png.h"
#include "misca7_png.h"
#include "misca8_png.h"
#include "misca9_png.h"
#include "BitmapCreater.h"
#include "Localization.h"

MiscAToolBarView::MiscAToolBarView(ProjectView *projectView_)
: wxAuiToolBar(projectView_, wxID_ANY, 
			   wxDefaultPosition, wxDefaultSize, 
			   wxAUI_TB_DEFAULT_STYLE /*| wxAUI_TB_OVERFLOW/* | wxAUI_TB_VERTICAL*/)
, compressedLevelComboBox(0)
{
	this->SetForegroundColour(projectView_->GetForegroundColour());
    this->SetBackgroundColour(projectView_->GetBackgroundColour());

	wxBitmap updateassetsPngBitmap			= BitmapCreater::getBitmapFromMemory(updateassets_png, sizeof(updateassets_png));
	wxBitmap toggleCompressModePngBitmap	= BitmapCreater::getBitmapFromMemory(compressedMode_png, sizeof(compressedMode_png));
	// wxBitmap miscA1PngBitmap				= BitmapCreater::getBitmapFromMemory(misca1_png, sizeof(misca1_png));
	// wxBitmap miscA2PngBitmap				= BitmapCreater::getBitmapFromMemory(misca2_png, sizeof(misca2_png));
	// wxBitmap miscA3PngBitmap				= BitmapCreater::getBitmapFromMemory(misca3_png, sizeof(misca3_png));
	// wxBitmap miscA4PngBitmap				= BitmapCreater::getBitmapFromMemory(misca4_png, sizeof(misca4_png));
	// wxBitmap miscA5PngBitmap				= BitmapCreater::getBitmapFromMemory(misca5_png, sizeof(misca5_png));
	// wxBitmap miscA6PngBitmap				= BitmapCreater::getBitmapFromMemory(misca6_png, sizeof(misca6_png));
	// wxBitmap miscA7PngBitmap				= BitmapCreater::getBitmapFromMemory(misca7_png, sizeof(misca7_png));
	// wxBitmap miscA8PngBitmap				= BitmapCreater::getBitmapFromMemory(misca8_png, sizeof(misca8_png));
	// wxBitmap miscA9PngBitmap				= BitmapCreater::getBitmapFromMemory(misca9_png, sizeof(misca9_png));
	
	wxString choices[] =
	{
		Localization::getUnCompressed(),
		Localization::getCompressedLevel0(),
		Localization::getCompressedLevel1(),
		Localization::getCompressedLevel2(),
	};

	this->SetToolBitmapSize(wxDefaultSize);
	compressedLevelComboBox = new wxComboBox(this, wxID_ANY, choices[0], wxDefaultPosition, wxDefaultSize, sizeof(choices)/sizeof(choices[0]), choices, wxCB_READONLY);
	this->AddControl(compressedLevelComboBox, "Compression");
	this->AddSeparator();
	this->AddTool(MenuCommand::MENU_MISC_A_UPDATE_ASSETS		 , Localization::getMenuMiscAUpdateAssets()		, updateassetsPngBitmap			, Localization::getMenuMiscAUpdateAssets()		, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_TOGGLE_COMPRESS_MODE	 , Localization::getMenuMiscToggleCompressMode(), toggleCompressModePngBitmap	, Localization::getMenuMiscToggleCompressMode()	, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_1					 , Localization::getMenuMiscA1()				, miscA1PngBitmap				, Localization::getMenuMiscA1()					, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_2					 , Localization::getMenuMiscA2()				, miscA2PngBitmap				, Localization::getMenuMiscA2()					, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_3					 , Localization::getMenuMiscA3()				, miscA3PngBitmap				, Localization::getMenuMiscA3()					, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_4					 , Localization::getMenuMiscA4()				, miscA4PngBitmap				, Localization::getMenuMiscA4()					, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_5					 , Localization::getMenuMiscA5()				, miscA5PngBitmap				, Localization::getMenuMiscA5()					, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_6					 , Localization::getMenuMiscA6()				, miscA6PngBitmap				, Localization::getMenuMiscA6()					, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_7					 , Localization::getMenuMiscA7()				, miscA7PngBitmap				, Localization::getMenuMiscA7()					, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_8					 , Localization::getMenuMiscA8()				, miscA8PngBitmap				, Localization::getMenuMiscA8()					, wxITEM_RADIO);
	// this->AddTool(MenuCommand::MENU_MISC_A_9					 , Localization::getMenuMiscA9()				, miscA9PngBitmap				, Localization::getMenuMiscA9()					, wxITEM_RADIO);
	
	this->Realize();

	enableUIEvent();
}

MiscAToolBarView::~MiscAToolBarView()
{
}

void MiscAToolBarView::diableUI(unsigned int flags)
{
}

void MiscAToolBarView::enableUI(unsigned int flags)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////
// View request update Model
void MiscAToolBarView::onComboBoxDropDown(wxCommandEvent &evt)
{
	int value = ProjectModelBase::UNCOMPRESSED;
	value += evt.GetSelection();

	Vector<unsigned char> buffer;
	MemOutputStream os(buffer);
	os << String("ChangeCompressLevel") << value;
	GameDescriptor::instance().onGUIEvent(&buffer[0], buffer.length());
	/*
	int value = ProjectModelBase::LOCAL;
	value += evt.GetSelection();
	getModel().setCoordinateSystem((ProjectModelBase::CoordSys)value);
	*/
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Model request update View
void MiscAToolBarView::notify(int flags, ProjectModelBase &projectModel, const Vector<unsigned char> &buffer)
{
	if(flags & ProjectModelBase::COMPRESSED_LEVEL_CHANGED)
	{
		ProjectModelBase::CompressedLevel compressedLevel = projectModel.getCompressedLevel();

		compressedLevelComboBox->SetSelection(compressedLevel);
	}
	if(flags & ProjectModelBase::STATE_CHANGED)
	{
		if(projectModel.getCurrentState()=="DebugRun")
		{
			EnableTool(MenuCommand::MENU_MISC_A_UPDATE_ASSETS		, false);
			// EnableTool(MenuCommand::MENU_MISC_A_TOGGLE_COMPRESS_MODE, false);
			// EnableTool(MenuCommand::MENU_MISC_A_1					, false);
			// EnableTool(MenuCommand::MENU_MISC_A_2					, false);
			// EnableTool(MenuCommand::MENU_MISC_A_3					, false);
			// EnableTool(MenuCommand::MENU_MISC_A_4					, false);
			// EnableTool(MenuCommand::MENU_MISC_A_5					, false);
			// EnableTool(MenuCommand::MENU_MISC_A_6					, false);
			// EnableTool(MenuCommand::MENU_MISC_A_7					, false);
			// EnableTool(MenuCommand::MENU_MISC_A_8					, false);
			// EnableTool(MenuCommand::MENU_MISC_A_9					, false);
			compressedLevelComboBox->Disable();

			Refresh();
		}
		else
		{
			EnableTool(MenuCommand::MENU_MISC_A_UPDATE_ASSETS			, true);
			// EnableTool(MenuCommand::MENU_MISC_A_TOGGLE_COMPRESS_MODE	, true);
			// EnableTool(MenuCommand::MENU_MISC_A_1						, true);
			// EnableTool(MenuCommand::MENU_MISC_A_2						, true);
			// EnableTool(MenuCommand::MENU_MISC_A_3						, true);
			// EnableTool(MenuCommand::MENU_MISC_A_4						, true);
			// EnableTool(MenuCommand::MENU_MISC_A_5						, true);
			// EnableTool(MenuCommand::MENU_MISC_A_6						, true);
			// EnableTool(MenuCommand::MENU_MISC_A_7						, true);
			// EnableTool(MenuCommand::MENU_MISC_A_8						, true);
			// EnableTool(MenuCommand::MENU_MISC_A_9						, true);
			compressedLevelComboBox->Enable();

			Refresh();
		}
	}
}

void MiscAToolBarView::disableUIEvent()
{
	this->Disconnect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(MiscAToolBarView::onComboBoxDropDown), 0, this);
}

void MiscAToolBarView::enableUIEvent()
{
	this->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(MiscAToolBarView::onComboBoxDropDown), 0, this);
}