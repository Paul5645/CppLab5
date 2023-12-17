import Math;
#include <cmath>
#include <iostream>

using namespace Math;
	
	Complex f(const Complex& z)
	{
		Complex rezult;
		Complex u = z;
		Complex a = 1.0i;
		return rezult = 2 + 3 * a * exp(double(-u));
	}
	Rational f(const Rational& u) {
		// a = 1/2
		Rational a(1, 2);

		// e^(-u)
		double expTerm = std::exp(double((-u)));

		// 2+3a*e^(-u)
		double term = 2 + 3 * double(a) * expTerm;

		// ¬озвращаем приведенный к виду рациональной дроби результат с точностью до дес€тых
		return Rational(int(term*10),10);
	}
	double f(double x) {
		return(2 + 1.5 * exp(-x));
	}

	int main()
	{
		std::cout << "double f(0.5) = "<<f(0.5)<< std::endl;
		std::cout << "double f(0.7) = " << f(0.7) << std::endl;
		std::cout << "double f(1.5) = " << f(1.5) << std::endl<< std::endl;
		

		Rational r = Rational(1, 2);
		std::cout <<"Rational (1/2) = " << f(r) << std::endl;

		Rational r2 = Rational(7, 10);
		std::cout << "Rational f(7/10) = " << f(r2) << std::endl;

		Rational r3 = Rational(3, 2);
		std::cout << "Rational f(3/2) = " << f(r3) << std::endl << std::endl;

		Complex z = (1, 2);
		std::cout << "Complex f(1+2i) = " << f(z) << std::endl;

		Complex z2 = (7, 10);
		std::cout << "Complex f(7+10i) = " << f(z2) << std::endl;

		Complex z3 = (3, 2);
		std::cout << "Complex f(3+2i) = " << f(z3) << std::endl;

		return 0;
	}
