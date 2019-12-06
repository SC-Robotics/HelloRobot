#pragma once
#include <frc/XboxController.h>
#include "CompBotController.h"
#include <vector>

using frc::XboxController;

enum JoystickID {
  LEFT,
  RIGHT
};

const int GAMEPAD_ID = 0;

class XboxCompController : public CompBotController {
    XboxController m_controller{GAMEPAD_ID};

public:
    double GetMainDriveX() override {
        return m_controller.GetX(XboxController::JoystickHand::kLeftHand);
    }

    double GetMainDriveY() override {
        return m_controller.GetY(XboxController::JoystickHand::kLeftHand);
    }

    double GetPulleySpeed() override {
        return m_controller.GetY(XboxController::JoystickHand::kRightHand);
    }
};