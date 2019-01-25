// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/DriveTrain.h"
#include "Commands/TankDriveCommand.h"
#include <iostream>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
int count = 0;
DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
    sparkMax1.reset(new rev::CANSparkMax(1, rev::CANSparkMax::MotorType::kBrushless));
    sparkMax2.reset(new rev::CANSparkMax(2, rev::CANSparkMax::MotorType::kBrushless));
    sparkMax3.reset(new rev::CANSparkMax(3, rev::CANSparkMax::MotorType::kBrushless));
    sparkMax4.reset(new rev::CANSparkMax(4, rev::CANSparkMax::MotorType::kBrushless));
    differentialDrive.reset(new frc::DifferentialDrive(*sparkMax1, *sparkMax3));
    differentialDrive->SetSafetyEnabled(false);

    // Set follower modes for sparkMax2 and sparkMax4
    sparkMax2->Follow(*sparkMax1);
    sparkMax4->Follow(*sparkMax3);
}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new TankDriveCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveTrain::Periodic() {
    // Put code here to be run every loop

}

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::TankDrive(double left, double right) {
    //std::cout << left << "\t\t" << right << std::endl;
    differentialDrive->TankDrive(left, right);
}

void DriveTrain::ArcadeDrive(double leftMove, double leftRotate) {
    // Get joystick(s)
    double y = leftMove;
    double x = leftRotate;

    if(x>0.5){
        x-=0.5;
    } else if(x<-0.5){
        x+=0.5;
    }

    if(y>0.5){
        y-=0.5;
    } else if(y<-0.5){
        y+=0.5;
    } //set the max speeds of the x and y axes to 0.5. 

    std::cout << "Move: " << x << "\t\t" << "Rotate: " << y << std::endl;

    differentialDrive->ArcadeDrive(y, x);

}
