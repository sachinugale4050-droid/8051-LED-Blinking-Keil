
#include <reg51.h>

#define LCD P2

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

char password[] = "1234";
char entered[5];

char keys[4][4] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'C', '0', '=', '+'}
};

void delay(unsigned int t)
{
    unsigned int i, j;
    for(i = 0; i < t; i++)
        for(j = 0; j < 1275; j++);
}

void lcd_cmd(unsigned char cmd)
{
    LCD = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    delay(2);
    EN = 0;
}

void lcd_data(unsigned char dat)
{
    LCD = dat;
    RS = 1;
    RW = 0;
    EN = 1;
    delay(2);
    EN = 0;
}

void lcd_init()
{
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
    lcd_cmd(0x06);
}

void lcd_string(char *s)
{
    while(*s)
        lcd_data(*s++);
}

void keypad_wait_release()
{
    delay(20);
    while((P1 & 0xF0) != 0xF0);
    delay(20);
}

char keypad()
{
    unsigned char row, col;

    while(1)
    {
        for(row = 0; row < 4; row++)
        {
            P1 = 0xFF;
            P1 &= ~(1 << row);

            col = P1 & 0xF0;

            if(col != 0xF0)
            {
                delay(20);

                col = P1 & 0xF0;

                if(col != 0xF0)
                {
                    if(col == 0xE0)
                    {
                        keypad_wait_release();
                        return keys[row][0];
                    }
                    if(col == 0xD0)
                    {
                        keypad_wait_release();
                        return keys[row][1];
                    }
                    if(col == 0xB0)
                    {
                        keypad_wait_release();
                        return keys[row][2];
                    }
                    if(col == 0x70)
                    {
                        keypad_wait_release();
                        return keys[row][3];
                    }
                }
            }
        }
    }
}

void main()
{
    unsigned char i;
    char key;

    P1 = 0xFF;
    lcd_init();

    while(1)
    {
        i = 0;

        lcd_cmd(0x01);
        lcd_cmd(0x80);
        lcd_string("Enter Password");

        lcd_cmd(0xC0);

        while(1)
        {
            key = keypad();

            if(key == 'C')
            {
                i = 0;
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Enter Password");
                lcd_cmd(0xC0);
            }
            else if(key == '=')
            {
                break;
            }
            else if(key >= '0' && key <= '9')
            {
                if(i < 4)
                {
                    entered[i] = key;
                    lcd_data('*');
                    i++;
                }
            }
        }

        entered[i] = '\0';

        if(i == 4 &&
           entered[0] == password[0] &&
           entered[1] == password[1] &&
           entered[2] == password[2] &&
           entered[3] == password[3])
        {
            lcd_cmd(0x01);
            lcd_cmd(0x80);
            lcd_string("Unlocked!");
            lcd_cmd(0xC0);
            lcd_string("Namaskaram");
        }
        else
        {
            lcd_cmd(0x01);
            lcd_cmd(0x80);
            lcd_string("Wrong Password");
            lcd_cmd(0xC0);
            lcd_string("Try Again");
        }

        delay(2000);
    }
}
