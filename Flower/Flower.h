#pragma once
#include <iostream>
#include <time.h>
#include "helperClasses.h"
#include "Environment.h"

using namespace std;
using namespace System;

ref class Flowers { // �����-������

public:
	delegate void DeathEventHandler(Flowers^ flower, ReasonOfDeath reason, String^ message); // ���������
	delegate void GrowEventHandler(Flowers^ flower, GrowthStage stage); // ��������� ��� ����� ��� � ����
	event DeathEventHandler^ FlowerIsDead; // ������� ���������� ������
	event GrowEventHandler^ FlowerGrown; // ������� ����������� ������

private:
	// ���� � ����������
	String^ path;
	// �������� ��������
	int progress;
	// ���� ����, ��� ������ ������
	int chance;
	// �������� ���
	bool alive;
	// ������ ����� ������
	GrowthStage stage;
	// ������� ������
	ReasonOfDeath reason;

public:
	// ������ ��� ����� ���������
	Timer^ Timer;
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
	// ������� ������
	property ReasonOfDeath Reason {
		void set(ReasonOfDeath reason) {
			this->reason = reason;
			FlowerIsDead(
				this,
				reason,
				"������ ���� :("
			);
		}
		ReasonOfDeath get() {
			return reason;
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
	// �������
	void die(ReasonOfDeath reason);
	// �����
	virtual void grow();
	// ������� �� ����� ������� ����
	virtual void reactOnEnvironment(FlowerEnvironment^ env);
	virtual void OnTick(System::Object^ sender, System::EventArgs^ e);
};