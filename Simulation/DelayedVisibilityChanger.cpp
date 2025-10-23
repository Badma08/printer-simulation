#include "DelayedVisibilityChanger.h"
// класс `DelayedVisibilityChanger` позволяет изменять видимость элемента управления с заданной задержкой
namespace Simulation
{
	DelayedVisibilityChanger::DelayedVisibilityChanger(Control^ control) // конструктор с параметрами
	{
		_control = control;
		_timer = gcnew Timer();
		// подписание на событие
		_timer->Tick += gcnew System::EventHandler(this, &DelayedVisibilityChanger::OnTick);
	}
	// методы
	void DelayedVisibilityChanger::OnTick(System::Object^ sender, System::EventArgs^ e)
	{
		_timer->Stop();
		_control->Visible = (!_visibility); // Меняем видимость элемента управления на противоположную
	}

	void DelayedVisibilityChanger::Change(bool visibility, int delay)
	{
		if (_timer->Enabled)
			_timer->Stop();

		_control->Visible = visibility;

		if (delay != 0)
		{
			_visibility = visibility;
			_timer->Interval = delay;
			_timer->Start();
		}
	}
}
