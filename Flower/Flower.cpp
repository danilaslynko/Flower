#include "Flower.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Flowers::Flowers() {}

/*Конструкторы..*/
Flowers::Flowers(FlowerEnvironment^ env) {
	this->Timer = gcnew System::Windows::Forms::Timer();
	this->Timer->Tick += gcnew System::EventHandler(this, &Flowers::OnTick);
	this->Progress = 0;
	this->Alive = true;
	this->Timer->Interval = 1000;
	this->Timer->Enabled = false;
	env->DeadlyEvent += gcnew FlowerEnvironment::DeadlyEventHandler(this, &Flowers::die);
	env->ConditionsChanges += gcnew FlowerEnvironment::ConditionsChangedHandler(this, &Flowers::reactOnEnvironment);
}

Flowers::~Flowers()
{
	this->Timer->~Timer();
}

/*методы..*/
void Flowers::die(ReasonOfDeath reason)
{
	if (Alive) {
		Alive = false;
		Progress = 0;
		Reason = reason;
	}
}

void Flowers::grow()
{
	if (Progress < 30) {
		Progress += 2;
	}
	if (Progress == 18) {
		Stage = MIDDLE;
	}
	if (Progress == 30) {
		Stage = BIG;
	}
}

void Flowers::reactOnEnvironment(FlowerEnvironment^ env)
{
	switch (env->Season)
	{
	case SPRING:
		if (env->Temperature == COLD) {
			die(FROZEN);
		}
		if (!env->DayChanged) {
			Stage = LITTLE;
		}
		break;
	case WINTER:
		die(FROZEN);
		break;
	case AUTUMN:
		if (env->Temperature == COLD) {
			die(FROZEN);
		}
		break;
	default:
		break;
	}
}
/*.. и иже с ними*/

void Flowers::OnTick(System::Object^ sender, System::EventArgs^ e)
{
	if (Stage == LITTLE || Stage == MIDDLE) {
		grow();
	}
}
