#ifndef _CAR_H_
#define _CAR_H_
#include "vehicle.h"


class car : public vehicle
{
    private:
    bool isWearingSeatbelt;
    public:
    car();
    car(int safetyIndex, int numPassengers, bool isWearingSeatbelt);
    void decideAccident();

    virtual Json::Value dump2Json();
    virtual bool JSON2Object(Json::Value n);
};

#endif