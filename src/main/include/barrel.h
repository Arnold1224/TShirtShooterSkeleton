#pragma once 
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>

class Barrel
{
    private:
        WPI_TalonSRX *elevation_talon;
        frc::Joystick *controller;
    public:
        enum States{
            UP, DOWN, SLOW_BARREL, STOP, INIT
        };
        States current_state;

        Barrel();
            void StateMachine();
            void Init();
            void Down();
            void Stop();
            void Up();
            void Slow();
            
};