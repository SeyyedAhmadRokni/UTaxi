#ifndef HAND_C
#define HAND_C
#include "handlers.hpp"
#include <bits/stdc++.h>
#include "UTaxi.hpp"
#include "UTException.hpp"
#include "GeneralFunctions.hpp"

using namespace std;

Response* API::showMassage(string massage){
  Response *res = new Response();
  res->setHeader("Content-Type", "text/html");
  ifstream file;
  file.open("static/src/massage.html");
  string readed = "";
  string buffer;
  while (getline(file, buffer)) {
    readed += buffer += "\n";
  }
  string replaced = "[massage]";
  readed.replace(readed.find(replaced), replaced.length(), massage);
  res->setBody(readed);
  return res;
}


API::cancelTripHandler::cancelTripHandler(UTaxi* taxiService){
  utaxi = taxiService;
}

Response* API::cancelTripHandler::callback(Request* req){
  try{
    string username = req->getBodyParam("username");
    int id = stoi(req->getBodyParam("trip-id"));
    utaxi->cancelTrip(username, id);
    return showMassage(SUCCESS_MASSAGE);
  }
  catch(UTException& ex){
    cout << "break!" << endl;
    return showMassage(ex.getMassage());
  }
}

API::signupHandler::signupHandler(UTaxi* taxiService){
  utaxi = taxiService;
}

Response* API::signupHandler::callback(Request *req) {
  try{
    string username = req->getBodyParam("username");
    Role role = utaxi->identifyRole(req->getBodyParam("role"));
    utaxi->signup(username, role);
    return showMassage(SUCCESS_MASSAGE);
  }
  catch(UTException& ex){
    return showMassage(ex.getMassage());
  }
}

API::tripRequestHandler::tripRequestHandler(UTaxi* taxiService){
  utaxi = taxiService;
}
Response* API::tripRequestHandler::callback(Request *req){
  try{
    string username = req->getBodyParam("username");
    string origin = req->getBodyParam("origin");
    string destination = req->getBodyParam("destination");
    bool inHurry = stringToBool(req->getBodyParam("in_hurry"));
    string button = req->getBodyParam("button");
    if (button == "calculate-cost"){
      double cost = utaxi->getTripCost(username, origin, destination, inHurry);
      return showMassage("Trip cost : " + to_string(cost));
    }
    else if (button == "request"){
      int tripId = utaxi->startTrip(username, origin, destination, inHurry);
      return showMassage("Trip id : " + to_string(tripId));
    }
  }
  catch(UTException& ex){
    return showMassage(ex.getMassage());
  }
  
}

API::acceptTripHandler::acceptTripHandler(UTaxi* utaxiService){
  utaxi = utaxiService;
}

Response* API::acceptTripHandler::callback(Request* req){
  Response* res = new Response();
  res->setHeader("Content-Type", "text/html");

  string username = req->getQueryParam("username");
  int id = stoi(req->getQueryParam("id"));
  utaxi->acceptTrip(username, id);

  res->redirect("/trips-list?username="+username);
  return res;
}

API::finishTripHandler::finishTripHandler(UTaxi* utaxiService){
  utaxi = utaxiService;
}

Response* API::finishTripHandler::callback(Request* req){
  Response* res = new Response();
  res->setHeader("Content-Type", "text/html");

  string username = req->getQueryParam("username");
  int id = stoi(req->getQueryParam("id"));
  utaxi->finishTrip(username, id);

  res->redirect("/trips-list?username="+username);
  return res;
}

API::tripsListHandler::tripsListHandler(UTaxi* taxiService){
  utaxi = taxiService;
}

Response* API::tripsListHandler::callback(Request* req){
  try{
    Response* res = new Response();
    res->setHeader("Content-Type", "text/html");
    ifstream file;
    file.open("static/src/trips-list-table.html");
    string readed = "";
    string buffer;
    while (getline(file, buffer)) {
      readed += buffer += "\n";
    }
    string replace = "[Data]";
    string username = req->getQueryParam("username");
    bool is_sorted = stringToBool(req->getQueryParam("is_sorted"));
    string tableData = utaxi->getAllTrips(username, is_sorted);
    readed.replace(readed.find(replace), replace.length(), tableData);
    
  }
  catch(UTException& ex){
    showMassage(ex.getMassage());
  }
}


API::API(string mapLocation){
    utaxi = new UTaxi(mapLocation);
}

void API::run(){
    try {
        Server server;
        server.get("/", new ShowPage("static/src/home.html"));
        server.get("/signup", new ShowPage("static/src/signup-page.html"));
        server.get("/trip-request", new ShowPage("static/src/trip-request.html"));
        server.get("/trips-list", new ShowPage("static/src/trip-list-request.html"));
        server.get("/cancel-trip", new ShowPage("static/src/cancel-trip.html"));
        server.get("/css-style", new ShowFile("static/src/style.css", "text/css"));
        server.get("/images/taxi", new ShowImage("static/image/draw.png"));
        server.get("/images/ut_logo", new ShowImage("static/image/logo.png"));
        server.get("/massage", new ShowFile("static/src/massage.html", "text/html"));
        server.get("/trips-table", new ShowFile("static/src/trips-list-table.html", "text/html"));
        server.post("/signup", new signupHandler(utaxi));
        server.post("/trip-request", new tripRequestHandler(utaxi));
        server.post("/cancel-trip", new cancelTripHandler(utaxi));
        server.get("/trips-list", new tripsListHandler(utaxi));
        server.get("/accept-trip", new acceptTripHandler(utaxi));
        server.get("/finish-trip", new finishTripHandler(utaxi));
        server.run();
    }
    catch (Server::Exception& e) {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(UTException& ex){
      ex.getMassage();
    }
}

#endif