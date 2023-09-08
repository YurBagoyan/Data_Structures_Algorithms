# Euclidean Algorithm (GCD and LCM)

The Euclidean algorithm is an efficient method for finding the GCD of two integers. It relies on the following key observation:

- If `a` and `b` are two integers, and `b` is not zero, then the GCD of `a` and `b` is the same as the GCD of `b` and `a % b`. This observation forms the basis of the algorithm's recursive implementation.

### GCD Calculation

The `gcd` function calculates the GCD of two integers `a` and `b` using the Euclidean algorithm through recursion. Here's how it works:

1. The base case of the recursion is when `b` is zero. In this case, the GCD is `a`, and the function returns `a`.

2. If `b` is not zero, the function recursively calls itself with arguments `b` and `a % b`. This process continues until `b` becomes zero, at which point the GCD is found and returned.

### LCM Calculation

The `lcm` function calculates the Least Common Multiple (LCM) of two integers `a` and `b` using the relationship between GCD and LCM:

- LCM(a, b) = (a * b) / GCD(a, b)

Here's how the `lcm` function works:

1. It first calculates the GCD of `a` and `b` by calling the `gcd` function.

2. Then, it uses the formula to compute the LCM and returns the result.

