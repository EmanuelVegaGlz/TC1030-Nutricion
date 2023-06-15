# Clínica de Nutrición
#### Proyecto - TC1030.304
#### Profesor: Benjamín Valdés Aguirre

#### Nombre: Emanuel Josué Vega González
#### ID: A01710366

## Correcciones
#### Identifico los casos que harían que el proyecto deje de funcionar (SICT0301A)
Se encuentra en el README, en la parte de **Restriciones** (al final del README)
#### Genero un diagrama de clases UML correcto y explico su relación con el problema de forma clara (SICT0301A)
El diagrama de clases UML, esta en el archivo del repositorio llamado UML Nutri.png, de la misma forma se explica mas a detalle en la parte de **Contexto** (README)
#### Se implementa de manera correcta los modificadores de acceso (SICT0303A)
Ya se encuentre en el proyecto de pueden observar en:
  
#### Archivo *DatosPaciente.h*, líneas:

    28, 36, (102:324), 391, 450.
  
#### Archivo *menu.h*, líneas:
  
    22, 27, (75:129)
  
#### Archivo *DirectorioPacientes.h*, lineas:
  
    28, 32, (166:174)
  
#### Archivo *Nutricion.cpp*. lineas:
  
     (44:53), (59:61), 128, 145, (152:159), (217:219), (231:233),

     239, (257:251), 287, 368, (387:388), 413, 422, 431, 439, 448,
  
     450, 452, 463, 465, 474, 476
  
  
#### Se implementa de manera correcta la sobrecarga y sobreescritura de métodos (SICT0303A)

En los constructores de las clases y en los métodos de las siguientes clases se implementa **sobrecarga**:

-	Archivo *DatosPaciente.h*: Método **imprimirDieta() - imprimirDieta(int)**, 

	Encabezado: 57-58

	Declaración del Método: 344-383

	Uso:  

• *Nutricion.cpp*: 273,370
    
-	Archivo *menu.h*:	Método **getPlatillos() - getPlatillos(int)**

	Encabezado: 67-68

	Declaración del Método: 85-107

	Uso:

•	*Nutricion.cpp*: 287 ()

•	*DatosPaciente.h*: 362, 381(int)

-	Archivo *DirectorioPacientes.h*: Método **mostrarPacientes() – mostrarPacientes(int)**
-
	Encabezado: 66-67

	Declaración del Método: 84-164

	Uso:

•	*Nutricion.cpp*: 113, 121, 250 380()

•	Nutricion.cpp*:239, 391, 480(int)

**Sobreescritura:** 

-	Archivo *DatosPaciente.h*: setReqEnergia() = 0; Linea: 54

	Sobreescritura: 

•	413 – 423

•	472 - 482

-	Archivo *DatosPaciente.h*: setActFisica(int) = 0; Linea: 55
	Sobreescritura: 

•	425 – 442

•	484 - 500

## Contexto
El objetivo de este proyecto es crear un programa para una nutrióloga, el cual sirva como apoyo para su clínica de nutrición. Lo cual se soluciona haciendo un programa utilizando el paradigma orientado objetos. Se declararon 5 clases para lograr la funcionalidad del programa.

La primera clase es la clase *DatosPaciente*, la cual se define como una clase abstracta que hereda a las clases *Hombre* y *Mujer*, esto se hace porque para calcular el Requerimiento Energético Estimado (REE) y el factor de actividad física, las fórmulas predictivas (IOM) cambian de acuerdo con el sexo, es por esto que los métodos *setReqEnergia()* y *setActFisica* son declarados como virtuales y abstractos. La clase hijas únicamente tiene los atributos de la clase padre ya que ambos sexos de los pacientes requieren de los mismos atributos para que el programa funciones.

Estos atributos son los siguientes: *

-dieta[5]:*Menu (Arreglo de apuntadores de la clase Menu)

-nombre:string (Nombre del paciente)

-numero:string (Numero celular del paciente)

-correo:string (e-mail del paciente)

-objetivo:string (ejemplo: bajar de peso)

-cita:string (Proxima cita del paciente)

-peso:float 

-talla:float (estatura)

-imc:float (Indice de masa corporal)

-reqEnergia:float (REE)

-actFisica:float (Factor de Actividad Fisica)

-edad:int

-numDieta:int (Para almacenar el índice de la última posición llena que tiene el arreglo de Menu)*


Así mismo se tiene una clase *Menu*, la cual tiene como funcionalidad el instanciar objetos, que tienen como atributos una lista de 5 platillos o comidas, así como el aporte energético en calorías de la dieta. De esta clase se hace una agregación a la clase *DatosPaciente*, que se almacenan en el arreglo dieta (arreglo de apuntadores).

Finalmente hablando de las clases que conforman al programa se tiene la clase:

*DirectorioPacientes*, en esta clase se hace la agregación de *DatosPacientes* a *DirectorioPacientes*, se tiene un arreglo de apuntadores de la clase *DatosPacientes*, el cual es publico para facilitar el acceso a las funciones, sin embargo se declara como un atributo publico para poder realizar las funciones de una manera más práctica, que si bien lo ideal seria hacerlo privado, para que mediante métodos modificar el arreglo por facilidad se declara como público, cabe resaltar que cada objeto del arreglo tiene sus métodos privados, por lo que para acceder a ellos y modificarlos se utilizan métodos de acceso. **(Para mayor comprensión del proyecto se sugiere revisar el UML del proyecto)**

## Funcionalidad
El programa ocupa únicamente bibliotecas estándar.

En el main se crean 2 menús y 2 pacientes se hace la correspondiente agregación (solo son para ejemplificar).

El programa despliega instrucciones muy intuitivas, se solicitan inputs de acuerdo con la opción elegida. Al elegir una opción, se muestran los pacientes del directorio para seleccionar sobre que pacientes quiere realizar alguna acción. También se incluyen sleeps para que el despliegue de información en consola fuera más fácil de visualizar.

El programa consta de un menú principal que tiene 5 opciones:

- 1.- Ver el directorio de pacientes: En el que se muestran los pacientes agregados mediante impresiones en consolas.
- 2.- Agendarle una cita a un paciente: Se selecciona al paciente y después se ingresan los datos para la cita.
- 3.- Agregar paciente al directorio: En el que el usuario ingresa los datos de su paciente, como lo son el nombre, peso, talla, sexo, edad, objetivo, medios de contacto y la actividad física. El programa calculara el índice de masa corporal. Mediante fórmulas predictivas se calcula el Requerimiento Energético Estimado (REE), el sexo del paciente cambia la fórmula para la obtención del valor.
- 4.- Proporcionarles menús a tus pacientes: Pudiendo agregar de los menús de ejemplo o crear tus propias ideas de menús para asignarle a un paciente. **El programa no calcula las calorías de cada menú**
- 5.- Modificar/Actualizar datos de un paciente. Se selecciona un paciente y se pueden cambiar sus datos mediante setters, menos las citas que hay una (opción aparte), el REE, el IMC o el factor de actividad física, ya que lo calcula el programa, sin embargo si el usuario cambia el peso la talla o la edad se recalculan los 2 parámetro anteriores.
## Instrucciones
- Descargar los archivos y colocarlos en una misma carpeta.

**Opción 1:**

- Compilar el programa en terminal con: g++ Nutricion.cpp -o **programa** (*nombre deseado*)
- Correr el programa en consola con: **programa**.exe

**Opción 2:**

- Compilar el programa en terminal con: g++ Nutricion.cpp

- Correr el programa en consola con: a.exe

*Nota: Esto es usando el compilador g++ de MinGW en Windows.*

## Restricciones:
Al momento de ingresar lo inputs, el tipo de dato de la variable debe coincidir con la entrada, si ingresas un string o algún carácter cuando se soliciten valores numéricos el programa deja de funcionar.

De igual forma los archivos del repositorio al momento de descargarlos y descomprimirlos deben de estar en la misma carpeta, de lo contrario no compilara.

## Sugerencia
Intenta probar todas las opciones del menú, ya que dentro de las 5 opciones principales se tienen pequeñas variantes, como el hecho de crear el menú o de asignarle al paciente alguno de los creados anteriormente.

(Para salir del programa después de seleccionar por primera vez alguna de las opciones del menú ingresa un número que no esté entre 1:5)
