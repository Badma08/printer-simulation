#pragma once
#include "Document.h"
#include "Computer.h"

namespace SimulationObjects 
{
	ref class Document;
	ref class Computer;

	public ref class Printer 
	{
	protected: // ���� ������
		int _cartridgeFillLevel;

	protected: 
		Printer();

		int _cartridgeCapacity;
		int _paperTrayCapacity;
		int _paperTrayCount;

	public:
		// ��������
		Printer(Computer^ computer);

		property int PaperTrayCount // ������� ���-�� ������ 
		{
			int get();
			void set(int value);
		}

		property int PaperTrayCapacity // ����������� ������
		{
			int get();
		}

		property int CartridgeCapacity // ����������� ���������
		{
			int get();
		}
		// ������
		virtual void Print(Document^ document); // ������

		virtual int GetCartridgeFillLevel(int index); // ���������� ������� ������� ������

		virtual void FillCartridge(int index); // ���������� �������� �� ������ �������
		// �������� � �������
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
