#include <Commands/Drive Base/TeleOpTankDrive.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpTankDrive::TeleOpTankDrive(){
	Requires(Robot::drivebase);
	number_motors = Robot::oi->prefs->GetInt("NumberMotors", 4);
}

void TeleOpTankDrive::Initialize(){

}

void TeleOpTankDrive::Execute(){
	Robot::drivebase->DriveTank(Robot::oi->GetDriveAxis(tankLeftAxis), Robot::oi->GetDriveAxis(tankRightAxis), number_motors);
}

bool TeleOpTankDrive::IsFinished(){
	return false;
}

void TeleOpTankDrive::End(){
	Robot::drivebase->DriveTank(0, 0, number_motors);
}

void TeleOpTankDrive::Interrupted(){
	End();
}
