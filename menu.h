/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 * 
 * Clase Menu, sirve para instanciar objetos de tipo Menu en el programa
 * para que el usuario pueda asignarle menus a sus pacientes
 */

#ifndef MENU_H_
#define MENU_H_

#include<string>
using namespace std;

// Declaracion de la clase Menu

class Menu{
  private:
    // Atributos de la clase
    float calorias;
    string platillos[5];

  public:
    //Metodos de la clase

    /**
     * Constructor por default
     * 
     * @param
     * @return
     */
    Menu():calorias(0),platillos(){};
    
    /**
     * Constructor con parametros que recibe las calorias y los platillos
     * 
     * @param float: calorias, string: p1 desayuno, string: colacion, 
     *               string: p3 comida, string: p4 colacion, string: p5 cena
     * @return
     */
    Menu(float cal, string p1, string p2, string p3, string p4, string p5):
        calorias(cal){
        platillos[0]=p1;
        platillos[1]=p2;
        platillos[2]=p3;
        platillos[3]=p4;
        platillos[4]=p5;
    }

    /**
     * Constructor con parametros que recibe las calorias y un arrego de platillos
     * 
     * @param float: calorias, string: plat[5]
     * @return
     */
    Menu(float cal, string plat[5]):calorias(cal){
        for(int i=0;i<5;i++){
            platillos[i]=plat[i];
        }
    }
    
    float getCalorias();
    string getPlatillos();
    string getPlatillos(int i);

    void setPlatillos(string plat[5]);
    void setCalorias(float cal);
    
};

/**
 * getter calorias
 * 
 * @param
 * @return float: calorias
 */
float Menu::getCalorias(){
    return calorias;
}

/**
 * getter platillos
 * 
 * @param
 * @return string: platillos
 */
string Menu::getPlatillos(){
    string plat;
    for(int i=0;i<5;i++){
        plat+=platillos[i]+"\n";
    }
    return plat;
}

/**
 * getter platillos
 * 
 * @param int: i
 * @return string: platillo
 */
string Menu::getPlatillos(int i){
    return platillos[i];
}

/**
 * setter calorias
 * 
 * @param float: cal
 * @return
 */
void Menu::setCalorias(float cal){
    calorias=cal;
}

/**
 * setter platillos
 * 
 * @param string: plat[5]
 * @return
 */
void Menu::setPlatillos(string plat[5]){
    for(int i=0;i<5;i++){
        platillos[i]=plat[i];
    }
}

#endif