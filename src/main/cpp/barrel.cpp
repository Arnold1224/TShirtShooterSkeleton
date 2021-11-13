
#include "Barrel.h"

#include <frc/smartdashboard/SmartDashboard.h>

Barrel::Barrel(){
    elevation_talon = new WPI_TalonSRX(28);
    controller = new frc::Joystick(0);
}

void Barrel::Init() {
    elevation_talon->Set(0);
}

void Barrel::Slow() {
    elevation_talon->Set(-0.1);
}

void Barrel::Stop() {
    elevation_talon->Set(-0.1);
}

void Barrel::Up() {
    elevation_talon->Set(-0.3);
}

void Barrel::Down() {
    elevation_talon->Set(0.3);
}

void Barrel::StateMachine(){
    switch(current_state){
        case States::INIT:
            Init();
            break;
        case States::DOWN:
            Down();
            break;
        case States::UP:
            Up();
            break;
        case States::SLOW_BARREL:
            Slow();
            break;
    }
}
