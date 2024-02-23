#pragma once
#include "CommonInfo.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"

using namespace std;

class Car {
private:
	CommonInfo* commonInfo;
	Display* display;
	Sound* sound;
	General* general;
public:
	Car();
	~Car();
	void setCommonInfo(CommonInfo* data);
	CommonInfo* getCommonInfo();
	void setDisplay(Display* data);
	Display* getDisplay();
	void setSound(Sound* data);
	Sound* getSound();
	void setGeneral(General* data);
	General* getGeneral();
};
