#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ejercicios = 3;
    int cal1, cal2, cal3;
    
    for (int i = 1; i <= ejercicios; i++) {
    	int calificacion;
    	
    	printf("[0-100]\n");
    	printf("Ingrese la calificacion del ejercicio %i: ", i);
    	scanf("%i", &calificacion);
    	
    	if (i == 1) cal1 = calificacion;
		else if (i == 2) cal2 = calificacion;
		else if (i == 3) cal3 = calificacion;
		
		system("cls");        
    }
    
    if ((cal1 + cal2 + cal3) == 300) {
    	printf("ERES UN BUEN PROSPECTO PARA APROBAR EL SEMESTRE");
	} else if ((cal1 + cal2) == 200 || (cal1 + cal3) == 200 || (cal2 + cal3) == 200) {
		printf("HAY QUE ESFORZARSE MAS");
	} else if (cal2 == 100 || cal3 == 100) {
		printf("UPS A ESTUDIAR MUCHO");
	} else if (cal1 == 100) {
		printf("ESTUDIAR MUCHISIMO");
	} else if ((cal1 + cal2 + cal3) == 0) {
		printf("REGRESA AL SEMESTRE ANTERIOR");
	}
    
    return 0;
}



