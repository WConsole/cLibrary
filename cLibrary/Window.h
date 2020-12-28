#pragma once
#include "MyForm.h"

using namespace System;
using namespace System::Threading;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace cLibrary 
{
	public ref class Window : Standarts
	{
		void StartForm()
		{
			reinterpret_cast<Windows::Forms::Form^>(Window::Control)->ShowDialog();
		}

	public:
		Window(String^ Title, cLibrary::Vector2D^ Size)
		{
			WinAPI::MyForm^ Form = gcnew WinAPI::MyForm();
			Form->Text = Title;
			Form->Size = Drawing::Size(Size->X, Size->Y);

			Window::Control = Form; 
			Window::Size = Size;
			Window::Location = gcnew cLibrary::Vector2D(Form->Location.X, Form->Location.Y);
		}
		Window(String^ Title, cLibrary::Vector2D^ Size, cLibrary::Vector2D^ Location)
		{
			WinAPI::MyForm^ Form = gcnew WinAPI::MyForm();
			Form->Text = Title;
			Form->Size = Drawing::Size(Size->X, Size->Y);
			Form->Location = Drawing::Point(Location->X, Location->Y);

			Window::Control = Form;
			Window::Size = Size;
			Window::Location = Location;
		}

		void Show()
		{
			Thread^ t1 = gcnew Thread(gcnew ThreadStart(this, &Window::StartForm));
			t1->Start();
		}

		void BorderNone()
		{
			reinterpret_cast<Windows::Forms::Form^>(Window::Control)->FormBorderStyle = FormBorderStyle::None;
		}
		void BorderFix()
		{
			reinterpret_cast<Windows::Forms::Form^>(Window::Control)->FormBorderStyle = FormBorderStyle::FixedDialog;
		}
		void BorderDynamic()
		{
			reinterpret_cast<Windows::Forms::Form^>(Window::Control)->FormBorderStyle = FormBorderStyle::Sizable;
		}

	};
}
