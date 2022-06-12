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
    cancelTripHandler(UTaxi*);
    Response *callback(Request *);
  private:
    UTaxi* utaxi;
  };

  class signupHandler : public RequestHandler {
  public:
    signupHandler(UTaxi* );
    Response *callback(Request *);
  private:
    UTaxi* utaxi;
  };


  class tripRequestHandler : public RequestHandler {
  public:
    tripRequestHandler(UTaxi*);
    Response *callback(Request *);
  private:
    UTaxi* utaxi;
  };

  class tripsListHandler : public RequestHandler {
  public:
    tripsListHandler(UTaxi*);
    Response *callback(Request *);
  private:
    UTaxi* utaxi;
  };

  class acceptTripHandler: public RequestHandler {
  public:
    acceptTripHandler(UTaxi*);
    Response *callback(Request *);
  private:
    UTaxi* utaxi;
  };

  class finishTripHandler: public RequestHandler {
  public:
    finishTripHandler(UTaxi*);
    Response *callback(Request *);
  private:
    UTaxi* utaxi;
  };

  static Response* showMassage(std::string massage);

public:
    API(std::string mapLocation);
    void run();

};

#endif
