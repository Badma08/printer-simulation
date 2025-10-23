#pragma once
using namespace System::Windows::Forms;

namespace Simulation
{
	public ref class DelayedVisibilityChanger
	{
	private:
		// поля класса
		Control^ _control;
		Timer^ _timer;
		bool _visibility;
		// метод
		void OnTick(System::Object^ sender, System::EventArgs^ e);

	public:
		DelayedVisibilityChanger(Control^ control); // конструктор с параметрами

		void Change(bool visibility, int delay);
	};
}
