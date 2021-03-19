#pragma once
#include "wx/wx.h"
#include "controller.h"
#include <iostream>

class aMain : public wxFrame
{
public:
	aMain();
	~aMain();
public:
	int widht = 3;
	int height = 3;
	
	wxButton** btn;

	void ButtonClicked(wxCommandEvent &event);
	void chageAll(bool state);

	wxDECLARE_EVENT_TABLE();

};