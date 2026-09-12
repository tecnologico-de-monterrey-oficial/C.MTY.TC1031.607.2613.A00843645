#ifndef Log_h
#define Log_h

class Log{
    private:
        int year;
        string month;
        int day;
        string time;
        string ip;
        string message;
        string key;

    public:
    Log();
    Log(int year, string month, int day, string time, string ip, string message, string key);
    string createkey;
    bool operator<(const Log &other) const;
    bool operator>(const Log &other) const;
    bool operator==(const Log &other) const;
    bool operator!=(const Log &other) const;
    bool operator<=(const Log &other) const;
    bool operator>=(const Log &other) const;
}
//|||||||||||||||||||||||||||||| DIFERENCIA ENTRE ESTRUCTURA Y UNA CLASE: ||||||||||||||||||||||||||||||||||
//ambas pueden tener atributos, metodos, etc
//diferencia es la manera de acceder a sus atributos 
//struct -> publicos por defecto
//class -> privados por defecto

#endif /* Log_h */