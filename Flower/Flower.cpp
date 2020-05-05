#include "Flower.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/*Конструкторы..*/
Flowers::Flowers() {
	this->progress = 0;
	this->season = SUMMER;
	this->temperature = FINE;
	this->dayTime = DAY;
	this->alive = true;
	this->path = "..\\Pictures\\Flower\\Summer\\FlowerSummerDay.png";
}

Flowers::~Flowers()
{
}
/*.. и деструкторы*/

/*методы..*/
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
		this->Path = "..\\Pictures\\Flower\\Spring\\FlowerLittle.png";
		break;
	case SUMMER:
		if (DayTime == DAY) {
			this->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerDay.png";
		}
		if (DayTime == NIGHT) {
			this->Path = "..\\Pictures\\Flower\\Summer\\FlowerSummerNight.png";
		}
		break;
	default:
		break;
	}
}

void Flowers::eat()
{
	Alive = false;
	Progress = 0;
	FlowerIsDead(
		this,
		"..\\Pictures\\Flower\\Summer\\FlowerГусеничка.png",
		"Цветочек съела гусеница :(");
}

void Flowers::degidrate()
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
			"..\\Pictures\\Flower\\Summer\\FlowerDead.png", "Цветочек засох :(");
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
		Alive = false;
		FlowerIsDead(
			this,
			"..\\Pictures\\Flower\\Spring\\FlowerSpringFrozen.png",
			"Цветочек замерз :(");
	}
	if (Progress == 18) {
		FlowerGrown(
			this,
			"..\\Pictures\\Flower\\Spring\\FlowerMiddle.png");
	}
	if (Progress == 30 && DayTime == DAY) {
		FlowerGrown(
			this,
			"..\\Pictures\\Flower\\Spring\\FlowerSpringDay.png");
	}
	if (Progress == 30 && DayTime == NIGHT) {
		FlowerGrown(
			this,
			"..\\Pictures\\Flower\\Spring\\FlowerSpringNight.png");
	}
}

void Flowers::changeTime(TimesOfDay dayTime)
{
	if (this->Alive) {
		this->DayTime = dayTime;
		if (Season == SUMMER) {
			if (DayTime == DAY) {
				DayChange(
					this,
					"..\\Pictures\\Flower\\Summer\\FlowerSummerDay.png");
			}
			if (DayTime == NIGHT) {
				DayChange(
					this,
					"C..\\Pictures\\Flower\\Summer\\FlowerSummerNight.png");
			}
		}
		if (Season == SPRING && Progress == 30) {
			if (DayTime == DAY) {
				DayChange(
					this,
					"..\\Pictures\\Flower\\Spring\\FlowerSpringDay.png");
			}
			if (DayTime == NIGHT) {
				DayChange(
					this,
					"..\\Pictures\\Flower\\Spring\\FlowerSpringNight.png");
			}
		}
	}
}

void Flowers::changeSeason(Seasons season)
{
	this->Season = season;
	switch (Season)
	{
	case WINTER:
		Alive = false;
		FlowerIsDead(
			this,
			"..\\Pictures\\Flower\\Winter\\FlowerFrozen.png",
			"Зимой цветы не растут");
		break;
	case AUTUMN:
		Alive = false;
		if (Temperature == COLD) {
			FlowerIsDead(
				this,
				"..\\Pictures\\Flower\\Winter\\FlowerFrozen.png",
				"Холодная нынче осень, цветочек замерз :(");
		}
		else {
			FlowerIsDead(
				this,
				"..\\Pictures\\Flower\\Summer\\FlowerDead.png",
				"Осенью цветы засыхают");
		}
		break;
	default:
		break;
	}
}
/*.. и иже с ними*/