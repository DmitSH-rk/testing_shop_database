#pragma once
#include "User.h"
#include "Functions.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "Functions.h"
#include "chrono"



namespace testing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	/// <summary>
	/// —водка дл€ MyForm2
	/// </summary>
	/// 
	
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(User^ user)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			//fuck1 = gcnew Functions();
			//f1 = gcnew Functions();
			label1->Text = "Welcome " + user->UserName +"!";
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: Functions fuck1;
	private: Functions f1;
	private: Functions fuck2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(199, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(30, 95);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(165, 27);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"Find";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(300, 95);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(87, 27);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"Add Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(27, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Name";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(393, 95);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(97, 27);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"Add Box";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(506, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 27);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(205, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(61, 27);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Find";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(205, 130);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(61, 26);
			this->button3->TabIndex = 8;
			this->button3->Text = L"DEL";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm2::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(295, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(166, 28);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Your prods ID:";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(609, 289);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//Functions f1; //= gcnew Functions();
		String^ id = textBox1->Text;
		String^ result = f1.FindSmt(id);
		textBox1->Text = "";
		//String^ name = result->Item1;
		//String^ box = result->Item2;
		label2->Text = "Name: " + result;
		//label2->Text = "Box: " + box;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Functions fuck1; //= gcnew Functions();
		String^ name = textBox2->Text;
		String^ box = textBox3->Text;
		int id = fuck1.AddSmt(name, box);
		label3->Text = "Your prods ID: " + System::Convert::ToString(id);
		textBox2->Text = "";
		textBox3->Text = "";
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Submit your choice", "Are you sure?", MessageBoxButtons::OK);
	fuck2.DltSmt(textBox1->Text);
	textBox1->Text = "";
}
};
}
