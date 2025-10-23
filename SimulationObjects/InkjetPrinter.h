#pragma once
#include "Printer.h"
#include "Computer.h"

namespace SimulationObjects 
{
	public ref class InkjetPrinter : Printer
	{
	protected:
		// ����
		array<int>^ _cartridgeFillLevels;
		array<System::String^>^ _cartridgeColors;

	public:
		InkjetPrinter(Computer^ computer); // ����������� � �����������
		// ������
		void Print(Document^ document) override; // �������������� ����������� ����� �� �������� ������ `Printer`

		int GetCartridgeFillLevel(int index) override; // ���������� ������� ���������� ��������� �� ���������� �������

		void FillCartridge(int index) override; // ��������� �������� �� ���������� �������.
	};
}
