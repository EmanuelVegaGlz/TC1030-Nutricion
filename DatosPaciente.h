/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 */

/*
 * Clase abstracta DatosPaciente, que es la clase padre de Hombre y Mujer     
 */

#ifndef DATOS_PACIENTE_H_
#define DATOS_PACIENTE_H_

#include<string>
#include<math.h>
#include<iostream>
#include "menu.h"

using namespace std;

// Declaracion de la clase DatosPaciente (clase padre)

class DatosPaciente{

  protected:

    // Atributos de la clase
    float peso, talla, imc, reqEnergia, actFisica;
    int edad;
    string nombre, objetivo, correo, numero, cita;
    Menu *dieta[5];
    int numDieta;

  public:

    //Metodos de la clase
    float getPeso();
    float getTalla();
    float getImc();
    float getReqEnergia();
    float getActFisica();
    int getEdad();
    string getNumero();
    string getNombre();
    string getObjetivo();
    string getCorreo();
    string getCita();
    Menu getDieta();
    
    
    void setPeso(float);
    void setTalla(float);
    void setImc();
    virtual void setReqEnergia() = 0;
    virtual void setActFisica (int) = 0;
    void setEdad(int);
    void setNumero(string);
    void setNombre(string);
    void setObjetivo(string);
    void setCorreo(string);
    void setCita(string);
    void agregaDieta(Menu*);
    void imprimirDieta();
    void imprimirDieta(int);

    //Constructores
    
    /**
     * Constructor por default
     * Sirve para poder crear el arreglo en el directorio y poder determinar
     * la memoria necesaria. Se usaria para crear un objeto vacio y despues 
     * el doctor llenarlo con los setters.
     *
     * @param
     * @return Objeto DatosPaciente
     */

    DatosPaciente():peso(0), talla(0), imc(0), reqEnergia(0), actFisica(0),
                    edad(0), numero(""), nombre(""), objetivo(""), correo(""),
                    cita(""),dieta(),numDieta(0){};
    
    /**
     * Constructor donde recibe valores para llenar los atributos.
     *
     * @param float pes: Peso del paciente, float ta: Talla del paciente,
     * int eda: Edad del paciente, int num: Numero celular del paciente,
     * string nom: Nombre del paciente, string obj: Objetivo del paciente,
     * string corr: Correo electronico del paciente.
     * @return Objeto DatosPaciente
     */

    DatosPaciente(float pes, float ta, int eda, string num, string nom,
                    string obj, string corr):peso(pes), talla(ta),
                    imc(0), reqEnergia(0), actFisica(0), edad(eda),
                    numero(num), nombre(nom), objetivo(obj), correo(corr),
                    cita(""),dieta(),numDieta(0){};
};

//Getters

/**
 * getter peso
 *
 * @param
 * @return float: peso del paciente
*/
float DatosPaciente::getPeso(){
  return peso;
}

/**
 * getter talla
 *
 * @param
 * @return float: talla del paciente
*/
float DatosPaciente::getTalla(){
  return talla;
}

/**
 * getter imc
 *
 * @param
 * @return float: imc del paciente
*/
float DatosPaciente::getImc(){
  return imc;
}

/**
 * getter reqEnergia
 *
 * @param
 * @return float: Requerimiento estimado energético del paciente
*/
float DatosPaciente::getReqEnergia(){
  return reqEnergia;
}

/**
 * getter actFisica
 *
 * @param
 * @return float: Nivel de actividad fisica del paciente
*/
float DatosPaciente::getActFisica(){
  return actFisica;
}

/**
 * getter edad
 *
 * @param
 * @return int: Edad del paciente
*/
int DatosPaciente::getEdad(){
  return edad;
}

/**
 * getter numero
 *
 * @param
 * @return string: Numero celular del paciente
*/
string DatosPaciente::getNumero(){
  return numero;
}

/**
 * getter nombre
 *
 * @param
 * @return string: Nombre del paciente
*/
string DatosPaciente::getNombre(){
  return nombre;
}

/**
 * getter objetivo
 *
 * @param
 * @return string: Objetivo del paciente (ejemplo: "Bajar de peso")
*/
string DatosPaciente::getObjetivo(){
  return objetivo;
}

/**
 * getter correo
 *
 * @param
 * @return string: Correo electronico del paciente
*/
string DatosPaciente::getCorreo(){
  return correo;
}

/**
 * getter cita
 *
 * @param
 * @return string: Cita del paciente
*/
string DatosPaciente::getCita(){
  return cita;
}

/**
 * getter dieta
 *
 * @param
 * @return Menu: Dieta del paciente
*/
Menu DatosPaciente::getDieta(){
  return *dieta[numDieta];
}

//Setters

/**
 * setter peso
 *
 * @param float pes: peso que se le establece
 * @return
*/
void DatosPaciente::setPeso(float pes){
    peso = pes;
}

/**
 * setter talla
 *
 * @param float tall: talla que se le establece
 * @return
*/
void DatosPaciente::setTalla(float tall){
    talla = tall;
}

/**
 * setter imc
 *
 * @param
 * @return
*/
void DatosPaciente::setImc(){
    imc = peso / (pow(talla,2));
}

/**
 * setter edad
 *
 * @param
 * @return
*/
void DatosPaciente::setEdad(int ed){
    edad = ed;
}

/**
 * setter numero
 *
 * @param
 * @return
*/
void DatosPaciente::setNumero(string num){
    numero = num;
}

/**
 * setter nombre
 *
 * @param
 * @return
*/
void DatosPaciente::setNombre(string nom){
    nombre = nom;
}

/**
 * setter objetivo
 *
 * @param
 * @return
*/
void DatosPaciente::setObjetivo(string obj){
    objetivo = obj;
}

/**
 * setter correo
 *
 * @param
 * @return
*/
void DatosPaciente::setCorreo(string co){
    correo = co;
}

/**
 * setter cita
 *
 * @param
 * @return
*/
void DatosPaciente::setCita(string ci){
    cita = ci;
}

/**
 * agregar dieta
 * 
 * @param Menu: Dieta que se le agrega al paciente
 * @return
 */
void DatosPaciente::agregaDieta(Menu *d){
    dieta[numDieta] = d;
    numDieta++;
}

/**
 * imprimir dieta del paciente
 * 
 * @param
 * @return
 */
void DatosPaciente::imprimirDieta(){
    for(int i=0;i<numDieta;i++){
        cout << "Dieta " << i+1 << endl;
        cout << "Calorias: " << dieta[i]->getCalorias() << endl;
        cout << "Platillos: " << endl;
        for(int j=0;j<5;j++){
            cout << dieta[i]->getPlatillos(j) << endl;
        }
    }
}

/**
 * imprimir un platillo de la dieta del paciente
 * 
 * @param int: Platillo que se quiere imprimir de los 5 que conforma el menu
 * @return
 */
void DatosPaciente::imprimirDieta(int plat){
    for(int i=0;i<numDieta;i++){
    cout << "Dieta " << i+1 << endl;
    cout << "Calorias: " << dieta[i]->getCalorias() << endl;
    cout << "Platillo: " << plat << endl;
    cout << dieta[i]->getPlatillos(plat) << endl;
    }
}

/**
 * Clase Mujer, que es la clase hija de DatosPaciente     
 */

class Mujer : public DatosPaciente{

  public:

    /**
    * Constructor por default
    *
    * @param
    * @return Objeto Sedan
    */
    Mujer():DatosPaciente(){}

    /**
    * Constructor donde recibe valores para llenar los atributos
    *
    * @param float pes: Peso del paciente, float ta: Talla del paciente,
    * int eda: Edad del paciente, int num: Numero celular del paciente,
    * string nom: Nombre del paciente, string obj: Objetivo del paciente,
    * string corr: Correo electronico del paciente.
    * @return Objeto DatosPaciente
    */
    Mujer(float pes, float ta, int eda, string num, string nom, string obj, 
           string corr):DatosPaciente(pes, ta, eda, num, nom, obj, corr){};
    
    /**
    * setter reqEnergia
    *
    * @param
    * @return
    */
    void setReqEnergia(){
        reqEnergia = 354-(6.91*edad)+(actFisica*(9.36*peso+726*talla));
    }

    /**
    * setter actFisica
    *
    * @param
    * @return
    */
    void setActFisica(int act){
        if(act == 1)
        actFisica = 1;
        if(act == 2)
        actFisica = 1.12;
        if(act == 3)
        actFisica = 1.27;
        if(act == 4)
        actFisica = 1.45;
    }
};  

/**
 * Clase Hombre, que es la clase hija de DatosPaciente     
 */

class Hombre: public DatosPaciente{

  public:

    /**
    * Constructor por default
    *
    * @param
    * @return
    */
    Hombre():DatosPaciente(){}

    /**
    * Constructor donde recibe valores para llenar los atributos
    *
    * @param float pes: Peso del paciente, float ta: Talla del paciente,
    * int eda: Edad del paciente, int num: Numero celular del paciente,
    * string nom: Nombre del paciente, string obj: Objetivo del paciente,
    * string corr: Correo electronico del paciente.
    * @return Objeto DatosPaciente
    */
    Hombre(float pes, float ta, int eda, string num, string nom, string obj, 
            string corr):DatosPaciente(pes, ta, eda, num, nom, obj, corr){};
    
    /**
    * setter reqEnergia
    *
    * @param
    * @return
    */
    void setReqEnergia()override{
        reqEnergia = 662-(9.53*edad)+(actFisica*(15.91*peso+539*talla));
    }

    /**
    * setter actFisica
    *
    * @param
    * @return
    */
    void setActFisica(int act)override{
        if(act == 1)
        actFisica = 1;
        if(act == 2)
        actFisica = 1.11;
        if(act == 3)
        actFisica = 1.25;
        if(act == 4)
        actFisica = 1.48;
    }
};

#endif