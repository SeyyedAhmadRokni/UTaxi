#ifndef HAND_C
#define HAND_C
#include "handlers.hpp"
#include <bits/stdc++.h>
#include "UTaxi.hpp"
#include "UTException.hpp"

using namespace std;



Response* API::cancelTripHandler::callback(Request* req){
    Response *res = new Response();
    res->setHeader("Content-Type", "text/html");
    string username = req->getBodyParam("username");
    int id = stoi(req->getBodyParam("id"));
    utaxi->cancelTrip(username, id);
}

Response* API::signupHandler::callback(Request *req) {
    Response *res = new Response();
    res->setHeader("Content-Type", "text/html");
    return res;
}

Response* API::tripRequestHandler::callback(Request *req){
    Response *res = new Response();
    res->setHeader("Content-Type", "text/html");

    return res;
  
}

API::tempHandler::tempHandler(string filePath) : TemplateHandler(filePath) {}

map<string, string> API::tempHandler::handle(Request *req) {
    map<string, string> context;
    string newName = "I am " + req->getQueryParam("name");
    context["name"] = newName;
    context["color"] = req->getQueryParam("color");
    return context;
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
        server.post("/signup", new signupHandler());
        server.post("/trip-request", new tripRequestHandler());
        server.run();
    }
    catch (Server::Exception e) {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(UTException ex){
      ex.showMassage();
    }
}

#endif