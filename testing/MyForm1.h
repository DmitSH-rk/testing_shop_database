#pragma once
#include "MyForm1.h"
#include "MyForm2.h"
#include "Functions.h"
#include "User.h"

namespace testing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	/// <summary>
	/// —водка дл€ MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//f2 = gcnew Functions();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3; 
	private: Functions f4;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(62, 132);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Registrate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(62, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(156, 27);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Login";
			this->textBox1->Click += gcnew System::EventHandler(this, &MyForm1::textBox1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(62, 51);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(156, 27);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"Password";
			this->textBox2->Click += gcnew System::EventHandler(this, &MyForm1::textBox2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(62, 84);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(156, 27);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"Name";
			this->textBox3->Click += gcnew System::EventHandler(this, &MyForm1::textBox3_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"Registration";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Functions f2;
		//Functions f2;
		bool fuck = f4.Insert(textBox1->Text, textBox2->Text, textBox3->Text);
		if (fuck == true) {
			this->Close();
		}
	}
	
	
private: System::Void textBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox3->Text = "";
}
private: System::Void textBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = "";
}
private: System::Void textBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = "";
}
};

}
