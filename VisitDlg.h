#pragma once   //_____________________________________________ VisitDlg.h  
#include "resource.h"

class VisitDlg: public Win::Dialog
{
public:
	VisitDlg()
	{
		visita_id = -1;
	}
	~VisitDlg()
	{
	}
	int visita_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::DropDownList ddUser;
	Win::Label lb2;
	Win::DropDownList ddVehicle;
	Win::Label lb3;
	Win::DateTimeBox dtboxEntry_Date;
	Win::Label lb4;
	Win::DateTimeBox dtboxDeparture_Date;
	Win::Label lb5;
	Win::DropDownList ddDepartment;
	Win::Button btOk;
	Win::Button btCancel;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(11.02783);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(4.19100);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"User", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.14817, 0.25400, 3.02683, 0.55033, hWnd, 1000);
		ddUser.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.28083, 0.25400, 5.01650, 0.55033, hWnd, 1001);
		lb2.CreateX(NULL, L"Vehicle", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.10583, 1.12183, 3.04800, 0.55033, hWnd, 1002);
		ddVehicle.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.25967, 1.07950, 5.01650, 0.55033, hWnd, 1003);
		lb3.CreateX(NULL, L"Entry_Date", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.04233, 1.92617, 3.17500, 0.55033, hWnd, 1004);
		dtboxEntry_Date.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 3.25967, 1.84150, 5.03767, 0.55033, hWnd, 1005);
		lb4.CreateX(NULL, L"Departure_Date", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.04233, 2.66700, 3.15383, 0.55033, hWnd, 1006);
		dtboxDeparture_Date.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 3.25967, 2.64583, 5.03767, 0.55033, hWnd, 1007);
		lb5.CreateX(NULL, L"Street", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.04233, 3.49250, 3.15383, 0.55033, hWnd, 1008);
		ddDepartment.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.21733, 3.38667, 5.05883, 0.55033, hWnd, 1009);
		btOk.CreateX(NULL, L"Ok", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 8.65717, 0.25400, 2.22250, 0.63500, hWnd, 1010);
		btCancel.CreateX(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 8.65717, 1.01600, 2.15900, 0.63500, hWnd, 1011);
		this->SetDefaultButton(btOk);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lb1.Font = fontArial009A;
		ddUser.Font = fontArial009A;
		lb2.Font = fontArial009A;
		ddVehicle.Font = fontArial009A;
		lb3.Font = fontArial009A;
		dtboxEntry_Date.Font = fontArial009A;
		lb4.Font = fontArial009A;
		dtboxDeparture_Date.Font = fontArial009A;
		lb5.Font = fontArial009A;
		ddDepartment.Font = fontArial009A;
		btOk.Font = fontArial009A;
		btCancel.Font = fontArial009A;
	}
	//_________________________________________________
	void btOk_Click(Win::Event& e);
	void btCancel_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btOk.IsEvent(e, BN_CLICKED)) {btOk_Click(e); return true;}
		if (btCancel.IsEvent(e, BN_CLICKED)) {btCancel_Click(e); return true;}
		return false;
	}
};
