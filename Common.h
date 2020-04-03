//======================================
// Common.h
//======================================
#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>

using namespace std;

#define TIKET_PRICE (130) // �ؕ��̉��i�i�����j
#define E_MONEY_PRICE (124) // �ؕ��̉��i�i�d�q�}�l�[�j

// �ݕ��̗�
enum MONEY
{
	TEN = 10,				// 10�~
	FIFTY = 50,				// 50�~
	ONE_HUNDRED = 100,		// 100�~
	FIVE_HUNDRED = 500,		// 500�~
	ONE_THOUSAND = 1000,	// 1000�~
	FIVE_THOUSAND = 5000,	// 5000�~
	TEN_THOUSAND = 10000,	// 10000�~
};
typedef void(*DataChangeHandler)(string newData);

#endif // !COMMON_H