#include "stdafx.h"  //_____________________________________________ UserDlg.cpp
#include "UserDlg.h"

void UserDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Userx";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		conn.ExecuteSelect(L"SELECT department_id, street FROM department", 100, ddDepartment);
		if (userx_id < 0) return;
		Sys::Format(cmd, L"SELECT first_name, last_name, phone, email, descriptionx, typex, plate, cedula, entry_date, departure_date, department_id, street_block, house_number FROM userx WHERE userx_id=%d", userx_id);
		conn.ExecuteSelect(cmd);
		tbxFirst_name.MaxTextLength = 32;
		conn.BindColumn(1, tbxFirst_name, 128);
		tbxLast_name.MaxTextLength = 32;
		conn.BindColumn(2, tbxLast_name, 128);
		tbxPhone.MaxTextLength = 32;
		conn.BindColumn(3, tbxPhone, 128);
		tbxEmail.MaxTextLength = 32;
		conn.BindColumn(4, tbxEmail, 128);
		tbxDescriptionx.MaxTextLength = 32;
		conn.BindColumn(5, tbxDescriptionx, 128);
		conn.BindColumn(6, ckTypex);
		tbxPlate.MaxTextLength = 32;
		conn.BindColumn(7, tbxPlate, 128);
		tbxCedula.MaxTextLength = 32;
		conn.BindColumn(8, tbxCedula, 128);
		dtboxEntry_date.SetFormat(L"MMM dd, yyyy"); 
		conn.BindColumn(9, dtboxEntry_date);
		dtboxDeparture_date.SetFormat(L"MMM dd, yyyy"); 
		conn.BindColumn(10, dtboxDeparture_date);
		conn.BindColumn(11, ddDepartment);
		tbxStreet_block.Number=true;
		conn.BindColumn(12, tbxStreet_block, 128);
		tbxHouse_number.Number=true;
		conn.BindColumn(13, tbxHouse_number, 128);
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
	//_____________________________________________________________ Validate
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
	wregex regextbxDescriptionx(L"[A-Za-z]+(\\s[A-Za-z]*)*");
	if (regex_match(tbxDescriptionx.Text, regextbxDescriptionx) == false)
	{
		tbxDescriptionx.ShowBalloonTip(L"Invalid Descriptionx", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxPlate(L"^[A-Z0-9]{6}$");
	if (regex_match(tbxPlate.Text, regextbxPlate) == false)
	{
		tbxPlate.ShowBalloonTip(L"Invalid Plate", L"Please provide the next format CCC###", TTI_ERROR);
		return;
	}
	wregex regextbxCedula(L"^[A-Z0-9]{8}$");
	if (regex_match(tbxCedula.Text, regextbxCedula) == false)
	{
		tbxCedula.ShowBalloonTip(L"Invalid Cedula", L"Please provide the next format CCCCC###", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"userx", L"userx_id", userx_id);
	sb.Bind(L"first_name", tbxFirst_name);
	sb.Bind(L"last_name", tbxLast_name);
	sb.Bind(L"phone", tbxPhone);
	sb.Bind(L"email", tbxEmail);
	sb.Bind(L"descriptionx", tbxDescriptionx);
	sb.Bind(L"typex", ckTypex);
	sb.Bind(L"plate", tbxPlate);
	sb.Bind(L"cedula", tbxCedula);
	sb.BindMicrosoft(L"entry_date", dtboxEntry_date);
	sb.BindMicrosoft(L"departure_date", dtboxDeparture_date);
	sb.Bind(L"department_id", ddDepartment);
	sb.Bind(L"street_block", tbxStreet_block);
	sb.Bind(L"house_number", tbxHouse_number);
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

void UserDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

