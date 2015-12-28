#include "Robot.h"
#include "DriveBase.h"
#include "Commands/Drive Base/TeleOpTankDrive.h"
#include "Commands/Drive Base/TeleOpArcadeDrive.h"
#include "Commands/Drive Base/TeleOpMecanumDrive.h"
#include "../RobotMap.h"

DriveBase::DriveBase() : Subsystem("DriveBase"){
	fl_motor = new CANTalon(frontLeftDrive);
	fr_motor = new CANTalon(frontRightDrive);
	bl_motor = new CANTalon(backLeftDrive);
	br_motor = new CANTalon(backRightDrive);
	ml_motor = new CANTalon(middleLeftDrive);
	mr_motor = new CANTalon(middleRightDrive);

	drive_gyro = new Gyro(0);

	//might not work with CAN
	drive = new RobotDrive(1, 3, 2, 4);

	drive->SetInvertedMotor(drive->kFrontRightMotor, true);
	drive->SetInvertedMotor(drive->kRearRightMotor, true);

	drive->SetSafetyEnabled(false);
	drive->SetSensitivity(0.2);
}

void DriveBase::InitDefaultCommand(){
	int drive_mode = Robot::oi->prefs->GetInt("DriveMode", 1);
	if(drive_mode == 1){
		SetDefaultCommand(new TeleOpTankDrive());
	}
	else if(drive_mode == 2){
		SetDefaultCommand(new TeleOpArcadeDrive());
	}
	else if(drive_mode == 3){
		SetDefaultCommand(new TeleOpMecanumDrive());
	}
	else{
		SetDefaultCommand(new TeleOpTankDrive());
	}
}

void DriveBase::DriveTank(float left_speed, float right_speed, int number_motors){
	if(number_motors == 2){
		fl_motor->Set(left_speed);
		fr_motor->Set(right_speed);
	}
	else if(number_motors == 4){
		fl_motor->Set(left_speed);
		fr_motor->Set(right_speed);
		bl_motor->Set(left_speed);
		br_motor->Set(right_speed);
	}
	else if(number_motors == 6){
		fl_motor->Set(left_speed);
		fr_motor->Set(right_speed);
		bl_motor->Set(left_speed);
		br_motor->Set(right_speed);
		ml_motor->Set(left_speed);
		mr_motor->Set(right_speed);
	}
}

void DriveBase::DriveArcade(float speed, float rotation, int number_motors){
	if(number_motors == 2){
		//might not work with CAN
		drive = new RobotDrive(1, 2);

		drive->SetInvertedMotor(drive->kFrontRightMotor, true);

		drive->SetSafetyEnabled(false);
		drive->SetSensitivity(0.2);
	}

	//might not work with CAN
	drive->ArcadeDrive(speed, rotation);
}

void DriveBase::DriveMecanum(float x_speed, float y_speed, float rot_speed){
	//might not work with CAN
	drive->MecanumDrive_Cartesian(x_speed, y_speed, rot_speed);
}

float DriveBase::ReturnEncoderDistance(float e1, float e2, float distance){
	fl_motor->SetFeedbackDevice(CANTalon::QuadEncoder);
	fr_motor->SetFeedbackDevice(CANTalon::QuadEncoder);
	//fl_motor->SetSensorDirection(true);
	//fr_motor->SetSensorDirection(true);

	e1 = fl_motor->GetEncPosition();
	e2 = fr_motor->GetEncPosition() * -1;

	distance = (e2 + e1) / 2;
	SmartDashboard::PutNumber("Encoder Distance", distance);
	return distance;
}

void DriveBase::ResetEncoderPosition(){
	bl_motor->SetPosition(0);
	br_motor->SetPosition(0);
}

float DriveBase::ReturnGyroPosition(){
	SmartDashboard::PutNumber("Gyro Angle", drive_gyro->GetAngle());
	return drive_gyro->GetAngle();
}

void DriveBase::ResetGyro(){
	drive_gyro->Reset();
}
