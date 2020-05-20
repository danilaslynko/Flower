#pragma once
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
using namespace System;

enum GrowthStage : byte {
	MIDDLE = 1,
	BIG = 2,
	RIPENED = 3,
	HARVESTED = 4,
	LITTLE = 5
};

enum ReasonOfDeath : byte {
	FROZEN = 1,
	EATEN = 2,
	WITHERED = 3
};

enum Seasons : byte {
	WINTER = 1,
	SPRING = 2,
	SUMMER = 3,
	AUTUMN = 4
};

enum TimesOfDay : byte {
	DAY = 1,
	NIGHT = 2
};

enum Temperatures : byte {
	COLD = 1,
	FINE = 2,
	HOT = 3
};

ref class Flowers { // Класс-батька

public:
	delegate void DeathEventHandler(Flowers^ flower, ReasonOfDeath reason, String^ message); // Делегатик
	delegate void GrowEventHandler(Flowers^ flower, GrowthStage stage); // Делегатик для смены дня и ночи
	event DeathEventHandler^ FlowerIsDead; // Событие замерзания цветка
	event GrowEventHandler^ FlowerGrown; // Событие подрастания цветка

private:
	//Путь к картиночке
	String^ path;
	// Прогресс процесса
	int progress;
	// Шанс того, что цветок съеден
	int chance;
	// Цветочек жив
	bool alive;

public:
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
	// Картиночка
	property String^ Path {
		void set(String^ path) {
			this->path = path;
		}
		String^ get() {
			return this->path;
		}
	}
	// Шанс того, что цветок сожрали. Реализован через рандом.
	// Передаваемый параметр от 0 до 100 (шанс сжирания).
	property int Chance {
		void set(int treshold) {
			Random^ rnd = gcnew Random();
			this->chance = rnd->Next(0, 100);
			if (this->chance < treshold) {
				this->eat();
			}
		}
		int get() {
			return chance;
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
	// Съедание гусеницей
	void eat();
	// Дегидрация
	void degidrate(Temperatures temperature);
	// Расти
	virtual void grow(Temperatures temperature);
	// Реакция на смену времени года
	virtual void reactOnEnvironment(Seasons season, Temperatures temperature);
};