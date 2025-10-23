#include "pch.h"
#include "Human.h"

namespace SimulationObjects
{
	Human::Human(Computer^ computer) // ����������� ������ � �����������
	{
		_computer = computer;
		// ����������� �������
		_computer->CartridgeEmpty += gcnew Computer::CartridgeEmptyEventHandler(this, &Human::RefillCartridge);
		_computer->PaperTrayEmpty += gcnew Computer::PaperTrayEmptyEventHandler(this, &Human::RefillPaperTray);
	}
	// ������ �����������
	void Human::RefillCartridge(Printer^ printer, int index) // ���������� � ���, ��� �������� ��� ������������
	{
		printer->FillCartridge(index);

		CartridgeRefilled(index);
	}

	void Human::RefillPaperTray(Printer^ printer) // ���������� � ���, ��� ����� ��� ������������
	{
		printer->PaperTrayCount = printer->PaperTrayCapacity;

		PaperTrayRefilled(printer);
	}
}
