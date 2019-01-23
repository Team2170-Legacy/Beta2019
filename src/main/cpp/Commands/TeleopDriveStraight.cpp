/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TeleopDriveStraight.h"

double power;

TeleopDriveStraight::TeleopDriveStraight(): frc::Command(){
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::driveTrain.get());
}

// Called just before this Command runs the first time
void TeleopDriveStraight::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TeleopDriveStraight::Execute() {
  // Get left joystick (for now just use left joystick in driving robot)
  power = Robot::oi->getJoystickLeft()->GetY(frc::GenericHID::JoystickHand::kLeftHand);

  // Send motor power to robot
  Robot::driveTrain->TankDrive(power, power);
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDriveStraight::IsFinished() { 
  return false; 
}

// Called once after isFinished returns true
void TeleopDriveStraight::End() {
  Robot::driveTrain->TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDriveStraight::Interrupted() {}
