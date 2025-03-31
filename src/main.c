#include <32l432.h>

static void delay (unsigned int time) {
    for (unsigned int i = 0; i < time; i++)
        for (volatile unsigned int j = 0; j < 2000; j++);
}

int main (void) {

/*     RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    GPIOB->MODER |= GPIO_MODER_MODE3_0;
     */
    RCC->AHB2ENR |= (1<<1);                     //Register enables the clock for the GPIOB
    GPIOB->MODER |= (1<<6);		                //Pin PB3 (bits 6:5) as output (01)
    GPIOB->OTYPER &= ~(1<<3);	                //Output push pull

    
 /*   GPIOB->MODER &= ~GPIO_MODER_MODE3_Msk;    // Limpa os bits de modo do pino 3
    GPIOB->MODER |= GPIO_MODER_MODE3_0;       // Configura o pino como saída
   
     GPIOB->OTYPER &= ~GPIO_OTYPER_OT3;        // Configura como push-pull (0)
    
    // Configura o pino 3 de GPIOB com resistor pull-up (se necessário para o botão)
    GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD3_Msk;   // Limpa os bits de pull-up/pull-down do pino 3
 
    GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED3_Msk;  // Limpa os bits de velocidade do pino 3
    GPIOB->OSPEEDR |= (0x2UL << GPIO_OSPEEDR_OSPEED3_Pos); // Configura como alta velocidade (High speed)
 */

    // Loop para alternar o estado do pino 3
    while (1)
    {
        // Definir o pino 3 de GPIOB como HIGH (1)
        GPIOB->BSRR = GPIO_BSRR_BS3;
        for (volatile int i = 0; i < 1000000; i++);  // Atraso

        // Definir o pino 3 de GPIOB como LOW (0)
        GPIOB->BSRR = GPIO_BSRR_BR3;
        for (volatile int i = 0; i < 1000000; i++);  // Atraso
    }
    
    return 0;
}