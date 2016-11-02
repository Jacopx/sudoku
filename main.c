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
void solve(int *solve, int n, startmap **game, int k);

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
    solve(data, n, game, 0);
    
    return 0;
}

void solve(int *solve, int n, startmap **game, int k) {
    int i, j, k;
    
    if(pos>=n*n)
    {
        mapprint(n, game);
        return 1;
    }
    
    i=pos/dim;
    j=pos%dim;
}

int disp (int pos,int *val,int *sol,int *mark, int n, int k,int count) {
    int i;
    if (pos >= k) {
        for (i=0; i<k; i++) printf("%d ", sol[i]); printf("\n");
        return count+1; }
    for (i=0; i<n; i++)
    {
        if (mark[i] == 0)
        {
            mark[i] = 1;
            sol[pos] = val[i];
            count = disp(pos+1, val, sol, mark, n, k,count);
            mark[i] = 0; 
        }
    } 
    return count;
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
