#include <iostream>
#include <vector> 
#include "timecounter.h"
#include "randfiller.h"
#include <algorithm>
#include "ordinamento.hpp"
#include <iomanip> // Libreria trovata tramite IA


int main(void) {
	randfiller rf;
	timecounter tc;
	
	const int w = 15;
	
	std::cout << "\n" << std::left
			  << std::setw(10)<< "Dim (n)"
			  << std::setw(w) << "Bubble (s)"
			  << std::setw(w) << "Insertion (s)" 
			  << std::setw(w) << "Selection (s)"
			  << std::setw(w) << "std::sort (s)" << "\n"
			  << "--------------------------------------------------------------------\n";
	
	// 4 = 2^2, ..., 8192 = 2^13
	//4 8 16 32 64 128 256 512 1024 2048 5096 8192
	for (int n = 4; n <= 8192; n *= 2)
	{
		// Creo un vettore casuale
		std::vector<double> v;
		v.resize(n);
		rf.fill(v, -10000.0, 10000.0);
		
		//Creo delle copie del vettore per eseguire l'ordinamento con i vari algoritmi
		std::vector<double> v1 = v; std::vector<double> v2 = v; std::vector<double> v3 = v;
		
		//Tempo Bubble Sort
		tc.tic();
		bubble_sort(v1);
		double t_bubble = tc.toc();
		
		//Tempo Insertion Sort
		tc.tic();
		insertion_sort(v2);
		double t_insertion = tc.toc();
		
		//Tempo Selection Sort
		tc.tic();
		selection_sort(v3);
		double t_selection = tc.toc();
		
		//Tempo std::sort()
		tc.tic();
		std::sort(v.begin(), v.end());
		double t_sort = tc.toc();
		
		std::cout << std::left
			  << std::setw(10)<< n
			  << std::setw(w) << t_bubble
			  << std::setw(w) << t_insertion 
			  << std::setw(w) << t_selection
			  << std::setw(w) << t_sort 
			  << "\n";
	}

	return 0;
}