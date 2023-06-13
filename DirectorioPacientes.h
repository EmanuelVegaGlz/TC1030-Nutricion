/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 *
 * Clase Directorio Pacientes
 */

#ifndef DIRECTORIO_PACIENTES_H_
#define DIRECTORIO_PACIENTES_H_
#include <iostream>
#include <string>
#include <unistd.h>
#include "DatosPaciente.h"

using namespace std;

// Declaracion de la clase DirectorioPacientes

class DirectorioPacientes{
  private:
    int numPacientes;

  public:
    DatosPaciente *listaPacientes[100];
    DirectorioPacientes():listaPacientes(),numPacientes(0){};

    DirectorioPacientes(DatosPaciente *pacientes[100]):
        numPacientes(100){
        for(int i=0;i<100;i++){
            listaPacientes[i]=pacientes[i];
        }
    }

    void agregarPaciente(DatosPaciente *);
    void mostrarPacientes();
    void mostrarPacientes(int);
    int getNumPacientes(){return numPacientes;};
    void cambiarDietaPaciente(int i, Menu *dieta);
    
};

/**
 * Agrega un paciente al directorio
 * 
 * @param DatosPaciente *paciente
 * @return
 */
void DirectorioPacientes::agregarPaciente(DatosPaciente *paciente){
    for (int i=0;i<100;i++){
        if(listaPacientes[i] == nullptr){
            listaPacientes[i] = paciente;
            numPacientes++;
            break;
        }
    }
}

/**
 * Muestra los pacientes del directorio
 * 
 * @param
 * @return
 */
void DirectorioPacientes::mostrarPacientes(){
    for (int i=0;i<numPacientes;i++){
        cout << "Numero de paciente: " << i+1 << endl
                << "Nombre: " << listaPacientes[i]->getNombre() << endl
                << "Edad: " << listaPacientes[i]->getEdad() << endl
                << "Peso: " << listaPacientes[i]->getPeso() << " kg" << endl;
        sleep(1);
        cout << "Talla: " << listaPacientes[i]->getTalla() << " m" << endl
                << "IMC: " << listaPacientes[i]->getImc() << endl
                << "Requerimiento energetico: " 
                << listaPacientes[i]->getReqEnergia() << "Kcal" << endl
                << "Actividad fisica: " << listaPacientes[i]->getActFisica()
                << endl;
        sleep(1);
        cout << "Numero: " << listaPacientes[i]->getNumero() << endl
                << "Objetivo: " << listaPacientes[i]->getObjetivo() << endl
                << "Correo: " << listaPacientes[i]->getCorreo() << endl
                << "Cita: " << listaPacientes[i]->getCita() << endl
                << endl << endl;
        sleep(1);
    }
}

/**
 * Muestra solo un paciente del directorio (sobrecarga)
 * 
 * @param int i
 * @return
 */
void DirectorioPacientes::mostrarPacientes(int i){
    cout << "Numero de paciente: " << i+1 << endl << endl
         << "Nombre: " << listaPacientes[i]->getNombre() << endl
         << "Edad: " << listaPacientes[i]->getEdad() << endl
         << "Peso: " << listaPacientes[i]->getPeso() << " kg" << endl
         << "Talla: " << listaPacientes[i]->getTalla() << " m" <<  endl
         << "IMC: " << listaPacientes[i]->getImc() << endl
         << "Requerimiento energetico: "
         << listaPacientes[i]->getReqEnergia() << endl
         << "Actividad fisica: " << listaPacientes[i]->getActFisica() 
         << endl
         << "Numero: " << listaPacientes[i]->getNumero() << endl
         << "Objetivo: " << listaPacientes[i]->getObjetivo() << endl
         << "Correo: " << listaPacientes[i]->getCorreo() << endl
         << "Cita: " << listaPacientes[i]->getCita() << endl 
         << endl << endl;
}

/**
 * Cambia la dieta de un paciente
 * 
 * @param int i, Menu *dieta
 * @return
 */

void DirectorioPacientes::cambiarDietaPaciente(int i, Menu *dieta){
    listaPacientes[i]->agregaDieta(dieta);
}

#endif