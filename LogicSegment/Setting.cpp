#include "Setting.h"

Setting::Setting(int x, int y, int w, int h)
	:m_x(x), m_y(y), m_w(w), m_h(h)
{

}

int Setting::width()
{
	return m_w;
}

int Setting::height()
{
	return m_h;
}

void Setting::setFixsize(int w, int h)
{
	this->m_w = w;
	this->m_h = h;
}

int Setting::x()
{
	return m_x;
}

int Setting::y()
{
	return m_y;
}

void Setting::move(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}
