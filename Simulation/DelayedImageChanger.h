#pragma once
using namespace System::Windows::Forms;

namespace Simulation
{
	public ref class DelayedImageChanger
	{
	private:
		// ���� ������
		PictureBox^ _pictureBox;
		System::String^ _imagePath;
		Timer^ _timer;
		// ������
		void OnTick(System::Object^ sender, System::EventArgs^ e);

	public:
		DelayedImageChanger(PictureBox^ pictureBox); // ����������� ������

		void Change(System::String^ imagePath, int delay); // ������������ ��� ��������� ����������� � `PictureBox`
	};
}
