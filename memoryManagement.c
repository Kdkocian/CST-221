//Kyle David Kocian
//CST-221
//Professor Michael Landreth
//6/26/2020

#include <stdio.h>
#include <string.h>
//converts input into binary
void binary(int d)
{
	int n, c;
	printf("%d in binary is\n", d);
	for(n = 31; n >= 0; n--)
	{
		c = d >> n;
		if(c & 1)
			printf("1");
		else
			printf("0");		
	}  
	printf("\n");
}
//converts input into hexadecimal
void hexadecimal(int d)
{
	int n, c;
	int binary[32];
	printf("%d in hexadecimal is\n", d);
	printf("%X\n", d);
}
//changes the decimal inputed by user
void changeinput(int d)
{
	printf("%d will be changed to\n", d);
	for(int x = 16; x >= 0; x--)
	d = d >> x;
	d = d & 1111111111110000;
	d = d | 0x07ff;
	printf("%d\n", d);
}

int main()
{
	int input;
	while(input < 0 || input > 4095)
	{
		printf("enter a decimal number between 0 and 4095 \n");
		scanf("%d", &input);
	}
	binary(input);
	hexadecimal(input);
	changeinput(input);
	return(0);	
}	
