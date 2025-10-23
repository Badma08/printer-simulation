#include "DelayedImageChanger.h"

namespace Simulation
{
	DelayedImageChanger::DelayedImageChanger(PictureBox^ pictureBox) // конструктор с параметрами
	{
		_pictureBox = pictureBox;
		
		_timer = gcnew Timer();
		// событие
		_timer->Tick += gcnew System::EventHandler(this, &DelayedImageChanger::OnTick);
	}

	void DelayedImageChanger::OnTick(System::Object^ sender, System::EventArgs^ e)
	{
		_timer->Stop();
		_pictureBox->ImageLocation = _imagePath;
	}

	void DelayedImageChanger::Change(System::String^ imagePath, int delay) // используется для изменения изображения
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
