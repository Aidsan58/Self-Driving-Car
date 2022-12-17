
// for Json::value
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b

//#include "person.h"
//#include "thing.h"
#include "motorcycle.h"
#include "car.h"
#include <time.h>


using namespace jsonrpc;
using namespace std;

// std::map (key, value pairs)

// my location

class Myhw5Server : public hw5Server
{
public:
  Myhw5Server(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const Json::Value& location,
			   const std::string& object_id);
  virtual Json::Value done();
  bool is_done = false; 
  std::map<std::string, motorcycle *> motorcycle_Map;
  std::map<std::string, car *> car_Map;
 
//#Not sure if I need this 
/*
  virtual Json::Value dump2JSON(const std::string& action,
				const std::string& arguments,
				const std::string& class_id,
				const std::string& host_url,
				const std::string& object_id);
        */
};

Myhw5Server::Myhw5Server(AbstractServerConnector &connector, serverVersion_t type)
  : hw5Server(connector, type)
{
  std::cout << "Myhw5Server Object created" << std::endl;
}

// member functions

Json::Value Myhw5Server::move (const std::string& action, const std::string& class_id,
 const Json::Value& json_object, const Json::Value& location,
 const std::string& object_id)
 {
  //int error code == 0;

  Json::Value result;
  
if(class_id == "car" || class_id == "Car"){
	  car * lv_car_ptr;
    
	  if (car_Map.find(object_id) != car_Map.end())
	    {
	      lv_car_ptr = car_Map[object_id];
	    }
	  else
	    {
	      lv_car_ptr = new car {};
	      car_Map[object_id] = lv_car_ptr;
	    }

	 lv_car_ptr->JSON2Object(json_object);
}else{
   motorcycle * lv_motorcycle_ptr;
    
	  if (motorcycle_Map.find(object_id) != motorcycle_Map.end())
	    {
	      lv_motorcycle_ptr = motorcycle_Map[object_id];
	    }
	  else
	    {
	      lv_motorcycle_ptr = new motorcycle {};
	      motorcycle_Map[object_id] = lv_motorcycle_ptr;
	    }

	 lv_motorcycle_ptr->JSON2Object(json_object);
	
}
   result = json_object;

      std::cout << "recieved: " << result.toStyledString() << std::endl;
  return result;
}


Json::Value Myhw5Server::done ()
 {

  Json::Value result;
  result["done"] = "all data sent";
  //std::cout << result.toStyledString() << std::endl;
  this->is_done = true;
  return result;
}



/*int main()
{
  GPS_DD gps_Home_Woodland { 38.672215864622636, -121.72280111121437 };
  GPS_DD gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306 };
  GPS_DD gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501};

  // set location here
  process_here = gps_TLC_UCDavis; // server, forrest
  
  Person Felix { "987654321", "Felix", gps_Home_Woodland };
  Felix.setLocation(gps_IKEA_Sacramento, (*getNowJvTime()));

  IP_Address meatball_IP { 2850883174 };
  IOT_Thing Swedish_Meatball { Felix , meatball_IP };
  
  Swedish_Meatball.model = "HUVUDROLL";
  Swedish_Meatball.sequence_num = "123456-0000";
  Swedish_Meatball.description = "frozen";
  Swedish_Meatball.location = gps_Home_Woodland;
  Swedish_Meatball.purchased = *getNowJvTime();
  Swedish_Meatball.sold = *getNowJvTime();
  Swedish_Meatball.owner = Felix;

  int rc;
  char name_buf[256];
  
  bzero(name_buf, 256);
  snprintf(name_buf, 256, "./json_objects/%s_%s.json", "Thing", "000000001");
  // "./json_objects/Thing_00000001.json"
  Json::Value jv = Swedish_Meatball.dump2JSON();
  rc = myJSON2File(name_buf, &jv); // char *, Json::Value *
  if (rc != 0)
    {
      std::cout << "myJSON2File error " << rc << std::endl;
      exit(-1);
    }

  Thing_Map["00000001"] = (Thing *) (&Swedish_Meatball);
  for (const auto& [key, value] : Thing_Map)
    std::cout << '[' << key << "] = " << value << ";\n ";

#define _GPS_STUFF_
#ifdef _GPS_STUFF_
  
  bzero(name_buf, 256);
  snprintf(name_buf, 256, "./json_objects/%s_%s.json", "GPS", "000000001");
  Json::Value gps_jv = gps_IKEA_Sacramento.dump2JSON();
  rc = myJSON2File(name_buf, &gps_jv);
  if (rc != 0)
    {
      std::cout << "myJSON2File error " << rc << std::endl;
      exit(-1);
    }

  Json::Value gps_jv_2;
  rc = myFile2JSON(name_buf, &gps_jv_2);
  if (rc != 0)
    {
      std::cout << "myJSON2File error " << rc << std::endl;
      exit(-1);
    }
  GPS_DD new_one {};
  new_one.JSON2Object(gps_jv_2);
  std::cout << (new_one.dump2JSON()).toStyledString() << std::endl;
  /*
  std::cout << "Move\n";
  if (class_id != "Person")
    {
      result["status"] = "failed";
      strJson = ( "class " + class_id + " unknown");
      result["reason"] = strJson;
      error_code = -1;
    }

  if (object_id.empty())
    {
      result["status"] = "failed";
      strJson = ( "object_id null ");
      result["reason"] = strJson;
      error_code = -2;
    }

  GPS_DD incoming_location;
  if ((location.isNull() == true) ||
      (location.isObject() == false))
    {
      result["status"] = "failed";
      strJson = ( "location parsing error " );
      result["reason"] = strJson;
      error_code = -3;
    }

  if ((json_object.isNull() == true) ||
      (json_object.isObject() == false))
    {
      result["status"] = "failed";
      strJson = ( "person parsing error " );
      result["reason"] = strJson;
      error_code = -4;
    }
  */

//#endif /* _GPS_STUFF_ */
/*
{
  HttpServer httpserver(7374);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}
*/