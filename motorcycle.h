#ifndef _MOTORCYCLE_H
#define _MOTORCYCLE_H
#include "vehicle.h"

class motorcycle : public vehicle
{
private:
    bool isWearingHelmet;
    int motorcycleStability;
public:
    motorcycle();
    motorcycle(int safetyIndex, int numPassengers, bool isWearingHelmet, int motorcycleStability);

    bool getIsWearingHelmet();
    int getMotorcycleStability();
    virtual Json::Value dump2Json();
    virtual bool JSON2Object(Json::Value n);
};

#endif