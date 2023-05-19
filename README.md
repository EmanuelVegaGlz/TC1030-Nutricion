# Clínica de Nutrición
#### Proyecto - TC1030.304
#### Profesor: Benjamín Valdés Aguirre

#### Nombre: Emanuel Josué Vega González
#### ID: A01710366

## Contexto y Funcionalidad

El objetivo de este proyecto es crear un programa el cual sirva como apoyo para una clínica de nutrición. En el que el usuario ingresa los datos de su paciente, como lo son el peso, talla, edad, el objetivo del paciente y medios de contacto. El programa calculara el índice de masa corporal, así como la actividad física, un factor importante a considerar es que el sexo del paciente afecta en este valor. Mediante fórmulas predictivas se calcula el Requerimiento Energético Estimado (REE), la formula cambia de acuerdo al sexo del paciente y esta en función de la actividad física, la edad, el peso y la talla. 

De la misma manera el doctor puede añadir un plan de alimentación (dieta) a cada paciente, pudiendo ser vegetariano o no. En donde se tendrán distintos objetos de la clase menú para que se adecuen a los requerimientos energéticos de cada paciente. También se tiene un directorio de pacientes en el que se agregan los objetos de la clase *Paciente* en una lista. Tiene un método para agendar citas, en el que únicamente se imprimirá en la consola el nombre del paciente y los medios de contacto.

Se tiene la clase abstracta *DatosPaciente*, que es la clase padre de: 
-	*Sedentario*
-	*PocoActivo*
-	*Activo*
-	*MuyActivo*

Ya que para hacer uso de las formulas predictivas cambia en función del tipo de actividad física, así como del IMC, se hace una sobreescritura del método *setActFisica*, ya que cambia la formula entre las clases hijas. Ya que es una composición, se mandarán a llamar a los constructores de los datos del paciente desde la clase Paciente. Solo de debe de tener un solo tipo de actividad física por paciente. Se debe de hacer uso de memoria dinámica para agregar nuevos pacientes a la lista o en su defecto crear una lista vacía que este sobrada de espacio para almacenar los pacientes. 

***Para mayor comprensión del proyecto se recomienda visualizar la imagen del UML del proyecto.***
