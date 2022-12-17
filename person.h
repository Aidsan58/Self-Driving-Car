#ifndef _PERSON_H_
#define _PERSON_H_

#include "ecs36b_Common.h"
class Person
{
private:
    std::string name;
    std::string age;
    std::string description;

public:
    string getName();
    void setName(string name);

    string getAge();
    void setAge(string age);

    string getDescription();
    void setDescription(string description);

    Person();
    Person(string name, string description, string age);

    virtual Json::Value dump2Json();
    virtual bool JSON2Object(Json::Value);

    //makJson::Value dump2json();
};
#endif