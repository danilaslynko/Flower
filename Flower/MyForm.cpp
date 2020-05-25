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

void Flower::MyForm::GrowEventHandler(Flowers^ flower, GrowthStage stage)
{
	if (flower->Equals(sunFlower)) {
		switchImageSunflower();
		redraw(sunFlower, pictureBox2);
	}
	else {
		switchImagePinkFlower();
		redraw(pinkFlower, pictureBox1);
	}
}

void Flower::MyForm::DeathEventHandler(Flowers^ flower, ReasonOfDeath reason, String^ message)
{
	if (flower->Equals(sunFlower)) {
		switchImageSunflower();
		redraw(sunFlower, pictureBox2);
	}
	if (flower->Equals(pinkFlower)) {
		switchImagePinkFlower();
		redraw(pinkFlower, pictureBox1);
	}

	MessageBox::Show(this, message, "Ой", MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button1);
}

void Flower::MyForm::switchImagePinkFlower()
{
	switch (pinkFlowerEnvironment->Season)
	{
	case WINTER:
		pinkFlower->Path = "..\\Pictures\\Flower\\Winter\\FlowerFrozen.png";
		break;
	case SPRING:
		if (pinkFlower->Alive) {
			switch (pinkFlower->Stage) {
			case BIG:
				if (pinkFlowerEnvironment->DayTime == DAY) {
					pinkFlower->Path = "..\\Pictures\\Flower\\Spring\\FlowerSpringDay.png";
				}
				else {
					pinkFlower->Path = "..\\Pictures\\Flower\\Spring\\FlowerSpringNight.png";
				}
				break;
			case LITTLE:
				pinkFlower->Path = "..\\Pictures\\Flower\\Spring\\FlowerLittle.png";
				break;
			case MIDDLE:
				pinkFlower->Path = "..\\Pictures\\Flower\\Spring\\FlowerMiddle.png";
				break;
			}
		}
		else {
			pinkFlower->Path = "..\\Pictures\\Flower\\Spring\\FlowerSpringFrozen.png";
		}
		break;
	case SUMMER:
		if (pinkFlower->Alive) {
			if (pinkFlowerEnvironment->DayTime == DAY) {
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerDay.png";
			}
			else {
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerNight.png";
			}
		}
		else {
			switch (pinkFlower->Reason) {
			case WITHERED:
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerDead.png";
				break;
			case EATEN:
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerГусеничка.png";
				break;
			}
		}
		break;
	case AUTUMN:
		if (pinkFlowerEnvironment->DayTime == DAY) {
			pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerDay.png";
		}
		else {
			pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerNight.png";
		}
		if (!pinkFlower->Alive) {
			switch (pinkFlower->Reason) {
			case WITHERED:
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerDead.png";
				break;
			case FROZEN:
				pinkFlower->Path = "..\\Pictures\\Flower\\Winter\\FlowerFrozen.png";
				break;
			}
		}
		break;
	}
}

void Flower::MyForm::switchImageSunflower()
{
	switch (sunFlowerEnvironment->Season)
	{
	case WINTER:
		sunFlower->Path = "..\\Pictures\\Sunflower\\Winter\\SunFlowerWinterFrozen.png";
		break;
	case SPRING:
		if (sunFlowerEnvironment->DayTime == DAY) {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringDay.png";
		}
		else {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringNight.png";
		}
		if (!sunFlower->Alive) {
			switch (sunFlower->Reason)
			{
			case WITHERED:
				sunFlower->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerDead.png";
				break;
			case FROZEN:
				sunFlower->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringFrozen.png";
				break;
			}
		}
		break;
	case SUMMER:
		if (sunFlowerEnvironment->DayTime == DAY) {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerDay.png";
		}
		else {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerNight.png";
		}
		if (!sunFlower->Alive) {
			switch (sunFlower->Reason) {
			case WITHERED:
				sunFlower->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerDead.png";
				break;
			case EATEN:
				sunFlower->Path = "..\\Pictures\\Sunflower\\SunFlowerГусеничка.png";
				break;
			}
		}
		break;
	case AUTUMN:
		switch (sunFlower->Stage)
		{
		case BIG:
			sunFlower->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithoutSeeds.png";
			break;
		case RIPENED:
			sunFlower->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithSeeds.png";
			break;
		case HARVESTED:
			sunFlower->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithoutHead.png";
			break;
		}
		if (sunFlowerEnvironment->Temperature == COLD) {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerAutumnFrozen.png";
		}
		break;
	}
}

System::Void Flower::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlower = gcnew Flowers();
	sunFlower = gcnew SFlower();

	pinkFlowerEnvironment = gcnew FlowerEnvironment(
		(Temperatures)temperatureBarFlower->Value,
		(Seasons)seasonBarFlower->Value,
		(TimesOfDay)dayTimeBarFlower->Value
	);
	sunFlowerEnvironment = gcnew FlowerEnvironment(
		(Temperatures)temperatureBarSunflower->Value,
		(Seasons)seasonBarSunflower->Value,
		(TimesOfDay)dayTimeBarSunflower->Value
	);

	sunFlower->Timer->Enabled = false;
	pinkFlower->Timer->Enabled = true;
	pinkFlowerEnvironment->Timer->Enabled = true;
	sunFlowerEnvironment->Timer->Enabled = false;

	pinkFlower->FlowerGrown += gcnew Flowers::GrowEventHandler(this, &Flower::MyForm::GrowEventHandler);
	pinkFlower->FlowerIsDead += gcnew Flowers::DeathEventHandler(this, &Flower::MyForm::DeathEventHandler);

	sunFlower->FlowerGrown += gcnew Flowers::GrowEventHandler(this, &Flower::MyForm::GrowEventHandler);
	sunFlower->FlowerIsDead += gcnew Flowers::DeathEventHandler(this, &Flower::MyForm::DeathEventHandler);

	pinkFlowerEnvironment->DeadlyEvent += gcnew FlowerEnvironment::DeadlyEventHandler(pinkFlower, &Flowers::die);
	sunFlowerEnvironment->DeadlyEvent += gcnew FlowerEnvironment::DeadlyEventHandler(sunFlower, &SFlower::die);

	pinkFlowerEnvironment->ConditionsChanges += gcnew FlowerEnvironment::ConditionsChangedHandler(pinkFlower, &Flowers::reactOnEnvironment);
	sunFlowerEnvironment->ConditionsChanges += gcnew FlowerEnvironment::ConditionsChangedHandler(sunFlower, &SFlower::reactOnEnvironment);

	switchImagePinkFlower();
	switchImageSunflower();

	pinkFlowerEnvironment->Timer->Tick += gcnew System::EventHandler(this, &Flower::MyForm::OnTickFlower);
	sunFlowerEnvironment->Timer->Tick += gcnew System::EventHandler(this, &Flower::MyForm::OnTickSunflower);
	
	redraw(pinkFlower, pictureBox1);
	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::temperatureBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlowerEnvironment->Temperature = (Temperatures)(temperatureBarFlower->Value);
	switchImagePinkFlower();
	
	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::dayTimeBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlowerEnvironment->DayTime = (TimesOfDay)dayTimeBarFlower->Value;
	switchImagePinkFlower();

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::seasonBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->buttonNewFlower_Click(sender, e);
	if (pinkFlowerEnvironment->Season == WINTER) {
		this->labelParamFlower->Text = "В мертвом цветке уже ничего не изменится...";
		this->buttonNewFlower->Enabled = false;
		this->buttonWaterFlower->Enabled = false;
	}
	else {
		this->labelParamFlower->Text = "Дегидратация";
		this->buttonNewFlower->Enabled = true;
		this->buttonWaterFlower->Enabled = true;
	}
}

System::Void Flower::MyForm::buttonNewFlower_Click(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlower->Progress = 0;
	pinkFlower->Alive = true;
	pinkFlowerEnvironment->SoilMoisture = 30;

	pinkFlowerEnvironment->Season = (Seasons)seasonBarFlower->Value;
	progressBar1->Value = pinkFlowerEnvironment->SoilMoisture;
	switchImagePinkFlower();

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::buttonWaterFlower_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->can->Visible = true;
	pinkFlowerEnvironment->SoilMoisture += 8;
}

System::Void Flower::MyForm::tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	switch (tabControl1->SelectedIndex)
	{
	case 0:
		pinkFlower->Timer->Enabled = true;
		sunFlower->Timer->Enabled = false;
		pinkFlowerEnvironment->Timer->Enabled = true;
		sunFlowerEnvironment->Timer->Enabled = false;

		pinkFlowerEnvironment->Temperature = (Temperatures)temperatureBarFlower->Value;
		pinkFlowerEnvironment->Season = (Seasons)seasonBarFlower->Value;
		pinkFlowerEnvironment->DayTime = (TimesOfDay)dayTimeBarFlower->Value;
		break;
	case 1:
		pinkFlower->Timer->Enabled = false;
		sunFlower->Timer->Enabled = true;
		pinkFlowerEnvironment->Timer->Enabled = false;
		sunFlowerEnvironment->Timer->Enabled = true;

		sunFlowerEnvironment->Temperature = (Temperatures)temperatureBarSunflower->Value;
		sunFlowerEnvironment->Season = (Seasons)seasonBarSunflower->Value;
		sunFlowerEnvironment->DayTime = (TimesOfDay)dayTimeBarSunflower->Value;
		break;
	default:
		break;
	}
}

System::Void Flower::MyForm::temperatureBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	sunFlowerEnvironment->Temperature = (Temperatures)(temperatureBarSunflower->Value);
	switchImageSunflower();

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::dayTimeBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	sunFlowerEnvironment->DayTime = (TimesOfDay)dayTimeBarSunflower->Value;
	switchImageSunflower();

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::seasonBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->buttonNewSunflower_Click(sender, e);
	switch (sunFlowerEnvironment->Season)
	{
	case WINTER:
		this->labelParamSunflower->Text = "В мертвом цветке уже ничего не изменится...";
		this->buttonNewSunflower->Enabled = false;
		this->buttonWaterSunflower->Enabled = false;
		this->buttonSeeds->Enabled = false;
		break;
	case SPRING:
		this->labelParamSunflower->Text = "Подсолнух весной не хочет ничего делать :)";
		this->buttonNewSunflower->Enabled = true;
		this->buttonWaterSunflower->Enabled = true;
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
}

System::Void Flower::MyForm::buttonSeeds_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sunFlower->Alive) {
		if (sunFlower->Stage == RIPENED && sunFlowerEnvironment->Season == AUTUMN) {
			sunFlower->Alive = false;
			sunFlower->Stage = HARVESTED;
		}
		else {
			MessageBox::Show(
				this,
				"А не рановато ли?",
				"Вообще говоря, действительно рано",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1);
		}

		redraw(sunFlower, pictureBox2);
	}
	else {
		MessageBox::Show(
			this,
			"Цветок мертв, собирать нечего",
			"Печально, но...",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information,
			MessageBoxDefaultButton::Button1);
	}
}

System::Void Flower::MyForm::buttonNewSunflower_Click(System::Object^ sender, System::EventArgs^ e)
{
	sunFlower->Progress = 0;
	sunFlower->Alive = true;
	sunFlowerEnvironment->SoilMoisture = 30;

	progressBar2->Value = sunFlowerEnvironment->SoilMoisture;
	sunFlowerEnvironment->Season = (Seasons)seasonBarSunflower->Value;
	switchImageSunflower();

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::buttonWaterSunflower_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->can2->Visible = true;
	sunFlowerEnvironment->SoilMoisture += 8;
}

void Flower::MyForm::OnTickSunflower(System::Object^ sender, System::EventArgs^ e)
{
	this->can2->Visible = false;
	if (sunFlowerEnvironment->SoilMoisture >= 0)
	progressBar2->Value = sunFlowerEnvironment->SoilMoisture;
}

void Flower::MyForm::OnTickFlower(System::Object^ sender, System::EventArgs^ e)
{
	this->can->Visible = false;
	if (pinkFlowerEnvironment->SoilMoisture >= 0)
	progressBar1->Value = pinkFlowerEnvironment->SoilMoisture;
}
