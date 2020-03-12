Void RadixSort(Node L[],length,maxradix)
{
   int m,n,k,lsp;
   k=1;m=1;
   int temp[10][length-1];
   Empty(temp); //清空临时空间
   while(k<maxradix) //遍历所有关键字
   {
     for(int i=0;i<length;i++) //分配过程
    {
       if(L[i]<m)
          Temp[0][n]=L[i];
       else
          Lsp=(L[i]/m)%10; //确定关键字
       Temp[lsp][n]=L[i];
       n++;
   }
   CollectElement(L,Temp); //收集
   n=0;
   m=m*10;
  k++;
 }
}
