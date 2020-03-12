# my_project
#python list clone git

C语言八大排序算法，附动图和详细代码解释！
21ic电子网  1周前
一、前言


如果说各种编程语言是程序员的招式，那么数据结构和算法就相当于程序员的内功。



想写出精炼、优秀的代码，不通过不断的锤炼，是很难做到的。




二、八大排序算法


排序算法作为数据结构的重要部分，系统地学习一下是很有必要的。


1、排序的概念


排序是计算机内经常进行的一种操作，其目的是将一组“无序”的记录序列调整为“有序”的记录序列。



排序分为内部排序和外部排序。



若整个排序过程不需要访问外存便能完成，则称此类排序问题为内部排序。

反之，若参加排序的记录数量很大，整个序列的排序过程不可能在内存中完成，则称此类排序问题为外部排序。


2、排序分类


八大排序算法均属于内部排序。如果按照策略来分类，大致可分为：交换排序、插入排序、选择排序、归并排序和基数排序。如下图所示：







3、算法分析
1.插入排序
  *直接插入排序
  *希尔排序
2.选择排序
  *简单选择排序
  *堆排序
3.交换排序
  *冒泡排序
  *快速排序
4.归并排序
5.基数排序
不稳定排序：简单选择排序，快速排序，希尔排序，堆排序
稳定排序：冒泡排序，直接插入排序，归并排序，奇数排序

1、插入排序


将第一个和第二个元素排好序，然后将第3个元素插入到已经排好序的元素中，依次类推（插入排序最好的情况就是数组已经有序了）

2、希尔排序


因为插入排序每次只能操作一个元素，效率低。元素个数N，取奇数k=N/2，将下标差值为k的数分为一组（一组元素个数看总元素个数决定），在组内构成有序序列，再取k=k/2，将下标差值为k的数分为一组，构成有序序列，直到k=1，然后再进行直接插入排序。

3、简单选择排序


选出最小的数和第一个数交换，再在剩余的数中又选择最小的和第二个数交换，依次类推

4、堆排序

以升序排序为例，利用小根堆的性质（堆顶元素最小）不断输出最小元素，直到堆中没有元素

1.构建小根堆
2.输出堆顶元素
3.将堆低元素放一个到堆顶，再重新构造成小根堆，再输出堆顶元素，以此类推

5、冒泡排序

改进1：如果某次冒泡不存在数据交换，则说明已经排序好了，可以直接退出排序
改进2：头尾进行冒泡，每次把最大的沉底，最小的浮上去，两边往中间靠1

6、快速排序

选择一个基准元素，比基准元素小的放基准元素的前面，比基准元素大的放基准元素的后面，这种动作叫分区，每次分区都把一个数列分成了两部分，每次分区都使得一个数字有序，然后将基准元素前面部分和后面部分继续分区，一直分区直到分区的区间中只有一个元素的时候，一个元素的序列肯定是有序的嘛，所以最后一个升序的序列就完成啦。

7、归并排序

将一个无序的数列一直一分为二，直到分到序列中只有一个数的时候，这个序列肯定是有序的，因为只有一个数，然后将两个只含有一个数字的序列合并为含有两个数字的有序序列，这样一直进行下去，最后就变成了一个大的有序数列

8、基数排序

找到最大的数，开个比最大的数大一点的数组，遍历每个元素，某个元素为k，则a[k]++,最好遍历数组a，a[k]等于多少就输出多少个k。只能处理整型数




三、具体排序讲解


下面针对不同排序进行一一讲解。



一、直接插入排序（Insertion Sort)



算法思想：

直接插入排序的核心思想就是：将数组中的所有元素依次跟前面已经排好的元素相比较，如果选择的元素比已排序的元素小，则交换，直到全部元素都比较过 因此，从上面的描述中我们可以发现，直接插入排序可以用两个循环完成：

       第一层循环：遍历待比较的所有数组元素

        第二层循环：将本轮选择的元素(selected)与已经排好序的元素(ordered)相比较。如果：selected > ordered，那么将二者交换。







算法代码：



void print(int a[], int n ,int i){
  cout<<i <<":";
  for(int j= 0; j<8; j++){
    cout<<a[j] <<" ";
  }
  cout<<endl;
} 
void InsertSort(int a[], int n)
{
  for(int i= 1; i<n; i++){
    if(a[i] < a[i-1]){   //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
      int j= i-1;  
      int x = a[i];     //复制为哨兵，即存储待排序元素
      a[i] = a[i-1];           //先后移一个元素
      while(x < a[j]){   //查找在有序表的插入位置
        a[j+1] = a[j];
        j--;     //元素后移
      }
      a[j+1] = x;     //插入到正确位置
    }
    print(a,n,i);      //打印每趟排序的结果
  }

}

int main(){
  int a[8] = {3,1,5,7,2,4,9,6};
  InsertSort(a,8);
  print(a,8,8);
}



二、希尔排序（Shell' s Sort）

算法思想:

希尔排序，也称递减增量排序算法，是插入排序的一种更高效的改进版本。但希尔排序是非稳定排序算法。

希尔排序的基本思想是：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。

算法步骤：

    1.选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；

    2.按增量序列个数k，对序列进行k 趟排序；

    3.每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。



算法代码:



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



三、简单选择排序（Selection Sort）

算法思想：

简单选择排序的实现思想：比较+交换

从待排序序列中，找到关键字最小的元素；

如果最小元素不是待排序序列的第一个元素，将其和第一个元素互换；

从余下的 N - 1 个元素中，找出关键字最小的元素，重复(1)、(2)步，直到排序结束。因此我们可以发现，简单选择排序也是通过两层循环实现。第一层循环：依次遍历序列当中的每一个元素 第二层循环：将遍历得到的当前元素依次与余下的元素进行比较，符合最小元素的条件，则交换。





算法代码：

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



四、堆排序（Heap Sort）

算法思想：

堆的概念

堆：本质是一种数组对象。特别重要的一点性质：任意的叶子节点小于（或大于）它所有的父节点。对此，又分为大顶堆和小顶堆：

大顶堆要求节点的元素都要大于其孩子。

小顶堆要求节点元素都小于其左右孩子。

两者对左右孩子的大小关系不做任何要求。

 利用堆排序，就是基于大顶堆或者小顶堆的一种排序方法。下面，我们通过大顶堆来实现。



基本思想：堆排序可以按照以下步骤来完成：

    1.首先将序列构建称为大顶堆；（这样满足了大顶堆那条性质：位于根节点的元素一定是当前序列的最大值）







    2. 取出当前大顶堆的根节点，将其与序列末尾元素进行交换；（此时：序列末尾的元素为已排序的最大值；由于交换了元素，当前位于根节点的堆并不一定满足大顶堆的性质）

    3. 对交换后的n-1个序列元素进行调整，使其满足大顶堆的性质；



       4. 重复2.3步骤，直至堆中只有1个元素为止



下面是基于大顶堆的堆排序算法代码：

void print(int a[], int n){
  for(int j= 0; j<n; j++){
    cout<<a[j] <<"  ";
  }
  cout<<endl;
}
/**
 * 已知H[s…m]除了H[s] 外均满足堆的定义
 * 调整H[s],使其成为大顶堆.即将对第s个结点为根的子树筛选, 
 *
 * @param H是待调整的堆数组
 * @param s是待调整的数组元素的位置
 * @param length是数组的长度
 */
void HeapAdjust(int H[],int s, int length)
{
  int tmp  = H[s];
  int child = 2*s+1; //左孩子结点的位置。(i+1 为当前调整结点的右孩子结点的位置)
    while (child < length) {
    if(child+1 <length && H[child]<H[child+1]) { // 如果右孩子大于左孩子(找到比当前待调整结点大的孩子结点)
      ++child ;
    }
    if(H[s]<H[child]) {  // 如果较大的子结点大于父结点
      H[s] = H[child]; // 那么把较大的子结点往上移动，替换它的父结点
      s = child;     // 重新设置s ,即待调整的下一个结点的位置
      child = 2*s+1;
    }  else {       // 如果当前待调整结点大于它的左右孩子，则不需要调整，直接退出
       break;
    }
    H[s] = tmp;      // 当前待调整的结点放到比其大的孩子结点位置上
  }
  print(H,length);
}

/**
 * 初始堆进行调整
 * 将H[0..length-1]建成堆
 * 调整完之后第一个元素是序列的最小的元素
 */
void BuildingHeap(int H[], int length)
{ 
  //最后一个有孩子的节点的位置 i=  (length -1) / 2
  for (int i = (length -1) / 2 ; i >= 0; --i)
    HeapAdjust(H,i,length);
}
/**
 * 堆排序算法
 */
void HeapSort(int H[],int length)
{
    //初始堆
  BuildingHeap(H, length);
  //从最后一个元素开始对序列进行调整
  for (int i = length - 1; i > 0; --i)
  {
    //交换堆顶元素H[0]和堆中最后一个元素
    int temp = H[i]; H[i] = H[0]; H[0] = temp;
    //每次交换堆顶元素和堆中最后一个元素之后，都要对堆进行调整
    HeapAdjust(H,0,i);
  }
} 

int main(){
  int H[10] = {3,1,5,7,2,4,9,6,10,8};
  cout<<"初始值：";
  print(H,10);
  HeapSort(H,10);
  //selectSort(a, 8);
  cout<<"结果：";
  print(H,10);

}
 



五、冒泡排序（Bubble Sort）


算法思想：

冒泡遍历所有的数据，每次对相邻元素进行两两比较，如果顺序和预先规定的顺序不一致，则进行位置交换；这样一次遍历会将最大或最小的数据上浮到顶端，之后再重复同样的操作，直到所有的数据有序。这个算法的名字由来是因为越大的元素会经由交换慢慢“浮”到数列的顶端。





算法代码：

void bubbleSort(int a[], int n){
  for(int i =0 ; i< n-1; ++i) {
    for(int j = 0; j < n-i-1; ++j) {
      if(a[j] > a[j+1])
      {
        int tmp = a[j] ; a[j] = a[j+1] ;  a[j+1] = tmp;
      }
    }
  }
}



六、快速排序（Quick Sort）

算法思想：

快速排序是由东尼·霍尔所发展的一种排序算法。在平均状况下，排序 n 个项目要Ο(n logn)次比较。在最坏状况下则需要Ο(n2)次比较，但这种状况并不常见。事实上，快速排序通常明显比其他Ο(n log n) 算法更快，因为它的内部循环（inner loop）可以在大部分的架构上很有效率地被实现出来

快速排序使用分治法（Divide and conquer）策略来把一个串行（list）分为两个子串行（sub-lists）。

算法步骤：

从数列中挑出一个元素，称为 “基准”（pivot）。

重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作。

递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。

递归的最底部情形，是数列的大小是零或一，也就是永远都已经被排序好了。虽然一直递归下去，但是这个算法总会退出，因为在每次的迭代（iteration）中，它至少会把一个元素摆到它最后的位置去。



算法代码：



void print(int a[], int n){
  for(int j= 0; j<n; j++){
    cout<<a[j] <<"  ";
  }
  cout<<endl;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int a[], int low, int high)
{
  int privotKey = a[low];                //基准元素
  while(low < high){                    //从表的两端交替地向中间扫描
    while(low < high  && a[high] >= privotKey) --high;  //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
    swap(&a[low], &a[high]);
    while(low < high  && a[low] <= privotKey ) ++low;
    swap(&a[low], &a[high]);
  }
  print(a,10);
  return low;
}

void quickSort(int a[], int low, int high){
  if(low < high){
    int privotLoc = partition(a,  low,  high);  //将表一分为二
    quickSort(a,  low,  privotLoc -1);      //递归对低子表递归排序
    quickSort(a,   privotLoc + 1, high);    //递归对高子表递归排序
  }
}

int main(){
  int a[10] = {3,1,5,7,2,4,9,6,10,8};
  cout<<"初始值：";
  print(a,10);
  quickSort(a,0,9);
  cout<<"结果：";
  print(a,10);

}



七、归并排序（Merge Sort）

算法思想：

归并排序（Merge sort）是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。

算法步骤：

申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；

设定两个指针，最初位置分别为两个已经排序序列的起始位置；

比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；

重复步骤3直到某一指针达到序列尾；

将另一序列剩下的所有元素直接复制到合并序列尾。





算法代码：



void print(int a[], int n){
  for(int j= 0; j<n; j++){
    cout<<a[j] <<"  ";
  }
  cout<<endl;
}

//将r[i…m]和r[m +1 …n]归并到辅助数组rf[i…n]
void Merge(ElemType *r,ElemType *rf, int i, int m, int n)
{
  int j,k;
  for(j=m+1,k=i; i<=m && j <=n ; ++k){
    if(r[j] < r[i]) rf[k] = r[j++];
    else rf[k] = r[i++];
  }
  while(i <= m)  rf[k++] = r[i++];
  while(j <= n)  rf[k++] = r[j++];
  print(rf,n+1);
}

void MergeSort(ElemType *r, ElemType *rf, int lenght)
{ 
  int len = 1;
  ElemType *q = r ;
  ElemType *tmp ;
  while(len < lenght) {
    int s = len;
    len = 2 * s ;
    int i = 0;
    while(i+ len <lenght){
      Merge(q, rf,  i, i+ s-1, i+ len-1 ); //对等长的两个子表合并
      i = i+ len;
    }
    if(i + s < lenght){
      Merge(q, rf,  i, i+ s -1, lenght -1); //对不等长的两个子表合并
    }
    tmp = q; q = rf; rf = tmp; //交换q,rf，以保证下一趟归并时，仍从q 归并到rf
  }
}


int main(){
  int a[10] = {3,1,5,7,2,4,9,6,10,8};
  int b[10];
  MergeSort(a, b, 10);
  print(b,10);
  cout<<"结果：";
  print(a,10);
}





八、基数排序(Radix Sort)



算法思想：

基数排序：通过序列中各个元素的值，对排序的N个元素进行若干趟的“分配”与“收集”来实现排序。

分配：我们将L[i]中的元素取出，首先确定其个位上的数字，根据该数字分配到与之序号相同的桶中 。

收集：当序列中所有的元素都分配到对应的桶中，再按照顺序依次将桶中的元素收集形成新的一个待排序列L[ ] 。

对新形成的序列L[]重复执行分配和收集元素中的十位、百位...直到分配完该序列中的最高位，则排序结束。



算法代码：



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





四、使用Python实现


一、冒泡排序



冒泡排序算法的运作如下：



● 比较相邻的元素。如果第一个比第二个大，就交换他们两个。

● 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。

● 针对所有的元素重复以上的步骤，除了最后一个。

● 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。



以上节选自维基百科



代码实现：



def bubble_sort(numberlist):
    length = len(numberlist)
    for i in range(length):
        for j in range(1, length - i):
            if numberlist[j - 1] > numberlist[j]:
                numberlist[j], numberlist[j - 1] = numberlist[j - 1], numberlist[j]
    return numberlist



二、选择排序



选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。



以上节选自维基百科



代码实现：

def findSmallest(arr):  # 用于查找出数组中最小的元素，返回最小元素的索引。
    smallest = arr[0]
    smallest_index = 0
    for i in range(1, len(arr)):
        if smallest > arr[i]:
            smallest = arr[i]
            smallest_index = i
    return smallest_index

def selectSort(arr):
    newArr = []
    while arr:
        smallest = findSmallest(arr)
        newArr.append(arr.pop(smallest))
    return newArr






三、插入排序



步骤如下



● 从第一个元素开始，该元素可以认为已经被排序
● 取出下一个元素，在已经排序的元素序列中从后向前扫描
● 如果该元素（已排序）大于新元素，将该元素移到下一位置
● 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
● 将新元素插入到该位置后



重复步骤2~5



以上节选自维基百科



代码实现





def insert_sort(data):
    for k in range(1, len(data)):
        cur = data[k]
        j = k
        while j > 0 and data[j - 1] > cur:
            data[j] = data[j - 1]
            j -= 1
        data[j] = cur
    return data





四、希尔排序



希尔排序通过将比较的全部元素分为几个区域来提升插入排序的性能。这样可以让一个元素可以一次性地朝最终位置前进一大步。然后算法再取越来越小的步长进行排序，算法的最后一步就是普通的插入排序，但是到了这步，需排序的数据几乎是已排好的了（此时插入排序较快）。



以上节选自维基百科



代码实现：

def shell_sort(numberlist):
    length = len(numberlist)
    gap = length // 2
    while gap > 0:
        for i in range(gap, length):
            temp = numberlist[i]
            j = i
            while j >= gap and numberlist[j - gap] > temp:
                numberlist[j] = numberlist[j - gap]
                j -= gap
            numberlist[j] = temp
        gap = gap // 2
    return numberlist





五、归并排序



原理如下（假设序列共有{displaystyle n}个元素）：



● 将序列每相邻两个数字进行归并操作，形成{displaystyle ceil(n/2)}个序列，排序后每个序列包含两/一个元素

● 若此时序列数不是1个则将上述序列再次归并，形成{displaystyle ceil(n/4)}个序列，每个序列包含四/三个元素

● 重复步骤2，直到所有元素排序完毕，即序列数为1



以上节选自维基百科



代码如下：

def  merge(left, right):
    result = []
    while left and right:
        if left[0] < right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    if left:
        result += left
    if right:
        result += right
    return result


def merge_sort(numberlist):
    if len(numberlist) <= 1:
        return numberlist
    mid = len(numberlist) // 2
    left = numberlist[:mid]
    right = numberlist[mid:]

    left = merge_sort(left)
    right = merge_sort(right)
    return merge(left, right)





六、快速排序



从数列中挑出一个元素，称为“基准”（pivot），


● 重新排序数列，所有比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面（相同的数可以到任何一边）。在这个分割结束之后，该基准就处于数列的中间位置。这个称为分割（partition）操作。

● 递归地（recursively）把小于基准值元素的子数列和大于基准值元素的子数列排序。

● 递归到最底部时，数列的大小是零或一，也就是已经排序好了。这个算法一定会结束，因为在每次的迭代（iteration）中，它至少会把一个元素摆到它最后的位置去。



以上节选自维基百科



代码如下：

def quick_sort(array):
        if len(array) < 2:
            return array
        else:
            pivot = array[0]
            less = [i for i in array[1:] if i <= pivot]
            greater = [i for i in array[1:] if i > pivot]
            return quick_sort(less) + [pivot] + quick_sort(greater)



七、堆排序



若以升序排序说明，把数组转换成最大堆积(Max-Heap Heap)，这是一种满足最大堆积性质(Max-Heap Property)的二叉树：对于除了根之外的每个节点i, A[parent(i)] ≥ A[i]。



重复从最大堆积取出数值最大的结点(把根结点和最后一个结点交换，把交换后的最后一个结点移出堆)，并让残余的堆积维持最大堆积性质。

def heap_sort(numberlist):
    length = len(numberlist)
    def sift_down(start, end):
        root = start
        while True:
            child = 2 * root + 1
            if child > end:
                break
            if child + 1 <= end and numberlist[child] < numberlist[child + 1]:
                child += 1
            if numberlist[root] < numberlist[child]:
                numberlist[root], numberlist[child] = numberlist[child], numberlist[root]
                root = child
            else:
                break

# 创建最大堆
    for start in range((length - 2) // 2, -1, -1):
        sift_down(start, length - 1)

# 堆排序
    for end in range(length - 1, 0, -1):
        numberlist[0], numberlist[end] = numberlist[end], numberlist[0]
        sift_down(0, end - 1)

    return numberlist





八、计数排序



以上节选自维基百科


代码如下：

def counting_sort(numberlist, maxnumber):  # maxnumber为数组中的最大值
    length = len(numberlist)  # 待排序数组长度
    b = [0 for i in range(length)] # 设置输出序列，初始化为0
    c = [0 for i in range(maxnumber+ 1)]  # 设置技术序列，初始化为0
    for j in numberlist:
        c[j] = c[j] + 1
    for i in range(1, len(c)):
        c[i] = c[i] + c[i - 1]
    for j in numberlist:
        b[c[j] - 1] = j
        c[j] = c[j] - 1
    return b



五、总结





各种排序的稳定性，时间复杂度和空间复杂度总结：



我们比较时间复杂度函数的情况：



                          

时间复杂度函数O(n)的增长情况



所以对n较大的排序记录。一般的选择都是时间复杂度为O(nlog2n)的排序方法。



时间复杂度来说：



(1)平方阶(O(n2))排序

　　各类简单排序:直接插入、直接选择和冒泡排序；

 

(2)线性对数阶(O(nlog2n))排序

　　快速排序、堆排序和归并排序；



(3)O(n1+§))排序,§是介于0和1之间的常数。

       希尔排序



(4)线性阶(O(n))排序
　　基数排序，此外还有桶、箱排序。





说明：



当原表有序或基本有序时，直接插入排序和冒泡排序将大大减少比较次数和移动记录的次数，时间复杂度可降至O（n）；



而快速排序则相反，当原表基本有序时，将蜕化为冒泡排序，时间复杂度提高为O（n2）；



原表是否有序，对简单选择排序、堆排序、归并排序和基数排序的时间复杂度影响不大。



稳定性：



排序算法的稳定性:若待排序的序列中，存在多个具有相同关键字的记录，经过排序， 这些记录的相对次序保持不变，则称该算法是稳定的；若经排序后，记录的相对 次序发生了改变，则称该算法是不稳定的。 



稳定性的好处：排序算法如果是稳定的，那么从一个键上排序，然后再从另一个键上排序，第一个键排序的结果可以为第二个键排序所用。基数排序就是这样，先按低位排序，逐次按高位排序，低位相同的元素其顺序再高位也相同时是不会改变的。另外，如果排序算法稳定，可以避免多余的比较；



稳定的排序算法：冒泡排序、插入排序、归并排序和基数排序



不是稳定的排序算法：选择排序、快速排序、希尔排序、堆排序





选择排序算法准则：



每种排序算法都各有优缺点。因此，在实用时需根据不同情况适当选用，甚至可以将多种方法结合起来使用。



选择排序算法的依据



影响排序的因素有很多，平均时间复杂度低的算法并不一定就是最优的。相反，有时平均时间复杂度高的算法可能更适合某些特殊情况。同时，选择算法时还得考虑它的可读性，以利于软件的维护。一般而言，需要考虑的因素有以下四点：



1．待排序的记录数目n的大小；

2．记录本身数据量的大小，也就是记录中除关键字外的其他信息量的大小；

3．关键字的结构及其分布情况；

4．对排序稳定性的要求。



设待排序元素的个数为n.



1）当n较大，则应采用时间复杂度为O(nlog2n)的排序方法：快速排序、堆排序或归并排序序。



快速排序：是目前基于比较的内部排序中被认为是最好的方法，当待排序的关键字是随机分布时，快速排序的平均时间最短；


堆排序 ：  如果内存空间允许且要求稳定性的，



归并排序：它有一定数量的数据移动，所以我们可能过与插入排序组合，先获得一定长度的序列，然后再合并，在效率上将有所提高。



2）  当n较大，内存空间允许，且要求稳定性 =》归并排序



3）当n较小，可采用直接插入或直接选择排序。



直接插入排序：当元素分布有序，直接插入排序将大大减少比较次数和移动记录的次数。



直接选择排序 ：元素分布有序，如果不要求稳定性，选择直接选择排序



4）一般不使用或不直接使用传统的冒泡排序。



5）基数排序



它是一种稳定的排序算法，但有一定的局限性：

　　1、关键字可分解。

　　2、记录的关键字位数较少，如果密集更好

　　3、如果是数字时，最好是无符号的，否则将增加相应的映射复杂度，可先将其正负分开排序。



总结



以上所述是小编给大家介绍的必须知道的C语言 八大排序算法(收藏)，希望对大家有所帮助，如果大家有任何疑问请给我留言，小编会及时回复大家的。



-END-



