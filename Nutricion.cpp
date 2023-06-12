/*
 * Proyecto final TC1030.
 * Programación orientada a objetos.
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Emanuel Josué Vega González.
 * ID: A01710366.
 * 22/05/2022
 *
 * El programa está pensado para ayudar a una nutriologa en su clínica, en el
 * cual se calculen datos acerca del paciente, como su IMC, su requerimiento 
 * energético estimado, a demás de proporcionarles menús y agendar citas.
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
          cout << "Opcion invalida" << endl
               << "Ingresa el numero de la opcion que deseas realizar: "
               << endl;
          cin >> opcion;
     }
     return opcion;
}

int main(){

     // Creando objeto de la clase DirectorioPacientes
     DirectorioPacientes directorio;

     /*
      * Creando objetos de la clase Mujer y Hombre haciendo uso de 
      * polimorfismo y sobrecarca, en donde se crea un objeto vacio
      * (mediante un constructor por default) y despues se le asignan
      * valores a sus atributos mediante los modificadores de acceso.
      * El otro objeto se instancia con un constructor que recibe parametros
      * y se le asignan valores a sus atributos
      */

     // Creando objeto de la clase Mujer (constructor vacio)
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

     // Crear objeto de la clase Hombre (Constructor con parametros)
     DatosPaciente *juanito = new Hombre(70.5, 1.98, 19, "4424423451",
                                        "Juan Delgado", "Estar sano",
                                        "juanito78900@hotmail.com");

     juanito->setActFisica(2);
     juanito->setImc();
     juanito->setReqEnergia();

     // Crear un objeto de la clase Menu (ejemplo)
     Menu *menu1 = new Menu(1500, "Ensalada de pollo", "Sopa de verduras",
                              "Pescado a la plancha", "Pechuga de pollo", 
                              "Ensalada de atún");
     Menu *menu2 = new Menu(2000, "Enchiladas", "Arroz", "Mango",
                              "Frijoles charros", "Tacos al pastor");

     // Crear un arreglo de objetos de la clase Menu
     Menu * listaMenus[25];
     listaMenus[0] = menu1;
     listaMenus[1] = menu2;
     int indiceMenu = 2;

     /*
      * Agregacion de los objetos de la clase menus al objeto
      * juanita y juanito
      */
     juanita->agregaDieta(menu1);
     juanita->agregaDieta(menu2);

     // Agregar los pacientes al directorio
     directorio.agregarPaciente(juanita);
     directorio.agregarPaciente(juanito);

     // Mensaje de bienvenida
     cout << "Bienvenida Dra. al programa de nutricion" << endl
          << "En el que cuentas con un directorio de tus paciente" << endl
          << "El programa calculara el IMC y el REE de tus pacientes" << endl
          << "Tambien podras agendar citas y proporcionarles menus" << endl
          << "Ingresa el numero de la opcion que deseas realizar" << endl
          << endl
          << "1: Ver el directorio de pacientes" << endl
          << "2: Agendarle una cita a un paciente" << endl
          << "3: Agregar paciente al directorio" << endl
          << "4: Proporcionarle menus a tus pacientes" << endl << endl;
     

     int opcion;
     cin >> opcion;
     opcion = validarOpcion(opcion, 1, 5);

     while (opcion >= 1 && opcion <= 5)
     {
          switch (opcion)
          {
               case 1:{
                    // Ver el directorio de pacientes
                    directorio.mostrarPacientes();    
               
               break;
               }

               case 2:{
                    // Agendarle una cita a un paciente
                    cout << "Estos son los pacientes que tienes registrados"
                         << endl;

                    directorio.mostrarPacientes();

                    cout << "Ingresa el numero de paciente para agendar cita:"
                         << endl;

                    int num;
                    cin >> num;
                    num = validarOpcion(num, 1, directorio.getNumPacientes());

                    cout << "Ingresa la fecha de la cita" << endl;
                    string fecha;
                    getline(cin, fecha); 

                    cout << "Escribe el motivo de la cita" << endl;
                    string motivo;
                    getline(cin, motivo);

                    break;
                    
               }

               case 3:{
                    // Agregar paciente al directorio
                    cout << "Ingresa el nombre del paciente" << endl;
                    string nombre;
                    getline(cin, nombre);

                    cout << "Ingresa la edad del paciente" << endl;
                    int edad;
                    cin >> edad;

                    cout << "Ingresa el peso del paciente" << endl;
                    float peso;
                    cin >> peso;

                    cout << "Ingresa la talla del paciente" << endl;
                    float talla;
                    cin >> talla;

                    cout << "Ingresa el numero celular del paciente" << endl;
                    string numero;
                    getline(cin, numero);

                    cout << "Ingresa el e-mail del paciente" << endl;
                    string correo;
                    getline(cin, correo);

                    cout << "Ingresa el objetivo del paciente" << endl;
                    string objetivo;
                    getline(cin, objetivo);

                    cout << "Ingresa el tipo de actividad fisica del paciente"
                         << endl
                         << "1: Sedentaria" << endl
                         << "2: Poco activa" << endl
                         << "3: Activa" << endl
                         << "4: Muy activa" << endl;
                    int actFisica;
                    cin >> actFisica;
                    actFisica = validarOpcion(actFisica, 1, 4);
                    cout << "Ingresa la opcion para el sexo del paciente"
                         << endl
                         << "1: Mujer" << endl
                         << "2: Hombre" << endl;
                    int genero;
                    cin >> genero;
                    if (genero == 1)
                    {
                         DatosPaciente *paciente = new Mujer(peso,
                                                             talla,
                                                             edad,
                                                             numero,
                                                             nombre,
                                                             objetivo,
                                                             correo);
                         paciente->setActFisica(actFisica);
                         paciente->setImc();
                         paciente->setReqEnergia();
                         directorio.agregarPaciente(paciente);
                    }
                    else if (genero == 2)
                    {
                         DatosPaciente *paciente = new Hombre(peso,
                                                              talla, 
                                                              edad,
                                                              numero,
                                                              nombre,
                                                              objetivo,
                                                              correo);
                         paciente->setActFisica(actFisica);
                         paciente->setImc();
                         paciente->setReqEnergia();
                         directorio.agregarPaciente(paciente);
                    }
                    
                    break;
               }

               case 4:{
                    // Proporcionarle menus a tus pacientes
                    cout << "Estos son los pacientes que tienes registrados"
                         << endl;

                    directorio.mostrarPacientes();

                    cout << "Ingresa el numero de paciente para"
                         << " proporcionarle menus:" << endl;

                    int numPaciente;
                    cin >> numPaciente;
                    numPaciente = validarOpcion(numPaciente, 1, 
                                                directorio.getNumPacientes());

                    cout << "Estos son los menus que tienes registrados"
                         << endl;
                    
                    for (int i = 0; i < indiceMenu; i++)
                    {
                         cout << i+1 << ": " << listaMenus[i]->getPlatillos()
                              << endl << endl;
                    }

                    cout << "Desea agrear alguno de estos menus" << endl
                         << "al paciente o desea crear un menu:" << endl
                         << "1: Agregar un menu existente" << endl
                         << "2: Crear un menu" << endl;
                    
                    int opcionMenu;
                    cin >> opcionMenu;
                    opcionMenu = validarOpcion(opcionMenu, 1, 2);

                    if (opcionMenu == 1)
                    {
                         cout << "Ingresa numero del menu que deseas agregar"
                              << endl;
                         int numMenu;
                         cin >> numMenu;
                         numMenu = validarOpcion(numMenu, 1, indiceMenu);

                         directorio.listaPacientes[numPaciente-1]->
                         agregaDieta(listaMenus[numMenu-1]);
                    }
                    else if (opcionMenu == 2)
                    {
                         string platillos[5];
                         for (int i = 0; i < 5; i++)
                         {
                              cout << "Ingresa el nombre del platillo" 
                                   << endl;
                              getline(cin, platillos[i]);
                         }

                         cout << "Ingresa el numero de calorias del menu"
                              << endl;
                         float calorias;
                         cin >> calorias;

                         Menu *menu = new Menu(calorias, platillos);
                         directorio.listaPacientes[numPaciente-1]->
                         agregaDieta(menu);
                    }

                    break;
                    
               }
          }
          cout << "Que mas deseas hacer" << endl << endl
                         << "1: Ver el directorio de pacientes" << endl
                         << "2: Agendarle una cita a un paciente" << endl
                         << "3: Agregar paciente al directorio" << endl
                         << "4: Proporcionarle menus a tus pacientes" << endl
                         << "Otro numero: Salir del programa" 
                         << endl;          
                    cin >> opcion;
     }

     return 0;

};