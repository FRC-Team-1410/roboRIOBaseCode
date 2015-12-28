#ifndef TeleOpMecanumDrive_H
#define TeleOpMecanumDrive_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpMecanumDrive: public Command {
private:
	int number_motors;
public:
	TeleOpMecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
