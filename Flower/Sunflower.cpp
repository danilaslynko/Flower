#include "Sunflower.h"

SFlower::SFlower() {
	this->Progress = 0;
	this->Season = SUMMER;
	this->Temperature = FINE;
	this->DayTime = DAY;
	this->Alive = true;
	this->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerDay.png";
}

SFlower::~SFlower()
{
}

void SFlower::changeSeason(Seasons season)
{
	this->Season = season;
	switch (Season)
	{
	case WINTER:
		Alive = false;
		FlowerIsDead(
			this,
			"..\\Pictures\\Sunflower\\Winter\\SunFlowerWinterFrozen.png", "Зимой подсолнуху плохо :(");
		break;
	case SPRING:
		if (Temperature == COLD) {
			Alive = false;
			FlowerIsDead(
				this,
				"..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringFrozen.png", "Подсолнух замерз :(");
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
		if (this->Temperature == COLD) {
			Alive = false;
			FlowerIsDead(
				this,
				"..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringFrozen.png", "Подсолнух замерз :(");
		}
		if (this->DayTime == DAY) {
			this->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringDay.png";
		}
		else {
			this->Path = "..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringNight.png";
		}
		break;
	case SUMMER:
		if (this->DayTime == DAY) {
			this->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerDay.png";
		}
		else {
			this->Path = "..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerNight.png";
		}
		break;
	case AUTUMN:
		this->Path = "..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithoutSeeds.png";
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
				DayChange(
					this,
					"..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerDay.png");
			}
			if (DayTime == NIGHT) {
				DayChange(
					this,
					"..\\Pictures\\Sunflower\\Summer\\SunFlowerSummerNight.png");
			}
		}
		if (Season == SPRING) {
			if (DayTime == DAY) {
				DayChange(
					this,
					"..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringDay.png");
			}
			if (DayTime == NIGHT) {
				DayChange(
					this,
					"..\\Pictures\\Sunflower\\Spring\\SunFlowerSpringNight.png");
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

void SFlower::eat()
{
	Alive = false;
	Progress = 0;
	FlowerIsDead(
		this,
		"..\\Pictures\\Sunflower\\SunFlowerГусеничка.png",
		"Цветочек съела гусеница :(");
}

void SFlower::grow()
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
		Alive = false;
		FlowerIsDead(
			this,
			"..\\Pictures\\Sunflower\\Autumn\\SunFlowerAutumnFrozen.png",
			"Холодная нынче осень, цветочек замерз :(");
	}
	if (Progress == 30) {
		FlowerGrown(this,
			"..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithSeeds.png");
	}
}

void SFlower::degidrate()
{
	if (Progress < 30) {
		Progress += (int)Temperature;
	}
	if (Progress > 30) {
		Progress = 30;
	}
	if (Progress == 30) {
		Alive = false;
		FlowerIsDead(
			this,
			"..\\Pictures\\Sunflower\\Summer\\SunFlowerDead.png",
			"Подсолнух засох :(");
	}
}

void SFlower::takeSeeds()
{
	if (Season == AUTUMN) {
		if (Progress == 30) {
			Progress = 0;
			Seeds(
				this,
				"..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithoutSeeds.png",
				"Семечки собраны!");
		}
		else {
			Seeds(
				this,
				"..\\Pictures\\Sunflower\\Autumn\\SunFlowerWithoutSeeds.png",
				"А не рановато ли?");
		}
	}
}