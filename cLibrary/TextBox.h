#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace cLibrary
{
	public ref class TextBox : Standarts
	{
		static void TextChange(Object^ sender, EventArgs^ e)
		{
			TextBox::Text = reinterpret_cast<Windows::Forms::TextBox^>(sender)->Text;
		}

	public:
		TextBox(cLibrary::Vector2D^ Size, cLibrary::Vector2D^ Location, cLibrary::Window^ Window)
		{
			Windows::Forms::TextBox^ tb = gcnew Windows::Forms::TextBox();
			tb->Size = Drawing::Size(Size->X, Size->Y);
			tb->Location = Drawing::Point(Location->X, Location->Y);
			tb->TextChanged += gcnew EventHandler(TextChange);

			Window->Add(tb);

			TextBox::Control = tb;
		}

		void KeyDown(void Callback(Object^ sender, KeyEventArgs^ e))
		{
			reinterpret_cast<Windows::Forms::TextBox^>(TextBox::Control)->KeyDown += gcnew KeyEventHandler(Callback);
		}
	};
}
