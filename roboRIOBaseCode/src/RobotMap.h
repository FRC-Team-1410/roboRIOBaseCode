/*
* RobotMap defines motor and sensor ports and buttons/axis for the robot.
* This is for ease of use and so that we can easily make sure that there
* are no conflicts with ports, constants, etc.
*/

#ifndef ROBOTMAP_H_
#define ROBOTMAP_H_

//Motors

//DriveBase motors
const int frontLeftDrive = 1;
const int frontRightDrive = 2;
const int backLeftDrive = 3;
const int backRightDrive = 4;
const int middleLeftDrive = 5;
const int middleRightDrive = 6;

//Controller constants
const int tankLeftAxis = 1;
const int tankRightAxis = 5;
const int arcadeMovementAxis = 1;
const int arcadeRotationAxis = 0;
const int mecanumXAxis = 0;
const int mecanumYAxis = 1;
const int mecanumRotationAxis = 4;

#endif /* ROBOTMAP_H_ */
