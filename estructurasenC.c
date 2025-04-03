
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





typedef struct s_obrero  {
    int legajo;
    char nombre [30];
    char apellido [30];
    char categoria[30];
    //float sueldo;

}s_obrero ;

typedef struct nodo_obrero {

    s_obrero obrero;

    struct nodo_obrero* siguiente;
}nodo_obrero;

typedef struct s_obra{

    char codigo[20];
    char direccion [40];


}s_obra;

typedef struct s_profesional {
    int legajo;
    char nombre [30];
    char apellido [30];
    //s_obra * supervisada;
}s_profesional ;

typedef struct nodo_profesional {

    s_profesional profesional;


    struct nodo_profesional* siguiente;
}nodo_profesional;









//------------------------------------Listas-----------------------//
nodo_obrero* listaObreros = NULL;                                  //
nodo_profesional* listaProfesionales = NULL;                       //
//-----------------------------------------------------------------//



nodo_obrero * crearNodoObrero(int ,char[],char [],char[]);
nodo_profesional * crearNodoProfesional(int ,char [],char []);
void Bdd ();



int main() {



    Bdd();

    printf("\t\tBienvenido al sistema de GESTION de REPARAR S.A. \n");

    printf("\n\n \t  Coloque la opcion deseada ");


    printf("\n\n  1- Buscar");
    printf("\n\n  2- Agregar  ");
    printf("\n\n  3- Modificar ");
    printf("\n\n  4- Eliminar ");
    printf("\n\n  5- Salir ");
    printf("\n\n");


    crud();

    return 0;
}
;


void Bdd (){

//Cargamos los datos de los obreros primero con vectores para no tener usar una base de datos ni archivos de esta manera podemos hacer todo en tiempo de ejecucion

//----------------------OBREROS--------------------------------------------------------//

    int n =15,i=0;

    int legajo[]={1,3,5,6,7,8,9,10,22,33,44,55,66,77,99};
    char* nombre []={"Agustín", "Belen", "Camila", "Daniel", "Esteban", "Florencia", "Gonzalo", "Hugo", "Ivan", "Julieta","Kevin", "Laura", "Martín", "Natalia", "Oscar"};
    char* nombre2[] = {"Lucas", "Sofia", "Mariano", "Valeria", "Emiliano","Patricia", "Diego", "Veronica", "Andres", "Monica","Fernando", "Silvana", "Ricardo", "Liliana", "Javier"
};

    char* apellido []={"Gonzalez", "Rodriguez", "Perez", "Fernandez", "Lopez","Martinez", "Gomez", "Diaz", "Sanchez", "Romero","Alvarez", "Torres", "Ramirez", "Flores", "Benitez"};
    char* apellido2[] = {"Molina", "Castro", "Ortega", "Rivas", "Vega","Acosta", "Herrera", "Nunez", "Silva", "Cabrera","Franco", "Peralta", "Escobar", "Miranda", "Salinas"
};
    char* categoria[]={"oficial", "medio"," aprendiz","oficial", "medio"," aprendiz","oficial", "medio"," aprendiz","oficial", "medio"," aprendiz","oficial", "medio"," aprendiz"};



    for(i=0;i<n;i++){
        //printf("\nHola soy %s  %s mi legajo es : %d y mi categoria es %s",nombre[i],apellido[i],legajo[i],categoria[i]);
        crearNodoObrero(legajo[i],nombre [i],apellido [i],categoria [i]);
        crearNodoProfesional((legajo[i])+100,nombre2[i],apellido2[i]);
    }
};

nodo_obrero* insertar(){





};

nodo_obrero * crearNodoObrero(int legajo,char nombre [30],char apellido [30],char categoria[30]){

     nodo_obrero *nuevo = (nodo_obrero*)malloc(sizeof(nodo_obrero)); //casteo para recibir el puntero del tipo especificado// Reservamos memoria
    if (nuevo == NULL) {
        printf("Error: No hay memoria disponible.\n");
        return NULL;
    }


    // Llenamos los datos del obrero
    strcpy(nuevo->obrero.nombre, nombre);
    strcpy(nuevo->obrero.apellido, apellido);
    strcpy(nuevo->obrero.categoria, categoria);
    nuevo->obrero.legajo=legajo;


    // El nuevo nodo apunta a NULL al principio
    nuevo->siguiente = NULL;

    return nuevo;


};


nodo_profesional * crearNodoProfesional(int legajo,char nombre [30],char apellido [30]){

     nodo_profesional *nuevo = (nodo_profesional*)malloc(sizeof(nodo_profesional)); //casteo para recibir el puntero del tipo especificado// Reservamos memoria
    if (nuevo == NULL) {
        printf("Error: No hay memoria disponible.\n");
        return NULL;
    }


    // Llenamos los datos del obrero
    strcpy(nuevo->profesional.nombre, nombre);
    strcpy(nuevo->profesional.apellido, apellido);
    //nuevo->profesional.supervisada=supervisada;
    nuevo->profesional.legajo=legajo;


    // El nuevo nodo apunta a NULL al principio
    nuevo->siguiente = NULL;

    return nuevo;


};

















