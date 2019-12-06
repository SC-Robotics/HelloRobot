#pragma once

class CompBotController {
public:
    virtual double GetMainDriveX() = 0;
    virtual double GetMainDriveY() = 0;
    virtual double GetPulleySpeed() = 0;
};