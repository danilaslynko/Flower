#include "Sunflower.h"

SFlower::SFlower() {
	this->Progress::set(0);
	this->Season::set(SUMMER);
	this->Temperature::set(FINE);
	this->DayTime::set(DAY);
	this->Alive::set(true);
	this->Path::set("C:\\Users\\��������\\Pictures\\Sunflower\\Summer\\Day.png");
}

SFlower::~SFlower()
{
}

void SFlower::conditionCheck()
{
	switch (Season)
	{
	case WINTER:
		Alive = false;
		FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Winter\\Frozen.png", "����� ���������� ����� :(");
		break;
	case SPRING:
		if (Temperature == COLD) {
			Alive = false;
			FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Spring\\Frozen.png", "��������� ������ :(");
		}
		break;
	case SUMMER:
		if (Progress == 30) {
			Alive = false;
			FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Summer\\Dead.png", "��������� ����� :(");
		}
		break;
	case AUTUMN:
		if (Temperature == COLD) {
			Alive = false;
			FlowerIsDead(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Autumn\\Frozen.png", "�������� ����� �����, �������� ������ :(");
		}
		else {
			if (Progress == 30) {
				FlowerGrown(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Autumn\\WSeeds.png");
			}
		}
		break;
	default:
		break;
	}
}
void SFlower::findNewFlower()
{
	this->Progress = 0;
	this->Alive = true;
	switch (Season)
	{
	case SPRING:
		if (this->DayTime == DAY) {
			this->Path = "C:\\Users\\��������\\Pictures\\Sunflower\\Spring\\Day.png";
		}
		else {
			this->Path = "C:\\Users\\��������\\Pictures\\Sunflower\\Spring\\Night.png";
		}
		break;
	case SUMMER:
		if (this->DayTime == DAY) {
			this->Path = "C:\\Users\\��������\\Pictures\\Sunflower\\Summer\\Day.png";
		}
		else {
			this->Path = "C:\\Users\\��������\\Pictures\\Sunflower\\Summer\\Night.png";
		}
		break;
	case AUTUMN:
		this->Path = "C:\\Users\\��������\\Pictures\\Sunflower\\Autumn\\WSeeds.png";
		break;
	default:
		break;
	}
}

void SFlower::changeTime(TimesOfDay dayTime)
{
	if (this->Alive) {
		this->DayTime = dayTime;
		if (Season == SUMMER) {
			if (DayTime == DAY) {
				DayChange(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Summer\\Day.png");
			}
			if (DayTime == NIGHT) {
				DayChange(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Summer\\Night.png");
			}
		}
		if (Season == SPRING) {
			if (DayTime == DAY) {
				DayChange(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Spring\\Day.png");
			}
			if (DayTime == NIGHT) {
				DayChange(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Spring\\Night.png");
			}
		}
	}
}

void SFlower::water()
{
	if (Season == SUMMER) {
		this->Progress = 0;
	}
	if (Season == AUTUMN) {
		this->grow();
	}
}

void SFlower::takeSeeds()
{
	if (Progress == 30) {
		Progress = 0;
		Seeds(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Autumn\\WSeeds.png", "������� �������!");
	}
	else {
		Seeds(this, "C:\\Users\\��������\\Pictures\\Sunflower\\Autumn\\WSeeds.png", "� �� �������� ��?");
	}
}
