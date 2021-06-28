#include <iostream>
#include <algorithm>

using namespace std;

int Containers( int *Array, int n)
{
    int i = 0, count = 1;
    int j = 1;

    while ( j<n )                       //selection function
    {
        if ( Array[j] <= Array[i]+4 )   //feasibility function
        {
            j++;
        }

        else
        {
            i = j;                      //objective function
            j++;
            count++;
        }
    }

    return count;                      //solution function
}

int main()
{
    int n, i, NoOfContainers;

    cin >> n;                   //number of products
       
    int weight[n];              // candidate set

    for ( i=0; i<n; i++ )     
    {                         // product weights array
        cin >> weight[i];
    }

    sort(weight,weight+n);      //The selection function
                                //sorting the weights of the products in ascending order

    NoOfContainers = Containers(weight,n);

    cout << NoOfContainers << endl;
}
