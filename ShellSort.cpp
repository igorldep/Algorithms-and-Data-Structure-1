void shellSort(int *vetor, int tamanho)
{
   int i = (tamanho - 1) / 2;
   int chave, k, aux;
 
   while(i != 0)
   {
      do
      {
         chave = 1;
         for(k = 0; k < MAX - i; ++k)
         {
            if(Vetor[k] > Vetor[k + i])
            {
               aux = Vetor[k];
               Vetor[k] = Vetor[k + i];
               Vetor[k + i] = aux;
               chave = 0;
            }
         }
      }while(chave == 0);
      i = i / 2;
   }
}
