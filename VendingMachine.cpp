//======================================
// VendingMachine.cpp
// =====================================
#include "VendingMachine.h"

void ChangeData(string data)
{
	cout << "Change: " << data << endl;
}

VendingMachine::VendingMachine()
{
	model = Model("VendingMachine");
	view = View(model);
	this->controller = new Controller(model, view);
}

VendingMachine::~VendingMachine()
{
	delete this->controller;
}

void VendingMachine::Run()
{
	this->model.RegisterDataChangeHandler(&ChangeData);

	// �A�v���P�[�V�������N�������Ƃ�
	this->controller->OnLoad();
	
}
