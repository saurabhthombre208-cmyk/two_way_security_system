#include<reg51.h>

sbit RS = P3^7;
sbit RW = P3^6;
sbit EN = P3^5;

#define data_line P1
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay(int);
void lcd_string(unsigned char *);
void UART_init(void);
unsigned char recerver(void);
void main()
{
	unsigned char receive[4];
	int i;
	lcd_init();
UART_init();
	while(1){
	lcd_cmd(0x80);
	lcd_string("password is ");
	lcd_cmd(0xc0);
		delay(10000);
	for(i=0;i<4;i++)
	{
	receive[i]=receiver();
	lcd_data('*');
    }
	if(receive[0]=='8'&&receive[1]=='6'&&receive[2]=='0'&&receive[3]=='0')
	{
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("access granted");
		delay(1000);
	}
	else{
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("access dened");
		delay(1000);
	}}
	
	


}
	void lcd_string(unsigned char *p)
{
	while(*p!='\0')
	{
		lcd_data(*p);
	p++;
	}
	}
void lcd_init(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_cmd(0x0f);
}
void lcd_cmd(unsigned char s)
{
	data_line=s;
	RS = 0;
	RW = 0;
	EN =1;
	delay(10);
	EN = 0;
}
	
void lcd_data(unsigned char s)
{
	data_line=s;
	RS = 1;
	RW = 0;
	EN =1;
	delay(10);
	EN = 0;
}
void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<200;j++)
		{
		}
	}
}
void UART_init(void)
{
	TMOD = 0X20;
	TH1 = 0XFD;
	SCON = 0X50;
	TR1 = 1;
}
unsigned char receiver(void)
{
	while(RI==0);
	RI = 0;
	return SBUF;
}

	

