#pragma once
#include "Flower.h"
ref class SFlower : public Flowers { // �������������� �����
public:
	// ����������� � ����������
	SFlower(FlowerEnvironment^ env);
	~SFlower();
	// ���������������� ������
	virtual void reactOnEnvironment(FlowerEnvironment^ env) override;
	virtual void grow() override;
	virtual void OnTick(System::Object^ sender, System::EventArgs^ e) override;
};