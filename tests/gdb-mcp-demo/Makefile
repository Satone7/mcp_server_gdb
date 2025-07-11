CXXFLAGS_COVERAGE = -fprofile-arcs -ftest-coverage
LDFLAGS_COVERAGE = -lgcov

all: main

main: main.cpp
	$(CXX) -g -o main main.cpp

coverage: main_cov
	./main_cov
	gcov -b main.cpp

main_cov: main.o
	$(CXX) -g $(CXXFLAGS_COVERAGE) -o main_cov main.o $(LDFLAGS_COVERAGE)

main.o: main.cpp
	$(CXX) -g $(CXXFLAGS_COVERAGE) -c main.cpp

clean:
	rm -f main main_cov *.o *.gcno *.gcda *.gcov