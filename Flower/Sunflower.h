#pragma once
#include "Flower.h"
ref class SFlower : public Flowers { // Унаследованный класс
public:
	event LocalEventHandler^ Seeds; // Событие сбора семечек
	// Конструктор и деструктор
	SFlower();
	~SFlower();
	// Переопределенные методы
	virtual void conditionCheck() override;
	virtual void findNewFlower() override;
	virtual void changeTime(TimesOfDay dayTime) override;
	virtual void water() override;
	virtual void eat() override;
	// Новые методы
	void takeSeeds();
};

