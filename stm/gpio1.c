
#define RCC_AHB1ENR (*((volatile unsigned int*)0x40023830))
#define GPIOG_MODER (*((volatile unsigned int*)0x40021800))
#define GPIOG_ODR (*((volatile unsigned int*)0x40021814))
#define GPIOG_IDR (*((volatile unsigned int*)0x40021810))
#define GPIO_PIN1 (1<<1)//LDR INPUT
#define GPIO_PIN13 (1<<13)//LED OUTPUT
void delay(void)
{
	for(volatile int i=0;i<100000;i++);
}

int main(void)
{
    RCC_AHB1ENR |= (1<<6);

//    GPIOG_MODER &=~((3<<(13*2))|(3<<(1*2)));
      GPIOG_MODER |= (1<<(13*2));
    while(1)
    {
    	if((GPIOG_IDR & GPIO_PIN1)==0)
    	{
    		GPIOG_ODR &= GPIO_PIN13; //LED off when dark
    	}
    	else
    	{
    		GPIOG_ODR |= GPIO_PIN13;//LED On when light
    	}
    	delay();
    }

}

