#pragma once
#include "User.h"
#include "MyForm2.h"
#include "MyForm1.h"
#include <tuple>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;
using namespace System::Collections::Generic;

public ref class Functions
{
//public: MyForm2^ form3 = gcnew MyForm2(user);
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
		};
	
public: bool Insert(String^ Name, String^ Login, String^ UserName) {
	try {
		ConnectToDB();
		if (!Name->Contains("@") || Login->Length < 5) {
			// ћожно бросить исключение или вернуть false, чтобы обозначить ошибку
			MessageBox::Show("Email is incorrect or pass should be more than five", "Email or password govno", MessageBoxButtons::OK);
			
			return false; // ≈сли предпочитаете возвращать логическое значение ошибки
		}
		else {
			String^ cmdText = "INSERT INTO dbo.Table_2(Name, Login, UserName) VALUES(@NameVstavka, @Login, @UserName)";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
			cmd->Parameters->AddWithValue("@NameVstavka", Name);
			cmd->Parameters->AddWithValue("@Login", Login);
			cmd->Parameters->AddWithValue("@UserName", UserName);
			conn->Open();
			cmd->ExecuteNonQuery();
			return true;
		}
		//MyForm1^ form1 = gcnew MyForm1();
		//form1->Show();
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}

}
public: User^ user = nullptr;
//public: MyForm2^ form3 = nullptr;
public:void Find(String^ Name, String^ Login, String^ UserName) {
	try {
		ConnectToDB();
		conn->Open();
		
		String^ cmdText = "SELECT * FROM dbo.Table_2 WHERE Name = @NameVstavka AND Login = @Login AND UserName = @UserName";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		cmd->Parameters->AddWithValue("@NameVstavka", Name);
		cmd->Parameters->AddWithValue("@Login", Login);
		cmd->Parameters->AddWithValue("@UserName", UserName);
		cmd->ExecuteNonQuery();
		SqlDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read()) {
			user = gcnew User;
			user->id = reader->GetInt32(0);
			user->Name = reader->GetString(1);
			user->Login = reader->GetString(2);
			user->UserName = reader->GetString(3);
			MessageBox::Show("Login is correct", "Email password submitted", MessageBoxButtons::OK);
			//MyForm2^ form3 = gcnew MyForm2(user);
			//form3->Show();
			reader->Close();
			

		}
		else
		{
			MessageBox::Show("Login or Name is incorrect", "Haram!", MessageBoxButtons::OK);
			
		}
	}
	finally {
		if (conn != nullptr ) {
			conn->Close();
		}
	}

}
public:String^ Search(String^ Name) {
	try {
		ConnectToDB();
		conn->Open();
		String^ cmdText = "SELECT * FROM dbo.Table_2 WHERE Name LIKE @NameVstavka";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		cmd->Parameters->AddWithValue("@NameVstavka", "%" + Name + "%");
		cmd->ExecuteNonQuery();
		SqlDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read()) {
			user = gcnew User;
			String^ name = user->Name;
			name = reader->GetString(1);
			return name;
		}
		else {
			return nullptr; // или возвращать String::Empty, или обработать случай, когда запись не найдена
		}
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}

public: String^ FindSmt(String^ id) {
	try {
		ConnectToDB();
		conn->Open();
		int id1 = System::Convert::ToInt32(id);
		String^ cmdText = "SELECT * FROM dbo.Table_1 WHERE id = @id";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		cmd->Parameters->AddWithValue("@id", id1);
		cmd->ExecuteNonQuery();
		SqlDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read()) {
			String^ name = reader->GetString(1);
			String^ box = reader->GetString(2);
			return  name;
		}
		else {
			return nullptr; // или возвращать String::Empty, если запись не найдена
		}
	}

	finally {
		  if (conn != nullptr) {
			  conn->Close();
		  }
	  }
}
public: int AddSmt(String^ Name, String^ box) {
	try{
		ConnectToDB();
		conn->Open();
		System::Collections::Generic::List<String^> ^ boxes = gcnew System::Collections::Generic::List<String^>();
		//System::Collections::Generic::List<String^>^ boxes1 = gcnew System::Collections::Generic::List<String^>();

		String^ cmdtext = "SELECT Box FROM dbo.Table_1 WHERE Box = @box";
		SqlCommand^ cmd = gcnew SqlCommand(cmdtext, conn);
		cmd->Parameters->AddWithValue("@box", box);
		SqlDataReader^ reader = cmd->ExecuteReader();
		while (reader->Read()) {
			String^ box1 = reader->GetString(reader->GetOrdinal("Box"));
			boxes->Add(box1);
		}
		reader->Close(); // «акрыть ридер перед выполнением нового запроса


		String^ cmdText = "INSERT INTO dbo.Table_1(Name, Box) VALUES(@Name, @Box)";
		SqlCommand^ cmd1 = gcnew SqlCommand(cmdText, conn);
		cmd1->Parameters->AddWithValue("@Name", Name);
		cmd1->Parameters->AddWithValue("@Box", box);
		if (boxes->Count > 9) {
			MessageBox::Show("This box is full", "Choose another box", MessageBoxButtons::OK);
			return -1; // «авершаем метод, если €щик полон
		}
		cmd1->ExecuteNonQuery();


		String^ cmdText1 = "SELECT id FROM dbo.Table_1 WHERE Name = @Name AND Box = @box";
		SqlCommand^ cmd2 = gcnew SqlCommand(cmdText1, conn);
		cmd2->Parameters->AddWithValue("@Name", Name);
		cmd2->Parameters->AddWithValue("@box", box);
		SqlDataReader^ reader2 = cmd2->ExecuteReader();

		// ќбработка данных из нового ридера
		if (reader2->Read()) {
			int id = reader2->GetInt32(reader2->GetOrdinal("id"));
			reader2->Close();
			return id;
		}
		else { reader2->Close(); return -1; }
	}
	finally{
		if (conn != nullptr) {
			conn->Close();
		}
	}
}
public: void DltSmt(String^ id) {
	try {
		ConnectToDB();
		conn->Open();

		String^ cmdText = "DELETE FROM dbo.Table_1 WHERE id = @id";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		int id1 = System::Convert::ToInt32(id);
		cmd->Parameters->AddWithValue("@id", id1);
		cmd->ExecuteNonQuery();
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}
	 
};

