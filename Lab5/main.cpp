import Math;
#include <cmath>
namespace Math {
	Complex f(const Complex& z) {
		// ���������� ������� a^b = e^(b ln(a)), ��� � - ������������ �����, � b - �����������
		double im = std::pow(3 * exp(1.0),-z);
		return 2 + (im)i;
	}
	Rational f(const Rational& r) {
		Rational a = Rational(1, 2);


	}
	double f(double x) {
		return(2 + 1.5 * exp(-x));
	}

	int main()
	{
		return 0;
	}
}	