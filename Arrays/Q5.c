#include <stdio.h>

typedef struct{
	int r;
	int c;
	int val;
}Element;

typedef struct{
	int r;
	int c;
	int non_zero;
	Element data[10000];
}SparseMatrix;

void inp(SparseMatrix* mat){
	printf("Enter rows and col : ");
	scanf("%d %d", &mat->r,&mat->c);
	printf("Enter no of non zero elements : ");
	scanf("%d",&mat->non_zero);
	printf("Enter non zero elements (row column element) :\n");
	for(int i=0;i<mat->non_zero;i++){
		scanf("%d %d %d",&mat->data[i].r,&mat->data[i].c,&mat->data[i].val);
	}
}

void prnt(SparseMatrix* mat){
	printf("Row\tColumn\tValue\n");
	for(int i=0;i<mat->non_zero;i++){
		printf("%d\t%d\t%d\n",mat->data[i].r,mat->data[i].c,mat->data[i].val);
	}
}

SparseMatrix addition(SparseMatrix* A,SparseMatrix* B){
	SparseMatrix res;
	if(A->r!=B->r || A->c!=B->c){
		printf("Dimensions don't match\n");
		return res;
	}
	int i=0,j=0,k=0;
	res.r = A->r;
	res.c = A->c;
	res.non_zero=0;

	while(i<A->non_zero && j<B->non_zero){
		if(A->data[i].r<B->data[j].r || (A->data[i].r==B->data[j].r && A->data[i].c<B->data[j].c)){
			res.data[k++]=A->data[i++];
		}
		else if(A->data[i].r>B->data[j].r || (A->data[i].r==B->data[j].r && A->data[i].c>B->data[j].c)){
			res.data[k++]=B->data[j++];
		}
		else{
			res.data[k]=A->data[i];
			res.data[k].val=A->data[i].val+B->data[i].val;
			if(res.data[k].val!=0) k++;
			i++; j++;
		}
	}

	while(i<A->non_zero){
		res.data[k++]=A->data[i++];
	}

	while(j<B->non_zero){
		res.data[k++]=B->data[i++];
	}

	res.non_zero=k;
	return res;
}

SparseMatrix subtract(SparseMatrix* A,SparseMatrix* B){
	SparseMatrix res;
	if(A->r!=B->r || A->c!=B->c){
		printf("Dimensions don't match\n");
		return res;
	}

	int i=0,j=0,k=0;
	res.r = A->r;
	res.c = A->c;
	res.non_zero=0;

	while(i<A->non_zero && j<B->non_zero){
		if(A->data[i].r<B->data[j].r || (A->data[i].r==B->data[j].r && A->data[i].c<B->data[j].c)){
			res.data[k++]=A->data[i++];
		}
		else if(A->data[i].r>B->data[j].r || (A->data[i].r==B->data[j].r && A->data[i].c>B->data[j].c)){
			res.data[k]=B->data[j++];
			res.data[k].val=-res.data[k].val;
			k++;
		}
		else{
			res.data[k]=A->data[i];
			res.data[k].val=A->data[i].val-B->data[i].val;
			if(res.data[k].val!=0) k++;
			i++; j++;
		}
	}

	while(i<A->non_zero){
		res.data[k++]=A->data[i++];
	}

	while(j<B->non_zero){
		res.data[k]=B->data[i++];
		res.data[k].val=-res.data[k].val;
		k++;
	}

	res.non_zero=k;
	return res;
	
}



int main(){
	SparseMatrix A;
	SparseMatrix B;
	SparseMatrix add;
	SparseMatrix sub;
	printf("Enter Matrix A\n");
	inp(&A);
	printf("Enter Matrix B\n");
	inp(&B);
	printf("Matrix A\n");
	prnt(&A);
	printf("\n");
	printf("Matrix B\n");
	prnt(&B);
	printf("\n");
	add=addition(&A,&B);
	printf("Addition of A and B :\n");
	prnt(&add);
	printf("\n");
	sub=subtract(&A,&B);
	printf("Subtraction of A and B :\n");
	prnt(&sub);

}