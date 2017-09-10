#include "ResourceImporterView.h"
#include "ResourceImportDragDrop.h"
#include "ProjectView.h"
#include "ResourceImport.h"
#include "BitmapCreater.h"
#include "png_audioclip.h"
#include "png_audiostream.h"
#include "png_mat.h"
#include "png_prefab.h"
#include "png_scene.h"
#include "png_skelanimmodel.h"
#include "png_skelanimmodel2.h"
#include "png_texture.h"
#include "png_texturecube.h"
#include "png_cmprtexture.h"
#include "png_bvhtrimesh.h"
#include "png_cpp.h"

enum
{
	audioclip = 0,
	audiostream,
	mat,
	prefab,
	scene,
	skelanimmodel,
	skelanimmodel2,
	texture,
	texturecube,
	cmprtexture,
	bvhtrimesh,
	cpp,
};

const char *getDirectory(const char *fullPath)
{
	static char buffer[4096];
	strncpy(&buffer[0], fullPath, 4096);

	char *filename = strrchr(&buffer[0], '/');
	if(!filename)
	{
		return 0;
	}
	else
	{
		filename[0] = 0;
		return &buffer[0];
	}
}

const char *getFileName(const char *fullPath)
{
	static char buffer[4096];
	strncpy(&buffer[0], fullPath, 4096);

	char *ext      = strrchr(&buffer[0], '.');
	if(ext)
		ext[0] = 0;

	char *filename = strrchr(&buffer[0], '/');
	if(!filename)
	{
		return &buffer[0];
	}
	else
	{
		return filename+1;
	}
}

const char *getExtension(const char *fullPath)
{
	static char buffer[4096];
	strncpy(&buffer[0], fullPath, 4096);

	const char *ext      = strrchr(&buffer[0], '.');
	if(ext)
		return ext+1;
	else
		return 0;
}

ResourceImporterView::ResourceImporterView(ProjectView *projectView_)
: wxTreeCtrl(projectView_, wxID_ANY,
		     wxDefaultPosition, wxDefaultSize, 
			 wxTR_DEFAULT_STYLE | wxTR_MULTIPLE | wxTR_EDIT_LABELS | wxTR_HIDE_ROOT | wxNO_BORDER)
{
	wxImageList* imglist = new wxImageList(32, 32, true, 2);
	imglist->Add(wxArtProvider::GetBitmap(wxART_FOLDER, wxART_OTHER, wxSize(32, 32)					)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_audioclip, sizeof(png_audioclip)			)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_audiostream, sizeof(png_audiostream)		)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_mat, sizeof(png_mat)						)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_prefab, sizeof(png_prefab)					)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_scene, sizeof(png_scene)					)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_skelanimmodel, sizeof(png_skelanimmodel)	)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_skelanimmodel2, sizeof(png_skelanimmodel2)	)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_texture, sizeof(png_texture)				)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_texturecube, sizeof(png_texturecube)		)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_cmprtexture, sizeof(png_cmprtexture)		)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_bvhtrimesh, sizeof(png_bvhtrimesh)			)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_cpp, sizeof(png_cpp)						)	);
	imglist->Add(BitmapCreater::getBitmapFromMemory(png_bvhtrimesh, sizeof(png_bvhtrimesh)			)	);

	imageIDs[""]						= 0;
	imageIDs["audioclip"]				= 1;
	imageIDs["audiostream"]				= 2;
	imageIDs["mat"]						= 3;
	imageIDs["magnumprefab"]			= 4;
	imageIDs["magnumscene"]				= 5;
	imageIDs["skelanimmodel"]			= 6;
	imageIDs["skelanimmodel2"]			= 7;
	imageIDs["texture"]					= 8;
	imageIDs["texturecube"]				= 9;
	imageIDs["cmprtexture"]				= 10;
	imageIDs["trianglescene"]			= 11;
	imageIDs["cpp"]						= 12;
	imageIDs["trianglecollider"]		= 13;

    this->SetForegroundColour(wxColour(  0,   0,   0, 255));
    this->SetBackgroundColour(wxColour(128, 128, 128, 255));
	this->Centre();
	this->AssignImageList(imglist);
	
	wxTreeItemId root = this->AddRoot(wxT(""), 0);

	enableUIEvent();
}

ResourceImporterView::~ResourceImporterView()
{
}

void ResourceImporterView::diableUI(unsigned int flags)
{
}

void ResourceImporterView::enableUI(unsigned int flags)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////
// View request update Model
void ResourceImporterView::onBeginDrag(wxTreeEvent &event)
{
	int flag = 0;
	wxTreeItemId hitItem = this->HitTest(event.GetPoint(), flag);

	if(flag & (wxTREE_HITTEST_ONITEMBUTTON | wxTREE_HITTEST_ONITEMICON | wxTREE_HITTEST_ONITEMINDENT | wxTREE_HITTEST_ONITEMLABEL) )
	{
		wxString text = this->GetItemText(hitItem);

		ResourceImport *resourceImport = (ResourceImport *)pointerTreeItemMap.find(hitItem);
		if(!resourceImport)
			return;

		ResourceImportDataObject resourceImportDataObject(resourceImport->name(), resourceImport->extension());
		wxDropSource dragSource(this);
		dragSource.SetData(resourceImportDataObject);

		wxDragResult result = dragSource.DoDragDrop(wxDrag_CopyOnly);
		switch (result)
		{
			case wxDragError:
				// error prevented the d&d operation from completing
			break;
			case wxDragNone:
				// drag target didn't accept the data
			break;
			case wxDragCopy: 
				// copy the data
			break;
			case wxDragMove: 
				// move the data
			break;
			case wxDragLink:
				// operation is a drag-link
			break;
			case wxDragCancel:
				// the operation was cancelled by user (not an error)
			break;
		};
	}
	else if(flag & wxTREE_HITTEST_NOWHERE )
	{
		event.Veto();
	}
}

wxTreeItemId ResourceImporterView::collectDirectory(DirectoryTreeItemMap &directoryTreeItemMap, const String &directory)
{
	DirectoryTreeItemMapItr itr	= directoryTreeItemMap.find(directory);
	if(itr!=directoryTreeItemMap.end()) // if directory already exist, return it directly
	{
		return itr->second;
	}
	else // else create it
	{
		String ext					= getExtension(directory.text());
		String filename				= getFileName(directory.text());
		String parentDirectory		= getDirectory(directory.text());
		wxTreeItemId parentItem		= collectDirectory(directoryTreeItemMap, parentDirectory);

		String displayName			= filename;
		if(ext!="")
		{
			displayName += String(".") + ext;
		}

		String extlower				= ext;
		extlower.toLower();

		map<String, int>::iterator itr = imageIDs.find(extlower);
		if(itr==imageIDs.end())
		{
			int a = 1;
			assert(0);
		}

		wxTreeItemId item = this->AppendItem(parentItem, displayName.text(), itr->second, itr->second);
		directoryTreeItemMap.insert(DirectoryTreeItemPair(directory, item));

		return item;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Model request update View
void ResourceImporterView::notify(int flags, ProjectModelBase &projectModel, const Vector<unsigned char> &buffer)
{
	if(flags & ProjectModelBase::RESOURCE_IMPORTERS)
	{
		DirectoryTreeItemMap directoryTreeItemMap;
		DeleteAllItems();				// delete UI
		pointerTreeItemMap.clear();		// delete map;

		wxTreeItemId rootItem = this->AddRoot(wxT("Root Node"), 0);
		directoryTreeItemMap.insert(DirectoryTreeItemPair("", rootItem));

		for(int i=0; i<projectModel.getNumResourceCreators(); i++)
		{
			ResourceImport::ICreator *creator = projectModel.getResourceCreators(i);
			for(int j=0; j<creator->getNumResourceImporters(); j++)
			{
				ResourceImport *resourceImport = creator->getResourceImporters(j);

				String filePath		= String("/") + String(resourceImport->name()) + String(".") + String(creator->getExpExtension());
				wxTreeItemId item	= collectDirectory(directoryTreeItemMap, filePath);
				pointerTreeItemMap.add(item, resourceImport);
			}
		}

		this->ExpandAllChildren(rootItem);
	}
	if(flags & ProjectModelBase::STATE_CHANGED)
	{
	}

	/*
	if(flags & ProjectModelBase::RESOURCE_IMPORTERS)
	{
		DeleteAllItems();
		pointerTreeItemMap.clear();
		wxTreeItemId root = this->AddRoot(wxT("Root Node"), 0);

		for(int i=0; i<projectModel.getNumResourceCreators(); i++)
		{
			ResourceImport::ICreator *creator = projectModel.getResourceCreators(i);

			for(int j=0; j<creator->getNumResourceImporters(); j++)
			{
				ResourceImport *resourceImport = creator->getResourceImporters(j);

				wxTreeItemId item = this->AppendItem(GetRootItem(), resourceImport->name(), wxTreeItemIcon_Normal, wxTreeItemIcon_Selected);
				assert(item.IsOk());

				pointerTreeItemMap.add(item, resourceImport);
			}
		}
	}
	if(flags & ProjectModelBase::STATE_CHANGED)
	{
	}
	*/
}

void ResourceImporterView::disableUIEvent()
{
	Disconnect(wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler(ResourceImporterView::onBeginDrag));
}

void ResourceImporterView::enableUIEvent()
{
	Connect(wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler(ResourceImporterView::onBeginDrag));
}