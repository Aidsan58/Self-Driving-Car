#include "person.h"

Person::Person() {}
Person::Person(string name, string description, string age)
{
    this->name = name;
    this->description = description;
    this->age = age;
}
string Person::getName()
{
    return name;
};
void Person::setName(string name)
{
    this->name = name;
};

string Person::getAge()
{
    return age;
};
void Person::setAge(string age)
{
    this->age = age;
};

string Person::getDescription()
{
    return description;
};
void Person::setDescription(string name)
{
    this->description = description;
};

Json::Value Person::dump2Json()
{
    // std::cout<<"Dump 2 json entered"<<endl;
    Json::Value result;
    if (this->name != "")
    {
        result["name"] = this->name;
    }
    if (this->age != "")
    {
        result["age"] = this->age;
    }
    if (this->description != "")
    {
        result["description"] = this->description;
    }
    //  std::cout<<result.toStyledString()<<endl;
    return result;
}

bool Person::JSON2Object(Json::Value n)
{
    if (n["name"].isNull() || !n["name"].isString())
    {
        return false;
    }
    if (n["age"].isNull() || !n["age"].isString())
    {
        return false;
    }
    if (n["description"].isNull() || !n["description"].isString())
    {
        return false;
    }

    this->name = n["name"].asString();
    this->age = n["age"].asString();
    this->description = n["description"].asString();

    return true;
}
