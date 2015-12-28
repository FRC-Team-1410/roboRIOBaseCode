#include <Commands/Autonomous/Very Simple Auto/VerySimpleAuto/AutoDriveStraightOverTime.h>
#include "Robot.h"
#include "../../../../RobotMap.h"

AutoDriveStraightOverTime::AutoDriveStraightOverTime(){
	Requires(Robot::drivebase);
	number_motors = Robot::oi->prefs->GetInt("NumberMotors", 4);
	drive_mode = Robot::oi->prefs->GetInt("DriveMode", 1);
	drive_time = Robot::oi->prefs->GetFloat("AutoDriveTime", 2.0);
	drive_speed = Robot::oi->prefs->GetFloat("AutoDriveSpeed", 0.5);
}

void AutoDriveStraightOverTime::Initialize(){

}

void AutoDriveStraightOverTime::Execute(){
	if(drive_mode == 1){
		Robot::drivebase->DriveTank(drive_speed, -drive_speed, number_motors);
	}
	else if(drive_mode == 2){
		Robot::drivebase->DriveArcade(drive_speed, 0, number_motors);
	}
	else if(drive_mode == 3){
		Robot::drivebase->DriveMecanum(0, drive_speed, 0);
	}
	else{
		Robot::drivebase->DriveTank(drive_speed, -drive_speed, number_motors);
	}
	Wait(drive_time);
	End();
}

bool AutoDriveStraightOverTime::IsFinished(){
	return false;
}

void AutoDriveStraightOverTime::End(){
	if(drive_mode == 1){
			Robot::drivebase->DriveTank(0, 0, number_motors);
		}
		else if(drive_mode == 2){
			Robot::drivebase->DriveArcade(0, 0, number_motors);
		}
		else if(drive_mode == 3){
			Robot::drivebase->DriveMecanum(0, 0, 0);
		}
		else{
			Robot::drivebase->DriveTank(0, 0, number_motors);
		}
}

void AutoDriveStraightOverTime::Interrupted(){
	End();
}
