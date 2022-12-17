/*

// ecs36b first program

#include <iostream>
#include "ecs36b_Exception.h"

// JSON RPC part
#include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

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

#include "person.h"
#include "vehicle.h"
#include <time.h>

using namespace jsonrpc;
//using namespace std;

Json::Value hw5Client::done ()
 {

  Json::Value result;
  result["done"] = "all data sent";
  std::cout << result.toStyledString() << std::endl;
  this->is_done = true;
  return result;
}

int
main()
{
  Thing *thing_ptr;
  
  // first object
  // Shadow_Thing st_1 { "http://10.42.0.1:7374", "Thing", "00000001" };
  // Shadow_Thing st_1 { "http://127.0.0.1:7374", "Thing", "00000001" };

  // second object
  GPS_DD gps_Home_Woodland { 38.672215864622636, -121.72280111121437 };
  GPS_DD gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306 };
  GPS_DD gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501};

  Person John { "987654320", "John", gps_Home_Woodland };
  John.setLocation(gps_IKEA_Sacramento, (*getNowJvTime()));

  // object mobility demo for 11/18/2022 and 11/21/2022
  HttpClient httpclient("http://127.0.0.1:7374");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2); 
  Json::Value myv;

  // move
  try {
    myv = myClient.move("move", "Person",
			John.dump2JSON(),
			gps_TLC_UCDavis.dump2JSON(),
			"987654321");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  exit(-2);
  Shadow_Thing st_1 { "http://127.0.0.1:7374", "Thing", "00000001" };
  
  // search
  try {
    myv = myClient.search("search", "Person",
			"987654321");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  // demo on 10/27/2022 ecs36b for JSON2Object
  Json::Value xyz = gps_Home_Woodland.dump2JSON();
  GPS_DD yyy;
  bool status_j = yyy.JSON2Object(xyz);
  std::cout << (yyy.dump2JSON()).toStyledString() << std::endl;
  std::cout << (gps_Home_Woodland.dump2JSON()).toStyledString() << std::endl;
  
  // demo on 11/14/2022
  Json::Value abc = John.dump2JSON();
  Person John_Clone {};
  John_Clone.JSON2Object(abc);
  John_Clone.name = "John Clone";
  abc = John_Clone.dump2JSON();
  std::cout << abc.toStyledString() << std::endl;
  
  IP_Address meatball_IP { 2850883174 };
  IOT_Thing Irish_Coffee { John , meatball_IP };
  
  Irish_Coffee.model = "HUVUDROLL";
  Irish_Coffee.sequence_num = "123456-0000";
  Irish_Coffee.description = "frozen";
  Irish_Coffee.location = gps_Home_Woodland;
  Irish_Coffee.purchased = *getNowJvTime();
  Irish_Coffee.sold = *getNowJvTime();
  Irish_Coffee.owner = John;

  Json::Value result;

  thing_ptr = (Thing *) (&Irish_Coffee);
  result = thing_ptr->dump2JSON();
  cout << result.toStyledString() << endl;

  thing_ptr = (Thing *) (&st_1);
  result = thing_ptr->dump2JSON();
  cout << result.toStyledString() << endl;

  return 0;
}
*/