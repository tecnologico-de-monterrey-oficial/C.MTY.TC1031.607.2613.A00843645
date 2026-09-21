//Daniela Chávez Ibarra
//A00843645
//#include <iostream>
#include <string>
#include "../include/Log.h"

using namespace std;

//contructores
Log::Log() {
    //valores limpios
    year = 0;
    month = "";
    day = 0;
    time = "";
    ip = "";
    message = "";
    key = "";
}
//contrsuctor con parametros
//aquí asigna los valores leídos del archivo seleccionado a los atributos internos del objeto
Log::Log(int year, string month, int day, string time, string ip, string message, string key) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    this->key = key;
}

//Generar Key
//aqui transformo el mes en texto a un num de dos digito y junta todo en formato AAAAMMDDHHMMSS
string Log::createKey() {
    string monthNum = "01";
    if (month == "Jan") monthNum = "01";
    else if (month == "Feb") monthNum = "02";
    else if (month == "Mar") monthNum = "03";
    else if (month == "Apr") monthNum = "04";
    else if (month == "May") monthNum = "05";
    else if (month == "Jun") monthNum = "06";
    else if (month == "Jul") monthNum = "07";
    else if (month == "Aug") monthNum = "08";
    else if (month == "Sep") monthNum = "09";
    else if (month == "Oct") monthNum = "10";
    else if (month == "Nov") monthNum = "11";
    else if (month == "Dec") monthNum = "12";


    //eliminar los dos puntos del tiempo
    string cleanTime = "";
    for (char c : time) {
        if (c != ':') {
            cleanTime += c;
        }
    }

    //regresar clave unida 
    return to_string(year) + monthNum + to_string(day) + cleanTime;
}

//getter
string Log::getKey() const {
    return this->key;
}

//regresar a formato original el registro 
string Log::getFormattedLog() const {
    return month + " " + to_string(day) + " " + time + " " + ip + " " + message;
}

// Implementar los operadores de comparación
bool Log::operator<(const Log &other) const {
    return this->key < other.key; // Compara si la llave de este Log es cronológicamente anterior
}

bool Log::operator>(const Log &other) const {
    return this->key > other.key; // Compara si la llave de este Log es posterior
}

bool Log::operator==(const Log &other) const {
    return this->key == other.key; // Compara si ambos logs ocurrieron exactamente en el mismo segundo
}

bool Log::operator!=(const Log &other) const {
    return this->key != other.key;
}

bool Log::operator<=(const Log &other) const {
    return this->key <= other.key;
}

bool Log::operator>=(const Log &other) const {
    return this->key >= other.key;
}