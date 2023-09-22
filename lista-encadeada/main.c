//Atividade de aprendizagem semestre 2023.1, Engenharia de Computação IFPB-CG
//Menu para um sistema escolar baseado em uma lista simplesmente encadeada
//Data de conclusão: 23/05/2023

#include "listadinalu.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  ListaAluno l;
  int opcao;
  cria(&l);
  printf("\033[1;34mDeveloped by Pedro Medeiros and Paulo Felipe\033[0m\n");

  while (1) {
    printf("\n        Sistema escolar");
    printf("\n-----------------------------------");
    printf("\n 1  - Verificar se a lista está vazia");
    printf("\n 2  - Exibir todos os dados da lista");
    printf("\n 3  - Tamanho da lista");
    printf("\n 4  - Inserir aluno no fim da lista");
    printf("\n 5  - Inserir aluno em determinada posição");
    printf("\n 6  - Inserir aluno com ordem decrescente p/matricula");
    printf("\n 7  - Remover aluno p/matricula");
    printf("\n 8  - Remover aluno p/posição");
    printf("\n 9  - Obter dados por posição");
    printf("\n 10 - Obter posição por matricula");
    printf("\n 11 - Pesquisar aluno p/nome ou matricula");
    printf("\n 12 - sair");
    printf("\n-----------------------------------");
    printf("\nDigite a opção:");
    scanf("%d", &opcao);

    if (opcao >= 1 && opcao <= 12) {
      // 1.Verificar lista vazia
      if (opcao == 1) {
        if (vazia(&l)) {
          texto("A lista está vazia");
        } else {
          texto("A lista possui elementos");
        }
      }
      // 2.Exibir dados da lista
      if (opcao == 2) {
        system("clear");
        if (vazia(&l)) {
          texto("A lista está vazia");
        }
        exibirAlunos(&l);
      }
      // 3.Tamanho da lista
      if (opcao == 3) {
        system("clear");
        printf("\n-------------------------------\n");
        printf("A lista possui %d alunos", tamanho(&l));
        printf("\n-------------------------------\n");
      }
      // 4.Inserir no fim
      if (opcao == 4) {
        Aluno dado;
        system("clear");
        printf("\nInsira o nome do aluno: ");
        scanf("%s", dado.nome);
        fl();
        printf("\nInsira a matricula do aluno: ");
        scanf("%d", &dado.matricula);
        fl();
        printf("\nInsira as notas separadas por espaço: ");
        scanf("%f %f", &dado.nota1, &dado.nota2);
        fl();
        if (insereFinal(&l, dado) == 1) {
          texto("Aluno inserido com sucesso!");
        }
      }
      // 5. Inserir aluno em determinada posicao
      if (opcao == 5) {
        Aluno dado;
        int posicao;
        system("clear");
        printf("\nInsira o nome do aluno: ");
        scanf("%s", dado.nome);
        fl();
        printf("\nInsira a matricula do aluno: ");
        scanf("%d", &dado.matricula);
        fl();
        printf("\nInsira as notas separadas por espaço: ");
        scanf("%f %f", &dado.nota1, &dado.nota2);
        fl();
        printf("\nInforme a posição na qual inserir o aluno: ");
        scanf("%d", &posicao);
        fl();
        if (inserePos(&l, dado, posicao) == 1) {
          texto("Aluno inserido com sucesso!");
        }
      }
      // 6.Inserir por ordem decrescente de matricula
      if (opcao == 6) {
        Aluno dado;
        system("clear");
        printf("\nInsira o nome do aluno: ");
        scanf("%s", dado.nome);

        printf("\nInsira a matricula do aluno: ");
        scanf("%d", &dado.matricula);

        printf("\nInsira as notas separadas por espaço: ");
        scanf("%f %f", &dado.nota1, &dado.nota2);
        inseredecresc(&l, dado);
      }
      // 7. Remover aluno por matricula
      if (opcao == 7) {
        int matricula;
        system("clear");
        printf("\nInsira a matricula do aluno: ");
        scanf("%d", &matricula);
        if (removeAlunoMat(&l, matricula) == 1) {
          texto("Aluno removido com sucesso");
        } else {
          texto("Nao foi possivel remover o aluno");
        }
      }
      // 8. Remover aluno por posição
      if (opcao == 8) {
        int posicao;
        system("clear");
        printf("\nInsira a posição do aluno na lista: ");
        scanf("%d", &posicao);
        if (removeAluno(&l, posicao) == 1) {
          texto("Aluno removido com sucesso");
        } else {
          texto("Nao foi possivel remover o aluno");
        }
      }
      if (opcao == 9) {
        int pos;
        Aluno al;
        system("clear");
        printf("Informe a posição do aluno: ");
        scanf("%d", &pos);
        if (buscaAlunoPos(&l, pos, &al) == 1) {
          system("clear");
          printf(
              "O aluno da posição %d é %s:\nMatrícula: %d\nNotas: %.1f e %.1f.\n",
              pos, al.nome, al.matricula, al.nota1, al.nota2);
        } else {
          texto("Esta posição não consta no cadastro");
        }
      }
        // 10.Posição p/matricula
        if (opcao == 10) {
          int matricula;
          int posicao;
          printf("\nInsira a matricula do aluno: ");
          scanf("%d", &matricula);
          
          if (buscaPosMat(&l, matricula, &posicao) == 1) {
            system("clear");
            printf("\n-------------------------------\n");
            printf("A posição do aluno é:%d", posicao);
            printf("\n-------------------------------\n");
          } else {
            texto("O aluno informado não está na lista");
          }
        }
          if (opcao == 11) {
              char dado[50];
              int matricula, pos;
              Aluno al;
              system("clear");
              printf("\nInforme nome/matricula do aluno: ");
              scanf("%s", dado);
          
              if (isdigit(dado[0])) {
                  matricula = atoi(dado);
                  if (buscaPosMat(&l, matricula, &pos) && buscaAlunoPos(&l, pos, &al)) {
                      system("clear");
                      printf("\n-------------------------------------");
                      printf("\nO aluno encontrado é:\n%s - Matrícula: %d\nNotas: %.1f e %.1f.\n", al.nome, al.matricula, al.nota1, al.nota2);
                    printf("\n-------------------------------------\n");
                  } else {
                      texto("Aluno não encontrado.");
                  }
              } else {
                  if (buscaNome(&l, &al, dado)) {
                      system("clear");
                      printf("\nO aluno encontrado é %s:\nMatrícula: %d\nNotas: %.1f e %.1f.\n", al.nome, al.matricula, al.nota1, al.nota2);
                  } else {
                      texto("Aluno não encontrado.");
                  }
              }
          }

        if (opcao == 12) {
         printf("\n %d", ultima(&l, 123456));
        }
    }
      else {
        texto("Opção inválida, tente novamente");
      }
  }
    texto("Até Logo!");
  }

