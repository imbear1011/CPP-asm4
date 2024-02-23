#include "CommonInfo.h"

CommonInfo::CommonInfo()
{
	name = "None";
	personal_key = "None";
	email = "None";		
	odo = 0;
	service_remind = 0;
}

CommonInfo::~CommonInfo()
{
}

void CommonInfo::nhapThongTin()
{
	string name, email, id, odo, sv;
	//cin.ignore();	//Xóa bộ nhớ đệm trước khi getline để bò qua ký tự '\n'

	/*				ENTER OWNER NAME			*/
	do {
		system("cls");
		cout << "--- SETTING USER INFORMATION ---" << endl;
		cout << "Owner name: ";
		getline(cin, name);
	} while (!ValidateInput(name, VALIDATE_NAME));
	setName(name);


	/*				ENTER PRIVATE ID			*/
	do {
		system("cls");
		cout << "--- SETTING USER INFORMATION ---" << endl;
		cout << "Owner name: " << name << endl;
		cout << "Private ID: ";
		getline(cin, id);
	} while (!ValidateInput(id, VALIDATE_ID));	//Nếu ID nhập vào không hợp lệ thì nhập lại, các thông tin đã lưu
	setPersonalKey(id);

	/*				ENTER OWNER EMAIL			*/
	do {
		system("cls");
		cout << "--- SETTING USER INFORMATION ---" << endl;
		cout << "Owner name: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email: ";
		getline(cin, email);
	} while (!ValidateInput(email, VALIDATE_EMAIL));
	setEmail(email);

	/*				ENTER CommonInfo ODO NUMBER			*/
	do {
		system("cls");
		cout << "--- SETTING USER INFORMATION ---" << endl;
		cout << "Owner name: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email: " << email << endl;
		cout << "ODO number: ";
		getline(cin, odo);
	} while (!ValidateInput(odo, VALIDATE_INPUT_NUMBER));
	setODO(stoi(odo));

	/*				ENTER SERVICE REMIND NUMBER			  */
	do {
		system("cls");
		cout << "--- SETTING USER INFORMATION ---" << endl;
		cout << "Owner name: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email: " << email << endl;
		cout << "ODO number: " << odo << endl;
		cout << "Remind service (km): ";
		getline(cin, sv);
	} while (!ValidateInput(sv, VALIDATE_INPUT_NUMBER));
	setServiceRemind(stoi(sv));
}

void CommonInfo::xuatThongTin()
{
	cout << left << setw(25) << getName() << setw(25) << getEmail() << setw(15) << getPersonalKey() << setw(15) << getODO() << setw(20) << getServiceRemind();
}

string CommonInfo::getName()
{
	return name;
}

string CommonInfo::getPersonalKey()
{
	return personal_key;
}

string CommonInfo::getEmail()
{
	return email;
}

int CommonInfo::getODO()
{
	return odo;
}

int CommonInfo::getServiceRemind()
{
	return service_remind;

}

void CommonInfo::setName(string data)
{
	name = data;
}

void CommonInfo::setPersonalKey(string data)
{
	personal_key = data;
}

void CommonInfo::setEmail(string data)
{
	email = data;
}

void CommonInfo::setODO(int data)
{
	odo = data;
}

void CommonInfo::setServiceRemind(int data)
{
	service_remind = data;
}
