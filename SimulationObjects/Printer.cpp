#include "pch.h"
#include "Printer.h"

namespace SimulationObjects
{
	Printer::Printer() {} // �����������

	Printer::Printer(Computer^ computer) // ����������� � ����������
	{
		_cartridgeCapacity = 50; // ������� ���������
		_cartridgeFillLevel = 50; // ������� ������� ������ � ���������

		_paperTrayCapacity = 70; // ����������� ����� ��� ������
		_paperTrayCount = 70; // ������� ���-�� ������

		computer->DocumentSentToPrinter += gcnew Computer::DocumentSentToPrinterEventHandler(this, &Printer::Print); // ��������� ���������� ��� ������
	}

	int Printer::CartridgeCapacity::get() // ���������� ������� ���������
	{
		return _cartridgeCapacity;
	}

	int Printer::PaperTrayCapacity::get() // ���������� ����������� ����� ��� ������
	{
		return _paperTrayCapacity;
	}

	int Printer::PaperTrayCount::get() // ���������� ������� ���-�� ������ � �����
	{
		return _paperTrayCount;
	}

	void Printer::PaperTrayCount::set(int value) // ������������� ������� ���-�� ������ � �����
	{
		_paperTrayCount = value;
	}

	void Printer::Print(Document^ document)
	{
		int pageCount = document->PageCount;

		System::Random^ random = gcnew System::Random();

		for (int i = 0; i < pageCount; i++)
		{
			Printing(this); // ����� �������

			PaperTrayCount--;

			if (_paperTrayCount <= 0)
				PaperTrayEmpty(this); // ����� �������

			_cartridgeFillLevel--;

			if (_cartridgeFillLevel <= 0)
				CartridgeEmpty(this, -1); // ����� �������
		}
		StopPrinting(this); // ����� �������
	}

	int Printer::GetCartridgeFillLevel(int index) // ���������� ������� ������� ������
	{
		return _cartridgeFillLevel;
	}

	void Printer::FillCartridge(int index) // ���������� �������� �� ������ �������
	{
		_cartridgeFillLevel = _cartridgeCapacity;
	}
}
