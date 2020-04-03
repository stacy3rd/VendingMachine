//======================================
// Common.h
//======================================
#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>

using namespace std;

#define TIKET_PRICE (130) // 切符の価格（現金）
#define E_MONEY_PRICE (124) // 切符の価格（電子マネー）

// 貨幣の列挙
enum MONEY
{
	TEN = 10,				// 10円
	FIFTY = 50,				// 50円
	ONE_HUNDRED = 100,		// 100円
	FIVE_HUNDRED = 500,		// 500円
	ONE_THOUSAND = 1000,	// 1000円
	FIVE_THOUSAND = 5000,	// 5000円
	TEN_THOUSAND = 10000,	// 10000円
};
typedef void(*DataChangeHandler)(string newData);

#endif // !COMMON_H