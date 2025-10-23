#include "pch.h"
#include "Internet.h"
#include "Document.h"
using namespace System;

namespace SimulationObjects
{
	Internet::Internet(int requestDocumentDelay, int generateDocumentDelay)
	{
		_requestDocumentDelay = requestDocumentDelay; // задержка в мс, с которой происходит запрос документа
		_requestDocumentTimer = gcnew System::Windows::Forms::Timer(); 
		_requestDocumentTimer->Interval = requestDocumentDelay;
		_requestDocumentTimer->Start();

		_generateDocumentDelay = generateDocumentDelay;// задержкка в мс, с которой генерируется новый жокумент
		_generateDocumentTimer = gcnew System::Windows::Forms::Timer();
		_generateDocumentTimer->Interval = generateDocumentDelay;
		_generateDocumentTimer->Tick += gcnew EventHandler(this, &Internet::GenerateDocument);
	}

	void Internet::GenerateDocument(Object^ sender, System::EventArgs^ e) // отвечает за создание нового документа
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

	void Internet::TrySendDocument(Object^ sender, System::EventArgs^ e) //Метод проверяет, есть ли документы в очереди, и если они есть, отправляет первый документ из очереди.
	{
		_requestDocumentTimer->Tick -= gcnew EventHandler(this, &Internet::TrySendDocument);

		if (_documents->Count > 0)
			DocumentSent(_documents->Dequeue());
	}

	void Internet::StartGenerating() // Запускает таймер, отвечающий за генерацию документов.
	{
		_generateDocumentTimer->Start();
	}

	void Internet::StopGenerating() // Останавливает таймер генерации документов
	{
		_generateDocumentTimer->Stop();
	}

	void Internet::RequestDocument() // Устанавливает обработчик события таймера _requestDocumentTimer, чтобы начать попытку отправки документа при следующем тике таймера.
	{
		_requestDocumentTimer->Tick += gcnew EventHandler(this, &Internet::TrySendDocument);
	}

	void Internet::ChangeTimerInterval(int speed) // Меняет интервалы таймеров, уменьшая их в зависимости от переданного коэффициента speed.
	{
		_requestDocumentTimer->Interval = _requestDocumentDelay / speed;
		_generateDocumentTimer->Interval = _generateDocumentDelay / speed;
	}

	int Internet::GetCurrentDocumentCount() // Возвращает текущее количество документов в очереди
	{
		return _documents->Count;
	}
}
