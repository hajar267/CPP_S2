# C++ Modules (05-09)

*This project has been created as part of the 42 curriculum by hfiqar.*

## Description

This series of C++ modules focuses on advanced object-oriented programming concepts in C++98. 
Each module explores specific aspects of the language, from exception handling to template programming and STL containers.

### Module Overview

- **CPP05**: Exception handling, bureaucracy simulation with forms and grades
- **CPP06**: C++ type casting (static_cast, dynamic_cast, reinterpret_cast, const_cast)
- **CPP07**: C++ templates - function templates and class templates
- **CPP08**: Templated containers, iterators, and algorithms (STL introduction)
- **CPP09**: STL containers - practical applications with std::map, std::stack, std::deque

## Structure
```
CPP_Modules/
├── cpp05/
│   ├── ex00/  # Bureaucrat basics
│   ├── ex01/  # Form class
│   ├── ex02/  # Concrete forms
│   └── ex03/  # Intern class
├── cpp06/
│   ├── ex00/  # Scalar conversion
│   ├── ex01/  # Serialization
│   └── ex02/  # Type identification
├── cpp07/
│   ├── ex00/  # Function templates
│   ├── ex01/  # Iter function
│   └── ex02/  # Array template class
├── cpp08/
│   ├── ex00/  # Easy find
│   ├── ex01/  # Span class
│   └── ex02/  # Mutated stack
└── cpp09/
    ├── ex00/  # Bitcoin Exchange
    ├── ex01/  # Reverse Polish Notation
    └── ex02/  # PmergeMe (merge-insert sort)
```

## Instructions

**Compilation:**
Each exercise contains a Makefile. Navigate to the desired exercise and run:
```bash
make
```

**Execution:**
```bash
# Example for CPP05/ex00
cd cpp05/ex00
make
./bureaucrat
```

**Cleaning:**
```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Rebuild everything
```

## Key Concepts

**CPP05 - Exceptions:**
- Try-catch blocks
- Custom exception classes
- Exception safety and RAII
- Nested exceptions

**CPP06 - Type Casting:**
- Static casting for implicit conversions
- Dynamic casting for polymorphic types
- Reinterpret casting for low-level operations
- Const casting (understanding its dangers)

**CPP07 - Templates:**
- Function template syntax
- Template specialization
- Class templates
- Template instantiation

**CPP08 - STL Containers:**
- Container operations and iterators
- Algorithm usage with templates
- Custom container manipulation
- Exception handling with STL

**CPP09 - Advanced STL:**
- Container selection (map, stack, deque, vector)
- Performance considerations
- Complex data structure implementation
- Algorithm optimization

## Coding Standards

All modules follow the **C++98 standard** and adhere to:
- Orthodox Canonical Form (when applicable)
- No STL usage before CPP08 (except where specified)
- No memory leaks (checked with valgrind)
- Proper error handling and edge cases
- Clean code structure and naming conventions

## Resources

**Official Documentation:**
- [cppreference.com](https://en.cppreference.com/) - Comprehensive C++ reference
- [C++ Standard (C++98)](http://www.open-std.org/jtc1/sc22/wg21/)
- [LearnCpp.com](https://www.learncpp.com/) - Detailed C++ tutorials

**Books:**
- *The C++ Programming Language* by Bjarne Stroustrup
- *Effective C++* by Scott Meyers
- *C++ Primer* by Stanley Lippman

**Exception Handling:**
- [C++ Exceptions Best Practices](https://isocpp.org/wiki/faq/exceptions)
- Understanding RAII principle

**Templates & STL:**
- [STL Tutorial](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
- [Template Metaprogramming Guide](https://www.modernescpp.com/index.php/c-core-guidelines-programming-at-compile-time-with-the-type-traits)

**AI Usage:**
AI tools were used for:
- Understanding complex template syntax and error messages
- Exploring edge cases for type casting scenarios
- Clarifying STL container performance characteristics
- Debugging template compilation errors
- Reviewing best practices for exception safety

## Notes

- Each module builds upon concepts from previous ones
- Code is designed to be educational, demonstrating specific C++ features
- Memory management is crucial - all heap allocations are properly freed
- Thoroughly tested with various inputs and edge cases

## Testing

Recommended testing approach:
```bash
# Compile with flags for debugging
c++ -Wall -Wextra -Werror -std=c++98 -g

# Memory leak detection
valgrind --leak-check=full ./program

# Additional helpful flags during development
c++ -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow
```

---

*Each module deepens understanding of C++ mechanics and prepares for modern C++ development.*
