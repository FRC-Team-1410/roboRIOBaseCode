#ifndef MY_ROBOT_H_
#define MY_ROBOT_H_

#include "WPILib.h"

#include "OI.h"
#include "Subsystems/DriveBase.h"

class Robot: public IterativeRobot {
public:
	static OI * oi;
	static DriveBase * drivebase;

private:
	LiveWindow * lw;
	Command * auto_command;
	SendableChooser * auto_choice;
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif
