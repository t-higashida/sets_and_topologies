#include<stdio.h>
#include<math.h>
double function(double x);
double inversefunction(double x);
void main(void){
	double t;
	double dt=0.05;
	
	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(1.7,1)\n");

	for(t=-0.3;t<=6.5;t=t+dt){
		printf("\t\\thicklines \\path(%4.2f,%4.2f)(%4.2f,%4.2f) \n",t,function(t),t+dt,function(t+dt));
	}

	//printf("\%a‚ÌƒÂ‹ß–T\n");
	//printf("\t\\thinlines \\path(3.50,0.00)(3.50,%4.2f) \n",function(3.50));
	printf("\t\\thinlines \\path(4.00,0.00)(4.00,%4.2f) \n",function(4.00));
	//printf("\t\\thinlines \\path(4.50,0.00)(4.50,%4.2f) \n",function(4.50));	

	//printf("\t\\thinlines \\path(0.00,%4.2f)(3.50,%4.2f) \n",function(3.50),function(3.50));
	printf("\t\\thinlines \\path(0.00,%4.2f)(4.00,%4.2f) \n",function(4.00),function(4.00));
	//printf("\t\\thinlines \\path(0.00,%4.2f)(4.50,%4.2f) \n",function(4.50),function(4.50));	


	printf("\%‚†(a)‚ÌƒÃ‹ß–T\n");	
	printf("\t\\thinlines \\path(0.00,%4.2f)(%4.2f,%4.2f)\n",function(4.00)+1.7,inversefunction(function(4.00)+1.7),function(4.00)+1.7);
	printf("\t\\thinlines \\path(0.00,%4.2f)(%4.2f,%4.2f)\n",function(4.00)-1.7,inversefunction(function(4.00)-1.7),function(4.00)-1.7);

	printf("\t\\thinlines \\path(%4.2f,0.00)(%4.2f,%4.2f)\n",inversefunction(function(4.00)+1.7),inversefunction(function(4.00)+1.7),function(4.00)+1.7);
	printf("\t\\thinlines \\path(%4.2f,0.00)(%4.2f,%4.2f)\n",inversefunction(function(4.00)-1.7),inversefunction(function(4.00)-1.7),function(4.00)-1.7);

	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}

double function(double x){
	//return 0.075*(x-0.0)*(x-1.0)*(x-2.0)+0.25;
	return x;
}

double inversefunction(double y){
	double t;
	double dt=0.05;

	for(t=0.0;function(t+dt)<y;t=t+dt){
	}
	return(t);
}