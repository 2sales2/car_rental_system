#ifndef DATE_H
#define DATE_H

#include <string>


class Date {
    
    public:

        // Construtor default
        Date(): day{0},month{0},year{0} {}

        // Construtor por parâmetro
        Date(int aDay, int aMonth, int aYear) {

            // Validando o mês
            if (aMonth < 1 || aMonth > 12) {
                month = 0;
            }

            else {
                month = aMonth;
            }

            // Validando o dia
            if (aMonth >= 1 || aMonth <= 12) {

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

            // Validando o ano
            if (aYear < 0) {
                year = 0;
            }

            else {
                year = aYear;
            }
        }

        //Construtor de cópia
        Date(const Date &aDate): day{aDate.day}, month{aDate.month}, year{aDate.year} {}
        
        // Destrutor
        ~Date() {}

        // --- Getters ---
        int getDay();
        int getMonth();
        int getYear();
        

        // Método para imprimir a data formatada
        std::string toString();

        // Método para converter uma data em dias desde 01/01/0000
        long toDays();
        
        //Método para verificar se o ano é bisexto
        bool isLeap();
        
        //Método para calcular a diferença entre duas datas
        static long days_diferrence(Date &a_date, Date &another_date);

        // --- Setters ---
        void setDM(int aDay, int aMonth);
        void setYear(int aYear);

    private:
    
        //Dados-membro
        int day;
        int month;
        int year;
};

#endif