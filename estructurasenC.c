
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
void imprimirProfesionales();
void imprimirObreros();

void crearNodoObrero(int ,char[],char [],char[]);
void crearNodoProfesional(int ,char [],char []);
void modificarEmpleado();
void Bdd ();

void crud();
void eliminarObrero();
void eliminarProfesional();
void eliminarEmpleado();
int main() {


    Bdd();
    crud();


    printf("Hasta la proxima bb <3 <3");
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


void crearNodoObrero(int legajo,char nombre [30],char apellido [30],char categoria[30]){

     nodo_obrero *nuevo = (nodo_obrero*)malloc(sizeof(nodo_obrero)); //casteo para recibir el puntero del tipo especificado// Reservamos memoria
    if (nuevo == NULL) {
        printf("Error: No hay memoria disponible.\n");
        return ;
    }


    //los datos del obrero
    strcpy(nuevo->obrero.nombre, nombre);
    strcpy(nuevo->obrero.apellido, apellido);
    strcpy(nuevo->obrero.categoria, categoria);
    nuevo->obrero.legajo=legajo;


    nuevo->siguiente = listaObreros;
    listaObreros = nuevo;




};

void crearNodoProfesional(int legajo,char nombre [30],char apellido [30]){

     nodo_profesional *nuevo = (nodo_profesional*)malloc(sizeof(nodo_profesional)); //casteo para recibir el puntero del tipo especificado// Reservamos memoria
    if (nuevo == NULL) {
        printf("Error: No hay memoria disponible.\n");
        return ;
    }


    //los datos del obrero
    strcpy(nuevo->profesional.nombre, nombre);
    strcpy(nuevo->profesional.apellido, apellido);
    //nuevo->profesional.supervisada=supervisada;
    nuevo->profesional.legajo=legajo;



    nuevo->siguiente = listaProfesionales;
    listaProfesionales = nuevo;

};



void crud(){

    int eleccion=6;

    const int gremio;
    while (eleccion){



        printf("\n\n\n\t\tBienvenido al sistema de GESTION de REPARAR S.A. \n");

        printf("\n\n \t  Coloque la opcion deseada ");


        printf("\n\n  1- Ver Empleados");
        printf("\n\n  2- Agregar  ");
        printf("\n\n  3- Modificar ");
        printf("\n\n  4- Eliminar ");
        printf("\n\n  0- Salir ");
        printf("\n\n");

        scanf("%d",&eleccion);

        if (eleccion){


            switch (eleccion){

                int selec;

            //*****************************************************************************************************************************
                case 1:
                    printf("Coloque 1 para los Obreros  o 2 para los Profesionales \n" );

                    scanf("%d",&selec);
                    printf("\n");
                        if (selec){

                            if(selec==1)

                            imprimirObreros();

                            else

                            imprimirProfesionales();


                        }

                            else
                                printf("eleccion no valida");

                        getchar();
                        getchar();


                    break;

            //*****************************************************************************************************************************
                case 2:

                    printf("Coloque 1 para los Obreros  o 2 para los Profesionales \n" );

                    scanf("%d",&selec);
                    printf("\n");


                            if(selec==1){

                             int legajo;
                             char nombre [30];
                             char apellido [30];
                             char categoria[30];



                             printf("Ingrese Legajo\n");
                             scanf("%d",&legajo);

                             printf("Ingrese Nombre\n");
                             scanf("%s",nombre);

                             printf("Ingrese Apellido\n");
                             scanf("%s",apellido);

                             printf("Ingrese Categoria\n");
                             scanf("%s",categoria);






                            crearNodoObrero(legajo,nombre,apellido,categoria);
                            }
                            else
                            {
                             int legajo;
                             char nombre [30];
                             char apellido [30];




                             printf("Ingrese Legajo\n");
                             scanf("%d",&legajo);

                             printf("Ingrese Nombre\n");
                             scanf("%s",nombre);

                             printf("Ingrese Apellido\n");
                             scanf("%s",apellido);


                            crearNodoProfesional(legajo,nombre,apellido);
                            }



                        getchar();
                        getchar();




                    break;

            //*****************************************************************************************************************************
                case 3:
                    modificarEmpleado();
                    break;

            //*****************************************************************************************************************************

                case 4:
                    eliminarEmpleado();

                    break;


             //*****************************************************************************************************************************
                case 0:
                    return;

            //*****************************************************************************************************************************


            }

        }

        }
};


void imprimirObreros() {
    nodo_obrero* actual = listaObreros;

    if (actual == NULL) {
        printf("\nNo hay obreros en la lista.\n");
        return;
    }

    printf("\n\t\t      ===== Lista de Obreros =====\n\n\n");
    while (actual != NULL) {
        printf("\t Legajo: %d | Nombre: %s %s | Categoría: %s\n  " ,
               actual->obrero.legajo,
               actual->obrero.nombre,
               actual->obrero.apellido,
               actual->obrero.categoria
               );
        actual = actual->siguiente;
    }
}



void imprimirProfesionales() {
    nodo_profesional* actual = listaProfesionales;

    if (actual == NULL) {
        printf("\nNo hay profesionales en la lista.\n");
        return;
    }

    printf("\n\t\t=====       Lista de Profesionales =====\n\n\n");
    while (actual != NULL) {
        printf("\tLegajo: %d | Nombre: %s %s\n",
               actual->profesional.legajo,
               actual->profesional.nombre,
               actual->profesional.apellido);
        actual = actual->siguiente;
    }
}


void modificarEmpleado() {
    int tipo, legajoEncontrado = 0;
    printf("\nColoque 1 para modificar Obreros o 2 para Profesionales: ");
    scanf("%d", &tipo);
    getchar(); // Limpiar el búfer

    if (tipo == 1) {
        int legajo;
        printf("\nIngrese el legajo del obrero a modificar: ");
        scanf("%d", &legajo);
        getchar();

        nodo_obrero* actual = listaObreros;
        while (actual != NULL) {
            if (actual->obrero.legajo == legajo) {
                legajoEncontrado = 1;
                printf("\nObrero encontrado: %s %s - Categoría: %s\n", actual->obrero.nombre, actual->obrero.apellido, actual->obrero.categoria);

                printf("Ingrese el nuevo nombre: ");
                fgets(actual->obrero.nombre, sizeof(actual->obrero.nombre), stdin);
                actual->obrero.nombre[strcspn(actual->obrero.nombre, "\n")] = 0;

                printf("Ingrese el nuevo apellido: ");
                fgets(actual->obrero.apellido, sizeof(actual->obrero.apellido), stdin);
                actual->obrero.apellido[strcspn(actual->obrero.apellido, "\n")] = 0;

                printf("Ingrese la nueva categoría: ");
                fgets(actual->obrero.categoria, sizeof(actual->obrero.categoria), stdin);
                actual->obrero.categoria[strcspn(actual->obrero.categoria, "\n")] = 0;

                printf("\nObrero modificado exitosamente.\n");
                break;
            }
            actual = actual->siguiente;
        }

    } else if (tipo == 2) {
        int legajo;
        printf("\nIngrese el legajo del profesional a modificar: ");
        scanf("%d", &legajo);
        getchar();

        nodo_profesional* actual = listaProfesionales;
        while (actual != NULL) {
            if (actual->profesional.legajo == legajo) {
                legajoEncontrado = 1;
                printf("\nProfesional encontrado: %s %s\n", actual->profesional.nombre, actual->profesional.apellido);

                printf("Ingrese el nuevo nombre: ");
                fgets(actual->profesional.nombre, sizeof(actual->profesional.nombre), stdin);
                actual->profesional.nombre[strcspn(actual->profesional.nombre, "\n")] = 0;

                printf("Ingrese el nuevo apellido: ");
                fgets(actual->profesional.apellido, sizeof(actual->profesional.apellido), stdin);
                actual->profesional.apellido[strcspn(actual->profesional.apellido, "\n")] = 0;

                printf("\nProfesional modificado exitosamente.\n");
                break;
            }
            actual = actual->siguiente;
        }
    } else {
        printf("\nOpción no válida.\n");
        return;
    }

    if (!legajoEncontrado) {
        printf("\nNo se encontró un empleado con ese legajo.\n");
    }

    printf("\nPresione ENTER para continuar...");
    getchar();
}

void eliminarObrero(int legajo) {
    nodo_obrero *actual = listaObreros, *anterior = NULL;

    while (actual != NULL && actual->obrero.legajo != legajo) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("\nObrero con legajo %d no encontrado.\n", legajo);
        return;
    }

    if (anterior == NULL) {
        listaObreros = actual->siguiente;  // Eliminar el primer nodo
    } else {
        anterior->siguiente = actual->siguiente;  // Eliminar nodo intermedio/final
    }

    free(actual);  // Liberar memoria
    printf("\nObrero con legajo %d eliminado.\n", legajo);
}



void eliminarProfesional(int legajo) {
    nodo_profesional *actual = listaProfesionales, *anterior = NULL;

    while (actual != NULL && actual->profesional.legajo != legajo) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("\nProfesional con legajo %d no encontrado.\n", legajo);
        return;
    }

    if (anterior == NULL) {
        listaProfesionales = actual->siguiente;  // Eliminar el primer nodo
    } else {
        anterior->siguiente = actual->siguiente;  // Eliminar nodo intermedio/final
    }

    free(actual);  // Liberar memoria
    printf("\nProfesional con legajo %d eliminado.\n", legajo);
}

void eliminarEmpleado() {
    int tipo, legajo;
    printf("\nColoque 1 para eliminar un Obrero o 2 para un Profesional: ");
    scanf("%d", &tipo);

    printf("\nIngrese el número de legajo del empleado a eliminar: ");
    scanf("%d", &legajo);

    if (tipo == 1) {
        eliminarObrero(legajo);
    } else if (tipo == 2) {
        eliminarProfesional(legajo);
    } else {
        printf("Opción no válida.\n");
    }
}
