#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds, std::string;

void GenerateWarning(string sAbNormalParameter) {
    cout << sAbNormalParameter << " is out of range!\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}
bool IsTempInNormalRange(float temperature) {
    if (temperature >= 102 || temperature <= 95) {
        GenerateWarning("temperature");
        return false;
    }
    return true;
}
bool IsPulseInNormalRange(float pulseRate) {
    if (pulseRate <= 60 || pulseRate >= 100) {
        GenerateWarning("Pulse Rate");
        return false;
    }
    return true;
}

bool IsSPO2InNormalRange(float spo2) {
    if (spo2 <= 90) {
        GenerateWarning("Oxygen Saturation");
        return false;
    }
    return true;
}


bool vitalsOk(float temperature, float pulseRate, float spo2) {
    return (IsTempInNormalRange(temperature) &&
        IsPulseInNormalRange(pulseRate) &&
        IsSPO2InNormalRange(spo2));
}
