void print(int a[], int n ,int i){
  cout<<i <<":";
  for(int j= 0; j<8; j++){
    cout<<a[j] <<" ";
  }
  cout<<endl;
}
/**
 * 直接插入排序的一般形式
 *
 * @param int dk 缩小增量，如果是直接插入排序，dk=1
 *
 */

void ShellInsertSort(int a[], int n, int dk)
{
  for(int i= dk; i<n; ++i){
    if(a[i] < a[i-dk]){      //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
      int j = i-dk;  
      int x = a[i];      //复制为哨兵，即存储待排序元素
      a[i] = a[i-dk];      //首先后移一个元素
      while(x < a[j]){    //查找在有序表的插入位置
        a[j+dk] = a[j];
        j -= dk;       //元素后移
      }
      a[j+dk] = x;      //插入到正确位置
    }
    print(a, n,i );
  }

}

 // 先按增量d（n/2,n为要排序数的个数进行希尔排序
void shellSort(int a[], int n){

  int dk = n/2;
  while( dk >= 1  ){
    ShellInsertSort(a, n, dk);
    dk = dk/2;
  }
}
int main(){
  int a[8] = {3,1,5,7,2,4,9,6};
  //ShellInsertSort(a,8,1); //直接插入排序
  shellSort(a,8);        //希尔插入排序
  print(a,8,8);
}
