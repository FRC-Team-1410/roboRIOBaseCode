#include <Commands/Drive Base/TeleOpArcadeDrive.h>
#include "Robot.h"
#include "../../RobotMap.h"
TeleOpArcadeDrive::TeleOpArcadeDrive(){
	Requires(Robot::drivebase);
	number_motors = Robot::oi->prefs->GetInt("NumberMotors", 4);
}

void TeleOpArcadeDrive::Initialize(){

}

void TeleOpArcadeDrive::Execute(){
	Robot::drivebase->DriveArcade(Robot::oi->GetDriveAxis(arcadeMovementAxis), Robot::oi->GetDriveAxis(arcadeRotationAxis), number_motors);
}

bool TeleOpArcadeDrive::IsFinished(){
	return false;
}

void TeleOpArcadeDrive::End(){
	Robot::drivebase->DriveArcade(0, 0, number_motors);
}

void TeleOpArcadeDrive::Interrupted(){
	End();
}
