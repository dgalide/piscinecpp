#include <iostream>

template <class T>
class Array
{
    public:

        /**
         * Constructor / Destructor
         */
        Array(void);
        Array(unsigned int n);
        ~Array(void);
        Array(const Array<T> &ref);

        /**
         * Operator
         */
        Array<T>        &operator=(const Array<T> &ref);
        T               &operator[](unsigned int index);

        /**
         * Property
         */
        unsigned int    size;
        T               *array;
};

template <class T>
Array<T>::Array(unsigned int n) {
    this->size = n;
    if (n > 0) {
        this->array = new T[n];
    } else {
        this->array = nullptr;
    }
}

template <class T>
Array<T>::Array(void): array(nullptr), size(0) {}

template <class T>
Array<T>::Array(const Array<T> &ref) {
    T *lst = new T[ref.size];
    this->size = ref.size;

    for (unsigned int i = 0; i < ref.size;i++) {
        lst[i] = ref.array[i];
    }

    this->array = lst;
}

template <class T>
Array<T>::~Array(void) {
    if (this->array)
        delete [] this->array;
}

template <class T>
Array<T>        &Array<T>::operator=(const Array<T> &ref) {
    if (this != &ref) {
        if (this->array)
            delete [] this->array;
        this->size = ref.size;
        ref.size ? this->array = new T[ref.size] : nullptr;

        for (unsigned int i = 0;i < ref.size;i++)
            this->array[i] = ref.array[i];
    }
    return *this;
}

template <class T>
T       &Array<T>::operator[](unsigned int index) {

    if (index < this->size) {
        return this->array[index];
    } else {
        throw std::range_error("Invalid Index");
    }
}