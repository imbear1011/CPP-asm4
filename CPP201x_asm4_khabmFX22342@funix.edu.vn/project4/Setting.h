#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <algorithm>


using namespace std;


const auto VALIDATE_NAME = ".+";
const auto VALIDATE_EMAIL = "^\\w+\\@\\w+\\.\\w+(\\.\\w+)*$";	//Định dạng email là: name@abc.xyz(.vn)
const auto VALIDATE_ID = "^\\d{8}$";	//MSCN phải bao gồm 8 số
const auto VALIDATE_INPUT_NUMBER = "^[1-9]\\d*$";//chỉ dược nhập các số nguyên dương
const auto VALIDATE_INPUT_DISPLAY_SOUND = "^[1-5]$";//chỉ được nhập các số nguyên từ 1-5
const auto VALIDATE_INPUT_MENU = "^[1-9]+";	//input nhập vào phải là số (không có số 0 ở đầu E.g: 01 -> sai, 1 -> đúng)
const auto VALIDATE_INPUT_YES_NO = "^y$|^n$|^Y$|^N$";	//Các câu hỏi yes/no chỉ nhập vào y or n


bool ValidateInput(string str, const char* regExp);	//Xét tính hợp lệ của input
vector<string> downloadTimezone();//Trả về vector list Timezone lấy từ file Timezones.txt
vector<string> downloadLanguage();//Trả về vector list Language lấy từ file Languages.txt
const vector<string> explode(const string& s);//Tách một chuỗi theo ký tự phân tách rồi trả về vector lưu các chỗi đã phân tách
	

#endif /* SETTING_H_ */

