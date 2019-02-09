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
#include "Commands/VisionDrive.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
int count = 0;

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain")
{
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    analogGyro.reset(new frc::ADXRS450_Gyro());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    sparkMax1.reset(new rev::CANSparkMax(1, rev::CANSparkMax::MotorType::kBrushless));
    sparkMax2.reset(new rev::CANSparkMax(2, rev::CANSparkMax::MotorType::kBrushless));
    sparkMax3.reset(new rev::CANSparkMax(3, rev::CANSparkMax::MotorType::kBrushless));
    sparkMax4.reset(new rev::CANSparkMax(4, rev::CANSparkMax::MotorType::kBrushless));
    differentialDrive.reset(new frc::DifferentialDrive(*sparkMax1, *sparkMax3));
    differentialDrive->SetSafetyEnabled(false);

    // Set follower modes for sparkMax2 and sparkMax4
    sparkMax2->Follow(*sparkMax1);
    sparkMax4->Follow(*sparkMax3);

    // Initialize PID controllers
    pidControllerL.reset(new rev::CANPIDController(sparkMax1->GetPIDController()));
    pidControllerR.reset(new rev::CANPIDController(sparkMax3->GetPIDController()));

    // Set min/max powers
    pidControllerL->SetOutputRange(kMinOutput, kMaxOutput);
    pidControllerR->SetOutputRange(kMinOutput, kMaxOutput);

    // Set kFF and kP (after tuning, since gains have already been determined)
    pidControllerL->SetP(kP);
    pidControllerR->SetP(kP);

    pidControllerL->SetFF(kFF);
    pidControllerR->SetFF(kFF);
}

/** Takes values pre-entered into an external file and moves robot to specified positions.
 * pre: the external file must exist, the row of value to extract must be specified, and ping must 
 * be given. 
 * post: moves robot to external file's positions according to ping time. 
 **/
// int DriveTrain::MotionProfilePosition(double dT, int arrRow) {
//     ifstream inFile;
//     inFile.open("something.exe");
//     if(!inFile){
//         cout << "File not found";
//         return 0; //exits back to teleop if file is not found. 
//     }
//     std::vector< std::vector<double> > positionValues; //vector to store the position value
//                                                 // across and up to get to the specified area. 
    
//     while(!inFile.eof()){
//          std::vector<double> positions; //create new sub vector. 
//          double temp; //temp to load inFIle vars. 
//          for(int cols = 0; cols < 2; cols++){
//              inFile >> temp;
//              positions.push_back(temp); //the x and y distances are loaded into sub vector
//          }
//          positionValues.push_back(positions); //sub vector loaded into vector. 
//     }
//     inFile.close();

//     double distanceHorizontal;
//     double distanceVertical;
//     double theta;
//     double turnTheta;
//     double distanceHyp;
//     double arcTurnDistance;
//     double totalDistance;
//     double wheelsRevs;
//     double velocityBot;
//     string turnDirection;

//     distanceVertical = positionValues[arrRow][0]; 
//     distanceHorizontal = positionValues[arrRow][1];
//     //get the distance that needs to be travelled horizontally and vertically.

//     (distanceVertical==0) ? theta = 90 : theta = atan((distanceVertical/distanceHorizontal)); //theta undefined? 
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

//     arcTurnDistance = (PI * robotRadius * turnTheta)/(180);
//     totalDistance = arcTurnDistance + distanceHyp;   //total distance ROBOT travels.  

//     wheelsRevs = (distanceHyp)/(2 * PI * wheelRadius); //to get to final position. Excluding turn revs.
//     velocityBot = wheelsRevs/(dT/60); //RPM

//     pidControllerL->SetReference(velocityBot, rev::ControlType::kVelocity); //send RPM to pid controllers. 
//     pidControllerR->SetReference(-velocityBot, rev::ControlType::kVelocity);

//     return 1;
// }

void DriveTrain::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new TankDriveCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveTrain::Periodic()
{
    // Put code here to be run every loop
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::TankDrive(double left, double right)
{
    //std::cout << left << "\t\t" << right << std::endl;
    differentialDrive->TankDrive(left, right);
}

void DriveTrain::TankDriveVelocity(double left, double right, bool squaredInputs)
{
    static bool reported = false;
    if (!reported)
    {
        HAL_Report(HALUsageReporting::kResourceType_RobotDrive, 4,
                   HALUsageReporting::kRobotDrive_Tank);
        reported = true;
    }

    if (left > 1.0)
    {
        left = 1.0;
    }
    if (left < -1.0)
    {
        left = -1.0;
    }
    if (right > 1.0)
    {
        right = 1.0;
    }
    if (right < -1.0)
    {
        right = -1.0;
    }

    // square the inputs (while preserving the sign) to increase fine control
    // while permitting full power
    if (squaredInputs)
    {
        left = std::copysign(left * left, left);
        right = std::copysign(right * right, right);
    }

    double leftMotorRPM = left * maxRPM;
    double rightMotorRPM = right * -maxRPM;

    // Send setpoints to pid controllers
    pidControllerL->SetReference(leftMotorRPM, rev::ControlType::kVelocity);
    pidControllerR->SetReference(rightMotorRPM, rev::ControlType::kVelocity);
}

void DriveTrain::ArcadeDrive(double leftMove, double leftRotate)
{
    // Get joystick(s)
    double y = leftMove;
    double x = leftRotate;

    // if(x > 0.5){
    //     double difference = x-0.5;
    //     x -= difference;
    // } else if(x < -0.5){
    //      double difference = x+0.5;
    //     x += difference;
    // }

    // if(y > 0.5){
    //     double difference = y-0.5;
    //     y -= difference;
    // } else if(y < -0.5){
    //      double difference = y+0.5;
    //     y += difference;
    // }
    //set the max speeds of the x and y axes to 0.5.

    //-std::cout << "Move: " << y << "\t\t" << "Rotate: " << x << std::endl;

    differentialDrive->ArcadeDrive(y, x);
}

void DriveTrain::ArcadeDriveVelocity(double leftMove, double leftRotate, bool squaredInputs)
{
    double moveValue = leftMove;
    double rotateValue = leftRotate;

    if(moveValue > 0.0 && moveValue < 0.05){
        moveValue = 0.0;
    } else if(moveValue < 0.0 && moveValue > -0.05){
        moveValue = 0.0;
    } 

    if(rotateValue > 0.0 && rotateValue < 0.05){
        rotateValue = 0.0;
    } else if(rotateValue > 0.0 && rotateValue < 0.05){
        rotateValue = 0.0;
    }

    static bool reported = false;
    if (!reported)
    {
        HAL_Report(HALUsageReporting::kResourceType_RobotDrive, 4,
                   HALUsageReporting::kRobotDrive_ArcadeStandard);
        reported = true;
    }

    // local variables to hold the computed PWM values for the motors
    double leftMotorOutput;
    double rightMotorOutput;

    // LeftMove and leftRotate limits to +-1.0
    if (moveValue > 1.0)
    {
        moveValue = 1.0;
    }
    if (moveValue < -1.0)
    {
        moveValue = -1.0;
    }
    if (rotateValue > 1.0)
    {
        rotateValue = 1.0;
    }
    if (rotateValue < -1.0)
    {
        rotateValue = -1.0;
    }

    // square the inputs (while preserving the sign) to increase fine control
    // while permitting full power
    if (squaredInputs)
    {
        moveValue = std::copysign(moveValue * moveValue, moveValue);
        rotateValue = std::copysign(rotateValue * rotateValue, rotateValue);
    }

    if (moveValue > 0.0)
    {
        if (rotateValue > 0.0)
        {
            leftMotorOutput = moveValue - rotateValue;
            rightMotorOutput = std::max(moveValue, rotateValue);
        }
        else
        {
            leftMotorOutput = std::max(moveValue, -rotateValue);
            rightMotorOutput = moveValue + rotateValue;
        }
    }
    else
    {
        if (rotateValue > 0.0)
        {
            leftMotorOutput = -std::max(-moveValue, rotateValue);
            rightMotorOutput = moveValue + rotateValue;
        }
        else
        {
            leftMotorOutput = moveValue - rotateValue;
            rightMotorOutput = -std::max(-moveValue, -rotateValue);
        }
    }

    double leftMotorRPM = leftMotorOutput * maxRPM;
    double rightMotorRPM = rightMotorOutput * maxRPM;

    // Send setpoints to pid controllers
    pidControllerL->SetReference(leftMotorRPM, rev::ControlType::kVelocity);
    pidControllerR->SetReference(rightMotorRPM, rev::ControlType::kVelocity);
}

void DriveTrain::ClosedLoopVelocityControl(double speed)
{
    // read PID coefficients from SmartDashboard

    // // if PID coefficients on SmartDashboard have changed, write new values to controller
    // if(p != kP) {
    //     pidControllerL->SetP(p); kP = p;
    //     pidControllerR->SetP(p); kP = p;
    // }
    // if(i != kI) {
    //     pidControllerL->SetI(i); kI = i;
    //     pidControllerR->SetI(i); kI = i;
    // }
    // if(d != kD) {
    //     pidControllerL->SetD(d); kD = d;
    //     pidControllerR->SetD(d); kD = d;
    // }
    // if(iz != kIz) {
    //     pidControllerL->SetIZone(iz); kIz = iz;
    //     pidControllerR->SetIZone(iz); kIz = iz;
    // }
    // if(ff != kFF) {
    //     pidControllerL->SetFF(ff); kFF = ff;
    //     pidControllerR->SetFF(ff); kFF = ff;
    // }

    if (speed > 0.5)
    {
        double difference = speed - 0.5;
        speed -= difference;
    }
    else if (speed < -0.5)
    {
        double difference = speed + 0.5;
        speed += difference;
    }
    //set the max speeds of the axis to 0.5.

    // read setpoint from joystick and scale by max rpm
    double setPointL = maxRPM * speed;
    double setPointR = maxRPM * -speed;

    // Send setpoints to pid controllers
    pidControllerL->SetReference(setPointL, rev::ControlType::kVelocity);
    pidControllerR->SetReference(setPointR, rev::ControlType::kVelocity);

    // Put editable PID values on Dashboard

    //std::cout << kFF << std::endl;
}

double DriveTrain::getMotorRPM(int id)
{
    double rpm;

    switch (id)
    {
    case 1:
        rpm = sparkMax1->GetEncoder().GetVelocity();
        break;
    case 2:
        rpm = sparkMax2->GetEncoder().GetVelocity();
        break;
    case 3:
        rpm = sparkMax3->GetEncoder().GetVelocity();
        break;
    case 4:
        rpm = sparkMax4->GetEncoder().GetVelocity();
        break;
    }

    return rpm;
}

double DriveTrain::getRobotSpeed()
{
    // RPM to FPS
    double rpm = getMotorRPM(1);
    double rpm_axle = rpm / GEARING_RATIO;

    double circumference = PI * WHEEL_DIAMETER;

    double speed = (rpm_axle * circumference) / 12.0 / 60.0; // [ft/s]

    return speed;
}

double DriveTrain::getCommandedSpeed()
{
    return commandedSpeed;
}

void DriveTrain::TankDriveVelocityError(double velocity, double error) {
    // Left and right are [ft/s]
    double velocity_RPM = fpsToRPM(velocity);

    // double setPointL = -velocity_RPM - (kP_Vision * error);
    // double setPointR = velocity_RPM - (kP_Vision * error);
    double setPointL = -(kP_Vision * error);
    double setPointR = (kP_Vision * error);

    pidControllerL->SetReference(setPointL, rev::ControlType::kVelocity);
    pidControllerR->SetReference(setPointR, rev::ControlType::kVelocity);
}

double DriveTrain::fpsToRPM(double FPS) {
    double inPerSec_wheel = FPS * 12.0;
    double revPerSec_wheel = inPerSec_wheel / (PI * WHEEL_DIAMETER);
    double revPerSec_motor = revPerSec_wheel * GEARING_RATIO;

    return revPerSec_motor * 60;
}

double DriveTrain::rpmToFPS(double rpm) {
    double rpm_wheel = rpm / GEARING_RATIO;
    double circumference = PI * WHEEL_DIAMETER;     // [in]
    double speed = (rpm_wheel * circumference) / 12.0 / 60.0; // [ft/s]

    return speed;
}

double DriveTrain::joystickToFPS(double joystickValue){
    double rpm = joystickValue * maxRPM;

    return rpmToFPS(rpm);
}

void DriveTrain::resetGyro() {
    analogGyro->Reset();
}

double DriveTrain::getGyroAngle() {
    return analogGyro->GetAngle(); // [deg]
}
