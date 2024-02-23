#include "Sound.h"

Sound::Sound()
{
	media_level =  0;
	call_level =  0;
	navi_level =  0;
	notification_level = 0;
}

Sound::~Sound()
{
}

void Sound::nhapThongTin()
{
	string media, call, navi, noti;

	/*	         ENTER MEDIA VOLUME         */
	do {
		system("cls");
		cout << "SETTING VOLUME INFORMATION" << endl;
		cout << "Media volume: ";
		getline(cin, media);
	} while (!ValidateInput(media, VALIDATE_INPUT_DISPLAY_SOUND));
	set_media_level(stoi(media));

	/*	         ENTER CALL VOLUME         */
	do {
		system("cls");
		cout << "SETTING VOLUME INFORMATION" << endl;
		cout << "Media volume: " << media << endl;
		cout << "Call volume: ";
		getline(cin, call);
	} while (!ValidateInput(call, VALIDATE_INPUT_DISPLAY_SOUND));
	set_call_level(stoi(call));


	/*	         ENTER NAVIGATION VOLUME         */
	do {
		system("cls");
		cout << "SETTING VOLUME INFORMATION" << endl;
		cout << "Media volume: " << media << endl;
		cout << "Call volume: " << call << endl;
		cout << "Navigation volume: ";
		getline(cin, navi);
	} while (!ValidateInput(navi, VALIDATE_INPUT_DISPLAY_SOUND));
	set_navi_level(stoi(navi));

	/*	         ENTER NOTIFICATION VOLUME         */
	do {
		system("cls");
		cout << "SETTING VOLUME INFORMATION" << endl;
		cout << "Media volume: " << media << endl;
		cout << "Call volume: " << call << endl;
		cout << "Navigation volume: " << navi << endl;
		cout << "Notification volume: ";
		getline(cin, noti);
	} while (!ValidateInput(noti, VALIDATE_INPUT_DISPLAY_SOUND));
	set_notification_level(stoi(noti));
}

void Sound::xuatThongTin()
{
	cout << setw(10) << get_media_level() << setw(10) << get_call_level() << setw(10) << get_navi_level() << setw(10) << get_notification_level() << endl;
}

int Sound::get_media_level()
{
	return media_level;
}

int Sound::get_call_level()
{
	return call_level;
}

int Sound::get_navi_level()
{
	return navi_level;
}

int Sound::get_notification_level()
{
	return notification_level;
}

void Sound::set_media_level(int data)
{
	media_level = data;
}

void Sound::set_call_level(int data)
{
	call_level = data;
}

void Sound::set_navi_level(int data)
{
	navi_level = data;
}

void Sound::set_notification_level(int data)
{
	notification_level = data;
}
