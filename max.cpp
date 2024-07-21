#include<iostream>
using namespace std;

int maxHeightOfTriangle(int red, int blue) {
        int maxr=0,maxb=0;
        int nr=red,nb=blue;
        int dr=1,db=2;
        int i=1;
        while(true)
        {
            if(i%2!=0)
            {   
                if(nr>=dr)
                {maxr++;
                nr=nr-dr;
                dr=dr+2;}
                else
                break;
            }
            else
            {
              if(nb>=db)
                {maxr++;
                nb=nb-db;
                db=db+2;}
                else
                break;   
            }
            i++;
            
        }
        cout<<maxr;
        i=1;
        dr=2;
        db=1;
        nr=red;
        nb=blue;
        
         while(true)
        {
            if(i%2!=0)
            {   
                if(nb>=db)
                {maxb++;
                nb=nb-db;
                db=db+2;}
                else
                break;
            }
            else
            {
              if(nr>=dr)
                {maxb++;
                nr=nr-dr;
                dr=dr+2;}
                else
                break;   
            }
             i++;
        }
        cout<<maxb;
        if(maxr>maxb)
            return maxr;
        else
            return maxb;
        
    }
int main()
{
    cout<<maxHeightOfTriangle(2,4);
}