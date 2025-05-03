#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "song.hpp"
#include "listexception.h"
#include <iostream>
#include <string>

class List {
    private:
       Song hits[50];
       int last;

       bool isValidPos(const int&);
       void copyAll(const List&);

    public:
        //Método que inicializa la lista
        List();
        List (const List&);

        bool isEmpty();
        bool isFull();

        void insertData(const int&, const Song&); // Posicion y elemento

        void deleteData(const int&);// Posicion

        int getFirstPos();
        int getLastPos();
        int getPrevPos(const int&);
        int getNextPos(const int&);

        Song retrieve(const int&);

        std::string toString();

        void print();

        void deletAll();

        List& operator = (const List&);
    };

#endif // LIST_HPP_INCLUDED
