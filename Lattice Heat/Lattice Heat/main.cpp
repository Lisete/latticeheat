//  main.cpp
//  Lattice Heat

#include <iostream>
#include "backend.h"
#define SIZE 10

int main(int argc, const char * argv[]) {
	double* lattice = createLattice(SIZE);
	int i;
	setBounds(lattice, 10, 200, 10);
	
	for (i = 0; i < 100; i++) {
		update(i, 1, 1, SIZE, lattice, 0.5);
	}
	
	for (i = 0; i < SIZE; i++) {
		std::cout << lattice[i] << "\n";
	}
	
	std::cout << "\n";
	
	lattice = createLattice(SIZE);
	setBounds(lattice, 10, 200, 10);
	
	for (i = 0; i < 100; i++) {
		update(i, 1, 1, SIZE, lattice, 0.1);
	}
	
	for (i = 0; i < SIZE; i++) {
		std::cout << lattice[i] << "\n";
	}
	
	std::cout << "\n";
	delete lattice;

    return 0;
}