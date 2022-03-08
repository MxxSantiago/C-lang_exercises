#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {	
	char opcion[10];
	char key[] = "FIN";
	
	char pregunta1[] = "Cual es la funcion que se utiliza para copiar cadenas de caracteres?";
	char pregunta2[] = "Cual es la funcion que se utiliza para comparar cadenas de caracteres sin considerar diferentes las mayusculas y las minusculas?";
	char pregunta3[] = "Cual es la funcion que se utiliza para concatenar cadenas de caracteres?";
	char pregunta4[] = "Cual es la funcion que se utiliza para regresar la longitud de una cadena de caracteres?";

    char respuestaCorrecta1[] = "strcpy";
    char respuestaCorrecta2[] = "strcmp";
    char respuestaCorrecta3[] = "strcat";
    char respuestaCorrecta4[] = "strlen";
    
    char msjRespIncorrecta[] = "Respuesta incorrecta, vuelve a intentarlo";
    char msjIntentosAgotados[] = "Has agotado la cantidad de intentos posibles, se te redirigira a la siguiente pregunta";

	while (strcmp(key, opcion) != 0) {
	        int respCorrectas = 0;
			char nombre[20];
			
			printf("Ingresa tu nombre: ");
			gets(nombre);
			
			system("cls");
			
			//********************************************************************************************************
			
			int intentos1 = 0;
			char respuestaUsuario1[13];
			
			while (intentos1 < 4) {
			    intentos1++;
			    
			    if (intentos1 == 3) {
			        printf("%s", msjIntentosAgotados);
			        intentos1++;
			        
			        system("pause");
			    } else {
    			    printf("%s\n\nRespuesta: ", pregunta1);
    			    gets(respuestaUsuario1);
    			    
    			    if (strcmp(respuestaCorrecta1, respuestaUsuario1) != 0) {
    			    	system("cls");
    			        printf("%s\n", msjRespIncorrecta);
    			        system("pause");
    			    } else if (strcmp(respuestaCorrecta1, respuestaUsuario1) == 0) {
    			        intentos1 = 4;
    			        respCorrectas += 1;
    			    }
			    }
			    
                system("cls");
			}
			
			//********************************************************************************************************
			
			int intentos2 = 0;
			char respuestaUsuario2[10];
			
			while (intentos2 < 4) {
			    intentos2++;
			    
			    if (intentos2 == 3) {
			        printf("%s", msjIntentosAgotados);
			        intentos2++;
			        
                    system("pause");
			    } else {
    			    printf("%s\n\nRespuesta: ", pregunta2);
    			    gets(respuestaUsuario2);
    			    
    			    if (strcmp(respuestaCorrecta2, respuestaUsuario2) != 0) {
    			    	system("cls");
    			        printf("%s\n", msjRespIncorrecta);
    			        system("pause");
    			    } else if (strcmp(respuestaCorrecta2, respuestaUsuario2) == 0) {
    			        intentos2 = 4;
    			        respCorrectas += 1;
    			    }
			    }
			    
                system("cls");
			}
			
			//********************************************************************************************************
			
			int intentos3 = 0;
			char respuestaUsuario3[6];
			
			while (intentos3 < 4) {
			    intentos3++;
			    
			    if (intentos3 == 3) {
			        printf("%s", msjIntentosAgotados);
			        intentos3++;
			        
                    system("pause");
			    } else {
    			    printf("%s\n\nRespuesta: ", pregunta3);
    			    gets(respuestaUsuario3);
    			    
    			    if (strcmp(respuestaCorrecta3, respuestaUsuario3) != 0) {
    			    	system("cls");
    			        printf("%s\n", msjRespIncorrecta);
    			        system("pause");
    			    } else if (strcmp(respuestaCorrecta3, respuestaUsuario3) == 0) {
    			        intentos3 = 4;
    			        respCorrectas += 1;
    			    }
			    }
			    
                system("cls");
			}
			
            //********************************************************************************************************
			
			int intentos4 = 0;
			char respuestaUsuario4[16];
			
			while (intentos4 < 4) {
			    intentos4++;
			    
			    if (intentos4 == 3) {
			        printf("%s", msjIntentosAgotados);
			        intentos4++;
			        
                    system("pause");
			    } else {
    			    printf("%s\n\nRespuesta: ", pregunta4);
    			    gets(respuestaUsuario4);
    			    
    			    if (strcmp(respuestaCorrecta4, respuestaUsuario4) != 0) {
    			    	system("cls");
    			        printf("%s\n", msjRespIncorrecta);
                        system("pause");
    			    } else if (strcmp(respuestaCorrecta4, respuestaUsuario4) == 0) {
    			        intentos4 = 4;
    			        respCorrectas += 1;
    			    }
			    }
			    
                system("cls");
			}
			
			//********************************************************************************************************
			char resultado[20];
			
			if (respCorrectas == 4) {
				char resultado[] = "| EXCELENTE";
				printf("%s\n", strcat(nombre, resultado));	
			}
			else if (respCorrectas == 3) {
				char resultado[] = "| MUY BIEN";
				printf("%s\n", strcat(nombre, resultado));
			}   
			else if (respCorrectas == 2) {
				char resultado[] = "| BIEN";
				printf("%s\n", strcat(nombre, resultado));
			}   
			else if (respCorrectas == 1) {
				char resultado[] = "| PUEDES MEJORAR";
				printf("%s\n", strcat(nombre, resultado));
			}
			else if (respCorrectas == 0) {
				char resultado[] = "| REPASA EL TEMA NO LO DOMINAS";
				printf("%s\n", strcat(nombre, resultado));
			};    
			
			system("pause");
			
			system("cls");
			printf("Ingrese cualquier caracter para continuar, para salir del programa ingrese 'FIN': ");
			gets(opcion);
			system("cls");
	}
	
	system("pause");
}

