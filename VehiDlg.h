#pragma once   //_____________________________________________ VehiDlg.h  
#include "resource.h"

class VehiDlg: public Win::Dialog
{
public:
	VehiDlg()
	{
		vehicle_id = -1;
	}
	~VehiDlg()
	{
	}
	int vehicle_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbMarca;
	Win::Textbox tbxMarca;
	Win::Label lbColor;
	Win::Textbox tbxColor;
	Win::Label lbPlaca;
	Win::Textbox tbxPlaca;
	Win::Button btOK;
	Win::Button btCancel;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(8.82650);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(2.47650);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbMarca.CreateX(NULL, L"Marca", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 0.25400, 2.11667, 0.55033, hWnd, 1000);
		tbxMarca.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 0.21167, 4.23333, 0.55033, hWnd, 1001);
		lbColor.CreateX(NULL, L"Color", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 1.01600, 2.11667, 0.55033, hWnd, 1002);
		tbxColor.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 0.97367, 4.23333, 0.55033, hWnd, 1003);
		lbPlaca.CreateX(NULL, L"Placa", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 1.77800, 2.11667, 0.55033, hWnd, 1004);
		tbxPlaca.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 1.73567, 4.23333, 0.55033, hWnd, 1005);
		btOK.CreateX(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.98500, 0.21167, 1.69333, 0.63500, hWnd, 1006);
		btCancel.CreateX(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.98500, 1.10067, 1.69333, 0.63500, hWnd, 1007);
		this->SetDefaultButton(btOK);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbMarca.Font = fontArial009A;
		tbxMarca.Font = fontArial009A;
		lbColor.Font = fontArial009A;
		tbxColor.Font = fontArial009A;
		lbPlaca.Font = fontArial009A;
		tbxPlaca.Font = fontArial009A;
		btOK.Font = fontArial009A;
		btCancel.Font = fontArial009A;
	}
	//_________________________________________________
	void btOK_Click(Win::Event& e);
	void btCancel_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btOK.IsEvent(e, BN_CLICKED)) {btOK_Click(e); return true;}
		if (btCancel.IsEvent(e, BN_CLICKED)) {btCancel_Click(e); return true;}
		return false;
	}
};
