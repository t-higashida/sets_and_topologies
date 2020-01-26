#include<stdio.h>
#include<math.h>
#include<float.h>

#define DELTA_X_BORDER	0.06
#define DELTA_Y_BORDER	0.06

#define DELTA_X_STRIPE	0.06
#define DELTA_Y_STRIPE	0.06

void main(void){
	
	double t,x,y,
			x_start=DBL_MAX,
			y_start=DBL_MAX,
			x_end=DBL_MAX,
			y_end=DBL_MAX;
	
	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(5,1)\n");

	/*********************************/
	/* â~Çï`Ç≠                      */
	/*********************************/
	
	printf("\t\\thicklines\\put\(2,0\){\\circle{4}}\n");
	printf("\t\\thicklines\\path(-1,2.5)(5,2.5)(5,-2.5)(-1,-2.5)(-1,2.5)\n");

	/*********************************/
	/* â°ê¸Çà¯Ç≠                    */
	/*********************************/
	for(y=-3.0;y<=3.0;y=y+DELTA_Y_BORDER){
		for(x=-2.0;x<=6.0;x=x+DELTA_X_BORDER){
			if(x_start==DBL_MAX && y_start==DBL_MAX){
				if(
						((x-2)*(x-2)+y*y>=4) 		&&
						(-1<=x)	&&	(x<=5)	&&
						(-2.5<=y)	&&	(y<=2.5)
				){
					x_start=x;
					y_start=y;
				}
			}
			if( x_start	!=DBL_MAX	&& y_start	!=DBL_MAX &&
				x_end	==DBL_MAX	&& y_end	==DBL_MAX
			){
				if(
						(x-2+DELTA_X_BORDER)*(x-2+DELTA_X_BORDER)+(y)*(y)<4	||

						(x+DELTA_X_BORDER<-1)	||	(5<x+DELTA_X_BORDER)	||
						(y<-2.5)					||	(2.5<y)

				){
					x_end=x;
					y_end=y;
				}
			}
			if (x_start	!=DBL_MAX	&& y_start	!=DBL_MAX &&
				x_end	!=DBL_MAX	&& y_end	!=DBL_MAX
			){
				printf("\t\\thinlines\\path(%f,%f)(%f,%f)\n",x_start,y_start,x_end,y_end);
				x_start=DBL_MAX;
				y_start=DBL_MAX;
				x_end=DBL_MAX;
				y_end=DBL_MAX;
			}
		}
	}
	/*********************************/
	/* ècê¸Çà¯Ç≠                    */
	/*********************************/
	for(x=-2.0;x<=6.0;x=x+DELTA_X_BORDER){
		for(y=-3.0;y<=3.0;y=y+DELTA_Y_BORDER){
			if(x_start==DBL_MAX && y_start==DBL_MAX){
				if(
						(x-2)*(x-2)+y*y>4	&&
						(-1<=x)	&&	(x<=5)	&&
						(y>=-2.5)	&&	(y<=2.5)
				){
					x_start=x;
					y_start=y;
				}
			}
			
			if( x_start!=DBL_MAX && y_start!=DBL_MAX &&
				x_end==DBL_MAX   && y_end==DBL_MAX
			){
				if(
						(x-2)*(x-2)+(y+DELTA_Y_STRIPE)*(y+DELTA_Y_STRIPE)<4	||
						(x<-1)					||	(5<x)					||
						(y+DELTA_Y_BORDER<-2.5)	||	(y+DELTA_Y_BORDER>2.5)
				){
					x_end=x;
					y_end=y;
				}
			}
			if (x_start	!=DBL_MAX && y_start!=DBL_MAX &&
				x_end	!=DBL_MAX && y_end	!=DBL_MAX
			){
				printf("\t\\thinlines\\path(%f,%f)(%f,%f)\n",x_start,y_start,x_end,y_end);
				x_start=DBL_MAX;
				y_start=DBL_MAX;
				x_end=DBL_MAX;
				y_end=DBL_MAX;
			}
		}
	}
	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
