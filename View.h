//======================================
// View.h
// =====================================
#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Common.h"
#include "Model.h"

class View
{
public:
	View(const Model &model)
	{
		this->model = model;
	}

	View(){}

	~View(){}

	// �o��
	void Render()
	{
		cout << "Model data: " << model.GetData() << endl;

		// �������@�̑I��
		model.SelectMoney();

		// ����
		model.Payment();

		// �w������
		model.Transaction();

		// ���ʕ\��
		model.Result();
	}

private:
	Model model;
};

#endif // !VIEW_H