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

	// x•¥•û–@‚Ì‘I‘ğ
	void SelectMoney()
	{
		unsigned short num; // ì‹Æ—p•Ï”

		// x•¥•û–@‚ğ‘I‘ğ
		cout << "w“ü•û–@‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		cout << "Œ»‹à‚Å‚Ìw“ü‚È‚ç -> 1" << endl;
		cout << "“dqƒ}ƒl[‚Å‚Ìw“ü‚È‚ç -> 2" << endl;
		cout << "Input: ";
		cin >> num;

		// “dqƒ}ƒl[‚È‚ç
		if (num == 2)
		{
			this->isE_money = true; // ƒtƒ‰ƒO‚ğƒIƒ“
		}
		else // Œ»‹à‚Ìw“ü‚ª‘I‘ğ‚³‚ê‚½ê‡A‚Ü‚½‚Í—LŒø‚È”šˆÈŠO‚ª“ü—Í‚³‚ê‚½ê‡
		{
			this->isE_money = false; // ƒtƒ‰ƒO‚ğƒIƒt
		}
	}

	// “ü‹à
	void Payment()
	{
		// “dqƒ}ƒl[‚È‚ç
		if (this->isE_money)
		{
			// “dqƒ}ƒl[‚Ì‰Šú‹àŠz‚ğƒZƒbƒg
			amount = MONEY::ONE_THOUSAND;

			cout << endl;
			cout << "“dqƒ}ƒl[c‚: " << this->amount << "‰~" << endl;
		}
		else // Œ»‹à‚È‚ç
		{
			bool loop = true; // ƒ‹[ƒvƒtƒ‰ƒO

			// ƒ‹[ƒvƒtƒ‰ƒO‚ªƒIƒ“‚ÌŠÔƒ‹[ƒv
			while (loop)
			{
				loop = true; // ƒ‹[ƒvƒtƒ‰ƒO‚ğƒIƒ“‚É

				int work; // ì‹Æ—p•Ï”
				
				// “ü‹à‚·‚é‰İ•¼‚ğ‘I‘ğ
				cout << endl;
				cout << "“ü‚ê‚é‰İ•¼‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << endl;
				cout << "10‰~    -> 1" << endl;
				cout << "50‰~    -> 2" << endl;
				cout << "100‰~   -> 3" << endl;
				cout << "500‰~   -> 4" << endl;
				cout << "1000‰~  -> 5" << endl;
				cout << "5000‰~  -> 6" << endl;
				cout << "10000‰~ -> 7" << endl;
				cout << "Input: ";
				cin >> work;
				cout << endl;

				// “ü‹àˆ—
				switch (work)
				{
				case 1:
					if (this->myTenCoin < 1)
					{
						cout << "10‰~‹Ê‚Í‚à‚¤‚ ‚è‚Ü‚¹‚ñ" << endl;
						break;
					}
					this->tenCoin++;
					this->amount += MONEY::TEN;
					this->myTenCoin--;
					break;

				case 2:
					if (this->myFiftyCoin < 1)
					{
						cout << "50‰~‹Ê‚Í‚à‚¤‚ ‚è‚Ü‚¹‚ñ" << endl;
						break;
					}
					this->fiftyCoin++;
					this->amount += MONEY::FIFTY;
					this->myFiftyCoin--;
					break;

				case 3:
					if (this->myOne_hundredCoin < 1)
					{
						cout << "100‰~‹Ê‚Í‚à‚¤‚ ‚è‚Ü‚¹‚ñ" << endl;
						break;
					}
					this->one_hundredCoin++;
					this->amount += MONEY::ONE_HUNDRED;
					this->myOne_hundredCoin--;
					break;

				case 4:
					if (this->myFive_hundredCoin < 1)
					{
						cout << "500‰~‹Ê‚Í‚à‚¤‚ ‚è‚Ü‚¹‚ñ" << endl;
						break;
					}
					this->five_hundredCoin++;
					this->amount += MONEY::FIVE_HUNDRED;
					this->myFive_hundredCoin--;
					break;

				case 5:
					if (this->myOne_thousandBill < 1)
					{
						cout << "1000‰~D‚Í‚à‚¤‚ ‚è‚Ü‚¹‚ñ" << endl;
						break;
					}
					this->one_thousandBill++;
					this->amount += MONEY::ONE_THOUSAND;
					this->myOne_thousandBill--;
					break;

				case 6:
					if (this->myFive_thousandBill < 1)
					{
						cout << "5000‰~D‚Í‚à‚¤‚ ‚è‚Ü‚¹‚ñ" << endl;
						break;
					}
					this->five_thousandBill++;
					this->amount += MONEY::FIVE_THOUSAND;
					this->myFive_thousandBill--;
					break;

				case 7:
					if (this->myTen_thousandBill < 1)
					{
						cout << "10000‰~D‚Í‚à‚¤‚ ‚è‚Ü‚¹‚ñ" << endl;
						break;
					}
					this->ten_thousandBill++;
					this->amount += MONEY::TEN_THOUSAND;
					this->myTen_thousandBill--;
					break;

				default:
					break;
				}

				// w“ü‰Â”\‹àŠz‚É“’B‚µ‚½‚ç
				if (this->amount >= TIKET_PRICE)
				{
					char ans; // ì‹Æ—p•Ï”

					// ‚Ü‚¾“ü‹C‚·‚é‚©‚Ç‚¤‚©‚ğŠm”F
					cout << "‚Ü‚¾“ü‹à‚µ‚Ü‚·‚©H" << endl;
					cout << "Y/N : ";
					cin >> ans;

					// No‚Ìê‡‚Ì‚İ
					if (ans == 'N' || ans == 'n')
					{
						loop = false; // ƒ‹[ƒvƒtƒ‰ƒO‚ğƒIƒt‚É
					}
					cout << endl;
				}
			}

			// “Š“ü‹àŠz‚ğ•\¦
			cout << "“Š“ü‹àŠz: " << this->amount << "‰~" << endl;
		}
	}

	// w“üˆ—
	void Transaction()
	{
		// “dqƒ}ƒl[‚Ìê‡
		if (this->isE_money)
		{
			bool work = E_MonyTransaction();
		}
		else // Œ»‹à‚Ìê‡
		{
			// ŒvZ
			this->money = this->amount - TIKET_PRICE;

			// ‚¨’Ş‚è‚ª‚ ‚é‚È‚ç
			if (this->money > 0)
			{
				// ‚¨’Ş‚è‚ğ•Ê•Ï”‚É•Û
				this->change = this->money;
			}
		}
	}

	// “dqƒ}ƒl[‚Å‚Ìw“üˆ—
	bool E_MonyTransaction()
	{
		// w“üŒã‚Ìc‚‚ªƒ}ƒCƒiƒX‚É‚È‚éê‡
		if (this->amount - E_MONEY_PRICE < 0)
		{
			// ¸”s
			cout << "ˆø‹¸”s" << endl;
			cout << "c‚‚ª•s‘«‚µ‚Ä‚¢‚Ü‚·" << endl;
			cout << "c‚: " << this->amount << endl;
			return false;
		}

		// ŒvZ
		this->e_money = this->amount - E_MONEY_PRICE;

		// ¬Œ÷
		cout << "ˆø‹¬Œ÷" << endl;
		cout << "ˆø‹Šz: " << E_MONEY_PRICE << "‰~" << endl;
		cout << "c‚: " << this->e_money << endl;
		return true;
	}

	// ‚¨’Ş‚è‚ÌŒvZ
	void Change()
	{
		// ‚¨’Ş‚è‚ª‚ ‚é‚È‚ç
		if (this->change != 0)
		{
			// ’Ş‚è‘K‚Ì‹àŠz
			cout << "’Ş‚è‘K: " << this->change << "‰~" << endl;
			cout << endl;

			// ì‹Æ—p•Ï”
			int tenCoin, fiftyCoin, one_hundredCoin, five_hundredCoin, one_thousandBill, five_thousandBill, ten_thousandBill = 0;
			int work;
			
			// ’Ş‚è‘K‚ÌŒvZ
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

			// ’Ş‚è‘K‚Ì‹àí‚Æ–‡”
			cout << "’Ş‚è‘K‚Ì‹àí‚Æ–‡”" << endl;
			if (tenCoin != 0)
			{
				cout << "10‰~‹Ê: " << tenCoin << "–‡" << endl;
			}
			if (fiftyCoin != 0)
			{
				cout << "50‰~‹Ê: " << fiftyCoin << "–‡" << endl;
			}
			if (one_hundredCoin != 0)
			{
				cout << "100‰~‹Ê: " << one_hundredCoin << "–‡" << endl;
			}
			if (five_hundredCoin != 0)
			{
				cout << "500‰~‹Ê: " << five_hundredCoin << "–‡" << endl;
			}
			if (one_thousandBill != 0)
			{
				cout << "1000‰~D: " << one_thousandBill << "–‡" << endl;
			}
			if (five_thousandBill != 0)
			{
				cout << "5000‰~D: " << five_thousandBill << "–‡" << endl;
			}
			if (ten_thousandBill != 0)
			{
				cout << "10000‰~D: " << ten_thousandBill << "–‡" << endl;
			}
		}
	}

	// Œ‹‰Ê•\¦
	void Result()
	{
		cout << endl;
		cout << "x•¥‚¢•û–@: ";

		// “dqƒ}ƒl[‚Ìê‡
		if (this->isE_money)
		{
			cout << "“dqƒ}ƒl[" << endl;
			cout << "w“ü‘O‚Ìc‚: " << this->amount << "‰~" << endl;
			cout << "w“üŒã‚Ìc‚: " << this->e_money << "‰~" << endl;
		}
		else // Œ»‹à‚Ìê‡
		{
			cout << "Œ»‹à" << endl;
			cout << endl;

			// “Š“ü‚µ‚½‹àí‚Æ–‡”
			cout << "“Š“ü‚µ‚½‹àí‚Æ–‡”" << endl;
			if (this->tenCoin != 0)
			{
				cout << "10‰~‹Ê: " << this->tenCoin << "–‡" << endl;
			}
			if (this->fiftyCoin != 0)
			{
				cout << "50‰~‹Ê: " << this->fiftyCoin << "–‡" << endl;
			}
			if (this->one_hundredCoin != 0)
			{
				cout << "100‰~‹Ê: " << this->one_hundredCoin << "–‡" << endl;
			}
			if (this->five_hundredCoin != 0)
			{
				cout << "500‰~‹Ê: " << this->five_hundredCoin << "–‡" << endl;
			}
			if (this->one_thousandBill != 0)
			{
				cout << "1000‰~D: " << this->one_thousandBill << "–‡" << endl;
			}
			if (this->five_thousandBill != 0)
			{
				cout << "5000‰~D: " << this->five_thousandBill << "–‡" << endl;
			}
			if (this->ten_thousandBill != 0)
			{
				cout << "10000‰~D: " << this->ten_thousandBill << "–‡" << endl;
			}

			cout << endl;

			// ’Ş‚è‘K‚Ì‹àí‚Æ–‡”
			Change();
			cout << endl;

			// èŒ³‚Éc‚Á‚½Še‹àí‚Æ–‡”
			cout << "èŒ³‚Éc‚Á‚½Še‹àí‚Æ–‡”" << endl;
			if (this->myTenCoin != 0)
			{
				cout << "10‰~‹Ê: " << this->myTenCoin << "–‡" << endl;
			}
			if (this->myFiftyCoin != 0)
			{
				cout << "50‰~‹Ê: " << this->myFiftyCoin << "–‡" << endl;
			}
			if (this->myOne_hundredCoin != 0)
			{
				cout << "100‰~‹Ê: " << this->myOne_hundredCoin << "–‡" << endl;
			}
			if (this->myFive_hundredCoin != 0)
			{
				cout << "500‰~‹Ê: " << this->myFive_hundredCoin << "–‡" << endl;
			}
			if (this->myOne_thousandBill != 0)
			{
				cout << "1000‰~D: " << this->myOne_thousandBill << "–‡" << endl;
			}
			if (this->myFive_thousandBill != 0)
			{
				cout << "5000‰~D: " << this->myFive_thousandBill << "–‡" << endl;
			}
			if (this->myTen_thousandBill != 0)
			{
				cout << "10000‰~D: " << this->myTen_thousandBill << "–‡" << endl;
			}
		}

	}

private:
	string data = "";
	DataChangeHandler event = nullptr;

	bool isE_money = false; // “dqƒ}ƒl[‚©‚Ç‚¤‚©(true‚È‚ç“dqƒ}ƒl[)

	int amount = 0; // “Š“ü‹àŠz
	int money = 0; // Œ»‹à
	int e_money = 0; // “dqƒ}ƒl[
	int change = 0; // ‚¨’Ş‚è

	// d‰İE†•¼‚Ì”
	int tenCoin = 0; // 10‰~‹Ê
	int fiftyCoin = 0; // 50‰~‹Ê
	int one_hundredCoin = 0; // 100‰~‹Ê
	int five_hundredCoin = 0; // 500‰~‹Ê
	int one_thousandBill = 0; // 1000‰~D
	int five_thousandBill = 0; // 5000‰~D
	int ten_thousandBill = 0; // 10000‰~D

	// Š‚µ‚Ä‚¢‚é‰İ•¼
	int myTenCoin = 15; // 10‰~‹Ê
	int myFiftyCoin = 3; // 50‰~‹Ê
	int myOne_hundredCoin = 2; // 100‰~‹Ê
	int myFive_hundredCoin = 1; // 500‰~‹Ê
	int myOne_thousandBill = 1; // 1000‰~D
	int myFive_thousandBill = 1; // 5000‰~D
	int myTen_thousandBill = 1; // 10000‰~D

};

#endif // !MODEL_H