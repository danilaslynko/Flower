#pragma once
#include "helperClasses.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

ref class FlowerEnvironment
{
private:
	// ��������� �����
	int soilMoisture;
	// ���� ���� ���������
	int �hance;
	// �����������
	Temperatures temperature;
	// ����� �����
	TimesOfDay dayTime;
	// ����� ����
	Seasons season;
	// ���� ����� ������� �����
	bool dayChanged;
	
public:
	delegate void DeadlyEventHandler(ReasonOfDeath);
	delegate void ConditionsChangedHandler(FlowerEnvironment^);
	event DeadlyEventHandler^ DeadlyEvent;
	event ConditionsChangedHandler^ ConditionsChanges;
	// ������ ��� �������
	Timer^ Timer;
	// ���� ����� ������� �����
	property bool DayChanged {
		void set(bool dayChanged) {
			this->dayChanged = dayChanged;
		}
		bool get() {
			return dayChanged;
		}
	}
	// ����� �����
	property TimesOfDay DayTime {
		void set(TimesOfDay dayTime) {
			this->dayTime = dayTime;
			DayChanged = true;
			ConditionsChanges(this);
			DayChanged = false;
		}
		TimesOfDay get() {
			return dayTime;
		}
	}
	// �����������
	property Temperatures Temperature {
		void set(Temperatures temperature) {
			this->temperature = temperature;
			ConditionsChanges(this);
		}
		Temperatures get() {
			return temperature;
		}
	}
	// ��������� �����
	property int SoilMoisture {
		void set(int soilMoisture) {
			this->soilMoisture = soilMoisture;
			if (soilMoisture > 30) soilMoisture = 30;
		}
		int get() {
			return soilMoisture;
		}
	}
	// ����� ����
	property Seasons Season {
		void set(Seasons season) {
			this->season = season;
			ConditionsChanges(this);
		}
		Seasons get() {
			return season;
		}
	}
	// ���� ����, ��� ������ �������. ���������� ����� ������.
	// ������������ �������� �� 0 �� 100 (���� ��������).
	property int Chance {
		void set(int treshold) {
			Random^ rnd = gcnew Random();
			this->�hance = rnd->Next(0, 100);
			if (this->�hance < treshold) {
				DeadlyEvent(EATEN);
			}
		}
	}
	FlowerEnvironment(Temperatures temp, Seasons season, TimesOfDay dayTime);
	~FlowerEnvironment();
	void timerTick(System::Object^ sender, System::EventArgs^ e);
};