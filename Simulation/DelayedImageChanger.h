#pragma once
using namespace System::Windows::Forms;

namespace Simulation
{
	public ref class DelayedImageChanger
	{
	private:
		// поля класса
		PictureBox^ _pictureBox;
		System::String^ _imagePath;
		Timer^ _timer;
		// методы
		void OnTick(System::Object^ sender, System::EventArgs^ e);

	public:
		DelayedImageChanger(PictureBox^ pictureBox); // конструктор класса

		void Change(System::String^ imagePath, int delay); // используется для изменения изображения в `PictureBox`
	};
}
