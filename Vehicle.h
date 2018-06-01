#pragma once  //______________________________________ Vehicle.h  
#include "Resource.h"
class Vehicle: public Win::Window
{
public:
	Vehicle()
	{
	}
	~Vehicle()
	{
	}
	void FillListView();
	void FillListViewCol();
	void InsertItems();
	void EditItems();
	void DeleteItems();
	const wchar_t * GetClassName(){return L"Vehicle";}
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Toolbar toolbMain;
	Win::ListView lvItem;
protected:
	Win::Gdi::Font fontArial009A;
	void GetWindowInformation(CREATESTRUCT& createStruct)
	{
		createStruct.style = WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"Vehicle";
		toolbMain.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | CCS_NORESIZE | CCS_NOPARENTALIGN | CCS_ADJUSTABLE | CCS_NODIVIDER | TBSTYLE_FLAT | TBSTYLE_TOOLTIPS, 0.14817, 0.14817, 12.99633, 1.71450, hWnd, 1000);
		lvItem.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.16933, 2.01083, 17.97050, 7.47183, hWnd, 1001);
		lvItem.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lvItem.Font = fontArial009A;
		lvItem.SetDock(DOCK_BORDER, DOCK_BORDER, DOCK_BORDER, DOCK_BORDER);
	}
	//_________________________________________________
	void lvItem_ItemChanged(Win::Event& e);
	void lvItem_KeyDown(Win::Event& e);
	void lvItem_DblClk(Win::Event& e);
	void Window_Open(Win::Event& e);
	void Cmd_Add(Win::Event& e);
	void Cmd_Copy(Win::Event& e);
	void Cmd_Delete(Win::Event& e);
	void Cmd_Edit(Win::Event& e);
	void Cmd_Msexcel(Win::Event& e);
	void Cmd_Print(Win::Event& e);
	void Cmd_House1(Win::Event& e);
	void Cmd_Vehiclee(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lvItem.IsEvent(e, LVN_ITEMCHANGED)) {lvItem_ItemChanged(e); return true;}
		if (lvItem.IsEvent(e, LVN_KEYDOWN)) {lvItem_KeyDown(e); return true;}
		if (lvItem.IsEvent(e, NM_DBLCLK)) {lvItem_DblClk(e); return true;}
		if (this->IsEvent(e, IDM_ADD)) {Cmd_Add(e); return true;}
		if (this->IsEvent(e, IDM_COPY)) {Cmd_Copy(e); return true;}
		if (this->IsEvent(e, IDM_DELETE)) {Cmd_Delete(e); return true;}
		if (this->IsEvent(e, IDM_EDIT)) {Cmd_Edit(e); return true;}
		if (this->IsEvent(e, IDM_MSEXCEL)) {Cmd_Msexcel(e); return true;}
		if (this->IsEvent(e, IDM_PRINT)) {Cmd_Print(e); return true;}
		if (this->IsEvent(e, IDM_HOUSE1)) {Cmd_House1(e); return true;}
		if (this->IsEvent(e, IDM_VEHICLEE)) {Cmd_Vehiclee(e); return true;}
		return false;
	}
};
