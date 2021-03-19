#include "aMain.h"

wxBEGIN_EVENT_TABLE(aMain, wxFrame)
wxEND_EVENT_TABLE()

int toEnable[9] = { 0,1,2,3,4,5,6,7,8 };
controller controls;

aMain::aMain() : wxFrame(nullptr, wxID_ANY, "OH FAK", wxPoint(30, 30), wxSize(360, 360), (wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER))
{
	btn = new wxButton * [widht * height];
	wxGridSizer* grid = new wxGridSizer(widht, height, 0, 0);
	wxFont font(28, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int i = 0; i < 9; i++)
	{
			btn[i] = new wxButton(this, i);
			btn[i]->SetFont(font);
			grid->Add(btn[i], 1, wxEXPAND | wxALL);
			btn[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &aMain::ButtonClicked, this);
		
	}
	this->SetSizer(grid);
	grid->Layout();
	int ind = controls.AIMove();
	btn[ind]->SetLabel('X');
	toEnable[ind] = -1;
}


void aMain::chageAll(bool state) {
	if (state){
		for (int i = 0; i < 9; i++)
			if (toEnable[i] == i)
			{
				btn[i]->Enable(state);
			}
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			btn[i]->Enable(state);
		}
	}
}

void checkWin() {
	char winner = controls.daWinner();
	if (winner == 't') { wxMessageBox("Tie");}
	else if (winner == 'X' || winner == 'O'){
		wxMessageBox(winner,"Finished");
	}
}


void aMain::ButtonClicked(wxCommandEvent& event) {
	int id = event.GetId();
	btn[id]->SetLabel('O');
	controls.HumanMove(id);
	toEnable[id] = -1;
	checkWin();
	aMain::chageAll(false);
	int ind = controls.AIMove();
	btn[ind]->SetLabel('X');
	toEnable[ind] = -1;
	checkWin();
	aMain::chageAll(true);

	event.Skip();
}



aMain::~aMain()
{
	delete[]btn;
}