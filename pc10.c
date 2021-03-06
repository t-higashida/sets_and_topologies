#include<stdio.h>
#include<math.h>
#include<float.h>

#define DELTA_X_BORDER	0.01
#define DELTA_Y_BORDER	0.05

#define DELTA_X_STRIPE	0.1
#define DELTA_Y_STRIPE	0.01

void main(void){
	
	double t,x,y,
			x_start,
			y_start,
			x_end,
			y_end;


	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(5,3)\n");

	/*********************************/
	/*　左の図　　　　               */
	/*********************************/

		/*********************************/
		/* 座標軸（横軸）                */
		/*********************************/
		printf("\t\\thicklines\\put\(-7,3\){\\vector(1,0){6}}\n");

		/*********************************/
		/* 座標軸（縦軸）                */
		/*********************************/
		printf("\t\\thicklines\\put\(-4,0\){\\vector(0,1){6}}\n");

		/*********************************/
		/* 直線a=b　　　　               */
		/*********************************/
		printf("\t\\thicklines\\put\(-7,0\){\\line(1,1){6}}\n");

		/*********************************/
		/* 直線y=bの破線　               */
		/*********************************/
		for(t=-4;t<-1.5;t=t+0.3){
			printf("\t\\thinlines\\path(%4.2lf,5.5)(%4.2lf,5.5)\n",t,t+0.15);
		}

		/*********************************/
		/* 直線x=aの破線　               */
		/*********************************/
		for(t=3;t<5.5;t=t+0.3){
			printf("\t\\thinlines\\path(-1.5,%4.2lf)(-1.5,%4.2lf)\n",t,t+0.15);
		}

		/***************************/
		/* 文字a,b　               */
		/***************************/
		printf("\\put\(-1.5,2.5\)\{\\Large $a$\}\n");
		printf("\\put\(-4.5,5.5\)\{\\Large $b$\}\n");

		/***************************/
		/* 原点Ｏ　               */
		/***************************/
		printf("\\put\(-3.9,2.5\)\{\\Large $O$\}\n");

		/***************************/
		/* a=b　                   */
		/***************************/
		printf("\\put\(-4.5,-0.5\)\{\\Large $a=b$\}\n");

	/*********************************/
	/*　中央の図　　　               */
	/*********************************/

		/*********************************/
		/* 座標軸（横軸）                */
		/*********************************/
		printf("\t\\thicklines\\put\(-0.5,3\){\\vector(1,0){6}}\n");

		/*********************************/
		/* 座標軸（縦軸）                */
		/*********************************/
		printf("\t\\thicklines\\put\(2.5,0\){\\vector(0,1){6}}\n");

		/*********************************/
		/* 直線a=b　　　　               */
		/*********************************/
		printf("\t\\thicklines\\put\(-0.5,0\){\\line(1,1){6}}\n");

		/*********************************/
		/* 破線y=b      　               */
		/*********************************/
		for(t=2.5;t<3.5;t=t+0.3){
			printf("\t\\thicklines\\path(%4.2lf,5)(%4.2lf,5)\n",t,t+0.15);
		}

		/*********************************/
		/* 破線x=a      　               */
		/*********************************/
		for(t=3;t<5;t=t+0.3){
			printf("\t\\thicklines\\path(3.5,%4.2lf)(3.5,%4.2lf)\n",t,t+0.15);
		}

		/*********************************/
		/* 破線x=aと破線y=bの交点        */
		/*********************************/
		printf("\t\\thicklines\\put\(3.5,5\){\\circle{0.06}}\n");

		/*********************************/
		/* 領域に影をつける(横線）       */
		/*********************************/
		for(y=-0.10;y<6.01;y=y+DELTA_Y_BORDER){
			/************************/
			/*初期化								*/
			/************************/
			x_start	=DBL_MAX;
			y_start	=DBL_MAX;
			x_end		=DBL_MAX;
			y_end		=DBL_MAX;
			for(x=-1.0;x<=6.0;x=x+DELTA_X_BORDER){
				if(x_start==DBL_MAX && y_start==DBL_MAX){
					if(
							x<=y-0.5 && -0.5<=x && x<=5.5 && 0.0<=y && y<=6.0 
					){
						x_start=x;
						y_start=y;
					}
				}
				if( x_start	!=DBL_MAX	&& y_start	!=DBL_MAX &&
						x_end		==DBL_MAX	&& y_end		==DBL_MAX
				){
					if(
							x+DELTA_X_BORDER>y-0.5 || x+DELTA_X_BORDER<=-0.50 || 5.5<x+DELTA_X_BORDER || y<0.00 || 6.01<y 
					){
						x_end=x;
						y_end=y;
						printf("\t\\thinlines\\path(%4.2lf,%4.2lf)(%4.2lf,%4.2lf)\n",x_start,y_start,x_end,y_end);
						x_start	=DBL_MAX;
						y_start	=DBL_MAX;
						x_end		=DBL_MAX;
						y_end		=DBL_MAX;
					}
				}
			}
		}

		/***************************/
		/* 文字a,b　               */
		/***************************/
		printf("\\put\(3.5,2.5\)\{\\Large $a$\}\n");
		printf("\\put\(  2,  5\)\{\\Large $b$\}\n");

		/***************************/
		/* 原点Ｏ　               */
		/***************************/
		printf("\\put\(2.6,2.5\)\{\\Large $O$\}\n");

		/***************************/
		/* a<b　                   */
		/***************************/
		printf("\\put\(2.0,-0.5\)\{\\Large $a<b$\}\n");

	/*********************************/
	/*　右の図　　　　               */
	/*********************************/

		/*********************************/
		/* 座標軸（横軸）                */
		/*********************************/
		printf("\t\\thicklines\\put\(6,3\){\\vector(1,0){6}}\n");

		/*********************************/
		/* 座標軸（縦軸）                */
		/*********************************/
		printf("\t\\thicklines\\put\(9,0\){\\vector(0,1){6}}\n");

		/*********************************/
		/* 中心（0,0)半径1の円           */
		/*********************************/
		printf("\t\\thicklines\\put\(9,3\){\\circle{4}}\n");

		/*********************************/
		/* 領域に影をつける(横線）       */
		/*********************************/
		for(y=0.5;y<5.5;y=y+DELTA_Y_BORDER){
			/************************/
			/*初期化								*/
			/************************/
			x_start	=DBL_MAX;
			y_start	=DBL_MAX;
			x_end		=DBL_MAX;
			y_end		=DBL_MAX;
			for(x=7.0;x<=11.0;x=x+DELTA_X_BORDER){
				if(x_start==DBL_MAX && y_start==DBL_MAX){
					if(
							(x-9)*(x-9)+(y-3)*(y-3)<=4 && 7.0<=x && x<=11.0 && 1.0<=y && y<=5.0 
					){
						x_start=x;
						y_start=y;
					}
				}
				if( x_start	!=DBL_MAX	&& y_start	!=DBL_MAX &&
						x_end		==DBL_MAX	&& y_end		==DBL_MAX
				){
					if(
							(x-9+DELTA_X_BORDER)*(x-9+DELTA_X_BORDER)+(y-3)*(y-3)>4 || x<7.0 && 11.0<x || y<1.0 || 5.0<y 
					){
						x_end=x;
						y_end=y;
						printf("\t\\thinlines\\path(%4.2lf,%4.2lf)(%4.2lf,%4.2lf)\n",x_start,y_start,x_end,y_end);
						x_start	=DBL_MAX;
						y_start	=DBL_MAX;
						x_end		=DBL_MAX;
						y_end		=DBL_MAX;
					}
				}
			}
		}

		/*********************************/
		/* 破線y=b      　               */
		/*********************************/
		for(t=9.0;t<10.5;t=t+0.3){
			printf("\t\\thicklines\\path(%4.2lf,3.75)(%4.2lf,3.75)\n",t,t+0.15);
		}

		/*********************************/
		/* 破線x=a      　               */
		/*********************************/
		for(t=3;t<3.75;t=t+0.3){
			printf("\t\\thicklines\\path(10.5,%4.2lf)(10.5,%4.2lf)\n",t,t+0.15);
		}

		/*********************************/
		/* 破線x=aと破線y=bの交点        */
		/*********************************/
		printf("\t\\thicklines\\put\(10.5,3.75\){\\circle{0.06}}\n");

		/***************************/
		/* 文字a,b　               */
		/***************************/
		printf("\\put\(10.5,2.5\)\{\\Large $a$\}\n");
		printf("\\put\(8.5,3.75\)\{\\Large $b$\}\n");

		/***************************/
		/* 原点Ｏ　               */
		/***************************/
		printf("\\put\(9.1,2.5\)\{\\Large $O$\}\n");

		/***************************/
		/* 円と座標軸との交点      */
		/***************************/
		printf("\\put\(11.1,2.5\)\{\\Large  1\}\n");
		printf("\\put\( 6.5,2.5\)\{\\Large -1\}\n");
		printf("\\put\( 8.7,5.1\)\{\\Large  1\}\n");
		printf("\\put\( 8.6,0.5\)\{\\Large -1\}\n");

		/***************************/
		/* a^2+b^2<1               */
		/***************************/
		printf("\\put\(8.5,-0.5\)\{\\Large $a^2+b^2<1$\}\n");


	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
