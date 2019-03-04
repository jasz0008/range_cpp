#ifndef RANGE_CPP_RANGE_HPP
#define RANGE_CPP_RANGE_HPP

#include <vector>

namespace range_cpp {

/**
 * Returns an immutable increasing sequence of integers from 0 until stop.
 * @param stop the value of the stop parameter
 * @return an increasing sequence of integers within the interval [0, stop) of
 *         step size 1.
 */
std::vector<int> range(int stop);

/**
 * Returns an immutable sequence of integers from start until stop, optionally
 * taking a specified step size.
 * 
 * For a positive step, the contents of a range r are determined by the formula 
 * r[i] = start + step*i where i >= 0 and r[i] < stop.
 * 
 * For a negative step, the contents of a range r are determined by the formula 
 * r[i] = start + step*i where i >= 0 and r[i] > stop.
 * 
 * A range object will be empty if r[0] does not meet the value constraint. 
 * Ranges do support negative indices, but these are interpreted as indexing
 * from the end of the sequence determined by the positive indices.
 * 
 * @param start the value of the start parameter
 * @param stop  the value of the stop parameter
 * @param step  the value of the step parameter (or 1 if the parameter was not 
 *              specified)
 * @return a sequence of integers within the interval [start, stop).
 */
std::vector<int> range(int start, int stop, int step = 1);

}

#endif
