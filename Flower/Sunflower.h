#pragma once
#include "Flower.h"
ref class SFlower : public Flowers { // Унаследованный класс
public:
	// Конструктор и деструктор
	SFlower();
	~SFlower();
	// Переопределенные методы
	virtual void reactOnEnvironment(Seasons season, Temperatures temperature) override;
	virtual void grow(Temperatures temperature) override;
};

