//
//  main.c - Sudoku solver by Jacopx

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int map;
    int lock;
} startmap;

startmap **mapread(FILE* fp, int n);
void mapprint(int n, startmap **game);
void solve(int n, startmap **game, int k);

int main(int argc, const char * argv[]) {
    
    int n=0;
    startmap **game;
    if (argc<=1)
        return 2;
    
    FILE *fp=fopen(argv[1], "r");
    
    if(fp==NULL)
        return 1;
    
    fscanf(fp,"%d", &n);
    if(n==0 || n!=9)
    {
        printf("File Error!");
        return 1;
    }
    
    game=mapread(fp, n);
    fclose(fp);
    int data[9]={1,2,3,4,5,6,7,8,9};
    
    return 0;
}

void solve(int n, startmap **game, int k) {
    
}

startmap **mapread(FILE* fp, int n) {
    int i;
    
    startmap **game=malloc(n*sizeof(startmap *));
    for(i=0; i<n; i++)
        game[i]=malloc(n*sizeof(startmap));
    
    for(i=0;i<n;i++) {
        for(int j=0;j<n;j++)
        {
            fscanf(fp, "%d", &game[i][j].map);
            if(game[i][j].map!=0)
                game[i][j].lock=1;
        }
    }
    
    return game;
}

void mapprint(int n, startmap **game) {
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ", game[i][j].map);
        printf("\n");
    }
    return;
}
