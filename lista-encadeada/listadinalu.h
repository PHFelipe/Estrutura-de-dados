typedef struct aluno {
  int matricula;
  char nome[30];
  float nota1, nota2;
} Aluno;

typedef struct no {
  Aluno dado;
  struct no *prox;
} No;

typedef struct lista {
  No *inicio;
} ListaAluno;


void cria(ListaAluno *la);   // Cria a lista vazia
int tamanho(ListaAluno *la); // Retorna o tamanho da lista
int vazia(ListaAluno *la);   // Retorna se a lista está vazia
int buscaPosMat(ListaAluno *la, int mat,
                int *pos); // Pesquisa posição pela matricula (retorna
// a posição no parâmetro *pos)
int buscaAlunoPos(ListaAluno *la, int pos,
                  Aluno *al); // Pesquisa aluno pela pela posição
// (retorna o Aluno no parâmetro *al)

int buscaNome(ListaAluno *la, Aluno *al, char *nome);
void inseredecresc(
    ListaAluno *la,
    Aluno dado); // Insere o aluno antes do aluno com a matricula maior
int insereFinal(ListaAluno *la, Aluno al); // Insere aluno no final da lista
int inserePos(ListaAluno *la, Aluno al,
              int pos); // Insere aluno na posição determinada
int removeAlunoMat(ListaAluno *la,
                   int mat); // Remove aluno da lista passando a matricula
int removeAluno(ListaAluno *la, int pos); // Remove aluno por posição
void exibirAlunos(ListaAluno *la);        // Exibe a Lista de alunos
void texto(char *mensagem);
int ultima(ListaAluno *l, int ele);
void fl();
