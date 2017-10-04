# Dupplicate-Elimination
Duplicate Elimination using hashing and BTrees

	-Eavanshi Arora - 201501115

Folder contains 3 files:

code.cpp - main program that calls the appropriate program according to index.

btree.cpp - contains code of btree it opens input file puts distinct tuple in btree and then outputs
tuples in GetNext() function.

hash.cpp - contains code of hash it opens input file puts distinct tuple in C++ map and then outputs
tuples in GetNext() function.

Index Type :
1 - btree
0 - hash

Execute:
g++ --std=c++11 code.cpp

./a.out <input_file> <number_of_attributes> <number_of_blocks> <index_type>

Output :
Distinct tuples will be outputted in Output.txt file
