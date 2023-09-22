void menorelemento(int tamanho,int **matriz, int array[]){

  for(int linha = 0;linha<tamanho;linha++){
    for(int coluna = 0;coluna<tamanho;coluna++){
      scanf("%d",&mat[linha][coluna])
    }
  }
  int menor = *(*(matriz)+tamanho-1);
  *(array)=menor;
  *(arr+1)=0;
  *(arr+2)=tamanho-1;

  for(int i=0;i<tamanho;i++){
    for(int j =0; j<tamanho;j++){
      int elemento = *(*(matriz+i)+j);

      if(((i+j)==tamanho-1) && elemento<menor){
        menor = elemento;
        *(array)=menor;
        *(array+1)=i;
        *(array+2)=j;
      }
    }
  }
}