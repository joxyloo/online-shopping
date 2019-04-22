#include <stdio.h>
#include <stdlib.h>

//reset every item when added itno cart
// function 4 
void MainMenu(int[], float[],int [], float []);
void ViewItems(int[], float[]);
void AddDeleteItem(int[], float[],int [], float [],int *, float *);
void ViewCart(int[], float[],int [], float []);
int main() 
{
	char name [20];

	int password, c=0;
	float sum=0;	
	int Inum [5] = {1,2,3,4,5};
	//char Iname[5] = {"Earphone","cover", "clock","keyboard", "mouse"};
	float Iprice[5] = {22.90,12.50,35.30,19.90,33.40};
	int addId [5]={0,0,0,0,0};	
	float addPrice[5]={0,0,0,0,0};

	printf("Login\nUsername: ");
	gets(name);
	printf("Password(digit only): ");
	scanf("%d",&password);

	printf("\n\nWelcome to PP Online Shopping, %s\n",name);
	MainMenu(Inum,Iprice,addId, addPrice);	
return 0;	

}
void MainMenu(int Inum[],float Iprice[],int addId[], float addPrice[])
{
	int input, c=0;
	float sum=0;
	
	do
	{
		printf("Enter 1 if you want to view avaible items.\n");
		printf("Enter 2 if you want to add or delete items in your cart.\n");
		printf("Enter 3 if you want to view your cart.\n");
		printf("Enter 4 if you want to confirm your transaction.\n");
		printf("Enter 0 to exit.\n");
	
		scanf("%d",&input);
		if(input == 1)
			ViewItems(Inum,Iprice);
		else if(input == 2)
			AddDeleteItem(Inum,Iprice,addId, addPrice, &c,&sum);
		else if(input == 3)
			ViewCart(Inum,Iprice,addId, addPrice);
	//	else if(input == 4)

	}while(input>=0 && input<=4);

}
void ViewItems(int Inum[],float Iprice[])
{
	int i;
	char n=' ';
	printf("Available items:\n");
	printf("Item Id          Item Name         Item Price \n");

	printf("%5d %10c Earphone %8c RM %.2lf\n",Inum[0],n,n,Iprice[0]);
	printf("%5d %10c Cover %11c RM %.2lf\n",Inum[1],n,n,Iprice[1]);
	printf("%5d %10c Clock %11c RM %.2lf\n",Inum[2],n,n,Iprice[2]);
	printf("%5d %10c Keyboard %8c RM %.2lf\n",Inum[3],n,n,Iprice[3]);
	printf("%5d %10c Mouse %11c RM %.2lf\n\n",Inum[4],n,n,Iprice[4]);
		
}

void AddDeleteItem(int Inum[],float Iprice[],int addId[], float addPrice[],int *c, float *sum)
{
	int addItem, deleteItem, ans,i, input;
	float tempdel=0;
//	printf("\nMy cart:\n");
	printf("Enter 1 if you wish to ADD item to your cart.\n");
	printf("Enter 2 if you wish to DELETE item in your cart\n");
	scanf("%d",&ans);
	
	if(ans==1)
	{
		printf("\nEnter the item Id you want to ADD into your cart: ");
		scanf("%d", &addItem);
	
		for(i=0;i<5;i++)
		{
			if(Inum[i]==addItem)
			{
				addId[*c]=Inum[i];
				addPrice[*c]=Iprice[i];
				*c++;
			}		
		}
		printf("Successful added into cart.\n\n");	
	}
	else
	{
		printf("\nEnter the item Id you want to DELETE in your cart: ");
		scanf("%d", &deleteItem);
	
		for(i=0;i<5;i++)
		{
			if(addId[i]==deleteItem)
			{
				addId[i]=0;
				addPrice[i]=0;
			}
		}
	printf("Successful deleted from cart.\n\n");		
	}
	
}
void ViewCart(int Inum[],float Iprice[],int addId[], float addPrice[])
{
	int i;
	char n=' ';
	printf("\nMy cart:\n");
	printf("Item Id      Item Price \n");
	for(i=0;i<5;i++)
	{
		if(addId[i]!=0)
		{
			printf("%5d %8c RM%.2lf\n",addId[i],n,addPrice[i]);
	
		}
	}
printf("\n");
		
}
