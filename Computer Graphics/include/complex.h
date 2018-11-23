#pragma once

#include <iostream>

namespace cgmath
{
	class complex
	{
	public:
		// Estas dos variables se guardan en memoria de manera contigua.
		// S�lo las variables se almacenan, los m�todos no.
		float real;
		float imag;

		// Constructor por default.
		complex();
		// Constructor con 2 par�metros.
		complex(float real, float imag);

		// Forma de imprimir esta clase; com�n en otros lenguajes.
		void print() const;
		// Forma preferida en C++ de imprimir esta clase.
		friend inline std::ostream& operator<<(std::ostream& os, const complex& c)
		{
			os << c.real << " + " << c.imag << "i";
			return os;
		}

		// Forma de sumar (+=) dos n�meros complejos; com�n en otros lenguajes.
		void add(const complex& other);
		// Forma preferida en C++ de sumar (+=) dos n�meros complejos.
		complex& operator+=(const complex& other);

		// Forma de sumar (+) dos n�meros complejos; com�n en otros lenguajes.
		static complex add(const complex& a, const complex& b);
	};

	// Forma preferida en C++ de sumar (+) dos n�meros complejos.
	inline complex operator+(const complex& a, const complex& b)
	{
		return complex(a.real + b.real, a.imag + b.imag);
	}
}