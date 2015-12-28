#include <Commands/Drive Base/TeleOpMecanumDrive.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpMecanumDrive::TeleOpMecanumDrive(){
	Requires(Robot::drivebase);
	number_motors = Robot::oi->prefs->GetInt("NumberMotors", 4);
}

void TeleOpMecanumDrive::Initialize(){

}

void TeleOpMecanumDrive::Execute(){
	Robot::drivebase->DriveMecanum(Robot::oi->GetDriveAxis(mecanumXAxis), Robot::oi->GetDriveAxis(mecanumYAxis), Robot::oi->GetDriveAxis(mecanumRotationAxis));
}

bool TeleOpMecanumDrive::IsFinished(){
	return false;
}

void TeleOpMecanumDrive::End(){
	Robot::drivebase->DriveMecanum(0, 0, 0);
}

void TeleOpMecanumDrive::Interrupted(){
	End();
}
