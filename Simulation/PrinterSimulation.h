#pragma once;
#include "DelayedImageChanger.h"
#include "DelayedVisibilityChanger.h"

namespace Simulation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SimulationObjects;

	/// <summary>
	/// Сводка для PrinterSimulation
	/// </summary>
	public ref class PrinterSimulation : public System::Windows::Forms::Form
	{
	private:
		Human^ _human;
		Internet^ _internet;
		Computer^ _computer;
		Printer^ _laserPrinter;
		InkjetPrinter^ _inkjetPrinter;
		DelayedImageChanger^ _dicLaserPrinter;
		DelayedImageChanger^ _dicInkjetPrinter;
		DelayedImageChanger^ _dicComputerOnAction;
		DelayedVisibilityChanger^ _dvcRefillLaserPaperTray;
		DelayedVisibilityChanger^ _dvcRefillCartridge;
		DelayedVisibilityChanger^ _dvcRefillInkjetPaperTray;
		DelayedVisibilityChanger^ _dvcRefillCyanCartridge;
		DelayedVisibilityChanger^ _dvcRefillMagentaCartridge;
		DelayedVisibilityChanger^ _dvcRefillYellowCartridge;
		DelayedVisibilityChanger^ _dvcRefillBlackCartridge;




	private: System::Windows::Forms::GroupBox^ internetAdapterIllustrationGroupBox;
	private: System::Windows::Forms::PictureBox^ pictureInternetAdapter;
	private: System::Windows::Forms::Button^ slow;
	private: System::Windows::Forms::Button^ fast;
	private: System::Windows::Forms::PictureBox^ pictureRefillInkjetPaperTray;
	private: System::Windows::Forms::PictureBox^ pictureRefillLaserPaperTray;





		   int _programSpeed;

	public:
		PrinterSimulation(void)
		{
			InitializeComponent();

			_programSpeed = 1;

			_dicComputerOnAction = gcnew DelayedImageChanger(pictureComputer);

			_dicLaserPrinter = gcnew DelayedImageChanger(pictureLaserPrinter);
			_dvcRefillLaserPaperTray = gcnew DelayedVisibilityChanger(pictureRefillLaserPaperTray);
			_dvcRefillCartridge = gcnew DelayedVisibilityChanger(pictureRefillCartridge);

			_dicInkjetPrinter = gcnew DelayedImageChanger(pictureInkjetPrinter);
			_dvcRefillInkjetPaperTray = gcnew DelayedVisibilityChanger(pictureRefillInkjetPaperTray);
			_dvcRefillCyanCartridge = gcnew DelayedVisibilityChanger(pictureRefillCyanCartridge);
			_dvcRefillMagentaCartridge = gcnew DelayedVisibilityChanger(pictureRefillMagentaCartridge);
			_dvcRefillYellowCartridge = gcnew DelayedVisibilityChanger(pictureRefillYellowCartridge);
			_dvcRefillBlackCartridge = gcnew DelayedVisibilityChanger(pictureRefillBlackCartridge);

			_internet = gcnew Internet(3000, 1800);
			_computer = gcnew Computer(_internet, computerTimer);
			_human = gcnew Human(_computer);

			_laserPrinter = gcnew Printer(_computer);

			_inkjetPrinter = gcnew InkjetPrinter(_computer);
		}




	private: System::Windows::Forms::PictureBox^ pictureInkjetPrinter;
	private: System::Windows::Forms::PictureBox^ pictureCyanCartridge;

	private: System::Windows::Forms::PictureBox^ pictureMagentaCartridge;
	private: System::Windows::Forms::PictureBox^ pictureYellowCartridge;
	private: System::Windows::Forms::PictureBox^ pictureBlackCartridge;
	private: System::Windows::Forms::PictureBox^ pictureRefillBlackCartridge;
	private: System::Windows::Forms::PictureBox^ pictureInkjetPaperTray;
	private: System::Windows::Forms::PictureBox^ pictureRefillYellowCartridge;
	private: System::Windows::Forms::PictureBox^ pictureRefillCyanCartridge;
	private: System::Windows::Forms::PictureBox^ pictureRefillMagentaCartridge;

	private: System::Windows::Forms::PictureBox^ pictureRefillCartridge;

	private: System::Windows::Forms::PictureBox^ pictureComputer;


	private: System::Windows::Forms::PictureBox^ pictureCartridge;
	private: System::Windows::Forms::PictureBox^ pictureLaserPaperTray;
	private: System::Windows::Forms::PictureBox^ pictureLaserPrinter;
	private: System::Windows::Forms::CheckBox^ generateDocumentSwitch;
	private: System::Windows::Forms::CheckBox^ TurnOnDevices;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ laserPaperCountLabel;
	private: System::Windows::Forms::Label^ cartridgeFillLevelLabel;
	private: System::Windows::Forms::Label^ inkjetPaperCountLabel;
	private: System::Windows::Forms::Label^ blackCartridgeFillLevelLabel;
	private: System::Windows::Forms::Label^ yellowCartridgeFillLevelLabel;
	private: System::Windows::Forms::Label^ magentaCartridgeFillLevelLabel;
	private: System::Windows::Forms::Label^ cyanCartridgeFillLevelLabel;
	private: System::Windows::Forms::Label^ documentCountLabel;
	private: System::Windows::Forms::GroupBox^ internetGroupBox;
	private: System::Windows::Forms::GroupBox^ laserPrinterIllustrationGroupBox;
	private: System::Windows::Forms::GroupBox^ inkjetPrinterIllustrationGroupBox;
	private: System::Windows::Forms::GroupBox^ computerIllustrationGroupBox;


	private: System::Windows::Forms::GroupBox^ controlPanelGroupBox;
	private: System::Windows::Forms::GroupBox^ laserPrinterGroupBox;
	private: System::Windows::Forms::GroupBox^ inkjetPrinterGroupBox;
	private: System::Windows::Forms::GroupBox^ simulationGroupBox;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Timer^ computerTimer;
	private: System::Windows::Forms::TrackBar^ simulationSpeedTrackBar;
	private: System::ComponentModel::IContainer^ components;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PrinterSimulation()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PrinterSimulation::typeid));
			this->TurnOnDevices = (gcnew System::Windows::Forms::CheckBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureComputer = (gcnew System::Windows::Forms::PictureBox());
			this->pictureLaserPrinter = (gcnew System::Windows::Forms::PictureBox());
			this->generateDocumentSwitch = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->computerTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->controlPanelGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->slow = (gcnew System::Windows::Forms::Button());
			this->fast = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->simulationSpeedTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->laserPrinterGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->laserPaperCountLabel = (gcnew System::Windows::Forms::Label());
			this->cartridgeFillLevelLabel = (gcnew System::Windows::Forms::Label());
			this->inkjetPrinterGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->inkjetPaperCountLabel = (gcnew System::Windows::Forms::Label());
			this->blackCartridgeFillLevelLabel = (gcnew System::Windows::Forms::Label());
			this->yellowCartridgeFillLevelLabel = (gcnew System::Windows::Forms::Label());
			this->magentaCartridgeFillLevelLabel = (gcnew System::Windows::Forms::Label());
			this->cyanCartridgeFillLevelLabel = (gcnew System::Windows::Forms::Label());
			this->pictureCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureLaserPaperTray = (gcnew System::Windows::Forms::PictureBox());
			this->internetGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->documentCountLabel = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->simulationGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->inkjetPrinterIllustrationGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->pictureCyanCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureRefillInkjetPaperTray = (gcnew System::Windows::Forms::PictureBox());
			this->pictureMagentaCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureYellowCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBlackCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureRefillBlackCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureRefillYellowCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureRefillCyanCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureRefillMagentaCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->pictureInkjetPrinter = (gcnew System::Windows::Forms::PictureBox());
			this->pictureInkjetPaperTray = (gcnew System::Windows::Forms::PictureBox());
			this->internetAdapterIllustrationGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->pictureInternetAdapter = (gcnew System::Windows::Forms::PictureBox());
			this->laserPrinterIllustrationGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->pictureRefillLaserPaperTray = (gcnew System::Windows::Forms::PictureBox());
			this->pictureRefillCartridge = (gcnew System::Windows::Forms::PictureBox());
			this->computerIllustrationGroupBox = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureComputer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureLaserPrinter))->BeginInit();
			this->controlPanelGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->simulationSpeedTrackBar))->BeginInit();
			this->laserPrinterGroupBox->SuspendLayout();
			this->inkjetPrinterGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureLaserPaperTray))->BeginInit();
			this->internetGroupBox->SuspendLayout();
			this->simulationGroupBox->SuspendLayout();
			this->inkjetPrinterIllustrationGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCyanCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillInkjetPaperTray))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureMagentaCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureYellowCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBlackCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillBlackCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillYellowCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillCyanCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillMagentaCartridge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureInkjetPrinter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureInkjetPaperTray))->BeginInit();
			this->internetAdapterIllustrationGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureInternetAdapter))->BeginInit();
			this->laserPrinterIllustrationGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillLaserPaperTray))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillCartridge))->BeginInit();
			this->computerIllustrationGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// TurnOnDevices
			// 
			this->TurnOnDevices->AutoSize = true;
			this->TurnOnDevices->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TurnOnDevices->Location = System::Drawing::Point(8, 58);
			this->TurnOnDevices->Margin = System::Windows::Forms::Padding(4);
			this->TurnOnDevices->Name = L"TurnOnDevices";
			this->TurnOnDevices->Size = System::Drawing::Size(240, 24);
			this->TurnOnDevices->TabIndex = 2;
			this->TurnOnDevices->Text = L"Включить оборудование";
			this->TurnOnDevices->UseVisualStyleBackColor = true;
			this->TurnOnDevices->CheckedChanged += gcnew System::EventHandler(this, &PrinterSimulation::TurnOnDevices_CheckedChanged);
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &PrinterSimulation::timer_Tick);
			// 
			// pictureComputer
			// 
			this->pictureComputer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureComputer.Image")));
			this->pictureComputer->Location = System::Drawing::Point(77, 28);
			this->pictureComputer->Margin = System::Windows::Forms::Padding(4);
			this->pictureComputer->Name = L"pictureComputer";
			this->pictureComputer->Size = System::Drawing::Size(192, 192);
			this->pictureComputer->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureComputer->TabIndex = 3;
			this->pictureComputer->TabStop = false;
			this->pictureComputer->Click += gcnew System::EventHandler(this, &PrinterSimulation::pictureComputer_Click);
			// 
			// pictureLaserPrinter
			// 
			this->pictureLaserPrinter->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureLaserPrinter->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureLaserPrinter.Image")));
			this->pictureLaserPrinter->ImageLocation = L"";
			this->pictureLaserPrinter->Location = System::Drawing::Point(278, 97);
			this->pictureLaserPrinter->Margin = System::Windows::Forms::Padding(4);
			this->pictureLaserPrinter->Name = L"pictureLaserPrinter";
			this->pictureLaserPrinter->Size = System::Drawing::Size(212, 180);
			this->pictureLaserPrinter->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureLaserPrinter->TabIndex = 7;
			this->pictureLaserPrinter->TabStop = false;
			// 
			// generateDocumentSwitch
			// 
			this->generateDocumentSwitch->AutoSize = true;
			this->generateDocumentSwitch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->generateDocumentSwitch->Location = System::Drawing::Point(8, 26);
			this->generateDocumentSwitch->Margin = System::Windows::Forms::Padding(4);
			this->generateDocumentSwitch->Name = L"generateDocumentSwitch";
			this->generateDocumentSwitch->Size = System::Drawing::Size(200, 24);
			this->generateDocumentSwitch->TabIndex = 8;
			this->generateDocumentSwitch->Text = L"Включить интернет";
			this->generateDocumentSwitch->UseVisualStyleBackColor = true;
			this->generateDocumentSwitch->CheckedChanged += gcnew System::EventHandler(this, &PrinterSimulation::generateDocumentSwitch_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(8, 27);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(267, 20);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Заполненность картриджа, %:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 28);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 20);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Заполненность C-картриджа, %:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 60);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(287, 20);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Заполненность M-картриджа, %:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 95);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(283, 20);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Заполненность Y-картриджа, %:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(8, 129);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(284, 20);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Заполненность K-картриджа, %:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(8, 58);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(177, 20);
			this->label6->TabIndex = 21;
			this->label6->Text = L"Количество бумаги:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(8, 164);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(177, 20);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Количество бумаги:";
			// 
			// computerTimer
			// 
			this->computerTimer->Enabled = true;
			this->computerTimer->Interval = 3000;
			this->computerTimer->Tick += gcnew System::EventHandler(this, &PrinterSimulation::computerTimer_Tick);
			// 
			// controlPanelGroupBox
			// 
			this->controlPanelGroupBox->Controls->Add(this->slow);
			this->controlPanelGroupBox->Controls->Add(this->fast);
			this->controlPanelGroupBox->Controls->Add(this->label13);
			this->controlPanelGroupBox->Controls->Add(this->label12);
			this->controlPanelGroupBox->Controls->Add(this->label11);
			this->controlPanelGroupBox->Controls->Add(this->simulationSpeedTrackBar);
			this->controlPanelGroupBox->Controls->Add(this->generateDocumentSwitch);
			this->controlPanelGroupBox->Controls->Add(this->TurnOnDevices);
			this->controlPanelGroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->controlPanelGroupBox->Location = System::Drawing::Point(16, 15);
			this->controlPanelGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->controlPanelGroupBox->Name = L"controlPanelGroupBox";
			this->controlPanelGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->controlPanelGroupBox->Size = System::Drawing::Size(365, 217);
			this->controlPanelGroupBox->TabIndex = 23;
			this->controlPanelGroupBox->TabStop = false;
			this->controlPanelGroupBox->Text = L"Панель управления";
			// 
			// slow
			// 
			this->slow->Location = System::Drawing::Point(101, 161);
			this->slow->Name = L"slow";
			this->slow->Size = System::Drawing::Size(43, 40);
			this->slow->TabIndex = 35;
			this->slow->Text = L"<";
			this->slow->UseVisualStyleBackColor = true;
			this->slow->Click += gcnew System::EventHandler(this, &PrinterSimulation::slow_Click);
			// 
			// fast
			// 
			this->fast->Location = System::Drawing::Point(219, 161);
			this->fast->Name = L"fast";
			this->fast->Size = System::Drawing::Size(44, 40);
			this->fast->TabIndex = 34;
			this->fast->Text = L">";
			this->fast->UseVisualStyleBackColor = true;
			this->fast->Click += gcnew System::EventHandler(this, &PrinterSimulation::fast_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(325, 114);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(18, 20);
			this->label13->TabIndex = 33;
			this->label13->Text = L"5";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(8, 114);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(18, 20);
			this->label12->TabIndex = 33;
			this->label12->Text = L"1";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(8, 86);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(94, 20);
			this->label11->TabIndex = 28;
			this->label11->Text = L"Скорость:";
			// 
			// simulationSpeedTrackBar
			// 
			this->simulationSpeedTrackBar->LargeChange = 2;
			this->simulationSpeedTrackBar->Location = System::Drawing::Point(35, 114);
			this->simulationSpeedTrackBar->Margin = System::Windows::Forms::Padding(4);
			this->simulationSpeedTrackBar->Maximum = 5;
			this->simulationSpeedTrackBar->Minimum = 1;
			this->simulationSpeedTrackBar->Name = L"simulationSpeedTrackBar";
			this->simulationSpeedTrackBar->Size = System::Drawing::Size(283, 56);
			this->simulationSpeedTrackBar->TabIndex = 32;
			this->simulationSpeedTrackBar->Value = 1;
			this->simulationSpeedTrackBar->Scroll += gcnew System::EventHandler(this, &PrinterSimulation::simulationSpeedTrackBar_ValueChanged);
			this->simulationSpeedTrackBar->ValueChanged += gcnew System::EventHandler(this, &PrinterSimulation::simulationSpeedTrackBar_ValueChanged);
			// 
			// laserPrinterGroupBox
			// 
			this->laserPrinterGroupBox->Controls->Add(this->laserPaperCountLabel);
			this->laserPrinterGroupBox->Controls->Add(this->cartridgeFillLevelLabel);
			this->laserPrinterGroupBox->Controls->Add(this->label1);
			this->laserPrinterGroupBox->Controls->Add(this->label6);
			this->laserPrinterGroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->laserPrinterGroupBox->Location = System::Drawing::Point(16, 258);
			this->laserPrinterGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->laserPrinterGroupBox->Name = L"laserPrinterGroupBox";
			this->laserPrinterGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->laserPrinterGroupBox->Size = System::Drawing::Size(365, 98);
			this->laserPrinterGroupBox->TabIndex = 24;
			this->laserPrinterGroupBox->TabStop = false;
			this->laserPrinterGroupBox->Text = L"Лазерный принтер";
			// 
			// laserPaperCountLabel
			// 
			this->laserPaperCountLabel->AutoSize = true;
			this->laserPaperCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->laserPaperCountLabel->Location = System::Drawing::Point(307, 58);
			this->laserPaperCountLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->laserPaperCountLabel->Name = L"laserPaperCountLabel";
			this->laserPaperCountLabel->Size = System::Drawing::Size(27, 20);
			this->laserPaperCountLabel->TabIndex = 22;
			this->laserPaperCountLabel->Text = L"70";
			// 
			// cartridgeFillLevelLabel
			// 
			this->cartridgeFillLevelLabel->AutoSize = true;
			this->cartridgeFillLevelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->cartridgeFillLevelLabel->Location = System::Drawing::Point(307, 27);
			this->cartridgeFillLevelLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->cartridgeFillLevelLabel->Name = L"cartridgeFillLevelLabel";
			this->cartridgeFillLevelLabel->Size = System::Drawing::Size(36, 20);
			this->cartridgeFillLevelLabel->TabIndex = 22;
			this->cartridgeFillLevelLabel->Text = L"100";
			// 
			// inkjetPrinterGroupBox
			// 
			this->inkjetPrinterGroupBox->Controls->Add(this->inkjetPaperCountLabel);
			this->inkjetPrinterGroupBox->Controls->Add(this->blackCartridgeFillLevelLabel);
			this->inkjetPrinterGroupBox->Controls->Add(this->yellowCartridgeFillLevelLabel);
			this->inkjetPrinterGroupBox->Controls->Add(this->magentaCartridgeFillLevelLabel);
			this->inkjetPrinterGroupBox->Controls->Add(this->cyanCartridgeFillLevelLabel);
			this->inkjetPrinterGroupBox->Controls->Add(this->label2);
			this->inkjetPrinterGroupBox->Controls->Add(this->label3);
			this->inkjetPrinterGroupBox->Controls->Add(this->label7);
			this->inkjetPrinterGroupBox->Controls->Add(this->label4);
			this->inkjetPrinterGroupBox->Controls->Add(this->label5);
			this->inkjetPrinterGroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->inkjetPrinterGroupBox->Location = System::Drawing::Point(16, 373);
			this->inkjetPrinterGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->inkjetPrinterGroupBox->Name = L"inkjetPrinterGroupBox";
			this->inkjetPrinterGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->inkjetPrinterGroupBox->Size = System::Drawing::Size(365, 196);
			this->inkjetPrinterGroupBox->TabIndex = 25;
			this->inkjetPrinterGroupBox->TabStop = false;
			this->inkjetPrinterGroupBox->Text = L"Струйный принтер";
			// 
			// inkjetPaperCountLabel
			// 
			this->inkjetPaperCountLabel->AutoSize = true;
			this->inkjetPaperCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->inkjetPaperCountLabel->Location = System::Drawing::Point(307, 164);
			this->inkjetPaperCountLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->inkjetPaperCountLabel->Name = L"inkjetPaperCountLabel";
			this->inkjetPaperCountLabel->Size = System::Drawing::Size(27, 20);
			this->inkjetPaperCountLabel->TabIndex = 22;
			this->inkjetPaperCountLabel->Text = L"50";
			// 
			// blackCartridgeFillLevelLabel
			// 
			this->blackCartridgeFillLevelLabel->AutoSize = true;
			this->blackCartridgeFillLevelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->blackCartridgeFillLevelLabel->Location = System::Drawing::Point(307, 129);
			this->blackCartridgeFillLevelLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->blackCartridgeFillLevelLabel->Name = L"blackCartridgeFillLevelLabel";
			this->blackCartridgeFillLevelLabel->Size = System::Drawing::Size(36, 20);
			this->blackCartridgeFillLevelLabel->TabIndex = 22;
			this->blackCartridgeFillLevelLabel->Text = L"100";
			// 
			// yellowCartridgeFillLevelLabel
			// 
			this->yellowCartridgeFillLevelLabel->AutoSize = true;
			this->yellowCartridgeFillLevelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->yellowCartridgeFillLevelLabel->Location = System::Drawing::Point(307, 95);
			this->yellowCartridgeFillLevelLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->yellowCartridgeFillLevelLabel->Name = L"yellowCartridgeFillLevelLabel";
			this->yellowCartridgeFillLevelLabel->Size = System::Drawing::Size(36, 20);
			this->yellowCartridgeFillLevelLabel->TabIndex = 22;
			this->yellowCartridgeFillLevelLabel->Text = L"100";
			// 
			// magentaCartridgeFillLevelLabel
			// 
			this->magentaCartridgeFillLevelLabel->AutoSize = true;
			this->magentaCartridgeFillLevelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->magentaCartridgeFillLevelLabel->Location = System::Drawing::Point(307, 60);
			this->magentaCartridgeFillLevelLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->magentaCartridgeFillLevelLabel->Name = L"magentaCartridgeFillLevelLabel";
			this->magentaCartridgeFillLevelLabel->Size = System::Drawing::Size(36, 20);
			this->magentaCartridgeFillLevelLabel->TabIndex = 22;
			this->magentaCartridgeFillLevelLabel->Text = L"100";
			// 
			// cyanCartridgeFillLevelLabel
			// 
			this->cyanCartridgeFillLevelLabel->AutoSize = true;
			this->cyanCartridgeFillLevelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->cyanCartridgeFillLevelLabel->Location = System::Drawing::Point(307, 28);
			this->cyanCartridgeFillLevelLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->cyanCartridgeFillLevelLabel->Name = L"cyanCartridgeFillLevelLabel";
			this->cyanCartridgeFillLevelLabel->Size = System::Drawing::Size(36, 20);
			this->cyanCartridgeFillLevelLabel->TabIndex = 22;
			this->cyanCartridgeFillLevelLabel->Text = L"100";
			// 
			// pictureCartridge
			// 
			this->pictureCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureCartridge.Image")));
			this->pictureCartridge->ImageLocation = L"";
			this->pictureCartridge->Location = System::Drawing::Point(589, 274);
			this->pictureCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureCartridge->Name = L"pictureCartridge";
			this->pictureCartridge->Size = System::Drawing::Size(121, 128);
			this->pictureCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureCartridge->TabIndex = 26;
			this->pictureCartridge->TabStop = false;
			// 
			// pictureLaserPaperTray
			// 
			this->pictureLaserPaperTray->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureLaserPaperTray.Image")));
			this->pictureLaserPaperTray->Location = System::Drawing::Point(8, 172);
			this->pictureLaserPaperTray->Margin = System::Windows::Forms::Padding(4);
			this->pictureLaserPaperTray->Name = L"pictureLaserPaperTray";
			this->pictureLaserPaperTray->Size = System::Drawing::Size(212, 180);
			this->pictureLaserPaperTray->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureLaserPaperTray->TabIndex = 30;
			this->pictureLaserPaperTray->TabStop = false;
			this->pictureLaserPaperTray->Click += gcnew System::EventHandler(this, &PrinterSimulation::pictureLaserPaperTray_Click);
			// 
			// internetGroupBox
			// 
			this->internetGroupBox->Controls->Add(this->documentCountLabel);
			this->internetGroupBox->Controls->Add(this->label10);
			this->internetGroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->internetGroupBox->Location = System::Drawing::Point(16, 577);
			this->internetGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->internetGroupBox->Name = L"internetGroupBox";
			this->internetGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->internetGroupBox->Size = System::Drawing::Size(365, 71);
			this->internetGroupBox->TabIndex = 31;
			this->internetGroupBox->TabStop = false;
			this->internetGroupBox->Text = L"  ";
			// 
			// documentCountLabel
			// 
			this->documentCountLabel->AutoSize = true;
			this->documentCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->documentCountLabel->Location = System::Drawing::Point(307, 33);
			this->documentCountLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->documentCountLabel->Name = L"documentCountLabel";
			this->documentCountLabel->Size = System::Drawing::Size(18, 20);
			this->documentCountLabel->TabIndex = 22;
			this->documentCountLabel->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(8, 33);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(220, 20);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Количество документов:";
			// 
			// simulationGroupBox
			// 
			this->simulationGroupBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->simulationGroupBox->Controls->Add(this->inkjetPrinterIllustrationGroupBox);
			this->simulationGroupBox->Controls->Add(this->internetAdapterIllustrationGroupBox);
			this->simulationGroupBox->Controls->Add(this->laserPrinterIllustrationGroupBox);
			this->simulationGroupBox->Controls->Add(this->computerIllustrationGroupBox);
			this->simulationGroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->simulationGroupBox->Location = System::Drawing::Point(389, 15);
			this->simulationGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->simulationGroupBox->Name = L"simulationGroupBox";
			this->simulationGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->simulationGroupBox->Size = System::Drawing::Size(2133, 1252);
			this->simulationGroupBox->TabIndex = 32;
			this->simulationGroupBox->TabStop = false;
			this->simulationGroupBox->Text = L" ";
			// 
			// inkjetPrinterIllustrationGroupBox
			// 
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureCyanCartridge);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureRefillInkjetPaperTray);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureMagentaCartridge);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureYellowCartridge);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureBlackCartridge);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureRefillBlackCartridge);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureRefillYellowCartridge);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureRefillCyanCartridge);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureRefillMagentaCartridge);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureInkjetPrinter);
			this->inkjetPrinterIllustrationGroupBox->Controls->Add(this->pictureInkjetPaperTray);
			this->inkjetPrinterIllustrationGroupBox->Location = System::Drawing::Point(456, 26);
			this->inkjetPrinterIllustrationGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->inkjetPrinterIllustrationGroupBox->Name = L"inkjetPrinterIllustrationGroupBox";
			this->inkjetPrinterIllustrationGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->inkjetPrinterIllustrationGroupBox->Size = System::Drawing::Size(1033, 442);
			this->inkjetPrinterIllustrationGroupBox->TabIndex = 42;
			this->inkjetPrinterIllustrationGroupBox->TabStop = false;
			this->inkjetPrinterIllustrationGroupBox->Text = L"Струйный принтер";
			// 
			// pictureCyanCartridge
			// 
			this->pictureCyanCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureCyanCartridge.Image")));
			this->pictureCyanCartridge->ImageLocation = L"";
			this->pictureCyanCartridge->Location = System::Drawing::Point(589, 276);
			this->pictureCyanCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureCyanCartridge->Name = L"pictureCyanCartridge";
			this->pictureCyanCartridge->Size = System::Drawing::Size(92, 128);
			this->pictureCyanCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureCyanCartridge->TabIndex = 27;
			this->pictureCyanCartridge->TabStop = false;
			// 
			// pictureRefillInkjetPaperTray
			// 
			this->pictureRefillInkjetPaperTray->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureRefillInkjetPaperTray.Image")));
			this->pictureRefillInkjetPaperTray->Location = System::Drawing::Point(17, 27);
			this->pictureRefillInkjetPaperTray->Margin = System::Windows::Forms::Padding(4);
			this->pictureRefillInkjetPaperTray->Name = L"pictureRefillInkjetPaperTray";
			this->pictureRefillInkjetPaperTray->Size = System::Drawing::Size(212, 180);
			this->pictureRefillInkjetPaperTray->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureRefillInkjetPaperTray->TabIndex = 31;
			this->pictureRefillInkjetPaperTray->TabStop = false;
			this->pictureRefillInkjetPaperTray->Visible = false;
			// 
			// pictureMagentaCartridge
			// 
			this->pictureMagentaCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureMagentaCartridge.Image")));
			this->pictureMagentaCartridge->ImageLocation = L"";
			this->pictureMagentaCartridge->Location = System::Drawing::Point(699, 276);
			this->pictureMagentaCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureMagentaCartridge->Name = L"pictureMagentaCartridge";
			this->pictureMagentaCartridge->Size = System::Drawing::Size(93, 128);
			this->pictureMagentaCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureMagentaCartridge->TabIndex = 28;
			this->pictureMagentaCartridge->TabStop = false;
			this->pictureMagentaCartridge->Click += gcnew System::EventHandler(this, &PrinterSimulation::pictureMagentaCartridge_Click);
			// 
			// pictureYellowCartridge
			// 
			this->pictureYellowCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureYellowCartridge.Image")));
			this->pictureYellowCartridge->ImageLocation = L"";
			this->pictureYellowCartridge->Location = System::Drawing::Point(800, 276);
			this->pictureYellowCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureYellowCartridge->Name = L"pictureYellowCartridge";
			this->pictureYellowCartridge->Size = System::Drawing::Size(91, 128);
			this->pictureYellowCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureYellowCartridge->TabIndex = 28;
			this->pictureYellowCartridge->TabStop = false;
			// 
			// pictureBlackCartridge
			// 
			this->pictureBlackCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBlackCartridge.Image")));
			this->pictureBlackCartridge->ImageLocation = L"";
			this->pictureBlackCartridge->Location = System::Drawing::Point(910, 276);
			this->pictureBlackCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureBlackCartridge->Name = L"pictureBlackCartridge";
			this->pictureBlackCartridge->Size = System::Drawing::Size(93, 128);
			this->pictureBlackCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBlackCartridge->TabIndex = 28;
			this->pictureBlackCartridge->TabStop = false;
			// 
			// pictureRefillBlackCartridge
			// 
			this->pictureRefillBlackCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureRefillBlackCartridge.Image")));
			this->pictureRefillBlackCartridge->ImageLocation = L"";
			this->pictureRefillBlackCartridge->Location = System::Drawing::Point(939, 14);
			this->pictureRefillBlackCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureRefillBlackCartridge->Name = L"pictureRefillBlackCartridge";
			this->pictureRefillBlackCartridge->Size = System::Drawing::Size(36, 222);
			this->pictureRefillBlackCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureRefillBlackCartridge->TabIndex = 36;
			this->pictureRefillBlackCartridge->TabStop = false;
			this->pictureRefillBlackCartridge->Visible = false;
			// 
			// pictureRefillYellowCartridge
			// 
			this->pictureRefillYellowCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureRefillYellowCartridge.Image")));
			this->pictureRefillYellowCartridge->ImageLocation = L"";
			this->pictureRefillYellowCartridge->Location = System::Drawing::Point(826, 14);
			this->pictureRefillYellowCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureRefillYellowCartridge->Name = L"pictureRefillYellowCartridge";
			this->pictureRefillYellowCartridge->Size = System::Drawing::Size(36, 222);
			this->pictureRefillYellowCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureRefillYellowCartridge->TabIndex = 35;
			this->pictureRefillYellowCartridge->TabStop = false;
			this->pictureRefillYellowCartridge->Visible = false;
			// 
			// pictureRefillCyanCartridge
			// 
			this->pictureRefillCyanCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureRefillCyanCartridge.Image")));
			this->pictureRefillCyanCartridge->ImageLocation = L"";
			this->pictureRefillCyanCartridge->Location = System::Drawing::Point(615, 14);
			this->pictureRefillCyanCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureRefillCyanCartridge->Name = L"pictureRefillCyanCartridge";
			this->pictureRefillCyanCartridge->Size = System::Drawing::Size(36, 224);
			this->pictureRefillCyanCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureRefillCyanCartridge->TabIndex = 33;
			this->pictureRefillCyanCartridge->TabStop = false;
			this->pictureRefillCyanCartridge->Visible = false;
			// 
			// pictureRefillMagentaCartridge
			// 
			this->pictureRefillMagentaCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureRefillMagentaCartridge.Image")));
			this->pictureRefillMagentaCartridge->ImageLocation = L"";
			this->pictureRefillMagentaCartridge->Location = System::Drawing::Point(727, 14);
			this->pictureRefillMagentaCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureRefillMagentaCartridge->Name = L"pictureRefillMagentaCartridge";
			this->pictureRefillMagentaCartridge->Size = System::Drawing::Size(36, 222);
			this->pictureRefillMagentaCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureRefillMagentaCartridge->TabIndex = 34;
			this->pictureRefillMagentaCartridge->TabStop = false;
			this->pictureRefillMagentaCartridge->Visible = false;
			// 
			// pictureInkjetPrinter
			// 
			this->pictureInkjetPrinter->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureInkjetPrinter.Image")));
			this->pictureInkjetPrinter->Location = System::Drawing::Point(292, 135);
			this->pictureInkjetPrinter->Margin = System::Windows::Forms::Padding(4);
			this->pictureInkjetPrinter->Name = L"pictureInkjetPrinter";
			this->pictureInkjetPrinter->Size = System::Drawing::Size(212, 180);
			this->pictureInkjetPrinter->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureInkjetPrinter->TabIndex = 6;
			this->pictureInkjetPrinter->TabStop = false;
			// 
			// pictureInkjetPaperTray
			// 
			this->pictureInkjetPaperTray->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureInkjetPaperTray.Image")));
			this->pictureInkjetPaperTray->Location = System::Drawing::Point(17, 174);
			this->pictureInkjetPaperTray->Margin = System::Windows::Forms::Padding(4);
			this->pictureInkjetPaperTray->Name = L"pictureInkjetPaperTray";
			this->pictureInkjetPaperTray->Size = System::Drawing::Size(212, 180);
			this->pictureInkjetPaperTray->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureInkjetPaperTray->TabIndex = 29;
			this->pictureInkjetPaperTray->TabStop = false;
			// 
			// internetAdapterIllustrationGroupBox
			// 
			this->internetAdapterIllustrationGroupBox->Controls->Add(this->pictureInternetAdapter);
			this->internetAdapterIllustrationGroupBox->Location = System::Drawing::Point(31, 503);
			this->internetAdapterIllustrationGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->internetAdapterIllustrationGroupBox->Name = L"internetAdapterIllustrationGroupBox";
			this->internetAdapterIllustrationGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->internetAdapterIllustrationGroupBox->Size = System::Drawing::Size(281, 313);
			this->internetAdapterIllustrationGroupBox->TabIndex = 43;
			this->internetAdapterIllustrationGroupBox->TabStop = false;
			this->internetAdapterIllustrationGroupBox->Text = L"Интернет-адаптер";
			// 
			// pictureInternetAdapter
			// 
			this->pictureInternetAdapter->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureInternetAdapter.Image")));
			this->pictureInternetAdapter->Location = System::Drawing::Point(34, 84);
			this->pictureInternetAdapter->Margin = System::Windows::Forms::Padding(4);
			this->pictureInternetAdapter->Name = L"pictureInternetAdapter";
			this->pictureInternetAdapter->Size = System::Drawing::Size(212, 180);
			this->pictureInternetAdapter->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureInternetAdapter->TabIndex = 4;
			this->pictureInternetAdapter->TabStop = false;
			// 
			// laserPrinterIllustrationGroupBox
			// 
			this->laserPrinterIllustrationGroupBox->Controls->Add(this->pictureRefillLaserPaperTray);
			this->laserPrinterIllustrationGroupBox->Controls->Add(this->pictureRefillCartridge);
			this->laserPrinterIllustrationGroupBox->Controls->Add(this->pictureCartridge);
			this->laserPrinterIllustrationGroupBox->Controls->Add(this->pictureLaserPrinter);
			this->laserPrinterIllustrationGroupBox->Controls->Add(this->pictureLaserPaperTray);
			this->laserPrinterIllustrationGroupBox->Location = System::Drawing::Point(456, 503);
			this->laserPrinterIllustrationGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->laserPrinterIllustrationGroupBox->Name = L"laserPrinterIllustrationGroupBox";
			this->laserPrinterIllustrationGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->laserPrinterIllustrationGroupBox->Size = System::Drawing::Size(854, 410);
			this->laserPrinterIllustrationGroupBox->TabIndex = 41;
			this->laserPrinterIllustrationGroupBox->TabStop = false;
			this->laserPrinterIllustrationGroupBox->Text = L"Лазерный принтер";
			// 
			// pictureRefillLaserPaperTray
			// 
			this->pictureRefillLaserPaperTray->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureRefillLaserPaperTray.Image")));
			this->pictureRefillLaserPaperTray->Location = System::Drawing::Point(8, 27);
			this->pictureRefillLaserPaperTray->Margin = System::Windows::Forms::Padding(4);
			this->pictureRefillLaserPaperTray->Name = L"pictureRefillLaserPaperTray";
			this->pictureRefillLaserPaperTray->Size = System::Drawing::Size(212, 180);
			this->pictureRefillLaserPaperTray->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureRefillLaserPaperTray->TabIndex = 32;
			this->pictureRefillLaserPaperTray->TabStop = false;
			this->pictureRefillLaserPaperTray->Visible = false;
			// 
			// pictureRefillCartridge
			// 
			this->pictureRefillCartridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureRefillCartridge.Image")));
			this->pictureRefillCartridge->ImageLocation = L"";
			this->pictureRefillCartridge->Location = System::Drawing::Point(631, 27);
			this->pictureRefillCartridge->Margin = System::Windows::Forms::Padding(4);
			this->pictureRefillCartridge->Name = L"pictureRefillCartridge";
			this->pictureRefillCartridge->Size = System::Drawing::Size(36, 222);
			this->pictureRefillCartridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureRefillCartridge->TabIndex = 37;
			this->pictureRefillCartridge->TabStop = false;
			this->pictureRefillCartridge->Visible = false;
			// 
			// computerIllustrationGroupBox
			// 
			this->computerIllustrationGroupBox->Controls->Add(this->pictureComputer);
			this->computerIllustrationGroupBox->Location = System::Drawing::Point(31, 28);
			this->computerIllustrationGroupBox->Margin = System::Windows::Forms::Padding(4);
			this->computerIllustrationGroupBox->Name = L"computerIllustrationGroupBox";
			this->computerIllustrationGroupBox->Padding = System::Windows::Forms::Padding(4);
			this->computerIllustrationGroupBox->Size = System::Drawing::Size(395, 313);
			this->computerIllustrationGroupBox->TabIndex = 42;
			this->computerIllustrationGroupBox->TabStop = false;
			this->computerIllustrationGroupBox->Text = L"Компьютер";
			// 
			// PrinterSimulation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->simulationGroupBox);
			this->Controls->Add(this->internetGroupBox);
			this->Controls->Add(this->inkjetPrinterGroupBox);
			this->Controls->Add(this->laserPrinterGroupBox);
			this->Controls->Add(this->controlPanelGroupBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"PrinterSimulation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Модель работы принтера при его взаимодействии с компьютером";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureComputer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureLaserPrinter))->EndInit();
			this->controlPanelGroupBox->ResumeLayout(false);
			this->controlPanelGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->simulationSpeedTrackBar))->EndInit();
			this->laserPrinterGroupBox->ResumeLayout(false);
			this->laserPrinterGroupBox->PerformLayout();
			this->inkjetPrinterGroupBox->ResumeLayout(false);
			this->inkjetPrinterGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureLaserPaperTray))->EndInit();
			this->internetGroupBox->ResumeLayout(false);
			this->internetGroupBox->PerformLayout();
			this->simulationGroupBox->ResumeLayout(false);
			this->inkjetPrinterIllustrationGroupBox->ResumeLayout(false);
			this->inkjetPrinterIllustrationGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCyanCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillInkjetPaperTray))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureMagentaCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureYellowCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBlackCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillBlackCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillYellowCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillCyanCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillMagentaCartridge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureInkjetPrinter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureInkjetPaperTray))->EndInit();
			this->internetAdapterIllustrationGroupBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureInternetAdapter))->EndInit();
			this->laserPrinterIllustrationGroupBox->ResumeLayout(false);
			this->laserPrinterIllustrationGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillLaserPaperTray))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureRefillCartridge))->EndInit();
			this->computerIllustrationGroupBox->ResumeLayout(false);
			this->computerIllustrationGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:/**/
		void ShowPrinterPrinting(Printer^ printer)
		{
			String^ printerType;
			String^ printerTypeSecond;

			if (printer->GetType() == Printer::typeid)
			{
				printerType = "LaserPrinter";
				printerTypeSecond = "InkjetPrinter";
			}
			else
			{
				printerType = "InkjetPrinter";
				printerTypeSecond = "LaserPrinter";
			}

			int delay = 2000 / _programSpeed;

			if (printerType == "LaserPrinter")
			{
				_dicLaserPrinter->Change(printerType + "/Printing.png", delay);
				pictureInkjetPrinter->ImageLocation = printerTypeSecond + "/Printer.png";
			}
			else
			{
				_dicInkjetPrinter->Change(printerType + "/Printing.png", delay);
				pictureLaserPrinter->ImageLocation = printerTypeSecond + "/Printer.png";
			}
		}

		void ShowPrinterOutOfPaper(Printer^ printer)
		{
			String^ printerType = printer->GetType() == Printer::typeid ? "LaserPrinter" : "InkjetPrinter";

			String^ imagePath = printerType + "/PrinterOutOfPaper.png";

			if (printerType == "LaserPrinter")
				pictureLaserPrinter->ImageLocation = imagePath;
			else
				pictureInkjetPrinter->ImageLocation = imagePath;
		}

		void ShowPrinterMaintance(Printer^ printer, int index)
		{
			String^ printerType = printer->GetType() == Printer::typeid ? "LaserPrinter" : "InkjetPrinter";

			String^ imagePath = printerType + "/PrinterMaintance.png";

			if (printerType == "LaserPrinter")
				pictureLaserPrinter->ImageLocation = imagePath;
			else
				pictureInkjetPrinter->ImageLocation = imagePath;
		}

		String^ GetCartridgeColor(int index)
		{
			array<String^>^ colors = { "Cyan", "Magenta", "Yellow", "Black" };

			if (index >= 0 && index < colors->Length)
				return colors[index];
			else
				return "";
		}

		void ShowCartridgeFillLevel(PictureBox^ pictureBox, int cartridgeFillLevel, int index)
		{
			array<String^>^ fillRanges = { "0", "0-25", "25-50", "50-75", "75-100", "100" };
			array<int>^ thresholds = { 0, 1, 25, 50, 75, 100 };

			String^ fillRange = "0";

			for (int i = thresholds->Length - 1; i >= 0; i--)
			{
				if (cartridgeFillLevel >= thresholds[i])
				{
					fillRange = fillRanges[i];
					break;
				}
			}

			String^ cartridgeColor = GetCartridgeColor(index);
			pictureBox->ImageLocation = "Cartridges/" + cartridgeColor + "Cartridge_" + fillRange + ".png";
		}

		void ShowPaperTrayFillLevel(PictureBox^ pictureBox, int paperTrayFillLevel)
		{
			array<int>^ thresholds = { 0, 4, 16, 28, 40, 52, 64, 76, 88, 100 };

			int fillLevel = 0; // default value

			for (int i = thresholds->Length - 1; i >= 0; i--)
			{
				if (paperTrayFillLevel >= thresholds[i])
				{
					fillLevel = thresholds[i];
					break;
				}
			}

			pictureBox->ImageLocation = "PaperTray/PaperTray_" + fillLevel.ToString() + ".png";
		}

		void ShowRefillPaperTray(Printer^ printer)
		{
			int delay = 800 / _programSpeed;

			if (printer->GetType() == Printer::typeid)
				_dvcRefillLaserPaperTray->Change(true, delay);
			else
				_dvcRefillInkjetPaperTray->Change(true, delay);
		}

		void ShowRefillCartridge(int index) // 
		{
			String^ color = GetCartridgeColor(index);

			int delay = 800 / _programSpeed;

			if (color == "Cyan")
				_dvcRefillCyanCartridge->Change(true, delay);

			else if (color == "Magenta")
				_dvcRefillMagentaCartridge->Change(true, delay);

			else if (color == "Yellow")
				_dvcRefillYellowCartridge->Change(true, delay);

			else if (color == "Black")
				_dvcRefillBlackCartridge->Change(true, delay);

			else
				_dvcRefillCartridge->Change(true, delay);
		}

		int CalculateCartridgeFill(Printer^ printer, int cartridgeIndex) // возвращает текущий уровень чернил
		{
			int cartridgeFillLevel = printer->GetCartridgeFillLevel(cartridgeIndex);
			int cartridgeCapacity = printer->CartridgeCapacity;

			return (int)Math::Round((double)cartridgeFillLevel / cartridgeCapacity * 100);
		}

		int CalculatePaperTrayFill(Printer^ printer)
		{
			int paperTrayCount = printer->PaperTrayCount;
			int paperTrayCapacity = printer->PaperTrayCapacity;

			return (int)Math::Round((double)paperTrayCount / paperTrayCapacity * 100);
		}

		void SubscribeToPrinterEvents(Printer^ printer)
		{
			printer->Printing += gcnew Printer::PrintingEventHandler(this, &PrinterSimulation::ShowPrinterPrinting);
			printer->PaperTrayEmpty += gcnew Printer::PaperTrayEmptyEventHandler(this, &PrinterSimulation::ShowPrinterOutOfPaper);
			printer->CartridgeEmpty += gcnew Printer::CartridgeEmptyEventHandler(this, &PrinterSimulation::ShowPrinterMaintance);
		}

		void SubscribeToHumanEvents(Human^ human)
		{
			human->CartridgeRefilled += gcnew Human::CartridgeRefilledEventHandler(this, &PrinterSimulation::ShowRefillCartridge);
			human->PaperTrayRefilled += gcnew Human::PaperTrayRefilledEventHandler(this, &PrinterSimulation::ShowRefillPaperTray);
		}

		void UnsubscribeFromPrinterEvents(Printer^ printer)
		{
			printer->Printing -= gcnew Printer::PrintingEventHandler(this, &PrinterSimulation::ShowPrinterPrinting);
			printer->PaperTrayEmpty -= gcnew Printer::PaperTrayEmptyEventHandler(this, &PrinterSimulation::ShowPrinterOutOfPaper);
			printer->CartridgeEmpty -= gcnew Printer::CartridgeEmptyEventHandler(this, &PrinterSimulation::ShowPrinterMaintance);
		}

		void UnsubcribeFromHumanEvents(Human^ human)
		{
			human->CartridgeRefilled -= gcnew Human::CartridgeRefilledEventHandler(this, &PrinterSimulation::ShowRefillCartridge);
			human->PaperTrayRefilled -= gcnew Human::PaperTrayRefilledEventHandler(this, &PrinterSimulation::ShowRefillPaperTray);
		}

		private: System::Void TurnOnDevices_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			_computer->AdapterIsEnabled = TurnOnDevices->Checked;
			if (_computer->AdapterIsEnabled)
			{
				_computer->SubscribeToEvents(_laserPrinter);
				_computer->SubscribeToEvents(_inkjetPrinter);

				SubscribeToPrinterEvents(_laserPrinter);
				SubscribeToPrinterEvents(_inkjetPrinter);

				SubscribeToHumanEvents(_human);

				pictureComputer->ImageLocation = L"Computer/Computer.png";
			}
			else
			{
				UnsubcribeFromHumanEvents(_human);

				UnsubscribeFromPrinterEvents(_laserPrinter);
				UnsubscribeFromPrinterEvents(_inkjetPrinter);

				_computer->UnsubscribeFromEvents(_laserPrinter);
				_computer->UnsubscribeFromEvents(_inkjetPrinter);

				pictureComputer->ImageLocation = L"Computer/ComputerNoNetwork.png";

				_dicLaserPrinter->Change(L"LaserPrinter/Printer.png", 1000 / _programSpeed);
				_dicInkjetPrinter->Change(L"InkjetPrinter/Printer.png", 1000 / _programSpeed);
			}
		}

		private: System::Void fast_Click(System::Object^ sender, System::EventArgs^ e) {
			if ((_programSpeed >= 1) && (_programSpeed < 5))
				_programSpeed++;
				simulationSpeedTrackBar->Value = _programSpeed;
				_computer->ChangeTimerInterval(_programSpeed);

				_internet->ChangeTimerInterval(_programSpeed);
		}

		private: System::Void slow_Click(System::Object^ sender, System::EventArgs^ e) {
			if ((_programSpeed > 1) && (_programSpeed <= 5))
				_programSpeed--;
				simulationSpeedTrackBar->Value = _programSpeed;
				_computer->ChangeTimerInterval(_programSpeed);

				_internet->ChangeTimerInterval(_programSpeed);
		}

		private: System::Void generateDocumentSwitch_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (generateDocumentSwitch->Checked)
			{
				pictureInternetAdapter->ImageLocation = L"InternetAdapter/Enable.png";

				_internet->StartGenerating();
			}
			else
			{
				pictureInternetAdapter->ImageLocation = L"InternetAdapter/Disable.png";
				_internet->StopGenerating();
			}
		}

		private: System::Void computerTimer_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			if (_computer->AdapterIsEnabled)
			{
				pictureComputer->ImageLocation = "Computer/ComputerInAction.png";
				_dicComputerOnAction->Change("Computer/Computer.png", 1000 / _programSpeed);
			}

			if (_internet->GetCurrentDocumentCount() == 0 && (!generateDocumentSwitch->Checked))
			{
				_dicComputerOnAction->Change("Computer/ComputerNoNetwork.png", 1000 / _programSpeed);

				_dicLaserPrinter->Change(L"LaserPrinter/Printer.png", 1000 / _programSpeed);
				_dicInkjetPrinter->Change(L"InkjetPrinter/Printer.png", 1000 / _programSpeed);
			}
		}

		private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			int cartridgeFillLevel = CalculateCartridgeFill(_laserPrinter, -1);
			cartridgeFillLevelLabel->Text = Convert::ToString(cartridgeFillLevel);
			ShowCartridgeFillLevel(pictureCartridge, cartridgeFillLevel, -1);

			int cyanCartridgeFillLevel = CalculateCartridgeFill(_inkjetPrinter, 0);
			cyanCartridgeFillLevelLabel->Text = Convert::ToString(cyanCartridgeFillLevel);
			ShowCartridgeFillLevel(pictureCyanCartridge, cyanCartridgeFillLevel, 0);

			int magentaCartridgeFillLevel = CalculateCartridgeFill(_inkjetPrinter, 1);
			magentaCartridgeFillLevelLabel->Text = Convert::ToString(magentaCartridgeFillLevel);
			ShowCartridgeFillLevel(pictureMagentaCartridge, magentaCartridgeFillLevel, 1);

			int yellowCartridgeFillLevel = CalculateCartridgeFill(_inkjetPrinter, 2);
			yellowCartridgeFillLevelLabel->Text = Convert::ToString(yellowCartridgeFillLevel);
			ShowCartridgeFillLevel(pictureYellowCartridge, yellowCartridgeFillLevel, 2);

			int blackCartridgeFillLevel = CalculateCartridgeFill(_inkjetPrinter, 3);
			blackCartridgeFillLevelLabel->Text = Convert::ToString(blackCartridgeFillLevel);
			ShowCartridgeFillLevel(pictureBlackCartridge, blackCartridgeFillLevel, 3);

			laserPaperCountLabel->Text = Convert::ToString(_laserPrinter->PaperTrayCount);
			int laserPaperTrayFillLevel = CalculatePaperTrayFill(_laserPrinter);
			ShowPaperTrayFillLevel(pictureLaserPaperTray, laserPaperTrayFillLevel);

			inkjetPaperCountLabel->Text = Convert::ToString(_inkjetPrinter->PaperTrayCount);
			int inkjetPaperTrayFillLevel = CalculatePaperTrayFill(_inkjetPrinter);
			ShowPaperTrayFillLevel(pictureInkjetPaperTray, inkjetPaperTrayFillLevel);

			int currentDocumentCount = _internet->GetCurrentDocumentCount();
			documentCountLabel->Text = Convert::ToString(currentDocumentCount);
		}

		private: System::Void simulationSpeedTrackBar_ValueChanged(System::Object^ sender, System::EventArgs^ e)
		{
			_programSpeed = simulationSpeedTrackBar->Value;

			_computer->ChangeTimerInterval(_programSpeed);

			_internet->ChangeTimerInterval(_programSpeed);
		}
	private: System::Void pictureComputer_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureLaserPaperTray_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void simulationSpeedTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
	}
		
private: System::Void pictureMagentaCartridge_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
