#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define N 4

int a[10][10],b[100][2];
int grade;

int judgedie();
int judgeflag(char move);
void change(char move);
void set();
void output();

int main()
{
	int flag,die,i,j,move;
	flag = 0;
	die = 0;
	grade = 0;
	memset(a,-1,sizeof(a));
	memset(b,0,sizeof(b));
	
	for(i = 1;i <= N; i++)
	{
		for(j = 1;j <= N; j++)
		{
			a[i][j] = 0;
		}
	}
	set();
	output();
	
	for(;;)
	{
		die = judgedie();
		if(die == 1) break;
		
		/*scanf("%c",&move);
		getchar();*/
		move = getch();
		flag = judgeflag(move);
		if(flag == 0) continue;
		
		change(move);
		set();
		output();
	}
	
	printf("Doom!!!\n");
	
	return 0;
}

//判断是否游戏结束 
int judgedie()
{
	int i,j,die = 1;
	
	for(i = 1;i <= N; i++)
	{
		if(die == 0) break;
		for(j = 1;j <= N; j++)
		{
			if(a[i][j] == 0) die = 0;
			if(die == 0) break;
			if(a[i][j] == a[i - 1][j]) die = 0;
			if(a[i][j] == a[i + 1][j]) die = 0;
			if(a[i][j] == a[i][j - 1]) die = 0;
			if(a[i][j] == a[i][j + 1]) die = 0;
		}
	}
	
	return die;
}

//判断是否可以按照规定方向移动 
int judgeflag(char move)
{
	int i,j,k,flag = 0;
	
	if(move == 'a')
	{
		for(i = 1;i <= N; i++)
		{
			if(flag == 1) break;
			for(j = 1;j <= N; j++)
			{
				if(flag == 1) break;
				if(a[i][j] != 0)
				{
					for(k = j - 1;k >= 1; k--)
					{
						if(flag == 1) break;
						if(a[i][k] == 0) flag = 1;
					}
					if(a[i][j] == a[i][j + 1] && j <= N - 1) flag = 1;
				}
			}
		}
	}
	else if(move == 'd')
	{
		for(i = 1;i <= N; i++)
		{
			if(flag == 1) break;
			for(j = N;j >= 1; j--)
			{
				if(flag == 1) break;
				if(a[i][j] != 0)
				{
					for(k = j + 1;k <= N; k++)
					{
						if(flag == 1) break;
						if(a[i][k] == 0) flag = 1;
					}
					if(a[i][j] == a[i][j - 1] && j >= 2) flag = 1;
				}
			}
		}
	}
	else if(move == 'w')
	{
		for(i = 1;i <= N; i++)
		{
			if(flag == 1) break;
			for(j = 1;j <= N; j++)
			{
				if(flag == 1) break;
				if(a[j][i] != 0)
				{
					for(k = j - 1;k >= 1; k--)
					{
						if(flag == 1) break;
						if(a[k][i] == 0) flag = 1;
					}
					if(a[j][i] == a[j + 1][i] && j <= N - 1) flag = 1;
				}
			}
		}
	}
	else if(move == 's')
	{
		for(i = 1;i <= N; i++)
		{
			if(flag == 1) break;
			for(j = N;j >= 1; j--)
			{
				if(flag == 1) break;
				if(a[j][i] != 0)
				{
					for(k = j + 1;k <= N; k++)
					{
						if(flag == 1) break;
						if(a[k][i] == 0) flag = 1;
					}
					if(a[j][i] == a[j - 1][i] && j >= 2) flag = 1;
				}
			}
		}
	}
	else flag = 0;
	
	return flag;
}

//移动 
void change(char move)
{
	int i,j,k,flag = 0;
	
	if(move == 'a') 
	{
		for(i = 1;i <= N; i++)
		{
			for(j = 1;j < N; j++)
			{
				flag = 0;
				for(k = j;k <= N; k++)
				{
					if(a[i][k] != 0) flag = 1;
				}
				if(flag == 0) break;
				if(a[i][j] == 0)
				{
					for(k = j;k < N; k++)
					{
						a[i][k] = a[i][k + 1];
					}
					a[i][N] = 0;
					j--;
				}
			}
			for(j = 1;j < N; j++)
			{
				if(a[i][j] == a[i][j + 1] && a[i][j] != 0)
				{
					a[i][j] = a[i][j] * 2;
					grade += a[i][j];
					for(k = j + 1;k < N; k++)
					{
						a[i][k] = a[i][k + 1];
					}
					a[i][N] = 0;
				}
			}
		}
	}
	if(move == 'd') 
	{
		for(i = 1;i <= N; i++)
		{
			for(j = N;j > 1; j--)
			{
				flag = 0;
				for(k = j;k >= 1; k--)
				{
					if(a[i][k] != 0) flag = 1;
				}
				if(flag == 0) break;
				if(a[i][j] == 0)
				{
					for(k = j;k > 1; k--)
					{
						a[i][k] = a[i][k - 1];
					}
					a[i][1] = 0;
					j++;
				}
			}
			for(j = N;j > 1; j--)
			{
				if(a[i][j] == a[i][j - 1] && a[i][j] != 0)
				{
					a[i][j] = a[i][j] * 2;
					grade += a[i][j];
					for(k = j - 1;k > 1; k--)
					{
						a[i][k] = a[i][k - 1];
					}
					a[i][1] = 0;
				}
			}
		}
	}
	if(move == 'w') 
	{
		for(i = 1;i <= N; i++)
		{
			for(j = 1;j < N; j++)
			{
				flag = 0;
				for(k = j;k <= N; k++)
				{
					if(a[k][i] != 0) flag = 1;
				}
				if(flag == 0) break;
				if(a[j][i] == 0)
				{
					for(k = j;k < N; k++)
					{
						a[k][i] = a[k + 1][i];
					}
					a[N][i] = 0;
					j--;
				}
			}
			for(j = 1;j < N; j++)
			{
				if(a[j][i] == a[j + 1][i] && a[j][i] != 0)
				{
					a[j][i] = a[j][i] * 2;
					grade += a[j][i];
					for(k = j + 1;k < N; k++)
					{
						a[k][i] = a[k + 1][i];
					}
					a[N][i] = 0;
				}
			}
		}
	}
	if(move == 's') 
	{
		for(i = 1;i <= N; i++)
		{
			for(j = N;j > 1; j--)
			{
				flag = 0;
				for(k = j;k >= 1; k--)
				{
					if(a[k][i] != 0) flag = 1;
				}
				if(flag == 0) break;
				if(a[j][i] == 0)
				{
					for(k = j;k > 1; k--)
					{
						a[k][i] = a[k - 1][i];
					}
					a[1][i] = 0;
					j++;
				}
			}
			for(j = N;j > 1; j--)
			{
				if(a[j][i] == a[j - 1][i] && a[j][i] != 0)
				{
					a[j][i] = a[j][i] * 2;
					grade += a[j][i];
					for(k = j - 1;k > 1; k--)
					{
						a[k][i] = a[k - 1][i];
					}
					a[1][i] = 0;
				}
			}
		}
	}
}

//随机增加数字 
void set()
{
	int i,j,r,count,random;
	
	count = 0;
	for(i = 1;i <= N; i++)
	{
		for(j = 1;j <= N; j++)
		{
			if(a[i][j] == 0)
			{
				count++;
				b[count][0] = i;
				b[count][1] = j;
			}
		}
	}
	if(count != 0)
	{
		srand((unsigned)time(NULL));
		r = rand();
		random = r % count + 1;
		if((r % 10 != 1)) a[b[random][0]][b[random][1]] = 2;
		else a[b[random][0]][b[random][1]] = 4;
	}
}

//输出 
void output()
{
	int i,j;
	printf(" ****      ****        *       **** \n");
	printf("*    *    *    *     * *      *    *\n");
	printf("   *      *    *    *  *       ****\n");
	printf(" *        *    *    ******    *    *\n");
	printf("******     ****        *       **** \n");
	printf("Your Score: %8d\n",grade);
	printf("|-------|-------|-------|-------|\n");
	printf("|       |       |       |       |\n");
	for(i = 1;i <= N; i++)
	{
		printf("|       |       |       |       |\n");
		printf("|");
		for(j = 1;j <= N; j++)
		{
			if(a[i][j] != 0) printf("%6d |",a[i][j]);
			else printf("       |");
		}printf("\n");
		printf("|       |       |       |       |\n");
		if(i != N) printf("|-------|-------|-------|-------|\n");
	}
	printf("|-------|-------|-------|-------|\n");
}
