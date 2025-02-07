#include <Commands/Drive Base/TeleOpTankDrive.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpTankDrive::TeleOpTankDrive(){
	Requires(Robot::drivebase);
}

void TeleOpTankDrive::Initialize(){

}

void TeleOpTankDrive::Execute(){
	Robot::drivebase->DriveTank(Robot::oi->GetDriveAxis(tankLeftAxis), Robot::oi->GetDriveAxis(tankRightAxis));
}

bool TeleOpTankDrive::IsFinished(){
	return false;
}

void TeleOpTankDrive::End(){
	Robot::drivebase->DriveTank(0, 0);
}

void TeleOpTankDrive::Interrupted(){
	End();
}
