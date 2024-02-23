#include "BinarySearchTree.h"

BST::BST()
{
	root = NULL;
}

void BST::Insert(Car* data)
{
	
	if (root != NULL) {
		Insert(data, root);
		
	}
	else {
		root = new Node(data);
		root->left = NULL;
		root->right = NULL;
		count++;
	}
}

void BST::Insert(Car* data, Node* aNode)
{
	if (data->getCommonInfo()->getPersonalKey() < aNode->value->getCommonInfo()->getPersonalKey()) {
		if (aNode->left != NULL) {
			Insert(data, aNode->left);
		}
		else {
			aNode->left = new Node(data);
			aNode->left->left = NULL;
			aNode->left->right = NULL;
			count++;
		}
	}
	else if (data->getCommonInfo()->getPersonalKey() > aNode->value->getCommonInfo()->getPersonalKey()) {
		if (aNode->right != NULL) {
			Insert(data, aNode->right);
		}
		else {
			aNode->right = new Node(data);
			aNode->right->left = NULL;
			aNode->right->right = NULL;
			count++;
		}
	}

}

Node* BST::Search(string key)
{
	return Search(key, root);
}

Node* BST::Search(string key, Node* aNode)
{
	if (aNode != NULL) {
		if (key == aNode->value->getCommonInfo()->getPersonalKey()) {
			return aNode;
		}
		if (key < aNode->value->getCommonInfo()->getPersonalKey()) {
			return Search(key, aNode->left);
		}
		else {
			return Search(key, aNode->right);
		}
	}
	else {
		return NULL;
	}
	
}

void BST::OverWrite(Car* data)
{
	Search(data->getCommonInfo()->getPersonalKey())->value = data;
}

int BST::Size() {
	return count;
}

void BST::WriteDataToStorage(Node* aNode)
{
	fstream ofile;
	ofile.open("Setting.txt", ios::app | ios::ate);
	try {
		if (ofile.is_open()) {
			if (aNode != NULL) {
				WriteDataToStorage(aNode->left);
				ofile << "Common:"
					<< aNode->value->getCommonInfo()->getName() << ","
					<< aNode->value->getCommonInfo()->getEmail() << ","
					<< aNode->value->getCommonInfo()->getPersonalKey() << ","
					<< aNode->value->getCommonInfo()->getODO() << ","
					<< aNode->value->getCommonInfo()->getServiceRemind() << ";"
					<< "Display:"
					<< aNode->value->getDisplay()->get_light_level() << ","
					<< aNode->value->getDisplay()->get_screen_light_level() << ","
					<< aNode->value->getDisplay()->get_taplo_light_level() << ";"
					<< "Sound:"
					<< aNode->value->getSound()->get_media_level() << ","
					<< aNode->value->getSound()->get_call_level() << ","
					<< aNode->value->getSound()->get_navi_level() << ","
					<< aNode->value->getSound()->get_notification_level() << ";"
					<< "General:"
					<< aNode->value->getGeneral()->get_timeZone() << ","
					<< aNode->value->getGeneral()->get_language() << endl;
				WriteDataToStorage(aNode->right);
			}
		}
		else {
			throw "FAIL TO WRITE TO STORAGE";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	ofile.close();
}

void BST::WriteDataToStorage()
{
	ofstream ofile("Setting.txt", ios::out);
	ofile.close();
	WriteDataToStorage(root);
}

void BST::P_Display(Node* aNode)
{
	if (aNode != NULL) {
		P_Display(aNode->left);
		aNode->value->getCommonInfo()->xuatThongTin();
		aNode->value->getDisplay()->xuatThongTin();
		P_Display(aNode->right);
	}
}

void BST::P_Sound(Node* aNode)
{
	if (aNode != NULL) {
		P_Sound(aNode->left);
		aNode->value->getCommonInfo()->xuatThongTin();
		aNode->value->getSound()->xuatThongTin();
		P_Sound(aNode->right);
	}
}

void BST::P_General(Node* aNode)
{
	if (aNode != NULL) {
		P_General(aNode->left);
		aNode->value->getCommonInfo()->xuatThongTin();
		aNode->value->getGeneral()->xuatThongTin();
		P_General(aNode->right);
	}
}

void BST::P_All(Node* aNode)
{
	if (aNode != NULL) {
		P_All(aNode->left);
		cout << left << setw(5) << ++index << setw(25) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number" << setw(15) << "ODO number" << setw(20) << "Remind service" << endl;
		cout << setw(5) << " ";
		aNode->value->getCommonInfo()->xuatThongTin();
		cout << endl;
		cout << left << setw(5) << " " << setw(10) << "Display: " << setw(10) << "Light" << setw(10) << "Screen" << setw(10) << "Taplo" << endl;
		cout << setw(15) << " ";
		aNode->value->getDisplay()->xuatThongTin();
		cout << left << setw(5) << " " << setw(10) << "Sound: " << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
		cout << setw(15) << " ";
		aNode->value->getSound()->xuatThongTin();
		cout << left << setw(5) << " " << setw(10) << "General: " << setw(15) << "Timezone" << setw(15) << "Laguage" << endl;
		cout << setw(15) << " ";
		aNode->value->getGeneral()->xuatThongTin();
		cout << endl;
		P_All(aNode->right);
	}
}

void BST::Print(int i)
{
	switch (i) {
	case 1:
		cout << "--- Display setting ---" << endl;
		cout << left << setw(25) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number" << setw(15) << "ODO number" << setw(20) << "Remind service" << setw(10) << "Light" << setw(10) << "Screen" << setw(10) << "Taplo" << endl;
		P_Display(root);
		break;
	case 2:
		cout << "--- Sound setting ---" << endl;
		cout << left << setw(25) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number" << setw(15) << "ODO number" << setw(20) << "Remind service" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
		P_Sound(root);
		break;
	case 3:
		cout << "--- General setting ---" << endl;
		cout << left << setw(25) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number" << setw(15) << "ODO number" << setw(20) << "Remind service" << setw(15) << "Timezone" << setw(15) << "Language" << endl;
		P_General(root);
		break;
	case 4:
		index = 0;
		P_All(root);
		break;
	}
}

void BST::LoadDataFromStorage()
{
	vector<string> infoSetting;
	ifstream ifile("Setting.txt");
	try {
		if (ifile.is_open()) {
			string line;
			while (getline(ifile, line)) {
				infoSetting = explode(line);
				Car* car = new Car;
				//Common information
				car->getCommonInfo()->setName(infoSetting[0]);
				car->getCommonInfo()->setEmail(infoSetting[1]);
				car->getCommonInfo()->setPersonalKey(infoSetting[2]);
				car->getCommonInfo()->setODO(stoi(infoSetting[3]));
				car->getCommonInfo()->setServiceRemind(stoi(infoSetting[4]));
				//Display information
				car->getDisplay()->set_light_level(stoi(infoSetting[5]));
				car->getDisplay()->set_screen_light_level(stoi(infoSetting[6]));
				car->getDisplay()->set_taplo_light_level(stoi(infoSetting[7]));
				//Sound information
				car->getSound()->set_media_level(stoi(infoSetting[8]));
				car->getSound()->set_call_level(stoi(infoSetting[9]));
				car->getSound()->set_navi_level(stoi(infoSetting[10]));
				car->getSound()->set_notification_level(stoi(infoSetting[11]));
				//General information
				car->getGeneral()->set_timeZone(infoSetting[12]);
				car->getGeneral()->set_language(infoSetting[13]);
				Insert(car);
			}
		}
		else {
			throw "Open file fail";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	ifile.close();
}

