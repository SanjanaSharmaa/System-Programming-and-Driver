#define RCC_AHB1ENR (*((volatile unsigned int*)0x40023830))
#define GPIOG_MODER (*((volatile unsigned int*)0x40021800))
#define GPIOG_ODR (*((volatile unsigned int*)0x40021814))
void delay(void)
{
	for(volatile int i=0;i<100000;i++);
}

int main(void)
{
    RCC_AHB1ENR |= (1<<6);

    GPIOG_MODER &=~(3<<(13*2));
    GPIOG_MODER |= (1<<(13*2));
    while(1)
    {
    	GPIOG_ODR ^= (1<<13);
    	delay();
    }

}
