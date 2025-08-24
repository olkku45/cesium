/*
A basic CLI calculator that supports the basic operations: 
addition, subtraction, multiplication, and division.
*/

#include <stdio.h>
#include <stdlib.h>

double add(double a, double b) {
	return a + b;
}

double subtract(double a, double b) {
	return a - b;
}

double multiply(double a, double b) {
	return a * b;
}

double divide(double a, double b) {
	if (b != 0) {
		return a / b;
	} else {
		printf("Division by zero error");
		return 0;
	}
}

int main() {
	char operation;
	double num1, num2;

	while (true) {
		printf("Enter the first number (or 0 to exit): \n");
		scanf("%lf", &num1);

		if (num1 == 0) {
			return 0;
		}

		// space required in scanf for this to execute on its own
		printf("Enter operation (+, -, *, /): \n");
		scanf(" %c", &operation);

		printf("Enter the second number: \n");
		scanf("%lf", &num2);

		switch (operation) {
			case '+':
				printf("Result: %.2lf\n", add(num1, num2));
				break;
			case '-':
				printf("Result: %.2lf\n", subtract(num1, num2));
				break;
			case '*':
				printf("Result: %.2lf\n", multiply(num1, num2));
				break;
			case '/':
				printf("Result: %.2lf\n", divide(num1, num2));
				break;
			default:
				printf("Invalid operation.\n");
		}
	}

	return 0;
}