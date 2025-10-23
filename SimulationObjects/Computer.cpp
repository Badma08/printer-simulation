#include "pch.h"
#include "Computer.h"

namespace SimulationObjects
{
	Computer::Computer(Internet^ internet, Timer^ timer) // ����������� � �����������
	{
		_internet = internet;
		_internet->DocumentSent += gcnew Internet::DocumentSentEventHandler(this, &Computer::SendDocumentToPrinter); // ���������� �������

		_timer = timer;
		_timer->Tick += gcnew System::EventHandler(this, &Computer::RequestDocument);
	}
	// ��������
	bool Computer::AdapterIsEnabled::get() { // ���������� ��������� ��������-��������
		return _internetAdapterIsEnabled;
	}

	void Computer::AdapterIsEnabled::set(bool value) { // ������������� ��������� ��������-��������
		_internetAdapterIsEnabled = value;
	}
	// ������
	void Computer::ChangeTimerInterval(int speed) // �������� �������� ������� � ����������� �� �������� ��������
	{
		_timer->Interval = 2000 / speed;
	}

	void Computer::RequestDocument(System::Object^ sender, System::EventArgs^ e) // ����������� �������� �� ��������, ���� ������� �������
	{
		if (_internetAdapterIsEnabled)
			_internet->RequestDocument();
	}

	void Computer::SendDocumentToPrinter(Document^ document) // ���������� �������� �� �������
	{
		if (document->IsColor())
			DocumentSentToInkjetPrinter(document);
		else
			DocumentSentToPrinter(document);
	}

	// ��������� 2 ������ ������������ � ������������� �� ������� ��������
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

	// ����������� �������
	void Computer::OnPaperTrayEmpty(Printer^ printer)
	{
		PaperTrayEmpty(printer);
	}

	void Computer::OnCartridgeEmpty(Printer^ printer, int index)
	{
		CartridgeEmpty(printer, index);
	}
}
