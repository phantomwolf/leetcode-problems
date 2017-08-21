opts = -g -std=c++11 -Wall -pipe

all: max_xor_of_two max_xor_subarray subarray_less_than_k

max_xor_of_two: max_xor_of_two.cpp Trie.h
	g++ $(opts) -o max_xor_of_two max_xor_of_two.cpp

max_xor_subarray: max_xor_subarray.cpp Trie.h
	g++ $(opts) -o max_xor_subarray max_xor_subarray.cpp

subarray_less_than_k: subarray_less_than_k.cpp Trie.h
	g++ $(opts) -o subarray_less_than_k subarray_less_than_k.cpp

.PHONY: clean

clean:
	rm -f max_xor_of_two max_xor_subarray subarray_less_than_k
