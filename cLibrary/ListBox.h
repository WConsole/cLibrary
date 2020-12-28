#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace cLibrary
{
	public ref class ListBox : Standarts
	{
	public:

		ListBox(cLibrary::Vector2D^ Size, cLibrary::Vector2D^ Location, cLibrary::Window^ Window)
		{
			Windows::Forms::ListBox^ lb = gcnew Windows::Forms::ListBox();
			lb->Location = Drawing::Point(Location->X, Location->Y);
			lb->Size = Drawing::Size(Size->X, Size->Y);

			ListBox::Control = lb;
			ListBox::Location = Location;
			ListBox::Size = Size;


			Window->Add(lb);
		}

		void ItemAdd(String^ Item)
		{
			reinterpret_cast<Windows::Forms::ListBox^>(Control)->Items->Add(Item);
		}
		void Clear()
		{
			reinterpret_cast<Windows::Forms::ListBox^>(Control)->Items->Clear();
		}

		void DeleteItem(String^ Item)
		{
			Windows::Forms::ListBox^ lb = reinterpret_cast<Windows::Forms::ListBox^>(Control);

			array<String^>^ ListBoxInhalt = gcnew array<String^>(lb->Items->Count);
			bool found = false;

			for (int i = 0; i < lb->Items->Count; i++)
			{
				if (lb->Items[i] != Item)
				{
					if (found)
					{
						ListBoxInhalt[i - 1] = lb->Items[i]->ToString();
					}
					else
					{
						ListBoxInhalt[i] = lb->Items[i]->ToString();
					}
				}
				else
				{
					found = true;
				}
			}

			lb->Items->Clear();
			for (int i = 0; i < ListBoxInhalt->Length; i++)
			{
				if (ListBoxInhalt[i] != nullptr)
					lb->Items->Add(ListBoxInhalt[i]);
			}

		}
		void DeleteItem(int Index)
		{
			Windows::Forms::ListBox^ lb = reinterpret_cast<Windows::Forms::ListBox^>(Control);
			bool found;
			array<String^>^ ListBoxInhalt = gcnew array<String^>(lb->Items->Count);

			for (int i = 0; i < lb->Items->Count; i++)
			{
				if (i != Index)
				{
					if (found)
					{
						ListBoxInhalt[i - 1] = lb->Items[i]->ToString();
					}
					else
					{
						ListBoxInhalt[i] = lb->Items[i]->ToString();
					}
				}
				else
				{
					found = true;
				}
			}
		}

	};
}

