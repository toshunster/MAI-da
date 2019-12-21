#pragma once

#include <iostream>

namespace utils {

// 'Fast' power. O(log n)
int modular_exponentaions(uint32_t num, uint32_t pow, uint32_t mod);

//! Rabin-Karp algorithm.
size_t strstr_rk (const std::string & text, const std::string & pattern, const size_t start_pos=0);

} // namespace utils
