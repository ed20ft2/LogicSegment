// Libraries
#include <iostream>

// Headerfiles
#include "Display.h"
#include "Config.h"


Display::Display(int w, int h, int flag) {

	m_handle = ::initgraph(w, h, flag);
	::setbkmode(TRANSPARENT);
}
void Display::setDisplayTitle(const std::string& title)
{
	::SetWindowText(m_handle, title.c_str());
}

int Display::exec()
{
	return getchar();
}

int Display::width()
{
	return ::getwidth();
}

int Display::height()
{
	return ::getheight();
}

void Display::clear()
{
	::cleardevice();
}

void Display::beginDraw()
{
	::BeginBatchDraw();
}

void Display::flushDraw()
{
	::FlushBatchDraw();
}

void Display::endDraw()
{
	::EndBatchDraw();
}
