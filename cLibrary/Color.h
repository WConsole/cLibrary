#pragma once
using namespace System;
using namespace System::Drawing;

namespace cLibrary 
{
	public ref class ColorRGB
	{
	public:
		ColorRGB(int R, int G, int B)
		{
			ColorRGB::R = R;
			ColorRGB::G = G;
			ColorRGB::B = B;

			ColorRGB::DotNetColor = Color::FromArgb(255, R, G, B);
		}

		Color^ DotNetColor;

		int R;
		int G;
		int B;
	};
	public ref class ColorARGB
	{
	public:
		ColorARGB(int A, int R, int G, int B)
		{
			ColorARGB::A = A;
			ColorARGB::R = R;
			ColorARGB::G = G;
			ColorARGB::B = B;
			
			ColorARGB::DotNetColor = Color::FromArgb(A, R, G, B);
		}

		Color^ DotNetColor;

		int A;
		int R;
		int G;
		int B;
	};

}
