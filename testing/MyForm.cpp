#include "MyForm.h"
#include "MyForm1.h"
#include "Functions.h"
#include "MyForm2.h"
#include "User.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
[STAThreadAttribute]

int main(array<String^>^ args) {
	
		Application::SetCompatibleTextRenderingDefault(false);
		Application::EnableVisualStyles();
		testing::MyForm form;
		Application::Run(% form);
	
	
}
