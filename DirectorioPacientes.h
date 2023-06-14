/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 *
 * Clase Directorio Pacientes, en esta clase se hace la agregacion
 * de los pacientes.
 */

#ifndef DIRECTORIO_PACIENTES_H_
#define DIRECTORIO_PACIENTES_H_
#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
#include "DatosPaciente.h"

using namespace std;

// Declaracion de la clase DirectorioPacientes

class DirectorioPacientes{
  private:
    // Atributo de la clase
    int numPacientes;

  public:
    /* 
     * Atributo de la clase, arreglo de apuntadores de objetos de la clase
     * DatosPaciente, es publico para facilitar el acceso a los datos, sin
     * embargo, cada apuntador se modifica usando metodos de acceso. 
    */
    DatosPaciente *listaPacientes[100];

    // Metodos de la clase

    /**
     * Constructor por default
     * 
     * @param
     * @return
     */
    DirectorioPacientes():listaPacientes(),numPacientes(0){};

    /**
     * Constructor con parametros que recibe un arreglo de apuntadores de objetos
     * de la clase DatosPaciente
     * 
     * @param DatosPaciente *pacientes[100]
     * @return
     */
    DirectorioPacientes(DatosPaciente *pacientes[100]):
        numPacientes(100){
        for(int i=0;i<100;i++){
            listaPacientes[i]=pacientes[i];
        }
    }

    void agregarPaciente(DatosPaciente *);
    void mostrarPacientes();
    void mostrarPacientes(int);
    int getNumPacientes();
    void cambiarDietaPaciente(int i, Menu *dieta);
    
};

/**
 * Agrega un paciente al directorio
 * 
 * @param DatosPaciente *paciente
 * @return
 */
void DirectorioPacientes::agregarPaciente(DatosPaciente *paciente){
    listaPacientes[numPacientes]=paciente;
    numPacientes++;
}

/**
 * Muestra los pacientes del directorio
 * 
 * @param
 * @return
 */
void DirectorioPacientes::mostrarPacientes(){
    struct timespec pause;
    pause.tv_sec = 0;
    pause.tv_nsec = 300000000;
    for (int i=0;i<numPacientes;i++){
        cout << "Numero de paciente: " << i+1 << endl;
        nanosleep(&pause, NULL);
        cout << "Nombre: " << listaPacientes[i]->getNombre() << endl;
        nanosleep(&pause, NULL);
        cout << "Edad: " << listaPacientes[i]->getEdad() << endl;
        nanosleep(&pause, NULL);
        cout << "Peso: " << listaPacientes[i]->getPeso() << " kg" << endl;
        nanosleep(&pause, NULL);
        cout << "Talla: " << listaPacientes[i]->getTalla() << " m" << endl;
        nanosleep(&pause, NULL);
        cout << "IMC: " << listaPacientes[i]->getImc() << endl;
        nanosleep(&pause, NULL);
        cout << "Requerimiento energetico: ";
        nanosleep(&pause, NULL);
        cout << listaPacientes[i]->getReqEnergia() << "Kcal" << endl;
        nanosleep(&pause, NULL);
        cout << "Actividad fisica: " << listaPacientes[i]->getActFisica();
        cout<< endl;
        nanosleep(&pause, NULL);
        cout << "Numero: " << listaPacientes[i]->getNumero() << endl;
        nanosleep(&pause, NULL);
        cout << "Objetivo: " << listaPacientes[i]->getObjetivo() << endl;
        nanosleep(&pause, NULL);
        cout << "Correo: " << listaPacientes[i]->getCorreo() << endl;
        nanosleep(&pause, NULL);
        cout << "Cita: " << listaPacientes[i]->getCita() << endl << endl;
        nanosleep(&pause, NULL);
    }
}

/**
 * Muestra solo un paciente del directorio (sobrecarga)
 * 
 * @param int i
 * @return
 */
void DirectorioPacientes::mostrarPacientes(int i){
    cout << "Numero de paciente - " << i+1 << endl << endl
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
         << "Cita: " << listaPacientes[i]->getCita() << endl;
}

/**
 * getter numPacientes
 * 
 * @param
 * @return int numPacientes
 */
int DirectorioPacientes::getNumPacientes(){
    return numPacientes;
}

#endif