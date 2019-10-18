// Copyright [2019] <COLOQUE SEU NOME AQUI...>
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

namespace structures {

template<typename T>
//! CLASSE PILHA
class ArrayStack {
 public:
    //! construtor simples
    ArrayStack();
    //! construtor com parametro tamanho
    explicit ArrayStack(std::size_t max);
    //! destrutor
    ~ArrayStack();
    //! metodo empilha
    void push(const T& data);
    //! metodo desempilha
    T pop();
    //! metodo retorna o topo
    T& top();
    //! metodo limpa pilha
    void clear();
    //! metodo retorna tamanho
    int size();
    //! metodo retorna capacidade maxima
    int max_size();
    //! verifica se esta vazia
    bool empty();
    //! verifica se esta cheia
    bool full();

 private:
    T* contents;
    int top_;
    int max_size_;

    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif


template<typename T>
structures::ArrayStack<T>::ArrayStack() {
    ArrayStack(DEFAULT_SIZE);
}

template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
  max_size_ = max;
  contents = new T[max_size_];
  top_ = -1;
}

template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
    delete [] contents;
}

template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
    if (full()) {
        throw std::out_of_range("pilha cheia");
    } else {
        top_ = top_+1;
        contents[top_] = data;
    }
}

template<typename T>
T structures::ArrayStack<T>::pop() {
    int temp = 0;
    if (empty()) {
        throw std::out_of_range("pilha vazia");
    } else {
        temp = top_;
        top_ = top_-1;
    }
    return contents[temp];
}

template<typename T>
T& structures::ArrayStack<T>::top() {
  return contents[top_];
}

template<typename T>
void structures::ArrayStack<T>::clear() {
    top_ = -1;
}

template<typename T>
int structures::ArrayStack<T>::size() {
    return top_+1;
}

template<typename T>
int structures::ArrayStack<T>::max_size() {
    return max_size_;
}

template<typename T>
bool structures::ArrayStack<T>::empty() {
    if((top_+1) == 0){
      return true;
    }else{
      return false;
    }
}

template<typename T>
bool structures::ArrayStack<T>::full() {
  if((top_+1) == max_size_){
    return true;
  }else{
    return false;
  }
}
