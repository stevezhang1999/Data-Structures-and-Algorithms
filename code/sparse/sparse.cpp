# include <iostream>
using namespace std;
# define MAX 1000
typedef int ElemType;

typedef struct{
    int i, j;
    ElemType e;
}Triple;

typedef struct{
    Triple data[MAX];
    int m, n, non_zeros;
}SparseMatrix;

SparseMatrix transpose(const SparseMatrix M){
    SparseMatrix T;
    T.m = M.n;
    T.n = M.m;
    T.non_zeros = M.non_zeros;

    int idx_trans=0;

    if(T.non_zeros != 0){
        for(int column=1; column<=M.n; column++){
            for(int idx_origin=0; idx_origin<M.non_zeros; idx_origin++){
                if(M.data[idx_origin].j == column){
                    T.data[idx_trans].j = M.data[idx_origin].i;
                    T.data[idx_trans].i = M.data[idx_origin].j;
                    T.data[idx_trans].e = M.data[idx_origin].e;
                    ++idx_trans;
                }
            }
        }
    }
    return T;
}

SparseMatrix fast_transpose(const SparseMatrix M){
    SparseMatrix T;
    T.m = M.n;
    T.n = M.m;
    T.non_zeros = M.non_zeros;
    int col_first[M.n];
    int col_ele_num[M.n]; // for M.data[index_origin] in M, get index_trans for T.data

    for(int col=0; col<M.n; col++){
        col_ele_num[col] = 0;
    } // initialization: 0
    for(int i=0; i<M.non_zeros; i++){
        col_ele_num[M.data[i].j - 1] += 1; // j in data[] start from 1, but here start from 0
    } // for original matrix, how many elements in each columns
    // for each column of original matrix, the first element should be placed where in new data[?]
    col_first[0] = 0;
    for(int i=1; i<M.n; i++){
        col_first[i] = col_first[i-1] + col_ele_num[i-1];
    }
    for(int idx_origin=0; idx_origin<M.non_zeros; idx_origin++){
        int idx_trans;
        idx_trans = col_first[M.data[idx_origin].j - 1];
        col_first[M.data[idx_origin].j - 1] += 1;
        T.data[idx_trans].i = M.data[idx_origin].j;
        T.data[idx_trans].j = M.data[idx_origin].i;
        T.data[idx_trans].e = M.data[idx_origin].e;
    }
    return T;
}

void write_sparse(SparseMatrix &sparse, int i, int j, ElemType ele, int pos){
    sparse.data[pos].i = i;
    sparse.data[pos].j = j;
    sparse.data[pos].e = ele;
    sparse.non_zeros += 1;
}

void display_complete(SparseMatrix sparse, string str=""){
    cout << "**********" << endl;
    if(!str.empty()) cout << str << endl;
    int m = sparse.m;
    int n = sparse.n;
    int index=0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(sparse.data[index].i == i && sparse.data[index].j == j){
                cout << sparse.data[index].e << " ";
                index++;
            }
            else    cout << "0 " ;
        }
        cout << endl;
    }
    cout << "**********" << endl;
}

void display_sparse(SparseMatrix sparse, string str=""){
    cout << "**********" << endl;
    if(!str.empty()) cout << str << endl;
    for(int i=0; i<sparse.non_zeros; i++){
        cout << sparse.data[i].i << " " << sparse.data[i].j << " " << sparse.data[i].e << endl;
    }
    cout << "**********" << endl;
}

int main(){
    SparseMatrix sparse;
    sparse.m = 5;
    sparse.n = 6;
    SparseMatrix trans;
    SparseMatrix fast_trans;
    
    write_sparse(sparse, 1, 1, 3, 0);
    write_sparse(sparse, 1, 5, 7, 1);
    write_sparse(sparse, 2, 3, -1, 2);
    write_sparse(sparse, 3, 1, -1, 3);
    write_sparse(sparse, 3, 2, -2, 4);
    write_sparse(sparse, 5, 4, 2, 5);
    write_sparse(sparse, 5, 6, 9, 6);

    trans = transpose(sparse);
    fast_trans = fast_transpose(sparse);

    display_complete(sparse, "Original sparse matrix:");
    display_sparse(trans, "Transpose sparse matrix table:");
    display_sparse(fast_trans, "Fast-transposed saprse matrix table:");
    display_complete(fast_trans, "Fast-transposed sparse matrix:");
    
    
    system ("Pause");
    return 0;
}