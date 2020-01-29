#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct{
    char nome[max];
    int matricula[max];
    char cpf[15];
    int codigo;
    float np1,np2,media;

}aluno;
typedef struct{
    int codigo;
    int qtdDeAlunos;
    aluno alunox [30]; //quantidade de aluno maximo em cada turma
    char componente[max];
    int fase;
    char horario[max];
}turma;

//validor CPF
 int validadorCPF(char cpf[]){
	int icpf[12];
	int i, somador=0, digito1, result1, result2, digito2, valor;
	for(i=0; i<11; i++)
		icpf[i] = cpf[i] - 48;
	//Primeiro dígito
	for(i=0; i<9; i++)
		somador += icpf[i] * (10-i);
	result1=somador%11;
	if(result1 == 0 || result1 == 1)
		digito1=0;
	else
		digito1 = 11 - result1;
	//Segundo dígito
	somador = 0;
	for(i=0; i<10; i++)
		somador += icpf[i] * (11-i);
	valor = (somador / 11) * 11;
	result2 = somador-valor;
	if(result2 == 0 || result2 == 1)
		digito2 = 0;
	else
		digito2 = 11 - result2;
	//Resultado
	if((digito1 == icpf[9]) && (digito2 == icpf[10]))
		return 1;
	else
		return 0;
}

void cad_aluno(turma turmas[], int numturmas){
    int i,num,x,numalunos;
    printf("Escolha qual turma o aluno sera colocado\n");
    printf("Turmas Cadastradas\n");
    for(x=0;x<numturmas;x++){
        printf("Turma : %d\n",x+1);
        printf("Componente curricular : %s\n",turmas[x].componente);
    }
    printf("Digite o codigo da turma que voce quer\n");
    scanf("%d",&num);
    num--;
    printf("Digite a quantidade de aluno que vai ser cadastrado \n");
    scanf("%d",&numalunos);
    for(i = turmas[num].qtdDeAlunos ; numalunos > 0 ;i++, numalunos--){
        printf("Digite o Nome do aluno:\n");
        fflush(stdin);
        fgets(turmas[num].alunox[i].nome,max,stdin);
        printf("Digite a Matricula\n");
        scanf("%d",turmas[num].alunox[i].matricula);
        printf("Digite o CPF do Aluno\n");
        do{
            scanf("%s",turmas[num].alunox[i].cpf);
            if(!validadorCPF(turmas[num].alunox[i].cpf))
                printf("CPF invalido\n");
            }while(!validadorCPF(turmas[num].alunox[i].cpf));
        turmas[num].qtdDeAlunos++;
    }
}

void cad_turma(turma turmas[], int *contador){
    int con_soma=0;
    con_soma=1 + *contador;
    printf("O codigo da turma e: %d\n",con_soma);
    printf("digite o componente Corricular\n");
    fflush(stdin);
    fgets(turmas[*contador].componente,max,stdin);
    printf("Digite o numero da fase\n");
    scanf("%d",&turmas[*contador].fase);
    printf("Digite o Horario da a aula\n");
    fflush(stdin);
    fgets(turmas[*contador].horario,max,stdin);
    turmas[*contador].qtdDeAlunos = 0;//contador que ira mostrar quantos alunos estão cadastrados nas turmas e em cada turma
    (*contador)++;
}
void not_parciais(turma turmas[] ,int numturmas ){
    int num,i,x;
    printf("Escolha qual turma vai ser cadastrada as notas\n");
    printf("Turmas Cadastradas\n");
    for(x=0;x<numturmas;x++){
        printf("Turma : %d\n",x+1);
        printf("Componente curricular : %s\n",turmas[x].componente);
    }
    printf("Digite o codigo da turma que voce quer\n");
    scanf("%d",&num);
    num--;
    if(turmas[num].qtdDeAlunos ==0)
        puts("Nao a alunos cadastrados");
    else
    for(i=0;i<turmas[num].qtdDeAlunos;i++){
        printf("%s",turmas[num].alunox[i].nome);
        printf("Digite a nota  NP1\n");
        scanf("%f",&turmas[num].alunox[i].np1);
        printf("Digite a nota NP2\n");
        scanf("%f",&turmas[num].alunox[i].np2);
    }
}

void ex_parciais(turma turmas[], int numturmas){
    int x,num,i;
    printf("Escolha qual turma que sera exibita as notas parciais\n");
    printf("Turmas Cadastradas\n");
    for(x=0;x<numturmas;x++){
        printf("Turma:%d\n",x+1);
        printf("Componente curricular :%s\n",turmas[x].componente);
    }
    printf("Digite o codigo da turma que voce quer\n");
    scanf("%d",&num);
    num--;
    if(turmas[num].qtdDeAlunos ==0)
        puts("Nao a alunos cadastrados");
    else
       for(i=0;i<turmas[num].qtdDeAlunos;i++){
            printf("%s",turmas[num].alunox[i].nome);
            printf("Digite a  NP1: %.2f\n",turmas[num].alunox[i].np1);
            printf("Dgite a NP2 %.2f\n",turmas[num].alunox[i].np2);

        }
}

void en_diario(turma turmas[] , int numturmas){
   int x,num,i;
   float media_a;
   printf("Escolha a turma vai ser encerrado o diario de classe\n");
        printf("Turmas Cadastradas\n");
        for(x=0;x<numturmas;x++){
            printf("Turma :%d\n",x+1);
            printf("Componente curricular : %s\n",turmas[x].componente);
        }
        printf("Digite o codigo da turma que voce quer\n");
        scanf("%d",&num);
        num--;
         if(turmas[num].qtdDeAlunos ==0)
        puts("Nao a alunos cadastrados");
        else
        for(i=0;i<turmas[num].qtdDeAlunos;i++){
            media_a=((turmas[num].alunox[i].np1+turmas[num].alunox[i].np2)/2);
            if(media_a>=6)
                printf("%s = Aprovado\n",turmas[num].alunox[i].nome);
            else
                printf("%s = Reprovado\n",turmas[num].alunox[i].nome);

        }

    }
void ex_turma(turma turmas[], int numturmas){
    int x,num,i;
    printf("Escolha qual turma sera mostrado os dados da turma\n");
    printf("Turmas Cadastradas\n");
    for(x=0;x<numturmas;x++){
        printf("Turma : %d\n",x+1);
        printf("Componente curricular : %s\n",turmas[x].componente);
        }
    printf("Digite o codigo da turma que voce quer\n");
    scanf("%d",&num);
    num--;
    printf("O codigo da turma e: %d\n",turmas[num].codigo);
    printf("Componente curricular: %s",turmas[num].componente);
    printf("Fase do Curso: %d\n",turmas[num].fase);
    printf("Horario do Curso: %s",turmas[num].horario);
    for(i=0;i<turmas[num].qtdDeAlunos;i++)
        printf("Alunos cadastrado nesta turma:\n %s",turmas[num].alunox[i].nome);

}


int main(){
    int contador=0;
    turma turmas[30];

    int opc_menu_princ;
    do{
        printf("Menu Principal :\n");
        printf("1-Cadastro de Aluno:\n");
        printf("2-Cadastro da Turma:\n");
        printf("3-Digitar as notas:\n");
        printf("4-Exibir as Turma:\n");
        printf("5-Exibir notas Parciais:\n");
        printf("6-Encerrar Diario:\n");
        printf("7-Sair:\n");
        scanf("%d",&opc_menu_princ);
        switch(opc_menu_princ){
        case 1:
            if(contador == 0)
                puts("Nao existe turmas cadastradas");// se nao tiver nennhum aluno cadasttrado no contador naquela turma especifica ele vai mostrar que nao a alunos ou turma cadasrtrados
            else
                cad_aluno(turmas, contador);
            break;
        case 2:
            cad_turma(turmas, &contador);
            break;
        case 3:
            if(contador == 0)
                puts("Nao tem alunos cadastrador ou Turma");
            else
            not_parciais(turmas, contador);
            break;
        case 4:
            if(contador == 0)
                puts("Nao tem Turma Cadastrada");
            else
            ex_turma(turmas, contador);
            break;
        case 5:
            if(contador == 0)
                puts("Nao tem alunos cadastrador ou Turma");
            else
            ex_parciais(turmas, contador);
            break;
        case 6:
            if(contador == 0)
                puts("Nao tem alunos cadastrador ou Turma");
            else
            en_diario(turmas ,contador);
            break;
        case 7:
            exit(0);
            default:
        printf("Esses dados não foram encontrados no banco de dados");
        }
    }while(opc_menu_princ!=0);
    return 0;
 }

//o contador foi usado para dentro do cadastro da turma para ver quantos aluno teria na turma se nao chega-se ao maximo 30 e tambem para não colocar uma aluno sobre o outro cada vezz que cadastrar a turma
