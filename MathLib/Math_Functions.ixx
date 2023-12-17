module;

#include <cmath>

export module Math: Functions;

export namespace Math
{
    // Функция для нахождения наибольшего общего делителя
    int FindGreatestCommonDivisor(const int& x, const int& y) {
        int a, b;
        if (x >= y) {
            a = abs(x);
            b = abs(y);
        }
        else {
            a = abs(y);
            b = abs(x);
        }
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // Функция для нахождения наименьшего общего кратного
    int FindLeastCommonMultiple(const int& x, const int& y) {
        // Используем формулу lcm = |xy| / gcd(x, y)
        return (std::abs(x) * std::abs(y) / FindGreatestCommonDivisor(x, y)) ;
    }
    // Функция для сокращения рациональной дроби
    void ReduceFraction(int& numerator, int& denominator) {
        int gcd = FindGreatestCommonDivisor(numerator, denominator);
        short sign = 1;
        if (numerator < 0) sign *= -1;
        if(denominator < 0) sign *= -1;
        numerator = abs(numerator);
        denominator = abs(denominator);
        // Сокращение числителя и знаменателя
        numerator /= gcd;
        numerator *= sign;
        denominator /= gcd;

    }
}