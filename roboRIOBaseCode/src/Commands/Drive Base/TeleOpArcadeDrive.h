#ifndef TeleOpArcadeDrive_H
#define TeleOpArcadeDrive_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpArcadeDrive: public Command {
private:
	int number_motors;
public:
	TeleOpArcadeDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
