#pragma once

#include "barrel.h"

#include 'shooter.h'

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>

class TeleopStateMachine
{
private:
    /* data */
public:

    enum States {
        INIT, RUN, STOP,
        UP, SHOOT, DOWN,
        EMERGENCY, SLOW_BARREL, STOP_BARREL
    };

    States current_state;

    frc::Joystick *joystick;

    Barrel * barrel;

    int start_compressor_button = 5;
    int stop_compressor_button = 6;
    int shoot_button = 8;
    int up_button = 4;
    int down_button = 2;
    int emergency_button = 999;
    int slow_button = 1;


    bool start_compressor;
    bool stop_compressor;
    bool shoot;
    bool up;
    bool down;
    bool emergency;

    TeleopStateMachine(frc::Joystick *joystick_, Barrel * barrel_);
    void UpdateButtons();
    void StateMachine();
};

