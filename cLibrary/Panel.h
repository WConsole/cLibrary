#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace cLibrary
{
	public ref class Panel : Standarts
	{
	public:

		Panel(cLibrary::Vector2D^ Size, cLibrary::Vector2D^ Location, cLibrary::Window^ Window)
		{
			Windows::Forms::Panel^ p = gcnew Windows::Forms::Panel();
			p->Location = Drawing::Point(Location->X, Location->Y);
			p->Size = Drawing::Size(Size->X, Size->Y);

			Panel::Control = p;
			Panel::Location = Location;
			Panel::Size = Size;


			Window->Add(p);
		}
	};
}

