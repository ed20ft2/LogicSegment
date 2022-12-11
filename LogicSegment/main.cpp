// Group Project - 2645 - University of Leeds
// Members : Farhan Tanvir | Wenchao He | Mohammed Althagafi

// Libraries
#include <iostream>
#include <regex>

// easyx header files
#include "easyx.h" // easyx.h for the downloaded library to work
#include "graphics.h" // this is required for the application menu system to work

// Farhans header files
#include "Display.h" // Controls variables -- Application display, resolution size
#include "Manager.h" // File for all the functions
#include "Setting.h" // Dimensions

// Item 2
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))


// CLI System
void main_menu();

int get_user_input();

void select_menu_item(int input);
void print_main_menu();
void go_back_to_main();

bool is_integer(std::string num);

void menu_item_1();
void menu_item_2();
void menu_item_3();

int main(int argc, char const* argv[]) {
    main_menu();
    return 0;
}

void main_menu() {
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}

int get_user_input() {
    int input;
    std::string input_string;
    bool valid_input = false;
    int menu_items = 4; // number of menu items within the get_user_input

    do {
        std::cout << "\nSelect item: ";
        std::cin >> input_string;
        valid_input = is_integer(input_string);
        // if input is not an integer, print an error message
        if (valid_input == false) {
            std::cout << "Enter an integer!\n";
        }
        else {  // if it is an int, check whether in range
            input = std::stoi(input_string);  // convert to int
            if (input >= 1 && input <= menu_items) {
                valid_input = true;
            }
            else {
                std::cout << "Invalid menu item!\n";
                valid_input = false;
            }
        }
    } while (valid_input == false);

    return input;
}

void select_menu_item(int input) {
    switch (input) {
    case 1:
        menu_item_1(); //Me
        break;
    case 2:
        menu_item_2(); //Wenchao
        break;
    case 3:
        menu_item_3(); //Mohammad
        break;
    default:
        exit(1);
        break;
    }
}

void print_main_menu() {
    std::cout << "  |---------------------|\n";
    std::cout << "  |-------Group 7-------|\n";
    std::cout << "  |---------------------|\n";
    std::cout << "  |\t           \t|\n";
    std::cout << "  |\tMenu item 1\t|\n";
    std::cout << "  |\tMenu item 2\t|\n";
    std::cout << "  |\tMenu item 3\t|\n";
    std::cout << "  |\tExit       \t|\n";
    std::cout << "  |\t           \t|\n";
    std::cout << "  |---------------------|\n";
}

void go_back_to_main() {
    std::string input;
    do {
        std::cout << "\n\nEnter 'b' or 'B' to go back to main menu: ";
        std::cin >> input;
    } while (input != "b" && input != "B");
    main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit

bool is_integer(std::string num) {
    return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

// Farhan Tanvir
void menu_item_1() {
    std::cout << "\n>> Menu 1\n";
    //my own window
    Display w(400, 600, EW_SHOWCONSOLE); // Using this you can change the dimensions of the window
    w.setDisplayTitle("Logic Segment"); // Changes the name of the application
    //back_ground();
    Manager wi;
    wi.run();
    go_back_to_main();
}

// Wenchao He
void menu_item_2()
{
    std::cout << "\n>> Menu 2\n";
    std::cout << "\nSome code here does something useful\n";
    // you can call a function from here that handles menu 4
    go_back_to_main();
}

// Mohammed Althagafi
void menu_item_3() {
    std::cout << "\n>> Menu 3\n";
    std::cout << "\nSome code here does something useful\n";
    // you can call a function from here that handles menu 3
    go_back_to_main();
}