#include "MyForm1.h"
#include "Functions.h"
#include "MyForm2.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace testing3;
using namespace System::Collections::Generic;
[STAThreadAttribute]

int main1(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	//testing::MyForm1 form1;
	//Application::Run(% form1);
	//Functions h;
	//User^ user = h.user;
	//if (user != nullptr) {
		//MessageBox::Show("Login or Name is correct", "Email password yes", MessageBoxButtons::OK);
	//}
	//else { MessageBox::Show("Lo", "Email password yes", MessageBoxButtons::OK); }
	return 0;
}