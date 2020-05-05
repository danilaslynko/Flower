#pragma once
#include "Flower.h"
ref class SFlower : public Flowers { // Унаследованный класс
public:
	event LocalEventHandler^ Seeds; // Событие сбора семечек
	// Конструктор и деструктор
	SFlower();
	~SFlower();
	// Переопределенные методы
	virtual void changeSeason(Seasons season) override;
	virtual void findNewFlower() override;
	virtual void changeTime(TimesOfDay dayTime) override;
	virtual void water() override;
	virtual void eat() override;
	virtual void grow() override;
	virtual void degidrate() override;
	// Новые методы
	void takeSeeds();
};

