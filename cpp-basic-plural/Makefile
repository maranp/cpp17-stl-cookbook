CXX := clang++
CXXINCFLAGS := -std=c++17 -I . -I /home/maran/eclipse/boost_1_62_0 #-Werror=narrowing #-O3
CXXFLAGS := -Wall -g $(CXXINCFLAGS) -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
#CXXDEFS := -DDEBUG
#LDFLAGS := -lpthread

all: bin bin/template-demo

bin/template-demo : main.cpp Person.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEFS) main.cpp Person.cpp -o bin/template-demo $(LDFLAGS)

bin:
	mkdir bin

clean:
	rm -fr bin/ *~
