#include "DelayedImageChanger.h"

namespace Simulation
{
	DelayedImageChanger::DelayedImageChanger(PictureBox^ pictureBox) // ����������� � �����������
	{
		_pictureBox = pictureBox;
		
		_timer = gcnew Timer();
		// �������
		_timer->Tick += gcnew System::EventHandler(this, &DelayedImageChanger::OnTick);
	}

	void DelayedImageChanger::OnTick(System::Object^ sender, System::EventArgs^ e)
	{
		_timer->Stop();
		_pictureBox->ImageLocation = _imagePath;
	}

	void DelayedImageChanger::Change(System::String^ imagePath, int delay) // ������������ ��� ��������� �����������
	{
		if (_timer->Enabled)
			_timer->Stop();

		if (delay == 0)
			_pictureBox->ImageLocation = imagePath;
		else
		{
			_imagePath = imagePath;
			_timer->Interval = delay;
			_timer->Start();
		}
	}
}
