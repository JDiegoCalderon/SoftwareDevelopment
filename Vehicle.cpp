#include "stdafx.h"  //________________________________________ Vehicle.cpp
#include "Vehicle.h"
#include "UserDlg.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	Vehicle app;
	app.CreateMainWindow(L"Vehicle", cmdShow, IDI_Vehicle, NULL, (HBRUSH)(COLOR_WINDOW + 1), hInstance);
	return app.MessageLoop(IDC_Vehicle);
}

void Vehicle::Window_Open(Win::Event& e)
{
	//________________________________________________________ toolbMain
	TBBUTTON tbButton[10];//<< EDIT HERE THE NUMBER OF BUTTONS

	//int iconSizes[] ={16, 20, 24, 32, 40, 48};
	//const int pixelsIconSize = Sys::Metrics::GetBestIconSize(iconSizes, 6, Sys::Convert::CentimetersToScreenPixels(0.42333));
	//const int pixelsButtonSize = pixelsIconSize + Sys::Convert::CentimetersToScreenPixels(0.1);
	//toolbMain.imageList.Create(pixelsIconSize, pixelsIconSize, 6);//<< EDIT HERE THE NUMBER OF IMAGES

	toolbMain.imageList.Create(30,40, 8);//<< EDIT HERE THE NUMBER OF IMAGES
	toolbMain.imageList.AddIcon(this->hInstance, IDI_ADD);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_EDIT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_DELETE);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_VEHICLEE);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_HOUSE1);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_PRINT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_COPY);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_MSEXCEL);
	toolbMain.SendMessage(TB_BUTTONSTRUCTSIZE, (WPARAM)(int)sizeof(TBBUTTON), 0); 
	toolbMain.SetImageList(toolbMain.imageList);
	//_____________________________________
	tbButton[0].iBitmap=MAKELONG(0, 0); //<< IMAGE INDEX
	tbButton[0].idCommand=IDM_ADD;
	tbButton[0].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[0].fsStyle=BTNS_BUTTON;
	tbButton[0].dwData=0L; 
	tbButton[0].iString= (LONG_PTR)L"Add";
	//_____________________________________
	tbButton[1].iBitmap=MAKELONG(1, 0); //<< IMAGE INDEX
	tbButton[1].idCommand=IDM_EDIT;
	tbButton[1].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[1].fsStyle=BTNS_BUTTON;
	tbButton[1].dwData=0L; 
	tbButton[1].iString= (LONG_PTR)L"Edit";
	//_____________________________________
	tbButton[2].iBitmap=MAKELONG(2, 0); //<< IMAGE INDEX
	tbButton[2].idCommand=IDM_DELETE;
	tbButton[2].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[2].fsStyle=BTNS_BUTTON;
	tbButton[2].dwData=0L; 
	tbButton[2].iString= (LONG_PTR)L"Delete";
	//_______________________ A separator
	tbButton[3].iBitmap=-1;
	tbButton[3].idCommand=0;  
	tbButton[3].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[3].fsStyle=BTNS_SEP;  
	tbButton[3].dwData=0L;  
	tbButton[3].iString=0;  
	//_____________________________________
	tbButton[4].iBitmap = MAKELONG(3, 0); //<< IMAGE INDEX
	tbButton[4].idCommand = IDM_VEHICLEE;
	tbButton[4].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[4].fsStyle = BTNS_BUTTON;
	tbButton[4].dwData = 0L;
	tbButton[4].iString = (LONG_PTR)L"Vehicle";
	//_____________________________________
	tbButton[5].iBitmap = MAKELONG(4, 0); //<< IMAGE INDEX
	tbButton[5].idCommand = IDM_HOUSE1;
	tbButton[5].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[5].fsStyle = BTNS_BUTTON;
	tbButton[5].dwData = 0L;
	tbButton[5].iString = (LONG_PTR)L"Department";
	//_______________________ A separator
	tbButton[6].iBitmap = -1;
	tbButton[6].idCommand = 0;
	tbButton[6].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[6].fsStyle = BTNS_SEP;
	tbButton[6].dwData = 0L;
	tbButton[6].iString = 0;
	//_____________________________________
	tbButton[7].iBitmap=MAKELONG(5, 0); //<< IMAGE INDEX
	tbButton[7].idCommand=IDM_PRINT;
	tbButton[7].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[7].fsStyle=BTNS_BUTTON;
	tbButton[7].dwData=0L; 
	tbButton[7].iString= (LONG_PTR)L"Print";
	//____________________________________
	tbButton[8].iBitmap = MAKELONG(6, 0); //<< IMAGE INDEX
	tbButton[8].idCommand = IDM_COPY;
	tbButton[8].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[8].fsStyle = BTNS_BUTTON;
	tbButton[8].dwData = 0L;
	tbButton[8].iString = (LONG_PTR)L"Copy";
	//_____________________________________
	tbButton[9].iBitmap=MAKELONG(7, 0); //<< IMAGE INDEX
	tbButton[9].idCommand=IDM_MSEXCEL;
	tbButton[9].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[9].fsStyle=BTNS_BUTTON;
	tbButton[9].dwData=0L; 
	tbButton[9].iString= (LONG_PTR)L"Export to Microsoft Excel";

	toolbMain.SetBitmapSize(35,40);
	toolbMain.SetButtonSize(30,30);
	//toolbMain.SetBitmapSize(pixelsIconSize, pixelsIconSize);
	//toolbMain.SetButtonSize(pixelsButtonSize, pixelsButtonSize);
	toolbMain.AddButtons(tbButton, 10);// << EDIT HERE THE NUMBER OF BUTTONS
	toolbMain.SendMessage(TB_AUTOSIZE, 0, 0);
	toolbMain.SetMaxTextRows(0);// EDIT HERE TO DISPLAY THE BUTTON TEXT
	toolbMain.Show(SW_SHOWNORMAL);
//	toolbMain.ResizeToFit();
	
	//_______________________________________________________Enable or disable buttoms
	toolbMain.EnableButton(IDM_ADD, false);
	toolbMain.EnableButton(IDM_EDIT, false);
	toolbMain.EnableButton(IDM_DELETE, false);
	toolbMain.EnableButton(IDM_PRINT, true);
	toolbMain.EnableButton(IDM_VEHICLEE, true);
	toolbMain.EnableButton(IDM_HOUSE1, true);
	toolbMain.EnableButton(IDM_COPY, true);
	toolbMain.EnableButton(IDM_MSEXCEL, true);
    //________________________________________________________ lvItem
	lvItem.Cols.Add(0, LVCFMT_CENTER,300, L"Select an option.");

	FillListViewCol();
}


void Vehicle::lvItem_ItemChanged(Win::Event& e)
{
	if (lvItem.GetSelectedIndex() >= 0)
	{
		this->toolbMain.EnableButton(IDM_EDIT, true);
		this->toolbMain.EnableButton(IDM_DELETE, true);
	}
	else
	{
		this->toolbMain.EnableButton(IDM_EDIT, false);
		this->toolbMain.EnableButton(IDM_DELETE, false);
	}
}

void Vehicle::lvItem_KeyDown(Win::Event& e)
{
	LPNMLVKEYDOWN p = (LPNMLVKEYDOWN) e.lParam;
	if (p->wVKey == VK_DELETE)
	{
		DeleteItems();
	}
}

void Vehicle::lvItem_DblClk(Win::Event& e)
{
	EditItems();
}

void Vehicle::Cmd_Add(Win::Event& e)
{
	InsertItems();
}

void Vehicle::Cmd_Copy(Win::Event& e)
{
	toolbMain.EnableButton(IDM_COPY, false);
	lvItem.CopyToClipboard();
	toolbMain.EnableButton(IDM_COPY, true);
}

void Vehicle::Cmd_Delete(Win::Event& e)
{
	DeleteItems();
}

void Vehicle::Cmd_Edit(Win::Event& e)
{
	EditItems();
}

void Vehicle::Cmd_Msexcel(Win::Event& e)
{
}

void Vehicle::Cmd_Print(Win::Event& e)
{
	lvItem.Print();
}

void Vehicle::Cmd_House1(Win::Event& e)
{
}

void Vehicle::Cmd_Vehiclee(Win::Event& e)
{
	toolbMain.EnableButton(IDM_ADD, true);
	toolbMain.EnableButton(IDM_HOUSE1, true);
	toolbMain.EnableButton(IDM_VEHICLEE, false);
	toolbMain.EnableButton(IDM_EDIT, false);
	toolbMain.EnableButton(IDM_DELETE, false);
	FillListView();
}

void Vehicle::InsertItems()
{
	toolbMain.EnableButton(IDM_ADD, false);
	if (toolbMain.IsButtonEnabled(IDM_VEHICLEE) == false)
	{
		UserDlg user_dlg;
		user_dlg.BeginDialog(hWnd);
	}
	else return;
	FillListView();
	toolbMain.EnableButton(IDM_ADD, true);
}

void Vehicle::EditItems()
{
	toolbMain.EnableButton(IDM_EDIT, false);
	const int selectedIndex = lvItem.GetSelectedIndex();
	if (selectedIndex<0) return;
	//____________________________________________________Ask the user
	if (this->MessageBox(L"Are you sure you want to modify the selected item?", L"Edit item",
		MB_YESNO | MB_ICONQUESTION) != IDYES) return;
	//___________________________________________________Edit
	const int item_id = lvItem.Items[selectedIndex].Data;
	if (toolbMain.IsButtonEnabled(IDM_VEHICLEE) == false)
	{
		UserDlg user_dlg;
		user_dlg.userx_id = item_id;
		user_dlg.BeginDialog(hWnd);
	}
	else return;
	FillListView();
	toolbMain.EnableButton(IDM_EDIT, true);
}

void Vehicle::DeleteItems()
{
	Win::HourGlassCursor hgc(true);
	const int selectedIndex = lvItem.GetSelectedIndex();
	if (selectedIndex<0) return; //_____________________________Nothing is selected
								 //_________________________________________________________Ask the user
	if (this->MessageBox(L"Are you sure you want to delete the selected item?", L"Delete item",
		MB_YESNO | MB_ICONQUESTION) != IDYES) return;
	//________________________________________________________Delete;
	Sql::SqlConnection conn;
	wstring cmd;
	const int item_id = lvItem.Items[selectedIndex].Data; //Get the Primary Key; 
	int rows = 0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (toolbMain.IsButtonEnabled(IDM_VEHICLEE) == false)
			Sys::Format(cmd, L"DELETE FROM userx WHERE userx_id= %d", item_id);
		else return;
		rows = conn.ExecuteNonQuery(cmd);
		if (rows != 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"ERROR: number of deleted rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException ex)
	{
		this->MessageBox(ex.GetDescription(), L"ERROR", MB_OK | MB_ICONERROR);
	}
	FillListView();
	toolbMain.EnableButton(IDM_DELETE, false);
}

void Vehicle::FillListView()
{
	FillListViewCol();
	lvItem.SetRedraw(false);
	lvItem.Items.DeleteAll();
	Sql::SqlConnection conn;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (toolbMain.IsButtonEnabled(IDM_VEHICLEE) == false)
		{
			conn.ExecuteSelect(L"SELECT userx_id, usuario, phone, email, descriptionx, typex, plate, cedula, entry_date, departure_date,street, street_block, house_number FROM vw_Usuario", 100, lvItem);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	lvItem.SetRedraw(true);
}

void Vehicle::FillListViewCol()
{
	lvItem.SetRedraw(false);
	lvItem.Cols.DeleteAll();
	if (toolbMain.IsButtonEnabled(IDM_VEHICLEE) == false)
	{
		lvItem.Cols.Add(0, LVCFMT_LEFT, 200, L"Name");
		lvItem.Cols.Add(1, LVCFMT_LEFT, 150, L"Phone");
		lvItem.Cols.Add(2, LVCFMT_LEFT, 200, L"Email");
		lvItem.Cols.Add(3, LVCFMT_LEFT, 200, L"Car_Description");
		lvItem.Cols.Add(4, LVCFMT_LEFT, 200, L"Type of car (Private)");
		lvItem.Cols.Add(5, LVCFMT_LEFT, 150, L"Plate");
		lvItem.Cols.Add(6, LVCFMT_LEFT, 150, L"Cedula");
		lvItem.Cols.Add(7, LVCFMT_LEFT, 200, L"Entry_date");
		lvItem.Cols.Add(8, LVCFMT_LEFT, 200, L"Departure_date");
		lvItem.Cols.Add(9, LVCFMT_LEFT, 200, L"street");
		lvItem.Cols.Add(10, LVCFMT_LEFT, 200, L"street_block");
		lvItem.Cols.Add(11, LVCFMT_LEFT, 200, L"House_number");
	}
	lvItem.SetRedraw(true);
}

