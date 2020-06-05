#include "Sunflower.h"

SFlower::SFlower(FlowerEnvironment^ env) {
	this->Timer = gcnew System::Windows::Forms::Timer();
	this->Timer->Tick += gcnew System::EventHandler(this, &SFlower::OnTick);
	this->Timer->Interval = 1000;
	this->Progress = 0;
	this->Alive = true;
	this->Timer->Enabled = false;
	env->DeadlyEvent += gcnew FlowerEnvironment::DeadlyEventHandler(this, &SFlower::die);
	env->ConditionsChanges += gcnew FlowerEnvironment::ConditionsChangedHandler(this, &SFlower::reactOnEnvironment);
}

SFlower::~SFlower()
{
	this->Timer->~Timer();
}

void SFlower::reactOnEnvironment(FlowerEnvironment^ env)
{
	switch (env->Season)
	{
	case WINTER:
		die(FROZEN);
	case SPRING:
		Progress = 0;
		Stage = LITTLE;
		if (env->Temperature == COLD) {
			die(FROZEN);
		}
		break;
	case SUMMER:
		Progress = 30;
		Stage = MIDDLE;
		break;
	case AUTUMN:
		Progress = 60;
		Stage = BIG;
		if (env->Temperature == COLD) {
			die(FROZEN);
		}
		Stage = BIG;
		break;
	default:
		break;
	}
}

void SFlower::grow()
{
	if (Progress <= 90) {
		Progress += 2;
	}
	switch (Progress) {
	case 30: 
		Stage = MIDDLE;
		break;
	case 60:
		Stage = BIG;
		break;
	case 90:
		Stage = RIPENED;
		break;
	}
}

void SFlower::OnTick(System::Object^ sender, System::EventArgs^ e)
{
	if (Stage != HARVESTED) grow();
}
