#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _produto{
	char nome[30], data_fab[12], data_val[12] ;
	double val_venda;
	
}Produto;

typedef struct _compra{
	Produto produtos[30];
	double total;
}Compra;

typedef struct _cartao{
	int numero;
	Compra compras[20];
	double total_compras;
}Cartao;

typedef struct _cheque{
	int nCheque[20];
	int quantCheque; //quantidade que a pessoa usou o cheque	
}Cheque;

typedef struct _cliente{
	char nome[30], cpf[12], telefone[17], endereco[50];
	int dinheiro;
	Cartao cartao;
	Cheque cheque;
}Cliente;

typedef struct _venda{
    Compra venda;
    Cliente cliente;
    int cartao;
}Venda;

typedef struct _estoque{
	Produto produto;
	int qtd_estoque;
	double val_aquisicao;
	char fornecedor[30];
}Estoque;

int cadastrar_cliente(Cliente clientes[], int contclie){//cadastro basico dos clientes
   	int cont=0,aux;
    printf("Digite seu nome :\n");
     __fpurge(stdin);
    fgets(clientes[contclie].nome,30,stdin);
  
    do{//testa se tem 11 digitos o CPF
    	__fpurge(stdin); 
    	printf("Digite o cpf do cleinte:\n");
    	fgets(clientes[contclie].cpf,12,stdin);
    	aux=strlen((clientes[contclie].cpf));
    	
    }while(aux!=11);

    int i;
    for(i=0;i<contclie;i++){
    	if(strcmp(clientes[contclie].cpf, clientes[i].cpf)==0){//verifica se não tem um cpf igual cadastrado
    		printf("cpf já cadastrado\n");
    		cont++;
    		sleep(2);
    		return contclie;
    		
    	}
    }
    if(cont==0){
    	__fpurge(stdin);
    	printf("Digite o telefone do cleiente:\n");
    	fgets(clientes[contclie].telefone,17,stdin);
    	__fpurge(stdin);
    	printf("Digite o endereco do cliente:\n");
    	fgets(clientes[contclie].endereco,50,stdin);
    	__fpurge(stdin);
    	printf("Digite o numero do cartao:\n");
    	scanf("%d",&clientes[contclie].cartao.numero);

     	contclie++;
    	return contclie;
	}
 }
int cadastrar_produto(Estoque estoque[], int contpro){//cadastro das informações basicas do produto
    int cont=0,i;
    printf("Dite o nome do produto :\n");
     __fpurge(stdin);
    fgets(estoque[contpro].produto.nome,30,stdin);
     for(i=0;i<contpro;i++){
     	if(strcmp(estoque[contpro].produto.nome, estoque[i].produto.nome)==0){//verificar se o nome do produto ja n esta cadastrado
     		printf("produto já cadastrado\n");
     		cont++;
     		sleep(2);
     		return contpro;
     	}
     }
     if(cont==0){
    	printf("Digite a data de fabricação do produto:\n");
    	fgets(estoque[contpro].produto.data_fab,12,stdin);
    	__fpurge(stdin);
   	 	printf("Digite a data de validade do produto:\n");
    	fgets(estoque[contpro].produto.data_val,12,stdin);
   	 	__fpurge(stdin);
    	printf("Valor de aquisacao do produto:\n");
    	scanf("%lf",&estoque[contpro].val_aquisicao);
    	do{
    		printf("O valor de venda:\n");
    		scanf("%lf",&estoque[contpro].produto.val_venda);
    	}while(estoque[contpro].produto.val_venda<=0);
		__fpurge(stdin);
		printf("Digite o fornecedor :\n");
    	fgets(estoque[contpro].fornecedor,30,stdin);
    	printf("Digite a quantidade do produto no estoque:\n");
    	scanf("%d",&estoque[contpro].qtd_estoque);
     	contpro++;
     	return contpro;
 	}
 }
int somarprod(Estoque estoque[],Cliente clientes[],double *total,int contpro){//adiciona produtos ao carrinho
	char nomepro[20];
	int cont=0,i;
	int comprado;
	double venda;
	printf("Digite qual o nome do produto a ser vendido:\n");
    __fpurge(stdin);
    fgets(nomepro,20,stdin);
    for(i=0;i<=contpro;i++){
    	if(strcmp(estoque[i].produto.nome, nomepro)==0){//pesquisa de produto
    		printf("Nome: %s",estoque[i].produto.nome);
    		printf("Valor : %.2lf\n",estoque[i].produto.val_venda);
    		printf("Qual a quantidade que sera comprada:\n");
    		scanf("%d",&comprado);
    		printf("%d\n",estoque[i].qtd_estoque);
    		cont++;
    		if(estoque[i].qtd_estoque>=comprado){//verifica se tem produtos no estoque
    			estoque[i].qtd_estoque-=comprado;
    			printf("%d\n",estoque[i].qtd_estoque);
    			venda=comprado*estoque[i].produto.val_venda;
    			*total+=venda;
    			return cont;

    		}else{
    			printf("Quantidade invalida ou menor que a quantidade do estoque\n");
    			sleep(2); 
    			break;
    		}
    	}
    }
    if(cont==0){
    	printf("Produto não encontado\n");
    	sleep(2);
    }
}

	
void cadastrar_venda(Estoque estoque[] ,Cliente clientes[],int contpro,int contclie){//cadastra vendas
    int i,achou=0,comprado,x,numche,S,cont=0;
    char cpf [12]; 
    double venda,totalcomp=0 , dinheiro , troco;
    double *total = &totalcomp;
    
    do{
        memset(cpf, 0, sizeof(cpf));
        printf("Digite o Cpf do cliente ou 0 para sair:\n");
        __fpurge(stdin);
        fgets(cpf,12,stdin);
        for(i=0;i<=contclie;i++){
            if(strcmp(clientes[i].cpf ,cpf)==0){//pesquisa o cliente pelo cpf pra fazer a compra
                achou=1;
                printf("nome: %s",clientes[i].nome);
                printf("numero do cartão:%d\n",clientes[i].cartao.numero);
                printf("-----------------------------------\n");
                sleep(2);
                do{ system("clear");
                	printf("Total da compra até o momento : %.2lf\n1 : Adicionar mais produtos a compra:\n0 : Fechar carrinho\n",totalcomp);
                	scanf("%d",&x);
                	switch(x){
                		case 1:
                			cont=somarprod(estoque,clientes,total,contpro);//chama a funçao de adiciona produtos no carrinho
                			break;
                		case 0:
                			break;
                		default:
                			printf("Opcao invalida !!!!\n");
                			break;
                	}
                }while(x!=0);
                if(cont!=0){
                	printf("%d\n", cont);
                	system("clear");
              		printf("Digite 1 se o cliente vai comprar com o cartao\n");
					printf("Digite 2 se o cliente vai comprar com dinheiro\n");
					printf("Digite 3 se o cliente vai comprar com o cheque\n");
					__fpurge(stdin);
					scanf("%d",&S);
					if(S==1){
						clientes[i].cartao.total_compras+=totalcomp;//adiciona total de compras ao cartão
					}else if (S==2){
						for(;;){
						printf("total da compra:%.2lf\n",totalcomp);
						printf("Digite o valor pago em dinheiro:\n");
						scanf("%lf",&dinheiro);
							if(dinheiro>totalcomp){
								troco=dinheiro-totalcomp;
								printf("O troco vai ser: %.2lf\n",troco);
								sleep(2); 
								break;
							}	
						}			
					}else if(S==3){
						printf("Digite o numero do cheque sem caracteres\n");
						scanf("%d",&clientes[i].cheque.nCheque[clientes[i].cheque.quantCheque]);//salva o numero do cheque
						clientes[i].cheque.quantCheque++;//salva quantas vezes a pessoa usou cheque
						break;
					}
				}
			}
    	}
        if(achou == 0){
            printf("Cliente nao encontrado\n");
        	sleep(2);
        }	 
    }while(strcmp(cpf, "0\n") != 0 && achou==0);
    return;
}
void buscar_clientecpf(Cliente clientes[] ,int contclie){//busca cliente por cpf
    int i,achou;
    char cpf [12];
    do{
        memset(cpf, 0, sizeof(cpf));
        printf("Digite o Cpf do cliente ou 0 para sair:\n");
        __fpurge(stdin);
        fgets(cpf,12,stdin);
        achou=0;
        for(i=0;i<=contclie;i++){
            if(strcmp(clientes[i].cpf ,cpf)==0){//busca cliente cliente pelo cpf
                achou=1;
                printf("nome: %s",clientes[i].nome);
                printf("cpf:%s\n",clientes[i].cpf);
                printf("telefone:%s",clientes[i].telefone);
                printf("numero:%d\n",clientes[i].cartao.numero);
                printf("-----------------------------------\n");
                break;

            }
        }
        if(achou == 0)
            printf("Cliente nao encontrado\n");
        sleep(3); 
    }while(strcmp(cpf, "0\n") != 0 && achou==0);

}
void listar_produto(Estoque estoque[], int contpro){//lista todos os produtos cadastrados
    int i;
    if(contpro==0)
    	printf("Sem produtos cadastrados\n");
    for(i=0;i<contpro;i++){
    	printf("Nome: %s",estoque[i].produto.nome);
   	 	printf("Data de validade: %s",estoque[i].produto.data_val);
    	printf("Data de fabricacao: %s",estoque[i].produto.data_fab);
    	printf("Valor venda: %.2lf\n",estoque[i].produto.val_venda);
    	printf("Forcedor: %s",estoque[i].fornecedor);
    	printf("Quantidade de estoque :%d\n",estoque[i].qtd_estoque);
    	printf("Valor de aquisacao do produto :%.2lf\n",estoque[i].val_aquisicao);
    	printf("-----------------------------------\n");
    }
    sleep(5); 
}
void adicionar_prod_estoque(Estoque estoque[],int contpro){//adiciona estoque dos produtos ja cadastrados 
    char nomepro[20];
    int i,naoachou,j;
    do{
        printf("Digite o nome o nome do produto :\n ");
         __fpurge(stdin);
        fgets(nomepro,20,stdin);
        naoachou=0;
        for(i=0;i<=contpro;i++){
            if(strcmp(estoque[i].produto.nome,nomepro)==0){
                naoachou=1;
                printf("Digite a quantidade de produto que vai ser adicionado no estoque:\n");
                scanf("%d",&j);
                estoque[i].qtd_estoque+=j;
            }
        }
        if(naoachou==0)
                printf("Produto nao encontra\n");
        sleep(2);     
    }while(strcmp(nomepro, "0\n") != 0 && naoachou==0);
}

void listar_prod_fornecedor(Estoque estoque[],int contpro){//lista todos produtos com o mesmo fornecedor
	char nomefor[30];
	int i,num=0;
    printf("Digite o nome do fornecedor:\n");
    __fpurge(stdin);
     fgets(nomefor,30,stdin);
     for(i=0;i<contpro;i++){
     	if(strcmp(estoque[i].fornecedor,nomefor)==0){
     		printf("Nome do Produto: %s\n",estoque[i].produto.nome);
 			num++;    
     	}
     }
     if(num==0)
     	printf("Não a produto deste forcedor ou Não a este fornecedor");
     sleep(5); 

}

void listar_prod_baixa(Estoque estoque[],int contpro){//lista todos produtos que estão em baixa
	int i ,num=0;
    printf("Lista de produtos com menos de 10 unidades no estoque:\n");
    for(i=0;i<contpro;i++){
    	if(estoque[i].qtd_estoque<10){
    		printf("Nome: %s",estoque[i].produto.nome);
    		printf("Quantidade de estoque :%d\n",estoque[i].qtd_estoque);
    		printf("-----------------------------------\n");
    		num++;
    	}
	}
    if(num==0)
    	printf("Não a produtos faltando\n");
    sleep(5); 
}

void listar_clientes(Cliente clientes[],int contclie){//lista todos clientes cadastrados
	int i;
	if(contclie==0)
    	printf("Sem clientes cadastrados\n");
	for(i=0;i<contclie;i++){
		printf("nome: %s\n",clientes[i].nome);
		printf("cpf:%s\n",clientes[i].cpf);
		printf("telefone:%s\n",clientes[i].telefone);
		printf("numero do cartão:%d\n\n",clientes[i].cartao.numero);
		printf("valor gasto em compras no cartão:%.2lf\n\n",clientes[i].cartao.total_compras);
		printf("quantidade de vezes que usou cheque:%d\n\n",clientes[i].cheque.quantCheque);
		printf("Endereço:%s",clientes[i].endereco);
		printf("-----------------------------------\n");
	}
	sleep(5); 
}

void buscar_produto(Estoque estoque[], int contpro){//busca produto pelo nome
    char nomepro[20];
    int vaisaber=0,i;
    printf("Digite o nome do produto para fazer a busca:\n");
    __fpurge(stdin);
    fgets(nomepro,20,stdin);
    for(i=0;i<=contpro;i++){
        if(strcmp(estoque[i].produto.nome, nomepro)==0){
     		printf("Nome: %s",estoque[i].produto.nome);
            printf("Data de validade: %s",estoque[i].produto.data_val);
            printf("Data de fabricacao: %s",estoque[i].produto.data_fab);
            printf("Valor venda: %.2lf\n",estoque[i].produto.val_venda);
            printf("Forcedor: %s",estoque[i].fornecedor);
            printf(" Quantidade de estoque :%d\n",estoque[i].qtd_estoque);
            printf("Valor de aquisacao do produto :%.2lf\n",estoque[i].val_aquisicao);
        	vaisaber++;
        }
    }	
    if(vaisaber==0)
       printf("Produto nao encontrado\n");
    sleep(5); 
}







int main(void){
	int opcao,i;
	Cliente clientes[10];
	int contclie;
	Estoque estoque[10];
	int contpro;

	do{
		
		system("clear");
		printf("\tMenu de Opções:\n");
		printf("1 - Cadastrar clientes, produtos ou venda:\n");
		printf("2 - Buscar cliente:\n");
		printf("3 - Buscar produto:\n");
		printf("4 - Adicionar produto no estoque:\n");
		printf("5 - Listar produtos:\n");
		printf("6 - Listar clientes:\n");
		printf("0 - Sair do sistema:\n");
		printf("\n--> ");
		scanf("%d", &opcao);
		printf("\n");
		switch(opcao){
			case 1:
				do{
					system("clear");
					printf("\tSubmenu de cadastro\n");
					printf("1 - Cadastrar cliente:\n");
					printf("2 - Cadastrar produto:\n");
					printf("3 - Cadastrar venda:\n");
					printf("0 - Voltar ao menu anterior\n");
					printf("\n--> ");
					scanf("%d", &opcao);
					printf("\n");
					switch(opcao){
						case 1:
							contclie=cadastrar_cliente(clientes,contclie);

							opcao = 0;
							break;
						case 2:
							contpro=cadastrar_produto(estoque,contpro);

							opcao = 0;
							break;
						case 3:
							cadastrar_venda(estoque,clientes,contpro,contclie);
							opcao = 0;
							break;
						case 0:
							break;
						default:
							printf("Opcao inválida\n\n");
							break;
					}
				}while(opcao != 0);
				opcao = 1;
				break;
			case 2:
				buscar_clientecpf(clientes, contclie);
				break;
			case 3:
				buscar_produto(estoque, contpro);
				break;
			case 4:
				adicionar_prod_estoque(estoque, contpro);
				break;
			case 5:
				do{
					system("clear");
					printf("\tSubmenu de produtos\n");
					printf("1 - Listar produtos por fornecedor:\n");
					printf("2 - Listar produtos em baixa no estoque:\n");
					printf("3 - Listar todos os produtos  estoque:\n");
					printf("0 - Voltar ao menu anterior\n");
					printf("\n--> ");
					scanf("%d", &opcao);
					printf("\n");
					switch(opcao){
						case 1:
							listar_prod_fornecedor(estoque,contpro);
							opcao = 0;
							break;
						case 2:
							listar_prod_baixa(estoque,contpro);
							opcao = 0;
							break;
                        case 3:
							listar_produto(estoque,contpro);
							opcao = 0;
							break;
						case 0:
							break;
						default:
							printf("Opcao inválida\n\n");
							break;
					}

				}while(opcao != 0);
				opcao = 5;
				break;
			case 6:
				listar_clientes(clientes,contclie);
				system("clear");
				break;
			case 0:
				break;
			default:
				printf("Opção inválida\n\n");
		}
	}while(opcao != 0);


	return 0;
}


