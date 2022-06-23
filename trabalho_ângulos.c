#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846
#include <conio.h>
#include <ctype.h>

void limpar_entrada()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

int main()
{

  int opc;
  double seno, cosseno, tangente, secante, cossecante, cotangente, aseno, acosseno, atangente;
  char resp, calculo;
  double graus, rad;
  double senog, cosseg, tanggraus, secgraus, cossecgraus, cotanggraus;

  do
  {

    printf("\n\nEscolha o que deseja calcular...\n\n");

    printf("\t\tMenu:\n\t\t1 > Seno\n\t\t2 > Cosseno\n\t\t3 > Tangente\n\t\t4 > Secante\n\t\t5 > Cossencante\n\t\t6 > Cotangente\n\t\t7 > Arco seno\n\t\t8 > Arco cosseno\n\t\t9 > Arco tangente\n\t\t10 > Sair\n\n");

    do
    {
      opc = 0;
      printf("\n\nDigite a opcao desejada: ");
      scanf("%d", &opc);

      if (opc != 10 && opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5 && opc != 6 && opc != 7 && opc != 8 && opc != 9)
        printf("\n\nOpcao Invalida!!!\n\n");
      limpar_entrada(opc);

    } while (opc != 10 && opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5 && opc != 6 && opc != 7 && opc != 8 && opc != 9);

    if (opc == 10)
      return 0;

    if (opc == 1)
    {

      do
      {
        printf("\nVoce deseja calcular o Seno em graus ou radianos?(g/r)");
        scanf("%c", &calculo);
        if (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R')
          printf("\nResposta errada!!!\n");
        limpar_entrada(calculo);
      } while (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R');

      if (calculo == 'g' || calculo == 'G')
      {
        printf("\nDigite o valor que deseja calcular o seno(em graus): ");
        scanf("%lf", &graus);
        printf("\nO valor do seno em graus eh: %lf", senog = sin(graus * PI / 180));
        limpar_entrada(graus);
      }
      else if (calculo == 'r' || calculo == 'R')
      {
        printf("\nDigite o valor que deseja calcular o seno(em radianos): ");
        scanf("%lf", &rad);
        printf("\nO valor do seno eh: %lf", seno = sin(rad));
        limpar_entrada(rad);
      }
    }

    if (opc == 2)
    {

      do
      {
        printf("\nVoce deseja calcular o cosseno em graus ou radianos?(g/r)");
        scanf("%c", &calculo);
        if (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R')
          printf("\nResposta errada!!!\n");
        limpar_entrada(calculo);
      } while (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R');

      if (calculo == 'g' || calculo == 'G')
      {
        printf("\nDigite o valor que deseja calcular o cosseno(em graus): ");
        scanf("%lf", &graus);
        printf("\nO valor do cosseno em graus eh: %lf", cosseg = cos(graus * PI / 180));
        limpar_entrada(graus);
      }
      else if (calculo == 'r' || calculo == 'R')
      {
        printf("\nDigite o valor que deseja calcular o cosseno(em radianos): ");
        scanf("%lf", &rad);
        printf("\nO valor do cosseno eh: %lf", cosseno = cos(rad));
        limpar_entrada(rad);
      }
    }

    if (opc == 3)
    {

      do
      {
        printf("\nVoce deseja calcular a tangente em graus ou radianos?(g/r)");
        scanf("%c", &calculo);
        if (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R')
          printf("\nResposta errada!!!\n");
        limpar_entrada(calculo);
      } while (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R');

      if (calculo == 'g' || calculo == 'G')
      {
        do
        {
          printf("\nDigite o valor que deseja calcular a tangente(em graus): ");
          scanf("%lf", &graus);
          if (fabs(graus) > 89.999999 && fabs(graus) < 90.011111)
            printf("\n\nResposta errada!!! Nao existe tangente de 90\n\n");
          limpar_entrada(graus);
        } while (fabs(graus) > 89.999999 && fabs(graus) < 90.011111);

        printf("\nO valor da tangente em graus eh: %lf\n", tanggraus = tan(graus * PI / 180));
      }

      else if (calculo == 'r' || calculo == 'R')
      {
        printf("\nDigite o valor que deseja calcular a tangente(em radianos): ");
        scanf("%lf", &rad);
        printf("\nO valor da tangente eh: %lf", tangente = tan(rad));
        limpar_entrada(rad);
      }
    }

    if (opc == 4)
    {

      do
      {
        printf("\nVoce deseja calcular a secante em graus ou radianos?(g/r) ");
        scanf("%c", &calculo);
        if (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R')
          printf("\nResposta errada!!!\n");
        limpar_entrada(calculo);
      } while (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R');

      if (calculo == 'g' || calculo == 'G')
      {
        printf("\nDigite o valor que deseja calcular a secante(em graus): ");
        scanf("%lf", &graus);
        printf("\nO valor da secante em graus eh: %lf", secgraus = 1 / (cos(graus * PI / 180)));
        limpar_entrada(graus);
      }
      else if (calculo == 'r' || calculo == 'R')
      {
        printf("\nDigite o valor que deseja calcular a secante(em radianos): ");
        scanf("%lf", &rad);
        printf("\nO valor da secante eh: %lf", secante = 1 / (cos(rad)));
        limpar_entrada(rad);
      }
    }

    if (opc == 5)
    {

      do
      {
        printf("\nVoce deseja calcular a cossecante em graus ou radianos?(g/r) ");
        scanf("%c", &calculo);
        if (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R')
          printf("\nResposta errada!!!\n");
        limpar_entrada(calculo);
      } while (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R');

      if (calculo == 'g' || calculo == 'G')
      {
        printf("\nDigite o valor que deseja calcular a cossecante(em graus): ");
        scanf("%lf", &graus);
        printf("\nO valor da cossecante em graus eh: %lf", cossecgraus = 1 / (sin(graus * PI / 180)));
        limpar_entrada(graus);
      }
      else if (calculo == 'r' || calculo == 'R')
      {
        printf("\nDigite o valor que deseja calcular a cossecante(em radianos): ");
        scanf("%lf", &rad);
        printf("\nO valor da cossecante eh: %lf", cossecante = 1 / (sin(rad)));
        limpar_entrada(rad);
      }
    }

    if (opc == 6)
    {

      do
      {
        printf("\nVoce deseja calcular a contangente em graus ou radianos?(g/r) ");
        scanf("%c", &calculo);
        if (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R')
          printf("\nResposta errada!!!\n");
        limpar_entrada(calculo);
      } while (calculo != 'g' && calculo != 'G' && calculo != 'r' && calculo != 'R');

      if (calculo == 'g' || calculo == 'G')
      {
        printf("\nDigite o valor que deseja calcular a cotangente(em graus): ");
        scanf("%lf", &graus);
        printf("\nO valor da cotangente em graus eh: %lf", cotanggraus = 1 / (tan(graus * PI / 180)));
        limpar_entrada(graus);
      }
      else if (calculo == 'r' || calculo == 'R')
      {
        printf("\nDigite o valor que deseja calcular a cossecante(em radianos): ");
        scanf("%lf", &rad);
        printf("\nO valor da cotangente eh: %lf", cotangente = 1 / (tan(rad)));
        limpar_entrada(rad);
      }
    }

    if (opc == 7)
    {
      printf("\nDigite o numero que deseja calcular o arco seno: ");
      scanf("%lf", &rad);
      printf("\nO valor do arco seno eh: %lf", aseno = asin(rad));
      limpar_entrada(rad);
    }

    if (opc == 8)
    {
      printf("\nDigite o numero que deseja calcular o arco cosseno: ");
      scanf("%lf", &rad);
      printf("\nO valor do arco cosseno eh: %lf", acosseno = acos(rad));
      limpar_entrada(rad);
    }

    if (opc == 9)
    {
      printf("\nDigite o numero que deseja calcular o arco tangente: ");
      scanf("%lf", &rad);
      printf("\nO valor do arco tangente eh: %lf", atangente = atan(rad));
      limpar_entrada(rad);
    }
    do
    {
      printf("\n\nDeseja executar novamente (S/N)? \n");
      resp = toupper(getchar());
      if (resp != 'S' && resp != 'N')
      {
        printf("\nResposta errada!\n");
        limpar_entrada();
      }
      if (resp == 'S')
      {
        system("cls");
        limpar_entrada(resp);
      }
    } while (resp != 'S' && resp != 'N');

  } while (opc != 0 && resp != 'N');

  system("pause");
}