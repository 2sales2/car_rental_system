#include <string>

bool verify_license_plate(const std::string &aPlate);

class Car {

    public:
        // Construtor default
        Car(): license_plate{"LLLNLNN"}, year{-1}, model{"null"}, km{-1.0}, availability{"null"},
        observations{"null"} {}

        // Construtor com parâmetros
        Car(std::string aPlate, int aYear, std::string aModel, double aKm, std::string anAvailability,
        std::string anObservation): model{aModel}, observations{anObservation} { 

            // Validando placa do carro
            bool correct_plate = verify_license_plate(aPlate);

            if (correct_plate == true) {
                license_plate = aPlate;
            }

            else {
                license_plate = "LLLNLNN";
            }

            // Validando o ano do carro (levando em conta que o primeiro carro do mundo data 1886)
            if (aYear < 1886) {
                year = -1;
            }

            else{
                year = aYear;
            }

            // Validando quilometragem
            if (aKm < 0.0) {
                km = -1.0;
            }

            else {
                km = aKm;
            }

            // Validando disponibilidade
            if (anAvailability != "Available" || anAvailability != "Unavailable") {
                availability = "null";
            }

            else {

                if (anAvailability == "Available") {
                    availability = "Available";
                 }

                else if (anAvailability == "Unavailable") {
                    availability = "Unavailable";
                }
            }

        }

        // Construtor de cópia
        Car(const Car &aCar): license_plate{aCar.license_plate},year{aCar.year},model{aCar.model},
                              km{aCar.km},availability{aCar.availability},observations{aCar.observations} {}
        
        // --- Getters ---
        std::string getPlate() {
            return license_plate;
        }

        int getYear() {
            return year;
        }

        std::string getModel() {
            return model;
        }

        double getKm() {
            return km;
        }

        std::string getAvailability() {
            return availability;
        }

        std::string getObservations() {
            return observations;
        }

        // --- Setters ---
        void setPlate(const std::string &aPlate) {

            // Validando placa do carro
            bool correct_plate = verify_license_plate(aPlate);

            if (correct_plate == true) {
                license_plate = aPlate;
            }

            else {
                license_plate = "LLLNLNN";
            }
        }

        void setYear(int aYear) {

            // Validando o ano
            if (aYear < 1886) {
                year = -1;
            }

            else{
                year = aYear;
            }
        }

        void setModel(std::string aModel) {
            model = aModel;
        }

        void setKm(double aKm) {
            
            // Validando quilometragem
            if (aKm < 0.0) {
                km = -1.0;
            }

            else {
                km = aKm;
            }

        }

        void setAvailability(std::string anAvailability) {

            // Validando disponibilidade
            if (anAvailability != "Available" || anAvailability != "Unavailable") {
                availability = "null";
            }

            else {

                if (anAvailability == "Available") {
                    availability = "Available";
                 }

                else if (anAvailability == "Unavailable") {
                    availability = "Unavailable";
                }
            }
        }

        void setObservations(std::string anObservation) {
            observations = anObservation;
        }


    private:
        //Dados-membro
        std::string license_plate;
        int year;
        std::string model;
        double km;
        std::string availability;
        std::string observations;
};
//  0  1  2  3  4  5   6
// "L  L  L  N  L  N  N"
bool verify_license_plate(const std::string &aPlate) {

    // Validando a quantidade de digitos de uma placa levando em consideração o novo padrão do Merco-Sul
    if(aPlate.length() < 7 || aPlate.length() > 7) {
        return false;
    }

    else {

        // Verificação de digitos de uma placa levando em conta o novo padrão do Merco-Sul
        for (int i{0}; i < 7; i++) {

            // Verifica os 3 primeiros digitos
            if(i < 3) {

                if (!std::isalpha(aPlate.at(i))) {
                    return false;

                }
            }
            
            // Verifica o quarto digito
            if (i == 3) {
                if (!std::isdigit(aPlate.at(i))) {
                    return false;
                }
            }

            // Verifica o quinto digito
            if (i == 4) {
                if (!std::isalpha(aPlate.at(i))) {
                    return false;
                }
            }
            
            // Verifica os dois ultimos digitos
            if(i > 4) {

                if(!std::isdigit(aPlate.at(i))) {
                    return false;
                }

            }

        } 
    }

    return true;
    
}
