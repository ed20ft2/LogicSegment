#include "Config.h"
#include "Setting.h"

class PButtons :
    public Setting
{
public:
    PButtons(const std::string& text = "Pressbutton", int x = 0, int y = 0, int w = 200, int h = 40);
    void represent() override;
    bool isin();
    bool isClicked();


    void eventloop(const ExMessage& msg);//used to detect the information from the mouse.
private:
    std::string m_text;
    ExMessage m_msg;

    COLORREF current_color = RGB(232, 232, 236);// the current color of the menu;
    COLORREF normal_color = RGB(232, 232, 236);//normal color for the menu;
    COLORREF mouse_over = LIGHTBLUE;//color changes when mouse moves onto the button;

};