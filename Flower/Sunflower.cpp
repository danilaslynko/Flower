#include "Sunflower.h"

SFlower::SFlower() {
	this->Progress = 0;
	this->Alive = true;
}

SFlower::~SFlower()
{
}

void SFlower::reactOnEnvironment(Seasons season, Temperatures temperature)
{
	switch (season)
	{
	case WINTER:
		FlowerIsDead(
			this,
			FROZEN,
			"����� ���������� ����� :(");
		break;
	case SPRING:
		if (temperature == COLD) {
			FlowerIsDead(
				this,
				FROZEN,
				"��������� ������ :(");
		}
		break;
	case AUTUMN:
		if (temperature == COLD) {
			FlowerIsDead(
				this,
				FROZEN,
				"��������� ������ :("
			);
		}
	default:
		break;
	}
}

void SFlower::grow(Temperatures temperature)
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
			"�������� ����� �����, ��������� ������ :(");
	}
	if (Progress == 30) {
		FlowerGrown(
			this,
			RIPENED);
	}
}