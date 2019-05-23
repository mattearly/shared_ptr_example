CC= clang++

default: | main.cpp Sdata.it.h Sdata.h 
	$(CC) -std=c++11 main.cpp -o a.out