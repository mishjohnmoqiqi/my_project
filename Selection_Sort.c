void print(int a[], int n ,int i){
  cout<<"第"<<i+1 <<"趟 : ";
  for(int j= 0; j<8; j++){
    cout<<a[j] <<"  ";
  }
  cout<<endl;
}
/**
 * 数组的最小值
 *
 * @return int 数组的键值
 */
int SelectMinKey(int a[], int n, int i)
{
  int k = i;
  for(int j=i+1 ;j< n; ++j) {
    if(a[k] > a[j]) k = j;
  }
  return k;
}

/**
 * 选择排序
 *
 */
void selectSort(int a[], int n){
  int key, tmp;
  for(int i = 0; i< n; ++i) {
    key = SelectMinKey(a, n,i);           //选择最小的元素
    if(key != i){
      tmp = a[i];  a[i] = a[key]; a[key] = tmp; //最小元素与第i位置元素互换
    }
    print(a,  n , i);
  }
}
int main(){
  int a[8] = {3,1,5,7,2,4,9,6};
  cout<<"初始值：";
  for(int j= 0; j<8; j++){
    cout<<a[j] <<"  ";
  }
  cout<<endl<<endl;
  selectSort(a, 8);
  print(a,8,8);
}
