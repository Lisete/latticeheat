#include "backend.h"

double* createLattice(int size) {
	double* lattice = new double[size];
	for (int i = 0; i < size; i++) {
		lattice[i] = 0;
	}
	
	return lattice;
}

void setBounds(double* lattice, double t0, double t1, int size) {
	lattice[0] = t0;
	lattice[size - 1] = t1;
}

void update(double time, double dx, double dt, int size, double* lattice, double alpha) {
	double* temp = createLattice(size);
	for (int i = 0; i < size; i++) {
		temp[i] = lattice[i];
	}
	
	for (int i = 1; i < size - 1; i++) {
		lattice[i] = temp[i] + alpha*dt*(temp[i-1] + temp[i+1] - 2* temp[i]) / (dx*dx);
	}

	delete temp;
}