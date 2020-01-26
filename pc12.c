/*********************************************/
/*　二次関数の連続性をεδ論法で証明する図 　*/
/*********************************************/

#include<stdio.h>
#include<math.h>
#include<float.h>

#define DELTA_X_BORDER	0.05
#define DELTA_Y_BORDER	0.065

#define DELTA_X_STRIPE	0.065
#define DELTA_Y_STRIPE	0.006

/*********************************/
/* 点線のインターバルの定義      */
/*********************************/
#define TEN	0.05
#define SEN	0.1

void main(void){
	
	double t;

/*********************************/
/* texのpicture環境を出力        */
/*********************************/
	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(5,3)\n");

	/*********************************/
	/* 座標軸                        */
	/*********************************/

	printf("\t\\thicklines\\put\(-3,0\){\\vector(1,0){6}}\n");
	printf("\t\\thicklines\\put\(0,-0.5\){\\vector(0,1){7}}\n");

	/************************************/
	/* y=x^2の曲線　　　　　　　　　　　*/
	/************************************/

	for(t=-2.51;t<2.51;t=t+DELTA_X_BORDER){
		//printf("\t\\path\(%lf,%lf\)\(%lf,%lf\)\n",t,t*t*4/5,t+DELTA_X_BORDER,(t+DELTA_X_BORDER)*(t+DELTA_X_BORDER)*4/5);
		printf("\t\\path\(%lf,%lf\)\(%lf,%lf\)\n",t,t*t,t+DELTA_X_BORDER,(t+DELTA_X_BORDER)*(t+DELTA_X_BORDER));
	}

	/*********************************/
	/* Texのソース改行               */
	/*********************************/
	printf("\t\n");

	/*********************************/
	/* ε近傍の逆像　　              */
	/*********************************/
	for(t=0.0;t<0.49;t=t+SEN){
		printf("\t\\thinlines\\path\(0.7,%lf)\(0.7,%lf\)\n",t,t+TEN);
	}

	for(t=0.0;t<2.5*2.5;t=t+SEN){
		printf("\t\\thinlines\\path\(2.5,%lf)\(2.5,%lf\)\n",t,t+TEN);
	}

	for(t=0.0;t<0.7;t=t+SEN){
		printf("\t\\thinlines\\path\(%lf,0.49)\(%lf,0.49\)\n",t,t+TEN);
	}

	for(t=0.0;t<2.5;t=t+SEN){
		printf("\t\\thinlines\\path\(%lf,%lf\)\(%lf,%lf\)\n",t,2.5*2.5,t+TEN,2.5*2.5);
	}


	/*********************************/
	/* δ近傍の像　　　              */
	/*********************************/
	printf("\t\n");
	for(t=0.0;t<1.36*1.36;t=t+SEN){
		printf("\t\\thinlines\\path\(1.36,%lf)\(1.36,%lf\)\n",t,t+TEN);
	}

	printf("\t\n");
	for(t=0.0;t<2.3*2.3;t=t+SEN){
		printf("\t\\thinlines\\path\(2.3,%lf)\(2.3,%lf\)\n",t,t+TEN);
	}

	for(t=0.0;t<1.36;t=t+SEN){
		printf("\t\\thinlines\\path\(%lf,%lf\)\(%lf,%lf\)\n",t,1.36*1.36,t+TEN,1.36*1.36);
	}

	printf("\t\n");
	for(t=0.0;t<2.3;t=t+SEN){
		printf("\t\\thinlines\\path\(%lf,%lf)\(%lf,%lf\)\n",t,2.3*2.3,t+TEN,2.3*2.3);
	}

	/*********************************/
	/* f(a)の像　　　　　            */
	/*********************************/
	printf("\t\n");
	for(t=0.0;t<1.836*1.836;t=t+SEN){
		printf("\t\\thinlines\\path\(1.836,%lf)\(1.836,%lf\)\n",t,t+TEN);
	}
	/*********************************/
	/* (0,f(a))を付点                */
	/*********************************/
	printf("\t\n");
	printf("\t%");
	printf("f(a)のε近傍\n");
	printf("\t{\\small	\\put(-0.75,%lf){$f(a)$}}\n",1.836*1.836);


	/*********************************/
	/*　aの像　　　　　　            */
	/*********************************/
	printf("\t\n");
	for(t=-0.1;t<1.70;t=t+SEN){
		printf("\t\\thinlines\\path\(%lf,%lf)\(%lf,%lf\)\n",t,1.836*1.836,t+TEN,1.836*1.836);
	}
	/*********************************/
	/* (a,0)を付点　　               */
	/*********************************/
	printf("\t\n");
	printf("\t%aのδ近傍\n");
	printf("\t{\\small	\\put(1.65,-0.3){$a$}}\n");

	/*********************************/
	/* Texのソース改行               */
	/*********************************/
	printf("\t\n");

/*********************************/
/* texのpicture環境を出力        */
/*********************************/
	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
