/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 * 22/05/2022
 *
 * El programa está pensado para implementarse en una clínica de nutrición,
 * en el cual se calculen datos acerca del paciente, como su IMC, su
 * requerimiento energético estimado, a su vez proporcionarles menús y poder   
 * agendar citas.
 */

//Bibliotecas

#include <iostream>                // Para entradas y salidas

#include <string>                  // Tipo de dato string

#include "DatosPaciente.h"         // Clase DatosPaciente

#include "DirectorioPacientes.h"   // Clase DirectorioPacientes

#include "menu.h"                  // Clase Menu

using namespace std;

int validarOpcion(int opcion, int min, int max){
     while(opcion < min || opcion > max)
     {
          cout << "Opcion invalida" << endl;
          cout << "Ingresa el numero de la opcion que deseas realizar: " << endl;
          cin >> opcion;
     }
     return opcion;
}

int main(){

// Creando objeto de la clase DirectorioPacientes
DirectorioPacientes directorio;

DatosPaciente *juanita = new Mujer();
juanita->setNombre("Juana Gutierrez");
juanita->setEdad(19);
juanita->setPeso(50);
juanita->setTalla(1.65);
juanita->setImc();
juanita->setActFisica(2);
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

// Agregar los pacientes al directorio.

directorio.agregarPaciente(juanita);
directorio.agregarPaciente(juanito);


cout << "Bienvenida Dra. al programa de nutricion" << endl
     << "En el que podras tener un directorio de tus paciente" << endl
     << "El programa calculara el IMC y el REE de tus pacientes" << endl
     << "Tambien podras agendar citas y proporcionarles menus" << endl;

int opcion;



cout << "Ingresa el numero de la opcion que deseas realizar" << endl << endl
     << "1: Ver el directorio de pacientes" << endl
     << "2: Agendarle una cita a un paciente" << endl
     << "3: Agregar paciente al directorio" << endl
     << "4: Proporcionarle menus a tus pacientes" << endl << endl;

cin >> opcion;

opcion = validarOpcion(opcion, 1, 5);

while (1 <= opcion <= 5)
{
     switch (opcion)
     {
          case 1:{
               directorio.mostrarPacientes();    
          
          break;
          }

          case 2:{
               cout << "Estos son los pacientes que tienes registrados"
                    << endl;
               directorio.mostrarPacientes();

               cout << "Ingresa el numero de paciente para agendar una cita" 
                    << endl;
               string nom;
               cin >> nom;
               cout << "Ingresa la fecha de la cita" << endl;
               string fecha;
               cin >> fecha;                    
               cout << "Ingresa el motivo de la cita" << endl;
               string motivo;
               cin >> motivo;
               
          }

          case 3:{
               cout << "Ingresa el nombre del paciente" << endl;
               string nombre;
               cin >> nombre;
               cout << "Ingresa la edad del paciente" << endl;
               int edad;
               cin >> edad;
               cout << "Ingresa el peso del paciente" << endl;
               float peso;
               cin >> peso;
               cout << "Ingresa la talla del paciente" << endl;
               float talla;
               cin >> talla;
               cout << "Ingresa el numero de telefono del paciente" << endl;
               string numero;
               cin >> numero;
               cout << "Ingresa el correo electronico del paciente" << endl;  
               string correo;
               cin >> correo;
               cout << "Ingresa el objetivo del paciente" << endl;
               string objetivo;
               cin >> objetivo;
               cout << "Ingresa el tipo de actividad fisica del paciente" 
                    << endl
                    << "1: Sedentaria" << endl
                    << "2: Poco activa" << endl
                    << "3: Activa" << endl
                    << "4: Muy activa" << endl;
               int actFisica;
               cin >> actFisica;
               cout << "Ingresa la opcion para el sexo del paciente"
                    << endl
                    << "1: Mujer" << endl
                    << "2: Hombre" << endl;
               int genero;
               cin >> genero;
               if (genero == 1)
               {
                    DatosPaciente *paciente = new Mujer(peso, talla, edad,
                                                        numero, nombre,
                                                        objetivo, correo);
                    paciente->setActFisica(actFisica);
                    paciente->setImc();
                    paciente->setReqEnergia();
                    directorio.agregarPaciente(paciente);
               }
               else if (genero == 2)
               {
                    DatosPaciente *paciente = new Hombre(peso, talla, edad,
                                                        numero, nombre,
                                                        objetivo, correo);
                    paciente->setActFisica(actFisica);
                    paciente->setImc();
                    paciente->setReqEnergia();
                    directorio.agregarPaciente(paciente);
               }
                 
               break;
          }
     }
     cout << "Que mas deseas hacer" << endl << endl
                    << "1: Ver el directorio de pacientes" << endl
                    << "2: Agendarle una cita a un paciente" << endl
                    << "3: Agregar paciente al directorio" << endl
                    << "4: Proporcionarle menus a tus pacientes" << endl 
                    << endl;          
               cin >> opcion;
}

return 0;

};
