#pragma once
#include <windows.h>

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