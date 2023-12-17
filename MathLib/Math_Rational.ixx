module;

#include <iostream>
#include <cmath>

export module Math:Rational;

import :Functions;
export namespace Math
{
    class Rational {
    private:
        int m_nominator;   // Числитель дроби
        int m_denominator; // Знаменатель дроби
        
    public:
        // Конструктор по умолчанию
        Rational() : m_nominator(0), m_denominator(1) {}

        // Конструктор инициализации
        Rational(int nominator, int denominator){
            ReduceFraction(nominator, denominator);
            m_nominator = nominator;
            m_denominator = denominator;
        }

        // Конструктор преобразования
        Rational(int nominator) : m_nominator(nominator), m_denominator(1) {}

        // Функция-член Nominator
        int Nominator() const {
            return m_nominator;
        }

        // Функция-член Denominator
        int Denominator() const {
            return m_denominator;
        }
        
        // Операция явного преобразования в тип double
        explicit operator double() const {
            return double(double(m_nominator) / double(m_denominator));
        }

        // Операция унарный минус
        Rational operator-() const {
            return Rational(-m_nominator, m_denominator);
        }

        // Префиксная форма инкремента
        Rational& operator++() {
            m_nominator += m_denominator;
            return *this;
        }

        // Постфиксная форма инкремента
        Rational operator++(int) {
            Rational temp(*this);
            ++(*this);
            return temp;
        }

        // Префиксная форма декремента
        Rational& operator--() {
            m_nominator -= m_denominator;
            return *this;
        }

        // Постфиксная форма декремента
        Rational operator--(int) {
            Rational temp(*this);
            --(*this);
            return temp;
        }

        // Составная операция присваивания со сложением
        Rational& operator+=(const Rational& other) {
            m_nominator = m_nominator * other.m_denominator + other.m_nominator * m_denominator;
            m_denominator *= other.m_denominator;
            ReduceFraction(m_nominator, m_denominator);
            return *this;
        }

        // Составная операция присваивания с вычитанием
        Rational& operator-=(const Rational& other) {
            m_nominator = m_nominator * other.m_denominator - other.m_nominator * m_denominator;
            m_denominator *= other.m_denominator;
            ReduceFraction(m_nominator, m_denominator);
            return *this;
        }

        // Составная операция присваивания с умножением
        Rational& operator*=(const Rational& other) {
            m_nominator *= other.m_nominator;
            m_denominator *= other.m_denominator;
            ReduceFraction(m_nominator, m_denominator);
            return *this;
        }

        // Составная операция присваивания с делением
        Rational& operator/=(const Rational& other) {
            m_nominator *= other.m_denominator;
            m_denominator *= other.m_nominator;
            ReduceFraction(m_nominator, m_denominator);
            return *this;
        }
    };

   // Определеные глобальных функций

    Rational operator+(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.Nominator() * rhs.Denominator() + rhs.Nominator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator());
    }

    Rational operator-(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.Nominator() * rhs.Denominator() - rhs.Nominator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator());
    }

    Rational operator*(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.Nominator() * rhs.Nominator(), lhs.Denominator() * rhs.Denominator());
    }

    Rational operator/(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.Nominator() * rhs.Denominator(), lhs.Denominator() * rhs.Nominator());
    }
    
    bool operator==(const Rational& lhs, const Rational& rhs) {
        return (lhs.Nominator() == rhs.Nominator()) && (lhs.Denominator() == rhs.Denominator());
    }

    bool operator!=(const Rational& lhs, const Rational& rhs) {
        return (lhs.Nominator() != rhs.Nominator()) || (lhs.Denominator() != rhs.Denominator());
    }

    bool operator<(const Rational& lhs, const Rational& rhs) {
        return lhs.Nominator() * rhs.Denominator() < rhs.Nominator() * lhs.Denominator();
    }

    bool operator>(const Rational& lhs, const Rational& rhs) {
        return rhs < lhs;
    }

    bool operator<=(const Rational& lhs, const Rational& rhs) {
        return !(rhs < lhs);
    }

    bool operator>=(const Rational& lhs, const Rational& rhs) {
        return !(lhs < rhs);
    }

    std::ostream& operator<<(std::ostream& stream, const Rational& rational) {
        stream << rational.Nominator() << "/" << rational.Denominator();
        return stream;
    }
}