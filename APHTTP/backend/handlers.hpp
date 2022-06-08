#ifndef _MY_HANDLERS_
#define _MY_HANDLERS_

#include "../server/server.hpp"
#include <iostream>
#include "UTaxi.hpp"

class API{
private:
  UTaxi* utaxi; 
  class cancelTripHandler: public RequestHandler {
  public:
    Response *callback(Request *);
  };

  class signupHandler : public RequestHandler {
  public:
    signupHandler(API* );
    Response *callback(Request *);
  private:
    API* api;
  };


  class tripRequestHandler : public RequestHandler {
  public:
    Response *callback(Request *);
  };

  class tempHandler : public TemplateHandler {
  public:
    tempHandler(std::string filePath);
    std::map<std::string, std::string> handle(Request *req);
  };

public:
    API(std::string mapLocation);
    void run();

};

#endif
