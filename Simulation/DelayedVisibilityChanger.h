#pragma once
using namespace System::Windows::Forms;

namespace Simulation
{
	public ref class DelayedVisibilityChanger
	{
	private:
		// ���� ������
		Control^ _control;
		Timer^ _timer;
		bool _visibility;
		// �����
		void OnTick(System::Object^ sender, System::EventArgs^ e);

	public:
		DelayedVisibilityChanger(Control^ control); // ����������� � �����������

		void Change(bool visibility, int delay);
	};
}
