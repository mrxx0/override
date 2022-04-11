#include <stdlib.h>
#include <stdio.h>

void	main(){
	int	i;
	char	str[130];

	fgets(str, 100, stdin);

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	printf(str);
	exit(0);
}
