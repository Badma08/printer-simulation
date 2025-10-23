#pragma once
#include "Computer.h"

namespace SimulationObjects {
	public ref class Human
	{
	private:
		Computer^ _computer;

	public:
		// ����������� � ����������
		Human(Computer^ computer);
		// ������
		void RefillCartridge(Printer^ printer, int index); // ���������� � ���, ��� �������� ��� ������������

		void RefillPaperTray(Printer^ printer); // ���������� � ���, ��� ����� ��� ������ ��� ������������

		// �������� � �������
		delegate void CartridgeRefilledEventHandler(int index);
		event CartridgeRefilledEventHandler^ CartridgeRefilled;

		delegate void PaperTrayRefilledEventHandler(Printer^ printer);
		event PaperTrayRefilledEventHandler^ PaperTrayRefilled;
	};
}
