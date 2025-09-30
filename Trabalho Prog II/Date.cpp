#include "Date.h"
#include <array>

const std::array<int,12> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// --- Getters ---
int Date::getDay() {return day;}
int Date::getMonth() {return month;}
int Date::getYear() {return year;}

int Date::getDaysInMonth() {

    if (month < 1 || month > 12) {
        return 0; 
    }

    int i = month - 1;
    int max_days = months.at(i);

    if (month == 2 && isLeap()) {
        max_days = 29;
    }

    return max_days;
}


//--- Setters---
void Date::setDay(int aDay) {

    if (month < 1 || month > 12) {
        day = 0;
        return;
    }
    
    int maxDays = getDaysInMonth();
    
    if (aDay < 1 || aDay > maxDays) {
        day = 0;

    } 
    
    else {
        day = aDay;
    }
}

void Date::setMonth(int aMonth) {

    // Validando o mês
     if (aMonth < 1 || aMonth > 12) {
        month = 0;
        day = 0;

    } 
    
    else {
        month = aMonth;
        
        // se o dia atual for maior que o máximo do novo mês, ajusta
        int maxDays = getDaysInMonth();

        if (day > maxDays) {
            day = maxDays;
        }
        
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

    if (month == 2) {
        // Revalida o dia para fevereiro
        setDay(day); 
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

bool Date::isWhithinPeriod(Date &check_date,Date &start_date, Date &end_date) {
    
    long currentDays = check_date.toDays(); 
    long startDays = start_date.toDays();
    long endDays = end_date.toDays();
    
    // Verifica se a data atual está entre (ou é igual a) as datas de início e fim
    if (currentDays > 0 && startDays > 0 && endDays > 0) {
        return currentDays >= startDays && currentDays <= endDays;
    }
    
    return false;
}

