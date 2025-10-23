#include "pch.h"
#include "Human.h"

namespace SimulationObjects
{
	Human::Human(Computer^ computer) // конструктор класса с параметрами
	{
		_computer = computer;
		// обработчики событий
		_computer->CartridgeEmpty += gcnew Computer::CartridgeEmptyEventHandler(this, &Human::RefillCartridge);
		_computer->PaperTrayEmpty += gcnew Computer::PaperTrayEmptyEventHandler(this, &Human::RefillPaperTray);
	}
	// методы обработчики
	void Human::RefillCartridge(Printer^ printer, int index) // уведомляет о том, что картридж был перезаполнен
	{
		printer->FillCartridge(index);

		CartridgeRefilled(index);
	}

	void Human::RefillPaperTray(Printer^ printer) // уведомляет о том, что лоток был перезаполнен
	{
		printer->PaperTrayCount = printer->PaperTrayCapacity;

		PaperTrayRefilled(printer);
	}
}
