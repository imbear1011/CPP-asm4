#include "Setting.h"

bool ValidateInput(string str, const char* regExp)
{
	regex regexInput(regExp);
	if (regex_match(str, regexInput))	//Kiem tra giá trị nhập từ bàn phím có match với định dạng cho sẵn hay không
		return true;
	cout << "Invalid input, please enter again" << endl;
	system("pause");
	return false;
}

vector<string> downloadTimezone() {
	vector<string> timezoneList;
	ifstream file;
	file.open("timezones.txt");
	try {
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {	//Lấy giá trị trong language.txt và lưu vào vector list_language
				timezoneList.push_back(line);
			}
		}
		else {
			throw "FAIL TO OPEN FILE";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		file.close();
	}
	file.close();
	return timezoneList;
}

vector<string> downloadLanguage() {
	vector<string> languageList;
	ifstream file;
	file.open("languages.txt");
	try {
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {	//Lấy giá trị trong language.txt và lưu vào vector list_language
				languageList.push_back(explode(line)[1]);
			}
		}
		else {
			throw "FAIL TO OPEN FILE";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		file.close();
	}
	file.close();
	sort(languageList.begin(), languageList.end());
	return languageList;
}

const vector<string> explode(const string& s)
{
	vector<string> res;
	string buff{ "" };
	for (auto n : s)
	{
		if (n != ',' && n != ';' && n!= '/') {
			buff += n;
			if (buff == "Common:" || buff == "Display:" || buff == "Sound:" || buff == "General:") {
				buff = "";
			}
		}
		else if ((n == ',' || n == ';' || n == '/') && buff != "")	//Nếu gặp phải các kí tự này thì ghi biến buff vào vector và reset biến buff để ghi dữ liệu mới
		{
			res.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")	//Ghi những giá trị sau dấu phẩy cuối cùng vào vector
		res.push_back(buff);
	return res;
}



