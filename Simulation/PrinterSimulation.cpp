#include "PrinterSimulation.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Simulation::PrinterSimulation form;
	Application::Run(% form);
}
