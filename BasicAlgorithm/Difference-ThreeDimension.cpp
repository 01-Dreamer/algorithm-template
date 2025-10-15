void insert(int x1,int y1,int z1,int x2,int y2,int z2,int c)
{
    d[get(x1,y1,z1)]+=c;  
    d[get(x2+1,y1,z1)]-=c;
    d[get(x1,y2+1,z1)]-=c;
    d[get(x1,y1,z2+1)]-=c;
    d[get(x2+1,y2+1,z1)]+=c;
    d[get(x1,y2+1,z2+1)]+=c;
    d[get(x2+1,y1,z2+1)]+=c;
    d[get(x2+1,y2+1,z2+1)]-=c;
}