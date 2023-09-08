#include <iostream>

// Greatest Common Divisor
int gcd(const int a, const int b)
{
    return b ? gcd(b, a % b) : a;
}

// Least Common Multiple
int lcm(const int a, const int b)
{
    // a * b  = gcd * lcm => lcm = a * b / gcd
    return a * b / gcd(a, b);

}

int main()
{
    std::cout << gcd(12, 20) << std::endl;
    std::cout << gcd(15, 28) << std::endl;

    std::cout << lcm(15, 24) << std::endl;
    std::cout << lcm(14, 7) << std::endl;
}
