#include<stdio.h>
#include<math.h>
/*================= declaration des fonctions ========================*/

void pivo(float*,int);

/*================= la fonction principale ========================*/
int main()
{
      int i,j,N=1;
      float x[2],y[2],h[2],A[2][3],C0,C1,C,ep=0.0001,*p;
      p=&A[0][0];
      printf("donnez x0 et x1  arbitraires :\n");
      for(i=0;i<=N;i++)
     {
                       scanf("%f",&x[i]);
      
     } 
     do 
     {
                          
      /*matrice caracteristiqe*/
       y[0]= exp(x[0]+x[1])+x[0]-3;
       y[1]=exp(2*x[0]+x[1])+x[1] -4;
       A[0][0]=exp(x[0]+x[1])+1;
       A[0][1]=exp(x[0]+x[1]);
       A[1][0]=2*exp(2*x[0]+x[1]);
       A[1][1]=exp(2*x[0]+x[1])+1;
       A[0][2]=- y[0];
       A[1][2]=- y[1];
       
           printf("\n");
       
      pivo(A[0],N);
      
      h[0]=A[0][2];
      h[1]=A[1][2];
       x[0]=x[0]+h[0];
       x[1]=x[1]+h[1];
       C0=h[0]/x[0];
       C1=h[1]/x[1];
       C0=(C0<0)? -C0:C0;
       C1=(C1<0)? -C1:C1;
       C=C0+C1;
          printf("x0=%f   x1=%f   f0=%f   f1=%f\n",x[0],x[1],y[0],y[1]);/*=====visualisation des rÃ©sultat Ã  chaque iteration========*/
       }
       while(C>ep);
       printf("x0=%f   x1=%f   f0=%f   f1=%f\n",x[0],x[1],y[0],y[1]);
       
       
      scanf("%d",&i);
}

/*================= les fonctions ========================*/
void pivo(float* w,int N)
{           
      float s,ss;
      int i,j,k,l;
      for(i=0;i<=N;i++)
     {s=*(w+i*(N+2)+i);
      for(j=0;j<=N+1;j++)
     {*(w+i*(N+2)+j)=*(w+i*(N+2)+j)/s;}
     for(k=0;k<=N;k++)
     {ss=*(w+k*(N+2)+i);   
     if(k!=i)
     {for(l=0;l<=N+1;l++)
     {*(w+k*(N+2)+l)=*(w+k*(N+2)+l)-ss*(*(w+i*(N+2)+l));}
     }}}
     
} 
 