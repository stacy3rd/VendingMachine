//======================================
// Controller.h
// =====================================
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "View.h"

using namespace std;

class Controller
{
public:
	Controller(Model &model,View &view)
	{
		this->SetModel(model);
		this->SetView(view);
		cout << "Application start!" << endl;
	}

	~Controller(){}

	void SetModel(const Model &model)
	{
		this->model = model;
	}

	void SetView(const View &view)
	{
		this->view = view;
	}

	// アプリケーションの起動時に
	void OnLoad()
	{
		this->view.Render();
	}



private:
	Model model;
	View view;

};

#endif // !CONTROLLER_H