#include "motorcycle.h"
#include <iostream>

motorcycle::motorcycle()
{
    this->safetyIndex = 0;
    this->numPassengers = 0;
    this->isWearingHelmet = false;
    this->motorcycleStability = 0;
}

motorcycle::motorcycle(int safetyIndex, int numPassengers, bool isWearingHelmet, int motorcycleStability)
{
    this->safetyIndex = safetyIndex;
    this->numPassengers = numPassengers;
    this->isWearingHelmet = isWearingHelmet;
    this->motorcycleStability = motorcycleStability;
}

Json::Value motorcycle::dump2Json()
{
    // std::cout<<"Thing Dump 2 json entered"<<endl;
    Json::Value result;
    if (safetyIndex != NULL)
    {
        result["safetyIndex"] = this->safetyIndex;
    }
    if (numPassengers != NULL)
    {
        result["numPassengers"] = this->numPassengers;
    }
    if (isWearingHelmet != NULL)
    {
        result["isWearingHelmet"] = this->isWearingHelmet;
    }
    if (motorcycleStability != NULL)
    {
        result["motorcycleStability"] = this->motorcycleStability;
    }
    // if(result.isNull()){
    //     cout<<"thing dump 2 json is null"<<endl;
    //     cout<<result["name"].asString();
    //     cout<<result["size"].asString();
    //     cout<<result["description"].asString();
    // }
    // std::cout<<result.toStyledString()<<endl;

    return result;
}
bool motorcycle::JSON2Object(Json::Value n)

{
    if (n["safetyIndex"].isNull() || !n["safetyIndex"].isString())
    {
        return false;
        if (n["numPassengers"].isNull() || !n["numPassengers"].isString())
        {
            return false;
            if (n["isWearingHelmet"].isNull() || !n["isWearingHelmet"].isString())
            {
                return false;
                if (n["motorcycleStability"].isNull() || !n["motorcycleStability"].isString())
                {
                    return false;
                }

                this->safetyIndex = n["safetyIndex"].asInt();
                this->numPassengers = n["numPassengers"].asInt();
                this->isWearingHelmet = n["isWearingHelmet"].asBool();
                this->safetyIndex = n["motorcycleStability"].asInt();
            }
        }
    }
}

bool motorcycle::getIsWearingHelmet()
{
    //return this->isWearingHelmet;
    return isWearingHelmet;
}