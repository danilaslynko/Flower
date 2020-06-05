#pragma once
#include "Flower.h"
ref class SFlower : public Flowers { // Унаследованный класс
public:
	// Конструктор и деструктор
	SFlower(FlowerEnvironment^ env);
	~SFlower();
	// Переопределенные методы
	virtual void reactOnEnvironment(FlowerEnvironment^ env) override;
	virtual void grow() override;
	virtual void OnTick(System::Object^ sender, System::EventArgs^ e) override;
};