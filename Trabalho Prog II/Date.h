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
        int getDay() {
            return day;
        }

        int getMonth() {
            return month;
        }

        int getYear() {
            return year;
        }

        // Método para imprimir a data formatada
        std::string toString() {
            return std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
        }

        // --- Setters ---
        void setDM(int aDay, int aMonth) {

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


        void setYear(int aYear) {

            // Validando o ano
            if (aYear < 0) {
                year = 0;
            }

            else {
                year = aYear;
            }

        }

    private:
    
        //Dados-membro
        int day;
        int month;
        int year;
};

