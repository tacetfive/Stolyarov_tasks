#include <cstdio>
#include <cmath>

typedef long long sll;
typedef unsigned long long ull;

class Rational {
    sll num; // numerator
    ull den; // denominator
public:
    sll Get_num() { return num; }
    ull Get_den() { return den; }
// constructors
    Rational(sll m) { num = m; den = 1; }
    Rational(sll m, ull n) { num = m; den = n; }
// override arithmetic operators
    Rational operator+(Rational addend) {
        Rational sum((num * addend.Get_den() + addend.Get_num() * den),
                        den * addend.Get_den());
        return sum;
    }
    Rational operator-(Rational subtr) {
        Rational difference((num * subtr.Get_den() - subtr.Get_num() * den),
                        den * subtr.Get_den());
        return difference;
    }
    Rational operator*(Rational factor) {
        Rational product((num * factor.Get_num()), den * factor.Get_den());
        return product;
    }
    Rational operator/(Rational divisor) {
        Rational quotient((num * divisor.Get_den()), den * divisor.Get_num());
        return quotient;
    }
// override assignment operators
    const Rational& operator+=(const Rational& addend) {
        num = num * addend.den + addend.num * den;
        den = den * addend.den;
        return *this;
    }
    const Rational& operator-=(const Rational& subtr) {
        num = num * subtr.den - subtr.num * den;
        den = den * subtr.den;
        return *this;
    }
    const Rational& operator*=(const Rational& factor) {
        num *= factor.num;
        den *= factor.den;
        return *this;
    }
    const Rational& operator/=(const Rational& divisor) {
        num *= divisor.den;
        den *= divisor.num;
        return *this;
    }
// cast operators
    operator double() { return num/den; }
    operator int() { return round(num/den); }
};

int main()
{
    Rational a(7, 8);
    Rational b(22, 7);
    printf("a =  %lld / %llu\n", a.Get_num(), a.Get_den());
    printf("b =  %lld / %llu\n", b.Get_num(), b.Get_den());
    Rational c = a + b;
    printf("a + b  %lld / %llu\n", c.Get_num(), c.Get_den());
    c = a - b;
    printf("a - b  %lld / %llu\n", c.Get_num(), c.Get_den());
    c = a * b;
    printf("a * b  %lld / %llu\n", c.Get_num(), c.Get_den());
    c = a / b;
    printf("a / b  %lld / %llu\n", c.Get_num(), c.Get_den());
    b += 4;
    printf("b += 4  %lld / %llu\n", b.Get_num(), b.Get_den());
    b += 7.67;
    printf("b += 7.67  %lld / %llu\n", b.Get_num(), b.Get_den());
    a = b;
    a *= Rational(78,8889);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    a *= Rational(78,8889);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    a *= Rational(78,8889);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    a *= Rational(78,8889);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    a *= Rational(78,8889);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    a *= Rational(78,8889);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    a *= Rational(78,8889);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    a *= Rational(78,8889);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    a = Rational(-14);
    printf("%lld / %llu\n", a.Get_num(), a.Get_den());
    return 0;
}

/* this code causes error:
In member function ‘const Rational& Rational::operator-=(const Rational&)’:
p10t08.cpp:42:34: error: passing ‘const Rational’ as ‘this’ argument discards qualifiers [-fpermissive]
42 |         num = num * subtr.Get_den() - subtr.Get_num() * den;
   |                     ~~~~~~~~~~~~~^~/
When using getters instead of just field names:
    const Rational& operator-=(const Rational& subtr) {
        num = num * subtr.Get_den() - subtr.Get_num() * den;
        den = den * subtr.Get_den();
        return *this;
    }
*/
