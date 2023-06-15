/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 * 
 * Archivo de funciones, la funcion principar es validarOpcion, la demas son
 * para imprimir mensajes en pantalla y tratar de reducir el codigo en el main
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

// Bibliotecas
#include <iostream>
#include <string>
#include "DatosPaciente.h"
using namespace std;

/**
 * Funcion para validar que la opcion ingresada por el usuario
 * este dentro del rango de opciones
 * 
 * @param int: opcion a validar, int: min valor minimo permitido,
 *             int max valor maximo permitido
 * @return int: opcion validada
 */

int validarOpcion(int opcion, int min, int max){
     while(opcion < min || opcion > max)
     {
          cout << "Opcion invalida" << endl
               << "Ingresa el numero de la opcion que deseas realizar: "
               << endl;
          cin >> opcion;
     }
     return opcion;
}

/**
 * Funcion para imprimir las opciones que tiene el usuario
 * 
 * @param
 * @return
 */
void imprimirOpciones(){
     cout << "1.- Ver el directorio de pacientes" << endl
          << "2.- Agendarle una cita a un paciente" << endl
          << "3.- Agregar paciente al directorio" << endl
          << "4.- Proporcionarle menus a tus pacientes" << endl
          << "5.- Modificar/Actualizar datos de un paciente" << endl;
}

/**
 * Funcion para imprimir el mensaje de bienvenida
 * 
 * @param
 * @return
 */
void mensajeBienvenida(){
    cout << "Bienvenida Dra. al nutri programa" << endl << endl
         << "En el que cuentas con un directorio de tus paciente" << endl
         << "el programa calcula tanto IMC como REE de tus pacientes," << endl
         << "tambien podras agendar citas asi como proporcionarles menus" << endl
         << "de igual manera crear nuevos menus y agregar pacientes" 
         << endl << endl
         << "Ingresa el numero de la opcion que deseas realizar" << endl
         << endl;
}

/**
 * Funcion para las opciones de actividad fisica
 * 
 * @param
 * @return
 */
void mensajeActFisica(){
     cout << endl << "Ingresa el tipo de actividad fisica del paciente"
          << endl
          << "1: Sedentaria" << endl
          << "2: Poco activa" << endl
          << "3: Activa" << endl
          << "4: Muy activa" << endl;
}

/**
 * Funcion para imrpimir el aviso de ingresar solo numeros
 * 
 * @param
 * @return
 */
void aviso(){

     cout << "IMPORTANTE: Solo ingresar numeros: ";
}

/**
 * Funcion para imprimir las opciones del sexo del paciente para
 * intanciar un hombre o una mujer
 * 
 * @param
 * @return
 */
void mensajeGeneroPaciente(){
     cout << endl << "Ingresa la opcion para el sexo del paciente" << endl
          << "1: Mujer" << endl
          << "2: Hombre" << endl;
}

/**
 * Funcion para imprimir las opciones al agregar un menu a un paciente
 * 
 * @param
 * @return
 */
void mensajeOpcionesMenu(){
     cout << endl << "Desea agrear alguno de estos menus" << endl
          << "al paciente o desea crear un menu nuevo:" << endl
          << "1: Agregar un menu existente" << endl
          << "2: Crear un menu" << endl;
}

/**
 * Funcion para imprimir separacion entre opciones ejecutadas
 * 
 * @param
 * @return
 */
void encabezado(){
     cout << endl 
          << "_______________________________________________________________"
          << endl;
}

#endif