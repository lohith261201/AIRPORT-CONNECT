#include<stdio.h>
#include<string.h>
int flag=0;
int num=1;

char dest[15];

typedef struct data
{
    int price, flightnum;
    char airline[20], dest[20];
}da;
da fu;

void readdest();
void payment();
void board(int,int);
void calculate();
void flightscheck(int,int);

void main()
{
printf("            ****************WELCOME TO THE INSTANT FLIGHT BOOKING PORTAL OF ALGL AIRPORT***************                 \n\n");   
printf("  BOOKING ONLY  AVAILABLE FOR FLIGHTS SCHEDULED TO DEPART FROM ALGL AIRPORT WITHIN THE NEXT 3 HOURS(DOMESTIC) AND WITHIN THE NEXT 6 HOURS(INTERNATIONAL)\n");
    readdest();
    calculate();
if(flag==1)
{
printf("                    **************** YOUR FLIGHT DETAILS****************                                                \n\n");    

printf("Price = %u\nFlightnum = %u\nDest = %s\nAirline = %s\n",fu.price, fu.flightnum, fu.dest, fu.airline);
printf("                    ****************HAVE A SAFE JOURNEY*****************                                                \n");
 }   
}

void readdest()
{
    int n=0,m=0;
   a:printf("Please Select\n1.Domestic Flights\n2.International Flights\n");
    scanf("%d",&n);
    if(n==1)
    {
        board(m,n);
    }
    else if(n==2)
    {
        printf("Please Select Region\n1.Africa\n2.Eurasia\n3.Australasia\n4.South America\n5.North America\n");
        scanf("%d",&m);
        board(m,n);

    }
    else
    {
printf("enter valid option\n");
goto a;
    }
    
    
}

void board(int n,int m)
{
    FILE *fp;
    char buff[1000];
    int rows=0, fields=0;
    if(n==1)
        fp = fopen("AfFlights.txt","r");
    else if(n==2)
        fp = fopen("EUASFlights.txt","r");
    else if(n==3)
        fp = fopen("AUFlights.txt","r");
    else if(n==4)
        fp = fopen("SAFlights.txt","r");
    else if(n==5)
        fp = fopen("NAFlights.txt","r");
    else if(m==1)
        fp = fopen("LocalFlights.txt","r");
    
    if(!fp)
        printf("Can't Open file");
    
    while(fgets(buff,1000,fp))
    {
        fields = 0;
        rows++;
        if(rows==1)
            continue;

        char *field = strtok(buff,",");

            while (field) 
            {
                if (fields == 0) 
                {
                    printf("Destination:\t");
                }
                if (fields == 1)
                {
                    printf("Airline:\t");
                }
                if (fields== 2) 
                {
                    printf("Flight Number:\t");
                }
                if (fields == 3) 
                {
                    printf("Base Price:\t");
                }
                printf("%s\n", field);
                field = strtok(NULL, ",");
                printf("\n");
                fields++;
            }
    }
    printf("Enter Name of the selected Destination\n");
    scanf("%s",&dest);
    flightscheck(n,m);
    
    fclose(fp);
}


void flightscheck(int n,int m)
{
    FILE *fp;
    char buff[1000];
    int rows=0, fields=0;
    if(n==1)
        fp = fopen("AfFlights.txt","r");
    else if(n==2)
        fp = fopen("EUASFlights.txt","r");
    else if(n==3)
        fp = fopen("AUFlights.txt","r");
    else if(n==4)
        fp = fopen("SAFlights.txt","r");
    else if(n==5)
        fp = fopen("NAFlights.txt","r");
    else if(m==1)
        fp = fopen("LocalFlights.txt","r");
    if(!fp)
        printf("Can't Open file");
    
    printf("The selected Flight details are\n\n");

    while(fgets(buff,1000,fp))
    {
        fields = 0;
        rows++;
        if(rows==1)
            continue;

        char *field = strtok(buff,",");
        if(strcmp(field,dest)==0)
        {
            while (field) 
            {
                if (fields == 0) 
                {
                    printf("Destination:\t");
                    strcpy(fu.dest, field);
                }
                if (fields == 1)
                {
                    printf("Airline:\t");
                    strcpy(fu.airline, field);
                }
                if (fields== 2) 
                {
                    printf("Flight Number:\t");
                    fu.flightnum = atoi(field);
                }
                if (fields == 3) 
                {
                    printf("Base Price:\t");
                    fu.price = atoi(field);
                }
                printf("%s\n", field);
                field = strtok(NULL, ",");

                fields++;
            }
        }
         

}
    
   fclose(fp);

}


void calculate()
{
    int n,m;
    printf("Enter the number of tickets you'd like to book\n");
    scanf("%d",&n);
    fu.price=fu.price*n;
   choice:printf("You have these options for seats\n1.Economy (Base Price+Tax)\n2.Business (Base Price + 20000+TAX)\n3.First (Base Price + 100000+TAX)\n");
    scanf("%d",&m);
    if(m==1)
   {
    fu.price=fu.price+400;
   }
    else if(m==2)
        fu.price=fu.price+20000+(20000*20)/100;
    else if(m==3)
        fu.price=fu.price+100000+(100000*20)/100;
else if(m!=1&&m!=2&&m!=3)
{
printf("enter valid option\n");
goto choice;
}
printf("**** **** ****       WELCOME TO THE PAYMENT PORTAL OF ALGL AIRPORT       ****  ****  **** \n\n");
int a[10][2];
memset(a,0,sizeof(a[0][0])*10*2);
a[0][0]=500000;
a[1][0]=600000;
a[2][0]=200;
a[0][1]=111;
a[1][1]=222;
a[2][1]=333;
int no;
printf("enter your ALGL userid\n");
scanf("%d",&no);
if(a[no][1]!=0)
{
int pin;
printf("enter your ALGL pin\n");
scanf("%d",&pin);
if(a[no][1]==pin)
{
printf("your available balance is  %d \n",a[no][0]);
if(a[no][0]>fu.price)
{
printf("price:%u\n",fu.price);
printf("payment successful\n");
printf("remaining balance:%u\n",a[no][0]-fu.price);

flag=1;
}
else
{
printf("insufficient balance\n");
printf(" transaction disrupted,please re-enter the portal");

}}
else
{
printf("incorrect pin\n");
}
}
else
{
printf("invalid user id\n transaction disrupted ,please re -enter the portal\n");

} 
}
