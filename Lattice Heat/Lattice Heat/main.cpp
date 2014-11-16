//  main.cpp
//  Lattice Heat

#include <iostream>
#include <cstdio>
#include <cstring>
#include "backend.h"

int main(int argc, const char * argv[]) {
	char line[200];
	FILE *fp;
	char filename[200];
	strcat(filename, argv[2]);
	
	fp = fopen(filename, "r");
	
	if (fp==NULL) {
		return -1;
	}
	
	int size, nt;
	double t0, t1, x0, x1, alpha, dt;
	
	fscanf(fp, "%*s %*s %i", &size);
	fscanf(fp, "%*s %*s %lf", &t0);
	fscanf(fp, "%*s %*s %lf", &t1);
	fscanf(fp, "%*s %*s %lf", &x0);
	fscanf(fp, "%*s %*s %lf", &x1);
	fscanf(fp, "%*s %*s %lf", &alpha);
	fscanf(fp, "%*s %*s %lf", &dt);
	fscanf(fp, "%*s %*s %i", &nt);
	
	std::cout << "size = " << size << "\n";
	std::cout << "T0 = " << t0 << "\n";
	std::cout << "T1 = " << t1 << "\n";
	std::cout << "x0 = " << x0 << "\n";
	std::cout << "x1 = " << x1 << "\n";
	std::cout << "alpha = " << alpha << "\n";
	std::cout << "dt = " << dt << "\n";
	std::cout << "number of timesteps = " << nt << "\n";
	
	double* lattice = createLattice(size);
	int i;
	
	setBounds(lattice, t0, t1, size);
	
	for (i = 0; i < nt; i++) {
		update(i*dt, (x1 - x0)/size, dt, size, lattice, alpha);
	}
	
	for (i = 0; i < size; i++) {
		std::cout << lattice[i] << "\n";
	}

	delete lattice;
	
	return 0;
}