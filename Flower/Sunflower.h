#pragma once
#include "Flower.h"
ref class SFlower : public Flowers { // �������������� �����
public:
	event LocalEventHandler^ Seeds; // ������� ����� �������
	// ����������� � ����������
	SFlower();
	~SFlower();
	// ���������������� ������
	virtual void conditionCheck() override;
	virtual void findNewFlower() override;
	virtual void changeTime(TimesOfDay dayTime) override;
	virtual void water() override;
	virtual void eat() override;
	// ����� ������
	void takeSeeds();
};

