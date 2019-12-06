/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <cmath>

#include "XboxCompController.h"

enum MotorID {
  LEFT_DRIVE,
  RIGHT_DRIVE,
  PULLEY,
  LIFTER
};

class Robot : public frc::TimedRobot {
  frc::PWMVictorSPX m_leftMotor{LEFT_DRIVE};
  frc::PWMVictorSPX m_rightMotor{RIGHT_DRIVE};
  frc::PWMVictorSPX m_pulleyMotor{PULLEY};
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  XboxCompController m_controller;

 public:
  
  void TeleopPeriodic() {
    // Drive with arcade style
    m_robotDrive.ArcadeDrive(std::pow(m_controller.GetMainDriveY(), 3), std::pow(m_controller.GetMainDriveX(), 3));
    m_pulleyMotor.Set(m_controller.GetPulleySpeed());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
