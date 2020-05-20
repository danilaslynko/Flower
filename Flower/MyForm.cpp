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
	switch (stage)
	{
	// Блок для цветуечка
	case LITTLE:
		flower->Path = "..\\Pictures\\Flower\\Spring\\FlowerLittle.png";
		break;
	case MIDDLE:
		flower->Path = "..\\Pictures\\Flower\\Spring\\FlowerMiddle.png";
		break;
	case BIG:
		if (DayTime == DAY) {
			flower->Path = "..\\Pictures\\Flower\\Spring\\FlowerSpringDay.png";
		}
		else {
			flower->Path = "..\\Pictures\\Flower\\Spring\\FlowerSpringNight.png";
		}
		break;
	// Блок для подсолнуха
	case RIPENED:
		flower->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithSeeds.png";
		break;
	case HARVESTED:
		flower->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithoutHead.png";
		break;
	default:
		break;
	}
}

void Flower::MyForm::DeathEventHandler(Flowers^ flower, ReasonOfDeath reason, String^ message)
{
	flower->Alive = false;
	flower->Progress = 0;
	if (flower->Equals(pinkFlower)) {
		switch (reason)
		{
		case FROZEN:
			switch (Season) {
			case SPRING:
				flower->Path = "..\\Pictures\\Flower\\Spring\\FlowerSpringFrozen.png";
				break;
			default:
				flower->Path = "..\\Pictures\\Flower\\Winter\\FlowerFrozen.png";
				break;
			}
			break;
		case EATEN:
			flower->Path = "..\\Pictures\\Flower\\Summer\\FlowerГусеничка.png";
			break;
		case WITHERED:
			flower->Path = "..\\Pictures\\Flower\\Summer\\FlowerDead.png";
			break;
		default:
			break;
		}
	}
	if (flower->Equals(sunFlower)) {
		switch (reason)
		{
		case FROZEN:
			switch (Season)
			{
			case WINTER:
				flower->Path = "..\\Pictures\\Sunflower\\Winter\\SunFlowerWinterFrozen.png";
				break;
			case SPRING:
				flower->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringFrozen.png";
				break;
			case AUTUMN:
				flower->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerAutumnFrozen.png";
				break;
			default:
				break;
			}
			break;
		case EATEN:
			flower->Path = "..\\Pictures\\Sunflower\\SunFlowerГусеничка.png";
			break;
		case WITHERED:
			flower->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerDead.png";
			break;
		default:
			break;
		}
	}
	MessageBox::Show(this, message, "Ой", MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button1);
}

void Flower::MyForm::switchImageSunFlower()
{
	switch (Season) {
	case SPRING:
		if (DayTime == DAY) {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringDay.png";
		}
		else {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringNight.png";
		}
		break;
	case SUMMER:
		if (DayTime == DAY) {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerDay.png";
		}
		else {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerNight.png";
		}
		break;
	case AUTUMN:
		if (DayTime == DAY) {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithoutSeeds.png";
		}
		else {
			sunFlower->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerNight.png";
		}
		break;
	}
}

System::Void Flower::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	timer1->Enabled = true;
	timer2->Enabled = false;

	Temperature = (Temperatures)temperatureBarFlower->Value;
	Season = (Seasons)seasonBarFlower->Value;
	DayTime = (TimesOfDay)dayTimeBarFlower->Value;

	pinkFlower->FlowerGrown += gcnew Flowers::GrowEventHandler(this, &Flower::MyForm::GrowEventHandler);
	pinkFlower->FlowerIsDead += gcnew Flowers::DeathEventHandler(this, &Flower::MyForm::DeathEventHandler);

	sunFlower->FlowerGrown += gcnew Flowers::GrowEventHandler(this, &Flower::MyForm::GrowEventHandler);
	sunFlower->FlowerIsDead += gcnew Flowers::DeathEventHandler(this, &Flower::MyForm::DeathEventHandler);

	pinkFlower->reactOnEnvironment(Season, Temperature);
	sunFlower->reactOnEnvironment(Season, Temperature);

	if (Season == SUMMER) {
		if (pinkFlower->Alive) {
			if (DayTime == DAY) {
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerDay.png";
			}
			else {
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerNight.png";
			}
		}
		if (sunFlower->Alive) {
			switchImageSunFlower();
		}
	}
	
	redraw(pinkFlower, pictureBox1);
	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::temperatureBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->Temperature = (Temperatures)(temperatureBarFlower->Value);
	pinkFlower->reactOnEnvironment(Season, Temperature);
	progressBar1->Value = pinkFlower->Progress;
	
	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::dayTimeBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->DayTime = (TimesOfDay)dayTimeBarFlower->Value;
	if (pinkFlower->Alive) {
		if (Season == SUMMER) {
			if (DayTime == DAY) {
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerDay.png";
			}
			if (DayTime == NIGHT) {
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerNight.png";
			}
		}
		if (Season == SPRING && pinkFlower->Progress == 30) {
			if (DayTime == DAY) {
				pinkFlower->Path = "..\\Pictures\\Flower\\Spring\\FlowerSpringDay.png";
			}
			if (DayTime == NIGHT) {
				pinkFlower->Path = "..\\Pictures\\Flower\\Spring\\FlowerSpringNight.png";
			}
		}
	}

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::seasonBarFlower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->Season = (Seasons)this->seasonBarFlower->Value;
	if (this->Season == WINTER || this->Season == AUTUMN) {
		this->labelParamFlower->Text = "В мертвом цветке уже ничего не изменится...";
		this->buttonNewFlower->Enabled = false;
		this->buttonWaterFlower->Enabled = false;
	}
	else {
		if (this->Season == SUMMER) {
			this->labelParamFlower->Text = "Дегидратация";
		}
		if (this->Season == SPRING) {
			this->labelParamFlower->Text = "Рост цветочка";
		}
		this->buttonNewFlower->Enabled = true;
		this->buttonWaterFlower->Enabled = true;
	}
	this->buttonNewFlower_Click(sender, e);
}

System::Void Flower::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	can->Visible = false;
	if (pinkFlower->Alive) {
		progressBar1->Step = (int)this->Temperature;
		if (pinkFlower->Progress < 30) {
			if (this->Season == SUMMER) {
				pinkFlower->degidrate(Temperature);
				pinkFlower->Chance = 5;
				progressBar1->Value = pinkFlower->Progress;
			}
			if (this->Season == SPRING) {
				pinkFlower->grow(Temperature);
				progressBar1->Value = pinkFlower->Progress;
			}
		}
	}

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::buttonNewFlower_Click(System::Object^ sender, System::EventArgs^ e)
{
	pinkFlower = gcnew Flowers();

	pinkFlower->FlowerGrown += gcnew Flowers::GrowEventHandler(this, &Flower::MyForm::GrowEventHandler);
	pinkFlower->FlowerIsDead += gcnew Flowers::DeathEventHandler(this, &Flower::MyForm::DeathEventHandler);
	pinkFlower->reactOnEnvironment(Season, Temperature);

	if (Season == SUMMER) {
		if (pinkFlower->Alive) {
			if (DayTime == DAY) {
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerDay.png";
			}
			else {
				pinkFlower->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerNight.png";
			}
		}
	}

	progressBar1->Value = pinkFlower->Progress;

	redraw(pinkFlower, pictureBox1);
}

System::Void Flower::MyForm::buttonWaterFlower_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (Season == SUMMER && pinkFlower->Alive) {
		can->Visible = true;
		pinkFlower->Progress = 0;
	}
	if (Season == SPRING && pinkFlower->Alive) {
		can->Visible = true;
		pinkFlower->grow(Temperature);
	}
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

		Temperature = (Temperatures)temperatureBarFlower->Value;
		Season = (Seasons)seasonBarFlower->Value;
		DayTime = (TimesOfDay)dayTimeBarFlower->Value;
		break;
	case 1:
		timer1->Enabled = false;
		timer2->Enabled = true;

		Temperature = (Temperatures)temperatureBarSunflower->Value;
		Season = (Seasons)seasonBarSunflower->Value;
		DayTime = (TimesOfDay)dayTimeBarSunflower->Value;
		break;
	default:
		break;
	}
}

System::Void Flower::MyForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e)
{
	can2->Visible = false;
	if (sunFlower->Alive) {
		progressBar2->Step = (int)this->Temperature;
		if (sunFlower->Progress < 30) {
			if (this->Season == SUMMER) {
				sunFlower->degidrate(Temperature);
				sunFlower->Chance = 5;
				progressBar2->Value = sunFlower->Progress;
			}
			if (this->Season == AUTUMN) {
				sunFlower->grow(Temperature);
				progressBar2->Value = sunFlower->Progress;
			}
		}
	}

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::temperatureBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->Temperature = (Temperatures)(temperatureBarSunflower->Value);
	sunFlower->reactOnEnvironment(Season, Temperature);
	progressBar2->Value = sunFlower->Progress;

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::dayTimeBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->DayTime = (TimesOfDay)dayTimeBarSunflower->Value;
	switchImageSunFlower();

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::seasonBarSunflower_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->Season = (Seasons)this->seasonBarSunflower->Value;
	switch (this->Season)
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
	this->buttonNewSunflower_Click(sender, e);
	progressBar2->Value = sunFlower->Progress;

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::buttonSeeds_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sunFlower->Alive) {
		if (sunFlower->Progress == 30 && Season == AUTUMN) {
			sunFlower->Alive = false;
			this->GrowEventHandler(sunFlower, HARVESTED);
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
		progressBar2->Value = sunFlower->Progress;

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
	sunFlower = gcnew SFlower();
	sunFlower->FlowerGrown += gcnew Flowers::GrowEventHandler(this, &Flower::MyForm::GrowEventHandler);
	sunFlower->FlowerIsDead += gcnew Flowers::DeathEventHandler(this, &Flower::MyForm::DeathEventHandler);

	sunFlower->reactOnEnvironment(Season, Temperature);

	if (sunFlower->Alive) {
		switchImageSunFlower();
	}
	progressBar2->Value = sunFlower->Progress;

	redraw(sunFlower, pictureBox2);
}

System::Void Flower::MyForm::buttonWaterSunflower_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (Season == SUMMER && sunFlower->Alive) {
		can2->Visible = true;
		sunFlower->Progress = 0;
	}
	if (Season == AUTUMN && sunFlower->Alive) {
		can2->Visible = true;
		sunFlower->grow(Temperature);
	}
	progressBar2->Value = sunFlower->Progress;

	redraw(sunFlower, pictureBox2);
}
