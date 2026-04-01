#include <iostream>
#include "rational.hpp"

// Controllo che tutte le operazioni definite in rational.hpp funzionino
// Verifico inoltre la buona gestione dei vari casi da parte dell'operatore di stream che ho ridefinito

int main()
{
	rational<int> n(1,1);
	rational<int> r;
	rational<int> r1(4,5);
	rational<int> r2(8,9);
	rational<int> r3(2,6);
	rational<int> r0(0,0);
	rational<int> rInf1(12,0);
	rational<int> rInf2(3,0);
	std::cout << "Output desiderato: 0,        " << "Output ottenuto: " << r << "\n";
	std::cout << "Output desiderato: 1,        " << "Output ottenuto: " << n << "\n";
	std::cout << "Output desiderato: 4/5,      " << "Output ottenuto: " << r1 << "\n";
	std::cout << "Output desiderato: 1/3,      " << "Output ottenuto: " << r3 << "\n";
	std::cout << "Output desiderato: 11/9,     " << "Output ottenuto: " << r2+r3 << "\n";
	std::cout << "Output desiderato: 17/9,     " << "Output ottenuto: " << r2+n << "\n";
	std::cout << "Output desiderato: 32/45,    " << "Output ottenuto: " << r1*r2 << "\n";
	std::cout << "Output desiderato: 8/3,      " << "Output ottenuto: " << r2/r3 << "\n";
	std::cout << "Output desiderato: NaN,      " << "Output ottenuto: " << r0-r3 << "\n";
	std::cout << "Output desiderato: NaN,      " << "Output ottenuto: " << rInf1 - rInf2 << "\n";
	std::cout << "Output desiderato: Inf,      " << "Output ottenuto: " << rInf1 + rInf2 << "\n";

return 0;

}