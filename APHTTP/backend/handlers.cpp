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
}

API::signupHandler::signupHandler(API* parentApi){
  api = parentApi;
}

Response* API::signupHandler::callback(Request *req) {
    Response *res = new Response();
    res->setHeader("Content-Type", "text/html");
    string username = req->getBodyParam("username");
    cout << "req body:" << req->getBody() << endl;
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
        server.get("/css-style", new ShowFile("static/src/style.css", "text/css"));
        server.get("/images/taxi", new ShowImage("static/image/draw.png"));
        server.get("/images/ut_logo", new ShowImage("static/image/logo.png"));
        server.post("/signup", new signupHandler(this));
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