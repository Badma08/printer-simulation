#include "pch.h"
#include "InkjetPrinter.h"

namespace SimulationObjects 
{
	InkjetPrinter::InkjetPrinter(Computer^ computer) // ����������� � �����������
	{
		_cartridgeCapacity = 15;
		_cartridgeFillLevels = gcnew array<int>{ 15, 15, 15, 15 };
		_cartridgeColors = gcnew array<System::String^>{ "Cyan", "Magenta", "Yellow", "Black" };

		_paperTrayCapacity = 50;
		_paperTrayCount = 50;
		// �������� �� ������� `DocumentSentToInkjetPrinter`, ������� �������� ����� `Print`, ����� �������� ������������ �� �������.
		computer->DocumentSentToInkjetPrinter += gcnew Computer::DocumentSentToInkjetPrinterEventHandler(this, &InkjetPrinter::Print);
	}

	void InkjetPrinter::Print(Document^ document)
	{
		int pageCount = document->PageCount;

		System::Random^ random = gcnew System::Random();

		for (int i = 0; i < pageCount; i++)
		{
			Printing(this); // ����� �������

			PaperTrayCount--;

			if (_paperTrayCount <= 0)
				PaperTrayEmpty(this); // ����� �������

			System::String^ color = document->GetPageColor(i);
			// ���������� ����������
			int index = 0;
			for each (System::String^ cardridgeColor in _cartridgeColors)
			{
				if (cardridgeColor == color)
				{
					_cartridgeFillLevels[index]--;

					if (_cartridgeFillLevels[index] <= 0)
						CartridgeEmpty(this, index); // ����� �������

					break;
				}
				index++;
			}
		}
		StopPrinting(this); // ����� �������
	}

	int InkjetPrinter::GetCartridgeFillLevel(int index) // ���������� ������� ���������� ��������� �� ��������� �������
	{
		return _cartridgeFillLevels[index];
	}

	void InkjetPrinter::FillCartridge(int index) // ��������� �������� �� ������������� ������
	{
		_cartridgeFillLevels[index] = _cartridgeCapacity;
	}
}
