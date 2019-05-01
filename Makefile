
target: obj obj/main.o
	g++ -Wall -pedantic -std=c++11 obj/main.o

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/Alias.hh  inc/Graph.hh src/Graph.cpp inc/Priority.hh src/Priority.cpp inc/ListGraph.hh src/ListGraph.cpp
	g++ -c -g -Iinc -Isrc -std=c++11 -Wall -pedantic -o obj/main.o src/main.cpp


clean:
	rm -f obj/*.o
