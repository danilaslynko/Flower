#pragma once
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
using namespace System;

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
	delegate void LocalEventHandler(Flowers^ flower, String^ path, String^ message); // Делегатик
	delegate void NoMessageHandler(Flowers^ flower, String^ path); // Делегатик для смены дня и ночи
	event LocalEventHandler^ FlowerIsDead; // Событие замерзания цветка
	event NoMessageHandler^ DayChange; // Событие смены дня и ночи
	event NoMessageHandler^ FlowerGrown; // Событие подрастания цветка

private:
	//Путь к картиночке
	String^ path;
	// Прогресс процесса
	int progress;
	// Температура
	Temperatures temperature;
	// Время суток
	TimesOfDay dayTime;
	// Время года
	Seasons season;
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
	// Время суток
	property TimesOfDay DayTime {
		void set(TimesOfDay dayTime) {
			this->dayTime = dayTime;
		}
		TimesOfDay get() {
			return dayTime;
		}
	}
	// Температура
	property Temperatures Temperature {
		void set(Temperatures temperature) {
			this->temperature = temperature;
		}
		Temperatures get() {
			return temperature;
		}
	}
	// Время года
	property Seasons Season {
		void set(Seasons season) {
			this->season = season;
		}
		Seasons get() {
			return season;
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
	// Полить
	virtual void water();
	// Найти новый цветочек
	virtual void findNewFlower();
	// Съедание гусеницей
	virtual void eat();
	// Дегидрация
	void degidrate();
	// Расти
	void grow();
	// Смена времени суток
	virtual void changeTime(TimesOfDay dayTime);
	// Информация о цветочке
	virtual void conditionCheck();
};