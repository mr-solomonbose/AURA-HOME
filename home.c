#include<lpc21xx.h>
#include<string.h>
#include"lcdheader.h"
#include"uartheader.h"
#define light1 1<<14
#define light2 1<<15
#define light3 1<<16
#define light4 1<<17
char ch;
char rx_buf[120];
int i=0;
int main()
{
	IODIR0|=light1|light2|light3|light4;
	IOSET0=light1|light2|light3|light4;
	LCD_INIT();
	UART0_CONFIG();
	scroll_left_to_right("AURA HOME:An Integrated IoT framework for cloud based domestic automation");
	LCD_COMMAND(0x01);
	LCD_COMMAND(0x80);
	LCD_STR("LIGHT_1:OFF");
	LCD_COMMAND(0xc0);
	LCD_STR("LIGHT_2:OFF");
	LCD_COMMAND(0x94);
	LCD_STR("LIGHT_3:OFF");
	LCD_COMMAND(0xD4);
	LCD_STR("LIGHT_4:OFF");

while (1)
{
	   ch = UART0_RX();
     rx_buf[i++] = ch;

     if (i >= sizeof(rx_buf) - 1)
     {
			i = 0;
			rx_buf[0] = '\0';
		 }

				rx_buf[i] = '\0';

        if (strcmp(rx_buf,"light1on") == 0)
        {
            LCD_COMMAND(0x80);
					  IOCLR0=light1;
            LCD_STR("LIGHT_1:ON ");
					  i=0;
					  rx_buf[0] = '\0';
        }
        else if (strcmp(rx_buf,"light1off") == 0)
        {
            LCD_COMMAND(0x80);
					  IOSET0=light1;
            LCD_STR("LIGHT_1:OFF");
					  i=0;
					  rx_buf[0] = '\0';
        }
				else if (strcmp(rx_buf,"light2on") == 0)
        {
            LCD_COMMAND(0xc0);
					  IOCLR0=light2;
            LCD_STR("LIGHT_2:ON ");
					  i=0;
					  rx_buf[0] = '\0';
        }
				else if (strcmp(rx_buf,"light2off") == 0)
        {
            LCD_COMMAND(0xc0);
					  IOSET0=light2;
            LCD_STR("LIGHT_2:OFF");
					  i=0;
					  rx_buf[0] = '\0';
        }
				else if (strcmp(rx_buf,"light3on") == 0)
        {
            LCD_COMMAND(0x94);
					  IOCLR0=light3;
            LCD_STR("LIGHT_3:ON ");
					  i=0;
					  rx_buf[0] = '\0';
        }
				else if (strcmp(rx_buf,"light3off") == 0)
        {
            LCD_COMMAND(0x94);
					  IOSET0=light3;
            LCD_STR("LIGHT_3:OFF");
					  i=0;
					  rx_buf[0] = '\0';
        }
				else if (strcmp(rx_buf,"light4on") == 0)
        {
            LCD_COMMAND(0xd4);
					  IOCLR0=light4;
            LCD_STR("LIGHT_4:ON ");
					  i=0;
					  rx_buf[0] = '\0';
        }
				else if (strcmp(rx_buf,"light4off") == 0)
        {
            LCD_COMMAND(0xd4);
					  IOSET0=light4;
            LCD_STR("LIGHT_4:OFF");
					  i=0;
					  rx_buf[0] = '\0';
        }
			
}
			
}
