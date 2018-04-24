#include <iostream>

using namespace std;

int main(){
	double c=1;
	double dt=0.001;
	double xmin = -2;
	double xmax = 2;
	double dx=0.01;
	int Nx=(xmax-xmin)/dx +1;
	int Nt=700;
	
	double *ynew = new double[Nx];
	double *yold = new double[Nx];
	//creacion y(x,t=0)
	int i;
	int j;
	double x=-2;
	int sep = Nt/4;
	for(i=0;i<Nx;i++)
	{
		
		if(x>0.5 or x<-0.5)
		{
			yold[i]=0;
		}else{
			yold[i]=0.5;
		}
		cout<<0<<" "<<x<<" "<<yold[i]<<endl;
		x+=dx;
	}
	//evolucion temporal

	for(j=1;j<=Nt;j++)//recorro tiempos
	{
		x=-2;//inicializo x otra vez en menos 2
		ynew[0]=0;//condicion de frontera
		ynew[Nx-1]=0;//condicion de frontera
		for(i=1;i<Nx-1;i++)
		{
			ynew[i]=yold[i]-c*dt*(yold[i]-yold[i-1])/(dx);//condicion de recursion
		}
		for(i=0;i<Nx;i++)
		{
			yold[i]=ynew[i];//actualizo el arreglo
		}
		if(j%sep==0)//mirar cuales t voy a imprimir
		{
			for(i=0;i<Nx;i++)
			{
				
				cout<<j<<" "<<x<<" "<<ynew[i]<<endl;
				x+=dx;//imprimo x y y actualizo x
			}
		}
	}
	return 0;
}
