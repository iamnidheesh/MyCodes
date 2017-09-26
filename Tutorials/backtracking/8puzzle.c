#include <stdio.h>
#include <stdlib.h>

void solve(int **);
int isSolvable(int **);
int vis[1000];
int main()
{
  int i,**board;
  board = (int **)malloc(3*sizeof(int *));
  board[0] = (int *)malloc(3*sizeof(int));
  board[1] = (int *)malloc(3*sizeof(int));
  board[2] = (int *)malloc(3*sizeof(int));
  for(i=0;i<3;i=i+1) {
    scanf("%d%d%d",&board[i][0],&board[i][1],&board[i][2]);
  }
  solve(board);
  return 0;
}
int hash(int ** board) {
	
	int i,j,c = 1,sum = 0;
        for(i = 0;i < 3;i++)
                for(j = 0;j < 3;j++) {
                        sum = sum + c*board[i][j];
			c++;
                }
//	printf("%d \n ",sum);
	return sum;	

}
void swap(int ** board,int i,int j,int k,int l) {
	
	int temp = board[i][j];
	board[i][j] = board[k][l];
	board[k][l] = temp;
}
void ppath(int ** board) {
	int i,j;
	printf("\n");
	for(i = 0;i < 3;i++) {
		for(j = 0;j < 3;j++) {
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
	printf("\n*------------*\n");
}
int puzzle(int **board,int x,int y) {
	//printf("hello\n");
	int i,j,c = 1;
	vis[hash(board)] = 1;
	for(i = 0;i < 3;i++)
		for(j = 0;j < 3;j++) {
			if(board[i][j] == 0)
				continue;
			else {
				if(board[i][j] == c)
					c++;
				else
					break;
			}
		}
	if(c == 9) {
		ppath(board);
		return 1;
	}
	int f = 0,g = 0,h = 0,k = 0;
	if(x < 2) {
		swap(board,x,y,x+1,y);
		if(!vis[hash(board)])
			f = puzzle(board,x+1,y);
		swap(board,x,y,x+1,y);
		if(f == 1) {
			ppath(board);
			return 1;
		}
		//swap(board,x,y,x+1,y);//right
	}
	if(x > 0) {
	//	printf("2\n");
		swap(board,x,y,x-1,y);
		if(!vis[hash(board)])
			g = puzzle(board,x-1,y);
		 swap(board,x,y,x-1,y);
		if(g == 1) {
			ppath(board);
			return 1;
		}
		//swap(board,x,y,x-1,y);// left
	}
	if(y > 0) {
	//	printf("3\n");
		swap(board,x,y,x,y-1);
		 if(!vis[hash(board)] && isSolvable(board))
			h = puzzle(board,x,y-1);
		swap(board,x,y,x,y-1);
		if(h == 1) {
			ppath(board);
			return 1;
		}
		//swap(board,x,y,x,y-1);//up
	}
	if(y < 2) {
	//	printf("4\n");
		swap(board,x,y,x,y+1);
		if(!vis[hash(board)] && isSolvable(board))
			k = puzzle(board,x,y+1);//down
		swap(board,x,y,x,y+1);
		if(k == 1) {
			ppath(board);
			return 1;
		}
		//swap(board,x,y,x,y+1);
	}
	vis[hash(board)] = 0;
	return 0;
}
int getInvCount(int *arr)
{
    int inv_count = 0,i,j;
    for (i = 0; i < 9 - 1; i++)
        for (j = i+1; j < 9; j++)
             if (arr[j] && arr[i] &&  arr[i] > arr[j])
                  inv_count++;
    return inv_count;
}
int isSolvable(int **board)
{	
	int i,j,arr[10];
	int c = 0;	
    for(i = 0;i < 3;i++)
	for(j = 0;j < 3;j++)
		arr[c++] = board[i][j];	
    int invCount = getInvCount(arr);
    if(invCount%2 == 1)
		printf("\nopt\n");
    return (invCount%2 == 0);
}
void solve(int **board)
{
	int i,j,x,y;
	for(i = 0;i < 3;i++) {
		if(board[i][0] == 0) {
			x = i;y = 0;break;
		}
		if(board[i][1] == 0) {
			x = i;y = 1;break;
		}
		if(board[i][2] == 0) {
			x = i;y = 2;break;
		}
  	}
	for(i = 0;i < 1000;i++)
		vis[i] = 0;
	if(isSolvable(board))
		puzzle(board,x,y);
	else
		printf("Not solvable\n");
  /* Print the steps required to solve the puzzle or print unsolvable */
}

