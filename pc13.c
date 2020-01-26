#include<stdio.h>
#include<math.h>

/*************************/
/* xy	\geqq	1�̐}	 */
/*************************/


void main(void){
	
	double t,x,y;
	int	h_scale	=	7;
	int	v_scale	=	7;
	/*************************/
	/*�@�}�`���̐ݒ�@�@	 */
	/*************************/
	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(%d,%d)\n",h_scale,v_scale);

	/*************************/
	/*�@���W���̕`��@�@	 */
	/*************************/
	printf("%���W��\n");
	printf("\\thicklines\\put(-1,0){\\vector(1,0){%d}}\n",h_scale);
	printf("\\thicklines\\put(0,-1){\\vector(0,1){%d}}\n",v_scale);

	/*****************************/
	/*�@���E���̕`��@�@�@  	 */
	/*****************************/
	printf("\n");
	printf("%���E��xy=1\n");
	for(t=0.17;t<=v_scale-1.3;t=t+.01) {
		printf("\t\\path\(%f,%f\)\(%f,%f\)\n",t,1/t,t+0.01	,1/(t+.01));
	}
	/*********************/
	/*�@�̈�̕`��@�@	 */
	/*********************/
	printf("\n");
	printf("%���E��xy=1\n");
	printf("\t\\put(3.0,3.0)\{\$F\$\}\n");
	for(t=0.17;t<=v_scale-1.3;t=t+.1) {
		printf("\t\\thinlines\\path\(%f,%f\)\(%f,%f\)\n",t+0.1,1/(t+0.1),t,6.0);
	}
	

	/*************************/
	/*�@�}�`���̐ݒ�I��	 */
	/*************************/
	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}