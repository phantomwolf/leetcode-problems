cxx = g++ -g -std=c++11

all: brute_force binary_search

brute_force: brute_force.cpp
	$(cxx) -o brute_force brute_force.cpp

binary_search: binary_search.cpp
	$(cxx) -o binary_search binary_search.cpp

.PHONY: clean
clean:
	rm -f *.o brute_force binary_search
