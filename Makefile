
server:server.cpp Client.o
	g++ -o server server.cpp Client.o

Client.o:Client.cpp Client.hpp
	g++ -c -o Client.o Client.cpp

clean:
	-rm-f server *.o
