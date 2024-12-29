options = -g -pipe -Wall

all: minimum_partition all_partitions

minimum_partition: minimum_partition.c
	gcc $(options) -std=c99 -o minimum_partition minimum_partition.c

all_partitions: all_partitions.cpp
	g++ $(options) -std=c++11 -o all_partitions all_partitions.cpp

.PHONY: clean

clean:
	rm -f minimum_partition all_partitions
