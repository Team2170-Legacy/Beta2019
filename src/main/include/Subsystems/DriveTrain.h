// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H
#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"


/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<rev::CANSparkMax> sparkMax1;
	std::shared_ptr<rev::CANSparkMax> sparkMax2;
	std::shared_ptr<frc::SpeedControllerGroup> speedControllerGroupLeft;
	std::shared_ptr<rev::CANSparkMax> sparkMax3;
	std::shared_ptr<rev::CANSparkMax> sparkMax4;
	std::shared_ptr<frc::SpeedControllerGroup> speedControllerGroupRight;
	std::shared_ptr<frc::DifferentialDrive> differentialDrive;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	DriveTrain();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void TankDrive(double left, double right);

};

#endif
