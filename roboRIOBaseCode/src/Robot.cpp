#include "WPILib.h"
#include "Robot.h"

OI * Robot::oi = NULL;
DriveBase * Robot::drivebase = NULL;

void Robot::RobotInit(){
	oi = new OI();
	drivebase = new DriveBase();

	lw = LiveWindow::GetInstance();
	
	auto_choice = new SendableChooser();
	SmartDashboard::PutData("Autonomous Mode", auto_choice);
}

void Robot::AutonomousInit(){
	auto_command = (Command *) auto_choice->GetSelected();
	auto_command->Start();
}

void Robot::AutonomousPeriodic(){
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit(){
	auto_command->Cancel();
}

void Robot::TeleopPeriodic(){
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic(){
	lw->Run();
}

START_ROBOT_CLASS(Robot);
