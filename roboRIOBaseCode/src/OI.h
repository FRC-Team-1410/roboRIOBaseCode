#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI{
private:
	Joystick * driver_stick;
	Joystick * operator_stick;


public:
	Preferences * prefs;
	OI();
	double GetDriveAxis(int axis);
};

#endif
