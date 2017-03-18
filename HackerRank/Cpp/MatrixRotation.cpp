//https://www.hackerrank.com/challenges/matrix-rotation-algo

#include<iostream>

using namespace std;

struct node
{
    long val;
    node *next;
};
class CQueue
{
    public:
        int size;
        node *first,*last;
        CQueue()
        {
            size=0;
            first=last=NULL;
        }
        void enqueue(long val)
        {
            size++;
            node *a = new node;
            a->val=val;
            if(first==NULL)
            {
                first=a;
                first->next=last;
                last=a;
                last->next=first;
            }
            else
            {
                a->next=first;
                last->next=a;
                last=a;
            }
        }
        long dequeue()
        {
            long val =first->val;
            first=first->next;
            return val;
        }
        void traverse()
        {
            node *temp=first;
            while(true)
            {
                cout<<temp->val<<" ";
                temp=temp->next;
                if(temp==first)
                {
                    break;
                }
            }
        }
        void rotate(long r)
        {
            for(long i=0;i<r%size;i++)
            {
                first=first->next;
                last=last->next;
            }
        }
};
int main()
{
    int m,n;
    long r;
    cin>>m>>n>>r;
    long arr[m][n],newMat[m][n];
    int loops=min(m,n)/2;
    CQueue cQueues[loops];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    /*
    cout<<endl<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    */
    for(int i=0;i<loops;i++)
    {
        for(int j=i;j<n-i;j++)
        {
            cQueues[i].enqueue(arr[i][j]);
        }

        for(int j=i+1;j<m-i-1;j++)
        {
            cQueues[i].enqueue(arr[j][n-i-1]);
        }

        for(int j=n-i-1;j>=i;j--)
        {
            cQueues[i].enqueue(arr[m-i-1][j]);
        }

        for(int j=m-i-2;j>=i+1;j--)
        {
            cQueues[i].enqueue(arr[j][i]);
        }



        cQueues[i].rotate(r);

    }
    /*
    cQueues[0].traverse();
    cout<<" Size :"<<cQueues[0].size<<endl;
    cQueues[1].traverse();
    cout<<" Size :"<<cQueues[1].size<<endl;
    */
    for(int i=0;i<loops;i++)
    {
        for(int j=i;j<n-i;j++)
        {
            newMat[i][j]=cQueues[i].dequeue();
        }

        for(int j=i+1;j<m-i-1;j++)
        {
            newMat[j][n-i-1]=cQueues[i].dequeue();
        }

        for(int j=n-i-1;j>=i;j--)
        {
            newMat[m-i-1][j]=cQueues[i].dequeue();
        }

        for(int j=m-i-2;j>=i+1;j--)
        {
            newMat[j][i]=cQueues[i].dequeue();
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<newMat[i][j]<<" ";
        }
        cout<<endl;
    }

}
