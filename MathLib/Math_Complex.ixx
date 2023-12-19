// Файл "Math_Complex.ixx"

module;

#include <cmath>
#include <iostream>

export module Math:Complex;
export namespace Math
{
    class Complex {
    private:
        double m_re; // Реальная часть комплексного числа
        double m_im; // Мнимая часть комплексного числа

    public:
        // Конструктор по умолчанию
        Complex() : m_re(0), m_im(0) {}

        // Конструктор инициализации
        Complex(double re, double im) : m_re(re), m_im(im) {}

        // Конструктор преобразования
        Complex(double re) : m_re(re), m_im(0) {}

        // Статическая функция-член FromExponentialForm
        static Complex FromExponentialForm(double mod, double arg) {
            double realPart = mod * std::cos(arg);
            double imagPart = mod * std::sin(arg);
            return Complex(realPart, imagPart);
        }

        // Статическая функция-член FromAlgebraicForm
        static Complex FromAlgebraicForm(double re, double im) {
            return Complex(re, im);
        }
        
        // Функция-член Re
        double Re() const {
            return m_re;
        }

        // Функция-член Im
        double Im() const {
            return m_im;
        }

        // Функция-член Mod
        double Mod() const {
            return std::sqrt(m_re * m_re + m_im * m_im);
        }

        // Функция-член Arg
        double Arg() const {
            return std::atan2(m_im, m_re);
        }

        // Операция явного преобразования в тип double. 
        explicit operator double() const {
            return m_re;
        }

        // Операция унарный минус.
        Complex operator-() const {
            return Complex(-m_re, -m_im);
        }

        // Префиксная форма инкремента. 
        Complex& operator++() {
            m_re += 1;
            return *this;
        }

        // Постфиксная форма инкремента. 
        Complex operator++(int) {
            Complex temp(*this);
            ++(*this);
            return temp;
        }

        // Префиксная форма декремента. 
        Complex& operator--() {
            m_re -= 1;
            return *this;
        }

        // Постфиксная форма декремента. 
        Complex operator--(int) {
            Complex temp(*this);
            --(*this);
            return temp;
        }

        Complex& operator+=(const Complex& other) {
            m_re += other.m_re;
            m_im += other.m_im;
            return *this;
        }

        Complex& operator-=(const Complex& other) {
            m_re -= other.m_re;
            m_im -= other.m_im;
            return *this;
        }

        Complex& operator*=(const Complex& other) {
            double temp_re = m_re * other.m_re - m_im * other.m_im;
            double temp_im = m_re * other.m_im + m_im * other.m_re;
            m_re = temp_re;
            m_im = temp_im;
            return *this;
        }

        Complex& operator/=(const Complex& other) {
            double denominator = other.m_re * other.m_re + other.m_im * other.m_im;
            double temp_re = (m_re * other.m_re + m_im * other.m_im) / denominator;
            double temp_im = (m_im * other.m_re - m_re * other.m_im) / denominator;
            m_re = temp_re;
            m_im = temp_im;
            return *this;
        }

    };

    // Реализация глобальных функций

    Complex operator+(const Complex& lhs, const Complex& rhs) {
        Complex result = lhs;
        result += rhs;
        return result;
    }

    Complex operator-(const Complex& lhs, const Complex& rhs) {
        return Complex(lhs.Re() - rhs.Re(), lhs.Im() - rhs.Im());
    }

    Complex operator*(const Complex& lhs, const Complex& rhs) {
        double realPart = lhs.Re() * rhs.Re() - lhs.Im() * rhs.Im();
        double imagPart = lhs.Re() * rhs.Im() + lhs.Im() * rhs.Re();
        return Complex(realPart, imagPart);
    }

    Complex operator/(const Complex& lhs, const Complex& rhs) {
        double denominator = rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im();
        double realPart = (lhs.Re() * rhs.Re() + lhs.Im() * rhs.Im()) / denominator;
        double imagPart = (lhs.Im() * rhs.Re() - lhs.Re() * rhs.Im()) / denominator;
        return Complex(realPart, imagPart);
    }

    export Complex operator""i(long double imag) {
        return Complex(0, imag);
    }

    export Complex operator""i(unsigned long long imag) {
        return Complex(0, imag);
    }
   
    std::ostream& operator<<(std::ostream& stream, const Complex& complex) {
        stream << complex.Re() << " + " << complex.Im() << "i";
        return stream;
    }
   
}