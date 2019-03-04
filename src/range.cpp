#include <range_cpp/range.hpp>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <stdexcept>

namespace range_cpp {

static std::vector<int> empty{};

static std::vector<int> rangeImpl(const int start,
                                  const int stop,
                                  const int step = 1)
{
    const size_t distance = std::abs(stop - start);
    const size_t size = ((distance / std::abs(step)) + (distance % std::abs(step)));
    std::vector<int> values(size);
    std::generate(std::begin(values), std::end(values), 
                  [n = (start - step), step] () mutable { return n += step; });
    return values;
}

std::vector<int> range(const int stop)
{
    if (stop == 0) { // start == stop
        return empty;
    }

    return rangeImpl(0, stop);
}

std::vector<int> range(const int start, const int stop, const int step)
{
    // Handle invalid step
    if (step == 0) {
        throw std::logic_error("range_cpp::range(): step must not be zero");
    }

    // Handle trivial cases
    if (start == stop) {
        return empty;
    }
    if ((start > stop) && (step > 0)) {
        return empty;
    }
    if ((start < stop) && (step < 0)) {
        return empty;
    }

    return rangeImpl(start, stop, step);
}

} // namespace range_cpp
