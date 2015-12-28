#include <Commands/Autonomous/Very Simple Auto/VerySimpleAuto/AutoDriveTurn.h>
#include "Robot.h"
#include "../../../../RobotMap.h"

AutoDriveTurn::AutoDriveTurn(){
	Requires(Robot::drivebase);
	number_motors = Robot::oi->prefs->GetInt("NumberMotors", 4);
	drive_mode = Robot::oi->prefs->GetInt("DriveMode", 1);
	drive_angle = Robot::oi->prefs->GetFloat("AutoDriveAngle", 90.0);
	drive_speed = Robot::oi->prefs->GetFloat("AutoDriveSpeed", 0.5);
	turn_left = Robot::oi->prefs->GetFloat("AutoTurnLeft", false);
}

void AutoDriveTurn::Initialize(){

}

void AutoDriveTurn::Execute(){
	if(turn_left == true){
		TurnLeft();
	}
	else{
		TurnRight();
	}
}

bool AutoDriveTurn::IsFinished(){
	return Robot::drivebase->ReturnGyroPosition() >= drive_angle;
}

void AutoDriveTurn::End(){
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

void AutoDriveTurn::Interrupted(){
	End();
}

void AutoDriveTurn::TurnLeft(){
	if (drive_mode == 1){
		TankTurn(true);
	}
	else if(drive_mode == 2){
		ArcadeTurn(true);
	}
	else if(drive_mode == 3){
		MecanumTurn(true);
	}
	else{
		TankTurn(true);
	}
}

void AutoDriveTurn::TurnRight(){
	if (drive_mode == 1){
		TankTurn(false);
	}
	else if(drive_mode == 2){
		ArcadeTurn(false);
	}
	else if(drive_mode == 3){
		MecanumTurn(false);
	}
	else{
		TankTurn(false);
	}
}

void AutoDriveTurn::TankTurn(bool left){
	if(left == true){
		Robot::drivebase->DriveTank(-drive_speed, -drive_speed, number_motors);
	}
	else{
		Robot::drivebase->DriveTank(drive_speed, drive_speed, number_motors);
	}
}

void AutoDriveTurn::ArcadeTurn(bool left){
	if(left == true){
		Robot::drivebase->DriveArcade(0, -drive_speed, number_motors);
	}
	else{
		Robot::drivebase->DriveArcade(0, drive_speed, number_motors);
	}
}

void AutoDriveTurn::MecanumTurn(bool left){
	if(left == true){
		Robot::drivebase->DriveMecanum(0, 0, -drive_speed);
	}
	else{
		Robot::drivebase->DriveMecanum(0, 0, drive_speed);
	}
}
