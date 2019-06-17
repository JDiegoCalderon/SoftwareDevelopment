#include "stdafx.h"  //_____________________________________________ VisitDlg.cpp
#include "VisitDlg.h"

void VisitDlg::Window_Open(Win::Event& e)
{
	this->Text = L"Visit";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//_______________________________________________________________Conection
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		conn.ExecuteSelect(L"SELECT userx_id, last_name FROM userx", 100, ddUser);
		conn.ExecuteSelect(L"SELECT vehicle_id, placa FROM vehicle", 100, ddVehicle);
		conn.ExecuteSelect(L"SELECT department_id, street FROM department", 100, ddDepartment);
		if (visita_id < 0) return;
		Sys::Format(cmd, L"SELECT userx_id, vehicle_id, entry_date, departure_date,department_id FROM visit WHERE visit_id=%d", visita_id);
		conn.ExecuteSelect(cmd);
		conn.BindColumn(1, ddUser);
		conn.BindColumn(2, ddVehicle);
		dtboxEntry_Date.SetFormat(L"MMM dd, yyyy");
		conn.BindColumn(3, dtboxEntry_Date);
		dtboxDeparture_Date.SetFormat(L"MMM dd, yyyy");
		conn.BindColumn(4, dtboxDeparture_Date);
		conn.BindColumn(5, ddDepartment);
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



void VisitDlg::btOk_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	Sql::StringBuilder sb(L"Visita", L"visita_id", visita_id);
	sb.Bind(L"userx_id", ddUser);
	sb.Bind(L"vehicle_id", ddVehicle);
	sb.BindMicrosoft(L"entry_date", dtboxEntry_Date);
	sb.BindMicrosoft(L"departure_date", dtboxDeparture_Date);
	sb.Bind(L"department_id", ddDepartment);
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		rows = conn.ExecuteNonQuery(sb.GetString());
		if (rows != 1)
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

void VisitDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

