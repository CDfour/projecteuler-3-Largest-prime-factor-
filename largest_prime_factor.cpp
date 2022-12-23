#include "largest_prime_factor.h"

#include <vector>

// n = 600851475143, answer = 6857
unsigned long long largest_prime_factor(unsigned long long n) {

    std::vector<unsigned long long>primeNumbers{ 2 };

    bool flag = true;

    for (unsigned long long i = 3; i <= sqrt(n); ++i) {

        for (auto v : primeNumbers) {
            if (i % v == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primeNumbers.push_back(i);
        }
        else {
            flag = true;
        }
    }

    for (int i = (int)primeNumbers.size() - 1;; --i) {

        if (n % primeNumbers[i] == 0) {
            return primeNumbers[i];
        }
    }
}