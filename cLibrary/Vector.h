#pragma once

using namespace System;

namespace cLibrary {
	public ref class Vector2D
	{
	public:
		Vector2D(int X, int Y)
		{
			Vector2D::X = X;
			Vector2D::Y = Y;
		}

		int X;
		int Y;
	};
}