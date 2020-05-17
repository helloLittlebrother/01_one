#include<stdio.h>
int main(){
	int a[6],i,s;
	s=a[0];
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		if(a[i]>=s){
			s=s;
		}else{
			s=a[i];
		}
	}
	printf("%d",s);
	return 0;
}