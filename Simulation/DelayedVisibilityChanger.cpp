#include "DelayedVisibilityChanger.h"
// ����� `DelayedVisibilityChanger` ��������� �������� ��������� �������� ���������� � �������� ���������
namespace Simulation
{
	DelayedVisibilityChanger::DelayedVisibilityChanger(Control^ control) // ����������� � �����������
	{
		_control = control;
		_timer = gcnew Timer();
		// ���������� �� �������
		_timer->Tick += gcnew System::EventHandler(this, &DelayedVisibilityChanger::OnTick);
	}
	// ������
	void DelayedVisibilityChanger::OnTick(System::Object^ sender, System::EventArgs^ e)
	{
		_timer->Stop();
		_control->Visible = (!_visibility); // ������ ��������� �������� ���������� �� ���������������
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
