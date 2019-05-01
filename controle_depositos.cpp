#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

/* 	PROGRAMA GERENCIA SOLICITAÇOES DE DEPOSITOS
	PARA CADA DEPOSITO O USUARIO INFORMA O BANCO, LOJA DEPOSITO, DATA E VALOR DEPOSITADO.
	
	(1) INSERIR DEPÓSITO;
	(2) PESQISAR POR LOJA;
	(3) PESQUISAR POR MÊS;
	(4) LISTAR DEPOSITOS;
	(5) SAIR;
	
*/

void cabecalho();
void inserir();
void listar();
void pesquisar();


typedef struct data  DATA;
typedef struct dados DADOS;

struct data {
				int dia;
				int mes;
				int ano;	
};
	    	
struct dados{
				char 	banco [30];
				char 	nome_cliente[50];
				char 	loja[20];
				float 	valor;
				DATA	data_deposito; 	
};

main(){
	setlocale(LC_ALL,"Portuguese");
inicio:
	int opcao;

	
	do{
		cabecalho();
		
		printf(" \n 1 - INSERIR DEPOSITO \n");
		printf(" \n 2 - LISTAR \n");
		printf(" \n 3 - PESQUISAR POR LOJA \n");
		printf(" \n 4 - SAIR \n");
		printf(" \n Escolha uma opção: ");		
		scanf("%d",&opcao);		
		
		switch(opcao){
			
			case 1:				
				inserir();
				break;	
						
			case 2:
				listar();
				break;	
							
			case 3:
				pesquisar();
				break;	
											
            case 4:
            	cabecalho();
     			printf("\n\n DESENVOLVIDO POR: RODRIGO RABELO \n\n");
     			getch();
				break;	
						
		default:
				cabecalho();
				printf("\n Opção inválida\n\n");
				getch();
				return 0;
				break;			
								
		}// end switch
		
	}while(opcao!= 4);	
	
	
}// end main

void cabecalho(){
		
		system("cls");
		printf("--------------------------------------");
		printf("\n CONTROLE DE DEPOSITO\n");
		printf("--------------------------------------\n");
	
}// end cabecalho

void inserir(){
	
		FILE		*arquivo;
		DADOS		ctt;
		arquivo	=	fopen("controle.txt","a");
		
		if(arquivo == NULL){
			printf("Problemas na abertura do arquivo!\n");
			
		}//end if
		else{
			
			do{
				cabecalho();
				
				fflush(stdin);
				printf("\n");
				printf(" Digite a loja da venda: ");
				gets(ctt.loja);
				printf("\n");				
				
				fflush(stdin);
				printf(" Digite o Banco: ");
				gets(ctt.banco);
				printf("\n");
				
				fflush(stdin);
				printf(" Digite a valor do depósito: ");
				scanf("%f",&ctt.valor);
				printf("\n");
				
				fflush(stdin);
				printf(" Digite o dia do depósito: ");
				scanf("%d",&ctt.data_deposito.dia);
				printf("\n");
				
				fflush(stdin);
				printf(" Digite o mês do depósito: ");
				scanf("%d",&ctt.data_deposito.mes);
				printf("\n");
				
				fflush(stdin);
				printf(" Digite o ano do depósito: ");
				scanf("%d",&ctt.data_deposito.ano);
				printf("\n");
				
							
			
				printf("\n");				
				
				fwrite(&ctt,sizeof(DADOS),1,arquivo);
				
				printf("\n\n Deseja continuar(s/n)? ");
				
							
				
			}while(getche() =='s');
			fclose(arquivo);
			
		}//end else inserir
	
}// end inserir

void listar(){
		
		FILE		*arquivo;
		DADOS 	 	ctt;
		arquivo 	= fopen("controle.txt","r");
		
		cabecalho();
		
		if(arquivo==NULL){
			printf("Problemas na abertura do arquivo!\n");
		}//end if
		
		else{
			while(fread(&ctt,sizeof(DADOS),1,arquivo)==1){
				
				printf("\n");
				
				printf("LOJA: %s\n",ctt.loja);
				printf("\n");
				printf("BANCO: %s\n",ctt.banco);
				printf("\n");
				printf("VALOR: %4.2f \n",ctt.valor);
				printf("\n");
				printf("DATA: %d/%d/%d\n",ctt.data_deposito.dia,ctt.data_deposito.mes,ctt.data_deposito.ano);
				printf("--------------------------------------\n\n");
				
			} // end while
				
		}//end else
		
			fclose(arquivo);
			getch();	
}//end listar

void pesquisar(){
	
		FILE		*arquivo;
		DADOS 		 ctt;
		char 		 loja[30];	
			
		arquivo = fopen("controle.txt","r");
		
	if(arquivo==NULL){
		printf(" Problema na abertura do arquivo\n");
		system("pause");
	}//end if
	
	else{
		cabecalho();
		
		fflush(stdin);
		printf("\nDigite a loja a pesquisar: ");
		gets(loja);
		printf("\n\n");
		
		while(fread(&ctt,sizeof(DADOS),1,arquivo)==1){
			if(strcmp(loja,ctt.loja)==0){
				
				
			
				printf("LOJA: %s\n",ctt.loja);
				printf("\n");
				printf("BANCO: %s\n",ctt.banco);
				printf("\n");
				printf("VALOR: %4.2f\n",ctt.valor);
				printf("\n");
				printf("DATA: %d/%d/%d\n",ctt.data_deposito.dia,ctt.data_deposito.mes,ctt.data_deposito.ano);
			
				printf("--------------------------------------\n\n");				
				
			}//end if
			
		}//end while
	}//end else
	
	fclose(arquivo);
	getch();
	
}//end pesquisar


