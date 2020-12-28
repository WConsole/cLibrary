#pragma once

#include "Vector.h"
#include "Color.h"
#include "Standart.h"
#include "Window.h"
#include "Button.h"
#include "TextBox.h"
#include "ListBox.h"
#include "Panel.h"

using namespace System;
using namespace System::Windows::Forms;

public ref class cLibraryInfos
{
	static String^ v = "1.0.0.0";

public:

	static void Show()
	{
		if (MessageBox::Show("cLibrary v" + v + Environment::NewLine + Environment::NewLine + "Do you want show documentation?", "cLibrary Infos", MessageBoxButtons::YesNo) == DialogResult::Yes)
		{
			System::Diagnostics::Process::Start("https://github.com/WConsole/cLibrary/tree/main/Documentation");
		}
	}

};