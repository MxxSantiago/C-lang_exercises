#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char states[][20] = { "Baja California", "Sonora", "Durango", "Chihuahua" }, highestTemperatureState[20];
	int statesQuantity = 4, months = 12, month, state;
	float temperatures[statesQuantity][months], highestTemperature;
	
	for (state = 0; state < statesQuantity; state++) {
		for (month = 0; month < months; month++) {
			printf("Enter the temperature of the month [%i] of the state of %s: ", month + 1, states[state]);
			scanf("%f", &temperatures[state][month]);
			system("cls");
		}
	}
	
	for (state = 0; state < statesQuantity; state++) {
		float annualAverageTemperature = 0;
		
		for (month = 0; month < months; month++)  {
			annualAverageTemperature += temperatures[state][month];
		}
		
		annualAverageTemperature /= months;
		
		if (annualAverageTemperature > highestTemperature) {
			highestTemperature = annualAverageTemperature;
			strcpy(highestTemperatureState, states[state]);
		}
		
		printf("%s annual average temperature: %.1f\n", states[state], annualAverageTemperature);
	}
	
	printf("\n");
	
	for (month = 0; month < months; month++) {
		float monthlyAverageTemperature = 0;
		
		for (state = 0; state < statesQuantity; state++) {
			monthlyAverageTemperature += temperatures[state][month];
		}
		
		monthlyAverageTemperature /= statesQuantity;
		
		printf("Average temperature of the %i states on month [%i]: %.1f\n", statesQuantity, month + 1, monthlyAverageTemperature);
	}
	
	printf("\n(%s was the state with the highest average temperature, with an average of [%.1f])\n", highestTemperatureState, highestTemperature);
	
	return 0;
}
