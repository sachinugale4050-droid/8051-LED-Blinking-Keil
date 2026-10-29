#include <reg51.h>

void delay(unsigned int i)
{
    unsigned char j;

    for (; i > 0; i--)
    {
        for (j = 255; j > 0; j--);
        for (j = 232; j > 0; j--);
    }
}

void main(void)
{
    unsigned int i;

    while (1)
    {
        for (i = 1; i <= 100; i++)
        {
            P2 = i;
            delay(1000);
        }
    }
}