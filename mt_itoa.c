#include "minitalk.h"

static long	numlen(long n)
{
	long i;

	i = 1;
	while ((n /= 10) != 0)
		i++;
	return (i);
}

static char	*zero_condition(void)
{
	char	*n;

	if (!(n = (char*)malloc(2)))
		return (NULL);
	*n = '0';
	*(n + 1) = '\0';
	return (n);
}

static char	*negative_condition(long n)
{
	char	*strnum;
	long	len;

	len = numlen(n);
	if (!(strnum = (char*)malloc(len + 2)))
		return (NULL);
	mt_bzero(strnum, len + 2);
	strnum[0] = '-';
	while (n)
	{
		strnum[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (strnum);
}

char		*mt_itoa(long n)
{
	char	*strnum;
	long	len;

	if (n == 0)
		return (zero_condition());
	if (n < 0)
		return (negative_condition((long)(n * -1)));
	len = numlen(n);
	if (!(strnum = (char*)malloc(len + 1)))
		return (NULL);
	mt_bzero(strnum, len + 1);
	while (n)
	{
		--len;
		strnum[len] = (n % 10) + '0';
		n /= 10;
	}
	return (strnum);
}
