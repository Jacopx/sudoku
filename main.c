//
//  main.c - Sudoku solver by Jacopx

#include <stdio.h>
#include <stdlib.h>

int **mapread(FILE* fp, int n);
void mapprint(int n, int **map);

int main(int argc, const char * argv[]) {
    
    int **map,n=0;
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
    
    map=mapread(fp, n);
    fclose(fp);
    
    
    mapprint(n, map);
    return 0;
}

int **mapread(FILE* fp, int n) {
    
    int i, **map=calloc(0,n*sizeof(int));
    
    for(i=0; i<n; i++)
        map[i]=calloc(0,n*sizeof(int));
    
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(fp, "%d", &map[i][j]);
    
    return map;
}

void mapprint(int n, int **map) {
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    return;
}
