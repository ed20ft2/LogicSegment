#include <iostream>
#include <vector> // Menu system
#include <easyx.h> // easyx.h graphic
#include <conio.h> // input and output
#include <graphics.h> // easyx.h requirement
#include <cmath> // item 4
#include <string>

// header files
#include "Display.h"
#include "Manager.h"

using namespace std;

# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

Manager::Manager()
{
	//set up the main menu back ground:
	::loadimage(&m_prb, "image/bgk.jpg", Display::width(), Display::height());

	//set up the main menu button:
	menu_btns.push_back(new PButtons("4-bit Output Finder")); // sets the title for button 1
	menu_btns.push_back(new PButtons("Truth Table Calculator")); // sets the title for button 2
	menu_btns.push_back(new PButtons("1's and 2's Complement")); // sets the title for button 3
	menu_btns.push_back(new PButtons("Bin&Hex&Dec Converter")); // sets the title for button 4
	menu_btns.push_back(new PButtons("Exit"));   // sets the title for button 5

	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->setFixsize(250, 50); //sets width and height of the menu buttons

		int bx = (Display::width() - menu_btns[i]->width()) / 2;
		// 150, I chose this because the video I learned this menu system from, the line of code originally set to establish the 'middle'
		// of the application menu did not work unfortunately. So I started experimenting with different values.
		int by = 130 + i * menu_btns[i]->height();

		menu_btns[i]->move(bx, by);
	}
}

void Manager::run()
{
	std::cin.ignore();
	int op = Menu;
	Display::beginDraw();
	while (true) {

		Display::clear();
		probackground();

		if (Display::hasMsg()) {
			m_msg = Display::getMsg();
			switch (m_msg.message)
			{
			case WM_KEYDOWN:
				if (m_msg.vkcode == VK_ESCAPE) {
					op = Menu;
				}
				break;
			default:
				break;
			}
		}
		switch (op)
		{
		case Menu:
			op = menu();
			break;
		case Manager::Item_Menu1:
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			Item1();
			op = menu();
			break;
		case Manager::Item_Menu2:
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			Item2();
			op = menu();
			break;
		case Manager::Item_Menu3:
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			Item3();
			op = menu();
			break;
		case Manager::Item_Menu4:
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			Item4();
			op = menu();
			break;
		default:
			closegraph();
			return;
			break;
		}
		Display::flushDraw();
	}
	Display::endDraw();
}

int Manager::menu()
{
	//outtextxy(0, 0, "menu");
	/*std::cout << "menu\n" << std::endl;
	Window::flushDraw();
	int op = 0;
	cin>> op;*/  //TEST PURPOSE ONLY.

	outtextxy(0, 0, "Menu: Please select an Item from the application ");
	for (auto btn : menu_btns)
	{
		btn->represent();
	}
	for (int i = 0; i < menu_btns.size(); i++) {
		menu_btns[i]->represent();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isClicked())
		{
			return i;
		}
	}
	return Menu;
}

// Item 3
// https://codescracker.com/cpp/program/cpp-program-convert-hexadecimal-to-decimal.htm
// C++ program to print 1's and 2's complement of a binary number
// Returns '0' for '1' and '1' for '0'
char flip(char c) { return (c == '0') ? '1' : '0'; }
void printOneAndTwosComplement(string bin) {
	int n = bin.length();
	int i;

	string ones, twos;
	ones = twos = "";

	//  for ones complement flip every bit
	for (i = 0; i < n; i++)
		ones += flip(bin[i]);
	// twos complement
	twos = ones;
	for (i = n - 1; i >= 0; i--)
	{
		if (ones[i] == '1')
			twos[i] = '0';
		else
		{
			twos[i] = '1';
			break;
		}
	}
	// If No break : all are 1  as in 111  or  11111;
	// in such case, add extra 1 at beginning
	if (i == -1)
		twos = '1' + twos;
	cout << "\n1's complement: " << ones << endl;
	cout << "\n2's complement: " << twos << endl;
}
// https://www.geeksforgeeks.org/1s-2s-complement-binary-number/

/// Item 4
int i = 0;
char hexDecNum[20];
unsigned long HexDecToDec(char[]); // k = 2
unsigned long HexDecToDec(char hexDecNum[]) {
	char* hexDecPointer;
	int i, len = 0;
	const int base = 16;
	unsigned long decimalNum = 0;
	// Find the len of Hexadecimal Number
	for (hexDecPointer = hexDecNum; *hexDecPointer != '\0'; hexDecPointer++)
		len++;
	// Again initialize the starting address of Hexadecimal Number
	hexDecPointer = hexDecNum;
	// Now convert hex digit to decimal number one by one
	for (i = 0; *hexDecPointer != '\0' || i < len; i++, hexDecPointer++)
	{
		if (*hexDecPointer >= 48 && *hexDecPointer <= 57)
			decimalNum = decimalNum + (*hexDecPointer - 48) * pow(base, len - i - 1);
		else if (*hexDecPointer >= 65 && *hexDecPointer <= 70)
			decimalNum = decimalNum + (*hexDecPointer - 55) * pow(base, len - i - 1);
		else if (*hexDecPointer >= 97 && *hexDecPointer <= 102)
			decimalNum = decimalNum + (*hexDecPointer - 87) * pow(base, len - i - 1);
		else
			len = 0;
	}
	if (len == 0)
		return 0;
	else
		return decimalNum;
}


// Menu items
void Manager::Item1() // 4-bit Truth Table Finder
{
	//std::cout << "\n>> Item 1\n";
	std::string c;
	std::cout << "\nNOTE:After pressing enter twice, you can select another item from the menu!\n";
	std::cout << "\nPlease, enter your y output for the calculator to find your Logic gate: ";
	std::getline(std::cin, c);

	//https://cplusplus.com/reference/string/string/getline/

	if (c == "0001") {
		printf("\nYour gate is a Logic AND gate!\n");
		std::cout << "\n\t --- [ Truth Table ] ---\n";
		std::cout << "\t|   a   |   b   |  out  |\n";
		std::cout << "\t|   0   |   0   |   0   |\n";
		std::cout << "\t|   0   |   1   |   0   |\n";
		std::cout << "\t|   1   |   0   |   0   |\n";
		std::cout << "\t|   1   |   1   |   1   |\n";
		std::cout << "\t-------------------------\n";
		Item1();
	}
	else if (c == "0111") {
		printf("\nYour gate is a Logic OR gate!\n");
		std::cout << "\n\t--- [ Truth Table ] ---\n";
		std::cout << "\t|   a   |   b   |  out  |\n";
		std::cout << "\t|   0   |   0   |   0   |\n";
		std::cout << "\t|   0   |   1   |   1   |\n";
		std::cout << "\t|   1   |   0   |   1   |\n";
		std::cout << "\t|   1   |   1   |   1   |\n";
		std::cout << "\t-------------------------\n";
		Item1();
	}
	else if (c == "10") {
		printf("\nYour gate is a Logic NOT gate!");
		std::cout << "\n\t[  Truth Table  ]\n";
		std::cout << "\t|  in   |  out  |\n";
		std::cout << "\t|   0   |   1   |\n";
		std::cout << "\t|   1   |   0   |\n";
		std::cout << "\t-----------------\n";
		Item1();
	}
	else if (c == "1110") {
		printf("\nYour gate is a Logic NAND gate!\n");
		std::cout << "\n\t--- [ Truth Table ] ---\n";
		std::cout << "\t|   a   |   b   |  out  |\n";
		std::cout << "\t|   0   |   0   |   1   |\n";
		std::cout << "\t|   0   |   1   |   1   |\n";
		std::cout << "\t|   1   |   0   |   1   |\n";
		std::cout << "\t|   1   |   1   |   0   |\n";
		std::cout << "\t-------------------------\n";
		Item1();
	}
	else if (c == "01") {
		printf("\nYour gate is a Logic Buffer gate!");
		std::cout << "\n\t[  Truth Table  ]\n";
		std::cout << "\t|  in   |  out  |\n";
		std::cout << "\t|   0   |   0   |\n";
		std::cout << "\t|   1   |   1   |\n";
		std::cout << "\t-----------------\n";
		Item1();
	}
	else if (c == "0110") {
		printf("\nYour gate is a Logic XOR gate!\n");
		std::cout << "\n\t--- [ Truth Table ] ---\n";
		std::cout << "\t|   a   |   b   |  out  |\n";
		std::cout << "\t|   0   |   0   |   0   |\n";
		std::cout << "\t|   0   |   1   |   1   |\n";
		std::cout << "\t|   1   |   0   |   1   |\n";
		std::cout << "\t|   1   |   1   |   0   |\n";
		std::cout << "\t-------------------------\n";
		Item1();
	}
	else if (c == "1001") {
		printf("\n\tYour gate is a Logic XNOR gate!");
		std::cout << "\n\t--- [ Truth Table ] ---\n";
		std::cout << "\t|   a   |   b   |  out  |\n";
		std::cout << "\t|   0   |   0   |   1   |\n";
		std::cout << "\t|   0   |   1   |   0   |\n";
		std::cout << "\t|   1   |   0   |   0   |\n";
		std::cout << "\t|   1   |   1   |   1   |\n";
		std::cout << "\t-------------------------\n";
		Item1();
	}
	else if (c == "") {
		printf("\nYou pressed Enter to leave! Press Enter again to confirm!");
		run();
	}
	else {
		printf("\nYour gate input is either incorrect");
		Item1();
	}
}

void Manager::Item2()
{
	outtextxy(0, 0, "Menu Item 2");
	cout << "Item 2\n";
}

void Manager::Item3() //	1's and 2's Complement Converter
{
	string code3;
	cout << "Type your n-bit code: ";
	cin >> code3; // get user input from the keyboard
	string bin = code3;
	printOneAndTwosComplement(bin);

	std::string c;
	std::cout << "\nPress Enter twice to exit this Menu Item\n";
	std::getline(std::cin, c);

	std::cin.ignore();
	if (c == "") {
		printf("\nPress Enter again to confirm!");
		run();
	}
}

void Manager::Item4() // Converter Calculator (Bin,Dec,Hex)
{
	// printf("Item is working") TEST ONLY
	outtextxy(0, 0, "Menu Item 4");
	cout << "Bin&Hex&Bin Converter\n";

	std::cout << "\t---- [ Converter ] ----\n";
	std::cout << "\tBinary to Hexadecimal  (1)\n";
	std::cout << "\tBinary to Decimal      (2)\n";
	std::cout << "\tHexadecimal to Binary  (3)\n";
	std::cout << "\tHexadecimal to Decimal (4)\n";
	std::cout << "\tDecimal to Binary      (5)\n";
	std::cout << "\tDecimal to Hexadecimal (6)\n";
	std::cout << "\t---------Exit--------- (7)\n";

	// https://www.w3schools.com/cpp/cpp_do_while_loop.asp Instead of using an integer, I chose to use a boolean variable.
	bool looper = false;
	do {
		int k = 0;
		std::cout << "\n\n---> Converter Option: ";
		std::cin >> k;
		// Binary to Hexadecimal
		//https://codescracker.com/cpp/program/cpp-program-convert-binary-to-hexadecimal.htm
		if (k == 1) {
			int binaryNum, hex = 0, mul = 1, chk = 1, rem, i = 0;
			char hexDecNum[20];
			printf("[8-bit limit] for this converter\n"); 
			cout << "Enter any Binary Number: ";
			cin >> binaryNum;
			while (binaryNum != 0)
			{
				rem = binaryNum % 10;
				hex = hex + (rem * mul);
				if (chk % 4 == 0)
				{
					if (hex < 10)
						hexDecNum[i] = hex + 48;
					else
						hexDecNum[i] = hex + 55;
					mul = 1;
					hex = 0;
					chk = 1;
					i++;
				}
				else
				{
					mul = mul * 2;
					chk++;
				}
				binaryNum = binaryNum / 10;
			}
			if (chk != 1)
				hexDecNum[i] = hex + 48;
			if (chk == 1)
				i--;
			cout << "\nEquivalent Value in Hexadecimal: ";
			for (i = i; i >= 0; i--)
				cout << hexDecNum[i];
		}
		// Binary to Decimal
		// https://codescracker.com/cpp/program/cpp-program-convert-binary-to-decimal.htm
		else if (k == 2) { 
			printf("[10-bit limit] for this converter\n");
			int binnum, decnum = 0, i = 1, rem;
			cout << "Enter any Binary Number: ";
			cin >> binnum;
			while (binnum != 0)
			{
				rem = binnum % 10;
				decnum = decnum + (rem * i);
				i = i * 2;
				binnum = binnum / 10;
			}
			cout << "\nEquivalent Decimal Value = " << decnum;
		}
		// Hexadecimal to Binary
		// https://codescracker.com/cpp/program/cpp-program-convert-hexadecimal-to-binary.htm
		else if (k == 3) { 
			int i = 0;
			printf("[0 to F] Limit for this section\n");
			char hexDecNum[10];
			cout << "Enter the Hexadecimal Number: ";
			cin >> hexDecNum;
			cout << "\nEquivalent Binary Value = ";
			while (hexDecNum[i])
			{
				switch (hexDecNum[i])
				{
				case '0':
					cout << "0000";
					break;
				case '1':
					cout << "0001";
					break;
				case '2':
					cout << "0010";
					break;
				case '3':
					cout << "0011";
					break;
				case '4':
					cout << "0100";
					break;
				case '5':
					cout << "0101";
					break;
				case '6':
					cout << "0110";
					break;
				case '7':
					cout << "0111";
					break;
				case '8':
					cout << "1000";
					break;
				case '9':
					cout << "1001";
					break;
				case 'A':
				case 'a':
					cout << "1010";
					break;
				case 'B':
				case 'b':
					cout << "1011";
					break;
				case 'C':
				case 'c':
					cout << "1100";
					break;
				case 'D':
				case 'd':
					cout << "1101";
					break;
				case 'E':
				case 'e':
					cout << "1110";
					break;
				case 'F':
				case 'f':
					cout << "1111";
					break;
				default:
					cout << "--Invalid Hex Digit (" << hexDecNum[i] << ")--";
				}
				i++;
			}
		}
		// Hexadecimal to Decimal
		// https://codescracker.com/cpp/program/cpp-program-convert-hexadecimal-to-decimal.htm
		else if (k == 4) { 
			unsigned long decimalNum;
			char hexDecNum[10];
			printf("[0 to F] Limit for this section\n");
			cout << "\nEnter the Hexadecimal Number: ";
			cin >> hexDecNum;
			decimalNum = HexDecToDec(hexDecNum);
			if (decimalNum == 0)
				cout << "\nInvalid Hex Digit!";
			else
				cout << "\nEquivalent Decimal Value: " << decimalNum;
		}
		// Decimal to Binary
		// https://codescracker.com/cpp/program/cpp-program-convert-decimal-to-binary.htm
		else if (k == 5) { 
			int decimalNum, binaryNum[20], i = 0;
			printf("[256] Limit for this section\n");
			cout << "Enter the Decimal Number: ";
			cin >> decimalNum;
			while (decimalNum != 0)
			{
				binaryNum[i] = decimalNum % 2;
				i++;
				decimalNum = decimalNum / 2;
			}
			cout << "\nEquivalent Binary Value: ";
			for (i = (i - 1); i >= 0; i--)
				cout << binaryNum[i];
		}
		// Decimal to Hexadecimal
		// https://codescracker.com/cpp/program/cpp-program-convert-decimal-to-hexadecimal.htm
		else if (k == 6) {
			int decimalNum, rem, i = 0;
			char hexaDecimalNum[50];
			printf("[256] Limit for this section\n");
			cout << "Enter the Decimal Number: ";
			cin >> decimalNum;
			while (decimalNum != 0)
			{
				rem = decimalNum % 16;
				if (rem < 10)
					rem = rem + 48;
				else
					rem = rem + 55;
				hexaDecimalNum[i] = rem;
				i++;
				decimalNum = decimalNum / 16;
			}
			cout << "\nEquivalent Hexadecimal Value: ";
			for (i = i - 1; i >= 0; i--)
				cout << hexaDecimalNum[i];
		}
		// Exit
		else if (k == 7) { 
			looper = true;
		}
	} while (looper == false);

	std::string c;
	std::cout << "\nPress Enter twice to exit this Menu Item\n";
	std::getline(std::cin, c);

	std::cin.ignore();
	if (c == "") {
		printf("\nPress Enter again to confirm!");
		run();
	}
}
// https://replit.com/@ed20ft2/Binary2Hex-MenuItem4#main.cpp << Link of me testing this Item 4 in Replit before implementing it in Visual Studio Code

void Manager::probackground()
{
	::putimage(0, 0, &m_prb);
}