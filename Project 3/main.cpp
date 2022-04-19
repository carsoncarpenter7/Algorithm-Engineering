#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdint>

using namespace std;

int dbh_loop_count = 0;

bool root_dbh_range(uint64_t n, uint64_t x, uint64_t lo, uint64_t hi, uint64_t& result) {
    dbh_loop_count++;
    auto mid = (lo + hi) / 2;
    if (mid == lo) {
        return false;
    }
    else if (pow(mid, n) == x) {  // mid^n = pow(mid, exponent)
        result = mid;
        return true;
    }
    else if (pow(mid, n) < x) {
        return root_dbh_range(n, x, mid, hi, result);
    }
    else {
        return root_dbh_range(n, x, lo, mid, result);
    }
}

bool root_dbh(uint64_t n, uint64_t x, uint64_t& result) {
    return root_dbh_range(n, x, 0, x, result);
}

int exhaustive_loop_count = 0;

bool root_exhaustive(uint64_t exponent, uint64_t target, uint64_t& base) {
    for (base = 0; base < target; base++) {
        exhaustive_loop_count++;

        if ((uint64_t) pow(base, exponent) == target)
            return true;
    }

    return false;
}

int main() {
    cout << fixed;

    { // Decrease By Half
        auto start = chrono::system_clock::now();

        uint64_t base;
        uint64_t exponent = 11;
        uint64_t target = 16985107389382393856U;
        auto success = root_dbh(exponent, target, base);

        auto duration = std::chrono::duration<float>(chrono::system_clock::now() - start).count();

        if (base != 0)
            cout << target << " raised to the 1 / " << exponent << " power is " << base << ". (" << dbh_loop_count << " iterations, " << duration << " seconds)\n";
        else
            cout << target << " raised to the 1 / " << exponent << " power has no integer answer. (" << dbh_loop_count << " iterations, " << duration << " seconds)\n";
    }

    { // Exhaustive Search
        auto start = chrono::system_clock::now();

        uint64_t base;
        uint64_t exponent = 11;
        uint64_t target = 16985107389382393856U;
        auto success = root_exhaustive(exponent, target, base);

        auto duration = std::chrono::duration<float>(chrono::system_clock::now() - start).count();

        if (success)
            cout << target << " raised to the 1 / " << exponent << " power is " << base << ". (" << exhaustive_loop_count << " iterations, " << duration << " seconds)\n";
        else
            cout << target << " raised to the 1 / " << exponent << " power has no integer answer. (" << exhaustive_loop_count << " iterations, " << duration << " seconds)\n";
    }
}
