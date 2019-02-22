//  Dijktras Algorithm

#include <stdio.h>
#include <stdlib.h>
int INF = 999,
    n, array[50][50], cost[55][55];
int main()
{
	int i, j, k, v;
	printf("Enter total no vertices\n");
	scanf("%d", &n);
	printf("Enter the adjacency matrix for cost of edges\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0 && i != j)
			{
				array[i][j] = INF;
			}
			else
			{
				array[i][j] = cost[i][j];
			}
		}
	}

	printf("Adjacency matrix of cost of edges\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf(" %d ", array[i][j]);
		}
		printf("\n");
	}
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == j && cost[i][j] == 0)
				{
					array[i][j] = 0;
				}
				else
				{
					if (array[i][j] > array[i][k] + array[k][j])
					{
						array[i][j] = array[i][k] + array[k][j];
					}
				}
			}
		}
	}

	printf("Final Distance\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf(" %d ", array[i][j]);
		}
		printf("\n");
	}

	printf("Enter the vertices for shortest distance from it\n");
	scanf("%d", &v);
	for (i = v;;)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d to %d = %d\n", i, j, array[i][j]);
		}
		break;
	}
	return 0;
}
