#pragma once   //_____________________________________________ UserDlg.h  
#include "resource.h"

class UserDlg: public Win::Dialog
{
public:
	UserDlg()
	{
		userx_id = -1;
	}
	~UserDlg()
	{
	}
	int userx_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbFirst_name;
	Win::Textbox tbxFirst_name;
	Win::Label lbLast_name;
	Win::Textbox tbxLast_name;
	Win::Label lbPhone;
	Win::Textbox tbxPhone;
	Win::Label lbEmail;
	Win::Textbox tbxEmail;
	Win::Button btOK;
	Win::Button btCancel;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(8.82650);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(3.23850);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbFirst_name.CreateX(NULL, L"First name", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 0.25400, 2.11667, 0.55033, hWnd, 1000);
		tbxFirst_name.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 0.21167, 4.23333, 0.55033, hWnd, 1001);
		lbLast_name.CreateX(NULL, L"Last name", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 1.01600, 2.11667, 0.55033, hWnd, 1002);
		tbxLast_name.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 0.97367, 4.23333, 0.55033, hWnd, 1003);
		lbPhone.CreateX(NULL, L"Phone", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 1.77800, 2.11667, 0.55033, hWnd, 1004);
		tbxPhone.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 1.73567, 4.23333, 0.55033, hWnd, 1005);
		lbEmail.CreateX(NULL, L"Email", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 2.54000, 2.11667, 0.55033, hWnd, 1006);
		tbxEmail.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 2.49767, 4.23333, 0.55033, hWnd, 1007);
		btOK.CreateX(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.98500, 0.21167, 1.69333, 0.63500, hWnd, 1008);
		btCancel.CreateX(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.98500, 1.10067, 1.69333, 0.63500, hWnd, 1009);
		this->SetDefaultButton(btOK);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbFirst_name.Font = fontArial009A;
		tbxFirst_name.Font = fontArial009A;
		lbLast_name.Font = fontArial009A;
		tbxLast_name.Font = fontArial009A;
		lbPhone.Font = fontArial009A;
		tbxPhone.Font = fontArial009A;
		lbEmail.Font = fontArial009A;
		tbxEmail.Font = fontArial009A;
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
