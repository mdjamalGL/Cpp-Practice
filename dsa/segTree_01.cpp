#include <iostream>
#include <vector>

void build(int U, int L, int R, std::vector<int> &A, std::vector<int> &a)
{
    if(L == R)
    {
      A[U] = a[L];
      return ;
    }

    int mid = (L + R)/2;
    build(2*U + 1, L, mid, A, a);
    build(2*U + 2, mid + 1, R, A, a);

    A[U] = A[2*U + 1] + A[2*U + 2];
}
void build_tree(std::vector<int> &A, std::vector<int> &a)
{
    int n = a.size();
    build(0,0,n-1,A,a);
}

void update(int Current_Node, int LC, int RC, int Update_Index, int Val, std::vector<int> &A)
{
    if(LC == RC)
    {
        A[Current_Node] = Val;
        return;
    }
    int mid = (LC + RC)/2;

    if( Update_Index <= mid)
    {
        update(2*Current_Node + 1, LC, mid, Update_Index, Val, A);
    }
    else
    {
        update(2*Current_Node + 2, mid + 1, RC, Update_Index, Val, A);
    }
    A[Current_Node] = A[2*Current_Node + 1] + A[2*Current_Node + 2];

}

void update_tree(int U, int val, std::vector<int> &A, int n)
{
    update(0,0,n-1,U,val,A);
}

int query(int Current_Node, int LC, int RC, int L ,int R, std::vector<int> &A )
{
    if(LC >= L && RC <= R)
    {
        return A[Current_Node];
    }

    int mid = (LC + RC)/2;
    
    if(R <= mid)
    {
        return query(2*Current_Node + 1, LC, mid, L, R, A);
    }
    else if( L >= mid + 1)
    {
        return query(2*Current_Node + 2, mid + 1, RC, L, R, A);
    }
    else
    {
        return query(2*Current_Node + 1, LC, mid, L, mid, A) + query(2*Current_Node + 2, mid + 1, RC, mid + 1, R, A);
    }

}
int query_tree(int L, int R, std::vector<int> &A, int n)
{
    return query(0, 0, n-1, L, R, A);
}

int main()
{
    std::vector<int> a {1,2,3,4,5,6,7,8};
    std::vector<int> A(2 * a.size()-1, 0);

    build_tree(A,a);

    std::cout<<"Array : ";
    for(auto i : a)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Segment Tree : ";
    for(auto i : A)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Sum for (i : 2 to 5) : "<<query_tree(2, 5, A, a.size())<<std::endl;

    std::cout<<"Update index = 3 i.e. Val = 4 to 0"<<std::endl;
    std::cout<<"Before Update Segment Tree : ";
    for(auto i : A)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    update_tree(3,0,A,a.size());
    std::cout<<"After Update Segment Tree : ";
    for(auto i : A)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Sum for (i : 2 to 5) : "<<query_tree(2, 5, A, a.size())<<std::endl;
    return 0;
}