CXX=g++

CXXFLAGS= -std=c++11 -Wall -g

BINARIES=lab04Test

all: ${BINARIES}

lab04Test: lab04Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
