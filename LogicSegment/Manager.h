#pragma once
#include  <vector>

#include "Display.h"
#include "easyx.h"
#include "PButtons.h"

//this file is used to add some complimentation parameter for window and the function test.
class Manager
{
	enum Operator
	{
		Item_Menu1,
		Item_Menu2,
		Item_Menu3,
		Item_Menu4,
		Menu = 66 // keyboard settings
	};

public:
	Manager();
	int  menu();
	void run();
	void Item1();
	void Item2();
	void Item3();
	void Item4();

	void probackground();
	void eventloop();

private:
	IMAGE m_prb;
	ExMessage m_msg;
	// used to get information from your keyboard and your mouse
	std::vector<PButtons*>menu_btns;
};
