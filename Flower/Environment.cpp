#include "Environment.h"

FlowerEnvironment::FlowerEnvironment(Temperatures temp, Seasons season, TimesOfDay dayTime)
{
    Timer = gcnew System::Windows::Forms::Timer();
    Timer->Tick += gcnew System::EventHandler(this, &FlowerEnvironment::timerTick);
    Timer->Interval = 1000;
    this->Temperature = temp;
    this->Season = season;
    this->DayTime = dayTime;
    this->SoilMoisture = 30;
}

FlowerEnvironment::~FlowerEnvironment()
{
    this->Timer->~Timer();
}

void FlowerEnvironment::timerTick(System::Object^ sender, System::EventArgs^ e)
{
    if (Season != WINTER) {
        if (Season == SUMMER) {
            Chance = 5;
        }
        if (SoilMoisture >= 0) {
            SoilMoisture -= (int)Temperature;
        }
        if (soilMoisture == 0) DeadlyEvent(WITHERED);
    }
}