#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int opcao;
typedef struct{
    int codigo_aluno;
    char nome[100];
    char biotipo[25];

}Aluno;
typedef struct{
    int codigo_treino;
    char nome_treino[25];
    char nivel[25];
    int duracao;
}Treino;
//procedimento para imprimir dados do aluno
void imprimir_aluno(Aluno al){
    printf("\nCodigo de Matricula: %d", al.codigo_aluno);
    printf("\nNome Completo: %s", al.nome);
    printf("\nBiotipo:%s", al.biotipo);
}
//Função que le os dados do aluno
Aluno ler_aluno(){
    Aluno al;
    printf("\nDigite seu codigo: ");
    scanf("%d", &al.codigo_aluno);

    printf("\nDigite seu nome completo: ", al.nome);
    scanf("%s", al.nome);

    printf("\nDigite seu biotipo: ", al.biotipo);
    scanf("%s", al.biotipo);

    return al;
}
//Função MENU
int menu(){
    printf("\n\tMENU:\t\n1-Cadastrar aluno\t\n2-Cadastrar treino\t\n3-Remover aluno\t\n4-Remover treino\t\n5-Consultar alunos\t\n6-Consultar treinos\t\n7-Sair");
    printf("\nDigite uma das opcoes acima:");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    Aluno al;
    int opcao;
    printf("*** ACADEMIA - COMPUTACAO IME 27***");
    do{
        opcao = menu();
        switch (opcao)
        {
        case 1:  // INICIANDO CADASTRO
            FILE* faluno;
            faluno = fopen("aluno.txt", "w");
            ferror(faluno);
            char nome_aluno[50];
            char codigo_aluno[5];
            char biotipo;
            int tipo;
            

            printf("\nNOME DO ALUNO: ");
            scanf("%s", &nome_aluno);

            do{
                printf("\nCÓDIGO DO ALUNO (5 DÍGITOS): "); //CODIGO DEVE TER 5 DIGITOS
                scanf("%5s", &codigo_aluno);
                if(strlen(codigo_aluno) != 5){
                    printf("INSIRA 5 DÍGITOS\n");
                    return 1;
                }
                for (int i = 0; i < 5; i++){
                    if(!isdigit(codigo_aluno[i])){
                        printf("INSIRA APENAS NÚMEROS\n");
                        return 1;
                    }
                }
            } while (1);

            printf("\nBIOTIPO DO ALUNO: \n 1 - MESOMORFO \n 2 - ENDOMORFO \n 3 - ECTOMORFO");
            scanf("%d", &tipo);
            switch (tipo)
            {
            case 1:
                biotipo = "MESOMORFO";
                break;
            case 2:
                biotipo = "ENDOMORFO";
                break;
            case 3:
                biotipo = "ECTOMORFO";
                break;
            default:
                break;
            }
            
             
            fclose(faluno);
            break;
        case 2:
            FILE* ftreino;
            ftreino = fopen("treino.txt", "w");
            ferror(ftreino);


            fclose(ftreino);
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        default:
        printf("Opcao invalida!");
            break;
        }
    }while (opcao != 7);
    al = ler_aluno(); //variavel auxiliar para receber os valores lidos pela função
    imprimir_aluno(al);
    return 0;
}