#include "General.h"

General::General()
{
	timeZone = "None";
	language = " None";
}

General::~General()
{
}

void General::nhapThongTin()
{
	vector<string> timezoneList = downloadTimezone();
	vector<string> languageList = downloadLanguage();

	string timeZoneChoose;
	string languageChoose;
	//SETTING TIMEZONE
	string input_time;
		do {
			system("cls");
			cout << "--- SELECT TIMEZONE DATA ---" << endl;
			for (int i = 0; i < timezoneList.size(); i++) {
				cout << i + 1 << ": " << timezoneList[i] << endl;
			}
			cout << "YOUR SELECTION: ";
			getline(cin, input_time);
			
		} while (!ValidateInput(input_time, VALIDATE_INPUT_NUMBER) || stoi(input_time) > 32);//Chỉ có 32 giá trị timezone nên người dùng không nhập vào quá 32
	//SETTING LANGUAGE
	string input_language;
	do {
		system("cls");
		cout << "--- SELECT LANGUAGE DATA ---" << endl;
		for (int i = 0; i < languageList.size(); i++) {
			cout << i + 1 << ":" << languageList[i] << endl;
		}
		cout << "YOUR SELECTION: ";
		getline(cin, input_language);
	} while (!ValidateInput(input_language, VALIDATE_INPUT_NUMBER) || stoi(input_language) > 30);//Chỉ có 30 language nên giá trị nhập vào không được vượt quá 30

	timeZoneChoose = timezoneList[stoi(input_time) - 1];
	set_timeZone(explode(timeZoneChoose)[0]);
	languageChoose = languageList[stoi(input_language) - 1];
	set_language(languageChoose);
	
}

void General::xuatThongTin()
{
	cout << left << setw(14) << get_timeZone() << setw(15) << get_language() << endl;
}

string General::get_language()
{
	return language;
}

string General::get_timeZone()
{
	return timeZone;
}

void General::set_timeZone(string data)
{
	timeZone = data;
}

void General::set_language(string data)
{
	language = data;
}
