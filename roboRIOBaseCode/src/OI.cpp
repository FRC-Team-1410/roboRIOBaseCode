#include "OI.h"
#include "RobotMap.h"
#include "Commands/Drive Base/TeleOpTankDrive.h"
#include "Commands/Drive Base/TeleOpArcadeDrive.h"
#include "Commands/Drive Base/TeleOpMecanumDrive.h"
#include "Commands/Autonomous/Very Simple Auto/AutoDriveStraightOverTime.h"

const char inputShape[255] = {0,1,3,4,5,6,7,9,10,11,12,13,15,16,17,18,19,21,22,23,24,25,27,28,29,30,31,
 	        33,34,35,36,37,38,40,41,42,43,44,46,47,48,49,50,52,53,54,55,56,58,59,60,61,62,
 	        64,65,66,67,68,70,71,72,73,74,76,77,78,79,80,82,83,84,85,86,88,89,90,91,92,94,
 	        95,96,97,98,100,101,102,103,104,106,107,108,109,110,112,113,114,115,116,117,
 	        118,119,120,121,121,122,123,123,124,124,125,125,125,126,126,126,126,126,127,
 	        127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
 	        128,128,128,128,128,129,129,129,130,130,131,131,132,133,133,134,135,136,
 	        137,138,139,140,141,142,144,145,146,147,148,150,151,152,153,154,156,157,158,
 	        159,160,162,163,164,165,166,168,169,170,171,172,174,175,176,177,178,180,181,
 	        182,183,184,186,187,188,189,190,192,193,194,195,196,198,199,200,201,202,204,
 	        205,206,207,208,210,211,212,213,214,216,217,218,219,220,221,223,224,225,226,
 	        227,229,230,231,232,233,235,236,237,238,239,241,242,243,244,245,247,248,249,
 	        250,251,253,254,255};

float InputShape(float userValue){
	int iUserValue;


	iUserValue = (int)(userValue * 127);
	iUserValue += 127;
	iUserValue = inputShape[iUserValue];
	userValue = iUserValue - 127;
	userValue /= 127;
	return userValue;
}

OI::OI(){
	driver_stick = new Joystick(0);
	operator_stick = new Joystick(1);

	prefs = Preferences::GetInstance();

	//adding buttons to the SmartDashboard to test them
	SmartDashboard::PutData("Very Simple Auto", new AutoDriveStraightOverTime());
	SmartDashboard::PutData("TeleOpTankDrive", new TeleOpTankDrive());
	SmartDashboard::PutData("TeleOpMecanumDrive", new TeleOpMecanumDrive());
	SmartDashboard::PutData("TeleOpArcadeDrive", new TeleOpArcadeDrive());
}

double OI::GetDriveAxis(int axis){
	float drive_multiplier = prefs->GetFloat("DriveMultiplier", 1);

	return -(InputShape((float)driver_stick->GetRawAxis(axis) * drive_multiplier));
}
