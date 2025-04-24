#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <algorithm>  // for std::find
#include <stdexcept>  // for std::runtime_error
#include <iterator>   // for std::distance

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    // Find the first occurrence of 'value' in 'container'
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    // Check if the value was found
    if (it == container.end()) {
        // Option 1: Throw an exception
        throw std::runtime_error("Value not found in container");
        
        // Option 2: Return end iterator (comment out the throw above if using this)
        // return it;
    }
    
    // Return iterator to the found element
    return it;
}

#endif