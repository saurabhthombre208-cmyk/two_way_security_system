#include<reg51.h>
sbit r0 = P1^0;
sbit r1 = P1^1;
sbit r2 = P1^2;
sbit r3= P1^3;
sbit c0 = P1^4;
sbit c1 = P1^5;
sbit c2 = P1^6;
sbit c3 = P1^7;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN= P3^2;
#define data_line P2
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay(int);
void lcd_string(unsigned char *);

void UART_init(void);
void trans(unsigned char);
int i=0;
int pass[4];
void main()
{
	lcd_init();
	UART_init();
	while(1)
	{
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Enter password");
		i=0;
		lcd_cmd(0xc0);
		while(i<4)
		{
		r0 = 0;
			r1=r2=r3=1;
			if(c0==0)
			{
				lcd_data('*');
       pass[i]='1';   
				i++;
       }
			 
		r0 = 0;
			r1=r2=r3=1;
			if(c1==0)
			{
				lcd_data('*');
       pass[i]='2';   
				i++;
       }
			 
		r0 = 0;
			r1=r2=r3=1;
			if(c2==0)
			{
				lcd_data('*');
       pass[i]='3';   
				i++;
       }
			r1 = 0;
			r0=r2=r3=1;
			if(c0==0)
			{
				lcd_data('*');
       pass[i]='4';   
				i++;
       }
			 
		r1 = 0;
			r0=r2=r3=1;
			if(c1==0)
			{
				lcd_data('*');
       pass[i]='5';   
				i++;
       }
			 
		r1 = 0;
			 r0=r2=r3;
       if(c2==0)
			 {
				 lcd_data('*');
				 pass[i]='6';
				 i++;
			 }
			 
		r2 = 0;
			r1=r0=r3=1;
			if(c0==0)
			{
				lcd_data('*');
       pass[i]='7';   
				i++;
       }
			 
		r2 = 0;
			r1=r0=r3=1;
			if(c1==0)
			{
				lcd_data('*');
       pass[i]='8';   
				i++;
       }
			 
		r2 = 0;
			r1=r0=r3=1;
			if(c2==0)
			{
				lcd_data('*');
       pass[i]='9';   
				i++;
       }
			 
		r3 = 0;
			r1=r2=r0=1;
			if(c1==0)
			{
				lcd_data('*');
       pass[i]='0';   
				i++;
       }
			 delay(100);
		 }
		 lcd_cmd(0x01);
		 lcd_cmd(0x80);
		 lcd_string("sending");
		
 
	for(i=0;i<4;i++)
{
	trans(pass[i]);
 }
delay(1000);
}

}
void UART_init(void)
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
}
void trans(unsigned char x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
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

	


		