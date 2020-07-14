#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <Windows.h>
#include <WinUser.h>
//include "Custom.h"
#include "Variables.h"
#include "Settings.h"
#include "PinFunctions.h"
#include "MyForm.h"

using namespace Pinned; // This is your project name

[STAThread]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)

{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MyForm());

	return 0;

}