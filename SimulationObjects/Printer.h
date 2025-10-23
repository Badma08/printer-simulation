#pragma once
#include "Document.h"
#include "Computer.h"

namespace SimulationObjects 
{
	ref class Document;
	ref class Computer;

	public ref class Printer 
	{
	protected: // Поля класса
		int _cartridgeFillLevel;

	protected: 
		Printer();

		int _cartridgeCapacity;
		int _paperTrayCapacity;
		int _paperTrayCount;

	public:
		// Свойства
		Printer(Computer^ computer);

		property int PaperTrayCount // текущее кол-во бумаги 
		{
			int get();
			void set(int value);
		}

		property int PaperTrayCapacity // вместимость бумаги
		{
			int get();
		}

		property int CartridgeCapacity // вместимость картриджа
		{
			int get();
		}
		// Методы
		virtual void Print(Document^ document); // печать

		virtual int GetCartridgeFillLevel(int index); // Возвращает тукцщий уровень чернил

		virtual void FillCartridge(int index); // Заправляет картридж до полной емкости
		// Делагаты и события
		delegate void PrintingEventHandler(Printer^ printer);
		event PrintingEventHandler^ Printing;

		delegate void StopPrintingEventHandler(Printer^ printer);
		event StopPrintingEventHandler^ StopPrinting;

		delegate void CartridgeEmptyEventHandler(Printer^ printer, int index);
		event CartridgeEmptyEventHandler^ CartridgeEmpty;

		delegate void PaperTrayEmptyEventHandler(Printer^ printer);
		event PaperTrayEmptyEventHandler^ PaperTrayEmpty;
	};
}
