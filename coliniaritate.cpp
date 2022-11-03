#include <iostream>
using namespace std;
void sortare(int v[], int st, int m, int dr, int n)
{
    int i = st,k = st,j = m + 1,t[n];

    while (i <= m && j <= dr) {
        if (v[i] <= v[j]) {
            t[k] = v[i];
            i++;
            k++;
        }
        else {
            t[k] = v[j];
            j++;
            k++;
        }
    }
    while (i <= m) {
        t[k] = v[i];
        i++;
        k++;
    }
    while (j <= dr) {
        t[k] = v[j];
        j++;
        k++;
    }
    for (int p = st; p <= dr; p++) {
        v[p] = t[p];
    }
}
void mergeSort(int v[], int st, int dr, int n)
{
    if (st < dr) {
        int m = (st + dr) / 2;
        mergeSort(v, st, m, n);
        mergeSort(v, m + 1, dr, n);
        sortare(v, st, m, dr, n);
    }
}

int main()
{ int A[100],B[100],C[100],D[100],E[100],i,j,k,m,n,ok=0;
cout<<"Introdu numarul de elemente ale multimilor:";
cin>>n;
   cout<<"Introdu elementele multimii A:";
   for(i=0;i<n;i++)
    cin>>A[i];

   cout<<"Introdu elementele multimii B:";
      for(i=0;i<n;i++)
       cin>>B[i];

   cout<<"Introdu elementele multimii C:";
       for(i=0;i<n;i++)
        cin>>C[i];
   mergeSort(B, 0, (n - 1), n);
    mergeSort(C, 0, (n - 1), n);

   for(i=0;i<n;i++)
       D[i]=2*B[i];

   for(i=0;i<n;i++)
  {
      for(j=0;j < n;j++)
       E[j] = A[i] + C[j];

       j=0;
       k=0;
       while(j < n && k < n)
        {      if(E[k] == D[j])
                  {
                      ok = 1;
                      break;

                  }
               if(D[j] < E[k])
                      j++;

                if(E[k] < D[j])
                      k++;

  }}

if(ok==0)
    cout<<"Nu exista A, B, C coliniare";
   else
    cout<<"Exista A,  B,  C coliniare";
return 0;
}
