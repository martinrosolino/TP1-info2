#include "lib.h"

void cargadatos()//lee los parametros desde el archivo de configuracion
    {
    int numh,numm,numd,na,nb;
    FILE*datos=fopen("datos.txt","r");
    if(datos==NULL)
        {
        printf("Error en la lectura de la configuracion inicial");
        exit(1);
        }
    else
        {
//los %s son para que lea las descripciones del notepad y deje el cursor en el lugar indicado para leer el numero
        fscanf(datos,"%s%s%d",&na,&nb,&numh);
        fscanf(datos,"%s%s%d",&na,&nb,&numm);
        fscanf(datos,"%s%s%d",&na,&nb,&numd);
        p1=numh*60+numm;
        f1=p1+numd-1;
        fscanf(datos,"%s%s%d",&na,&nb,&numh);
        fscanf(datos,"%s%s%d",&na,&nb,&numm);
        fscanf(datos,"%s%s%d",&na,&nb,&numd);
        p2=numh*60+numm;
        f2=p2+numd-1;
        }
    fclose(datos);
    }

void abierto()//simula el estado del puente
    {
    printf("El puente esta abierto\n----------\n");
    }

void cerrado()//simula el estado del puente
    {
    printf("El puente esta cerrado\n----------\n");
    }

void inicio()//simula el horario y la entrada para el control manual y decide que hacer segun los datos obtenidos
    {
    int hora,min,horario;
    printf("Hora: ");
    scanf("%d",&hora);
    printf("Minutos: ");
    scanf("%d",&min);
    if(hora==777&&min==777)//control manual
        {
        if(estados==1)//alterna el estado actual segun el estado anterior
            cerrado();
        if(estados==0)
            abierto();
        printf("Pulse cualquier tecla para volver al control automatico\n----------\n");
        estado=2;
        system("pause>nul");
        }
    else//control automatico
        {
        if(hora>=0&&hora<24&&min>=0&&min<=59)//verifica que los datos ingresados sean coherentes
            {
            horario=hora*60+min;//pasa todo a minutos para facilitar el siguiente proceso
            if(horario>=p1&&horario<=f1||horario>=p2&&horario<=f2)//verifica si el horario se encuentra entre los campos activos
                {
                estado=1;
                estados=1;//para tener registro del estado anterior y asi poder alternarlo cuando se activa el control manual luego de un ingreso invalido
                }
            else
                {
                estado=0;
                estados=0;
                }
            }
        else
            {
            printf("Horario invalido\n----------\n");
            estado=2;
            }
        }
    }
