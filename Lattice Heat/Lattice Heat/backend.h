#ifndef __Lattice_Heat__backend__
#define __Lattice_Heat__backend__

#include <stdio.h>

double* createLattice(int size);
void setBounds(double* lattice, double x0, double x1, int size);
void update(double time, double dx, double dt, int size, double* lattice, double alpha);

#endif /* defined(__Lattice_Heat__backend__) */
