short int BinarySearch(int *a,int x,short int l,short r) 
{
    if(l==r) return (short)-1;
    short int mid=(l+r)/2;
    if(x==a[mid]) return mid;
    if(x<a[mid]) return BinarySearch(a,x,l,mid);
    else return BinarySearch(a,x,mid+1,r);
}
int extreme(int *a,int x,int left,short int size)
{
    int lo=0;
    int hi=size;
    while(lo<hi) 
    {
        int mid=(lo+hi)/2;
        if(a[mid]>x||(left==1&&x==a[mid])) 
        {
            hi=mid;
        }
        else 
        {
            lo=mid+1;
        }
    }
    return lo;
}
int BNSrange(int *a,int x,short int tr[2],short int size)
{
    tr[0]=-1;tr[1]=-1;
    tr[0]=extreme(a,x,1,size);
    if(tr[0]==size||a[tr[0]]!=x) 
    {
        return 0;
    }
    tr[1]=extreme(a,x,0,size)-1;
    return 0;
}