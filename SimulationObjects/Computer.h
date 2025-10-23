#pragma once
#include "Document.h"
#include "Internet.h"
#include "Printer.h"
using namespace System::Windows::Forms;

namespace SimulationObjects 
{
	ref class Printer;

	public ref class Computer
	{
		// поля класса
	private:
		Timer^ _timer;
		Internet^ _internet;
		bool _internetAdapterIsEnabled;

	public:
		Computer(Internet^ internet, Timer^ timer); // конструктор
		//Свойство
		property bool AdapterIsEnabled 
		{
			bool get();
			void set(bool value);
		}
		// Методы
		void RequestDocument(System::Object^ sender, System::EventArgs^ e);
		void ChangeTimerInterval(int speed);

		void SendDocumentToPrinter(Document^ document);
		void SubscribeToEvents(Printer^ printer);
		void UnsubscribeFromEvents(Printer^ printer);
		void OnPaperTrayEmpty(Printer^ printer);
		void OnCartridgeEmpty(Printer^ printer, int index);
		//// Делегаты и события
		//delegate void DocumentRequestedEventHandler();
		//event DocumentRequestedEventHandler^ DocumentRequested;

		delegate void DocumentSentToInkjetPrinterEventHandler(Document^ document);
		event DocumentSentToInkjetPrinterEventHandler^ DocumentSentToInkjetPrinter;

		delegate void DocumentSentToPrinterEventHandler(Document^ document);
		event DocumentSentToPrinterEventHandler^ DocumentSentToPrinter;
	
		delegate void CartridgeEmptyEventHandler(Printer^ printer, int index);
		event CartridgeEmptyEventHandler^ CartridgeEmpty;
		
		delegate void PaperTrayEmptyEventHandler(Printer^ printer);
		event PaperTrayEmptyEventHandler^ PaperTrayEmpty;
	};
}
