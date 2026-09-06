#include <stdio.h>
#include <math.h>

int main () {
	
	float result;
	float calcu1, calcu2;
	float sum = 0;
	float history[100];
	float firstNumber[100];
	float secondNumber[100];
	float memory = 0;
	
	char operation[100];
	
	int choice = 0;
	int again = 1;
	int count = 0;
	int decimal = 2;
	int settingsChoice;
	int pin;
	int correctPin = 12345;
	int attempts = 0, currentPin, newPin;
	int settingsAgain = 1; 
	int numerator, denominator;
	int memoryChoice;
	int unitChoice;
	
	
	printf ("-----PASSKEY TO THE CALCULATOR----\n");
	
	while (attempts < 3) {
		printf ("\nEnter the PIN: ");
		scanf("%d", &pin);
		
		if (pin == correctPin) {
			printf ("\nAccess granted!\n");
			break;
		}
		else {
			attempts++;
			printf ("\nIncorrect PIN!\n");
		}
	}
	
	if (attempts == 3) {
		printf ("\nToo many incorrect attempts. ");
		return 0;
	}
	
	while (choice != 18 && again == 1) {
	
	printf ("\nCALCULATOR");
	printf ("\n1. Addition");
	printf ("\n2. Subtraction");
	printf ("\n3. Multiplication");
	printf ("\n4. Division");
	printf ("\n5. Modulo");
	printf ("\n6. Power");
	printf ("\n7. Square Root");
	printf ("\n8. View History");
	printf ("\n9. Clear History");
	printf ("\n10. Show Calculation count");
	printf ("\n11. Show Average");
	printf ("\n12. Settings");
	printf ("\n13. Fraction");
	printf ("\n14. Percentage");
	printf ("\n15. Even or Odd");
	printf ("\n16. Memory");
	printf ("\n17. Unit Converter");
	printf ("\n18. Exit");
	
	printf ("\nEnter your choice: ");
	scanf ("%d",&choice);
	
	if (choice == 18) {
		printf ("\nCalculator closed");
		break;
	}
	if (choice == 8) {
		
		printf ("\nHISTORY");
		
		for (int i = 0; i < count; i++) {
		
		
		if (operation[i] == 'r') {
			printf ("sqrt%.2f = %.2f\n",
					firstNumber[i],
					history[i]);
		}
		else {
		
			printf ("%.2f %c %.2f = %.2f\n",
				firstNumber[i],
				operation[i],
				secondNumber[i],
				history[i]);
			}
		}
	}
	else if (choice == 9) {
		
		count = 0;
		printf ("\nHistory cleared!");	
	}
	else if (choice == 10) {
		printf ("\nTotal calculation: %d", count);
	}
	
	else if (choice == 11) {
		sum = 0;
		
		for (int i = 0; i < count; i++) {
			sum = sum + history[i];
		}
		
		if (count > 0) {
			printf ("\nAverage result: %.2f", sum / count);
		}
		else {
			printf ("\nNo calculations in history");
		}
	}
	else if (choice == 12) {
		
		settingsAgain = 1;
		
		while (settingsAgain == 1) {
		
		printf ("\nSETTINGS");
		printf ("\n1. Change Decimal Places");
		printf ("\n2. Change PIN");
		printf ("\n3. Back");
		
		printf ("\nEnter your choice: ");
		scanf("%d", &settingsChoice);
		
		if (settingsChoice == 1) {
			printf ("\nEnter decimal places: ");
			scanf("%d", &decimal);
			printf ("\nDecimal places changed!");
		}
		
		else if (settingsChoice == 2) {
			printf ("\nEnter current PIN: ");
			scanf("%d", &currentPin);
			
			if (currentPin == correctPin) {
				printf ("Enter the new PIN: ");
				scanf("%d", &newPin);
				
				correctPin == newPin;
				
				printf ("\nPIN changed succesfully!");
			}
			else {
				printf ("\nIncorrect current PIN!");
			}
		}
		else if (settingsChoice == 3) {
			settingsAgain = 0;
		}
		else {
			printf ("\nInvalid choice!");
		}
	}
}
	else if (choice == 13) {
		printf ("\nEnter numerator: ");
		scanf("%d", &numerator);
		
		printf("\nEnter the denominator: ");
		scanf("%d", &denominator);
		
		if (denominator !=0) {
			printf ("\nFraction = %d/%d", numerator, denominator);
			printf ("\nDecimal = %.*f", decimal, 
										(float)numerator / denominator);
		}
		else {
			printf ("\nCannot divide by zero.");
		}
	}
	
	else if (choice == 7) {
	
	
		printf ("\nEnter a value: ");
		scanf("%f", &calcu1);
		
		if (calcu1 >= 0) {
			result = sqrt(calcu1);
			printf("Result = %.*f", decimal, result);
			
			firstNumber[count] = calcu1;
			secondNumber[count] = 0;
			history[count] = result;
			operation[count] = 'r';
			count++;
			
		} else {
			printf ("Cannot find square root of a negative number.");
		}
	}
		else if (choice == 14) {
			printf ("\nEnter the number: ");
			scanf("%f", &calcu1);
			
			printf ("\nEnter the percentage: ");
			scanf("%f", &calcu2);
			
			result = (calcu1 * calcu2) / 100;
			
			printf ("\n%.2f%% of %.2f = %.*f",
											 calcu2, calcu1, decimal, result);			
		}
		
		else if (choice == 15) {
			printf ("\nEnter a number: ");
			scanf("%f", &calcu1);
			
			if ((int) calcu1 % 2 == 0) {
				printf ("\n%.0f is EVEN", calcu1);
			}
			else {
				printf ("\n%.0f is ODD", calcu1);
			}
		}
		
		else if (choice == 16) {
			printf ("\n------MEMORY-------\n");
			printf ("\n1. M+ Add to Memory");
			printf ("\n2. M- Subtract from Memory");
			printf ("\n3. MR Recall Memory");
			printf ("\n4. MC Clear Memory");
			
			printf ("\nEnter your choice: ");
			scanf ("%d", &memoryChoice);
			
			if (memoryChoice == 1) {

        printf ("\nEnter number to add: ");
        scanf ("%f", &calcu1);

        memory = memory + calcu1;

        printf ("\nMemory = %.2f", memory);
    }

    else if (memoryChoice == 2) {

        printf ("\nEnter number to subtract: ");
        scanf ("%f", &calcu1);

        memory = memory - calcu1;

        printf ("\nMemory = %.2f", memory);
    }

    else if (memoryChoice == 3) {

        printf ("\nMemory = %.2f", memory);
    }

    else if (memoryChoice == 4) {

        memory = 0;

        printf ("\nMemory cleared!");
    }

    else {
        printf ("\nInvalid memory choice!");
    }
}

	else if (choice == 18) {
		
		printf ("\n------UNIT CONVERTER-------");
		printf ("\n1. Celsius to Fahrenheit");
		printf ("\n2. Fahrenheit to Celsius");
		printf ("\n3. Kilometers to Miles");
		printf ("\n4. Miles to Kilometers");
		
		printf ("\nEnter your choice: ");
		scanf ("%d", &unitChoice);
		
		if (unitChoice == 1) {
			
			printf ("\nEnter Celsius: ");
			scanf ("%f", &calcu1);
			
			result = (calcu1 * 9/ 5) + 32;
			
			printf ("\nFahrenheit = %.*f", decimal, result);
		}
		
		else if (unitChoice == 2) {
			
			printf ("\nEnter Fahrenheit: ");
			printf ("%d", &calcu1);
			
			result ("calcu1 - 32") * 5/ 9;
			
			printf ("\nCelsius = %.*f", decimal, result);
		}
		
		else if (unitChoice == 3) {

        printf ("\nEnter Kilometers: ");
        scanf ("%f", &calcu1);

        result = calcu1 * 0.621371;

        printf ("\nMiles = %.*f", decimal, result);
    }

    else if (unitChoice == 4) {

        printf ("\nEnter Miles: ");
        scanf ("%f", &calcu1);

        result = calcu1 * 1.60934;

        printf ("\nKilometers = %.*f", decimal, result);
    }

    else {
        printf ("\nInvalid unit choice!");
    }
}	
		
	}
	
	else  {
	
	printf ("\nEnter the calcu1: ");
	scanf("%f", &calcu1); 
	
	printf ("Enter the calcu2: ");
	scanf("%f", &calcu2);
	
	
	switch (choice) {
		
		case  1:
			result = calcu1 + calcu2;
			printf ("Result = %.*f", decimal, result);
			
			firstNumber[count] = calcu1;
			secondNumber[count] = calcu2;
			history[count] = result;
			operation[count] = '+';
			count++;
			break;
		
		case  2:
			result = calcu1 - calcu2;
			printf ("Result = %.*f", decimal, result);
			
			firstNumber[count] = calcu1;
			secondNumber[count] = calcu2; 
			history[count] = result;
			operation[count] = '-';
			count++;
			break;
			
		case  3:
			result = calcu1 * calcu2;
			printf ("Result = %.*f", decimal, result);
			
			firstNumber[count] = calcu1;
			secondNumber[count] = calcu2;
			history[count] = result;
			operation[count]  = '*';
			count++;		
			break;
			
		case  4:
			if (calcu2 != 0) {
				result = calcu1 / calcu2;
				printf ("Result = %.*f", decimal, result);
				
				firstNumber[count] = calcu1;
				secondNumber[count] = calcu2;
				history[count] = result;
				operation[count] = '/';
				count++;
			} else {
				printf ("Cannot be divided by zero");
			}
			break;
						
		case 5:
			if (calcu2 !=0) {
				result = fmod(calcu1, calcu2);
				printf ("Result = %.*f", decimal, result);
				
				firstNumber[count] = calcu1;
				secondNumber[count] = calcu2;
				history[count] = result;
				operation[count] = '%';
				count++;
			} else {
				printf ("Cannot be modulo by zero");
			}
			break;
			
		case 6:
			result = pow(calcu1, calcu2);
			printf ("Result = %.*f", decimal, result);
			
			firstNumber[count] = calcu1;
			secondNumber[count] = calcu2;
			history[count] = result;
			operation[count] = '^';
			count++;
			break;	
			
		default:
			printf ("Invalid operator");	
			
	}
}
	printf ("\n\nDo you want to calculate again? ");
	printf ("\nEnter 1 if YES and Enter 0 if NO: ");
	scanf("%d", &again); 
}
	return 0;
}