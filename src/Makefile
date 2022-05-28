CC := g++ -std=c++11
CCFLAGS := -g -c

utaxi.out: main.o Area.o GeneralFunctions.o Persons.o Trip.cpp UTaxi.o Location.o UTException.o
	$(CC) Area.o GeneralFunctions.o Persons.o Trip.cpp UTaxi.o Location.o main.o UTException.o -o utaxi.out

main.o: main.cpp UTaxi.hpp Defines.hpp Persons.hpp Trip.hpp
	$(CC) $(CCFLAGS) main.cpp

Area.o: Area.cpp Location.hpp Area.hpp
	$(CC) $(CCFLAGS) Area.cpp

GeneralFunctions.o: GeneralFunctions.cpp GeneralFunctions.hpp
	$(CC) $(CCFLAGS) GeneralFunctions.cpp

Persons.o: Persons.cpp Persons.hpp Defines.hpp UTException.hpp 
	$(CC) $(CCFLAGS) Persons.cpp

Trip.o: Trip.cpp Defines.hpp Trip.hpp Persons.hpp UTException.hpp
	$(CC) $(CCFLAGS) Trip.cpp

UTaxi.o: UTaxi.cpp UTaxi.hpp GeneralFunctions.cpp Defines.hpp Persons.hpp Area.hpp Trip.hpp
	$(CC) $(CCFLAGS) UTaxi.cpp

Location.o: Location.cpp Location.hpp
	$(CC) $(CCFLAGS) Location.cpp

UTException.o: UTException.cpp UTException.hpp
	$(CC) $(CCFLAGS) UTException.cpp

clean:
	rm *.o utaxi.out

