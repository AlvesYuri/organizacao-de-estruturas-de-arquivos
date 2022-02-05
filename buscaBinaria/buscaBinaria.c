/*O objetivo da tarefa é implementar o método da busca binária no arquivo de ceps ordenado.
Você não pode trazer o arquivo inteiro para memória. Os registros serão lidos um de cada vez. 
Posicione o indicador de posição no registro do meio do arquivo. Verifique se esse registro é o registro desejado. 
Caso positivo, o algoritmo termina, apresentando o registro encontrado.
Caso o registro não seja o desejado, continue a pesquisa, considerando apenas a metade do arquivo onde o cep procurado possa estar. 
A implementação correta publicada no GIT vale até 2 pontos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
  char logradouro[72];
  char bairro[72];
  char cidade[72];
  char uf[72];
  char sigla[2];
  char cep[8];
  char lixo[2];
};

int main(int argc, char **argv)
{

  FILE *f;
  Endereco e;
  long tamanhoArquivo, tamanhoRegistro, qtdRegistros, posicao, primeiro, ultimo, meio;

  f = fopen("cep_ordenado.dat", "rb");
  fseek(f, 0, SEEK_END);
  tamanhoArquivo = ftell(f);
  tamanhoRegistro = sizeof(Endereco);
  qtdRegistros = tamanhoArquivo / tamanhoRegistro;
  primeiro = 0;
  ultimo = qtdRegistros - 1;

  printf("Tamanho do Arquivo: %ld\n", tamanhoArquivo);
  printf("Tamanho do Registro: %ld\n", tamanhoRegistro);
  printf("Quantidade de Registros: %ld\n", qtdRegistros); 
  printf("Ultimo registro: %ld\n", ultimo);

  while (primeiro <= ultimo)
  {
    
    meio = (primeiro + ultimo) / 2;

    fseek(f, meio * tamanhoRegistro, SEEK_SET);
    fread(&e, tamanhoRegistro, 1, f);

    if (argv[1] == e.cep)
    {
      printf("ACHOU");
    }
    else
    {
      if (argv[1] < e.cep)
      {
        ultimo = meio - 1;
      }
      else
      {
        primeiro = meio + 1;
      }
    }
  }

  fclose(f);

  return 0;
}