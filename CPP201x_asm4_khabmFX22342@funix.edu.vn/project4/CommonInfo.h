#ifndef COMMON_H_
#define COMMON_H_

#include "Setting.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CommonInfo{
public:
	CommonInfo();
	~CommonInfo();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	string getName();
	string getPersonalKey();
	string getEmail();
	int getODO();
	int getServiceRemind();
	void setName(string data);
	void setPersonalKey(string data);
	void setEmail(string data);
	void setODO(int data);
	void setServiceRemind(int data);
private:
	string name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};

#endif // COMMON_H_
