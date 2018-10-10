COMPILER=g++

bin: main.cpp
	$(COMPILER) -o bin main.cpp util.cpp
