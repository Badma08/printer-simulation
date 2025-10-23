#pragma once
#include "Document.h"

namespace SimulationObjects 
{
	public ref class Internet
	{
	private: // поля
		System::Windows::Forms::Timer^ _requestDocumentTimer;
		System::Windows::Forms::Timer^ _generateDocumentTimer;
		int _requestDocumentDelay;
		int _generateDocumentDelay;

	private:
		System::Collections::Generic::Queue<Document^>^ _documents = gcnew System::Collections::Generic::Queue<Document^>();
		// методы
		void GenerateDocument(Object^ sender, System::EventArgs^ e);
		void TrySendDocument(Object^ sender, System::EventArgs^ e);

	public:
		Internet(int requestDocumentDelay, int generateDocumentDelay); // конструктор
		// методы
		void StartGenerating();
		void StopGenerating();
		void RequestDocument();
		void ChangeTimerInterval(int speed);
		int GetCurrentDocumentCount();
		// делегаты и события
		delegate void DocumentSentEventHandler(Document^ document);
		event DocumentSentEventHandler^ DocumentSent;
	};
}
