#include "Display.h"

Display::Display()
{
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::~Display()
{
}

void Display::nhapThongTin()
{
	string light_level, screen_light_level, taplo_light_level;

	/*			ENTER LIGHT LEVEL       */
	do {
		system("cls");
		cout << "--- SETTING DISPLAY INFORMATION ---" << endl;
		cout << "Light level: ";
		getline(cin, light_level);
	} while (!ValidateInput(light_level, VALIDATE_INPUT_DISPLAY_SOUND));
	set_light_level(stoi(light_level));


	/*			ENTER SCREEN LIGHT LEVEL       */
	do {
		system("cls");
		cout << "--- SETTING DISPLAY INFORMATION ---" << endl;
		cout << "Light level: " << light_level << endl;
		cout << "Screen light level: ";
		getline(cin, screen_light_level);
	} while (!ValidateInput(screen_light_level, VALIDATE_INPUT_DISPLAY_SOUND));
	set_screen_light_level(stoi(screen_light_level));


	/*			ENTER TAPLO LIGHT LEVEL       */
	do {
		system("cls");
		cout << "--- SETTING DISPLAY INFORMATION ---" << endl;
		cout << "Light level: " << light_level << endl;
		cout << "Screen light level: " << screen_light_level << endl;
		cout << "Taplo light level: ";
		getline(cin, taplo_light_level);
	} while (!ValidateInput(taplo_light_level, VALIDATE_INPUT_DISPLAY_SOUND));
	set_taplo_light_level(stoi(taplo_light_level));
}

void Display::xuatThongTin()
{
	//Car:xuatThongTin();
	cout << left << setw(10) << get_light_level() << setw(10) << get_screen_light_level() << setw(10) << get_taplo_light_level() << endl;
}

int Display::get_light_level()
{
	return light_level;
}

int Display::get_screen_light_level()
{
	return screen_light_level;
}

int Display::get_taplo_light_level()
{
	return taplo_light_level;
}

void Display::set_light_level(int data)
{
	light_level = data;
}

void Display::set_screen_light_level(int data)
{
	screen_light_level = data;
}

void Display::set_taplo_light_level(int data)
{
	taplo_light_level = data;
}
