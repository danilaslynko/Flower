#include "Sunflower.h"

SFlower::SFlower() {
	this->Progress::set(0);
	this->Season::set(SUMMER);
	this->Temperature::set(FINE);
	this->DayTime::set(DAY);
	this->Alive::set(true);
	this->Path::set("C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Summer\\Day.png");
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
		FlowerIsDead(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Winter\\Frozen.png", "Зимой подсолнуху плохо :(");
		break;
	case SPRING:
		if (Temperature == COLD) {
			Alive = false;
			FlowerIsDead(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Spring\\Frozen.png", "Подсолнух замерз :(");
		}
		break;
	case SUMMER:
		if (Progress == 30) {
			Alive = false;
			FlowerIsDead(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Summer\\Dead.png", "Подсолнух засох :(");
		}
		break;
	case AUTUMN:
		if (Temperature == COLD) {
			Alive = false;
			FlowerIsDead(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Autumn\\Frozen.png", "Холодная нынче осень, цветочек замерз :(");
		}
		else {
			if (Progress == 30) {
				FlowerGrown(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Autumn\\WSeeds.png");
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
			this->Path = "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Spring\\Day.png";
		}
		else {
			this->Path = "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Spring\\Night.png";
		}
		break;
	case SUMMER:
		if (this->DayTime == DAY) {
			this->Path = "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Summer\\Day.png";
		}
		else {
			this->Path = "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Summer\\Night.png";
		}
		break;
	case AUTUMN:
		this->Path = "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Autumn\\WSeeds.png";
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
				DayChange(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Summer\\Day.png");
			}
			if (DayTime == NIGHT) {
				DayChange(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Summer\\Night.png");
			}
		}
		if (Season == SPRING) {
			if (DayTime == DAY) {
				DayChange(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Spring\\Day.png");
			}
			if (DayTime == NIGHT) {
				DayChange(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Spring\\Night.png");
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
		Seeds(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Autumn\\WSeeds.png", "Семечки собраны!");
	}
	else {
		Seeds(this, "C:\\Users\\Вдаделец\\Pictures\\Sunflower\\Autumn\\WSeeds.png", "А не рановато ли?");
	}
}
