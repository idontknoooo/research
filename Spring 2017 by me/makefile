output: main.o detail.o people.o
	g++ main.o detail.o people.o -o output
detail.o: detail.cpp
	g++ -std=c++11 -c detail.cpp
people.o: people.cpp
	g++ -std=c++11 -c people.cpp
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm *.o output
