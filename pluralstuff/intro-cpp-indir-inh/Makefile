CXX := /home/maran/bin/clang++
CXXINCFLAGS := -std=c++1z -I /home/maran/eclipse/boost_1_62_0 #-Werror=narrowing #-O3
CXXFLAGS := -Wall -g $(CXXINCFLAGS) -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
#CXXDEFS := -DDEBUG
LDFLAGS := -lpthread
SRC := $(wildcard *.cpp)
TARGET := $(SRC:%.cpp=bin/%)

all: bin bin/plural

bin/plural : pointer_and_inheritance.cpp Person.cpp Tweeter.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEFS) pointer_and_inheritance.cpp Person.cpp Tweeter.cpp -o $@ $(LDFLAGS)

bin:
	mkdir bin

clean:
	rm -fr bin/ *~
