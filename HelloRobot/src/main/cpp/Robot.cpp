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
#include <frc/XboxController.h>
#include <cmath>

enum MotorID {
  LEFT_DRIVE,
  RIGHT_DRIVE,
  PULLEY,
  LIFTER
};

enum JoystickID {
  LEFT,
  RIGHT
};

const std::vector<frc::XboxController::JoystickHand> JSHand = {
  frc::XboxController::JoystickHand::kLeftHand,
  frc::XboxController::JoystickHand::kRightHand
};

const int GAMEPAD_ID = 0;

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public frc::TimedRobot {
  frc::PWMVictorSPX m_leftMotor{LEFT_DRIVE};
  frc::PWMVictorSPX m_rightMotor{RIGHT_DRIVE};
  frc::PWMVictorSPX m_pulleyMotor{PULLEY};
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  frc::XboxController m_gamepad{GAMEPAD_ID};

 public:
  
  void TeleopPeriodic() {
    // Drive with arcade style
    m_robotDrive.ArcadeDrive(std::pow(m_gamepad.GetY(JSHand[LEFT]), 3), std::pow(m_gamepad.GetX(JSHand[LEFT]), 3));
    m_pulleyMotor.Set(m_gamepad.GetY(JSHand[RIGHT]));
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
