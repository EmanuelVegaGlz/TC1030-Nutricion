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
 * Adicional a que puedes actualizar o modificar los datos del paciente.
 */

//Bibliotecas
#include <iostream>               // Para entradas y salidas
#include <string>                  // Tipo de dato string
#include <sstream>                 // Para cadenas de strings
#include <unistd.h>                // Para funciones con el SO (sleep)
#include <time.h>                  // Para tiempo (nanosleep)
#include "DatosPaciente.h"         // Clase DatosPaciente
#include "DirectorioPacientes.h"   // Clase DirectorioPacientes
#include "menu.h"                  // Clase Menu
#include "funciones.h"             // Archivo de funciones

using namespace std;

int main(){

     // Creando objeto de la clase DirectorioPacientes
     DirectorioPacientes directorio;

     /*
      * Creando objetos de la clase Mujer y Hombre haciendo uso de 
      * polimorfismo y sobrecarga, en donde se crea un objeto vacio
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

     // Crear objetos de la clase Menu (ideas de dietas)
     Menu *menu1 = new Menu(1500, 
                            "Desayuno: Licuado de fresa y huevos revueltos",
                            "Colacion: Manzana",
                            "Comida: Sopa de verduras, filete de pescado",
                            "Colacion: Amaranto", 
                            "Cena: Hot cakes de avenas");

     Menu *menu2 = new Menu(2000, 
                            "Desayuno: Jugo de naranja y sandwich de jamon",
                            "Colacion: Uvas y nueces de la india",
                            "Comida: Arroz, pollo a la plancha y ensalada",
                            "Colacion: Palomitas de maiz caseras", 
                            "Cena: Tostadas horneadas con aguacate y queso");


     // Arreglo de objetos de la clase Menu para asignarle a los pacientes
     Menu * listaMenus[25];
     listaMenus[0] = menu1;
     listaMenus[1] = menu2;
     int indiceMenu = 1;

     /*
      * Agregacion de los objetos de la clase menus al objeto
      * juanita y juanito
      */
     juanita->agregaDieta(menu1);
     juanito->agregaDieta(menu2);

     // Agregar los pacientes al directorio
     directorio.agregarPaciente(juanita);
     directorio.agregarPaciente(juanito);

     // Mensaje de bienvenida y opciones que tiene el usuario
     encabezado();
     mensajeBienvenida();
     imprimirOpciones();
     aviso();
     
     int opcion;
     cin >> opcion;
     opcion = validarOpcion(opcion, 1, 5);

     while (opcion >= 1 && opcion < 6)
     {
          encabezado();
          switch(opcion)
          {
               case 1:{
                    // Ver el directorio de pacientes
                    directorio.mostrarPacientes();
               break;}

               case 2:{
                    // Agendarle una cita a un paciente
                    cout << "Estos son los pacientes que tienes registrados"
                         << endl;
                    sleep(1);
                    directorio.mostrarPacientes();

                    cout << "Ingresa el numero de paciente para agendar cita:"
                         << endl;
                    aviso();
                    int num;
                    cin >> num;
                    num = validarOpcion(num, 1, directorio.getNumPacientes());

                    cout << "Ingresa la fecha de la cita: ";
                    string fecha;
                    getline(cin >> ws, fecha);

                    cout << "Escribe el motivo de la cita: ";
                    string motivo;
                    getline(cin >> ws, motivo);

                    stringstream aux;
                    aux << "Cita:" << endl << endl
                        << "Fecha: " << fecha << endl
                        << "Motivo: " << motivo << endl;
                    
                    
                    string cita = aux.str();
                    directorio.listaPacientes[num-1]->setCita(cita);

                    cout << "Cita agendada exitosamente" << endl;
                    sleep(1);
                    cout << "Este es el resumen de su cita: " << endl << endl;
                    sleep(1);
                    cout << "Paciente: " 
                         << directorio.listaPacientes[num-1]->getNombre() 
                         << endl
                         << directorio.listaPacientes[num-1]->getCita()
                         << endl
                         << "Contacto: " << endl << "Celular: "
                         << directorio.listaPacientes[num-1]->getNumero()
                         << endl << "Correo: "
                         << directorio.listaPacientes[num-1]->getCorreo()
                         << endl;
                    encabezado();
                    sleep(1);
               break;}

               case 3:{
                    // Agregar paciente al directorio
                    cout << "Ingresa el nombre del paciente: ";
                    string nombre;
                    getline(cin >> ws, nombre);

                    cout << "Ingresa la edad del paciente" << endl;
                    aviso();
                    int edad;
                    cin >> edad;

                    cout << "Ingresa el peso del paciente en kg" << endl;
                    aviso();
                    float peso;
                    cin >> peso;

                    cout << "Ingresa la talla del paciente en m" << endl;
                    aviso();
                    float talla;
                    cin >> talla;

                    cout << "Ingresa el numero celular del paciente: ";
                    string numero;
                    getline(cin >> ws, numero);

                    cout << "Ingresa el e-mail del paciente: ";
                    string correo;
                    fflush(stdin); // Limpiar el buffer (Me lo recomendo Karen :D)
                    getline(cin >> ws, correo);

                    cout << "Ingresa el objetivo del paciente: ";
                    string objetivo;
                    getline(cin >> ws, objetivo);
                    mensajeActFisica();
                    aviso();
                    int actFisica;
                    cin >> actFisica;
                    actFisica = validarOpcion(actFisica, 1, 4);

                    mensajeGeneroPaciente();
                    aviso();
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
                    
                    cout << endl << "Paciente agregado exitosamente" << endl
                         << "Resumen del paciente agregado:" << endl << endl;
                    directorio.mostrarPacientes(directorio.getNumPacientes()
                                                -1);
                    encabezado();
               break;}

               case 4:{
                    // Proporcionarle menus a tus pacientes
                    cout << "Estos son los pacientes que tienes registrados"
                         << endl;
                    sleep(1);

                    directorio.mostrarPacientes();

                    cout << "Ingresa el numero de paciente para" << endl
                         << "proporcionarle menus:" << endl;

                    int numPaciente;
                    cin >> numPaciente;
                    numPaciente = validarOpcion(numPaciente, 1, 
                                                directorio.getNumPacientes());
                    
                    if(directorio.listaPacientes[numPaciente-1]->
                       getNumDieta() == 0)
                    {
                         encabezado();
                         cout << "El paciente no tiene menus aun" << endl;
                         encabezado();
                    }
                    else
                    {
                         encabezado();
                         cout << "El paciente ya tiene los siguientes menus:"
                              << endl;
                         directorio.listaPacientes[numPaciente-1]->
                         imprimirDieta();
                         encabezado();
                    }

                    cout << "Cuenta con los siguientes menus para asignar:"
                         << endl << endl;
                    sleep(1);
                    struct timespec pause;
                    pause.tv_sec = 0;
                    pause.tv_nsec = 300000000;
                    for (int i = 0; i <= indiceMenu; i++)
                    {
                         cout << i+1 << ".- "<<endl;
                         nanosleep(&pause, NULL); 
                         cout << listaMenus[i]->getPlatillos()
                              << endl;
                         nanosleep(&pause, NULL);
                    }
                    encabezado();

                    mensajeOpcionesMenu();                    
                    int opcionMenu;
                    cin >> opcionMenu;
                    opcionMenu = validarOpcion(opcionMenu, 1, 2);

                    if (opcionMenu == 1)
                    {
                         cout << "Ingresa numero del menu que deseas agregar:"
                              << endl;
                         int numMenu;
                         cin >> numMenu;
                         numMenu = validarOpcion(numMenu, 1, indiceMenu +1);

                         directorio.listaPacientes[numPaciente-1]->
                         agregaDieta(listaMenus[numMenu-1]);
                    }
                    else if (opcionMenu == 2)
                    {
                         string platillos[5];
                         for (int i = 0; i < 5; i++)
                         {
                              switch (i)
                              {
                                   case 0:{
                                        cout << "Ingresa el desayuno" << endl;
                                        string des;
                                        getline(cin >> ws, des);
                                        platillos[i] = "Desayuno: " + des;
                                   break;}

                                   case 1:{
                                        cout << "Ingresa la colacion" << endl;
                                        string col;
                                        getline(cin >> ws, col);
                                        platillos[i] = "Colacion: " + col;
                                   break;}

                                   case 2:{
                                        cout << "Ingresa la comida" << endl;
                                        string com;
                                        getline(cin >> ws, com);
                                        platillos[i] = "Comida: " + com;
                                   
                                   break;}

                                   case 3:{
                                        cout << "Ingresa la colacion" << endl;
                                        string col;
                                        getline(cin >> ws, col);
                                        platillos[i] = "Colacion: " + col;
                                   break;}

                                   case 4:{
                                        cout << "Ingresa la cena" << endl;
                                        string cen;
                                        getline(cin >> ws, cen);
                                        platillos[i] = "Cena: " + cen;
                                   break;}
                              }
                         }

                         cout << "Ingresa el numero de calorias del menu"
                              << endl;
                         float calorias;
                         cin >> calorias;

                         Menu *menu = new Menu(calorias, platillos);
                         directorio.listaPacientes[numPaciente-1]->
                         agregaDieta(menu);
                         listaMenus[indiceMenu+1] = menu;
                         indiceMenu++;
                    }

                    cout << "Menu agregado exitosamente" << endl
                         << "Su paciente " <<
                         directorio.listaPacientes[numPaciente-1]->getNombre()
                         << " cuenta con el siguiente menu: " << endl;
                    directorio.listaPacientes[numPaciente-1]->imprimirDieta();
                    cout << endl;
                         
               break;}

               case 5:{
                    // Modificar/Actualizar datos de un paciente
                    cout << "Estos son los pacientes que tienes registrados"
                         << endl;
                    sleep(1);
                    directorio.mostrarPacientes();

                    cout << "Ingresa el numero de paciente para modificar"
                         << endl;

                    int numPaciente;
                    cin >> numPaciente;
                    numPaciente = validarOpcion(numPaciente, 1, 
                                                directorio.getNumPacientes());
                    
                    cout << "Estos son los datos del paciente: " << endl;
                    directorio.mostrarPacientes(numPaciente-1);

                    cout << "Que datos deseas modificar" << endl
                         << " 1.- nombre" << endl
                         << " 2.- numero" << endl
                         << " 3.- correo" << endl
                         << " 4.- objetivo" << endl
                         << " 5.- peso" << endl
                         << " 6.- talla" << endl
                         << " 7.- edad" << endl;
                    aviso();
                    int opcionMod;
                    cin >> opcionMod;
                    opcionMod = validarOpcion(opcionMod, 1, 7);

                    switch (opcionMod)
                    {
                    case 1:{
                         cout << "Ingresa el nuevo nombre" << endl;
                         string nom;
                         getline(cin >> ws, nom);
                         directorio.listaPacientes[numPaciente-1]->
                         setNombre(nom);
                         break;}

                    case 2:{
                         cout << "Ingresa el nuevo numero" << endl;
                         string num;
                         cin >> num;
                         getline(cin >> ws, num);
                         directorio.listaPacientes[numPaciente-1]->
                         setNumero(num);
                         break;}

                    case 3:{
                         cout << "Ingresa el nuevo correo" << endl;
                         string cor;
                         cin >> cor;
                         getline(cin >> ws, cor);
                         directorio.listaPacientes[numPaciente-1]->
                         setCorreo(cor);
                         break;}
                    
                    case 4:{
                         cout << "Ingresa el nuevo objetivo" << endl;
                         string obj;
                         getline(cin >> ws, obj);
                         directorio.listaPacientes[numPaciente-1]->
                         setObjetivo(obj);
                         break;}
                    
                    case 5:{
                         cout << "Ingresa el nuevo peso" << endl;
                         aviso();
                         float pes;
                         cin >> pes;
                         directorio.listaPacientes[numPaciente-1]->
                         setPeso(pes);
                         directorio.listaPacientes[numPaciente-1]->
                         setImc();
                         directorio.listaPacientes[numPaciente-1]->
                         setReqEnergia();
                         break;}
                    
                    case 6:{
                         cout << "Ingresa la nueva talla" << endl;
                         aviso();
                         float tal;
                         cin >> tal;
                         directorio.listaPacientes[numPaciente-1]->
                         setTalla(tal);
                         directorio.listaPacientes[numPaciente-1]->
                         setImc();
                         directorio.listaPacientes[numPaciente-1]->
                         setReqEnergia();
                         break;}

                    case 7:{
                         cout << "Ingresa la nueva edad" << endl;
                         aviso();
                         int eda;
                         cin >> eda;
                         directorio.listaPacientes[numPaciente-1]->
                         setEdad(eda);
                         directorio.listaPacientes[numPaciente-1]->
                         setReqEnergia();
                         break;}
                    }
                    cout << "Estos son los datos del paciente actualizados: " << endl;
                    directorio.mostrarPacientes(numPaciente-1);
                    encabezado();
               break;}
          }
          sleep(1);
          cout << "Que mas deseas hacer" << endl << endl;
          imprimirOpciones();
          cout << "Otro numero -> Salir del programa" << endl;
          aviso();          
          cin >> opcion;
     }
     return 0;
};