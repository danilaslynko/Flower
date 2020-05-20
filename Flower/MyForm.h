#pragma once
#include "Flower.h"
#include <windows.h>
#include "Sunflower.h"
namespace Flower {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ Цветок;
	private: System::Windows::Forms::Button^ buttonWaterFlower;
	private: System::Windows::Forms::Button^ buttonNewFlower;
	private: System::Windows::Forms::Label^ labelParamFlower;
	private: System::Windows::Forms::Label^ lblt1;
	private: System::Windows::Forms::TrackBar^ dayTimeBarFlower;
	private: System::Windows::Forms::TrackBar^ seasonBarFlower;
	private: System::Windows::Forms::TabPage^ Подсолнух;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TrackBar^ seasonBarSunflower;
	private: System::Windows::Forms::TrackBar^ dayTimeBarSunflower;
	private: System::Windows::Forms::Label^ lblw2;
	private: System::Windows::Forms::Label^ lblt2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ buttonWaterSunflower;
	private: System::Windows::Forms::Button^ buttonNewSunflower;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::TrackBar^ temperatureBarFlower;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ labelParamSunflower;

	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::TrackBar^ temperatureBarSunflower;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Button^ buttonSeeds;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ can;
	private: System::Windows::Forms::PictureBox^ can2;

	private: System::ComponentModel::IContainer^ components;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->Цветок = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->temperatureBarFlower = (gcnew System::Windows::Forms::TrackBar());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonWaterFlower = (gcnew System::Windows::Forms::Button());
			this->buttonNewFlower = (gcnew System::Windows::Forms::Button());
			this->labelParamFlower = (gcnew System::Windows::Forms::Label());
			this->lblt1 = (gcnew System::Windows::Forms::Label());
			this->dayTimeBarFlower = (gcnew System::Windows::Forms::TrackBar());
			this->seasonBarFlower = (gcnew System::Windows::Forms::TrackBar());
			this->Подсолнух = (gcnew System::Windows::Forms::TabPage());
			this->buttonSeeds = (gcnew System::Windows::Forms::Button());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->labelParamSunflower = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->temperatureBarSunflower = (gcnew System::Windows::Forms::TrackBar());
			this->buttonWaterSunflower = (gcnew System::Windows::Forms::Button());
			this->buttonNewSunflower = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->seasonBarSunflower = (gcnew System::Windows::Forms::TrackBar());
			this->dayTimeBarSunflower = (gcnew System::Windows::Forms::TrackBar());
			this->lblw2 = (gcnew System::Windows::Forms::Label());
			this->lblt2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->can = (gcnew System::Windows::Forms::PictureBox());
			this->can2 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->Цветок->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->temperatureBarFlower))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dayTimeBarFlower))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seasonBarFlower))->BeginInit();
			this->Подсолнух->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->temperatureBarSunflower))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seasonBarSunflower))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dayTimeBarSunflower))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->can))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->can2))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->Цветок);
			this->tabControl1->Controls->Add(this->Подсолнух);
			this->tabControl1->Location = System::Drawing::Point(3, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1030, 672);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::tabControl1_SelectedIndexChanged);
			// 
			// Цветок
			// 
			this->Цветок->AllowDrop = true;
			this->Цветок->Controls->Add(this->can);
			this->Цветок->Controls->Add(this->pictureBox1);
			this->Цветок->Controls->Add(this->progressBar1);
			this->Цветок->Controls->Add(this->label26);
			this->Цветок->Controls->Add(this->label25);
			this->Цветок->Controls->Add(this->label24);
			this->Цветок->Controls->Add(this->label23);
			this->Цветок->Controls->Add(this->label22);
			this->Цветок->Controls->Add(this->label21);
			this->Цветок->Controls->Add(this->temperatureBarFlower);
			this->Цветок->Controls->Add(this->label17);
			this->Цветок->Controls->Add(this->label18);
			this->Цветок->Controls->Add(this->label19);
			this->Цветок->Controls->Add(this->label20);
			this->Цветок->Controls->Add(this->label13);
			this->Цветок->Controls->Add(this->label16);
			this->Цветок->Controls->Add(this->label4);
			this->Цветок->Controls->Add(this->label3);
			this->Цветок->Controls->Add(this->buttonWaterFlower);
			this->Цветок->Controls->Add(this->buttonNewFlower);
			this->Цветок->Controls->Add(this->labelParamFlower);
			this->Цветок->Controls->Add(this->lblt1);
			this->Цветок->Controls->Add(this->dayTimeBarFlower);
			this->Цветок->Controls->Add(this->seasonBarFlower);
			this->Цветок->Location = System::Drawing::Point(4, 25);
			this->Цветок->Name = L"Цветок";
			this->Цветок->Padding = System::Windows::Forms::Padding(3);
			this->Цветок->Size = System::Drawing::Size(1022, 643);
			this->Цветок->TabIndex = 0;
			this->Цветок->Text = L"Цветок";
			this->Цветок->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(6, 8);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(479, 615);
			this->pictureBox1->TabIndex = 35;
			this->pictureBox1->TabStop = false;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(494, 323);
			this->progressBar1->Maximum = 30;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(482, 40);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 34;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(914, 366);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(65, 17);
			this->label26->TabIndex = 33;
			this->label26->Text = L"Высокая";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(714, 366);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(65, 17);
			this->label25->TabIndex = 32;
			this->label25->Text = L"Средняя";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(494, 366);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(56, 17);
			this->label24->TabIndex = 31;
			this->label24->Text = L"Низкая";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(917, 87);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(65, 17);
			this->label23->TabIndex = 30;
			this->label23->Text = L"Высокая";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(494, 87);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(56, 17);
			this->label22->TabIndex = 29;
			this->label22->Text = L"Низкая";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(714, 87);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(65, 17);
			this->label21->TabIndex = 28;
			this->label21->Text = L"Средняя";
			// 
			// temperatureBarFlower
			// 
			this->temperatureBarFlower->Location = System::Drawing::Point(494, 28);
			this->temperatureBarFlower->Maximum = 3;
			this->temperatureBarFlower->Minimum = 1;
			this->temperatureBarFlower->Name = L"temperatureBarFlower";
			this->temperatureBarFlower->Size = System::Drawing::Size(485, 56);
			this->temperatureBarFlower->TabIndex = 27;
			this->temperatureBarFlower->Value = 2;
			this->temperatureBarFlower->ValueChanged += gcnew System::EventHandler(this, &MyForm::temperatureBarFlower_ValueChanged);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(491, 280);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(42, 17);
			this->label17->TabIndex = 23;
			this->label17->Text = L"Зима";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(636, 280);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(48, 17);
			this->label18->TabIndex = 22;
			this->label18->Text = L"Весна";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(791, 280);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(41, 17);
			this->label19->TabIndex = 21;
			this->label19->Text = L"Лето";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(930, 280);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(49, 17);
			this->label20->TabIndex = 20;
			this->label20->Text = L"Осень";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(491, 184);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(42, 17);
			this->label13->TabIndex = 19;
			this->label13->Text = L"День";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(938, 184);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(41, 17);
			this->label16->TabIndex = 16;
			this->label16->Text = L"Ночь";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(491, 105);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Время суток";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(488, 201);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Время года";
			// 
			// buttonWaterFlower
			// 
			this->buttonWaterFlower->Location = System::Drawing::Point(892, 585);
			this->buttonWaterFlower->Name = L"buttonWaterFlower";
			this->buttonWaterFlower->Size = System::Drawing::Size(103, 38);
			this->buttonWaterFlower->TabIndex = 7;
			this->buttonWaterFlower->Text = L"Полить";
			this->buttonWaterFlower->UseVisualStyleBackColor = true;
			this->buttonWaterFlower->Click += gcnew System::EventHandler(this, &MyForm::buttonWaterFlower_Click);
			// 
			// buttonNewFlower
			// 
			this->buttonNewFlower->Location = System::Drawing::Point(667, 585);
			this->buttonNewFlower->Name = L"buttonNewFlower";
			this->buttonNewFlower->Size = System::Drawing::Size(201, 38);
			this->buttonNewFlower->TabIndex = 6;
			this->buttonNewFlower->Text = L"Найти новый цветочек";
			this->buttonNewFlower->UseVisualStyleBackColor = true;
			this->buttonNewFlower->Click += gcnew System::EventHandler(this, &MyForm::buttonNewFlower_Click);
			// 
			// labelParamFlower
			// 
			this->labelParamFlower->AutoSize = true;
			this->labelParamFlower->Location = System::Drawing::Point(491, 303);
			this->labelParamFlower->Name = L"labelParamFlower";
			this->labelParamFlower->Size = System::Drawing::Size(88, 17);
			this->labelParamFlower->TabIndex = 4;
			this->labelParamFlower->Text = L"Дегидрация";
			// 
			// lblt1
			// 
			this->lblt1->AutoSize = true;
			this->lblt1->Location = System::Drawing::Point(494, 8);
			this->lblt1->Name = L"lblt1";
			this->lblt1->Size = System::Drawing::Size(96, 17);
			this->lblt1->TabIndex = 2;
			this->lblt1->Text = L"Температура";
			// 
			// dayTimeBarFlower
			// 
			this->dayTimeBarFlower->Location = System::Drawing::Point(494, 125);
			this->dayTimeBarFlower->Maximum = 2;
			this->dayTimeBarFlower->Minimum = 1;
			this->dayTimeBarFlower->Name = L"dayTimeBarFlower";
			this->dayTimeBarFlower->Size = System::Drawing::Size(485, 56);
			this->dayTimeBarFlower->TabIndex = 1;
			this->dayTimeBarFlower->Value = 1;
			this->dayTimeBarFlower->ValueChanged += gcnew System::EventHandler(this, &MyForm::dayTimeBarFlower_ValueChanged);
			// 
			// seasonBarFlower
			// 
			this->seasonBarFlower->Location = System::Drawing::Point(491, 221);
			this->seasonBarFlower->Maximum = 4;
			this->seasonBarFlower->Minimum = 1;
			this->seasonBarFlower->Name = L"seasonBarFlower";
			this->seasonBarFlower->Size = System::Drawing::Size(485, 56);
			this->seasonBarFlower->TabIndex = 0;
			this->seasonBarFlower->Value = 3;
			this->seasonBarFlower->ValueChanged += gcnew System::EventHandler(this, &MyForm::seasonBarFlower_ValueChanged);
			// 
			// Подсолнух
			// 
			this->Подсолнух->Controls->Add(this->can2);
			this->Подсолнух->Controls->Add(this->buttonSeeds);
			this->Подсолнух->Controls->Add(this->progressBar2);
			this->Подсолнух->Controls->Add(this->pictureBox2);
			this->Подсолнух->Controls->Add(this->label30);
			this->Подсолнух->Controls->Add(this->label31);
			this->Подсолнух->Controls->Add(this->label32);
			this->Подсолнух->Controls->Add(this->labelParamSunflower);
			this->Подсолнух->Controls->Add(this->label27);
			this->Подсолнух->Controls->Add(this->label28);
			this->Подсолнух->Controls->Add(this->label29);
			this->Подсолнух->Controls->Add(this->temperatureBarSunflower);
			this->Подсолнух->Controls->Add(this->buttonWaterSunflower);
			this->Подсолнух->Controls->Add(this->buttonNewSunflower);
			this->Подсолнух->Controls->Add(this->label12);
			this->Подсолнух->Controls->Add(this->label11);
			this->Подсолнух->Controls->Add(this->label10);
			this->Подсолнух->Controls->Add(this->label9);
			this->Подсолнух->Controls->Add(this->label8);
			this->Подсолнух->Controls->Add(this->label5);
			this->Подсолнух->Controls->Add(this->label2);
			this->Подсолнух->Controls->Add(this->label1);
			this->Подсолнух->Controls->Add(this->seasonBarSunflower);
			this->Подсолнух->Controls->Add(this->dayTimeBarSunflower);
			this->Подсолнух->Controls->Add(this->lblw2);
			this->Подсолнух->Controls->Add(this->lblt2);
			this->Подсолнух->Location = System::Drawing::Point(4, 25);
			this->Подсолнух->Name = L"Подсолнух";
			this->Подсолнух->Padding = System::Windows::Forms::Padding(3);
			this->Подсолнух->Size = System::Drawing::Size(1022, 643);
			this->Подсолнух->TabIndex = 1;
			this->Подсолнух->Text = L"Подсолнух";
			this->Подсолнух->UseVisualStyleBackColor = true;
			// 
			// buttonSeeds
			// 
			this->buttonSeeds->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonSeeds->Enabled = false;
			this->buttonSeeds->Location = System::Drawing::Point(497, 585);
			this->buttonSeeds->Name = L"buttonSeeds";
			this->buttonSeeds->Size = System::Drawing::Size(158, 38);
			this->buttonSeeds->TabIndex = 40;
			this->buttonSeeds->Text = L"Собрать семечки";
			this->buttonSeeds->UseVisualStyleBackColor = true;
			this->buttonSeeds->Click += gcnew System::EventHandler(this, &MyForm::buttonSeeds_Click);
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(494, 348);
			this->progressBar2->Maximum = 30;
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(485, 40);
			this->progressBar2->Step = 2;
			this->progressBar2->TabIndex = 35;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(6, 8);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(479, 617);
			this->pictureBox2->TabIndex = 39;
			this->pictureBox2->TabStop = false;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(911, 396);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(65, 17);
			this->label30->TabIndex = 38;
			this->label30->Text = L"Высокая";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(708, 396);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(65, 17);
			this->label31->TabIndex = 37;
			this->label31->Text = L"Средняя";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(491, 396);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(56, 17);
			this->label32->TabIndex = 36;
			this->label32->Text = L"Низкая";
			// 
			// labelParamSunflower
			// 
			this->labelParamSunflower->AutoSize = true;
			this->labelParamSunflower->Location = System::Drawing::Point(491, 328);
			this->labelParamSunflower->Name = L"labelParamSunflower";
			this->labelParamSunflower->Size = System::Drawing::Size(88, 17);
			this->labelParamSunflower->TabIndex = 34;
			this->labelParamSunflower->Text = L"Дегидрация";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(917, 87);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(65, 17);
			this->label27->TabIndex = 33;
			this->label27->Text = L"Высокая";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(494, 87);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(56, 17);
			this->label28->TabIndex = 32;
			this->label28->Text = L"Низкая";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(714, 87);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(65, 17);
			this->label29->TabIndex = 31;
			this->label29->Text = L"Средняя";
			// 
			// temperatureBarSunflower
			// 
			this->temperatureBarSunflower->Location = System::Drawing::Point(494, 28);
			this->temperatureBarSunflower->Maximum = 3;
			this->temperatureBarSunflower->Minimum = 1;
			this->temperatureBarSunflower->Name = L"temperatureBarSunflower";
			this->temperatureBarSunflower->Size = System::Drawing::Size(485, 56);
			this->temperatureBarSunflower->TabIndex = 28;
			this->temperatureBarSunflower->Value = 2;
			this->temperatureBarSunflower->ValueChanged += gcnew System::EventHandler(this, &MyForm::temperatureBarSunflower_ValueChanged);
			// 
			// buttonWaterSunflower
			// 
			this->buttonWaterSunflower->Location = System::Drawing::Point(892, 585);
			this->buttonWaterSunflower->Name = L"buttonWaterSunflower";
			this->buttonWaterSunflower->Size = System::Drawing::Size(103, 38);
			this->buttonWaterSunflower->TabIndex = 21;
			this->buttonWaterSunflower->Text = L"Полить";
			this->buttonWaterSunflower->UseVisualStyleBackColor = true;
			this->buttonWaterSunflower->Click += gcnew System::EventHandler(this, &MyForm::buttonWaterSunflower_Click);
			// 
			// buttonNewSunflower
			// 
			this->buttonNewSunflower->Location = System::Drawing::Point(687, 585);
			this->buttonNewSunflower->Name = L"buttonNewSunflower";
			this->buttonNewSunflower->Size = System::Drawing::Size(177, 38);
			this->buttonNewSunflower->TabIndex = 20;
			this->buttonNewSunflower->Text = L"Найти новый цветочек";
			this->buttonNewSunflower->UseVisualStyleBackColor = true;
			this->buttonNewSunflower->Click += gcnew System::EventHandler(this, &MyForm::buttonNewSunflower_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(488, 305);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(42, 17);
			this->label12->TabIndex = 19;
			this->label12->Text = L"Зима";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(636, 305);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(48, 17);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Весна";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(791, 305);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 17);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Лето";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(927, 305);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 17);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Осень";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(494, 191);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 17);
			this->label8->TabIndex = 15;
			this->label8->Text = L"День";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(938, 191);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Ночь";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(491, 226);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 20);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Время года";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(491, 112);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 17);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Время суток";
			// 
			// seasonBarSunflower
			// 
			this->seasonBarSunflower->Location = System::Drawing::Point(494, 246);
			this->seasonBarSunflower->Maximum = 4;
			this->seasonBarSunflower->Minimum = 1;
			this->seasonBarSunflower->Name = L"seasonBarSunflower";
			this->seasonBarSunflower->Size = System::Drawing::Size(485, 56);
			this->seasonBarSunflower->TabIndex = 9;
			this->seasonBarSunflower->Value = 3;
			this->seasonBarSunflower->ValueChanged += gcnew System::EventHandler(this, &MyForm::seasonBarSunflower_ValueChanged);
			// 
			// dayTimeBarSunflower
			// 
			this->dayTimeBarSunflower->Location = System::Drawing::Point(494, 132);
			this->dayTimeBarSunflower->Maximum = 2;
			this->dayTimeBarSunflower->Minimum = 1;
			this->dayTimeBarSunflower->Name = L"dayTimeBarSunflower";
			this->dayTimeBarSunflower->Size = System::Drawing::Size(485, 56);
			this->dayTimeBarSunflower->TabIndex = 8;
			this->dayTimeBarSunflower->Value = 1;
			this->dayTimeBarSunflower->ValueChanged += gcnew System::EventHandler(this, &MyForm::dayTimeBarSunflower_ValueChanged);
			// 
			// lblw2
			// 
			this->lblw2->AutoSize = true;
			this->lblw2->Location = System::Drawing::Point(492, 62);
			this->lblw2->Name = L"lblw2";
			this->lblw2->Size = System::Drawing::Size(79, 17);
			this->lblw2->TabIndex = 5;
			this->lblw2->Text = L"Влажность";
			// 
			// lblt2
			// 
			this->lblt2->AutoSize = true;
			this->lblt2->Location = System::Drawing::Point(494, 8);
			this->lblt2->Name = L"lblt2";
			this->lblt2->Size = System::Drawing::Size(96, 17);
			this->lblt2->TabIndex = 3;
			this->lblt2->Text = L"Температура";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// can
			// 
			this->can->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"can.Image")));
			this->can->Location = System::Drawing::Point(484, 8);
			this->can->Name = L"can";
			this->can->Size = System::Drawing::Size(498, 292);
			this->can->TabIndex = 36;
			this->can->TabStop = false;
			this->can->Visible = false;
			// 
			// can2
			// 
			this->can2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"can2.Image")));
			this->can2->Location = System::Drawing::Point(484, 8);
			this->can2->Name = L"can2";
			this->can2->Size = System::Drawing::Size(498, 314);
			this->can2->TabIndex = 41;
			this->can2->TabStop = false;
			this->can2->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1033, 677);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"Flower";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->Цветок->ResumeLayout(false);
			this->Цветок->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->temperatureBarFlower))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dayTimeBarFlower))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seasonBarFlower))->EndInit();
			this->Подсолнух->ResumeLayout(false);
			this->Подсолнух->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->temperatureBarSunflower))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seasonBarSunflower))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dayTimeBarSunflower))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->can))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->can2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		// Температура
		Temperatures temperature;
		// Время суток
		TimesOfDay dayTime;
		// Время года
		Seasons season;

	protected:
		Flowers^ pinkFlower = gcnew Flowers();
		SFlower^ sunFlower = gcnew SFlower();

	public:
		// Время суток
		property TimesOfDay DayTime {
			void set(TimesOfDay dayTime) {
				this->dayTime = dayTime;
			}
			TimesOfDay get() {
				return dayTime;
			}
		}
		// Температура
		property Temperatures Temperature {
			void set(Temperatures temperature) {
				this->temperature = temperature;
			}
			Temperatures get() {
				return temperature;
			}
		}
		// Время года
		property Seasons Season {
			void set(Seasons season) {
				this->season = season;
			}
			Seasons get() {
				return season;
			}
		}

	private:
		// Переотрисовка
		void redraw(Flowers^ flower, PictureBox^ pictureBox);
		void GrowEventHandler(Flowers^ flower, GrowthStage stage);
		void DeathEventHandler(Flowers^ flower, ReasonOfDeath reason, String^ message);
		void switchImageSunFlower();
		// Загрузка формы
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
		// Смена температуры цветка
		System::Void temperatureBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		// Смена времени суток
		System::Void dayTimeBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		// Смена времени года
		System::Void seasonBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		// Тик таймера 1
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
		// Новый цветок
		System::Void buttonNewFlower_Click(System::Object^ sender, System::EventArgs^ e);
		// Полить цветок
		System::Void buttonWaterFlower_Click(System::Object^ sender, System::EventArgs^ e);
		// Смена вкладки
		System::Void tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		// Тик таймера 2
		System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e);
		// Смена температуры подсолнуха
		System::Void temperatureBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		// Смена времени суток подсолнуха
		System::Void dayTimeBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		// Смена времени года подсолнуха
		System::Void seasonBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		// Сбор семян
		System::Void buttonSeeds_Click(System::Object^ sender, System::EventArgs^ e);
		// Новый подсолнух
		System::Void buttonNewSunflower_Click(System::Object^ sender, System::EventArgs^ e);
		// Полить цветок
		System::Void buttonWaterSunflower_Click(System::Object^ sender, System::EventArgs^ e);
	};
};