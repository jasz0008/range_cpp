#ifndef RANGECPP_RANGE_HPP
#define RANGECPP_RANGE_HPP

#include <vector>

namespace rangecpp {

std::vector<size_t> range(size_t stop);

std::vector<size_t> range(size_t start, size_t stop, int step = 1);

}

#endif
