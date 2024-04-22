//utilizzo header guard
#ifndef UTILS_HPP
#define UTILS_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;


double read_single_line(ifstream& fileInput);

void load_arrays(ifstream& fileInput,double* ptr_w, double* ptr_r);

void calcolo_V_r(const double* ptr_w, const double* ptr_r, double& V, double& r, double S, int n);

void stampa_vettore_fo(ofstream& fileOutput, const double* ptr_arr, int n);

void stampa_vettore_screen(ostream& fileOutput, const double* ptr_arr, int n);





#endif // UTILS_HPP
