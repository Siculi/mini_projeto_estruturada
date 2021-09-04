#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// Mini-Projeto da Cadeira de Programação Estruturada

int inicia_matrizes (char matriz[10][18]);
int print_lotacao (char matriz[10][18]);
int vefica_vagas (int vaga, char matriz[10][18]);
int quant_vagas ();
int indicador_de_vaga (int retorno, char matriz[10][18]);
int escolhe_vaga (int vaga, char matriz[10][18], int print);
int verifica_finalizacao (char matriz[10][18]);

int main()
{
	setlocale(LC_ALL,"Portuguese"); 
	
	int l, c, vaga, parar;	
	char fil, planta[10][18], retorno;
	
	inicia_matrizes(planta); 
	
	print_lotacao (planta);
			
	do{
		vaga = quant_vagas ();
		retorno = vefica_vagas (vaga, planta); 	
		indicador_de_vaga (retorno, planta);
		
		if(retorno=='S')
		{
			escolhe_vaga (vaga, planta, print_lotacao);
		}
		
		parar = verifica_finalizacao (planta);
				
	}while(parar!=0);
	
	printf("\n--------------------------------------------------------------------------------");
	printf("\n\n\t\t\t\tSessão encerrada.\n\n");
	system("pause");
		
	return 0;
}

int inicia_matrizes (char matriz[10][18])
{
	int l, c;		
	
	for(l=0;l<10;l++)
		{
			for(c=0;c<18;c++)
				{
					matriz[l][c]= 'L';					
				}			
		}
	
	return 0;
}

int print_lotacao (char matriz[10][18])
{
	int c, l;
	
	char fil = 'J';
					
	printf("\n");
	for(l=0;l<10;l++)
		{
			if(l==0)
				{
					printf("   __.-.__\n  '-._''7'\n   /'.-c\t\t   --- Nuovo Cinema Paradiso ---\n  |  /T\n  _)_/LI");
					printf("\n\n");
					printf("     01  02  03  04  05  06    07  08  09  10  11  12    13  14  15  16  17  18 \n\n");
				}
			printf("%c - ", fil); fil = fil - 1;
			
			for(c=0;c<18;c++)
				{
					if(c-1==5 || c==12){printf("  ");}
					printf("[%c] ", matriz[l][c]);								
				}			
			printf("\n");
		}
	
	printf("\n\n\n\n\n\n\t[=============================T=E=L=A=============================]");
	printf("\n\n\n  [L] - Livre     ");
	printf("[O] - Ocupado     ");
	printf("[ ] - Vazio devido ao distanciamento social\n");
	
	return 0;
}

int vefica_vagas (int vaga, char matriz[10][18])
{
	char resp; resp = 'N';
	int cont, x, l, c; 
	x=vaga; cont = 0;
	
	for(l=0;l<10;l++)
		{
			for(c=0;c<18;c++)
				{
					if(matriz[l][c]=='L')
						{
							cont++;
							if((cont/3)==x) 
								{
									resp ='S';																											
								}
						}									
				}
						
		}	
	
	/* 
		Essa divisão por 3 da variável "cont" se dá por que na melhor distribuição possivel, 
		para cada 1 vaga ocupada precisamos de no mínimo 3 livres.
		Por exemplo, um único cliente não podemos pedir as 180 vagas totais da sala, mas sim apenas 60.
	*/
	return resp;		
}

int quant_vagas ()
{
	int vaga;
	
	printf("\n--------------------------------------------------------------------------------");
	printf("\nQuantidade de poltronas que o clinte deseja: ");
	scanf("%i", &vaga);system("cls");
	
	return vaga;
}

int indicador_de_vaga (int retorno, char matriz[10][18])
{
	if(retorno=='S')
		{
			print_lotacao (matriz);
		}else{printf("\n\t\t!!! Ateção !!! Não há poltronas suficientes\n");}
}

int escolhe_vaga (int vaga, char matriz[10][18], int print)
{
	char letra;
	int numero, letra_n, cont;
	int l,c, a, b, cont_v;
	
	cont_v = cont = 0;
		
	do{
		
		do{
			
			printf("\n--------------------------------------------------------------------------------");
			printf("\n\t\t\t\tEscolha as poltronas\n");
			printf("\nLetra: ");
			scanf(" %c", &letra);
			printf("Número: ");
			scanf("%i", &numero);
		
			if(letra=='j'){letra_n=0;} if(letra=='i'){letra_n=1;} if(letra=='h'){letra_n=2;} if(letra=='g'){letra_n=3;} 
			if(letra=='f'){letra_n=4;} if(letra=='e'){letra_n=5;} if(letra=='d'){letra_n=6;} if(letra=='c'){letra_n=7;} 
			if(letra=='b'){letra_n=8;} if(letra=='a'){letra_n=9;} 
		
			if(matriz[letra_n][numero-1]!='L'){printf("\nEsta poltrona já esta ocupada ou integra o distanciamento social.\n");}
		
		}while(matriz[letra_n][numero-1]!='L');
		
		if(numero==6 || numero==12 || numero==18)
			{
				matriz[letra_n][numero-1] = 'O'; 
				matriz[letra_n][numero-2] = ' '; 
				matriz[letra_n][numero-3] = ' ';
			}else
				{
					if(numero==1 || numero==7 || numero==13)
						{
							matriz[letra_n][numero-1] = 'O'; 
							matriz[letra_n][numero] = ' '; 
							matriz[letra_n][numero+1] = ' ';	
						}else
							{
								if(numero==2 || numero==8 || numero==14)
									{
										matriz[letra_n][numero-2] = ' ';
										matriz[letra_n][numero-1] = 'O'; 
										matriz[letra_n][numero] = ' '; 
										matriz[letra_n][numero+1] = ' ';
									}else
										{
											if(numero==5 || numero==11 || numero==17)
												{
														matriz[letra_n][numero-3] = ' ';
														matriz[letra_n][numero-2] = ' ';
														matriz[letra_n][numero-1] = 'O'; 
														matriz[letra_n][numero] = ' '; 															
												}else
													{
														matriz[letra_n][numero-1] = 'O';
														matriz[letra_n][numero-2] = ' '; 
														matriz[letra_n][numero-3] = ' ';
														matriz[letra_n][numero] = ' '; 
														matriz[letra_n][numero+1] = ' ';
													}
										}
							}
				}		
		
		system("cls");
		
		print_lotacao(matriz);
						
		cont++;
	
	cont_v = 0;
		
	for(a=0;a<10;a++)
		{
			for(b=0;b<18;b++)
				{
					if(matriz[a][b]=='L')
						{
							cont_v++;					
						}									
				}
						
		}
			
	}while(cont<vaga && cont_v!=0);
	
}

int verifica_finalizacao (char matriz[10][18])
{
	int cont, l, c, continua; 
	
	cont = continua = 0;
	
	for(l=0;l<10;l++)
		{
			for(c=0;c<18;c++)
				{
					if(matriz[l][c]=='L')
						{
							cont++;					
						}									
				}
						
		}
	
	if(cont>0){continua=1;}	
	
	printf("\n--------------------------------------------------------------------------------\n");
	printf("Dado o distanciamento existem ainda %i poltronas para serem ocupadas.\n\n", cont/3);
	printf("Para encerrar a sessão digite 0. Para continuar digite qualquer outro número: ");
	scanf("%i", &continua);	
	
	return continua;
}
