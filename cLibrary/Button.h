#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace cLibrary 
{
	public ref class Button : Standarts
	{
	public:
		Button(String^ Text, cLibrary::Vector2D^ Size, cLibrary::Vector2D^ Location, cLibrary::Window^ Window)
		{
			Windows::Forms::Button^ btn = gcnew Windows::Forms::Button();
			btn->Text = Text;
			btn->Size = Drawing::Size(Size->X, Size->Y);
			btn->Location = Drawing::Point(Location->X, Location->Y);

			Button::Control = btn;
			Button::Location = Location;
			Button::Size = Size;

			Window->Add(btn);
		}	

		void Click(void Callback(Object^ sender, EventArgs^ e))
		{
			Control->Click += gcnew EventHandler(Callback);
		}
	};
}