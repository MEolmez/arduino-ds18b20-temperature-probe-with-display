#include <OneWire.h>
#include <DallasTemperature.h>
#include "LowPower.h"
 

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);
 

DallasTemperature sensors(&oneWire);

#include <TM1637Display.h>
const int CLK = 9; 
const int DIO = 8; 

TM1637Display display(CLK, DIO);  //set up the 4-Digit Display.
 
void setup(void)
{

  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  display.setBrightness(1);
  

  sensors.begin();
}
 
 
void loop(void)
{
    LowPower.idle(SLEEP_2S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
 
    sensors.requestTemperatures();


    display.showNumberDecEx(sensors.getTempCByIndex(0));
 
 
}
