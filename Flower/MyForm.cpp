#include "MyForm.h" 
#include <Windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

[STAThreadAttribute]
void Main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Flower::MyForm form;
	Application::Run(%form);
}

void Flower::MyForm::redraw(Flowers^ flower, PictureBox^ pictureBox)
{
	pictureBox->Image = Image::FromFile(flower->Path);
}

void Flower::MyForm::eventWithoutMessageHandler(Flowers^ flower, String^ path)
{
	flower->Path = path;
}

void Flower::MyForm::eventWithMessageHandler(Flowers^ flower, String^ path, String^ message)
{
	flower->Path = path;
	MessageBox::Show(this, message, "Ой", MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button1);
}

System::Void Flower::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	timer1->Enabled = true;
	timer2->Enabled = false;
	
	redraw(pinkFlower, pictureBox1);
	redraw(sunFlower, pictureBox2);

	pinkFlower->DayChange += gcnew Flowers::NoMessageHandler(this, &Flower::MyForm::eventWithoutMessageHandler);
	pinkFlower->FlowerGrown += gcnew Flowers::NoMessageHandler(this, &Flower::MyForm::eventWithoutMessageHandler);
	pinkFlower->FlowerIsDead += gcnew Flowers::LocalEventHandler(this, &Flower::MyForm::eventWithMessageHandler);
	
	sunFlower->DayChange += gcnew Flowers::NoMessageHandler(this, &Flower::MyForm::eventWithoutMessageHandler);
	sunFlower->FlowerGrown += gcnew Flowers::NoMessageHandler(this, &Flower::MyForm::eventWithoutMessageHandler);
	sunFlower->FlowerIsDead += gcnew Flowers::LocalEventHandler(this, &Flower::MyForm::eventWithMessageHandler);
	sunFlower->Seeds += gcnew Flowers::LocalEventHandler(this, &Flower::MyForm::eventWithMessageHandler);
}

System::Void Flower::MyForm::temperatureBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlower->Temperature = (Temperatures)(temperatureBarFlower->Value);
	pinkFlower->conditionCheck();
	progressBar1->Value = pinkFlower->Progress;
	
	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::dayTimeBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlower->changeTime((TimesOfDay)(dayTimeBarFlower->Value));
	pinkFlower->conditionCheck();

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::seasonBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlower->Season = (Seasons)(this->seasonBarFlower->Value);
	if (pinkFlower->Season == WINTER || pinkFlower->Season == AUTUMN) {
		this->labelParamFlower->Text = "В мертвом цветке уже ничего не изменится...";
		this->buttonNewFlower->Enabled = false;
		this->buttonWaterFlower->Enabled = false;
	}
	else {
		if (pinkFlower->Season == SUMMER) {
			this->labelParamFlower->Text = "Дегидрация";
		}
		if (pinkFlower->Season == SPRING) {
			this->labelParamFlower->Text = "Рост цветочка";
		}
		this->buttonNewFlower->Enabled = true;
		this->buttonWaterFlower->Enabled = true;
	}
	pinkFlower->findNewFlower();
	pinkFlower->conditionCheck();
	progressBar1->Value = pinkFlower->Progress;

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (pinkFlower->Alive) {
		progressBar1->Step = (int)pinkFlower->Temperature;
		if (pinkFlower->Progress < 30) {
			if (pinkFlower->Season == SUMMER) {
				pinkFlower->degidrate();
				pinkFlower->Chance = 5;
				progressBar1->Value = pinkFlower->Progress;
			}
			if (pinkFlower->Season == SPRING) {
				pinkFlower->grow();
				progressBar1->Value = pinkFlower->Progress;
			}
		}
		pinkFlower->conditionCheck();
	}

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::buttonNewFlower_Click(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlower->findNewFlower();
	pinkFlower->conditionCheck();
	progressBar1->Value = pinkFlower->Progress;

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::buttonWaterFlower_Click(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlower->water();
	pinkFlower->conditionCheck();
	progressBar1->Value = pinkFlower->Progress;

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	switch (tabControl1->SelectedIndex)
	{
	case 0:
		timer1->Enabled = true;
		timer2->Enabled = false;
		break;
	case 1:
		timer1->Enabled = false;
		timer2->Enabled = true;
		break;
	default:
		break;
	}
}

System::Void Flower::MyForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (sunFlower->Alive) {
		progressBar2->Step = (int)sunFlower->Temperature;
		if (sunFlower->Progress < 30) {
			if (sunFlower->Season == SUMMER) {
				sunFlower->degidrate();
				sunFlower->Chance = 5;
				progressBar2->Value = sunFlower->Progress;
			}
			if (sunFlower->Season == AUTUMN) {
				sunFlower->grow();
				progressBar2->Value = sunFlower->Progress;
			}
		}
		sunFlower->conditionCheck();
	}

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::temperatureBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	sunFlower->Temperature = (Temperatures)(temperatureBarSunflower->Value);
	sunFlower->conditionCheck();
	progressBar2->Value = sunFlower->Progress;

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::dayTimeBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	sunFlower->changeTime((TimesOfDay)(dayTimeBarSunflower->Value));
	sunFlower->conditionCheck();

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::seasonBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	sunFlower->Season = (Seasons)(this->seasonBarSunflower->Value);
	sunFlower->findNewFlower();
	switch (sunFlower->Season)
	{
	case WINTER:
		this->labelParamSunflower->Text = "В мертвом цветке уже ничего не изменится...";
		this->buttonNewSunflower->Enabled = false;
		this->buttonWaterSunflower->Enabled = false;
		this->buttonSeeds->Enabled = false;
		break;
	case SPRING:
		this->labelParamSunflower->Text = "Подсолнух весной не хочет ничего делать :)";
		this->buttonNewSunflower->Enabled = false;
		this->buttonWaterSunflower->Enabled = false;
		this->buttonSeeds->Enabled = false;
		break;
	case SUMMER:
		this->labelParamSunflower->Text = "Дегидрация";
		this->buttonNewSunflower->Enabled = true;
		this->buttonWaterSunflower->Enabled = true;
		this->buttonSeeds->Enabled = false;
		break;
	case AUTUMN:
		this->labelParamSunflower->Text = "Созревание семян";
		this->buttonNewSunflower->Enabled = true;
		this->buttonWaterSunflower->Enabled = true;
		this->buttonSeeds->Enabled = true;
		break;
	default:
		break;
	}
	sunFlower->conditionCheck();
	progressBar2->Value = sunFlower->Progress;

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::buttonSeeds_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sunFlower->Alive) {
		sunFlower->takeSeeds();
		sunFlower->conditionCheck();
		progressBar2->Value = sunFlower->Progress;

		redraw(sunFlower, pictureBox2);
	}
}

System::Void Flower::MyForm::buttonNewSunflower_Click(System::Object^ sender, System::EventArgs^ e)
{
	sunFlower->findNewFlower();
	sunFlower->conditionCheck();
	progressBar2->Value = sunFlower->Progress;

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::buttonWaterSunflower_Click(System::Object^ sender, System::EventArgs^ e)
{
	sunFlower->water();
	sunFlower->conditionCheck();
	progressBar2->Value = sunFlower->Progress;

	redraw(sunFlower, pictureBox2);
}
