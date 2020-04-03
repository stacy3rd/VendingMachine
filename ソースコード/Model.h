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

	// �x�����@�̑I��
	void SelectMoney()
	{
		unsigned short num; // ��Ɨp�ϐ�

		// �x�����@��I��
		cout << "�w�����@��I�����Ă�������" << endl;
		cout << "�����ł̍w���Ȃ� -> 1" << endl;
		cout << "�d�q�}�l�[�ł̍w���Ȃ� -> 2" << endl;
		cout << "Input: ";
		cin >> num;

		// �d�q�}�l�[�Ȃ�
		if (num == 2)
		{
			this->isE_money = true; // �t���O���I��
		}
		else // �����̍w�����I�����ꂽ�ꍇ�A�܂��͗L���Ȑ����ȊO�����͂��ꂽ�ꍇ
		{
			this->isE_money = false; // �t���O���I�t
		}
	}

	// ����
	void Payment()
	{
		// �d�q�}�l�[�Ȃ�
		if (this->isE_money)
		{
			// �d�q�}�l�[�̏������z���Z�b�g
			amount = MONEY::ONE_THOUSAND;

			cout << endl;
			cout << "�d�q�}�l�[�c��: " << this->amount << "�~" << endl;
		}
		else // �����Ȃ�
		{
			bool loop = true; // ���[�v�t���O

			// ���[�v�t���O���I���̊ԃ��[�v
			while (loop)
			{
				loop = true; // ���[�v�t���O���I����

				int work; // ��Ɨp�ϐ�
				
				// ��������ݕ���I��
				cout << endl;
				cout << "�����ݕ���I�����Ă�������" << endl;
				cout << "10�~    -> 1" << endl;
				cout << "50�~    -> 2" << endl;
				cout << "100�~   -> 3" << endl;
				cout << "500�~   -> 4" << endl;
				cout << "1000�~  -> 5" << endl;
				cout << "5000�~  -> 6" << endl;
				cout << "10000�~ -> 7" << endl;
				cout << "Input: ";
				cin >> work;
				cout << endl;

				// ��������
				switch (work)
				{
				case 1:
					if (this->myTenCoin < 1)
					{
						cout << "10�~�ʂ͂�������܂���" << endl;
						break;
					}
					this->tenCoin++;
					this->amount += MONEY::TEN;
					this->myTenCoin--;
					break;

				case 2:
					if (this->myFiftyCoin < 1)
					{
						cout << "50�~�ʂ͂�������܂���" << endl;
						break;
					}
					this->fiftyCoin++;
					this->amount += MONEY::FIFTY;
					this->myFiftyCoin--;
					break;

				case 3:
					if (this->myOne_hundredCoin < 1)
					{
						cout << "100�~�ʂ͂�������܂���" << endl;
						break;
					}
					this->one_hundredCoin++;
					this->amount += MONEY::ONE_HUNDRED;
					this->myOne_hundredCoin--;
					break;

				case 4:
					if (this->myFive_hundredCoin < 1)
					{
						cout << "500�~�ʂ͂�������܂���" << endl;
						break;
					}
					this->five_hundredCoin++;
					this->amount += MONEY::FIVE_HUNDRED;
					this->myFive_hundredCoin--;
					break;

				case 5:
					if (this->myOne_thousandBill < 1)
					{
						cout << "1000�~�D�͂�������܂���" << endl;
						break;
					}
					this->one_thousandBill++;
					this->amount += MONEY::ONE_THOUSAND;
					this->myOne_thousandBill--;
					break;

				case 6:
					if (this->myFive_thousandBill < 1)
					{
						cout << "5000�~�D�͂�������܂���" << endl;
						break;
					}
					this->five_thousandBill++;
					this->amount += MONEY::FIVE_THOUSAND;
					this->myFive_thousandBill--;
					break;

				case 7:
					if (this->myTen_thousandBill < 1)
					{
						cout << "10000�~�D�͂�������܂���" << endl;
						break;
					}
					this->ten_thousandBill++;
					this->amount += MONEY::TEN_THOUSAND;
					this->myTen_thousandBill--;
					break;

				default:
					break;
				}

				// �w���\���z�ɓ��B������
				if (this->amount >= TIKET_PRICE)
				{
					char ans; // ��Ɨp�ϐ�

					// �܂����C���邩�ǂ������m�F
					cout << "�܂��������܂����H" << endl;
					cout << "Y/N : ";
					cin >> ans;

					// No�̏ꍇ�̂�
					if (ans == 'N' || ans == 'n')
					{
						loop = false; // ���[�v�t���O���I�t��
					}
					cout << endl;
				}
			}

			// �������z��\��
			cout << "�������z: " << this->amount << "�~" << endl;
		}
	}

	// �w������
	void Transaction()
	{
		// �d�q�}�l�[�̏ꍇ
		if (this->isE_money)
		{
			bool work = E_MonyTransaction();
		}
		else // �����̏ꍇ
		{
			// �v�Z
			this->money = this->amount - TIKET_PRICE;

			// ���ނ肪����Ȃ�
			if (this->money > 0)
			{
				// ���ނ��ʕϐ��ɕێ�
				this->change = this->money;
			}
		}
	}

	// �d�q�}�l�[�ł̍w������
	bool E_MonyTransaction()
	{
		// �w����̎c�����}�C�i�X�ɂȂ�ꍇ
		if (this->amount - E_MONEY_PRICE < 0)
		{
			// ���s
			cout << "�������s" << endl;
			cout << "�c�����s�����Ă��܂�" << endl;
			cout << "�c��: " << this->amount << endl;
			return false;
		}

		// �v�Z
		this->e_money = this->amount - E_MONEY_PRICE;

		// ����
		cout << "��������" << endl;
		cout << "�����z: " << E_MONEY_PRICE << "�~" << endl;
		cout << "�c��: " << this->e_money << endl;
		return true;
	}

	// ���ނ�̌v�Z
	void Change()
	{
		// ���ނ肪����Ȃ�
		if (this->change != 0)
		{
			// �ނ�K�̋��z
			cout << "�ނ�K: " << this->change << "�~" << endl;
			cout << endl;

			// ��Ɨp�ϐ�
			int tenCoin, fiftyCoin, one_hundredCoin, five_hundredCoin, one_thousandBill, five_thousandBill, ten_thousandBill = 0;
			int work;
			
			// �ނ�K�̌v�Z
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

			// �ނ�K�̋���Ɩ���
			cout << "�ނ�K�̋���Ɩ���" << endl;
			if (tenCoin != 0)
			{
				cout << "10�~��: " << tenCoin << "��" << endl;
			}
			if (fiftyCoin != 0)
			{
				cout << "50�~��: " << fiftyCoin << "��" << endl;
			}
			if (one_hundredCoin != 0)
			{
				cout << "100�~��: " << one_hundredCoin << "��" << endl;
			}
			if (five_hundredCoin != 0)
			{
				cout << "500�~��: " << five_hundredCoin << "��" << endl;
			}
			if (one_thousandBill != 0)
			{
				cout << "1000�~�D: " << one_thousandBill << "��" << endl;
			}
			if (five_thousandBill != 0)
			{
				cout << "5000�~�D: " << five_thousandBill << "��" << endl;
			}
			if (ten_thousandBill != 0)
			{
				cout << "10000�~�D: " << ten_thousandBill << "��" << endl;
			}
		}
	}

	// ���ʕ\��
	void Result()
	{
		cout << endl;
		cout << "�x�������@: ";

		// �d�q�}�l�[�̏ꍇ
		if (this->isE_money)
		{
			cout << "�d�q�}�l�[" << endl;
			cout << "�w���O�̎c��: " << this->amount << "�~" << endl;
			cout << "�w����̎c��: " << this->e_money << "�~" << endl;
		}
		else // �����̏ꍇ
		{
			cout << "����" << endl;
			cout << endl;

			// ������������Ɩ���
			cout << "������������Ɩ���" << endl;
			if (this->tenCoin != 0)
			{
				cout << "10�~��: " << this->tenCoin << "��" << endl;
			}
			if (this->fiftyCoin != 0)
			{
				cout << "50�~��: " << this->fiftyCoin << "��" << endl;
			}
			if (this->one_hundredCoin != 0)
			{
				cout << "100�~��: " << this->one_hundredCoin << "��" << endl;
			}
			if (this->five_hundredCoin != 0)
			{
				cout << "500�~��: " << this->five_hundredCoin << "��" << endl;
			}
			if (this->one_thousandBill != 0)
			{
				cout << "1000�~�D: " << this->one_thousandBill << "��" << endl;
			}
			if (this->five_thousandBill != 0)
			{
				cout << "5000�~�D: " << this->five_thousandBill << "��" << endl;
			}
			if (this->ten_thousandBill != 0)
			{
				cout << "10000�~�D: " << this->ten_thousandBill << "��" << endl;
			}

			cout << endl;

			// �ނ�K�̋���Ɩ���
			Change();
			cout << endl;

			// �茳�Ɏc�����e����Ɩ���
			cout << "�茳�Ɏc�����e����Ɩ���" << endl;
			if (this->myTenCoin != 0)
			{
				cout << "10�~��: " << this->myTenCoin << "��" << endl;
			}
			if (this->myFiftyCoin != 0)
			{
				cout << "50�~��: " << this->myFiftyCoin << "��" << endl;
			}
			if (this->myOne_hundredCoin != 0)
			{
				cout << "100�~��: " << this->myOne_hundredCoin << "��" << endl;
			}
			if (this->myFive_hundredCoin != 0)
			{
				cout << "500�~��: " << this->myFive_hundredCoin << "��" << endl;
			}
			if (this->myOne_thousandBill != 0)
			{
				cout << "1000�~�D: " << this->myOne_thousandBill << "��" << endl;
			}
			if (this->myFive_thousandBill != 0)
			{
				cout << "5000�~�D: " << this->myFive_thousandBill << "��" << endl;
			}
			if (this->myTen_thousandBill != 0)
			{
				cout << "10000�~�D: " << this->myTen_thousandBill << "��" << endl;
			}
		}

	}

private:
	string data = "";
	DataChangeHandler event = nullptr;

	bool isE_money = false; // �d�q�}�l�[���ǂ���(true�Ȃ�d�q�}�l�[)

	int amount = 0; // �������z
	int money = 0; // ����
	int e_money = 0; // �d�q�}�l�[
	int change = 0; // ���ނ�

	// �d�݁E�����̐�
	int tenCoin = 0; // 10�~��
	int fiftyCoin = 0; // 50�~��
	int one_hundredCoin = 0; // 100�~��
	int five_hundredCoin = 0; // 500�~��
	int one_thousandBill = 0; // 1000�~�D
	int five_thousandBill = 0; // 5000�~�D
	int ten_thousandBill = 0; // 10000�~�D

	// �������Ă���ݕ�
	int myTenCoin = 15; // 10�~��
	int myFiftyCoin = 3; // 50�~��
	int myOne_hundredCoin = 2; // 100�~��
	int myFive_hundredCoin = 1; // 500�~��
	int myOne_thousandBill = 1; // 1000�~�D
	int myFive_thousandBill = 1; // 5000�~�D
	int myTen_thousandBill = 1; // 10000�~�D

};

#endif // !MODEL_H