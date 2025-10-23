#include "pch.h"
#include "Printer.h"

namespace SimulationObjects
{
	Printer::Printer() {} // Конструктор

	Printer::Printer(Computer^ computer) // Конструктор с параметром
	{
		_cartridgeCapacity = 50; // Емкость картриджа
		_cartridgeFillLevel = 50; // Текущий уровень чернил в картридже

		_paperTrayCapacity = 70; // Вместимость лотка для бумаги
		_paperTrayCount = 70; // Текущее кол-во бумаги

		computer->DocumentSentToPrinter += gcnew Computer::DocumentSentToPrinterEventHandler(this, &Printer::Print); // Получение документов для печати
	}

	int Printer::CartridgeCapacity::get() // Возвращает емкость картриджа
	{
		return _cartridgeCapacity;
	}

	int Printer::PaperTrayCapacity::get() // Возвращает вместимость лотка для бумаги
	{
		return _paperTrayCapacity;
	}

	int Printer::PaperTrayCount::get() // Возвращает текущее кол-во бумаги в лотке
	{
		return _paperTrayCount;
	}

	void Printer::PaperTrayCount::set(int value) // Устанавливает текущее кол-во бумаги в лотке
	{
		_paperTrayCount = value;
	}

	void Printer::Print(Document^ document)
	{
		int pageCount = document->PageCount;

		System::Random^ random = gcnew System::Random();

		for (int i = 0; i < pageCount; i++)
		{
			Printing(this); // Вызов события

			PaperTrayCount--;

			if (_paperTrayCount <= 0)
				PaperTrayEmpty(this); // Вызов события

			_cartridgeFillLevel--;

			if (_cartridgeFillLevel <= 0)
				CartridgeEmpty(this, -1); // Вызов события
		}
		StopPrinting(this); // Вызов события
	}

	int Printer::GetCartridgeFillLevel(int index) // Возвращает тукцщий уровень чернил
	{
		return _cartridgeFillLevel;
	}

	void Printer::FillCartridge(int index) // Заправляет картридж до полной емкости
	{
		_cartridgeFillLevel = _cartridgeCapacity;
	}
}
