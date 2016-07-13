#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include "Radio.h"


void menu (Radio *estacion_de_radio);
void controlDeUsuarios(Radio *estacion_de_radio);

int main ()
{
    //INSTANCIAR RADIO QUE CONTIENE TODAS LAS ESTRUCTURAS
	Radio mi_estacion_de_radio;
	//CARGAR LA LISTA CON LOS REGISTROS DEL ARCHIVO
	//cargarListaLocutores(&mi_estacion_de_radio);
	iniciarListas(&mi_estacion_de_radio);
	menu(&mi_estacion_de_radio);
	pausar();
	return 0;
}

// MENU
void menu (Radio *estacion_de_radio){
    int op;

    do{
    system("cls");
    textcolor(WHITE);
    printf("[1] Gestion de clientes para la publicidad \n");
    printf("[2] Gestion de usuarios de la radio\n");
    printf("[3] Gestion de planes de las publicidades \n");
    printf("[4] Listado de clientes \n");
    printf("[5] Salir \n");
    textcolor(YELLOW);
    printf("Ingrese la opcion: ");
    textcolor(WHITE);scanf("%i",&op);

    switch(op){
        case 1: break;
        case 2: controlDeUsuarios(estacion_de_radio); break;
        case 3: break;
        case 4: break;
        case 5: eliminarListaLocutor(estacion_de_radio);
				free(estacion_de_radio->lista_de_locutores);
        		exit(1);
        default : mensajePorDefecto();
    }
    }while(op!=5);
}

void controlDeUsuarios(Radio *estacion_de_radio)
{
    int op;
    do{
    system("cls");
    textcolor(WHITE);
    printf("[1] Registro de locutores \n");
    printf("[2] Registro de secretaria \n");
    printf("[3] Modificar registro de locutor \n");
    printf("[4] Modificar registro de secretaria \n");
    printf("[5] Mostrar listado de locutores \n");
    printf("[6] Mostrar listado de secretarias \n");
    printf("[7] Mostrar due%co \n",164);
    printf("[8] Menu principal \n");
    textcolor(YELLOW);
    printf("Ingrese la opcion:");
    textcolor(WHITE);scanf("%i",&op);

    switch(op){
        case 1: registroLocutor(estacion_de_radio); break;
        case 2: registroSecretaria(estacion_de_radio);break;
        case 3: modificarRegistroLocutor(estacion_de_radio); break;
        case 4: break;
        case 5: mostrarListaDeLocutores(); break;
        case 6: mostrarListaDeSecretarias();break;
        case 7: break;
        case 8: menu(estacion_de_radio); break;
        default : mensajePorDefecto();
    }
    }while(op!=8);

}
