#include "stdafx.h"  //_____________________________________________ VehiDlg.cpp
#include "VehiDlg.h"

void VehiDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Vehicle";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (vehicle_id < 0) return;
		Sys::Format(cmd, L"SELECT marca, color, placa FROM vehicle WHERE vehicle_id=%d", vehicle_id);
		conn.ExecuteSelect(cmd);
		tbxMarca.MaxTextLength = 40;
		conn.BindColumn(1, tbxMarca, 128);
		tbxColor.MaxTextLength = 40;
		conn.BindColumn(2, tbxColor, 128);
		tbxPlaca.MaxTextLength = 40;
		conn.BindColumn(3, tbxPlaca, 128);
		if (conn.Fetch() == false)
		{
			this->MessageBox(L"No data was returned", L"Error", MB_OK);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
}

void VehiDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	wregex regextbxMarca(L"[A-ZÁÉÍÓÚÑ][a-záéíóúñ]*(\\s[A-ZÁÉÍÓÚÑ][a-záéíóúñ]*)?");
	if (regex_match(tbxMarca.Text, regextbxMarca) == false)
	{
		tbxMarca.ShowBalloonTip(L"Invalid Marca", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxColor(L"[A-Za-z]+(\\s[A-Za-z]*)*");
	if (regex_match(tbxColor.Text, regextbxColor) == false)
	{
		tbxColor.ShowBalloonTip(L"Invalid Color", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxPlaca(L"^[A-Z0-9]{6}$");
	if (regex_match(tbxPlaca.Text, regextbxPlaca) == false)
	{
		tbxPlaca.ShowBalloonTip(L"Invalid Placa", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"vehicle", L"vehicle_id", vehicle_id);
	sb.Bind(L"marca", tbxMarca);
	sb.Bind(L"color", tbxColor);
	sb.Bind(L"placa", tbxPlaca);
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		rows = conn.ExecuteNonQuery(sb.GetString());
		if (rows!=1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of affected rows", MB_OK | MB_ICONERROR);
			return;
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	this->EndDialog(TRUE);
}

void VehiDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

