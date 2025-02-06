#pragma once

//#define		MYMSG_NOTIFYICON		(WM_APP + 100)

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace Pinned;
using System::Runtime::InteropServices::Marshal;

/*void ChangeIcon(HINSTANCE hInstance, HWND hWnd, DWORD dwMsgType)
{
	std::string iconame;
	if (pin == false) {
		iconame = "Hidden_Boo.ico";
	}
	else if (pin == true) {
		iconame = "Boo.ico";
	}

	HICON hIconAtIndex = (HICON)LoadImageA(inst, iconame.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	NOTIFYICONDATA IconData;
	IconData.cbSize = sizeof(NOTIFYICONDATA);
	IconData.hIcon = hIconAtIndex;
	IconData.hWnd = hWnd;
	lstrcpyn(IconData.szTip, (LPCWSTR)"Test",
		(int)strlen("Test") + 1);
	IconData.uCallbackMessage = MYMSG_NOTIFYICON;

	IconData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;

	Shell_NotifyIcon(dwMsgType, &IconData);
	SendMessage(hWnd, WM_SETICON, NULL, (long)hIconAtIndex);
	if (hIconAtIndex)
		DestroyIcon(hIconAtIndex);
}*/

static std::string toStandardString(System::String^ string)
{
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);
	return returnString;
}

void startup()
{
	LPCSTR lpApplicationName = "Pinned.exe";
	// additional information
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcessA
	(
		lpApplicationName,   // the path
		NULL,                // Command line
		NULL,                   // Process handle not inheritable
		NULL,                   // Thread handle not inheritable
		FALSE,                  // Set handle inheritance to FALSE
		CREATE_NEW_CONSOLE,     // Opens file in a separate console
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi           // Pointer to PROCESS_INFORMATION structure
	);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

void savesettings(TextBox ^ txtbox) {
	std::ofstream cfile("config.bin");
	std::string temp;

	//Opacity
	cfile << opacity << std::endl;

	//ForeColor
	cfile << toStandardString(ColorTranslator::ToHtml(txtbox->ForeColor)) << std::endl;

	//Background
	cfile << toStandardString(ColorTranslator::ToHtml(txtbox->BackColor)) << std::endl;

	//Font
	//Font name
	cfile << toStandardString(txtbox->Font->FontFamily->GetName(0)) << std::endl;
	//Font size
	cfile << txtbox->Font->SizeInPoints << std::endl;
	//Font style
	cfile << (int)txtbox->Font->Style << std::endl;
	//Font crossed
	//cfile << txtbox->Font->Strikeout << std::endl;
	//Font underlined
	//cfile << txtbox->Font->Underline << std::endl;
	//Font unit
	//cfile << (int)txtbox->Font->Unit << std::endl;
	//Font alphabet
	cfile << (int)txtbox->Font->GdiCharSet << std::endl;

	cfile.close();
}

void loadsettings(TextBox ^ txtbox) {
	std::ifstream cfile("config.bin");
	std::string temp;

	if (cfile.good())
	{
		try {
			//Opacity
			std::getline(cfile, temp);
			opacity = std::stoi(temp);

			//Forecolor
			std::getline(cfile, temp);

			String ^ argh = gcnew String(temp.c_str());
			txtbox->ForeColor = ColorTranslator::FromHtml(argh);

			//Background
			std::getline(cfile, temp);
			argh = gcnew String(temp.c_str());
			txtbox->BackColor = ColorTranslator::FromHtml(argh);

			//Font
			//Font name
			std::getline(cfile, temp);
			System::String ^ fname = gcnew System::String(temp.c_str());

			//Font size
			std::getline(cfile, temp);
			Single fsize = Single(std::stof(temp));

			//Font style
			std::getline(cfile, temp);
			System::Drawing::FontStyle fstyle = (System::Drawing::FontStyle)std::stoi(temp);

			//Font crossed
			//std::getline(cfile, temp);


			//Font underlined
			/*std::getline(cfile, temp);
			int temp_underlined = std::stoi(temp);*/

			//Font unit
			//std::getline(cfile, temp);
			System::Drawing::GraphicsUnit funit = (System::Drawing::GraphicsUnit) 3/*std::stoi(temp)*/;

			//Font charset
			std::getline(cfile, temp);
			Byte fcharset = Byte(std::stoi(temp));

			Font ^ f = gcnew Font(fname, fsize, fstyle, funit, fcharset);
			txtbox->Font = f;

			delete fname;
			delete argh;
			delete f;

			cfile.close();
		}
		catch (Exception ^ e) {
			cfile.close();
			std::remove("config.bin");
		}
	}
}

void save(TextBox^ txtbox) {

	SaveFileDialog ^ dlgSave = gcnew SaveFileDialog;

	dlgSave->OverwritePrompt = true;

	dlgSave->FileName = "Pinned Text";
	dlgSave->DefaultExt = "txt";
	dlgSave->Filter = "Plain Text files(*.txt) | *.txt | All files(*.*) | *.*";
	//dlgSave->InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

	if (dlgSave->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Open the file, copy the contents of memoryStream to fileStream,
		// and close fileStream. Set the memoryStream.Position value to 0 
		// to copy the entire stream. 

		//Use StreamWriter class.
		StreamWriter ^ sw = gcnew StreamWriter(dlgSave->OpenFile());

		//Use write method to write the text
		sw->Write(txtbox->Text);

		//always close your stream
		sw->Close();

		delete sw;
	}

	delete dlgSave;
}

void newdoc(TextBox^ txtbox) {
	if (txtbox->Text != "") {
		DialogResult dialogResult = System::Windows::Forms::MessageBox::Show("Would you like to save?", "Attention", MessageBoxButtons::YesNoCancel);
		if (dialogResult == DialogResult::Yes)
		{
			SaveFileDialog ^ dlgSave = gcnew SaveFileDialog;

			dlgSave->OverwritePrompt = true;

			dlgSave->FileName = "Pinned Text";
			dlgSave->DefaultExt = "txt";
			dlgSave->Filter = "Plain Text files(*.txt) | *.txt | All files(*.*) | *.*";
			//dlgSave->InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

			if (dlgSave->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				// Open the file, copy the contents of memoryStream to fileStream,
				// and close fileStream. Set the memoryStream.Position value to 0 
				// to copy the entire stream. 

				//Use StreamWriter class.
				StreamWriter ^ sw = gcnew StreamWriter(dlgSave->OpenFile());

				//Use write method to write the text
				sw->Write(txtbox->Text);

				//always close your stream
				sw->Close();
				delete sw;

				txtbox->Clear();
				txtbox->ClearUndo();
			}
			delete dlgSave;
		}
		else if (dialogResult == DialogResult::No)
		{
			txtbox->Clear();
			txtbox->ClearUndo();
		}
		else if (dialogResult == DialogResult::Cancel) {

		}
	}
	else {
		txtbox->ClearUndo();
	}
}

void loadtext(TextBox^ txtbox) {
	OpenFileDialog ^ dlgOpen = gcnew OpenFileDialog();

	if (dlgOpen->ShowDialog() == System::Windows::Forms::DialogResult::OK){

		txtbox->Text = File::ReadAllText(dlgOpen->FileName);
	}

	delete dlgOpen;
}

void showfontdial(TextBox ^ txtbox) {
	FontDialog ^ dlgFont = gcnew FontDialog();

	dlgFont->ShowColor = true;

	dlgFont->Font = gcnew Font(txtbox->Font->FontFamily, txtbox->Font->Size, txtbox->Font->Style, txtbox->Font->Unit, txtbox->Font->GdiCharSet);
	dlgFont->Color = txtbox->ForeColor;

	if (dlgFont->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		txtbox->Font = dlgFont->Font;
		txtbox->ForeColor = dlgFont->Color;
		savesettings(txtbox);
	}

	delete dlgFont;
}

void setpin(System::Windows::Forms::Form^ form, System::Windows::Forms::MenuStrip^ mstrip, System::Windows::Forms::TextBox^ textbox) {

	//PIN
	pin = true;
	//mi_pin->Text = "Unpin";
	mstrip->Hide();
	form->TopMost = true;
	form->ControlBox = false;
	//Opacity = 0.8;
	form->ShowIcon = false;
	form->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	/*textbox->BackColor = Color::Black;
	textbox->Enabled = false;*/
	int initialStyle = GetWindowLong(hwnd, -20);
	SetWindowLong(hwnd, -20, initialStyle | 0x80000 | 0x20);
	SetLayeredWindowAttributes(hwnd, 0, opacity, LWA_ALPHA);
	//ChangeIcon(inst, hwnd, NIM_MODIFY);
}

void removepin(System::Windows::Forms::Form^ form, System::Windows::Forms::MenuStrip^ mstrip, System::Windows::Forms::TextBox^ textbox) {

	pin = false;
	mstrip->Show();
	form->TopMost = false;
	form->ControlBox = true;
	form->ShowIcon = true;
	form->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
	EnableWindow(hwnd, true);
	SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);
	
	//ChangeIcon(inst, hwnd, NIM_MODIFY);
}

void showsettings(TextBox ^ txtbox) {
	Settings ^ settings = gcnew Settings;
	settings->backgroundcolor = txtbox->BackColor;
	settings->transparency = opacity;

	//settings->Show();
	if (settings->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		txtbox->BackColor = settings->backgroundcolor;
		opacity = settings->transparency;
		savesettings(txtbox);
	}

	delete settings;
}