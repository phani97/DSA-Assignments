#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 1001

int l[1048578],ri[1048578];
void merge(int a[],int p,int q,int r)
{
    int i,j;
    int n1 = q-p+1;
    int n2 = r-q;
    for(i=1;i <= n1 ;i++)
    {
        l[i] = a[p+i-1];
    }
    l[i] = INT_MAX;
    for(j=1;j <= n2 ;j++)
    {
        ri[j] = a[q+j];
    }
    ri[j] = INT_MAX;
    i = 1;
    j = 1;
    int k;
    for ( k = p; k <= r ; k++)
    {
        if(l[i] <= ri[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = ri[j];
            j++;
        }
    }

}
void Merge_sort(int a[],int p,int r)
{
    if (p < r)
    {
        int q = (p+r)/2;
        Merge_sort(a,p,q);
        Merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void way4(FILE *file1,FILE *file2,FILE *file3,FILE *file4,FILE *mer1)
{
   int i,count1 = 0,a,b,c,d,count2 = 0 ,count3 = 0 ,count4 = 0 ,num[5];
    fscanf(file1,"%d",&num[1]);
    fscanf(file2,"%d",&num[2]);
    fscanf(file3,"%d",&num[3]);
    fscanf(file4,"%d",&num[4]);
    a = num[1];
    b = num[2];
    c = num[3];
    d = num[4];
    for(i=0;i<(1024*1024*8*4);i++) 
    {
    Merge_sort(num,1,4);
        if(num[1] == a)
        {
	    fprintf(mer1,"%d\n",a);
            fscanf(file1,"%d",&num[1]);
            
            count1++;
        if(count1 == 1024*1024*8)
            num[1] = INT_MAX;
    a = num[1];
        }
        else if(num[1] == b)
        {
	     fprintf(mer1,"%d\n",b);        
             fscanf(file2,"%d",&num[1]);
            
            count2++;
        if(count2 == 1024*1024*8)
            num[1] = INT_MAX;
    b = num[1];
        }
        else if(num[1] == c)
        {
	    fprintf(mer1,"%d\n",c);
            fscanf(file3,"%d",&num[1]);
           
            count3++;
        if(count3 == 1024*1024*8)
            num[1] = INT_MAX;
    c = num[1];
        }
        else
        { 
	     fprintf(mer1,"%d\n",d);      
             fscanf(file4,"%d",&num[1]);
            
            count4++;
        if(count4 == 1024*1024*8)
            num[1] = INT_MAX;
    d = num[1];
        }
    }
}

void way8(FILE *file1,FILE *file2,FILE *file3,FILE *file4,FILE *file5,FILE *file6,FILE *file7,FILE *file8,FILE *mer1)
{
   int i,count1 = 0,a,b,c,d,e,f,g,h,count2 = 0 ,count8 = 0 ,count7 = 0 ,count6 = 0 ,count5 = 0 ,count3 = 0 ,count4 = 0 ,num[9];
    fscanf(file1,"%d",&num[1]);
    fscanf(file2,"%d",&num[2]);
    fscanf(file3,"%d",&num[3]);
    fscanf(file4,"%d",&num[4]);
    fscanf(file5,"%d",&num[5]);
    fscanf(file6,"%d",&num[6]);
    fscanf(file7,"%d",&num[7]);
    fscanf(file8,"%d",&num[8]);


    a = num[1];
    b = num[2];
    c = num[3];
    d = num[4];
    e = num[5];
    f = num[6];
    g = num[7];
    h = num[8];

    for(i=0;i<(1024*1024*8);i++) 
    {

    Merge_sort(num,1,8);

        if(num[1] == a)
        {
            fprintf(mer1,"%d\n",a);
            fscanf(file1,"%d",&num[1]);
            count1++;
        if(count1 == 1024*1024)
            num[1] = INT_MAX;
        a = num[1];

        }
        else if(num[1] == b)
        {  
	  fprintf(mer1,"%d\n",b);
          fscanf(file2,"%d",&num[1]);        
         
            count2++;
        if(count2 == 1024*1024)
            num[1] = INT_MAX;
        b = num[1];
        }
        else if(num[1] == c)
        {
	    fprintf(mer1,"%d\n",c);
            fscanf(file3,"%d",&num[1]);
            count3++;
        if(count3 == 1024*1024)
            num[1] = INT_MAX;
        c = num[1];
        }
        else if(num[1] == d)
        {   
	    fprintf(mer1,"%d\n",d);
            fscanf(file4,"%d",&num[1]);       

            count4++;
        if(count4 == 1024*1024)
            num[1] = INT_MAX;
        d = num[1];
        }
        else if(num[1] == e)
        {   
	    fprintf(mer1,"%d\n",e);
            fscanf(file5,"%d",&num[1]);       
            count5++;
        if(count5 == 1024*1024)
            num[1] = INT_MAX;
        e = num[1];
        }
    else if(num[1] == f)
        {  
	    fprintf(mer1,"%d\n",f);
            fscanf(file6,"%d",&num[1]);        
            count6++;
        if(count6 == 1024*1024)
            num[1] = INT_MAX;
        f = num[1];
        }
        else if(num[1] == g)
        { 
	    fprintf(mer1,"%d\n",g);
            fscanf(file7,"%d",&num[1]);         
          
            count7++;
        if(count7 == 1024*1024)
            num[1] = INT_MAX;
        g = num[1];
        }
        else 
        {  
	    fprintf(mer1,"%d\n",h);
            fscanf(file8,"%d",&num[1]);        
            count8++;
        if(count8 == 1024*1024)
            num[1] = INT_MAX;
        h = num[1];
        }
    }

}
void way2(FILE *ofile,FILE *nfile,FILE *mer1)
{
     int i,count1 = 0,count2 = 0 ,num1,num2;
    fscanf(ofile,"%d",&num1);
    fscanf(nfile,"%d",&num2);

    for(i=0;i<(1024*1024*64);i++) 
    {
        if(num1 < num2)
        {
	    fprintf(mer1,"%d\n",num1);
            fscanf(ofile,"%d",&num1);
            count1++;
        }
        else 
        {  
	    fprintf(mer1,"%d\n",num2);
            fscanf(nfile,"%d",&num2);        
            count2++;
        }
        if(count1 == 1024*1024*32)
            num1 = INT_MAX;
        if(count2 == 1024*1024*32)
            num2 = INT_MAX;
    }
	
}
int main()
{

    char n, p  ;
    int s = 1048576*64,size = 1048576*64,number,nsize;
    float average=0;
    char filename[64][10]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt","9.txt","10.txt",
                            "11.txt","12.txt","13.txt","14.txt","15.txt","16.txt","17.txt","18.txt","19.txt","20.txt",
                            "21.txt","22.txt","23.txt","24.txt","25.txt","26.txt","27.txt","28.txt","29.txt","30.txt",
                            "31.txt","32.txt","33.txt","34.txt","35.txt","36.txt","37.txt","38.txt","39.txt","40.txt",
                            "41.txt","42.txt","43.txt","44.txt","45.txt","46.txt","47.txt","48.txt","49.txt","50.txt",
                            "51.txt","52.txt","53.txt","54.txt","55.txt","56.txt","57.txt","58.txt","59.txt","60.txt",
                            "61.txt","62.txt","63.txt","64.txt"};
    char merge4[8][10]={"mer1.txt","mer2.txt","mer3.txt","mer4.txt","mer5.txt","mer6.txt","mer7.txt","mer8.txt"};
    char merge2[2][10] = {"s1.txt","s2.txt"};
    int w[1048577];

    FILE *ofile,*nfile;

    clock_t t;
    t = clock();
    ofile=fopen("big.txt","w");
    srand(time(NULL));
    while(size--)
    {
        number = rand()%595;
	fprintf(ofile,"%d\n",number);
        
    }
	fclose(ofile);
	ofile=fopen("big.txt","r");
    int k,u,v=1048577;
    s = 1048576*64;
    while(s > 0)
    {
        s = s - 1048576;
        nsize = 1048576;
	nfile=fopen(filename[k],"w");
       
    
        u = 1;

        while(nsize--)
        {
	    fscanf(ofile,"%d",&w[u]);
           
                u++;
        }
    
        Merge_sort(w,1,v+1);
    
        nsize = 1048576;
        
        u = 1;
        
        while(nsize--)
        {
		fprintf(nfile,"%d\n",w[u]);
            
                u++;
        }
        
        k++;
        fclose(nfile);
    }
	fclose(ofile);
   
    int l = 0;int i;
    FILE *mer1,*file1,*file2,*file3,*file4,*file5,*file6,*file7,*file8;
    for (i = 0; i < 64; i = i + 8)
    {
	file1=fopen(filename[i],"r");
        file2=fopen(filename[i+1],"r");
        file3=fopen(filename[i+2],"r");
        file4=fopen(filename[i+3],"r");
        file5=fopen(filename[i+4],"r");
        file6=fopen(filename[i+5],"r");
        file7=fopen(filename[i+6],"r");
        file8=fopen(filename[i+7],"r");
        mer1=fopen(merge4[l],"w");  
        l++;
        way8(file1,file2,file3,file4,file5,file6,file7,file8,mer1);
        fclose(file1);
        fclose(file2);
        fclose(file3);
        fclose(file4);
        fclose(file5);
        fclose(file6);
        fclose(file7);
        fclose(file8);
        fclose(mer1);
    }
    l = 0;  
    for (i = 0; i < 8; i = i + 4)
    {
        file1=fopen(merge4[i],"r");
        file2=fopen(merge4[i+1],"r");
        file3=fopen(merge4[i+2],"r");
        file4=fopen(merge4[i+3],"r");
        mer1=fopen(merge2[l],"w");  
        l++;
        way4(file1,file2,file3,file4,mer1);
        fclose(file1);
        fclose(file2);
        fclose(file3);
        fclose(file4);
        fclose(mer1);
    }
    char final[]={"output.txt"};
    file1=fopen(merge2[0],"r");
    file2=fopen(merge2[1],"r");
    mer1=fopen(final,"w");  
    way2(file1,file2,mer1);
    fclose(file1);
    fclose(file2);
    fclose(mer1);
    
}
