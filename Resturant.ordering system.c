#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct MenuItem {
	char name[50];
	int price;
};


void displayMenu(struct MenuItem* menu, int size) {
	printf("----------------------------------------\n");
	for (int i = 0; i < size; i++) {
		printf("%d. %s \t   -/%d\n",  i + 1, menu[i].name, menu[i].price);
	}
	printf("----------------------------------------\n");
}


int getUserOrder() {
	int order;
	printf("\nWhat would you like to order : ");
	scanf("%d", &order);
	return order;
}


int askQuantity() {
	int quantity;
	printf("\nPlease enter the quantity of delivered meal: ");
	scanf("%d", &quantity);
	return quantity;
}


char askCalculateBill() {
	char calculateBill;
	printf("\nWant to calculate bill ? (y/n): ");
	scanf(" %c", &calculateBill);
	return (calculateBill == 'n' || calculateBill == 'N');
}


float calculateBill(struct MenuItem* menu, int* orders, int* quantities, int numOrders) {
	float totalBill = 0;
	for (int i = 0; i < numOrders; i++) {
		int orderIndex = orders[i] - 1;
		if (orderIndex >= 0 && orderIndex < 10) {
			float itemPrice = menu[orderIndex].price;
			int itemQuantity = quantities[i];
			totalBill += itemPrice * itemQuantity;
		}
	}
	return totalBill;
}



int main() {

	printf("\t====================================\n");
	printf("\t|      Welcome To Restaurant        |\n");
	printf("\t====================================\n");
	printf("\t\t\t|MENU|\n");
	printf("\t\t\t====\n\n");


	struct MenuItem menu[10] = {
		{"Kabab",           70},
		{"Tikka",           60},
		{"Chpati",        10},
		{"Naan",            25},
		{"Tea",             35},
		{"Karahi",        1000},
		{"Qourma",         980},
		{"Fish",           800},
		{"Finger Fish",   1000},
		{"Mutton",        1400}
	};


	int choices[10];
	int quantities[10];
	int numChoices = 0;

	do {
		displayMenu(menu, 10);
		int choice = getUserOrder();
		int quantity = askQuantity();


		choices[numChoices] = choice;
		quantities[numChoices] = quantity;
		numChoices++;


		int calculateBill= askCalculateBill ();
		if (calculateBill == 0) {
			break;
		}
	} while
	(numChoices < 10);
	


	float bill = calculateBill(menu, choices, quantities, numChoices);

	printf("\n\t\t\t ======");
	printf("\n\t\t\t| BILL |\n");
	printf("-----------------------------------------------------------------\n");
	printf("|Name|\t\t|Quantity|\t\t|Price|\t\t|Total| |\n");
	printf("-----------------------------------------------------------------\n");

	for(int i=0; i<numChoices; i++) {

		printf("%s\t\t %d\t\t\t%d\t\t%d\n", menu[choices[i]-1].name, quantities[i], menu[choices[i]-1].price, menu[choices[i]-1].price*quantities[i]);
		
	}

	printf("-----------------------------------------------------------------\n");
	printf("|\t\tYour Grand Total is: -/%.2f\t\t\t|\n", bill);
	printf("-----------------------------------------------------------------\n");

	return 0;
}
