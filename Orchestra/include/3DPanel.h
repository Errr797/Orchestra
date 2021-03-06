/// @todo Needs Documentation Header.
#ifndef DEF_3DPANEL_H
#define DEF_3DPANEL_H

#include "axLib.h"
#include "irrlicht.h"
#include <list>

typedef irr::SIrrlichtCreationParameters	irr_CreateParam;
typedef irr::video::E_DRIVER_TYPE			irr_DriverType;
typedef irr::IrrlichtDevice					irr_Device;
typedef irr::scene::ISceneManager			irr_SceneManager;
typedef irr::video::IVideoDriver			irr_VideoDriver;
typedef irr::scene::ICameraSceneNode		irr_Camera;
typedef irr::scene::ISceneNode				irr_Node;
typedef irr::video::SColor					irr_Color;
typedef irr::core::dimension2d<irr::s32>	irr_Dimension2D;
typedef irr::core::vector3df				irr_Vector3D;
typedef irr::video::E_MATERIAL_FLAG			irr_MaterialFlag;
typedef irr::s32							irr_S32;
typedef irr::scene::IAnimatedMesh			irr_Mesh;
typedef irr::scene::IAnimatedMeshSceneNode	irr_SceneMesh;
typedef irr::scene::IBoneSceneNode			irr_Bone;
typedef irr::core::quaternion				irr_quatornion;
//typedef irr::scene::IAnimatedMeshSceneNode	irr_Animated_Node;

/// @todo Needs Documentation.
class Device3D : public wxWindow
{
public:
	Device3D(wxWindow* win, wxPoint point, wxSize size, irr_DriverType type = irr::video::EDT_OPENGL, bool bResizeable = true);
	~Device3D();

	//inline irr_Device		*GetHandle()		{ return irrDevice; }

	/// @todo Needs Documentation.
	inline irr_SceneManager *GetSceneManager()	{ return irrDevice ? irrDevice->getSceneManager() : NULL; }
	/// @todo Needs Documentation.
	inline irr_VideoDriver	*GetVideoDriver()	{ return irrDevice ? irrDevice->getVideoDriver()  : NULL; }

	/// @todo Needs Documentation.
	irr_Camera* AddCamera(irr_Node* parent = 0, 
						  irr_Vector3D& position = irr_Vector3D(0.0f, 0.0f, 0.0f), 
						  irr_Vector3D& lookat = irr_Vector3D(0.0f, 0.0f, 1.0f), 
						  irr_S32 id = 1);

	void mSize(const wxSize& newSize);

	//static const wxSize MINSIZE;
protected:
	irr_Device* irrDevice;
	irr_Bone* hand_, *hips_, *forearm_L, *upper_arm_L;

	irr_Camera* camera_;

	bool Compute(irr_Bone* boneNode, irr_Bone* rootBoneNode, irr_Vector3D target);

	double theta;
	wxPoint clickPt;

	void OnPaint(wxPaintEvent &event);
	void OnMouseLeftDown(wxMouseEvent& event);
	void OnMouseMotion(wxMouseEvent& event);
	void OnMouseLeftUp(wxMouseEvent& event);

	DECLARE_EVENT_TABLE()
};

#endif