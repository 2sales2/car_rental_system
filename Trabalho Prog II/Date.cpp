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

