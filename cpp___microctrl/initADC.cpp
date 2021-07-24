#include �lpc213x.h�
#include �uart.h�
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define P028_ADC01_SEL (1<<24)
#define P029_ADC02_SEL (1<<26)
/* Initialize ADC */
inline static void initADC(void)
{
 AD0CR = 60<<AD0CR_CLKDIV_BIT | 1<<AD0CR_PDN_BIT;
 PINSEL1 |= P028_ADC01_SEL | P029_ADC02_SEL;
}
/* Get ADC Value */
int getADC(int Chan)
{
 AD0CR &= ~AD0CR_SEL_MASK;
 AD0CR |= 1<<Chan & AD0CR_SEL_MASK;
 AD0CR |= 1<<AD0CR_START_BIT;
 while(!(AD0DR & AD0DR_DONE));
 return (AD0DR >> 6) & 0x3FF;
}
/* Funkcja glowna main */
int main(void)
{
 //Inicjalizacja UART
 Uart0Init(UART_BAUD(9600));
 //Napis zachety
 printf(�Mikrokontrolery z rdzeniem ARM cz IX\r\n�);
 printf(�Przetwornik A/C (Czujnik temperatury)\r\n�);
 initADC();
 int kty,pot;
 const float Vref = 3.3;
 while(1)
 kty = getADC(2);
 pot = getADC(1);
 printf(�Vpot = %.2f V\r\n�,(pot/1023.0)*Vref);
 float Ukty = (kty/1023.0)*Vref;
 printf(�Rkty = %.2f kOhm\r\n�,Ukty/(Vref�Ukty));
 for(volatile int i=0;i<1000000;i++);
 }
 return 0;
}
