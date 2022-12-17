#include "vehicle.h"
#include <iostream>

vehicle::vehicle()
{
    safetyIndex = 0;
    numPassengers = 0;
}
vehicle::vehicle(int safetyIndex, int numPassengers)
{
    this->safetyIndex = safetyIndex;
    this->numPassengers = numPassengers;
}

int vehicle::getSafetyIndex()
{
    return safetyIndex;
}
int vehicle::getNumPassengers()
{
    return numPassengers;
}

// Json::Value vehicle::dump2Json()
// {
//     // std::cout<<"Thing Dump 2 json entered"<<endl;
//     Json::Value result;
//     if (safetyIndex != NULL)
//     {
//         result["safetyIndex"] = this->safetyIndex;
//     }
//     if (numPassengers != NULL)
//     {
//         result["numPassengers"] = this->numPassengers;
//     }
//     // if (this->name != "")
//     // {
//     //     result["name"] = this->name ;
//     // }
//     // if (this->size != "")
//     // {
//     //     result["size"] = this->size;
//     // }
//     // if (this->description != "")
//     // {
//     //     result["description"] = this->description;
//     // }
//     // if(result.isNull()){
//     //     cout<<"thing dump 2 json is null"<<endl;
//     //     cout<<result["name"].asString();
//     //     cout<<result["size"].asString();
//     //     cout<<result["description"].asString();
//     // }
//     // std::cout<<result.toStyledString()<<endl;

//     return result;
// }

bool vehicle::JSON2Object(Json::Value n)
{
    /*
    if(n["name"].isNull() || !n["name"].isString()){
        return false;
    }
    if(n["size"].isNull() || !n["size"].isString()){
        return false;
    }
    if(n["description"].isNull() || !n["description"].isString()){
        return false;
    }

    this->name = n["name"].asString();
    this->size = n["size"].asString();
    this->description = n["description"].asString();
    */
    return true;
}