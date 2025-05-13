#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


// template <typename T, typename Container = std::deque<T>>
// class MutantStack : public std::stack<T, Container> {
//     private :
        

//     public :
//         class Iterator {
//             //overloading of it++, ++it , --it, it--, != , == , *, ->
//         };

//         //overloading begin() and end() that return Iterator to the begin and the end of the stack
//         /*
//         so to impliment the begin() and end() of the stack we should just return the begin and end of the underlying container that hold data for stack
//         */

// };

#include <stack>
#include <deque>
#include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // typedef Container container_type;
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    ~MutantStack() {}
    
    MutantStack& operator=(const MutantStack& other) {
        std::stack<T, Container>::operator=(other);
        return *this;
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif