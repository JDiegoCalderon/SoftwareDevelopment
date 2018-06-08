#include "stdafx.h"  //________________________________________ Residen.cpp
#include "Residen.h"
#include "UserDlg.h"
#include "VehiDlg.h"
#include "VisitDlg.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	Residen app;
	app.CreateMainWindow(L"Residen", cmdShow, IDI_Residen, NULL, (HBRUSH)(COLOR_WINDOW + 1), hInstance);
	return app.MessageLoop(IDC_Residen);
}

void Residen::Window_Open(Win::Event& e)
{
	//________________________________________________________ toolbMain
	TBBUTTON tbButton[11];//<< EDIT HERE THE NUMBER OF BUTTONS

	toolbMain.imageList.Create(35, 45, 9);//<< EDIT HERE THE NUMBER OF IMAGES
	toolbMain.imageList.AddIcon(this->hInstance, IDI_ADD);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_EDIT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_DELETE);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_CLIENT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_CART);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_SAVE);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_PRINT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_COPY);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_MSEXCEL);
	toolbMain.SendMessage(TB_BUTTONSTRUCTSIZE, (WPARAM)(int)sizeof(TBBUTTON), 0);
	toolbMain.SetImageList(toolbMain.imageList);
	//_____________________________________
	tbButton[0].iBitmap = MAKELONG(0, 0); //<< IMAGE INDEX
	tbButton[0].idCommand = IDM_ADD;
	tbButton[0].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[0].fsStyle = BTNS_BUTTON;
	tbButton[0].dwData = 0L;
	tbButton[0].iString = (LONG_PTR)L"Add";
	//_____________________________________
	tbButton[1].iBitmap = MAKELONG(1, 0); //<< IMAGE INDEX
	tbButton[1].idCommand = IDM_EDIT;
	tbButton[1].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[1].fsStyle = BTNS_BUTTON;
	tbButton[1].dwData = 0L;
	tbButton[1].iString = (LONG_PTR)L"Edit";
	//_____________________________________
	tbButton[2].iBitmap = MAKELONG(2, 0); //<< IMAGE INDEX
	tbButton[2].idCommand = IDM_DELETE;
	tbButton[2].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[2].fsStyle = BTNS_BUTTON;
	tbButton[2].dwData = 0L;
	tbButton[2].iString = (LONG_PTR)L"Delete";
	//_______________________ A separator
	tbButton[3].iBitmap = -1;
	tbButton[3].idCommand = 0;
	tbButton[3].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[3].fsStyle = BTNS_SEP;
	tbButton[3].dwData = 0L;
	tbButton[3].iString = 0;
	//_____________________________________
	tbButton[4].iBitmap = MAKELONG(3, 0); //<< IMAGE INDEX
	tbButton[4].idCommand = IDM_CLIENT;
	tbButton[4].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[4].fsStyle = BTNS_BUTTON;
	tbButton[4].dwData = 0L;
	tbButton[4].iString = (LONG_PTR)L"User";
	//_____________________________________
	tbButton[5].iBitmap = MAKELONG(4, 0); //<< IMAGE INDEX
	tbButton[5].idCommand = IDM_CART;
	tbButton[5].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[5].fsStyle = BTNS_BUTTON;
	tbButton[5].dwData = 0L;
	tbButton[5].iString = (LONG_PTR)L"Cart";
	//_____________________________________
	tbButton[6].iBitmap = MAKELONG(5, 0); //<< IMAGE INDEX
	tbButton[6].idCommand = IDM_SAVE;
	tbButton[6].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[6].fsStyle = BTNS_BUTTON;
	tbButton[6].dwData = 0L;
	tbButton[6].iString = (LONG_PTR)L"Save visit";
	//_______________________ A separator
	tbButton[7].iBitmap = -1;
	tbButton[7].idCommand = 0;
	tbButton[7].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[7].fsStyle = BTNS_SEP;
	tbButton[7].dwData = 0L;
	tbButton[7].iString = 0;
	//_____________________________________
	tbButton[8].iBitmap = MAKELONG(6, 0); //<< IMAGE INDEX
	tbButton[8].idCommand = IDM_PRINT;
	tbButton[8].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[8].fsStyle = BTNS_BUTTON;
	tbButton[8].dwData = 0L;
	tbButton[8].iString = (LONG_PTR)L"Print";
	//____________________________________
	tbButton[9].iBitmap = MAKELONG(7, 0); //<< IMAGE INDEX
	tbButton[9].idCommand = IDM_COPY;
	tbButton[9].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[9].fsStyle = BTNS_BUTTON;
	tbButton[9].dwData = 0L;
	tbButton[9].iString = (LONG_PTR)L"Copy";
	//_____________________________________
	tbButton[10].iBitmap = MAKELONG(8, 0); //<< IMAGE INDEX
	tbButton[10].idCommand = IDM_MSEXCEL;
	tbButton[10].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[10].fsStyle = BTNS_BUTTON;
	tbButton[10].dwData = 0L;
	tbButton[10].iString = (LONG_PTR)L"Export to Microsoft Excel";

	toolbMain.SetBitmapSize(40, 44);
	toolbMain.SetButtonSize(35, 33);
	//toolbMain.SetBitmapSize(pixelsIconSize, pixelsIconSize);
	//toolbMain.SetButtonSize(pixelsButtonSize, pixelsButtonSize);
	toolbMain.AddButtons(tbButton, 11);// << EDIT HERE THE NUMBER OF BUTTONS
	toolbMain.SendMessage(TB_AUTOSIZE, 0, 0);
	toolbMain.SetMaxTextRows(0);// EDIT HERE TO DISPLAY THE BUTTON TEXT
	toolbMain.Show(SW_SHOWNORMAL);
	//	toolbMain.ResizeToFit();

	//_______________________________________________________Enable or disable buttoms
	toolbMain.EnableButton(IDM_ADD, false);
	toolbMain.EnableButton(IDM_EDIT, false);
	toolbMain.EnableButton(IDM_DELETE, false);
	toolbMain.EnableButton(IDM_PRINT, true);
	toolbMain.EnableButton(IDM_CLIENT, true);
	toolbMain.EnableButton(IDM_CART, true);
	toolbMain.EnableButton(IDM_COPY, true);
	toolbMain.EnableButton(IDM_MSEXCEL, true);
	//________________________________________________________ lvItem
	lvItem.Cols.Add(0, LVCFMT_CENTER, 200, L"Select an option.");

	FillListViewCol();

	//________________________________________________________ img1
	img1.FileName = L"C:\\logo.jpg";
//	img1.SetIcon(hInstance, IDI_JOHN);
//	img1.SetBitmap(hInstance, IDB_MARY);
//	img1.SetEMF(hInstance, IDR_EMF1);

	//________________________________________________________Drop down visible 
	ddCategory1.Visible = false;
	ddCategory.Visible = false;
	//ddCategory2.Visible = false;

}

void Residen::lvItem_ItemChanged(Win::Event& e)
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

void Residen::lvItem_KeyDown(Win::Event& e)
{
	LPNMLVKEYDOWN p = (LPNMLVKEYDOWN) e.lParam;
	if (p->wVKey == VK_DELETE)
	{
		DeleteItems();
	}
}

//_____________________________________________________Para que al momento de dar doble clic se edite 
void Residen::lvItem_DblClk(Win::Event& e)
{
	EditItems();
}

//____________________________________________________Agregar item
void Residen::Cmd_Add(Win::Event& e)
{
	InsertItems();
}

void Residen::Cmd_Copy(Win::Event& e)
{
	toolbMain.EnableButton(IDM_COPY, false);
	lvItem.CopyToClipboard();
	toolbMain.EnableButton(IDM_COPY, true);
}


void Residen::Cmd_Cart(Win::Event& e)
{
	toolbMain.EnableButton(IDM_ADD, true);
	toolbMain.EnableButton(IDM_CART, false);
	toolbMain.EnableButton(IDM_CLIENT, true);
	toolbMain.EnableButton(IDM_SAVE, true);
	toolbMain.EnableButton(IDM_EDIT, false);
	toolbMain.EnableButton(IDM_DELETE, false);
	FillListView();
}

void Residen::Cmd_Client(Win::Event& e)
{
	toolbMain.EnableButton(IDM_ADD, true);
	toolbMain.EnableButton(IDM_CART, true);
	toolbMain.EnableButton(IDM_CLIENT, false);
	toolbMain.EnableButton(IDM_SAVE, true);
	toolbMain.EnableButton(IDM_EDIT, false);
	toolbMain.EnableButton(IDM_DELETE, false);
	FillListView();
}

void Residen::Cmd_Save(Win::Event& e)
{
	toolbMain.EnableButton(IDM_ADD, true);
	toolbMain.EnableButton(IDM_CART, true);
	toolbMain.EnableButton(IDM_CLIENT, true);
	toolbMain.EnableButton(IDM_SAVE, false);
	toolbMain.EnableButton(IDM_EDIT, false);
	toolbMain.EnableButton(IDM_DELETE, false);
	FillListView();
}

void Residen::Cmd_Delete(Win::Event& e)
{
	DeleteItems();
}

void Residen::Cmd_Edit(Win::Event& e)
{
	EditItems();
}

void Residen::Cmd_Msexcel(Win::Event& e)
{
	toolbMain.EnableButton(IDM_MSEXCEL, false);
	Win::FileDlg filedlg;
	filedlg.SetFilter(L"Excel File(*.xlsx)\0*.xlsx\0All Files(*.*)\0*.*\0\0", 0, L"xlsx");
	if (filedlg.BeginDialog(hWnd, L"Save a Ms Excel File", true));
	{
		lvItem.ExportToMsExcel(filedlg.GetFileNameFullPath());
	}
	toolbMain.EnableButton(IDM_MSEXCEL, true);
}


void Residen::Cmd_Print(Win::Event& e)
{
	lvItem.Print();
}

//__________________________________Funcion actualizar items 
void Residen::FillListView()
{
	FillListViewCol();
	lvItem.SetRedraw(false);
	lvItem.Items.DeleteAll();
	Sql::SqlConnection conn;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (toolbMain.IsButtonEnabled(IDM_CLIENT) == false)
		{
			conn.ExecuteSelect(L"SELECT userx_id, usuario, phone, email FROM vw_User", 100, lvItem);
			//ddCategory2.Visible = false;
			ddCategory1.Visible = false;
			ddCategory.Visible = true;
			conn.ExecuteSelect(L"SELECT userx_id, usuario FROM vw_User", 100, ddCategory);
		}
		if (toolbMain.IsButtonEnabled(IDM_CART) == false)
		{
			ddCategory1.Items.DeleteAll();
			conn.ExecuteSelect(L"SELECT vehicle_id, usuario, marca, color, placa FROM vw_Vehi", 100, lvItem);
			//ddCategory2.Visible = false;
			ddCategory.Visible = false;
			ddCategory1.Visible = true;
			conn.ExecuteSelect(L"SELECT vehicle_id, marca FROM vw_Vehi", 100, ddCategory1);
		}
		if (toolbMain.IsButtonEnabled(IDM_SAVE) == false)
		{
			conn.ExecuteSelect(L"SELECT visita_id, Usuario,vehiclee, entry_date, departure_date, street FROM vw_Visi", 100, lvItem);
			//ddCategory2.Visible = true;
			ddCategory.Visible = false;
			ddCategory1.Visible = false;
			//conn.ExecuteSelect(L"SELECT visita_id, entry_date FROM visita", 100, ddCategory2);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	lvItem.SetRedraw(true);
}


//__________________________________________________Funcion actualizar columnas 
void Residen::FillListViewCol()
{
	lvItem.SetRedraw(false);
	lvItem.Cols.DeleteAll();
	if (toolbMain.IsButtonEnabled(IDM_CLIENT) == false)
	{
		lvItem.Cols.Add(0, LVCFMT_LEFT, 200, L"Name");
		lvItem.Cols.Add(1, LVCFMT_LEFT, 150, L"Phone");
		lvItem.Cols.Add(2, LVCFMT_LEFT, 200, L"Email");
	}
	else if (toolbMain.IsButtonEnabled(IDM_CART) == false)
	{
		lvItem.Cols.Add(0, LVCFMT_LEFT, 200, L"Name");
		lvItem.Cols.Add(1, LVCFMT_LEFT, 200, L"Marca");
		lvItem.Cols.Add(2, LVCFMT_LEFT, 200, L"Color");
		lvItem.Cols.Add(3, LVCFMT_LEFT, 200, L"Placa");
	}
	else if (toolbMain.IsButtonEnabled(IDM_SAVE) == false)
	{
		this->Text = L"Visit Table";
		lvItem.Cols.Add(0, LVCFMT_LEFT, 180, L"User name");
		lvItem.Cols.Add(1, LVCFMT_LEFT, 180, L"Vehicle");
		lvItem.Cols.Add(2, LVCFMT_LEFT, 200, L"Entry date");
		lvItem.Cols.Add(3, LVCFMT_LEFT, 200, L"departure date");
		lvItem.Cols.Add(4, LVCFMT_LEFT, 200, L"Street");
	}
	lvItem.SetRedraw(true);
}

void Residen::InsertItems()
{
	toolbMain.EnableButton(IDM_ADD, false);
	if (toolbMain.IsButtonEnabled(IDM_CLIENT) == false)
	{
		UserDlg user_dlg;
		user_dlg.BeginDialog(hWnd);
	}
	else if (toolbMain.IsButtonEnabled(IDM_CART) == false)
	{
		VehiDlg vehidlg;
		vehidlg.BeginDialog(hWnd);
	}
	else if (toolbMain.IsButtonEnabled(IDM_SAVE) == false)
	{
		VisitDlg visitdlg;
		visitdlg.BeginDialog(hWnd);
	}
	else return;
	FillListView();
	toolbMain.EnableButton(IDM_ADD, true);
}

void Residen::EditItems()
{
	toolbMain.EnableButton(IDM_EDIT, false);
	const int selectedIndex = lvItem.GetSelectedIndex();
	if (selectedIndex<0) return;
	////____________________________________________________Ask the user
	//if (this->MessageBox(L"Are you sure you want to modify the selected item?", L"Edit item",
	//	MB_YESNO | MB_ICONQUESTION) != IDYES) return;
	//___________________________________________________Edit
	const int item_id = lvItem.Items[selectedIndex].Data;
	if (toolbMain.IsButtonEnabled(IDM_CLIENT) == false)
	{
		UserDlg user_dlg;
		user_dlg.userx_id = item_id;
		user_dlg.BeginDialog(hWnd);
	}
	else if (toolbMain.IsButtonEnabled(IDM_CART) == false)
	{
		VehiDlg vehidlg;
		vehidlg.vehicle_id = item_id;
		vehidlg.BeginDialog(hWnd);
	}
	else if (toolbMain.IsButtonEnabled(IDM_SAVE) == false)
	{
		VisitDlg visitdlg;
		visitdlg.visita_id = item_id;
		visitdlg.BeginDialog(hWnd);
	}
	else return;
	FillListView();
	toolbMain.EnableButton(IDM_EDIT, true);
}

void Residen::DeleteItems()
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
		if (toolbMain.IsButtonEnabled(IDM_CLIENT) == false)
			Sys::Format(cmd, L"DELETE FROM userx WHERE userx_id= %d", item_id);
		else if (toolbMain.IsButtonEnabled(IDM_CART) == false)
			Sys::Format(cmd, L"DELETE FROM vehicle WHERE vehicle_id= %d", item_id);
		else if (toolbMain.IsButtonEnabled(IDM_SAVE) == false)
			Sys::Format(cmd, L"DELETE FROM visita WHERE visita_id= %d", item_id);
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

void Residen::SearchUser()
{
	LPARAM userx_id, vehicle_id;
	if (ddCategory.GetSelectedData(userx_id) == false)return;
	//const int userx_id = ddCategory.;
	wstring sqlcmd;
	Sys::Format(sqlcmd, L"SELECT userx_id, usuario, phone, email FROM vw_User WHERE userx_id=%d", userx_id);
	Win::HourGlassCursor hgc(true);
	Sql::SqlConnection conn;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD);
		conn.OpenSession(hWnd, CONNECTION_STRING);
		lvItem.SetRedraw(false);//stop redrawing the control when inserting items
		lvItem.Items.DeleteAll();
		conn.ExecuteSelect(sqlcmd, 100, lvItem);
		lvItem.SetRedraw(true);
	}
	catch (Sql::SqlException ex)
	{
		this->MessageBox(ex.GetDescription(), L"ERROR", MB_OK | MB_ICONERROR);
	}
}

void Residen::SearchVehi()
{
	LPARAM vehicle_id;
	if (ddCategory1.GetSelectedData(vehicle_id) == false)return;
	//const int userx_id = ddCategory.;
	wstring sqlcmd;
	Sys::Format(sqlcmd, L"SELECT vehicle_id, usuario, marca, color, placa FROM vw_Vehi WHERE vehicle_id=%d", vehicle_id);
	Win::HourGlassCursor hgc(true);
	Sql::SqlConnection conn;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD);
		conn.OpenSession(hWnd, CONNECTION_STRING);
		lvItem.SetRedraw(false);//stop redrawing the control when inserting items
		lvItem.Items.DeleteAll();
		conn.ExecuteSelect(sqlcmd, 100, lvItem);
		lvItem.SetRedraw(true);
	}
	catch (Sql::SqlException ex)
	{
		this->MessageBox(ex.GetDescription(), L"ERROR", MB_OK | MB_ICONERROR);
	}
}

//void Residen::SearchRegi()
//{
//	LPARAM visita_id;
//	if (ddCategory2.GetSelectedData(visita_id) == false)return;
//	//const int userx_id = ddCategory.;
//	wstring sqlcmd;
//	Sys::Format(sqlcmd, L"SELECT vehicle_id, Usuario,vehiclee, entry_date, departure_date, street FROM vw_Visi WHERE visita_id=%d", visita_id);
//	Win::HourGlassCursor hgc(true);
//	Sql::SqlConnection conn;
//	try
//	{
//		//conn.OpenSession(DSN, USERNAME, PASSWORD);
//		conn.OpenSession(hWnd, CONNECTION_STRING);
//		lvItem.SetRedraw(false);//stop redrawing the control when inserting items
//		lvItem.Items.DeleteAll();
//		conn.ExecuteSelect(sqlcmd, 100, lvItem);
//		lvItem.SetRedraw(true);
//	}
//	catch (Sql::SqlException ex)
//	{
//		this->MessageBox(ex.GetDescription(), L"ERROR", MB_OK | MB_ICONERROR);
//	}
//}


void Residen::lb1_CtlColorStatic(Win::Event& e)
{
}

void Residen::ddCategory_SelChange(Win::Event& e)
{
	SearchUser();
}

void Residen::ddCategory1_SelChange(Win::Event& e)
{
	SearchVehi();
}

//void Residen::ddCategory2_SelChange(Win::Event& e)
//{
//	SearchRegi();
//}

