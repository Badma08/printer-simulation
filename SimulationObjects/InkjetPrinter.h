#pragma once
#include "Printer.h"
#include "Computer.h"

namespace SimulationObjects 
{
	public ref class InkjetPrinter : Printer
	{
	protected:
		// Поля
		array<int>^ _cartridgeFillLevels;
		array<System::String^>^ _cartridgeColors;

	public:
		InkjetPrinter(Computer^ computer); // конструктор с параметрами
		// методы
		void Print(Document^ document) override; // переопределяет виртуальный метод из базового класса `Printer`

		int GetCartridgeFillLevel(int index) override; // возвращает уровень заполнения картриджа по указанному индексу

		void FillCartridge(int index) override; // заполняет картридж по указанному индексу.
	};
}
