#include <string>

bool verify_license_plate(const std::string &aPlate);

class Car {

    
    friend class RentRegister;
    public:
        // Construtor default
        Car()
            : license_plate{"LLLNLNN"}, year{-1}, model{"null"}, km{-1}, availability{false},
            observations{"null"},price{0.0} {}

        // Construtor com parâmetros
        Car(std::string aPlate, int aYear, std::string aModel, int aKm, bool anAvailability,
            std::string anObservation, double aPrice)
            
            : model{aModel}, observations{anObservation}, availability{anAvailability} { 

            if(verify_license_plate(aPlate) == true){
                license_plate = aPlate ;
            }
            else
            {
                license_plate = "LLLNLNN" ;
            }

            // Validando o ano do carro (levando em conta que o primeiro carro do mundo data 1886)
            if (aYear < 1886) {
                year = -1;
            }

            else{
                year = aYear;
            }

            // Validando quilometragem
            if (aKm < 0) {
                km = -1;
            }

            else {
                km = aKm;
            }

            //Validando o preço base do carro
            if (aPrice < 0.0) {
                price = 0.0;
            }

            else {
                price = aPrice;
            }

        }

        // Construtor de cópia
        Car(const Car &aCar):
            license_plate{aCar.license_plate},year{aCar.year},model{aCar.model},
            km{aCar.km},availability{aCar.availability},observations{aCar.observations},price{aCar.price} {}
        
        // --- Getters ---
        std::string getPlate();
        int getYear();

        std::string getModel();

        int getKm();

        bool getAvailability();

        std::string getObservations();

        double getPrice();

        // --- Setters ---
        void setPlate(const std::string &aPlate);

        void setYear(int aYear);

        void setModel(std::string aModel);

        void setKm(int aKm);

        void setAvailability(bool anAvailability);

        void setObservations(std::string anObservation);

        void setPrice(double aPrice);

        //vizualizar dados como string
        std::string toString();

        // Método para atualizar kilometragem
        void updateKM(int new_km);

    private:
        //Dados-membro
        std::string license_plate;
        int year;
        std::string model;
        int km;
        bool availability;
        std::string observations;
        double price;
};


//  0  1  2  3  4  5   6
// "L  L  L  N  L  N  N"
bool verify_license_plate(const std::string &aPlate) {

    // Validando a quantidade de digitos de uma placa levando em consideração o novo padrão do Merco-Sul
    if(aPlate.length() != 7) {
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
