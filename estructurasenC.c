
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//programa de objetos con estructuras !!!
/*



Todos los empleados de la empresa, que pueden ser obreros o profesionales, acreditan: legajo (entero
sin signo, único e irrepetible), apellidos y nombres.


Los obreros, que podrán ser de oficio albañil, pintor, plomero, yesero, electricista, etc., según su
experiencia y dominio, se categorizan en oficiales, medio-oficiales y aprendices.


El haber mensual de los obreros, se calcula en base a un monto de referencia definido por el sindicato,
que se cobra al 100% en el caso de los oficiales, al 65% en los medio-oficiales, y al 25% en los aprendices.


Los profesionales, por su parte, son los responsables por la supervisión de una o más de una obra y
acreditan, además, como datos propios: el título habilitante (arquitecto, ingeniero, técnico constructor, maestro
mayor de obra, etc.), su número de matrícula (entero largo sin signo) y el nombre del consejo profesional que la
emite (Ejemplo: “Colegio de Arquitectos de la Provincia de Buenos Aires”).




Los profesionales perciben un haber mensual que surge de aplicarle al monto de referencia (sueldo
mensual de un obrero con categoría de oficial), un porcentaje propio y particular de aumento (negociado entre
ese profesional y la empresa), al que se agregará, luego, un monto fijo (de idéntico valor para todos los
profesionales), en carácter de canon universal para el pago de su matrícula, sólo si se encuentra supervisando, al
menos, una obra.



Las obras tendrán un código (alfanumérico, único e irrepetible), una dirección y, desde el momento mismo
de su registro, un profesional único designado como responsable de su supervisión que, luego y en cualquier
momento, podrá ser reemplazado por otro (también previamente registrado en la empresa).


*/

struct obrero {
int legajo;
char nombre [30];
char apellido [30];
float sueldo;
struct obra supervisada = NULL;
} ;

struct Profesional {
int legajo;
char nombre [30];
char apellido [30];
float sueldo;
} ;

struct obra{

char codigo[20];
char direccion [40];
struct profesional acargo;



};


int main() {















return 0;
}
;
