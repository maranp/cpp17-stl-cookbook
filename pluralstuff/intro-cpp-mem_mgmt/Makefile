CXX := /home/maran/bin/clang++
CXXINCFLAGS := -std=c++1z -I /home/maran/eclipse/boost_1_62_0 #-Werror=narrowing #-O3
CXXFLAGS := -Wall -g $(CXXINCFLAGS) -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
#CXXDEFS := -DDEBUG
LDFLAGS := -lpthread
SRC := $(wildcard *.cpp)
TARGET := $(SRC:%.cpp=bin/%)

all: bin bin/plural

#bin/plural : memory.cpp Person.cpp
#	$(CXX) $(CXXFLAGS) $(CXXDEFS) memory.cpp Person.cpp -o $@ $(LDFLAGS)

#bin/plural : containers.cpp
#	$(CXX) $(CXXFLAGS) $(CXXDEFS) containers.cpp -o $@ $(LDFLAGS)

bin/plural : pimpl_main.cpp Pimpl_Account.cpp Pimpl_AccountImpl.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEFS) pimpl_main.cpp Pimpl_Account.cpp Pimpl_AccountImpl.cpp -o $@ $(LDFLAGS)

bin:
	mkdir bin

clean:
	rm -fr bin/ *~
