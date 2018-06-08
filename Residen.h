#pragma once  //______________________________________ Residen.h  
#include "Resource.h"
class Residen: public Win::Window
{
public:
	Residen()
	{
	}
	~Residen()
	{
	}
	void FillListView();
	void FillListViewCol();
	void InsertItems();
	void EditItems();
	void DeleteItems();
	void SearchUser();
	void SearchVehi();
	void SearchRegi();
	const wchar_t * GetClassName(){return L"Residen";}
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Toolbar toolbMain;
	Win::ListView lvItem;
	Win::Image img1;
	Win::DropDownList ddCategory;
	Win::DropDownList ddCategory1;
protected:
	Win::Gdi::Font fontArial009A;
	void GetWindowInformation(CREATESTRUCT& createStruct)
	{
		createStruct.style = WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"Residen";
		lb1.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.10583, 0.04233, 25.63283, 2.37067, hWnd, 1000);
		toolbMain.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | CCS_NORESIZE | CCS_NOPARENTALIGN | CCS_ADJUSTABLE | CCS_NODIVIDER | TBSTYLE_FLAT | TBSTYLE_TOOLTIPS, 0.12700, 0.55033, 9.18633, 1.12183, hWnd, 1001);
		lvItem.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.12700, 2.45533, 25.61167, 7.21783, hWnd, 1002);
		img1.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_VISIBLE, 15.19767, 0.12700, 3.57717, 2.20133, hWnd, 1003);
		ddCategory.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 20.34117, 0.12700, 5.41867, 0.61383, hWnd, 1004);
		ddCategory1.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 20.32000, 0.78317, 5.46100, 0.55033, hWnd, 1005);
		lvItem.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lb1.Font = fontArial009A;
		lvItem.Font = fontArial009A;
		ddCategory.Font = fontArial009A;
		ddCategory1.Font = fontArial009A;
		lb1.SetDock(DOCK_BORDER, DOCK_BORDER, DOCK_BORDER, DOCK_NONE);
		lvItem.SetDock(DOCK_BORDER, DOCK_BORDER, DOCK_BORDER, DOCK_BORDER);
		ddCategory.SetDock(DOCK_NONE, DOCK_BORDER, DOCK_BORDER, DOCK_NONE);
		ddCategory1.SetDock(DOCK_NONE, DOCK_BORDER, DOCK_BORDER, DOCK_NONE);
		lb1.BackColor = RGB(200, 255, 255);
	}
	//_________________________________________________
	void lb1_CtlColorStatic(Win::Event& e);
	void lvItem_ItemChanged(Win::Event& e);
	void lvItem_KeyDown(Win::Event& e);
	void lvItem_DblClk(Win::Event& e);
	void ddCategory_SelChange(Win::Event& e);
	void ddCategory1_SelChange(Win::Event& e);
	void Window_Open(Win::Event& e);
	void Cmd_Add(Win::Event& e);
	void Cmd_Cart(Win::Event& e);
	void Cmd_Client(Win::Event& e);
	void Cmd_Copy(Win::Event& e);
	void Cmd_Delete(Win::Event& e);
	void Cmd_Edit(Win::Event& e);
	void Cmd_Msexcel(Win::Event& e);
	void Cmd_Print(Win::Event& e);
	void Cmd_Save(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lb1.IsEvent(e, WM_CTLCOLORSTATIC)) {lb1_CtlColorStatic(e); return true;}
		if (lvItem.IsEvent(e, LVN_ITEMCHANGED)) {lvItem_ItemChanged(e); return true;}
		if (lvItem.IsEvent(e, LVN_KEYDOWN)) {lvItem_KeyDown(e); return true;}
		if (lvItem.IsEvent(e, NM_DBLCLK)) {lvItem_DblClk(e); return true;}
		if (ddCategory.IsEvent(e, CBN_SELCHANGE)) {ddCategory_SelChange(e); return true;}
		if (ddCategory1.IsEvent(e, CBN_SELCHANGE)) {ddCategory1_SelChange(e); return true;}
		if (this->IsEvent(e, IDM_ADD)) {Cmd_Add(e); return true;}
		if (this->IsEvent(e, IDM_CART)) {Cmd_Cart(e); return true;}
		if (this->IsEvent(e, IDM_CLIENT)) {Cmd_Client(e); return true;}
		if (this->IsEvent(e, IDM_COPY)) {Cmd_Copy(e); return true;}
		if (this->IsEvent(e, IDM_DELETE)) {Cmd_Delete(e); return true;}
		if (this->IsEvent(e, IDM_EDIT)) {Cmd_Edit(e); return true;}
		if (this->IsEvent(e, IDM_MSEXCEL)) {Cmd_Msexcel(e); return true;}
		if (this->IsEvent(e, IDM_PRINT)) {Cmd_Print(e); return true;}
		if (this->IsEvent(e, IDM_SAVE)) {Cmd_Save(e); return true;}
		return false;
	}
};
