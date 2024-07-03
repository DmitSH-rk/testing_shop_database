#pragma once
#include "MyForm1.h"
#include "MyForm2.h"
#include "Functions.h"
#include "chrono"
#include "User.h"

namespace testing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			//form3 = gcnew MyForm2();
			//f = gcnew Functions();
			debounceTimer = gcnew System::Windows::Forms::Timer();
			debounceTimer->Interval = 300; // Интервал задержки для дебаунса
			debounceTimer->Tick += gcnew System::EventHandler(this, &MyForm::OnDebounceTimerTick);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
		   //private: MyForm2^ form3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private:
		bool _isTextUpdating = false;
		Functions f;
		Functions f1;
		User^ user;
	private: System::Windows::Forms::Timer^ debounceTimer;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(197, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"REG";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(22, 10);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(133, 27);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Login";
			this->textBox1->Click += gcnew System::EventHandler(this, &MyForm::textBox1_Click);
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(51, 123);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(72, 47);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Login";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(22, 47);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(133, 27);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"Password";
			this->textBox2->Click += gcnew System::EventHandler(this, &MyForm::textBox2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(22, 84);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(132, 27);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"Name";
			this->textBox3->Click += gcnew System::EventHandler(this, &MyForm::textBox3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//MessageBox::Show("Привет, это сообщение MessageBox!", "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
		MyForm1^ form2 = gcnew MyForm1();
		form2->Show();

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		//Functions f1;// = gcnew Functions();
		f1.Find(textBox1->Text, textBox2->Text, textBox3->Text);
		MyForm2^ form3 = gcnew MyForm2(f1.user);
		form3->Show();
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
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (_isTextUpdating) {
			return; // Если текст обновляется программно, не выполнять поиск
		}
		int minSearchLength = 3;
		if (textBox1->Text->Length < minSearchLength) {
			return; // Если текст короче минимальной длины для поиска, выходим
		}
		// Перезапуск таймера дебаунса
		debounceTimer->Stop();
		debounceTimer->Start();
	}
		   System::Void OnDebounceTimerTick(System::Object^ sender, System::EventArgs^ e)
		   {
			   debounceTimer->Stop(); // Останавливаем таймер

			   _isTextUpdating = true; // Устанавливаем флаг перед началом обновления текста

			   try {
				   //Functions f; //= gcnew Functions();
				   String^ searchText = textBox1->Text->Substring(0, std::min(textBox1->Text->Length, 100));
				   String^ result = f.Search(searchText);

				   if (!String::IsNullOrEmpty(result)) {
					   // Обновляем текст только если он отличается, чтобы избежать рекурсии
					   if (textBox1->Text != result) {
						   textBox1->Text = result;
					   }
				   }
			   }
			   
			   finally {
				   _isTextUpdating = false; // Сбрасываем флаг после завершения обновления текста
			   }
		   }

};
}
