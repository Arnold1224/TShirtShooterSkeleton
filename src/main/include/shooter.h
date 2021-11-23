#pragma once
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <chrono>

class Shooter
{
    private:
        WPI_TalonSRX*compressor_1;
        WPI_TalonSRX*compressor_2;
        frc::Solenoid*firing_valve;
        frc::Solenoid*emergency_valve;

    public:
        enum States{
            GO, INIT, STOP, SHOOT      
        };
        States current_state;
        States last_state;
        
        Shooter();
            void Init();
            void Stop();
            void Shoot();
            void Go();
            void StateMachine();
            void ResetCounter();
};