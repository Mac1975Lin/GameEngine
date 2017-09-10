///////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2009, Lin Koon Wing Macgyver, macgyvercct@yahoo.com.hk			 //
//																				 //
// Author : Mac Lin									                             //
// Module : DreamEngine v1.0.0												 //
// Date   : 20/Dec/2009											                 //
//																				 //
///////////////////////////////////////////////////////////////////////////////////
#include "ReflectedClassPropertyPanel.h"
using namespace IDreamSky;

////////////////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC_CLASS( ReflectedClassPropertyPanelEvent, wxNotifyEvent )
DEFINE_EVENT_TYPE( wxEVT_COMMAND_REFLECTED_CLASS_PROPERTY_PANEL_COLLAPSED_CHANGED	)
DEFINE_EVENT_TYPE( wxEVT_COMMAND_REFLECTED_CLASS_PROPERTY_PANEL_SIZE_CHANGED		)
DEFINE_EVENT_TYPE( wxEVT_COMMAND_REFLECTED_CLASS_PROPERTY_PANEL_NAME_CHANGED		)
DEFINE_EVENT_TYPE( wxEVT_COMMAND_REFLECTED_CLASS_PROPERTY_PANEL_TRANSFORM_CHANGED	)
DEFINE_EVENT_TYPE( wxEVT_COMMAND_REFLECTED_CLASS_PROPERTY_PANEL_VALUE_CHANGED		)