/********************************************************************************//**
 * @file	main.cpp
 * @author	Alexandre Arsenault <alexandre.arsenault@polymtl.ca>
 * @brief	Main Application
 * @date	Creation 06/02/2013
 ***********************************************************************************/
#include "main_Media_Player.h"

IMPLEMENT_APP(Orchestra);

bool Orchestra::OnInit()
{
	frame = new MainFrame(axT("Orchestra"));
	
	frame->Show();
	SetTopWindow(frame);

	return true;
}

MainFrame::MainFrame(const axString& title): axFrame(NULL, axID_ANY, title, axPoint(30, 30), axSize(500, 500))
{
	SetBackgroundColour(axColor(80, 80, 80));
	mainPanel = new axPanel(this, axID_ANY, axPoint(0, 0), this->GetSize());
	mainPanel->SetBackgroundColour(axColor(80, 80, 80));
}
