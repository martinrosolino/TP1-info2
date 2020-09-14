#include "lib.h"

int abierto(tipo config)//Simula el estado del puente
    {
    printf("El puente esta abierto\n----------\n");
    if(aux==1)
        {
        printf("Pulse cualquier tecla para volver al control automatico\n----------\n");
        system("pause>nul");
        }
    int hora,min,horario;
    printf("Hora: ");
    scanf("%d",&hora);
    printf("Minutos: ");
    scanf("%d",&min);

    //Control manual
    if(hora==777&&min==777)//Alterna el estado actual segun el estado anterior
        {
        aux=1;
        if(estado==1)
            return 0;
        if(estado==0)
            return 1;
        }

    //Control automatico
    else
        {
        //Verifica que los datos ingresados sean coherentes
        if(hora>=0&&hora<24&&min>=0&&min<=59)
            {
            horario=hora*60+min;//Pasa todo a minutos para facilitar el siguiente proceso
            aux=0;
            //Verifica si el horario se encuentra entre los campos activos
            if((horario>=config.p1&&horario<=config.f1)||(horario>=config.p2&&horario<=config.f2))
                    return 1;
            else
                    return 0;
            }
        //Si los datos no fueron coherentes da error
        else
            {
            aux=0;
            printf("Horario invalido\n----------\n");
            return estado;
            }
        }
    }

int cerrado(tipo config)//Simula el estado del puente
    {
    printf("El puente esta cerrado\n----------\n");
    if(aux==1)
        {
        printf("Pulse cualquier tecla para volver al control automatico\n----------\n");
        system("pause>nul");
        }
    int hora,min,horario;
    printf("Hora: ");
    scanf("%d",&hora);
    printf("Minutos: ");
    scanf("%d",&min);

    //Control manual
    if(hora==777&&min==777)//Alterna el estado actual segun el estado anterior
        {
        aux=1;
        if(estado==1)
            return 0;
        if(estado==0)
            return 1;
        }

    //Control automatico
    else
        {
        //Verifica que los datos ingresados sean coherentes
        if(hora>=0&&hora<24&&min>=0&&min<=59)
            {
            horario=hora*60+min;//Pasa todo a minutos para facilitar el siguiente proceso
            aux=0;
            //Verifica si el horario se encuentra entre los campos activos
            if((horario>=config.p1&&horario<=config.f1)||(horario>=config.p2&&horario<=config.f2))
                    return 1;
            else
                    return 0;
            }
        //Si los datos no fueron coherentes da error
        else
            {
            aux=0;
            printf("Horario invalido\n----------\n");
            return estado;
            }
        }
    }

tipo inicio()//Lee los parametros desde el archivo de configuracion, simula el horario y la entrada para el control manual y decide que hacer segun los datos obtenidos
    {
    int numh,numm,numd,p1,f1,p2,f2,horario,na,nb;
    tipo config;
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

        //Primer turno
        fscanf(datos,"%s%s%d",&na,&nb,&numh);
        fscanf(datos,"%s%s%d",&na,&nb,&numm);
        fscanf(datos,"%s%s%d",&na,&nb,&numd);
        config.p1=numh*60+numm;
        config.f1=config.p1+numd-1;

        //Segundo turno
        fscanf(datos,"%s%s%d",&na,&nb,&numh);
        fscanf(datos,"%s%s%d",&na,&nb,&numm);
        fscanf(datos,"%s%s%d",&na,&nb,&numd);
        config.p2=numh*60+numm;
        config.f2=config.p2+numd-1;
        }
    fclose(datos);
    return config;
    }
