// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/XboxController.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/PIDCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc/filter/SlewRateLimiter.h>
#include <frc/PowerDistribution.h>

#include "Constants.h"
#include "utils/SwerveUtils.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/IntakeSubsystem.h"

#include "commands/drive/DriveWithController.h"
#include "commands/intake/SimpleIntake.h"
#include "commands/intake/SimpleOuttake.h"
#include "commands/intake/StopIntake.h"
#include "commands/elevator/ExtendElevator.h"
#include "commands/elevator/RetractElevator.h"
#include "commands/elevator/StopElevator.h"
#include "commands/drive/DriveFacingGoal.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  /**
   * @return The command for autonomous
  */
  frc2::CommandPtr GetAutonomousCommand();

 private:
  /**
   * Convigures button bindings for commands
  */
  void ConfigureButtonBindings();

  // The driver and operator controllers
  frc::XboxController m_driveController{OIConstants::kDriverControllerPort};
  frc::XboxController m_operatorController{OIConstants::kOperatorControllerPort};

  frc::PowerDistribution m_revPDH{1, frc::PowerDistribution::ModuleType::kRev};
  // Variables 
  bool isFieldRelative = true;

  // The robot's subsystems
  DriveSubsystem m_drive;
  IntakeSubsystem m_intake;
  ElevatorSubsystem m_elevator;

  // Sendable chooser for auto
  frc::SendableChooser<std::string> m_autoChooser;

  DriveWithController m_driveWithController{&m_drive, &m_driveController};
  SimpleIntake m_simpleIntake{&m_intake};
  SimpleOuttake m_simpleOuttake{&m_intake};
  StopIntake m_stopIntake{&m_intake};
  ExtendElevator m_extendElevator{&m_elevator};
  RetractElevator m_retractElevator{&m_elevator};
  StopElevator m_stopElevator{&m_elevator};
  DriveFacingGoal m_driveFacingGoal{&m_drive, &m_driveController};

};
