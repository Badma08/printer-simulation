#include "pch.h"
#include "Computer.h"

namespace SimulationObjects
{
	Computer::Computer(Internet^ internet, Timer^ timer) // Конструктор с параметрами
	{
		_internet = internet;
		_internet->DocumentSent += gcnew Internet::DocumentSentEventHandler(this, &Computer::SendDocumentToPrinter); // обработчик события

		_timer = timer;
		_timer->Tick += gcnew System::EventHandler(this, &Computer::RequestDocument);
	}
	// Свойства
	bool Computer::AdapterIsEnabled::get() { // Возвращает состояние интернет-адаптера
		return _internetAdapterIsEnabled;
	}

	void Computer::AdapterIsEnabled::set(bool value) { // устанавливает состояние интернет-адаптера
		_internetAdapterIsEnabled = value;
	}
	// Методы
	void Computer::ChangeTimerInterval(int speed) // Изменяет интервал таймера в зависимости от заданной скорости
	{
		_timer->Interval = 2000 / speed;
	}

	void Computer::RequestDocument(System::Object^ sender, System::EventArgs^ e) // запрашивает докумень чз интернет, если адаптер включен
	{
		if (_internetAdapterIsEnabled)
			_internet->RequestDocument();
	}

	void Computer::SendDocumentToPrinter(Document^ document) // отправляет докумень на принтер
	{
		if (document->IsColor())
			DocumentSentToInkjetPrinter(document);
		else
			DocumentSentToPrinter(document);
	}

	// Слудеющие 2 метода отписываются и подписываются от событий принтера
	void Computer::SubscribeToEvents(Printer^ printer) 
	{
		printer->PaperTrayEmpty += gcnew Printer::PaperTrayEmptyEventHandler(this, &Computer::OnPaperTrayEmpty);
		printer->CartridgeEmpty += gcnew Printer::CartridgeEmptyEventHandler(this, &Computer::OnCartridgeEmpty);
	}

	void Computer::UnsubscribeFromEvents(Printer^ printer)
	{
		printer->PaperTrayEmpty -= gcnew Printer::PaperTrayEmptyEventHandler(this, &Computer::OnPaperTrayEmpty);
		printer->CartridgeEmpty -= gcnew Printer::CartridgeEmptyEventHandler(this, &Computer::OnCartridgeEmpty);
	}

	// обработчики событий
	void Computer::OnPaperTrayEmpty(Printer^ printer)
	{
		PaperTrayEmpty(printer);
	}

	void Computer::OnCartridgeEmpty(Printer^ printer, int index)
	{
		CartridgeEmpty(printer, index);
	}
}
