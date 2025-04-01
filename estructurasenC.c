
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//programa de objetos con estructuras !!!
/*



Todos los empleados de la empresa, que pueden ser obreros o profesionales, acreditan: legajo (entero
sin signo, �nico e irrepetible), apellidos y nombres.


Los obreros, que podr�n ser de oficio alba�il, pintor, plomero, yesero, electricista, etc., seg�n su
experiencia y dominio, se categorizan en oficiales, medio-oficiales y aprendices.


El haber mensual de los obreros, se calcula en base a un monto de referencia definido por el sindicato,
que se cobra al 100% en el caso de los oficiales, al 65% en los medio-oficiales, y al 25% en los aprendices.


Los profesionales, por su parte, son los responsables por la supervisi�n de una o m�s de una obra y
acreditan, adem�s, como datos propios: el t�tulo habilitante (arquitecto, ingeniero, t�cnico constructor, maestro
mayor de obra, etc.), su n�mero de matr�cula (entero largo sin signo) y el nombre del consejo profesional que la
emite (Ejemplo: �Colegio de Arquitectos de la Provincia de Buenos Aires�).




Los profesionales perciben un haber mensual que surge de aplicarle al monto de referencia (sueldo
mensual de un obrero con categor�a de oficial), un porcentaje propio y particular de aumento (negociado entre
ese profesional y la empresa), al que se agregar�, luego, un monto fijo (de id�ntico valor para todos los
profesionales), en car�cter de canon universal para el pago de su matr�cula, s�lo si se encuentra supervisando, al
menos, una obra.



Las obras tendr�n un c�digo (alfanum�rico, �nico e irrepetible), una direcci�n y, desde el momento mismo
de su registro, un profesional �nico designado como responsable de su supervisi�n que, luego y en cualquier
momento, podr� ser reemplazado por otro (tambi�n previamente registrado en la empresa).


*/





struct obrero {
    int legajo;
    char nombre [30];
    char apellido [30];
    char categoria[30];
    //float sueldo;

} ;

struct obra{

    char codigo[20];
    char direccion [40];


};
struct Profesional {
    int legajo;
    char nombre [30];
    char apellido [30];
    //float sueldo;
    struct obra supervisada;
} ;

struct nodoProfesional {

    struct Profesional;


    struct nodo* siguiente;
};




struct nodoObrero {

    struct obrero;

    struct nodo* siguiente;
};
void Bdd ();


int main() {

    int eleccion;




    printf("\t\tBienvenido al sistema de GESTION de REPARAR S.A. \n");


    printf("\n\n \t  Coloque la opcion deseada ");


    printf("\n\n  1- Buscar");
    printf("\n\n  2- Agregar  ");
    printf("\n\n  3- Modificar ");
    printf("\n\n  4- Eliminar ");
    printf("\n\n  5- Salir ");
    printf("\n\n");

    Bdd();



    return 0;
}
;


void Bdd (){

//Cargamos los datos de los obreros primero con vectores para no tener usar una base de datos ni archivos de esta manera podemos hacer todo en tiempo de ejecucion

//----------------------OBREROS--------------------------------------------------------//

    int n =15,i=0;

    int legajo[]={1,3,5,6,7,8,9,10,22,33,44,55,66,77,99};
    char* nombre []={"Agust�n", "Belen", "Camila", "Daniel", "Esteban", "Florencia", "Gonzalo", "Hugo", "Ivan", "Julieta",
        "Kevin", "Laura", "Mart�n", "Natalia", "Oscar"};

    char* apellido []={"Gonzalez", "Rodriguez", "Perez", "Fernandez", "Lopez",
        "Martinez", "Gomez", "Diaz", "Sanchez", "Romero",
        "Alvarez", "Torres", "Ramirez", "Flores", "Benitez"};
    char* categoria[]={"oficial", "medio"," aprendiz","oficial", "medio"," aprendiz","oficial", "medio"," aprendiz",
    "oficial", "medio"," aprendiz","oficial", "medio"," aprendiz"};

    //float sueldo;


    for(i=0;i<n;i++)
        printf("\nHola soy %s  %s mi legajo es : %d y mi categoria es %s",nombre[i],apellido[i],legajo[i],categoria[i]);



};


























