#include "shooter.h"

Shooter::Shooter()
{
    compressor_1 = new WPI_TalonSRX(1);
    compressor_2 = new WPI_TalonSRX(11);
    firing_valve = new frc::Solenoid(0, 2);
    emergency_valve = new frc::Solenoid(0, 3);
}

void Shooter::Stop() {
    compressor_1->Set(0);
    compressor_2->Set(0);
    firing_valve->Set(false);
}

void Shooter::Go(){
    compressor_1->Set(1);
    compressor_2->Set(1);
    firing_valve->Set(false);
}

void Shooter::Shoot(){
    firing_valve->Set(true);
}

void Shooter::Init(){
    compressor_1->Set(0);
    compressor_2->Set(0);
}


void Shooter::StateMachine(){
    switch(current_state){
        case States::STOP:
            Stop();
            break;
        case States::GO:
            Go();
            break;
        case States::SHOOT: 
            Shoot();
            break;
        case States::INIT:
            Init();
            break;
    }
}