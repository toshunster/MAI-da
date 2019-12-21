#include "utils.hpp"

namespace utils {

int modular_exponentaions(uint32_t num, uint32_t pow, uint32_t mod)
{
    uint64_t res = 1;
    while (pow > 0) {
        if (pow & 1) {
            res = (res * num) % mod;
        }
        pow /= 2;
        num = (num * num) % mod;
    }
    return res;
}

size_t strstr_rk (const std::string & text, const std::string & pattern, const size_t start_pos)
{
    if (pattern.size() > text.size() || text.size() - start_pos < pattern.size()) {
        return std::string::npos;
    }

    const uint32_t base = 2048;

    // Mersenne prime: 2 ** n - 1.
    const uint32_t prime = 2047;

    size_t n = text.size(), m = pattern.size();

    uint64_t max_power = modular_exponentaions(base, m-1, prime);
    int64_t h_t = 0, h_p = 0;

    for (size_t i = 0; i < m; ++i) {
        h_t = (h_t * base + text[i+start_pos]) % prime;
        h_p = (h_p * base + pattern[i]) % prime;
    }

    for (size_t i = start_pos; i <= n - m; ++i) {
        if (h_t == h_p && pattern == text.substr(i,m)) {
            return i;
        }

        if (i < n - m) {
            h_t = ( (h_t - text[i] * max_power) * base + text[i+m] ) % prime;
            if ( h_t < 0 ) {
                h_t += prime;
            }
        }
    }

    return std::string::npos;
}

} // namespace utils
