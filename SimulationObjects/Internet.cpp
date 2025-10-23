#include "pch.h"
#include "Internet.h"
#include "Document.h"
using namespace System;

namespace SimulationObjects
{
	Internet::Internet(int requestDocumentDelay, int generateDocumentDelay)
	{
		_requestDocumentDelay = requestDocumentDelay; // �������� � ��, � ������� ���������� ������ ���������
		_requestDocumentTimer = gcnew System::Windows::Forms::Timer(); 
		_requestDocumentTimer->Interval = requestDocumentDelay;
		_requestDocumentTimer->Start();

		_generateDocumentDelay = generateDocumentDelay;// ��������� � ��, � ������� ������������ ����� ��������
		_generateDocumentTimer = gcnew System::Windows::Forms::Timer();
		_generateDocumentTimer->Interval = generateDocumentDelay;
		_generateDocumentTimer->Tick += gcnew EventHandler(this, &Internet::GenerateDocument);
	}

	void Internet::GenerateDocument(Object^ sender, System::EventArgs^ e) // �������� �� �������� ������ ���������
	{
		Document^ document;

		Random^ random = gcnew Random();
		int pageCount = random->Next(3, 11);

		if (random->Next(3) == 2)
		{
			array<String^>^ colors = gcnew array<String^>(pageCount);

			for (int i = 0; i < pageCount; i++)
			{
				int colorIndex = random->Next(4);

				if (colorIndex == 0)
					colors[i] = "Cyan";

				else if (colorIndex == 1)
					colors[i] = "Magenta";

				else if (colorIndex == 2)
					colors[i] = "Yellow";

				else
					colors[i] = "Black";
			}
			document = gcnew Document(pageCount, colors);
		}
		else
		{
			document = gcnew Document(pageCount);
		}
		_documents->Enqueue(document);
	}

	void Internet::TrySendDocument(Object^ sender, System::EventArgs^ e) //����� ���������, ���� �� ��������� � �������, � ���� ��� ����, ���������� ������ �������� �� �������.
	{
		_requestDocumentTimer->Tick -= gcnew EventHandler(this, &Internet::TrySendDocument);

		if (_documents->Count > 0)
			DocumentSent(_documents->Dequeue());
	}

	void Internet::StartGenerating() // ��������� ������, ���������� �� ��������� ����������.
	{
		_generateDocumentTimer->Start();
	}

	void Internet::StopGenerating() // ������������� ������ ��������� ����������
	{
		_generateDocumentTimer->Stop();
	}

	void Internet::RequestDocument() // ������������� ���������� ������� ������� _requestDocumentTimer, ����� ������ ������� �������� ��������� ��� ��������� ���� �������.
	{
		_requestDocumentTimer->Tick += gcnew EventHandler(this, &Internet::TrySendDocument);
	}

	void Internet::ChangeTimerInterval(int speed) // ������ ��������� ��������, �������� �� � ����������� �� ����������� ������������ speed.
	{
		_requestDocumentTimer->Interval = _requestDocumentDelay / speed;
		_generateDocumentTimer->Interval = _generateDocumentDelay / speed;
	}

	int Internet::GetCurrentDocumentCount() // ���������� ������� ���������� ���������� � �������
	{
		return _documents->Count;
	}
}
