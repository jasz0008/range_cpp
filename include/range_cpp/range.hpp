#ifndef RANGE_CPP_RANGE_HPP
#define RANGE_CPP_RANGE_HPP

#include <vector>

namespace range_cpp {

std::vector<size_t> range(size_t stop);

std::vector<size_t> range(size_t start, size_t stop, int step = 1);

}

#endif
