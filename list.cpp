#include "list.hpp"
using namespace std;

bool List::isValidPos(const int& p) {
    return p >= 0 && p <= last + 1;
    }

void List::copyAll(const List& l) {
    last = l.last;
    for (int i = 0; i <= last; i++) {
        hits[i] = l.hits[i];
        }
    }

List::List():last(-1) { }

List::List(const List& l) {
    copyAll(l);
    }

bool List::isEmpty() {
    return last == -1;
    }

bool List::isFull() {
    return last == 49;
    }

//Insercion después del punto de interes
void List::insertData(const int& p, const Song& s) {
    if (isFull()) {
        throw ListException("Lista llena");
        }
    if (!isValidPos(p)) {
        throw ListException("Posicion invalida -> insertData");
        }
    for (int i = last; i >= p; i--) {
        hits[i + 1] = hits[i];
        }
    hits[p] = s;
    last++;
    }

void List::deleteData(const int& p) {
    if (isEmpty()) {
        throw ListException("List is empty");
        }
    if (!isValidPos(p)) {
        throw ListException("Invalid position");
        }
    for (int i = p; i < last; i++) {
        hits[i] = hits[i + 1];
        }
    last--;
    }

int List::getFirstPos() {
    if(isEmpty()) {
        return -1;
        }
    return 0;
    }

int List::getLastPos() {
    return last;
    }

int List::getPrevPos(const int& p) {
    if(p == getFirstPos() or !isValidPos(p)) {
        return -1;
        }
    return p - 1;
    }

int List::getNextPos(const int& p) {
    if(p == getLastPos() or !isValidPos(p)) {
        return -1;
        }
    return p + 1;
    }

Song List::retrieve(const int& p) {
    if (!isValidPos(p)) {
        throw ListException("Posicion invalida");
        }
    return hits[p];
    }

string List::toString() {
    string result;
    for (int i = 0; i <= last; i++) {
        result += hits[i].toString() + "\n";
        }
    return result;
    }

void List::print() {
    cout << toString();
    }

void List::deletAll() {
    last = -1;
    }

List& List::operator=(const List& l) {
    copyAll(l);
    return *this;
    }
