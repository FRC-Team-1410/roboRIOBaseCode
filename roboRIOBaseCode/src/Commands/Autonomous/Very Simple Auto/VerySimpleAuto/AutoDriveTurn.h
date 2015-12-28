#ifndef AutoDriveTurn_H
#define AutoDriveTurn_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveTurn: public Command {
private:
	int number_motors;
	int drive_mode;
	float drive_angle;
	float drive_speed;
	bool turn_left;

public:
	AutoDriveTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void TurnLeft();
	void TurnRight();

	void TankTurn(bool left);
	void ArcadeTurn(bool left);
	void MecanumTurn(bool left);
};

#endif
