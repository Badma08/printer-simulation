#pragma once

namespace SimulationObjects
{
	public ref class Document
	{
	private: // поля
		int _pageCount;
		array<System::String^>^ _colors;

	public:
		// конструкторы
		Document(int pageCount);
		Document(int pageCount, array<System::String^>^ colors);
		// свойства
		property int PageCount {
			int get();
			void set(int value);
		}
		// мметоды
		bool IsColor();
		System::String^ GetPageColor(int pageIndex);
	};
}
