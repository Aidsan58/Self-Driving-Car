
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
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include "vehicle.h"
#include "car.h"
#include "motorcycle.h"
#include <time.h>
#include "hw5server.cpp"
#include "hw5client.h"

using namespace jsonrpc;
using namespace std;

int main()
{
  motorcycle leftMotorcycle(0, 1, false, 0);

  HttpClient httpclient("http://127.0.0.1:7374");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);

  HttpServer httpserver(7375);
  Myhw5Server s(httpserver,
                JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  while (s.is_done == false)
  {
    s.StartListening();
  }
  s.StopListening();
  /*
  for (auto it = s.car_Map.begin(); it != s.car_Map.end(); it++)
  {
    try
    {
      myv = myClient.move("move", "car",
                          s.car_Map[it->first]->dump2Json(),
                          gps,
                          "car1");
      cout << "sent " << myv["safetyIndex"].asString() << " to " << gps["location"].asString() << endl;
    }
    catch (JsonRpcException &e)
    {
      cerr << e.what() << endl;
    }
    std::cout << myv.toStyledString() << std::endl;
  }*/
    Json::Value myv;
    Json::Value gps;
    gps["location"] = "mainCar";

    try {
      myv = myClient.move("move", "motorcycle",
      leftMotorcycle.dump2Json(),
      gps,
      "motorcycle");
      cout << "sent " << " to " << gps["location"].asString() << endl;
    }
    catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
    std::cout << myv.toStyledString() << std::endl;
  Json::Value finish;

  try
  {
    finish = myClient.done();
  }
  catch (JsonRpcException &e)
  {
    cerr << e.what() << endl;
  }
  cout << "finished recieving";
  return 0;
}
