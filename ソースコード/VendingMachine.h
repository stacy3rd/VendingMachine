//======================================
// VendingMachine.h
// =====================================
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "Controller.h"

class VendingMachine
{
public:
	VendingMachine();
	~VendingMachine();
	void Run();

private:
	Model model;
	View view;
	Controller* controller;
};

#endif // !VENDINGMACHINE_H
