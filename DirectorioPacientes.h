/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 */
/*
 * Clase Directorio Pacientes
 */

#ifndef DIRECTORIO_PACIENTES_H_
#define DIRECTORIO_PACIENTES_H_
#include <iostream>
#include <string>
#include "DatosPaciente.h"

using namespace std;

// Declaracion de la clase DirectorioPacientes

class DirectorioPacientes{
  private:
    DatosPaciente *listaPacientes[100];
    int numPacientes;

  public:
    DirectorioPacientes():listaPacientes(),numPacientes(0){};

    DirectorioPacientes(DatosPaciente *pacientes[100]):
        numPacientes(100){
        for(int i=0;i<100;i++){
            listaPacientes[i]=pacientes[i];
        }
    }

    void agregarPaciente(DatosPaciente *);
    void mostrarPacientes();
    
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
    for (int i=0;i<100;i++){
        if(listaPacientes[i] != nullptr){
            cout << "Nombre: " << listaPacientes[i]->getNombre() << endl
                 << "Edad: " << listaPacientes[i]->getEdad() << endl
                 << "Peso: " << listaPacientes[i]->getPeso() << endl
                 << "Talla: " << listaPacientes[i]->getTalla() << endl
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
    }
}

#endif