#pragma once

#include "CompBotController.h"
#include <frc/Joystick.h>
#include <vector>

class X3DCompController : public CompBotController {
    frc::Joystick m_joystick{0};

public:
    double GetMainDriveX() override {
        return m_joystick.GetX();
    }

    double GetMainDriveY() override {
        return m_joystick.GetY();
    }

    double GetPulleySpeed() override {
        int pov_deg = m_joystick.GetPOV();
        if (pov_deg == 0 || pov_deg == 45 || pov_deg == 315)
            return 0.75;
        else if (pov_deg == 135 || pov_deg == 180 || pov_deg == 225)
            return -0.75;
        return 0;
    }
};