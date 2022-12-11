#pragma once
#include "Config.h"

class Display
{
public:
	Display(int w, int h, int flag);
	void setDisplayTitle(const std::string& title);
	int exec();

	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	//keyboard and mouse operation in the menu:
	//check if there is a message from keyboard or mouse.
	inline static bool hasMsg() { return ::peekmessage(&m_msg, EX_KEY | EX_MOUSE); }
	inline static const ExMessage& getMsg() { return m_msg; }

private:
	HWND m_handle;  //windows setting;
	inline static ExMessage m_msg; //message from keybard and mouse 
	// (static format is used to make sure that it can be found by pointer).
};

