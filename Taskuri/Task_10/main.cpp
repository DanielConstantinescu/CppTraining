#include "Tesla.h"
#include "Renault.h"
#include "Vehicle.h"
#include "Utils.h"
#include "Petroleum.h"
#include <iostream>

int main() {
    /* Cazul 1: Obiect creat prin constructorul parametrizar.
      Pas 1: Este chemat constructorul parametrizat al clasei Petroleum pentru a fi creat un obiect de tip Petroleum
      Pas 2: De la obiectul Petroleum se creaza boiectul de tip Renault
      Pas 3: <prelucrari>
      Pas 4: Este chemat destructorul clasei Renault pentru a distruge obiectul de tip Renault
      Pas 5: Este chemat destructorul clasei Petroleum pentru a distruge obiectul de tip Petroleum creat la pasul 1
      
      Output:
        Petroleum(float, Fuel, Body, int, Equipment, int)
        Renault(float, Fuel, Body, int, Equipment, int)
        20
        ~Renault()
        ~Petroleum()
    */
   
   /*
    std::cout << "Cazul 1: Obiect creat prin constructorul parametrizat" << std::endl;
    Renault car1(20.0, Fuel::PETROL, Body::HATCHBACK, 1000, Equipment::BASIC, 1);
    std::cout << car1.GetFuelLevel() << std::endl;
    */

    /* Cazul 2: Obiect creat din alt obiect
    Pas 1: Este chemat constructorul parametrizat Petroleum pentru a crea un obiect de acest tip
    Pas 2: De la obiectul Petroleum se creaza obiectul car1 de tip Renault, folosind constructorul din Renault
    Pas 3: Se apeleaza, la fel ca mai sus, constructorul Petroleum si apoi cel Renault pentru a crea obiectul car2
    Pas 4: Se apeleaza copy constructorul din Renault pentru a copia car1 in car2
    pas 5: <prelucrari>
    Pas 6: Sunt chemati de cate doua ori, mai intai destructorul Renault, apoi destructorul Petroleum, pentru a distruge cele 2 obiecte
    
    Output:
        Petroleum(float, Fuel, Body, int, Equipment, int)
        Renault(float, Fuel, Body, int, Equipment, int)
        Petroleum(float, Fuel, Body, int, Equipment, int)
        Renault(float, Fuel, Body, int, Equipment, int)
        Renault(Renault &)
        20
        ~Renault()
        ~Petroleum()
        ~Renault()
        ~Petroleum()
    */
    /*
    std::cout << "Cazul 2: Obiect creat din alt obiect" << std::endl;
    Renault car1(20.0, Fuel::PETROL, Body::HATCHBACK, 1000, Equipment::BASIC, 1);
    Renault car2(car1);
    std::cout << car2.GetFuelLevel() << std::endl;
    */

    /* Cazul 3: Move assignment
    Pas 1: Este chemat constructorul parametrizat Petroleum pentru a crea un obiect de acest tip
    Pas 2: De la obiectul Petroleum se creaza obiectul car1 de tip Renault, folosind constructorul din Renault
    Pas 3: Se apeleaza, la fel ca mai sus, constructorul Petroleum si apoi cel Renault pentru a crea obiectul car2
    Pas 4: Se apeleaza copy constructorul din Renault pentru a copia car1 in car2
    Pas 5: Se face move din car1 in car2 folosind assignment
    pas 5: <prelucrari>
    Pas 6: Sunt chemati de cate doua ori, mai intai destructorul Renault, apoi destructorul Petroleum, pentru a distruge cele 2 obiecte
    
    Output:
        Petroleum(float, Fuel, Body, int, Equipment, int)
        Renault(float, Fuel, Body, int, Equipment, int)
        Petroleum(float, Fuel, Body, int, Equipment, int)
        Renault(float, Fuel, Body, int, Equipment, int)
        Renault(Renault &)
        Renault Fueling!
        Renault =(Renault &&)
        20
        ~Renault()
        ~Petroleum()
        ~Renault()
        ~Petroleum()
    */
   /*
    std::cout << "Cazul 3: Move assignment" << std::endl;
    Renault car1(20.0, Fuel::PETROL, Body::HATCHBACK, 1000, Equipment::BASIC, 1);
    Renault car2(car1);
    car2.fuelCar(200);
    car2 = std::move(car1);
    std::cout << car2.GetFuelLevel() << std::endl;
   */

    /* Cazul 4: Testare clasa Utils si metodele din ea
        Concluzie: Functia de print si calcul distanta functioneaza cum ar trebui
    */
    /*
    Renault car1(20.0, Fuel::PETROL, Body::HATCHBACK, 1000, Equipment::BASIC, 1);
    Petroleum car2 =(Petroleum)car1;

    Utils::Print(car2);
    */

    /* Cazul 5: Verificare Singleton Pattern din clasa Tesla 
    Implementare: Folosim pointerul static instancePtr din clasa Tesla si metode getInstance care returneaza acest pointer (sau il creaza in caz ca este
    prima apelare). In acest mod, folosind Singleton Design Pattern, ne aziguram ca utilizatorii nu pot apela direct constructorul (care era private).
    De asemenea, copy constructorul si operatorul de assignment copy au fost instantiate cu delete pentru a nu putea fi folosite sau implementate.

    In cazul de fata, desi am creat doua obiecte de tip Tesla unul dupa altul, se poate observa ca in terminal constructorul Tesla este apelat o singura data.
    Dupa ce obiectul car1 este sters, a doua functie de Print a lui car2 are valori diferite fata de prima, dovada ca adresa la car car2 pointa s-a modificat.
    */

    Tesla* car1 = Tesla ::getInstance();
    Tesla* car2 = Tesla ::getInstance();

    Utils::Print(static_cast<Electric>(*car2));
    std::cout << std::endl;

    delete car1;

    Utils::Print(static_cast<Electric>(*car2));

    return 0;
}