#include "Flower.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/*������������..*/
Flowers::Flowers() {
	this->progress = 0;
	this->season = SUMMER;
	this->temperature = FINE;
	this->dayTime = DAY;
	this->alive = true;
	this->path = "C:\\Users\\��������\\Pictures\\Flower\\Summer\\Day.png";
}

Flowers::~Flowers()
{
}
/*.. � �����������*/

/*������..*/
void Flowers::water()
{
	if (Season == SUMMER) {
		this->Progress = 0;
	}
	if (Season == SPRING) {
		this->grow();
	}
}

void Flowers::findNewFlower()
{
	this->progress = 0;
	this->alive = true;
	this->chance = 0;
	switch (Season)
	{
	case SPRING:
		this->Path = "C:\\Users\\��������\\Pictures\\Flower\\Spring\\Little.png";
		break;
	case SUMMER:
		if (DayTime == DAY) {
			this->Path = "C:\\Users\\��������\\Pictures\\Flower\\Summer\\Day.png";
		}
		if (DayTime == NIGHT) {
			this->Path = "C:\\Users\\��������\\Pictures\\Flower\\Summer\\Night.png";
		}
		break;
	default:
		break;
	}
}

void Flowers::degidrate()
{
	if (Progress < 30) {
		Progress += (int)Temperature;
	}
	if (Progress > 30) {
		Progress = 30;
	}
}

void Flowers::grow()
{
	if (Temperature != COLD) {
		if (Progress < 30) {
			Progress += (int)Temperature;
		}
		if (Progress > 30) {
			Progress = 30;
		}
	}
	else {
		Progress = 0;
	}
}

void Flowers::changeTime(TimesOfDay dayTime)
{
	if (this->Alive) {
		this->DayTime = dayTime;
		if (Season == SUMMER) {
			if (DayTime == DAY) {
				DayChange(this, "C:\\Users\\��������\\Pictures\\Flower\\Summer\\Day.png");
			}
			if (DayTime == NIGHT) {
				DayChange(this, "C:\\Users\\��������\\Pictures\\Flower\\Summer\\Night.png");
			}
		}
		if (Season == SPRING && Progress == 30) {
			if (DayTime == DAY) {
				DayChange(this, "C:\\Users\\��������\\Pictures\\Flower\\Spring\\Day.png");
			}
			if (DayTime == NIGHT) {
				DayChange(this, "C:\\Users\\��������\\Pictures\\Flower\\Spring\\Night.png");
			}
		}
	}
}

void Flowers::conditionCheck()
{
	switch (Season)
	{
	case WINTER:
		Alive = false;
		FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Flower\\Winter\\Frozen.png", "����� ����� �� ������");
		break;
	case SPRING:
		if (Progress == 18) {
			FlowerGrown(this, "C:\\Users\\��������\\Pictures\\Flower\\Spring\\Middle.png");
		}
		if (Progress == 30 && DayTime == DAY) {
			FlowerGrown(this, "C:\\Users\\��������\\Pictures\\Flower\\Spring\\Day.png");
		} 
		if (Progress == 30 && DayTime == NIGHT) {
			FlowerGrown(this, "C:\\Users\\��������\\Pictures\\Flower\\Spring\\Night.png");
		}
		if (Temperature == COLD) {
			Alive = false;
			FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Flower\\Spring\\Frozen.png", "�������� ������ :(");
		}
		break;
	case SUMMER:
		if (Progress == 30) {
			Alive = false;
			FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Flower\\Summer\\Dead.png", "�������� ����� :(");
		}
		break;
	case AUTUMN:
		Alive = false;
		if (Temperature == COLD) {
			FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Flower\\Autumn\\Frozen.png", "�������� ����� �����, �������� ������ :(");
		}
		else {
			FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Flower\\Autumn\\Dead.png", "������ ����� ��������");
		}
		break;
	default:
		break;
	}
}
/*.. � ��� � ����*/