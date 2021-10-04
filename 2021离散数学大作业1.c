#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, i, j, k; //二维数组模拟矩阵，和循环计数器
    int run = 1;    //用于矩阵性质是否成立的判断

    printf("请输入关系转换后的矩阵，本程序将验证其自反性，反自反性，对称性，反对称性，传递性并输出结果\n");
    printf("输入矩阵的维数：");
    scanf("%d", &m);
    int a[m][m]; //关系矩阵M
    int c[m][m]; //M^2
    //输入矩阵
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("-----------------------\n");
    //预览矩阵
    printf("您输入的矩阵如下： \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {

            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    //自反性判断:主对角线元素全是1
    for (i = 0; i < m; i++)
    {
        if (a[i][i] == 0)
        {
            printf("此关系无自反性！\n");
            run = 0;
            break;
        }
    }
    if (run == 1)
    {
        printf("此关系有自反性！\n");
    }
    else
    {
        run = 1;
    }
    //反自反性判断:主对角线元素全是0
    for (i = 0; i < m; i++)
    {
        if (a[i][i] == 1)
        {
            printf("此关系无反自反性！\n");
            run = 0;
            break;
        }
    }
    if (run == 1)
    {
        printf("此关系有反自反性！\n");
    }
    else
    {
        run = 1;
    }
    //对称性判断:对称矩阵
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != a[j][i])
            {

                run = 0;
            }
        } //如果对称方向上的数不相等，则不是对称矩阵
    }
    if (run == 1)
    {
        printf("此关系有对称性！\n");
    }
    else
    {
        printf("此关系无对称性！\n");
        run = 1;
    }
    //非对称性判断 若rij＝1, 且i≠j, 则rji＝0
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 1 && i != j)
            {
                if (a[j][i] == 0)
                {
                    run = 1;
                }
                else
                {
                    run = 0;
                    break;
                }
            }
        } //如果对称方向上的数不相等，则不是对称矩阵
    }
    if (run == 1)
    {
        printf("此关系有反对称性！\n");
    }
    else
    {
        printf("此关系无反对称性！\n");
        run = 1;
    }
    //传递性判断 对M^2中1所在位置,M中相应位置都是1  0也可以
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < m; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * a[k][j];
            }
        }
    } // 计算M^2
      /*
    printf("为了判断传递性，应先计算关系矩阵的平方，输出如下：\n"); //输出M^2
   for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}*/
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                if (c[i][j] != 0)
                {

                    run = 0;
                }
            }
        }
    }

    if (run == 1)
    {
        printf("此关系有传递性！\n");
    }
    else
    {
        printf("此关系无传递性！\n");
    }
    return 0;
}
