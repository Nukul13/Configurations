/*
 * stl_utility.h
 *
 *  Created on: 25-Feb-2018
 *      Author: edutech
 */

#ifndef STL_UTILITY_H_
#define STL_UTILITY_H_

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>        // Like python dictionary
#include <tuple>
#include <memory>
#include <string>
#include <type_traits>
#include <iterator>
#include <functional>
#include <algorithm>
#include <numeric>              // some numeric algorithms
#include <cppformat/format.h>   // print format library fmt:: (Note: Add -lcppformat to linker)

/**
 * @brief PrintContainer prints vector, list or set elements by taking
 *        their begin and end iterator from the container. This will
 *        print whole container with space as separator.
 * @param container  provide vector/list/set
 */
template<typename t>
void printContainer(t container) {
    std::copy(container.begin(), container.end(),
            std::ostream_iterator<double>(std::cout, " "));
}

template <typename T>
std::vector <T> range(T start, T stop, T step) {
    if (step == T(0))
    {
      throw std::invalid_argument("step for range must be non-zero");
    }
//    static_assert(isInteger(step), "Integral required.");

    auto a = start-step;
    std::vector<T> numbers(std::ceil((float)(stop-start)/std::abs(step)));
    std::generate(numbers.begin(), numbers.end(), [step, &a](){ return a += step; });
    return numbers;
}


template <typename T>
std::vector <T> range(T start, T stop) {
    std::vector<T> numbers(stop-start);
    std::iota(numbers.begin(), numbers.end(), start);
    return numbers;
}


template <typename T>
std::vector <T> range(T stop) {
    std::vector<T> numbers(stop-0);
    std::iota(numbers.begin(), numbers.end(), 0);
    return numbers;
}


#endif /* STL_UTILITY_H_ */
