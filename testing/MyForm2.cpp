#include "MyForm2.h"
#include "MyForm1.h"
#include "Functions.h"
#include "User.h"
using namespace System;
using namespace System::Windows::Forms;
//using namespace testing;
using namespace System::Collections::Generic;
[STAThreadAttribute]

int main2(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	//testing::MyForm2 form2;
	//Application::Run(% form2);
	//Functions h;
	//User^ user = h.user;
	//if (user != nullptr) {
		//MessageBox::Show("Login or Name is correct", "Email password yes", MessageBoxButtons::OK);
	//}
	//else { MessageBox::Show("Lo", "Email password yes", MessageBoxButtons::OK); }
	return 0;
}