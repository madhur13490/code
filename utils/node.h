#include<iostream>

template <class T> 
class node {
    T data;
    node<T> *next;
    node<T> *prev;
};
    
