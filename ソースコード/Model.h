//======================================
// Model.h
// =====================================
#ifndef MODEL_H
#define MODEL_H

#include "Common.h"

using namespace std;

class Model
{
public:
	Model(const string &data)
	{
		this->data = data;
	}

	Model(){}

	~Model(){}

	string GetData()
	{
		return this->data;
	}

	void SetData(const string &data)
	{
		this->data = data;
		if (this->event != nullptr)
		{
			this->event(data);
		}
	}

	void RegisterDataChangeHandler(DataChangeHandler handler)
	{
		this->event = handler;
	}

	// 支払方法の選択
	void SelectMoney()
	{
		unsigned short num; // 作業用変数

		// 支払方法を選択
		cout << "購入方法を選択してください" << endl;
		cout << "現金での購入なら -> 1" << endl;
		cout << "電子マネーでの購入なら -> 2" << endl;
		cout << "Input: ";
		cin >> num;

		// 電子マネーなら
		if (num == 2)
		{
			this->isE_money = true; // フラグをオン
		}
		else // 現金の購入が選択された場合、または有効な数字以外が入力された場合
		{
			this->isE_money = false; // フラグをオフ
		}
	}

	// 入金
	void Payment()
	{
		// 電子マネーなら
		if (this->isE_money)
		{
			// 電子マネーの初期金額をセット
			amount = MONEY::ONE_THOUSAND;

			cout << endl;
			cout << "電子マネー残高: " << this->amount << "円" << endl;
		}
		else // 現金なら
		{
			bool loop = true; // ループフラグ

			// ループフラグがオンの間ループ
			while (loop)
			{
				loop = true; // ループフラグをオンに

				int work; // 作業用変数
				
				// 入金する貨幣を選択
				cout << endl;
				cout << "入れる貨幣を選択してください" << endl;
				cout << "10円    -> 1" << endl;
				cout << "50円    -> 2" << endl;
				cout << "100円   -> 3" << endl;
				cout << "500円   -> 4" << endl;
				cout << "1000円  -> 5" << endl;
				cout << "5000円  -> 6" << endl;
				cout << "10000円 -> 7" << endl;
				cout << "Input: ";
				cin >> work;
				cout << endl;

				// 入金処理
				switch (work)
				{
				case 1:
					if (this->myTenCoin < 1)
					{
						cout << "10円玉はもうありません" << endl;
						break;
					}
					this->tenCoin++;
					this->amount += MONEY::TEN;
					this->myTenCoin--;
					break;

				case 2:
					if (this->myFiftyCoin < 1)
					{
						cout << "50円玉はもうありません" << endl;
						break;
					}
					this->fiftyCoin++;
					this->amount += MONEY::FIFTY;
					this->myFiftyCoin--;
					break;

				case 3:
					if (this->myOne_hundredCoin < 1)
					{
						cout << "100円玉はもうありません" << endl;
						break;
					}
					this->one_hundredCoin++;
					this->amount += MONEY::ONE_HUNDRED;
					this->myOne_hundredCoin--;
					break;

				case 4:
					if (this->myFive_hundredCoin < 1)
					{
						cout << "500円玉はもうありません" << endl;
						break;
					}
					this->five_hundredCoin++;
					this->amount += MONEY::FIVE_HUNDRED;
					this->myFive_hundredCoin--;
					break;

				case 5:
					if (this->myOne_thousandBill < 1)
					{
						cout << "1000円札はもうありません" << endl;
						break;
					}
					this->one_thousandBill++;
					this->amount += MONEY::ONE_THOUSAND;
					this->myOne_thousandBill--;
					break;

				case 6:
					if (this->myFive_thousandBill < 1)
					{
						cout << "5000円札はもうありません" << endl;
						break;
					}
					this->five_thousandBill++;
					this->amount += MONEY::FIVE_THOUSAND;
					this->myFive_thousandBill--;
					break;

				case 7:
					if (this->myTen_thousandBill < 1)
					{
						cout << "10000円札はもうありません" << endl;
						break;
					}
					this->ten_thousandBill++;
					this->amount += MONEY::TEN_THOUSAND;
					this->myTen_thousandBill--;
					break;

				default:
					break;
				}

				// 購入可能金額に到達したら
				if (this->amount >= TIKET_PRICE)
				{
					char ans; // 作業用変数

					// まだ入気するかどうかを確認
					cout << "まだ入金しますか？" << endl;
					cout << "Y/N : ";
					cin >> ans;

					// Noの場合のみ
					if (ans == 'N' || ans == 'n')
					{
						loop = false; // ループフラグをオフに
					}
					cout << endl;
				}
			}

			// 投入金額を表示
			cout << "投入金額: " << this->amount << "円" << endl;
		}
	}

	// 購入処理
	void Transaction()
	{
		// 電子マネーの場合
		if (this->isE_money)
		{
			bool work = E_MonyTransaction();
		}
		else // 現金の場合
		{
			// 計算
			this->money = this->amount - TIKET_PRICE;

			// お釣りがあるなら
			if (this->money > 0)
			{
				// お釣りを別変数に保持
				this->change = this->money;
			}
		}
	}

	// 電子マネーでの購入処理
	bool E_MonyTransaction()
	{
		// 購入後の残高がマイナスになる場合
		if (this->amount - E_MONEY_PRICE < 0)
		{
			// 失敗
			cout << "引去失敗" << endl;
			cout << "残高が不足しています" << endl;
			cout << "残高: " << this->amount << endl;
			return false;
		}

		// 計算
		this->e_money = this->amount - E_MONEY_PRICE;

		// 成功
		cout << "引去成功" << endl;
		cout << "引去額: " << E_MONEY_PRICE << "円" << endl;
		cout << "残高: " << this->e_money << endl;
		return true;
	}

	// お釣りの計算
	void Change()
	{
		// お釣りがあるなら
		if (this->change != 0)
		{
			// 釣り銭の金額
			cout << "釣り銭: " << this->change << "円" << endl;
			cout << endl;

			// 作業用変数
			int tenCoin, fiftyCoin, one_hundredCoin, five_hundredCoin, one_thousandBill, five_thousandBill, ten_thousandBill = 0;
			int work;
			
			// 釣り銭の計算
			ten_thousandBill = this->change / MONEY::TEN_THOUSAND;
			work = this->change % MONEY::TEN_THOUSAND;
			five_thousandBill = work / MONEY::FIVE_THOUSAND;
			work = work % MONEY::FIVE_THOUSAND;
			one_thousandBill = work / MONEY::ONE_THOUSAND;
			work = work % MONEY::ONE_THOUSAND;
			five_hundredCoin = work / MONEY::FIVE_HUNDRED;
			work = work % MONEY::FIVE_HUNDRED;
			one_hundredCoin = work / MONEY::ONE_HUNDRED;
			work = work % MONEY::ONE_HUNDRED;
			fiftyCoin = work / MONEY::FIFTY;
			work = work % MONEY::FIFTY;
			tenCoin = work / MONEY::TEN;

			// 釣り銭の金種と枚数
			cout << "釣り銭の金種と枚数" << endl;
			if (tenCoin != 0)
			{
				cout << "10円玉: " << tenCoin << "枚" << endl;
			}
			if (fiftyCoin != 0)
			{
				cout << "50円玉: " << fiftyCoin << "枚" << endl;
			}
			if (one_hundredCoin != 0)
			{
				cout << "100円玉: " << one_hundredCoin << "枚" << endl;
			}
			if (five_hundredCoin != 0)
			{
				cout << "500円玉: " << five_hundredCoin << "枚" << endl;
			}
			if (one_thousandBill != 0)
			{
				cout << "1000円札: " << one_thousandBill << "枚" << endl;
			}
			if (five_thousandBill != 0)
			{
				cout << "5000円札: " << five_thousandBill << "枚" << endl;
			}
			if (ten_thousandBill != 0)
			{
				cout << "10000円札: " << ten_thousandBill << "枚" << endl;
			}
		}
	}

	// 結果表示
	void Result()
	{
		cout << endl;
		cout << "支払い方法: ";

		// 電子マネーの場合
		if (this->isE_money)
		{
			cout << "電子マネー" << endl;
			cout << "購入前の残高: " << this->amount << "円" << endl;
			cout << "購入後の残高: " << this->e_money << "円" << endl;
		}
		else // 現金の場合
		{
			cout << "現金" << endl;
			cout << endl;

			// 投入した金種と枚数
			cout << "投入した金種と枚数" << endl;
			if (this->tenCoin != 0)
			{
				cout << "10円玉: " << this->tenCoin << "枚" << endl;
			}
			if (this->fiftyCoin != 0)
			{
				cout << "50円玉: " << this->fiftyCoin << "枚" << endl;
			}
			if (this->one_hundredCoin != 0)
			{
				cout << "100円玉: " << this->one_hundredCoin << "枚" << endl;
			}
			if (this->five_hundredCoin != 0)
			{
				cout << "500円玉: " << this->five_hundredCoin << "枚" << endl;
			}
			if (this->one_thousandBill != 0)
			{
				cout << "1000円札: " << this->one_thousandBill << "枚" << endl;
			}
			if (this->five_thousandBill != 0)
			{
				cout << "5000円札: " << this->five_thousandBill << "枚" << endl;
			}
			if (this->ten_thousandBill != 0)
			{
				cout << "10000円札: " << this->ten_thousandBill << "枚" << endl;
			}

			cout << endl;

			// 釣り銭の金種と枚数
			Change();
			cout << endl;

			// 手元に残った各金種と枚数
			cout << "手元に残った各金種と枚数" << endl;
			if (this->myTenCoin != 0)
			{
				cout << "10円玉: " << this->myTenCoin << "枚" << endl;
			}
			if (this->myFiftyCoin != 0)
			{
				cout << "50円玉: " << this->myFiftyCoin << "枚" << endl;
			}
			if (this->myOne_hundredCoin != 0)
			{
				cout << "100円玉: " << this->myOne_hundredCoin << "枚" << endl;
			}
			if (this->myFive_hundredCoin != 0)
			{
				cout << "500円玉: " << this->myFive_hundredCoin << "枚" << endl;
			}
			if (this->myOne_thousandBill != 0)
			{
				cout << "1000円札: " << this->myOne_thousandBill << "枚" << endl;
			}
			if (this->myFive_thousandBill != 0)
			{
				cout << "5000円札: " << this->myFive_thousandBill << "枚" << endl;
			}
			if (this->myTen_thousandBill != 0)
			{
				cout << "10000円札: " << this->myTen_thousandBill << "枚" << endl;
			}
		}

	}

private:
	string data = "";
	DataChangeHandler event = nullptr;

	bool isE_money = false; // 電子マネーかどうか(trueなら電子マネー)

	int amount = 0; // 投入金額
	int money = 0; // 現金
	int e_money = 0; // 電子マネー
	int change = 0; // お釣り

	// 硬貨・紙幣の数
	int tenCoin = 0; // 10円玉
	int fiftyCoin = 0; // 50円玉
	int one_hundredCoin = 0; // 100円玉
	int five_hundredCoin = 0; // 500円玉
	int one_thousandBill = 0; // 1000円札
	int five_thousandBill = 0; // 5000円札
	int ten_thousandBill = 0; // 10000円札

	// 所持している貨幣
	int myTenCoin = 15; // 10円玉
	int myFiftyCoin = 3; // 50円玉
	int myOne_hundredCoin = 2; // 100円玉
	int myFive_hundredCoin = 1; // 500円玉
	int myOne_thousandBill = 1; // 1000円札
	int myFive_thousandBill = 1; // 5000円札
	int myTen_thousandBill = 1; // 10000円札

};

#endif // !MODEL_H