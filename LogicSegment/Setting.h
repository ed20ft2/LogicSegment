#pragma once
class Setting
{
public:
	Setting(int x, int y, int w, int h);

	//size parameter:
	int width();
	int height();
	void setFixsize(int w, int h);

	//dynamic parameter:
	int x();
	int y();
	void move(int x, int y);

	virtual void represent() = 0;

protected://if it's private, then the value would not be generated in the sub-class. 

	int m_x;
	int m_y;
	int m_w;
	int m_h;
};

