#include "Flower.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/*������������..*/
Flowers::Flowers() {
	this->Progress = 0;
	this->Alive = true;
}

/*.. � �����������*/
Flowers::~Flowers()
{
}

/*������..*/
void Flowers::eat()
{
	FlowerIsDead(
		this,
		EATEN,
		"�������� ����� �������� :(");
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
			"�������� ����� :(");
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
			"�������� ������ :(");
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
			"����� ����� �� ������");
		break;
	case AUTUMN:
		if (temperature == COLD) {
			FlowerIsDead(
				this,
				FROZEN,
				"�������� ����� �����, �������� ������ :(");
		}
		else {
			FlowerIsDead(
				this,
				WITHERED,
				"������ ����� ��������");
		}
		break;
	default:
		break;
	}
}
/*.. � ��� � ����*/