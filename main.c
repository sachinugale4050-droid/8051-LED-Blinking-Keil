
#include <reg51.h>

sbit LED = P1^0;

void delay(void)
{
    unsigned int i, j;

    for (i = 0; i < 200; i++)
    {
        for (j = 0; j < 1275; j++)
        {
            // Software delay
        }
    }
}

void main(void)
{
    while (1)
    {
        LED = 1;    // LED ON
        delay();

        LED = 0;    // LED OFF
        delay();
    }
}
