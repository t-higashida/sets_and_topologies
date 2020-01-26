#include<stdio.h>
#include<math.h>
#include<float.h>

void main(void){

	double x_1=2.5, y_1=0.0;
	double x_2=3.75,y_2=0.5;
	double x_3=5.0, y_3=0.0;
		
	double a,b,c;
	
	



}

/************************************************/
/* ‚Q“_(x_1,y_1),(x_2,y_2)‚ğ’Ê‚é’¼ü‚Ì®		*/
/*	y=ax+b										*/
/************************************************/
double a_yEQaPLUSb(double x_1,double y_1,double x_2,double y_2)
{
	if(x_1-x_2==0){
		return(0);
	}
	else{
		return((y_2-y_1)/(x_2-x_1));
	}	
}
/************************************************/
/* ‚Q“_(x_1,y_1),(x_2,y_2)‚ğ’Ê‚é’¼ü‚Ì®		*/
/*	y=ax+b										*/
/************************************************/
double b_yEQaPLUSb(double x_1,double y_1,double x_2,double y_2)
{
	if(x_1-x_2==0){
		return(0);
	}
	else{
		return((y_2-y_1)/(x_2-x_1));
	}	
}

