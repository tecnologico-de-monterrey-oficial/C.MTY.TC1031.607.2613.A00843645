#ifndef cliente_h
#define cliente_h


template <typename T>
struct Cliente {
    T data; 
    //std::unique_ptr<Cliente<T>> next;
    //Cliente
    string nombre;
    int boletos;
};



#endif /*cliente_h*/