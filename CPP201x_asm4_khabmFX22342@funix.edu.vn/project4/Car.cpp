#include "Car.h"

Car::Car()
{
	commonInfo = new CommonInfo;
	display = new Display;
	sound = new Sound;
	general = new General;
}

Car::~Car()
{
	delete commonInfo;
	delete display;
	delete sound;
	delete general;
}

void Car::setCommonInfo(CommonInfo* data)
{
	commonInfo = data;
}

CommonInfo* Car::getCommonInfo()
{
	return commonInfo;
}

void Car::setDisplay(Display* data) {
	display = data;
}
Display* Car::getDisplay() {
	return display;
}
void Car::setSound(Sound* data) {
	sound = data;
}
Sound* Car::getSound() {
	return sound;
}
void Car::setGeneral(General* data) {
	general = data;
}
General* Car::getGeneral() {
	return general;
}
