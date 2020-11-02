#include <iostream>
using namespace std;

class diagonal
{
    int n;
    int* d;

public:

    diagonal(int size=10)
    {
        n = size;
        d = new int[n];
    }

    ~diagonal()
    {
        delete[] d;
    }

    void store(int x, int i, int j);
    int get(int i, int j);
    void show();
};

void diagonal::store(int x, int i, int j) {

    if(i<0 || j<0 || i>n || j>n)
    {
        cout<<"\nOut of Bounds!";
        exit(-1);
    }

    else if(i == j)
    {
        d[i] = x;
    }

    else if(i!=j && x !=0)
    {
        cout<<"\nMust be 0.";
        return;
    }
}

int diagonal::get(int i, int j) {

    if(i<0 || j<0 || i>n || j>n)
    {
        cout<<"\nOut of Bounds!";
        exit(-1);
    }

    else if(i==j)
    {
       return d[i];
    }

    else
       return 0;
}

void diagonal::show() {

    for(int i=0; i<n; i++)
    {
        cout<<endl;
        for(int j=0; j<n; j++)
        {
            if (i!=j)
            {
                cout<<"0"<<" ";
            }

            else
            {
                cout<<d[i]<<" ";
            }
        }
    }
}

int main()
{
    int r=0, c=0;
    cout<<"\nEnter Rows: "; cin>>r;
    cout<<"\nEnter Columns: "; cin>>c;

    if(r != c)
    {
        cout<<"\nRows and Columns Must be Equal!";
        exit(-1);
    }

    diagonal d(c);
    int y=0;

    cout<<"\nEnter Elements: ";

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<"\nValue: ";
            cin>>y;
            d.store(y, i, j);
        }
    }

    d.show();
    cout<<"\n\n"<<d.get(2,2);

    return 0;
}