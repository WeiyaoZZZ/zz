client:client.cpp Client.o Guichet.o Guichet1.o Guichet2.o Guichet3.o Guichet4.o QueueClient.o
	g++ -o client client.cpp Client.o Guichet.o Guichet1.o Guichet2.o Guichet3.o Guichet4.o QueueClient.o

Client.o:Client.cpp Client.hpp
	g++ -c -o Client.o Client.cpp

Guichet.o:Guichet.cpp Guichet.hpp
	g++ -c -o Guichet.o Guichet.cpp

Guichet1.o:Guichet1.cpp Guichet1.hpp
	g++ -c -o Guichet1.o Guichet1.cpp

Guichet2.o:Guichet2.cpp Guichet2.hpp
	g++ -c -o Guichet2.o Guichet2.cpp

Guichet3.o:Guichet3.cpp Guichet3.hpp
	g++ -c -o Guichet3.o Guichet3.cpp

Guichet4.o:Guichet4.cpp Guichet4.hpp
	g++ -c -o Guichet4.o Guichet4.cpp

QueueClient.o:QueueClient.cpp QueueClient.hpp
	g++ -c -o QueueClient.o QueueClient.cpp

clean:
	-rm-f client *.o
