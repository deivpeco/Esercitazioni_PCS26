#pragma once
#include <concepts>
#include <iostream>

template<typename I> requires std::integral<I>

// Inizializzazione della classe

class rational 
{
	I num;
	I den;

	public:
	
		// Costruttore di default
		rational()
			: num(I{0}), den(I{1})
		{}
		
		// Costruttore user-defined
		rational(const I& n, const I& d)
			: num(n), den(d)
		{
			semplifica();
		}
		
		// Restituisco i valori numeratore e denominatore
		I numeratore() const {return num;}
		I denominatore() const {return den;}
		
		// Implementazione della somma tra razionali
		
		rational& operator+=(const rational& other) {
			if ((num == 0 && den == 0) || (other.den == 0 && other.num == 0))
			{
				num = 0; den = 0;
			}
			else if((num != 0 && den == 0) || (other.den == 0 && other.num != 0))
			{
				num = 1; den = 0;
			}
			else
			{
				num = (num * other.den) + (other.num * den);
				den = den * other.den;
				semplifica();
			}
			return *this;
		}
		
		rational operator+(const rational& other) const {
			rational ret = *this;
			ret += other;
			return ret;
		}
		
		// Implementazione della sottrazione tra razionali
		
		rational& operator-=(const rational& other) {
			if((num == 0 && den == 0) || (other.den == 0 && other.num == 0))
			{
				num = 0; den = 0;
			}
			else if((num != 0 && den == 0) && (other.den == 0 && other.num != 0))
			{
				num = 0; den = 0;
			}
			else
			{
				num = (num * other.den) - (other.num * den);
				den = den * other.den;
				semplifica();
			}
			return *this;
			
		}
		
		rational operator-(const rational& other) const {
			rational ret = *this;
			ret -= other;
			return ret;
		}
		
		// Implementazione della moltiplicazione tra razionali
		// non viene fatta la gestione dei casi limite perchè deriva dalla definizione dell'operazione
		
		rational& operator*=(const rational& other) {
			num = num * other.num;
			den = den * other.den;
			semplifica();
			return *this;
		}
		
		rational operator*(const rational& other) const {
			rational ret = *this;
			ret *= other;
			return ret;
		}
		
		// Implementazione della divisione tra razionali
		// non viene fatta la gestione dei casi limite perchè deriva dalla definizione dell'operazione
		
		rational& operator/=(const rational& other) {
			num = num * other.den;
			den = den * other.num;
			semplifica();
			return *this;
		}
		
		rational operator/(const rational& other) const {
			rational ret = *this;
			ret /= other;
			return ret;
		}
		
	
	private: 
	
		//  Funzione che trova il massimo comune divisore
		
		I maxcommondiv(I x, I y) 
		{
			if (x<0) {x = -x;}
			if (y<0) {y = -y;}
			while (y != 0)
			{
				I resto = x%y;
				x = y;
				y = resto;
			}
			return x;
		}
		
		// Funzione che semplifica una frazione ai minimi termini
		
		void semplifica()
		{
			if (den == 0){return;}
			I mcd = maxcommondiv(num,den);
			num = num/mcd;
			den = den/mcd;
			if (den < 0) 
			{
				num = -num;
				den = -den;
			}
		}
};


// Overload operatore << al fine di printare correttamente un numero razionale a seconda dei casi

template<typename I> 

std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
	if (r.denominatore() == 0) 
	{
		if (r.numeratore() == 0) {
			os << "NaN";
		}
		else {
			os << "Inf";
		}
	}
	else {
		if (r.numeratore() == 0) {
			os << 0;
		}
		else {
			if (r.denominatore() == 1) {
				os << r.numeratore();
			}
			else {
				os << r.numeratore() << "/" << r.denominatore();
			}
		}
	}
	return os;
}
