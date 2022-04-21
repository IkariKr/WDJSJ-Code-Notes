#include "iostream"
using namespace std;

#define MaxSize 10

//顺序表的静态实现
template <class ElemType>
struct SqList
{
    ElemType data[MaxSize] int length;
};

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

//初始化
void InitList(SqList &L)
{
    //可省略
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

//查
bool GetElem(SqList L, int index, int data)
{
    if (index > L.length)
    {
        return false;
    }
    data = L.data[index - 1];
    return true;
}

//顺序表的实现-动态分配
typedef struct
{
    int *data;
    int SeqMaxSize;
    int length;
} SeqList;

//初始化顺序表-动态分配
#define InitSize 100
void InitList(SeqList &L)
{
    //用malloc申请一片连续的储存空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.SeqMaxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((len + L.SeqMaxSize) * sizeof(int));
    //将数据复制到新区域
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.SeqMaxSize = len + L.SeqMaxSize; //顺序表最大长度增加len
    free(p);
}

//插入
bool ListInsert(SqList &L, int i, int e)
{
    if(i<1||i>L.length+1){
        return false;
    }
    if(L.length>=MaxSize){
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

//删除
bool ListDelete(SqList &L, int i, int &e)
{
    if(i<1||i>L.length+1){
        return false;
    }
    e=L.data[i-1];
    for (int j = i;j<L.length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

//按位查找
int GetElem(SqList L,int i){
    return L.data[i-1];
}

int LocateElemt(SqList L,int e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}



int main()
{
    SqList L;
    InitList(L);

    SeqList seqL;
    InitList(seqL);

    IncreaseSize(seqL, 30);

    return 0;
}