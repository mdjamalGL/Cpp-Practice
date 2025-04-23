#include <iostream>
#include <vector>
#include <math.h>

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

    A[U] = std::min(A[2*U + 1], A[2*U + 2]);
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
    A[Current_Node] = std::min(A[2*Current_Node + 1], A[2*Current_Node + 2]);

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
        return std::min(query(2*Current_Node + 1, LC, mid, L, mid, A), query(2*Current_Node + 2, mid + 1, RC, mid + 1, R, A));
    }

}
int query_tree(int L, int R, std::vector<int> &A, int n)
{
    return query(0, 0, n-1, L, R, A);
}

void build_tree(std::vector<int> &A, std::vector<int> &a)
{
    int n = a.size();
    build(0,0,n-1,A,a);
}

void update_tree(int U, int val, std::vector<int> &A, int n)
{
    update(0,0,n-1,U,val,A);
}
int main()
{
    int n, q;
    std::cin>>n>>q;

    std::vector<int> a(n);
    std::vector<int> A(2 * n - 1);

    for(auto &i : a)
    std::cin>>i;

    build_tree(A,a);

    char q_type;
    int param_1, param_2;

    while(q--)
    {
        std::cin>>q_type>>param_1>>param_2;
        if(q_type == 'u')
        {
            update_tree(param_1, param_2, A, n);
        }
        else
        {
            std::cout<<query_tree(param_1, param_2, A, n)<<std::endl;
        }
    }
    return 0;
}