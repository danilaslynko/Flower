#pragma once
#include "Flower.h"
ref class SFlower : public Flowers { // �������������� �����
public:
	event LocalEventHandler^ Seeds; // ������� ����� �������
	// ����������� � ����������
	SFlower();
	~SFlower();
	// ���������������� ������
	virtual void changeSeason(Seasons season) override;
	virtual void findNewFlower() override;
	virtual void changeTime(TimesOfDay dayTime) override;
	virtual void water() override;
	virtual void eat() override;
	virtual void grow() override;
	virtual void degidrate() override;
	// ����� ������
	void takeSeeds();
};

