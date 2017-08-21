all: main dp dp_optimized max_heap

main: main.cpp
	g++ -g -std=c++11 -o main main.cpp

dp: dp.cpp
	g++ -g -std=c++11 -o dp dp.cpp

dp_optimized: dp_optimized.cpp
	g++ -g -std=c++11 -o dp_optimized dp_optimized.cpp

max_heap: max_heap.cpp
	g++ -g -std=c++11 -o max_heap max_heap.cpp

.PHONY: clean

clean:
	rm -f main dp dp_optimized max_heap
