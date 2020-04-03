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

	// 出力
	void Render()
	{
		cout << "Model data: " << model.GetData() << endl;

		// 入金方法の選択
		model.SelectMoney();

		// 入金
		model.Payment();

		// 購入処理
		model.Transaction();

		// 結果表示
		model.Result();
	}

private:
	Model model;
};

#endif // !VIEW_H