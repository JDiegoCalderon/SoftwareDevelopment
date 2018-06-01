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
	Win::Label lbDescriptionx;
	Win::Textbox tbxDescriptionx;
	Win::Button ckTypex;
	Win::Label lbPlate;
	Win::Textbox tbxPlate;
	Win::Label lbCedula;
	Win::Textbox tbxCedula;
	Win::Label lbEntry_date;
	Win::DateTimeBox dtboxEntry_date;
	Win::Label lbDeparture_date;
	Win::DateTimeBox dtboxDeparture_date;
	Win::Label lbDepartment;
	Win::DropDownList ddDepartment;
	Win::Label lbStreet_block;
	Win::Textbox tbxStreet_block;
	Win::Label lbHouse_number;
	Win::Textbox tbxHouse_number;
	Win::Button btOK;
	Win::Button btCancel;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(8.82650);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(10.13883);
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
		lbDescriptionx.CreateX(NULL, L"Description of the car", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 3.23850, 2.11667, 0.71967, hWnd, 1008);
		tbxDescriptionx.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 3.25967, 4.23333, 0.55033, hWnd, 1009);
		ckTypex.CreateX(NULL, L"Private", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 2.54000, 4.02167, 4.23333, 0.57150, hWnd, 1010);
		lbPlate.CreateX(NULL, L"Plate", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 4.86833, 2.11667, 0.55033, hWnd, 1011);
		tbxPlate.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 4.82600, 4.23333, 0.55033, hWnd, 1012);
		lbCedula.CreateX(NULL, L"Cedula", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 5.63033, 2.11667, 0.55033, hWnd, 1013);
		tbxCedula.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 5.58800, 4.23333, 0.55033, hWnd, 1014);
		lbEntry_date.CreateX(NULL, L"Entry date", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 6.39233, 2.11667, 0.55033, hWnd, 1015);
		dtboxEntry_date.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 2.54000, 6.35000, 4.23333, 0.55033, hWnd, 1016);
		lbDeparture_date.CreateX(NULL, L"Departure date", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 7.15433, 2.11667, 0.55033, hWnd, 1017);
		dtboxDeparture_date.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 2.54000, 7.11200, 4.23333, 0.55033, hWnd, 1018);
		lbDepartment.CreateX(NULL, L"Street", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 7.91633, 2.11667, 0.55033, hWnd, 1019);
		ddDepartment.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 2.54000, 7.87400, 4.23333, 0.55033, hWnd, 1020);
		lbStreet_block.CreateX(NULL, L"Street block", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 8.67833, 2.11667, 0.55033, hWnd, 1021);
		tbxStreet_block.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 8.63600, 4.23333, 0.55033, hWnd, 1022);
		lbHouse_number.CreateX(NULL, L"House number", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 9.44033, 2.11667, 0.55033, hWnd, 1023);
		tbxHouse_number.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.54000, 9.39800, 4.23333, 0.55033, hWnd, 1024);
		btOK.CreateX(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.98500, 0.21167, 1.69333, 0.63500, hWnd, 1025);
		btCancel.CreateX(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.98500, 1.10067, 1.69333, 0.63500, hWnd, 1026);
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
		lbDescriptionx.Font = fontArial009A;
		tbxDescriptionx.Font = fontArial009A;
		ckTypex.Font = fontArial009A;
		lbPlate.Font = fontArial009A;
		tbxPlate.Font = fontArial009A;
		lbCedula.Font = fontArial009A;
		tbxCedula.Font = fontArial009A;
		lbEntry_date.Font = fontArial009A;
		dtboxEntry_date.Font = fontArial009A;
		lbDeparture_date.Font = fontArial009A;
		dtboxDeparture_date.Font = fontArial009A;
		lbDepartment.Font = fontArial009A;
		ddDepartment.Font = fontArial009A;
		lbStreet_block.Font = fontArial009A;
		tbxStreet_block.Font = fontArial009A;
		lbHouse_number.Font = fontArial009A;
		tbxHouse_number.Font = fontArial009A;
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
