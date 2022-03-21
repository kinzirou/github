#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define H 100
/*Hの値は3の倍数に1を足した数にしてください*/

struct KEN {
    struct KEN *prev;
    int zyan;
    struct KEN *next;
};
struct KEN header = {NULL, 0, NULL};

struct KEN *hand_check(struct KEN *p, int data);
int randam(void);

int main(void){
    
    int i;
    int y_hand;
    int c_hand;
    int c_hand_exe;
    int check;
    int *decide;
    struct KEN *hahahand;
    struct KEN *err;
    struct KEN *p;
	
	header.prev = header.next = &header;
    
    hahahand = header.prev;
    for(i = 1; i <= 2; i++){
        err = hand_check(hahahand, i);
        if(err == NULL){
            exit(1);
        }
    }
    
    decide = (int *)malloc(sizeof(int )*H);
    
    for(i = 0; i < H; i++){
        decide[i] = -1;
    }
    
    printf("グー:0  チョキ:1  パー:2\n");
    printf("レッツジャンケン！\n");
    printf("最初はグー、ジャンケン\n");
    scanf("%d", &y_hand);
    if(y_hand < 0 || y_hand >2){
        printf("実行者が不正を行いました。強制終了します");
        exit(0);
    }
    
    c_hand_exe = randam();
    decide[c_hand_exe] = c_hand_exe;
    
    for(i = 0; i < H; i++){
        if(decide[i] != -1){
            check = decide[i];
            break;
        }
    }
    
    if(check == 0){
        printf("コンピュータが不正を行いました。強制終了します。");
        exit(0);
    }else if(check <= H/3){
        c_hand = 0;
    }else if(check <= H/3 * 2){
        c_hand = 1;
    }else {
        c_hand = 2;
    }
    
    printf("あなたの手:");
    if(y_hand == 0){
        printf("グー");
    }else if(y_hand == 1){
        printf("チョキ");
    }else if(y_hand == 2){
        printf("パー");
    }
	putchar('\n');
	
    printf("コンピュータの手:");
    if(c_hand == 0){
        printf("グー");
    }else if(c_hand == 1){
        printf("チョキ");
    }else if(c_hand == 2){
        printf("パー");
    }
    putchar('\n');
	
    if(y_hand == c_hand){
        printf("あいこです。\n");
    }else {
        for(p = &header; p != NULL; p = p -> next){
            if(p -> zyan == y_hand){
                if(p -> next -> zyan == c_hand){
                    printf("コンピュータの勝ちです。\n");
                	break;
                }else {
                    printf("あなたの勝ちです。\n");
                	break;
                }
            }
        }
    }
    
    putchar('\n');
    return 0;
}

struct KEN *hand_check(struct KEN *p, int data){
    
    struct KEN *x;
    
    if(p == NULL){
        printf("insert:引数がおかしい");
        return NULL;
    }
    
    x = (struct KEN*)malloc(sizeof(struct KEN));
    if(x == NULL){
        printf("insert:メモリが足りない");
        return NULL;
    }
    
    x -> zyan = data;
    x -> prev = p;
    x -> next = p -> next;
    p -> next -> prev = x;
    p -> next = x;
    
    return x;
}

int randam(void){

    int magical;
    
    srand((unsigned) time(NULL));
    
    magical = rand()%H+0;
    
    return magical;
    
}