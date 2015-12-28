#ifndef AutoDriveStraightOverTime_H
#define AutoDriveStraightOverTime_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveStraightOverTime: public Command {
private:
	int number_motors;
	int drive_mode;
	float drive_time;
	float drive_speed;

public:
	AutoDriveStraightOverTime();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
