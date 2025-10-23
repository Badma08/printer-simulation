#include "pch.h"
#include "InkjetPrinter.h"

namespace SimulationObjects 
{
	InkjetPrinter::InkjetPrinter(Computer^ computer) // конструктор с параметрами
	{
		_cartridgeCapacity = 15;
		_cartridgeFillLevels = gcnew array<int>{ 15, 15, 15, 15 };
		_cartridgeColors = gcnew array<System::String^>{ "Cyan", "Magenta", "Yellow", "Black" };

		_paperTrayCapacity = 50;
		_paperTrayCount = 50;
		// Подписка на событие `DocumentSentToInkjetPrinter`, которое вызывает метод `Print`, когда документ отправляется на принтер.
		computer->DocumentSentToInkjetPrinter += gcnew Computer::DocumentSentToInkjetPrinterEventHandler(this, &InkjetPrinter::Print);
	}

	void InkjetPrinter::Print(Document^ document)
	{
		int pageCount = document->PageCount;

		System::Random^ random = gcnew System::Random();

		for (int i = 0; i < pageCount; i++)
		{
			Printing(this); // вызов события

			PaperTrayCount--;

			if (_paperTrayCount <= 0)
				PaperTrayEmpty(this); // вызов события

			System::String^ color = document->GetPageColor(i);
			// заполнение картриджей
			int index = 0;
			for each (System::String^ cardridgeColor in _cartridgeColors)
			{
				if (cardridgeColor == color)
				{
					_cartridgeFillLevels[index]--;

					if (_cartridgeFillLevels[index] <= 0)
						CartridgeEmpty(this, index); // вызов события

					break;
				}
				index++;
			}
		}
		StopPrinting(this); // вызов события
	}

	int InkjetPrinter::GetCartridgeFillLevel(int index) // возвращает уровень заполнения картриджа по заданному индексу
	{
		return _cartridgeFillLevels[index];
	}

	void InkjetPrinter::FillCartridge(int index) // заполняет картридж до максимального уровня
	{
		_cartridgeFillLevels[index] = _cartridgeCapacity;
	}
}
