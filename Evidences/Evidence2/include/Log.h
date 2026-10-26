#ifndef Log_h
#define Log_h

#include <string>
using namespace std;

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
    Log(); //constructor por defecto
    //constructor con parametros
    Log(int year, string month, int day, string time, string ip, string message, string key);
    string createKey(); //Generar cadena key
    string getKey() const; //para acceder
    string getFormattedLog() const; //registro completo con el formato AAAAMMDDHHMMSS
    
    //sobrecarga de operadores
    bool operator<(const Log &other) const;
    bool operator>(const Log &other) const;
    bool operator==(const Log &other) const;
    bool operator!=(const Log &other) const;
    bool operator<=(const Log &other) const;
    bool operator>=(const Log &other) const;
};
#endif /* Log_h */