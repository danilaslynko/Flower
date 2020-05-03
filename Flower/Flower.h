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

ref class Flowers { // �����-������

public:
	delegate void LocalEventHandler(Flowers^ flower, String^ path, String^ message); // ���������
	delegate void NoMessageHandler(Flowers^ flower, String^ path); // ��������� ��� ����� ��� � ����
	event LocalEventHandler^ FlowerIsDead; // ������� ���������� ������
	event NoMessageHandler^ DayChange; // ������� ����� ��� � ����
	event NoMessageHandler^ FlowerGrown; // ������� ����������� ������

private:
	//���� � ����������
	String^ path;
	// �������� ��������
	int progress;
	// �����������
	Temperatures temperature;
	// ����� �����
	TimesOfDay dayTime;
	// ����� ����
	Seasons season;
	// ���� ����, ��� ������ ������
	int chance;
	// �������� ���
	bool alive;

public:
	//����������� � ����������
	Flowers();
	~Flowers();
	// ����������
	property int Progress {
		void set(int progress) {
			this->progress = progress;
		}
		int get() {
			return progress;
		}
	}
	// ����� �����
	property TimesOfDay DayTime {
		void set(TimesOfDay dayTime) {
			this->dayTime = dayTime;
		}
		TimesOfDay get() {
			return dayTime;
		}
	}
	// �����������
	property Temperatures Temperature {
		void set(Temperatures temperature) {
			this->temperature = temperature;
		}
		Temperatures get() {
			return temperature;
		}
	}
	// ����� ����
	property Seasons Season {
		void set(Seasons season) {
			this->season = season;
		}
		Seasons get() {
			return season;
		}
	}
	// ����������
	property String^ Path {
		void set(String^ path) {
			this->path = path;
		}
		String^ get() {
			return this->path;
		}
	}
	// ���� ����, ��� ������ �������. ���������� ����� ������.
	// ������������ �������� �� 0 �� 100 (���� ��������).
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
	// ������
	virtual void water();
	// ����� ����� ��������
	virtual void findNewFlower();
	// �������� ���������
	virtual void eat();
	// ����������
	void degidrate();
	// �����
	void grow();
	// ����� ������� �����
	virtual void changeTime(TimesOfDay dayTime);
	// ���������� � ��������
	virtual void conditionCheck();
};