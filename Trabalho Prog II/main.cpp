#include "Agency.h"
#include "Payments.h"
#include "Car.h"
#include "RentRegister.h"
#include "Person.h"
#include "Date.h"


int main() {
    Agency agency ;
        // Inicialização de 10 objetos LegalPerson (p1 a p10)
    LegalPerson p1("Empresa A", "Rua A, 100", "11900010001", "00000000000101", 1);
    LegalPerson p2("Empresa B", "Rua B, 200", "11900010002", "00000000000102", 2);
    LegalPerson p3("Empresa C", "Rua C, 300", "11900010003", "00000000000103", 1);
    LegalPerson p4("Empresa D", "Rua D, 400", "11900010004", "00000000000104", 3);
    LegalPerson p5("Empresa E", "Rua E, 500", "11900010005", "00000000000105", 2);
    LegalPerson p6("Empresa F", "Rua F, 600", "11900010006", "00000000000106", 1);
    LegalPerson p7("Empresa G", "Rua G, 700", "11900010007", "00000000000107", 3);
    LegalPerson p8("Empresa H", "Rua H, 800", "11900010008", "00000000000108", 2);
    LegalPerson p9("Empresa I", "Rua I, 900", "11900010009", "00000000000109", 1);
    LegalPerson p10("Empresa J", "Rua J, 1000", "11900010010", "00000000000110", 3);

    // Inicialização de 10 objetos NaturalPerson (p11 a p20)
    NaturalPerson p11("João Silva", "Av. Brasil, 1", "21980001001", "11111111101", 1);
    NaturalPerson p12("Maria Souza", "Av. Brasil, 2", "21980001002", "222222222202", 2);
    NaturalPerson p13("Carlos Santos", "Av. Brasil, 3", "21980001003", "333333333-03", 1);
    NaturalPerson p14("Ana Costa", "Av. Brasil, 4", "21980001004", "44444444404", 3);
    NaturalPerson p15("Pedro Oliveira", "Av. Brasil, 5", "21980001005", "55555555505", 2);
    NaturalPerson p16("Luiza Pereira", "Av. Brasil, 6", "21980001006", "66666666606", 1);
    NaturalPerson p17("Fernando Rocha", "Av. Brasil, 7", "21980001007", "77777777707", 3);
    NaturalPerson p18("Julia Alves", "Av. Brasil, 8", "21980001008", "88888888808", 2);
    NaturalPerson p19("Rafael Lima", "Av. Brasil, 9", "21980001009", "99999999909", 1);
    NaturalPerson p20("Gabriela Castro", "Av. Brasil, 10", "21980001010", "01001001010", 3);
    
    // Inicialização de 20 objetos Car (c1 a c20)
    Car c1("ABC1A01", 2020, "Sedan", 50000, true, "Bancos de couro", 65000.00);
    Car c2("DEF2B02", 2021, "SUV", 30000, true, "Teto solar panorâmico", 120000.00);
    Car c3("GHI3C03", 2019, "Hatch", 75000, false, "Pequeno arranhão na porta", 40000.00);
    Car c4("JKL4D04", 2022, "Picape", 15000, true, "Capota marítima", 150000.00);
    Car c5("MNO5E05", 2018, "Coupé", 90000, true, "Rodas esportivas", 80000.00);
    Car c6("PQR6F06", 2023, "Minivan", 5000, true, "Multimídia avançada", 110000.00);
    Car c7("STU7G07", 2017, "Sedan", 120000, false, "Necessita troca de pneus", 35000.00);
    Car c8("VWX8H08", 2020, "SUV", 45000, true, "Câmera de ré", 105000.00);
    Car c9("YZA9I09", 2021, "Hatch", 25000, true, "Único dono", 55000.00);
    Car c10("BCD1J10", 2019, "Picape", 80000, true, "Engate para reboque", 95000.00);
    Car c11("EFG2K11", 2022, "Sedan", 10000, true, "Sensor de estacionamento", 70000.00);
    Car c12("HIJ3L12", 2018, "SUV", 60000, false, "Pequeno amassado no para-choque", 90000.00);
    Car c13("KLM4M13", 2023, "Hatch", 2000, true, "Zero km", 60000.00);
    Car c14("NOP5N14", 2017, "Coupé", 110000, true, "Revisado", 70000.00);
    Car c15("QRS6O15", 2020, "Minivan", 35000, true, "Sistema de entretenimento traseiro", 98000.00);
    Car c16("TUV7P16", 2021, "Picape", 20000, true, "Garantia de fábrica", 130000.00);
    Car c17("WXY8Q17", 2019, "Sedan", 70000, false, "Detalhes na pintura", 48000.00);
    Car c18("ZAB9R18", 2022, "SUV", 8000, true, "Versão completa", 135000.00);
    Car c19("CDE1S19", 2018, "Hatch", 95000, true, "Econômico", 38000.00);
    Car c20("FGH2T20", 2023, "Sedan", 100, true, "Novo, sem uso", 78000.00);
    
    Person* persons[] = {
    &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10,
    &p11, &p12, &p13, &p14, &p15, &p16, &p17, &p18, &p19, &p20
    };
    
    Car* cars[] = {
    &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10,
    &c11, &c12, &c13, &c14, &c15, &c16, &c17, &c18, &c19, &c20
    };

    RentRegister rr1(persons[0], cars[0], Date(10, 10, 2025), Date(1, 10, 2025), 500.0, false, 50.0, 0.0);
    RentRegister rr2(persons[1], cars[1], Date(12, 10, 2025), Date(2, 10, 2025), 650.0, true, 65.0, 0.0);
    RentRegister rr3(persons[2], cars[2], Date(15, 10, 2025), Date(3, 10, 2025), 400.0, false, 40.0, 5.0);
    RentRegister rr4(persons[3], cars[3], Date(14, 10, 2025), Date(4, 10, 2025), 800.0, true, 80.0, 0.0);
    RentRegister rr5(persons[4], cars[4], Date(16, 10, 2025), Date(5, 10, 2025), 720.0, false, 72.0, 10.0);
    RentRegister rr6(persons[5], cars[5], Date(18, 10, 2025), Date(6, 10, 2025), 550.0, true, 55.0, 0.0);
    RentRegister rr7(persons[6], cars[6], Date(19, 10, 2025), Date(7, 10, 2025), 600.0, false, 60.0, 0.0);
    RentRegister rr8(persons[7], cars[7], Date(21, 10, 2025), Date(8, 10, 2025), 780.0, true, 78.0, 15.0);
    RentRegister rr9(persons[8], cars[8], Date(23, 10, 2025), Date(9, 10, 2025), 480.0, false, 48.0, 0.0);
    RentRegister rr10(persons[9], cars[9], Date(25, 10, 2025), Date(10, 10, 2025), 900.0, true, 90.0, 0.0);
    RentRegister rr11(persons[10], cars[10], Date(26, 10, 2025), Date(11, 10, 2025), 520.0, false, 52.0, 0.0);
    RentRegister rr12(persons[11], cars[11], Date(28, 10, 2025), Date(12, 10, 2025), 680.0, true, 68.0, 8.0);
    RentRegister rr13(persons[12], cars[12], Date(30, 10, 2025), Date(13, 10, 2025), 450.0, false, 45.0, 0.0);
    RentRegister rr14(persons[13], cars[13], Date(1, 11, 2025), Date(14, 10, 2025), 850.0, true, 85.0, 0.0);
    RentRegister rr15(persons[14], cars[14], Date(3, 11, 2025), Date(15, 10, 2025), 700.0, false, 70.0, 12.0);
    RentRegister rr16(persons[15], cars[15], Date(5, 11, 2025), Date(16, 10, 2025), 580.0, true, 58.0, 0.0);
    RentRegister rr17(persons[16], cars[16], Date(7, 11, 2025), Date(17, 10, 2025), 620.0, false, 62.0, 0.0);
    RentRegister rr18(persons[17], cars[17], Date(9, 11, 2025), Date(18, 10, 2025), 820.0, true, 82.0, 20.0);
    RentRegister rr19(persons[18], cars[18], Date(11, 11, 2025), Date(19, 10, 2025), 490.0, false, 49.0, 0.0);
    RentRegister rr20(persons[19], cars[19], Date(13, 11, 2025), Date(20, 10, 2025), 950.0, true, 95.0, 0.0);

    for (int i = 0; i < 20; ++i) {
    agency.registerCustomer(persons[i]);
    }

    for (int i = 0; i < 20; ++i) {
    agency.registerCar(cars[i]);
    }


    agency.registerReg(&rr1);
    agency.registerReg(&rr2);
    agency.registerReg(&rr3);
    agency.registerReg(&rr4);
    agency.registerReg(&rr5);
    agency.registerReg(&rr6);
    agency.registerReg(&rr7);
    agency.registerReg(&rr8);
    agency.registerReg(&rr9);
    agency.registerReg(&rr10);
    agency.registerReg(&rr11);
    agency.registerReg(&rr12);
    agency.registerReg(&rr13);
    agency.registerReg(&rr14);
    agency.registerReg(&rr15);
    agency.registerReg(&rr16);
    agency.registerReg(&rr17);
    agency.registerReg(&rr18);
    agency.registerReg(&rr19);
    agency.registerReg(&rr20);

    Date start{14,10,2025} ;
    Date end{20,10,2025} ;

    std::cout << agency.reportCustomerInf("00000000000101") << std::endl ;

    return 0 ;
}




