#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 10
struct casas
{
 	char rua[50];
	char bairro[50];
	char nome_responsavel[50];
	int foco_dengue;
 	int cod_responsavel;
	int numero;
	
};

int posicao=0;
casas foco[MAX];
int opcao;

int menu(){

	printf("------------------------MENU-------------------------");
	printf("\n\n1 - Inserir Casa");
	printf("\n\n2 - Listar Casa com Foco de Dengue");
	printf("\n\n3 - Ordenar Casas pelo Bairro");
	printf("\n\n4 - Listar Bairros com Focos de Mosquitos");
	printf("\n\n5 - Sair\n\n");

	scanf("%d",&opcao);
	fflush(stdin);
	
	return opcao;

}

void inserir() {
	
	casas casa_revistada;
	
	printf("\n\nEntre com o Codigo do Resposavel: ");
 	scanf("%d", &casa_revistada.cod_responsavel);
 	
	fflush(stdin);

 	printf("\n\nEntre com o nome do Resposavel: ");
 	gets(casa_revistada.nome_responsavel);
 
 	fflush(stdin);
 
 	printf("\n\nEntre com a Rua do Responsavel: ");
 	gets(casa_revistada.rua);

	fflush(stdin);
 	
 	printf("\n\nEntre com o numero da casa: ");
 	scanf("%d", &casa_revistada.numero);
 	
	fflush(stdin);
 	
	printf("\n\nEntre com o Bairro: ");
 	gets(casa_revistada.bairro);

 	fflush(stdin);
 	
	printf("\n\nDigite 0 para casa sem Foco e 1 para casa com Foco: ");
 	scanf("%d", &casa_revistada.foco_dengue);

	fflush(stdin);
	
	foco[posicao] = casa_revistada;
	
	posicao++;
	
	system("cls");

	printf("Inserido com Sucesso\n\n"); 

}
	
void listar_foco(){

	for(int i=0; i<posicao; i++){
 		

 		if (foco[i].foco_dengue == 1) {
 	
 		
 			printf("Codigo do Responsavel : %d\n", foco[i].cod_responsavel);
 			printf("Nome do Resposavel : %s\n", foco[i].nome_responsavel);
 			printf("Rua do Responsavel : %s\n", foco[i].rua);
 			printf("Numero : %d\n", foco[i].numero);
 			printf("Bairro : %s\n", foco[i].bairro);
 			printf("Foco : %d\n\n\n", foco[i].foco_dengue);
	
		} 		
 	}
}

void ordenar(){
	
	casas aux[1];
	
	for(int x=0;x<posicao;x++){
		
		for(int y=x;y<posicao;y++){
			
			if(strcmp(foco[x].bairro,foco[y].bairro)> 0){
				
				aux[0]=foco[x];
				foco[x]=foco[y];
				foco[y]=aux[0];
				
			}
		}
	}	
}

void listar_bairro(){
	
	ordenar();
		
	int verifica=1;
			
	for(int y=0;y<posicao;y++){
			
		if(strcmp(foco[y].bairro,foco[y+1].bairro)==0 && foco[y].foco_dengue == 1){

			verifica++;
				
		}else{
				
			if(foco[y].foco_dengue == 1){
			
				fflush(stdin);
				printf("%s ",foco[y].bairro);
				fflush(stdin);
				printf("%d\n",verifica);
				verifica=1;
				
			}
		}
	}
}

int main(){

	
	posicao = 0;
	
	while(true){
	
	opcao = menu();  
	  	
		switch (opcao) {
			
    		case 1 :
         	system("cls");
          		inserir(); 
	   			break;
	   		
        	case 2 :
        	 	
        		system("cls");
          		listar_foco();
				break;
				
        	case 3 : 
         		system("cls");
				ordenar();
				printf("Ordenado com Sucesso\n");
          		break;  
          	
	  		case 4 : 
	  	 		system("cls");
		    	listar_bairro();
 				break;
 			
	  		case 5 : 
	  	 
		    	exit(0);
 				break;    
			     
			default: 
		  		
				system("cls");
          		printf("\noperacao invalida\n\n"); 
				break;
 	
		}
	 }
 	
 	system("PAUSE");
	return(0);
	
}


