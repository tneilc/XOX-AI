#pragma once
#include "wx/wx.h"
#include "aMain.h"


class App : public wxApp
{
public:
	App();
	~App();

private:
	aMain* frame1 = nullptr;

public:
	virtual bool OnInit();
	
};

