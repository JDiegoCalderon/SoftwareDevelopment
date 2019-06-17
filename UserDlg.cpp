#include "stdafx.h"  //_____________________________________________ UserDlg.cpp
#include "UserDlg.h"

void UserDlg::Window_Open(Win::Event& e)
{
	this->Text = L"Userx";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (userx_id < 0) return;
		Sys::Format(cmd, L"SELECT first_name, last_name, phone, email FROM userx WHERE userx_id=%d", userx_id);
		conn.ExecuteSelect(cmd);
		tbxFirst_name.MaxTextLength = 32;
		conn.BindColumn(1, tbxFirst_name, 128);
		tbxLast_name.MaxTextLength = 32;
		conn.BindColumn(2, tbxLast_name, 128);
		tbxPhone.MaxTextLength = 32;
		conn.BindColumn(3, tbxPhone, 128);
		tbxEmail.MaxTextLength = 32;
		conn.BindColumn(4, tbxEmail, 128);
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

void UserDlg::btOK_Click(Win::Event& e)
{
	//_______________________________________________________________ Validate
	wregex regextbxFirst_name(L"[A-ZÁÉÍÓÚÑ][a-záéíóúñ]*(\\s[A-ZÁÉÍÓÚÑ][a-záéíóúñ]*)?");
	if (regex_match(tbxFirst_name.Text, regextbxFirst_name) == false)
	{
		tbxFirst_name.ShowBalloonTip(L"Invalid First name", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxLast_name(L"[A-ZÁÉÍÓÚÑ][a-záéíóúñ]*(\\s[A-ZÁÉÍÓÚÑ][a-záéíóúñ]*)?");
	if (regex_match(tbxLast_name.Text, regextbxLast_name) == false)
	{
		tbxLast_name.ShowBalloonTip(L"Invalid Last name", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxPhone(L"[0-9]{3}\\-[0-9]{3}\\-[0-9]{4}");
	if (regex_match(tbxPhone.Text, regextbxPhone) == false)
	{
		tbxPhone.ShowBalloonTip(L"Invalid Phone", L"Please provide the format:###-###-####", TTI_ERROR);
		return;
	}
	wregex regextbxEmail(L"^[_a-z0-9-]+(.[_a-z0-9-]+)*@[a-z0-9-]+(.[a-z0-9-]+)*(.[a-z]{2,4})$");
	if (regex_match(tbxEmail.Text, regextbxEmail) == false)
	{
		tbxEmail.ShowBalloonTip(L"Invalid Email", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"userx", L"userx_id", userx_id);
	sb.Bind(L"first_name", tbxFirst_name);
	sb.Bind(L"last_name", tbxLast_name);
	sb.Bind(L"phone", tbxPhone);
	sb.Bind(L"email", tbxEmail);
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		//__________________________________________________________________Conection
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

void UserDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

