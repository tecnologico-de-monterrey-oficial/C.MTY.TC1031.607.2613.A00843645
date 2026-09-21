//Daniela Chávez Ibarra
//A00843645
#include <string>
#include "../include/Log.h"

using namespace std;

// constructores
Log::Log() {
    year = 0;
    month = "";
    day = 0;
    time = "";
    ip = "";
    message = "";
    key = "";
}

// constructor con parámetros
Log::Log(int year, string month, int day, string time, string ip, string message, string key) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    this->key = key;
}

// Generar Key
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

    // Formatear el día a 2 dígitos (ej. 1 -> "01")
    string dayStr = (day < 10 ? "0" : "") + to_string(day);

    // eliminar los dos puntos del tiempo
    string cleanTime = "";
    for (char c : time) {
        if (c != ':') {
            cleanTime += c;
        }
    }

    // regresar clave unida con formato fijo AAAA MM DD HHMMSS
    return to_string(year) + monthNum + dayStr + cleanTime;
}

// getter
string Log::getKey() const {
    return this->key;
}

// regresar a formato original el registro 
string Log::getFormattedLog() const {
    string dayStr = (day < 10 ? "0" : "") + to_string(day);
    return month + " " + dayStr + " " + to_string(year) + " " + time + " " + ip + " " + message;
}

// Implementar los operadores de comparación
bool Log::operator<(const Log &other) const {
    return this->key < other.key;
}

bool Log::operator>(const Log &other) const {
    return this->key > other.key;
}

bool Log::operator==(const Log &other) const {
    return this->key == other.key;
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