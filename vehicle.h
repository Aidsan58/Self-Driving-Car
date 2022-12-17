#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include "ecs36b_Common.h"

class vehicle
{
protected:
    int safetyIndex;
    int numPassengers;

public:
    vehicle();
    vehicle(int safetyIndex, int numPassengers);
    //virtual Json::Value dump2Json();
    int getSafetyIndex();
    int getNumPassengers(); 
    // Commenting this out as a reminder in case I need Json2object
    virtual bool JSON2Object(Json::Value);
};
#endif