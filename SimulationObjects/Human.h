#pragma once
#include "Computer.h"

namespace SimulationObjects {
	public ref class Human
	{
	private:
		Computer^ _computer;

	public:
		// конструктор с параметром
		Human(Computer^ computer);
		// методы
		void RefillCartridge(Printer^ printer, int index); // уведомляет о том, что картридж был перезаполнен

		void RefillPaperTray(Printer^ printer); // уведомляет о том, что лоток для бумаги был перезаполнен

		// делегаты и события
		delegate void CartridgeRefilledEventHandler(int index);
		event CartridgeRefilledEventHandler^ CartridgeRefilled;

		delegate void PaperTrayRefilledEventHandler(Printer^ printer);
		event PaperTrayRefilledEventHandler^ PaperTrayRefilled;
	};
}
