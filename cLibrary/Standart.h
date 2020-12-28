#pragma once

using namespace System;
using namespace System::Windows::Forms;

public ref class Standarts
{
	String^ Button = "System.Windows.Forms.Button";
	String^ TextBox = "System.Windows.Forms.TextBox";
	String^ ListBox = "System.Windows.Forms.ListBox";
	String^ Panel = "System.Windows.Forms.Panel";

public:
	Windows::Forms::Control^ Control;
	cLibrary::Vector2D^ Location;
	cLibrary::Vector2D^ Size;
	static System::String^ Text;

	void ChangeForeColor(cLibrary::ColorRGB^ Color)
	{
		Control->ForeColor = Color::FromArgb(255, Color->R, Color->G, Color->B);
	}
	void ChangeBackColor(cLibrary::ColorRGB^ Color)
	{
		Control->BackColor = Color::FromArgb(255, Color->R, Color->G, Color->B);
	}
	void ChangeLocation(cLibrary::Vector2D^ NewLocation)
	{
		Control->Location = Point(NewLocation->X, NewLocation->Y);
		Location = NewLocation;
	}
	void ChangeSize(cLibrary::Vector2D^ NewSize)
	{
		Control->Size = Drawing::Size(NewSize->X, NewSize->Y);
	}

	void BorderNone()
	{

		MessageBox::Show(Control->GetType()->ToString() + Environment::NewLine + Button);

		if (Control->GetType()->ToString() == Button)
		{
			reinterpret_cast<Windows::Forms::Button^>(Control)->FlatStyle = FlatStyle::Flat;
			reinterpret_cast<Windows::Forms::Button^>(Control)->FlatAppearance->BorderSize = 0;
		}

		if (Control->GetType()->ToString() == TextBox)
		{
			reinterpret_cast<Windows::Forms::TextBox^>(Control)->BorderStyle = BorderStyle::None;
		}

		if (Control->GetType()->ToString() == ListBox)
		{
			reinterpret_cast<Windows::Forms::ListBox^>(Control)->BorderStyle = BorderStyle::None;
		}

		if (Control->GetType()->ToString() == Panel)
		{
			reinterpret_cast<Windows::Forms::Panel^>(Control)->BorderStyle = BorderStyle::None;
		}
	}
	void Border()
	{
		if (Control->GetType()->ToString() == Button)
		{
			reinterpret_cast<Windows::Forms::Button^>(Control)->FlatAppearance->BorderSize = 1;
		}

		if (Control->GetType()->ToString() == TextBox)
		{
			reinterpret_cast<Windows::Forms::TextBox^>(Control)->BorderStyle = BorderStyle::FixedSingle;
		}

		if (Control->GetType()->ToString() == ListBox)
		{
			reinterpret_cast<Windows::Forms::ListBox^>(Control)->BorderStyle = BorderStyle::FixedSingle;
		}

		if (Control->GetType()->ToString() == Panel)
		{
			reinterpret_cast<Windows::Forms::Panel^>(Control)->BorderStyle = BorderStyle::FixedSingle;
		}
	}

	void Remove(Windows::Forms::Control^ Window)
	{
		reinterpret_cast<Windows::Forms::Form^>(Window)->Controls->Remove(Control);
	}
	void Add(Windows::Forms::Control^ Object)
	{
		Control->Controls->Add(Object);
	}
};