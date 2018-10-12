#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
    private:
		typedef    std::stack<T> st;

	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(MutantStack const &ref);

		typedef typename st::container_type::iterator iterator;

		iterator	begin(void);
		iterator	end();
};

template <class T>
MutantStack<T>::MutantStack(void) {}

template <class T>
MutantStack<T>::~MutantStack(void) {}

template <class T>
MutantStack<T>::MutantStack(MutantStack<T> const &ref): st(ref) {}

template <class T>
typename MutantStack<T>::iterator        MutantStack<T>::begin(void) {
    return this->st::c.begin();
}

template <class T>
typename MutantStack<T>::iterator        MutantStack<T>::end(void) {
    return this->st::c.end();
}

#endif