// Aluno: Jose Carlos	
//Matricula: UC17100669

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //usar para funcoes String. 
#define QTD_MAX_FUNCIONARIOS 500

/* 
Sintese:
Objetivo: Controle dos Funcionarios de uma empresa.
Entrada: Matriculas e Salarios dos Funcionarios. 
Saida: Matriculas e Salarios dos Funcionarios.
*/

//Prototipos das funções
int leInt(char msg[]);
int leValidaInt(char msg[], int min, int max);
float leFloat(char msg[]);
int verificaRepetido(int valores[], int posicao);
void ordenaSalarios(int matriculas[],float salarios[], int qtdFuncionarios);
void apresentaFuncionarios(int matriculas[],float salarios[], int qtdFuncionarios);

int main() {  
//Declarações
    int matriculas[QTD_MAX_FUNCIONARIOS], qtdFuncionarios,cont;
    float salarios[QTD_MAX_FUNCIONARIOS];

//Instruções
    qtdFuncionarios = leValidaInt("Informe Quantidade de Funcionarios: ",1,QTD_MAX_FUNCIONARIOS);
    
    for(cont=0;cont<qtdFuncionarios;cont++)
    {
    	printf("DADOS FUNCIONARIO # %d:\n",cont+1);
    	do{
    		matriculas[cont] = leInt("Informe Numero de Matricula: ");
		}while(verificaRepetido(matriculas,cont) == 1);
		
		salarios[cont] = leFloat("Informe o Salario: ");
	}
	
	system("cls");
	
	apresentaFuncionarios(matriculas,salarios,qtdFuncionarios);
	
	getch();
	return 0;
}

//Objetivo: Ler um número do tipo int
//Parâmetros: referência ao vetor msg.
//Retorno: número tipo int lido.
int leInt(char msg[]){
	int ret;
	int num;
	do{
		printf("%s", msg);
		fflush(stdin);
		ret = scanf("%d",&num);
		if (ret == 0 || num < 0)
			printf("Favor digitar valor correto, com valores maiores que zero!.\n");
	}while (ret == 0 || num < 0 );

	return num;
}

//Objetivo: Validar um número do tipo int com Valor minimo e valor maximo.
//Parâmetros: referência ao vetor mensagem, número minímo, número máximo.
//Retorno: número tipo int validado.
int leValidaInt(char msg[], int min, int max){
	int num;

	do{
		num = leInt(msg);
		if (num < min || num > max)
			printf("Favor digitar um valor entre %d e %d.\n", min, max);
	}while(num < min || num > max);

	return num;
}

//Objetivo: Ler um número do tipo float
//Parâmetros: referência ao vetor mensagem.
//Retorno: número tipo float lido.
float leFloat(char msg[]){
	float num;
	int ret;

	do{
		printf("%s", msg);
		fflush(stdin);
		ret = scanf("%f",&num);
		if (ret == 0 || num < 0)
			printf("Favor digitar salario valido.\n");
	}while (ret == 0 || num < 0 );

	return num;
}

//Objetivo: Verificar se existe numero repetido em um vetor.
//Parametro: Referencia ao vetor e a posicao que deve ser verificado 
//Retorno: 0 para se nao existe e 1 para se existe numero repetido
int verificaRepetido(int valores[], int posicao)
{
	int cont,flag=0;
	for(cont=0;cont<posicao;cont++)
	{
		if(valores[posicao]==valores[cont])
		{
			printf("Valor Inserido ja existe no sistema ...\n");
			flag=1;
			break;
		}
	}
	return flag;
}

//Objetivo: Metodo que ordena os salarios.
//parametros: referencia ao vetor a ordenar
//Retorno: nada
void ordenaSalarios(int matriculas[],float salarios[], int qtdFuncionarios)
{
	int contMinimo, contSalario, min, auxiliarMatriculas;
	float auxiliarSalario;
	for(contMinimo=0;contMinimo<qtdFuncionarios;contMinimo++)
	{
		min=contMinimo;
		for(contSalario=contMinimo;contSalario<qtdFuncionarios;contSalario++)
		{
			if(salarios[contSalario] <salarios[min])
			{
				min = contSalario;
			}
		}
		auxiliarSalario = salarios[contMinimo];
		salarios[contMinimo] = salarios[min];
		salarios[min] = auxiliarSalario;
		
		auxiliarMatriculas = matriculas[contMinimo];
		matriculas[contMinimo] = matriculas[min];
		matriculas[min] = auxiliarMatriculas;
	}
}  

//Objetivo: Apresentar salarios dos Funcionarios em forma descrecente de salarios.
//Parametro: Referencia aos Vetores matriculas e salarios. 
//Retorno: nada
void apresentaFuncionarios(int matriculas[],float salarios[], int qtdFuncionarios)
{
	int cont;
	
	ordenaSalarios(matriculas,salarios,qtdFuncionarios);
	
	printf("FUNCIONARIOS ORDENADOS POR SALARIOS:\n");
	for(cont=(qtdFuncionarios-1);cont>=0;cont--)
	{
		printf("Matricula # %d ----- Salario = %.2f\n",matriculas[cont],salarios[cont]);
	}
}
