#include "Robot.h"
#include "../RobotMap.h"
#include "DriveBase.h"
#include "Commands/Drive Base/TeleOpTankDrive.h"

DriveBase::DriveBase() : Subsystem("DriveBase"){
	fl_motor = new CANTalon(frontLeftDrive);
	fr_motor = new CANTalon(frontRightDrive);
	bl_motor = new CANTalon(backLeftDrive);
	br_motor = new CANTalon(backRightDrive);
	ml_motor = new CANTalon(middleLeftDrive);
	mr_motor = new CANTalon(middleRightDrive);

	drive_gyro = new Gyro(0);
}

void DriveBase::InitDefaultCommand(){
	SetDefaultCommand(new TeleOpTankDrive());
}

void DriveBase::DriveTank(float left_speed, float right_speed){

	fl_motor->Set(left_speed);
	fr_motor->Set(right_speed);
	bl_motor->Set(left_speed);
	br_motor->Set(right_speed);
	//ml_motor->Set(left_speed);
	//mr_motor->Set(right_speed);
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
