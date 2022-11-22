/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
 
 
 
 
enum estados {estadoUno, estadoDos} estado;
 
const float         AVG_SLOPE   = 4.3E-03;      
const float         V30         = 1.43;   
float Vsense;
int i = 0; 
int j = 0;

DigitalOut led(LED1);
DigitalIn  boton(USER_BUTTON);
AnalogIn adc_temp(ADC_TEMP);
float TempsArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ; 
float max = 0.0;
float min = 0.0;

int contador = 0;

Timer temporizador;

//DigitalIn boton(PC_13);


void estado1() //Estado1, TomarMedida
{
    if(boton==0) {
        temporizador.reset();
        led=1;
        estado=estadoDos;
    }
}
 
void estado2()  //Estado2, EstadoReset
{
    if(temporizador.read()>2.0f) {
        led=0;
        estado=apagado;
    }
}


void estado3()   //Estado3, Estado MaxMin
{ 
    if(temporizador.read()<1.0f && contador == 2 ) {
       

        for (i=0;i<10;i++){
            if (TempsArray[i]>TempsArray[i+1]){
            max = TempsArray[i];   
            } 
        }

        for (i=0;i<10;i++){
            if (TempsArray[j]<TempsArray[j+1]){
                min = TempsArray[j];
            }
        }

        led=1;
        
        estado=apagado;
    }
}

estado = estadoUno;

int main()
{

for (i=0;i<10;i++){


switch (estado){

    case estadoUno:

        break;

    case estadoDos:

        break;

    case estadoTres:

    break;


}

    

   estado=estadoUno;
   Vsense=adc_temp.read()*3.3;








   if (i==10){
       i=0;
   }



    while(1) {
      
    }
}
 
            
//Repository toolbox
//Import into Keil Studio
 //Export to desktop IDE
// Build repository
//Repository details
//Type:	 Program
//Mbed OS support:	Mbed 2 deprecated
//Created:	21 Dec 2021
//Imports:	 23
//Forks:	 0
//Commits:	 2
//Dependents:	 0
//Dependencies:	 1
//Followers:	 1
 //Twitter  YouTube  Forum  Blog
//Copyright © 2022 Arm Limited (or its affiliates).