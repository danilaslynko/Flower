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

ref class Flowers { // �����-������

public:
	delegate void DeathEventHandler(Flowers^ flower, ReasonOfDeath reason, String^ message); // ���������
	delegate void GrowEventHandler(Flowers^ flower, GrowthStage stage); // ��������� ��� ����� ��� � ����
	event DeathEventHandler^ FlowerIsDead; // ������� ���������� ������
	event GrowEventHandler^ FlowerGrown; // ������� ����������� ������

private:
	//���� � ����������
	String^ path;
	// �������� ��������
	int progress;
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
	// �������� ���������
	void eat();
	// ����������
	void degidrate(Temperatures temperature);
	// �����
	virtual void grow(Temperatures temperature);
	// ������� �� ����� ������� ����
	virtual void reactOnEnvironment(Seasons season, Temperatures temperature);
};