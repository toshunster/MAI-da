#pragma once

#include <iostream>

#include "vector.hpp"

using Pair = std::pair<int, std::string>;

namespace sort
{

void counting_sort( vector::Vector<Pair> &elems );

} // namespace sort
