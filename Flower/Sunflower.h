#pragma once
#include "Flower.h"
ref class SFlower : public Flowers { // �������������� �����
public:
	// ����������� � ����������
	SFlower();
	~SFlower();
	// ���������������� ������
	virtual void reactOnEnvironment(Seasons season, Temperatures temperature) override;
	virtual void grow(Temperatures temperature) override;
};

