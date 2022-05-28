#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define set_2bit(bit,index,value) bit |= (value<<(index*2))
#define set_4bit(bit,index,value) bit |= (value<<((index)*4))
#define b_compare(bit,index) ((((d>>((i+4)*4))&0xF) == ((d>>((((i+1)%3)+1)*4))&0xF)) || ((((d>>((i+4)*4))&0xF)) == ((d>>((((i+2)%3)+1)*4))&0xF)))
#define s_compare(bit,index) (((d>>(i+4)*4)&0xF) == ((d>>(i+1)*4)&0xF))


unsigned int d;

void init(){
    srandom(time(NULL));
    int table[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int x, i = 0; i < 3; i++) {
        do {
            x = random() % 10;
        } while (table[x] == -1);
        set_4bit(d,(i+4),table[x]);
        printf("%d\n",table[x]);
        table[x] = -1;
    }
}

void input(){
    int buf,n=3;
    while(n--){
        scanf("%d ",&buf);
        set_4bit(d,n,buf);
    }
}

void process(){
    if((d>>16) == ((d&0xFFF0)>>4)){ set_2bit(d,1,3); return ;}
    for(int i=0; i<3; i++){
        if(s_compare(d,i)) d+=4;
        if(b_compare(d,i)) d+=1; 
    }
}

void show(){
    printf("s: %d  b: %d",((d&0xC)>>2),(d&3));
}

int main(){
    d&0;
    init();
    do{
        d = d & 0xFFF0000;
        printf("\n%d",d);
        input();
        process();
        show();
    }while(((d&12)>>2)!=3);
}
