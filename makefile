all: run-trees

run-trees: BSTree.o BSTree_main.cpp
		c++ -g -std=c++11 BSTree_main.cpp BSTree.o -o run-trees

BSTree.o: BSTree.cpp BSTree.h
		c++ -g -std=c++11 -c BSTree.cpp

clean:
		rm *.o run-trees