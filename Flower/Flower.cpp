#include "Flower.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/*Конструкторы..*/
Flowers::Flowers() {
	this->Progress = 0;
	this->Alive = true;
}

/*.. и деструкторы*/
Flowers::~Flowers()
{
}

/*методы..*/
void Flowers::eat()
{
	FlowerIsDead(
		this,
		EATEN,
		"Цветочек съела гусеница :(");
}

void Flowers::degidrate(Temperatures temperature)
{
	if (Progress < 30) {
		Progress += (int)temperature;
	}
	if (Progress > 30) {
		Progress = 30;
	}
	if (Progress == 30) {
		FlowerIsDead(
			this,
			WITHERED,
			"Цветочек засох :(");
	}
}

void Flowers::grow(Temperatures temperature)
{
	if (temperature != COLD) {
		if (Progress < 30) {
			Progress += (int)temperature;
		}
		if (Progress > 30) {
			Progress = 30;
		}
	}
	else {
		FlowerIsDead(
			this,
			FROZEN,
			"Цветочек замерз :(");
	}
	if (Progress == 18) {
		FlowerGrown(
			this,
			MIDDLE);
	}
	if (Progress == 30) {
		FlowerGrown(
			this,
			BIG);
	}
}

void Flowers::reactOnEnvironment(Seasons season, Temperatures temperature)
{
	switch (season)
	{
	case SPRING:
		FlowerGrown(
			this,
			LITTLE);
		break;
	case WINTER:
		FlowerIsDead(
			this,
			FROZEN,
			"Зимой цветы не растут");
		break;
	case AUTUMN:
		if (temperature == COLD) {
			FlowerIsDead(
				this,
				FROZEN,
				"Холодная нынче осень, цветочек замерз :(");
		}
		else {
			FlowerIsDead(
				this,
				WITHERED,
				"Осенью цветы засыхают");
		}
		break;
	default:
		break;
	}
}
/*.. и иже с ними*/