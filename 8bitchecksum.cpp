//program to take sender_codedecimal inout and perform the 8-bit checksum on the network
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<math.h>
#include<cstdlib>
//#include<libm.a>

char * read_input(int n) //n is taken from the main(). n=number of hexadecimal inputs
{	
    char *sendercode;
    sendercode=(char*)malloc(n * sizeof(char));
    for(int i=0;i<=n;i++)
    {   
        scanf("%c",&sendercode[i]);
    }
	
	return sendercode;
}

char * hex_to_binary(char *sender_code,int n)
{   int i=1;
    int j=0;

    char *hex_code;
    hex_code=(char *)malloc((n*4)*sizeof(char));
        while (i<=n)

    {   switch (sender_code[i])
		
        {
		case '0':
            hex_code[i+j]='0';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='0';
            break;

        case '1':

            hex_code[i+j]='0';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='1'; 
            break;

        case '2':

            hex_code[i+j]='0';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='0'; 
            break;

        case '3':

            hex_code[i+j]='0';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='1';
            break;

        case '4':

            hex_code[i+j]='0';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='0'; 
            break;

        case '5':

            hex_code[i+j]='0';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='1'; 
            break;

        case '6':

            hex_code[i+j]='0';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='0'; 
            break;

        case '7':

            hex_code[i+j]='0';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='1'; 
            break;

        case '8':

            hex_code[i+j]='1';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='0'; 
            break;

        case '9':

            hex_code[i+j]='1';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='1';
            break;

        case 'A':

            hex_code[i+j]='1';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='0'; 
            break;

        case 'B':

            hex_code[i+j]='1';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='1'; 
            break;

        case 'C':

            hex_code[i+j]='1';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='0'; 
            break;

        case 'D':

            hex_code[i+j]='1';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='1'; 
            break;

        case 'E':

            hex_code[i+j]='1';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='0';
            break;

        case 'F':

            hex_code[i+j]='1';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='1'; 
            break;

        case 'a':

            hex_code[i+j]='1';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='0'; 
            break;

        case 'b':

            hex_code[i+j]='1';
            hex_code[i+j+1]='0';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='1'; 
            break;

        case 'c':

            hex_code[i+j]='1';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='0'; 
            break;

        case 'd':

            hex_code[i+j]='1';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='0';
            hex_code[i+j+3]='1'; 
            break;

        case 'e':

            hex_code[i+j]='1';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='0';
            break;

        case 'f':

            hex_code[i+j]='1';
            hex_code[i+j+1]='1';
            hex_code[i+j+2]='1';
            hex_code[i+j+3]='1'; 
            break;
        default:
            printf("Invalid HxD value entered.");
            break;
        }        
        j+=3;
        i++;
		}
    
    return hex_code;
}

int binary_adder(int binary1, int binary2)
{
int i = 0, remainder = 0; 
int *sum;
sum=(int*)malloc(20 * sizeof(int));

    while (binary1 != 0 || binary2 != 0)

    {
        sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;

        remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;

        binary1 = binary1 / 10;

        binary2 = binary2 / 10;
 }

    if (remainder != 0)

        sum[i++] = remainder;

    --i; //the sum[] has the summation in reverse order in the array.
    char *binary_sum;
    binary_sum=(char*)malloc((i+1)* sizeof(char));
    
    while (i >= 0)
        binary_sum[i]=sum[i--];
    
    int summation;
    sscanf(binary_sum,"%d",&summation);
    
    int rev_num = 0; 
    while(summation > 0) 
    { 
        rev_num = rev_num*10 + summation%10; 
        summation = summation/10; 
    } 
    return rev_num;
}

int * segmentation(char *binary, int len)
{   
	int *segments,k=0,rem=0,temp_len;
	char temp[8];
    	
	if(len%8==0)
	{
		len/=8;
		segments=(int*)malloc((len)*sizeof(int));
		for(int i=1;i<=len;i++)
		{	
			for(int j=0;j<7;j++)
			temp[j]=binary[j+k+1];
			
			sscanf(temp,"%d",segments[i]);
			k+=8;
		}
	}
	
	else
	{	rem=len-8;
		len=(len/8)+1;
		k=0;
		segments=(int*)malloc(((len)*sizeof(int)));
		
		for(int i=1;i<=(len-1);i++)
		{	
			for(int j=0;j<7;j++)
			temp[j]=binary[j+k+1];
			
			sscanf(temp,"%d",segments[i]);
			k+=8;
		}
		
		temp_len=(8*(len/8));
		for(int j=0;j<rem;j++)
			temp[j]=binary[j+temp_len+1];
			
		sscanf(temp,"%d",segments[len]);
	}
    
    return segments;
    
}

int complement(int checksum)
{
    int len=8;
        
    int rem;
    char complementary[len];
    for(int i=1;i<=len;i++)
      {
        rem=checksum%10;
        
        if(rem==0)
        complementary[len-i]='1';
        else
        complementary[len-i]='0';
        
        checksum/=10;
       }
       
       int complement1;
       sscanf(complementary,"%d",&complement1);
       return complement1;
}

int sender(char *binary,int n)
{
    int *segments;
    segments=segmentation(binary,n*4);
    int checksum=0,len, overflow, temp;
    
    for(int i=0;i<n;i++)
    {   
        checksum=binary_adder(checksum,segments[i]);
        len=0;
        temp=checksum;
        while(temp>9)
        {
            len++; 
            temp/=10;
      }
        if(len>8)
        {   
            overflow=(checksum/(pow(10,8)));
            checksum=(checksum%((int)pow(10,8)));
            checksum=binary_adder(checksum,overflow);
            }
        }
    
        return checksum;
}
    
int received(char *binary, int n)
{   int *segments;
    segments=segmentation(binary,n*4);
    int checksum=0,len, overflow, temp;
    
    for(int i=0;i<n;i++)
    {   
        checksum=binary_adder(checksum,segments[i]);
        len=0;
        temp=checksum;
        while(temp>9)
        {
            len++; 
            temp/=10;
      }
        if(len>8)
        {   
            overflow=(checksum/(pow(10,8)));
            checksum=(checksum%((int)pow(10,8)));
            checksum=binary_adder(checksum,overflow);
            }
        }
    
    return complement(checksum); 
}

 
int main()
{
    int n;
    printf("Enter the number of HxD values:");
    scanf("%d",&n);
    
    char *sender_code=read_input(n);
    char *hex_code=hex_to_binary(sender_code,n);
    int checksum=sender(hex_code,n);
    printf("The checksum value is: %d\nEnter the number of bits of received code: ",checksum);
    
    int rcn;
    scanf("%d",&rcn);
	char *received_code=read_input(rcn);
    int received_decoded=received(received_code,rcn);
    
    if(received_decoded==00000000)
    {
        printf("\nThe received code has not been tampering.");
     }
        
    else
    {
        printf("\nThe received code has been tampered.");
        }
        
    free(sender_code);
    free(hex_code);
    return 0;    
}
