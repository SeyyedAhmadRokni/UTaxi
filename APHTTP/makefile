CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template
SOURCE_DIR=backend

all: $(BUILD_DIR) utaxi.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp 
	$(CC) $(CF) -c -g utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c -g utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c -g utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c -g utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c -g server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c -g server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/handlers.o: $(SOURCE_DIR)/handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c -g $(SOURCE_DIR)/handlers.cpp -o $(BUILD_DIR)/handlers.o

$(BUILD_DIR)/main.o: $(SOURCE_DIR)/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp $(SOURCE_DIR)/UTaxi.hpp $(SOURCE_DIR)/Defines.hpp $(SOURCE_DIR)/Persons.hpp $(SOURCE_DIR)/Trip.hpp
	$(CC) $(CF) -c -g $(SOURCE_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Area.o: $(SOURCE_DIR)/Area.cpp $(SOURCE_DIR)/Location.hpp $(SOURCE_DIR)/Area.hpp
	$(CC) $(CF) -c -g $(SOURCE_DIR)/Area.cpp -o $(BUILD_DIR)/Area.o

$(BUILD_DIR)/GeneralFunctions.o: $(SOURCE_DIR)/GeneralFunctions.cpp $(SOURCE_DIR)/GeneralFunctions.hpp
	$(CC) $(CF) -c -g $(SOURCE_DIR)/GeneralFunctions.cpp -o $(BUILD_DIR)/GeneralFunctions.o

$(BUILD_DIR)/Persons.o: $(SOURCE_DIR)/Persons.cpp $(SOURCE_DIR)/Persons.hpp $(SOURCE_DIR)/Defines.hpp $(SOURCE_DIR)/UTException.hpp 
	$(CC) $(CF) -c -g $(SOURCE_DIR)/Persons.cpp -o $(BUILD_DIR)/Persons.o

$(BUILD_DIR)/Trip.o: $(SOURCE_DIR)/Trip.cpp $(SOURCE_DIR)/Defines.hpp $(SOURCE_DIR)/Trip.hpp $(SOURCE_DIR)/Persons.hpp $(SOURCE_DIR)/UTException.hpp
	$(CC) $(CF) -c -g $(SOURCE_DIR)/Trip.cpp -o $(BUILD_DIR)/Trip.o

$(BUILD_DIR)/UTaxi.o: $(SOURCE_DIR)/UTaxi.cpp $(SOURCE_DIR)/UTaxi.hpp $(SOURCE_DIR)/GeneralFunctions.cpp $(SOURCE_DIR)/Defines.hpp $(SOURCE_DIR)/Persons.hpp $(SOURCE_DIR)/Area.hpp $(SOURCE_DIR)/Trip.hpp
	$(CC) $(CF) -c -g $(SOURCE_DIR)/UTaxi.cpp -o $(BUILD_DIR)/UTaxi.o

$(BUILD_DIR)/Location.o: $(SOURCE_DIR)/Location.cpp $(SOURCE_DIR)/Location.hpp
	$(CC) $(CF) -c -g $(SOURCE_DIR)/Location.cpp -o $(BUILD_DIR)/Location.o

$(BUILD_DIR)/UTException.o: $(SOURCE_DIR)/UTException.cpp $(SOURCE_DIR)/UTException.hpp
	$(CC) $(CF) -c -g $(SOURCE_DIR)/UTException.cpp -o $(BUILD_DIR)/UTException.o

utaxi.out:  $(BUILD_DIR)/main.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o \
	$(BUILD_DIR)/UTException.o $(BUILD_DIR)/Location.o $(BUILD_DIR)/UTaxi.o $(BUILD_DIR)/Trip.o $(BUILD_DIR)/Persons.o $(BUILD_DIR)/GeneralFunctions.o $(BUILD_DIR)/Area.o 
	$(CC) -g $(CF) $(BUILD_DIR)/main.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o \
	$(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o \
	$(BUILD_DIR)/UTException.o $(BUILD_DIR)/Location.o $(BUILD_DIR)/UTaxi.o $(BUILD_DIR)/Trip.o $(BUILD_DIR)/Persons.o $(BUILD_DIR)/GeneralFunctions.o $(BUILD_DIR)/Area.o \
	-o utaxi.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o utaxi.out &> /dev/null
