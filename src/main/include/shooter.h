#pragma once

class Shooter
{
    private:
        WPITalonSRX*compressor_1;
        WPITalonSRX*compressor_2;
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
            Void Go();
            void StateMachine();
            void ResetCounter();
};