#include "VerySimpleAuto.h"
#include "VerySimpleAuto/AutoDriveStraightOverTime.h"

VerySimpleAuto::VerySimpleAuto(){
	AddSequential(new AutoDriveStraightOverTime());
}
