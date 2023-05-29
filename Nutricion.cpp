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

// Instanciando objetos de la clase Mujer y Hombre para el avance (ejemplos).

int main(){
    
    Mujer juanita;
    juanita.setNombre("Juana Lopez Hernandez");
    juanita.setEdad(45);
    juanita.setPeso(89.8);
    juanita.setTalla(1.45);
    juanita.setImc();
    cout << "Ingresa el numero por el tipo de actividad del paciente"<<endl
         << "1: sedentaria"<<endl
         << "2: poco activa"<<endl
         << "3: activa"<<endl
         << "4: muy activa"<<endl<<endl;
    int actividad;
    cin >> actividad;
    juanita.setActFisica(actividad);
    juanita.setReqEnergia();
    juanita.setNumero("5566778899");   
    juanita.setObjetivo("Bajar de peso");
    juanita.setCorreo("juanita@gmail.com");

    Hombre juanito(70.5, 1.98, 19, "4424423451", "Juan Delgado", "Estar sano", 
            "juanito78900@hotmail.com");
    juanito.setActFisica(2);
    juanito.setImc();
    juanito.setReqEnergia();
    
    //Datos del paciente
    cout << "Nombre: "<< juanita.getNombre()<<endl
         << "Peso (kg): " << juanita.getPeso()<<endl
         << "Estatura (m): " << juanita.getTalla()<<endl
         << "IMC: " << juanita.getImc()<<endl
         << "Req. Energetico Estimado (Kcal): " <<juanita.getReqEnergia()<<endl
         << "Actividad fisica: " << juanita.getActFisica()<<endl
         << "Edad: " << juanita.getEdad()<<endl
         << "Numero celular: " << juanita.getNumero()<<endl
         << "Objetivo del paciente: " << juanita.getObjetivo()<<endl
         << "Correo electronico: " << juanita.getCorreo()<<endl<<endl;

    cout << "Nombre: "<< juanito.getNombre()<<endl
         << "Peso (kg): " << juanito.getPeso()<<endl
         << "Estatura (m): " << juanito.getTalla()<<endl
         << "IMC: " << juanito.getImc()<<endl
         << "Req. Energetico Estimado (Kcal): " <<juanito.getReqEnergia()<<endl
         << "Actividad fisica: " << juanito.getActFisica()<<endl
         << "Edad: " << juanito.getEdad()<<endl
         << "Numero celular: " << juanito.getNumero()<<endl
         << "Objetivo del paciente: " << juanito.getObjetivo()<<endl
         << "Correo electronico: " << juanito.getCorreo()<<endl<<endl;

    return 0;
}