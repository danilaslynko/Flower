#pragma once
#include <iostream>
#include <time.h>
#include "helperClasses.h"
#include "Environment.h"

using namespace std;
using namespace System;

ref class Flowers { // Класс-батька

public:
	delegate void DeathEventHandler(Flowers^ flower, ReasonOfDeath reason, String^ message); // Делегатик
	delegate void GrowEventHandler(Flowers^ flower, GrowthStage stage); // Делегатик для смены дня и ночи
	event DeathEventHandler^ FlowerIsDead; // Событие замерзания цветка
	event GrowEventHandler^ FlowerGrown; // Событие подрастания цветка

private:
	// Путь к картиночке
	String^ path;
	// Прогресс процесса
	int progress;
	// Шанс того, что цветок съеден
	int chance;
	// Цветочек жив
	bool alive;
	// Стадия роста цветка
	GrowthStage stage;
	// Причина смерти
	ReasonOfDeath reason;

public:
	// Таймер для роста цветуечка
	Timer^ Timer;
	//Конструктор и деструктор
	Flowers();
	~Flowers();
	// Дегидрация
	property int Progress {
		void set(int progress) {
			this->progress = progress;
		}
		int get() {
			return progress;
		}
	}
	// Причина смерти
	property ReasonOfDeath Reason {
		void set(ReasonOfDeath reason) {
			this->reason = reason;
			FlowerIsDead(
				this,
				reason,
				"Цветок умер :("
			);
		}
		ReasonOfDeath get() {
			return reason;
		}
	}
	// Картиночка
	property String^ Path {
		void set(String^ path) {
			this->path = path;
		}
		String^ get() {
			return this->path;
		}
	}
	property GrowthStage Stage {
		void set(GrowthStage stage) {
			this->stage = stage;
			FlowerGrown(
				this,
				stage
			);
		}
		GrowthStage get() {
			return stage;
		}
	}
	property bool Alive {
		void set(bool alive) {
			this->alive = alive;
		}
		bool get() {
			return alive;
		}
	}
	// Умереть
	void die(ReasonOfDeath reason);
	// Расти
	virtual void grow();
	// Реакция на смену времени года
	virtual void reactOnEnvironment(FlowerEnvironment^ env);
	virtual void OnTick(System::Object^ sender, System::EventArgs^ e);
};