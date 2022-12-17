
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
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b

#include "vehicle.h"
#include "motorcycle.h"
#include "car.h"
#include <time.h>
#include "hw5server.cpp"

// JSON RPC part
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;

int main()
{

  int i;

  car car1(10, 2, true);

  // rightMotorcycle
  HttpClient httpclient("http://127.0.0.1:7376");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value gps;
  gps["location"] = "rightMotorcycle";

  try
  {
    myv = myClient.move("move", "car", car1.dump2Json(), gps, "car1");
    cout << myv << endl;
    cout << "leftMotorcycle: move successful" << endl;
  }
  catch (JsonRpcException &e)
  {
    std::cout << "catch entered" << std::endl;
    cerr << e.what() << endl;
  }
  // Json::Value finish;
  HttpServer httpserver(7374);
  Myhw5Server s(httpserver,
                JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  //std::cout << "Hit enter to stop the server" << std::endl;
  //getchar();
  s.StopListening();

  // leftMotorcycle
  HttpClient http2client("http://127.0.0.1:7375");
  hw5Client my2Client(http2client, JSONRPC_CLIENT_V2);
  gps["location"] = "leftMotorcycle";

  try
  {
    myv = my2Client.move("move", "car", car1.dump2Json(), gps, "car1");
    cout << myv << endl;
    cout << "rightMotorcycle: move successful" << endl;
  }
  catch (JsonRpcException &e)
  {
    std::cout << "catch entered" << std::endl;
    cerr << e.what() << endl;
  }
  Json::Value finish;

  try
  {
    finish = myClient.done();
  }
  catch (JsonRpcException &e)
  {
    cerr << e.what() << endl;
  }

  for (i = 1; i < 2; i++)
  {
    HttpServer httpserver(7374);
    Myhw5Server s(httpserver,
                  JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
    s.StartListening();
    //std::cout << "Hit enter to stop the server" << std::endl;
    //getchar();
    s.StopListening();
  }

  int leftMotorSafety = 0;
  for (auto it = s.motorcycle_Map.begin(); it != s.motorcycle_Map.end(); it++)
  {
    leftMotorSafety = s.motorcycle_Map[it->first]->getSafetyIndex();
    if(s.motorcycle_Map[it->first]->getIsWearingHelmet())
    {
      leftMotorSafety += 5;
    }
  }
  int rightMotorSafety = 0;
  for (auto it = s.motorcycle_Map.begin(); it != s.motorcycle_Map.end(); it++){
    rightMotorSafety = s.motorcycle_Map[it->first]->getSafetyIndex();
    if(s.motorcycle_Map[it->first]->getIsWearingHelmet())
    {
      rightMotorSafety += 5;
    }
  }
  if(rightMotorSafety == leftMotorSafety)
  {
    //hit truck
    cout<<"Car crashing into truck"<<endl;
  }
  else if(rightMotorSafety > leftMotorSafety)
  {
    //hit right motorcycle
    cout<<"Crashing into right motorcycle"<<endl;
  }
  else{
    //hit left motorcycle
    cout<<"Crashing into left motorcycle"<<endl;
  }
  return 0;
}
