#include <stdio.h>

void f(int i, int n){
	if(!n) return ;
	f(i/2,n-1);
	printf("%c",i%2 ? 'X':'O');
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<(1<<n); i++,puts("")){
		f(i,n);
	}
}