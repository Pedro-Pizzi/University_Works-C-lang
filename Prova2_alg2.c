#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

// Node
typedef struct No
{
    char cpf[11], nome[45], estado[8];
    int idade;
    int id; //Valor usado para ordenar de acordo com o estado de saúde.
    struct No *proximo;
} No;

//Lista
typedef struct
{
    No *inicio;
    int tam;
} Lista;

//Recebe a lista como parâmetro;
//Faz o cadastro e ordenação dos dados na lista.
void cadastrarPaciente(Lista *lista)
{
    char opc;
    do
    {

        system("cls");

        No *novo = (No *)malloc(sizeof(No));
        No *aux;

        printf("\nDigite o NOME do paciente: ");
        fflush(stdin);
        gets(novo->nome);

        printf("\nDigite o CPF do paciente: ");
        fflush(stdin);
        scanf("%s%*c", novo->cpf);

        printf("\nDigite a IDADE do paciente: ");
        fflush(stdin);
        scanf("%d", &novo->idade);

        printf("\nDigite o ESTADO DE SAÚDE do paciente: ");
        fflush(stdin);
        scanf("%s%*c", novo->estado);

        if (!strcmp(novo->estado, "Regular"))
        {
            novo->id = 3;
        }
        else if (!strcmp(novo->estado, "Grave"))
        {
            novo->id = 2;
        }
        if (!strcmp(novo->estado, "Pessimo"))
        {
            novo->id = 1;
        }

        //Ordena a lista de acordo com o estado de saúde.
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if (novo->id < lista->inicio->id)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo && novo->id > aux->proximo->id)

                aux = aux->proximo;

            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;

        printf("\nDeseja cadastrar outro paciente? (S/N)");
        do
        {
            opc = toupper(getch());
        } while (opc != 'S' && opc != 'N');

    } while (opc == 'S');
}

//Lista todos os pacientes cadastrados.
void listarPacientes(Lista *lista)
{

    No *listar = lista->inicio;
    char sair;

    system("cls");

    printf("Quantidade de pacientes: %d\n\n", lista->tam);

    if (lista->tam > 0)
    {
        while (listar != NULL)
        {

            printf("Nome: %s\n", listar->nome);
            printf("CPF: %s\n", listar->cpf);
            printf("IDADE: %d\n", listar->idade);
            printf("ESTADO DE SAÚDE: %s\n", listar->estado);
            printf("\n\n");
            listar = listar->proximo;
        }
    }

    printf("\n\nPressione qualquer tecla para voltar para o menu...");
    sair = getch();
}

//Lista em ordem de atendimento os pacientes e informa o próximo à ser atendido;
void atenderPacientes(Lista *lista)
{
    char opc;

    int i = 1;

    do
    {
        if (lista->tam == 0)
        {
            return;
        }

        No *listar = lista->inicio;
        system("cls");

        printf("Quantidade de pacientes: %d\n", lista->tam);

        if (lista->tam > 0)
        {
            printf("\n\n********************************\n");
            printf("Paciente à ser atendido:\n");
            printf("Nome: %s\n", listar->nome);
            printf("CPF: %s\n", listar->cpf);
            printf("Idade: %d\n", listar->idade);
            printf("ESTADO DE SAÚDE: %s\n", listar->estado);
            printf("********************************\n\n\n");

            printf("Ordem de atendimento:\n\n");
        }

        while (listar != NULL)
        {

            printf("Nome: %s\n", listar->nome);
            printf("CPF: %s\n", listar->cpf);
            printf("Idade: %d\n", listar->idade);
            printf("ESTADO DE SAÚDE: %s\n", listar->estado);
            printf("\n\n");
            listar = listar->proximo;
        }

        lista->inicio = lista->inicio->proximo;
        lista->tam--;

        printf("Deseja atender outro paciente?(S/N)\n");
        do
        {
            opc = toupper(getch());
        } while (opc != 'S' && opc != 'N');

    } while (opc == 'S');
}

//Escreve todos os pacientes cadastrados no programa em um arquivo.
void escreverNoArquivo(Lista *lista)
{
    No *salvar = lista->inicio;
    FILE *arq = fopen("ficha.bin", "a");

    if (arq)
    {

        for (int i = 0; i < lista->tam; i++)
        {
            fprintf(arq, "NOME: %s\n", salvar->nome);
            fprintf(arq, "CPF: %s\n", salvar->cpf);
            fprintf(arq, "IDADE: %d\n", salvar->idade);
            fprintf(arq, "ESTADO DE SAÚDE: %s\n\n", salvar->estado);
            salvar = salvar->proximo;
        }

        fclose(arq);
    }
    else
    {
        printf("ERRO: não foi possível abrir o arquivo.\n\n");
    }
}

/*
void lerDoArquivo(Lista *lista)
{
    No *novo = (No *)malloc(sizeof(No));
    No *aux;

    FILE *arq = fopen("ficha.bin", "r");
    int i, quant = 0;

    if (arq)
    {
        fscanf(arq, "%d", &quant);

        for (i = 0; i < quant; i++)
        {
            fgets(novo->nome, 45, arq);
            fgets(novo->cpf, 11, arq);
            fscanf(arq, "%d", novo->idade);
            fgets(novo->estado, 8, arq);
            lista->inicio = novo;
            novo = novo->proximo;

            if (!strcmp(novo->estado, "Regular"))
            {
                novo->id = 3;
            }
            else if (!strcmp(novo->estado, "Grave"))
            {
                novo->id = 2;
            }
            if (!strcmp(novo->estado, "Pessimo"))
            {
                novo->id = 1;
            }

            // Ordena a lista de acordo com o estado de saúde.
            if (lista->inicio == NULL)
            {
                novo->proximo = NULL;
                lista->inicio = novo;
            }
            else if (novo->id < lista->inicio->id)
            {
                novo->proximo = lista->inicio;
                lista->inicio = novo;
            }
            else
            {
                aux = lista->inicio;
                while (aux->proximo && novo->id > aux->proximo->id)

                    aux = aux->proximo;

                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
            lista->tam++;
        }
    }
}
*/

//Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista lista;
    char opc;

    lista.inicio = NULL;
    lista.tam = 0;


    do
    {
        system("cls");
        printf("\t1 - CADASTRAR PACIENTES\n\t2 - ATENDER PACIENTES\n\t3 - LISTAR PACIENTES\n\t4 - SALVAR NO ARQUIVO\n\t5 - SAIR E SALVAR\n");
        do
        {
            opc = getch();
        } while (opc < '1' || opc > '5');

        if (opc != '5')
        {

            switch (opc)
            {
            case '1':
                cadastrarPaciente(&lista);
                break;

            case '2':
                atenderPacientes(&lista);
                break;

            case '3':
                listarPacientes(&lista);
                break;

            case '4':
              escreverNoArquivo(&lista);
              break;
            }
        }
    } while (opc != '5');
    escreverNoArquivo(&lista);
    return 0;
}
