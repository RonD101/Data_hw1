//
// Created by Ron Dahan on 20/06/2020.
//

#ifndef HW3PARTB_TEMARRAY_H
#define HW3PARTB_TEMARRAY_H

#include <iostream>
//#include "Auxiliaries.h"
#include <string>

/**
* Template Array
*
* Implements a generic typed array.
* with an Exception class of BadAccess
*
* The following functions are available:
*   the big three - constructor , destructor and copy constructor.
*   size		- Return the size of the array.
*
* The following operators are available:
*   operator=      - Assignment of one matrix to the other
*   operator[]      - Return reference to value
*/


    template<class T>
    class TemArray {
        T *data;
        int length;
    public:
        class BadAccess;

/**
*	Constructor: create a new Template Array
*
* @param
* size - The Initial size of the Array(optional)
* @return
* 	The new Array
* @assumption
*   There is a default constructor for class T.
*/
        explicit TemArray(int size = 10);

/**
*	Copy Constructor: create a copy Array
*
* @param
* TemArray - The template Array which we copy the values from.
* @return
* 	The copied Array
* @assumption
*   There is a default constructor for class T.
*   There is a '=' operator implement for class T.
*/
        TemArray(const TemArray<T> &a);

/**
*    Destructor: Destroy the Template Array when her 'life' end.
*
* @return
* 	No Return Value.
* @assumption
*   There is a default destructor for class T.
*/
        ~TemArray();

/**
*	operator=: assign template array
*
* @param
* TemArray - The template array which we copy the values from.
* @return
* 	The assigned array
* @assumption
*   There is a default constructor for class T.
*   There is a default destructor for class T.
*   There is a '=' operator implement for class T.
*/
        TemArray &operator=(const TemArray<T> &a);

/**
*	size: Returns the amount of element in array.
*
* @return
* 	Amount of elements
*/
        int size() const;

/**
*	operator[]: Return element from Template Array
*
* @param
* index - The index of the element
* @return
* 	Reference to the element
* @exception
*   Return BadAccess for invalid read of memory.
*/
        T &operator[](int index);

/**
*	operator[]: Return a const element from Array
*
* @param
* index - The index of the element
* @return
* 	Reference to the const element
* @exception
*   Return BadAccess for invalid read of memory.
*/
        const T &operator[](int index) const;
    };

    template<class T>
    TemArray<T>::TemArray(int size) {
        data = new T[size];
        length = size;
    }

    template<class T>
    TemArray<T>::TemArray(const TemArray<T> &a) {
        data = new T[a.size()];
        length = a.size();
        for (int i = 0; i < a.size(); ++i) {
            data[i] = a[i];
        }
    }

    template<class T>
    TemArray<T>::~TemArray() {
        delete[] data;
    }

    template<class T>
    TemArray<T>& TemArray<T>::operator=(const TemArray<T> &a) {
        if (this == &a) {
            return *this;
        }
        T *temp_array = new T[a.size()];
        delete[] data;
        for (int i = 0; i < a.size(); ++i) {
            try {
                temp_array[i] = a[i];
            }
            catch (const std::exception &e) {
                delete[] temp_array;
                throw e;
            }
        }
        data = temp_array;
        length = a.size();
        return *this;
    }

    template<class T>
    int TemArray<T>::size() const {
        return length;
    }

    template<class T>
    T &TemArray<T>::operator[](int index) {
        if (index < 0 || index >= this->size()) {
            throw TemArray::BadAccess();
        }
        return data[index];
    }

    template<class T>
    const T &TemArray<T>::operator[](int index) const {
        if (index < 0 || index >= this->size()) {
            throw TemArray::BadAccess();
        }
        return data[index];
    }


/**
* Exception Bad Access
*
* Implements of an exception class indicating a bad access to memory,
* which Inherit from std::exception.
*
* The following functions are available:
*   the big three - constructor , destructor and copy constructor(default).
*   what		- Return info on the exception.
*/
    template <class T>
    class TemArray<T>::BadAccess : public std::exception {
    public:
        const char* what() const noexcept override
        {
            return "Bad Access";
        }
    };


#endif //HW3PARTB_TEMARRAY_H
