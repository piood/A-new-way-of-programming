#include<stdio.h>
#define maxn 1005
int a[maxn];
int main()
{
	int i = 0,j,max,min,s=0,d1,d,k,t,m,n,z=0;
	scanf("%d", &a[0]); 
	max = min = a[0];
	s += a[0];
	while (scanf("%d", &a[++i])!=EOF)
	{
		s += a[i];
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	double v,s2=0;
	v = 1.0 * s / i;
	s2 = 0;
	for (j = 0; j < i; j++)
		s2 += (a[j] - v) * (a[j] - v) / i;
	for(j=0;j<i;j++)
		for(k=0;k<j;k++)
			if (a[k] > a[k + 1])
			{
				t = a[k];
				a[k] = a[k + 1];
				a[k + 1] = t;
			}
	for (j = 0; j < i; j++)
		if (a[j] > v)
		{
			z = j;
			break;
		}
	if (a[1] <= a[0])
		d = a[0] - a[1];
	else
		d = a[1] - a[0];
	m = 0; n = 1;
	for (j = 1; j < i ; j++)
	{    
		if (a[j + 1] < a[j])
			d1 = -(a[j + 1] - a[j]);
		else
			d1= a[j + 1] - a[j];
		if (d1 < d)
		{
			d = d1;
			m = j;
			n = j+1;
		}
	}
	printf("一共有  %d  个数  最大值是：%d  最小值是：%d  平均值是：%lf\n",i, max, min, v);
	printf("最接近的两个值是  % d  和  %d  \n", a[m], a[n]);
	printf("它们的方差是：%lf\n", s2);
	printf("不超过平均数的个数有  %d  \n", z);
   return 0;
}
