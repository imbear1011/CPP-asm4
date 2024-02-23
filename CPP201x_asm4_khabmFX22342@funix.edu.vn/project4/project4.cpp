// Project4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include "Setting.h"
#include "Car.h"
#include "BinarySearchTree.h"

using namespace std;

BST carTree;
int carCnt = 0;

void Main_Menu();
void Input_Menu();
void Print_Menu();

void Input_Display();
void Input_Sound();
void Input_General();

void Print_CommonInfo(CommonInfo* data);//In thông tin chung của xe được cài đặt

void CheckID(string key, Car* data ){
	if (carTree.Search(key) != NULL) {
		//Nếu đối tượng đã tồn tại thì thay thế bằng thông tin mới
		cout << "       -> This car already existed, data will be overwritten." << endl;
		
		carTree.OverWrite(data);
	}
	else
	{
		//Nếu chưa thì insert vào BST
		cout << "       -> This is new car, data will be append to your list." << endl;
		carTree.Insert(data);
	}
}

int main() {
	carTree.LoadDataFromStorage();
	Main_Menu();
	return 0;
}

void Main_Menu() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. INPUT SETTING INFORMATION" << endl;
		cout << "2. PRINT SETTING INFORMATION" << endl;
		cout << "3. EXIT" << endl;
		cout << "Your selection: ";
		getline(cin, inputkey);
	} while (!ValidateInput(inputkey, VALIDATE_INPUT_MENU));
	int selection = stoi(inputkey);

	switch (selection) {
	case 1:
		Input_Menu();
		break;
	case 2:
		Print_Menu();
		break;
	case 3:
		cout << endl;
		cout << "GOOD BYE !!!" << endl;
		break;
	default:
		cout << "Invalid choice, please enter again" << endl;
		system("pause");
		Main_Menu();
		break;
	}
}

void Input_Menu() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. DISPLAY SETTING" << endl;
		cout << "2. SOUND SETTING" << endl;
		cout << "3. GENERAL SETTING" << endl;
		cout << "4. RETURN" << endl;
		cout << "Your selection: ";
		getline(cin, inputkey);
	} while (!ValidateInput(inputkey, VALIDATE_INPUT_MENU));
	int selection = stoi(inputkey);
	switch (selection) {
	case 1:
		Input_Display();
		break;
	case 2:
		Input_Sound();
		break;
	case 3:
		Input_General();
		break;
	case 4:
		Main_Menu();
		break;
	default:
		cout << "Invalid choice, please enter again" << endl;
		system("pause");
		Input_Menu();
		break;
	}
}

void Print_Menu() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. PRINT DISPLAY SETTING INFORMATION" << endl;
		cout << "2. PRINT SOUND SETTING INFORMATION" << endl;
		cout << "3. PRINT GENERAL SETTING INFORMATION" << endl;
		cout << "4. PRINT ALL SETTING INFORMATION" << endl;
		cout << "5. RETURN" << endl;
		cout << "Your selection: ";
		getline(cin, inputkey);
	} while (!ValidateInput(inputkey, VALIDATE_INPUT_MENU));
	int selection = stoi(inputkey);

	switch (selection) {
	case 1:
		carTree.Print(1);
		break;
	case 2:
		carTree.Print(2);
		break;
	case 3:
		carTree.Print(3);
		break;
	case 4:
		carTree.Print(4);
		break;
	case 5:
		Main_Menu();
		break;
	default:
		cout << "Invalid choice, please enter again" << endl;
		break;
	}
	system("pause");
	Main_Menu();
}

void Print_CommonInfo(CommonInfo* data) {
	cout << "    Owner: " << data->getName() << endl;
	cout << "    Email: " << data->getEmail() << endl;
	cout << "    Key number: " << data->getPersonalKey() << endl;
	cout << "    ODO number: " << data->getODO() << endl;
	cout << "    Remind service (km): " << data->getServiceRemind() << endl;
}

void Input_Display() {
	string inputkey = "n";
	do {
		system("cls");
		if (carTree.Size() <= 99) {
			carCnt = carTree.Size() + 1;
			Car* car = new Car;
			car->getCommonInfo()->nhapThongTin();//Nhập CommnonInfo
			car->getDisplay()->nhapThongTin();//Nhập DisplayInfo
			do {
				system("cls");
				cout << "----- Input Display Setting ------" << endl;
				cout << "Car index: " << carCnt << endl;
				Print_CommonInfo(car->getCommonInfo());
				CheckID(car->getCommonInfo()->getPersonalKey(), car);
				//Ghi dữ liệu vào file Setting.txt
				carTree.WriteDataToStorage();
				cout << "    Light level: " << car->getDisplay()->get_light_level() << endl;
				cout << "    Screen light level: " << car->getDisplay()->get_screen_light_level() << endl;
				cout << "    Taplo light level: " << car->getDisplay()->get_taplo_light_level() << endl;
				cout << "Will you input for car " << carCnt + 1 << " (y/n): " << endl;
				cout << "Please enter y or n: ";
				getline(cin, inputkey);
			} while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO));
		}
		else {
			cout << "Da vuot qua so luong xe cho phep cai dat." << endl;
			system("pause");
			break;
		}
	} while (inputkey == "y" || inputkey == "Y"); //Nếu người dùng chọn yes thì tiếp tục nhập thông tin display
	Main_Menu();
}

void Input_Sound() {
	string inputkey = "n";
	do {
		if (carTree.Size() <= 99) {
			system("cls");
			carCnt = carTree.Size() + 1;
			Car* car = new Car;
			car->getCommonInfo()->nhapThongTin();//Nhập CommnonInfo
			car->getSound()->nhapThongTin();//Nhập SoundInfo
			do {
				system("cls");
				cout << "----- Input Sound Setting ------" << endl;
				cout << "Car index: " << carCnt << endl;
				Print_CommonInfo(car->getCommonInfo());
				CheckID(car->getCommonInfo()->getPersonalKey(), car);
				//Lưu dữ liệu vào file Setting.txt
				carTree.WriteDataToStorage();
				cout << "    Media volume: " << car->getSound()->get_media_level() << endl;
				cout << "    Call volume: " << car->getSound()->get_call_level() << endl;
				cout << "    Navigation volume: " << car->getSound()->get_navi_level() << endl;
				cout << "    Notification volume: " << car->getSound()->get_notification_level() << endl;
				cout << "Will you input for car " << carCnt + 1 << " (y/n): " << endl;
				cout << "Please enter y or n: ";
				getline(cin, inputkey);
			} while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO));
		}
		else {
			cout << "Da vuot qua so luong xe cho phep cai dat." << endl;
			system("pause");
			break;
		}
	} while (inputkey == "y" || inputkey == "Y");//Nếu người dùng chọn yes thì tiếp tục nhập thông tin sound
	Main_Menu();
}

void Input_General() {
	string inputkey = "n";
	do {
		if (carTree.Size() <= 99) {
			system("cls");
			carCnt = carTree.Size() + 1;
			Car* car = new Car;
			car->getCommonInfo()->nhapThongTin();//Nhập CommnonInfo
			car->getGeneral()->nhapThongTin();//Nhập GeneralInfo
			do {
				system("cls");
				cout << "----- Input General Setting ------" << endl;
				cout << "Car index: " << carCnt << endl;
				Print_CommonInfo(car->getCommonInfo());
				CheckID(car->getCommonInfo()->getPersonalKey(), car);
				//Lưu dữ liệu vào file Setting.txt
				carTree.WriteDataToStorage();
				cout << "    Timezone: " << car->getGeneral()->get_timeZone() << endl;
				cout << "    Language:" << car->getGeneral()->get_language() << endl;
				cout << "Will you input for car " << carCnt + 1 << " (y/n): " << endl;
				cout << "Please enter y or n: ";
				getline(cin, inputkey);
			} while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO));
		}
		else {
			cout << "Da vuot qua so luong xe cho phep cai dat." << endl;
			system("pause");
			break;
		}
	} while (inputkey == "y" || inputkey == "Y"); //Nếu người dùng chọn yes thì tiếp tục nhập thông tin general
	Main_Menu();
}

