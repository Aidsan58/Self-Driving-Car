#include "car.h"
#include <iostream>

car::car(){
    this->safetyIndex = 0;
    this->numPassengers = 0;
    this->isWearingSeatbelt = false;
}

car::car(int safetyIndex, int numPassengers, bool isWearingSeatbelt){
    this->safetyIndex = safetyIndex;
    this->numPassengers = numPassengers;
    this->isWearingSeatbelt = isWearingSeatbelt;
}


Json::Value car::dump2Json()
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
    if(isWearingSeatbelt != NULL){
        result["isWearingSeatbelt"] = this->isWearingSeatbelt;
    }
    if(result.isNull()){
       // cout<<"car dump 2 json is null"<<endl;
        // cout<<result["safetyIndex"].asString();
        // cout<<result["size"].asString();
        // cout<<result["description"].asString();
    }
   // std::cout<<result.toStyledString()<<endl;
    return result;
}
bool car::JSON2Object(Json::Value n)
{
    if(n["safetyIndex"].isNull() || !n["safetyIndex"].isString())
    {
        return false;
    if(n["numPassengers"].isNull() || !n["numPassengers"].isString()){
        return false;
    if(n["isWearingSeatbelt"].isNull() || !n["isWearingSeatbelt"].isString()){
        return false;
    }

    this->safetyIndex = n["safetyIndex"].asInt();
    this->numPassengers = n["numPassengers"].asInt();
    this->isWearingSeatbelt = n["isWearingSeatbelt"].asBool();
    }
    }
}