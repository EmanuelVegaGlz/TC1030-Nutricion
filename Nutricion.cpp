/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 * 22/05/2022
 */

/*
 * El programa está pensado para implementarse en una clínica de nutrición,
 * en el cual se calculen datos acerca del paciente, como su IMC, su
 * requerimiento energético estimado, a su vez proporcionarles menús y poder 
 * agendar citas.
 */

//Bibliotecas
#include <iostream>      // Para entradas y salidas
#include <string>        // Tipo de dato string
using namespace std;
#include "DatosPaciente.h"
#include "DirectorioPacientes.h"

// Instanciando objetos de la clase Mujer y Hombre para el avance.

int main(){

    //Ejemplos para el avance
   
    DatosPaciente *juanita = new Mujer();
    juanita->setNombre("Juana Gutierrez");
    juanita->setEdad(19);
    juanita->setPeso(50);
    juanita->setTalla(1.65);
    juanita->setImc();
    cout << "Ingresa el numero por el tipo de actividad del paciente"<<endl
         << "1: sedentaria"<<endl
         << "2: poco activa"<<endl
         << "3: activa"<<endl
         << "4: muy activa"<<endl<<endl;
    int actividad;
    cin >> actividad;
    juanita->setActFisica(actividad);
    juanita->setReqEnergia();
    juanita->setNumero("5566778899");   
    juanita->setObjetivo("Bajar de peso");
    juanita->setCorreo("juanita@gmail.com");

    // Crear objeto de la clase Hombre
     DatosPaciente *juanito = new Hombre(70.5, 1.98, 19, "4424423451", 
                                        "Juan Delgado", "Estar sano", 
                                        "juanito78900@hotmail.com");

    juanito->setActFisica(2);
    juanito->setImc();
    juanito->setReqEnergia();
    
     // Crear un objeto de la clase Menu (ejemplo).
     Menu *menu1 = new Menu(1500, "Ensalada de pollo", "Sopa de verduras",
                            "Pescado a la plancha", "Pechuga de pollo", 
                            "Ensalada de atún");
     Menu *menu2 = new Menu(2000, "Enchiladas", "Arroz", "Mango",
                            "Frijoles charros", "Tacos al pastor");

     // Agregar los menús al arreglo de menús del paciente.
     juanita->agregaDieta(menu1);
     juanita->agregaDieta(menu2);

     // Crear un objeto de la clase DirectorioPacientes (ejemplo).
     DirectorioPacientes directorio;

     // Agregar los pacientes al directorio.

     directorio.agregarPaciente(juanita);
     directorio.agregarPaciente(juanito);

     // Mostrar los pacientes del directorio.

     directorio.mostrarPacientes();

     return 0;

};
