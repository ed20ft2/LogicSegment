#include "PButtons.h"
#include "Setting.h"

PButtons::PButtons(const std::string& text, int x, int y, int w, int h)
	:Setting(x, y, w, h), m_text(text)
{

}

void PButtons::represent()
{
	setfillcolor(current_color);
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 40);

	setlinestyle(PS_SOLID, 5);
	setlinecolor(BLACK); // changes the colour of the border around the menu buttons
	settextcolor(BLACK); // chnages the colour of the text

	int tx = m_x + (m_w - textwidth(m_text.c_str())) / 2;
	int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(tx, ty, m_text.c_str());
}

bool PButtons::isin()
{
	//set conditions when mouse button is clicked, avaliable area should be exactly same as button area.
	if (m_msg.x >= m_x && m_msg.x < m_x + m_w && m_msg.y >= m_y && m_msg.y < m_y + m_h)
	{
		return true;
	}
	return false;
}

bool PButtons::isClicked()
{
	if (isin())
	{
		if (m_msg.message == WM_LBUTTONDOWN) //left mouse button
		{
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void PButtons::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	if (isin())
	{
		current_color = mouse_over;
	}
	else
	{
		current_color = normal_color;
	}
}
