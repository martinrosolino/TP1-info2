#include "lib.h"

void abierto()//Simula el estado del puente
    {
    printf("El puente esta abierto\n----------\n");
    }

void cerrado()//Simula el estado del puente
    {
    printf("El puente esta cerrado\n----------\n");
    }

void abierto1()//Simula el estado del puente con el cambio manual
    {
    printf("El puente esta abierto\n**Pulse cualquier tecla para volver al control automatico**\n----------\n");
    system("pause>nul");
    }

void cerrado1()//Simula el estado del puente con el cambio manual
    {
    printf("El puente esta cerrado\n**Pulse cualquier tecla para volver al control automatico**\n----------\n");
    system("pause>nul");
    }

void error()//Muestra el error por un ingreso de hora invalido
    {
    printf("Horario invalido\n----------\n");
    }

int inicio()//Lee los parametros desde el archivo de configuracion, simula el horario y la entrada para el control manual y decide que hacer segun los datos obtenidos
    {
    int numh,numm,numd,p1,f1,p2,f2,hora,min,horario,estado;
    char na,nb;
    FILE*datos=fopen("datos.txt","r");

    //Chequea si el archivo se abrio ok
    if(datos==NULL)
        {
        printf("Error en la lectura de la configuracion inicial");
        exit(1);
        }
    //Si se abrio ok funciona la maquina
    else
        {
        //Lee los datos del archivo de configuracion
        //Los %s son para que lea las descripciones del notepad y deje el cursor en el lugar indicado para leer el numero
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

    //Simula la obtencion de la hora
    printf("Hora: ");
    scanf("%d",&hora);
    printf("Minutos: ");
    scanf("%d",&min);

    //Control manual
    if(hora==777&&min==777)
        {
        //Alterna el estado actual segun el estado anterior
        if(aux==1)
            {
            estado=2;
            aux=0;
            }
        else
            if(aux==0)
            {
                estado=3;
                aux=1;
            }
        }

    //Control automatico
    else
        {
        //Verifica que los datos ingresados sean coherentes
        if(hora>=0&&hora<24&&min>=0&&min<=59)
            {
            horario=hora*60+min;//Pasa todo a minutos para facilitar el siguiente proceso
            //Verifica si el horario se encuentra entre los campos activos
            if((horario>=p1&&horario<=f1)||(horario>=p2&&horario<=f2))
                {
                    estado=1;
                    aux=1;
                }
            else
                {
                    estado=0;
                    aux=0;
                }
            }
        //Si los datos no fueron coherentes da error
        else
            estado=4;
        }
        return estado;
    }
