#include "Date.h"
#include <array>

// --- Getters ---
int Date::getDay() {return day;}
int Date::getMonth() {return month;}
int Date::getYear() {return year;}

//--- Setters---
void Date::setDM(int aDay, int aMonth) {

    // Validando o dia
    if (aMonth >= 1 || aMonth <= 12) {
                
        month = aMonth;

        // Definindo quantidade de dias em meses que possuem 31 dias
        if(aMonth == 1 || aMonth == 3 || aMonth == 5 ||aMonth == 7 || aMonth ==8 || aMonth == 10 || month == 12) {

            if(aDay < 1 || aDay > 31) {
                day = 0;
            }

            else {
                day = aDay;
            }
                
        }
                
        // Validando quantidade de dias em fevereiro
        else if (aMonth == 2) {

            if (aDay < 1 || aDay > 28) {
                day = 0;
            }

            else {
                day = aDay;
            }

        }
                
        // Validando quantidade de dias em meses que possuem 30 dias
         else if (aMonth == 4 || aMonth == 6 || aMonth == 9 || aMonth == 11 ) {

            if (aDay < 1 || aDay > 30) {
                day = 0;
            }

            else{

                day = aDay;
            }

        }
                
            }

        else{
            month = 0;
            day = 0;

        }
    } 


    void Date::setYear(int aYear) {

        // Validando o ano
        if (aYear < 0) {
            year = 0;
        }

        else {
                year = aYear;
        }
            
}

std::string Date::toString() {
    return std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
}

bool Date::isLeap() {

    if ((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0)) {
        return true;
    }

    return false;
}

long Date::toDays() {

    long total_days = day;

    std::array<int,12> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Dias dos meses anteriores
    for (int i{0}; i < month - 1; i++) {
        total_days += months.at(i);
    }

    // Ajuste para no bissexto
    if (month > 2 && isLeap()) {
        total_days += 1;
    }

    total_days += year * 365;

    // Adicionar dias extras dos anos bissextos
    total_days += (year / 4) - (year / 100) + (year / 400);

    return total_days;

}

long Date::days_diferrence(Date &a_date, Date &another_date) {

    return (a_date.toDays() - another_date.toDays());

}