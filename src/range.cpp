#include "range.hpp"
#include <algorithm>
#include <cassert>
#include <numeric>
#include <stdexcept>

namespace rangecpp {

struct Status {
    bool ok;
    const char* message;
};

static std::vector<size_t> sequentiallyIncreasingRange(const size_t start,
                                                       const size_t stop)
{
    assert(stop > start);
    std::vector<size_t> values(stop);
    std::iota(std::begin(values), std::end(values), start);
    return values;
}

static Status validate(const size_t start, const size_t stop, const int step)
{
    assert(stop > start);
    assert((start + step) >= stop);
    // Negative step
    // Start > stop
    // Start or stop near size_t max/min
    // Large step
    // Step over stop
}

std::vector<size_t> range(const size_t stop)
{
    return sequentiallyIncreasingRange(0, stop);
}

std::vector<size_t> range(const size_t start, const size_t stop, const int step)
{
    const Status status = validate(start, stop, step);
    if (!status.ok) {
        throw std::logic_error(status.message);
    }

    if (step == 1) {
        return sequentiallyIncreasingRange(start, stop);
    }

    std::vector<size_t> values((stop - start), start);
    std::accumulate(std::begin(values), std::end(values), step);

    return values;
}

} // namespace rangecpp
