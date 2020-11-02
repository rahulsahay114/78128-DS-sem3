#include <iostream>
using namespace std;

class lower_diag
{
    int n;
    int *d;

public:

    lower_diag(int size=10)
    {
        n = size;
        d = new int[(n*(n-1))/2];
    }

    ~lower_diag()
    {
        delete[] d;
    }

    void store(int x, int i, int j);
    void show();
};

//i->row; j->column
void lower_diag::store(int x, int i, int j) {

    if(j <= i)
    {
        int k = i * (i-1)/2 + j - 1;
        d[k] = x;
    }

    else if(i<0 || j<0 || j>n || i>n)
    {
        cout<<"\nOut of bounds!";
        exit(-1);
    }

    else if(x != 0)
    {
        cout<<"\nMust be 0.";
        return;
    }
}

void lower_diag::show() {

    for(int i=1; i<=n; i++)
    {
        cout<<endl;
        for(int j=1; j<=n; j++)
        {
            if(i < j)
            {
                cout<<"0"<<" ";
            }

            else
            {
                int k = i * (i-1)/2 + j - 1;
                cout<<d[k]<<" ";
            }
        }
    }
}

int main() {

    int r=0, c=0, x=0;

    cout<<"\nEnter Rows: ";
    cin>>r;

    cout<<"\nEnter Columns: ";
    cin>>c;

    if(r != c)
    {
        cout<<"\nRows and Columns must be equal!";
        exit(-1);
    }

    lower_diag d(r);

    cout<<"\nEnter Values: ";
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            cout<<"\nValue "<<i<<", "<<j<<": ";
            cin>>x;
            d.store(x, i, j);
        }
    }

    d.show();

    return 0;
}
