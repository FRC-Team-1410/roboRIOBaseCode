#ifndef DriveBase_H
#define DriveBase_H

#include "WPILib.h"

class DriveBase: public Subsystem{
private:
	CANTalon * fl_motor;
	CANTalon * fr_motor;
	CANTalon * bl_motor;
	CANTalon * br_motor;
	CANTalon * ml_motor;
	CANTalon * mr_motor;

	Gyro * drive_gyro;

	//might not work with CAN
	RobotDrive * drive;

public:
	DriveBase();
	void InitDefaultCommand();
	void DriveTank(float left_speed, float right_speed, int number_motors);
	void DriveArcade(float speed, float rotation, int number_motors);
	void DriveMecanum(float x_speed, float y_speed, float rot_speed);

	float ReturnEncoderDistance(float e1, float e2, float distance);
	void ResetEncoderPosition();

	float ReturnGyroPosition();
	void ResetGyro();
};

#endif
