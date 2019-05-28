CXX = g++
CXXFLAGS = -Wall
#CXXFLAGS = -Wall -std=c++11

all: test_config

test_config: test_config.cpp config_file.h
	$(CXX) test_config.cpp -o test_config $(CXXFLAGS)

clean:
	rm -f test
 
