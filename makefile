all: sentence anagrams
sentence: sentence.cpp
	g++ -o sentence sentence.cpp -Wall -std=c++11
anagrams: anagrams.cpp
	g++ -o anagrams anagrams.cpp -Wall -std=c++11
