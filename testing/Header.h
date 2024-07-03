#include "Functions.h"
#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

ref class Functions
{
public:
	Functions() {};
	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStrinfBuilder;
	void ConnectToDB() {
		//Data Source=DESKTOP-5SHM15R\SQLEXPRESS;Initial Catalog=testings;Integrated Security=True;Encrypt=False
		//Data Source = localhost\sqlexpress; Initial Catalog = you; Integrated Security = True; Encrypt = False
		connStrinfBuilder = gcnew SqlConnectionStringBuilder();
		connStrinfBuilder->DataSource = "DESKTOP-5SHM15R\\SQLEXPRESS";
		connStrinfBuilder->InitialCatalog = "testings";
		connStrinfBuilder->IntegratedSecurity = true;
		connStrinfBuilder->Encrypt = false;
		conn = gcnew SqlConnection(Convert::ToString(connStrinfBuilder));
	}
public: void Insert(String^ Name) {
	try {
		ConnectToDB();
		String^ cmdText = "INSERT INTO dbo.Tabltest(Name) VALUES(@NameVstavka)";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		cmd->Parameters->AddWithValue("@NameVstavka", Name);
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}

}

};
