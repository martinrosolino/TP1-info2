#include "lib.h"

tipoestado abrir(tipo config)//Simula el estado del puente
    {
    printf("El puente esta abierto\n----------\n");
    sleep(1);
    int horario;
    time(&currenttime);
    struct tm *tiempo=localtime(&currenttime);
    horario=(tiempo->tm_hour)*60+(tiempo->tm_min);

    //Control automatico
    //Verifica si el horario se encuentra entre los campos activos
    if((horario>=config.p1&&horario<=config.f1)||(horario>=config.p2&&horario<=config.f2))
            return abierto;
    else
            return cerrado;
    }

tipoestado cerrar(tipo config)//Simula el estado del puente
    {
    printf("El puente esta cerrado\n----------\n");
    sleep(1);
    int horario;
    time(&currenttime);
    struct tm *tiempo=localtime(&currenttime);
    horario=(tiempo->tm_hour)*60+(tiempo->tm_min);

    //Control automatico
    //Verifica si el horario se encuentra entre los campos activos
    if((horario>=config.p1&&horario<=config.f1)||(horario>=config.p2&&horario<=config.f2))
            return abierto;
    else
            return cerrado;
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
