// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/VisionDrive.h"
#include <iostream>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

VisionDrive::VisionDrive(): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void VisionDrive::Initialize() {
    Robot::driveTrain->resetGyro();
    //auto inst = nt::NetworkTableInstance::GetDefault();
    //auto table = inst.GetTable("datatable"); //network table initialized.
}

// Called repeatedly when this Command is scheduled to run
void VisionDrive::Execute() {
    double currentBearing = Robot::driveTrain->getGyroAngle();

    Robot::driveTrain->TankDriveVelocityError(4.0, currentBearing);
    //VisionTargetDrive();

    std::cout << "Gyro running" << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool VisionDrive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void VisionDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionDrive::Interrupted() {

}

/** Takes values entered into the network table and moves the robot to specified position 
*pre: Network table instance must exist. File must be found. 
*post: moves robot to network table values. 
**/
// void VisionDrive::VisionTargetDrive() {
//     xEntry = table->GetEntry("X");
//     double x;
//     xEntry.SetDouble(x); //put the network table instances into the doubles. 

//     double distanceHorizontal;
//     double distanceVertical;
//     double theta;
//     double turnTheta;
//     double distanceHyp;
//     double arcTurnDistance;
//     double totalDistance;
//     double wheelsRevs;
//     String turnDirection;

//     distanceVertical = xsin(DriveTrain::analogGyro->GetAngle()); 
//     distanceHorizontal = xcos(DriveTrain::analogGyro->GetAngle());
//     //get the distance that needs to be travelled horizontally and vertically.

//     theta = Robot::driveTrain->getGyroAngle();
//     distanceHyp = sqrt(pow(distanceHorizontal, 2) + pow(distanceVertical, 2));

//     //direction is controlled by distanceHorizontal, degrees is controlled by distanceVertical. 

//     turnTheta;
//     if(theta == 90){
//         turnTheta = 90;
//     } else {if(distanceVertical < 0){
//         turnTheta = 90-theta;
//     } else if(distanceVertical > 0){
//         turnTheta = theta;
//     } //how many degrees does robot turn?

//     turnDirection = NULL;
//     if(distanceHorizontal < 0){
//         turnDirection = "Left";
//     } else if(distanceHorizontal > 0){
//         turnDirection = "right";
//     } //which way does robot turn?

//     arcTurnDistance = (PI * ROBOTRADIUS * turnTheta)/(180);
//     totalDistance = arcTurnDistance + distanceHyp;   //total distance ROBOT travels.  

//     wheelsRevs = (distanceHyp)/(2 * PI * WHEELRADIUS); //to get to final position. Excluding turn revs.
//     velocityBot = wheelsRevs/(dT/60); //RPM

//     if(turnDirection.equals("Left")){
//         pidControllerR.SetReference(-velocityBot, rev::ControlType::kVelocity);
//     } else if(turnDirection.equals("Right")){
//         pidControllerL.SetReference(velocityBot, rev::ControlType::kVelocity);
//     }

//     pidControllerL->SetReference(velocityBot, rev::ControlType::kVelocity); //send RPM to pid controllers. 
//     pidControllerR->SetReference(-velocityBot, rev::ControlType::kVelocity);
// }
