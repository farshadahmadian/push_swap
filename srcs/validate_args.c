#include "../push_swap.h"

int	validate_args(int argc, char **argv) 
{
	int		i;
	char	**split_result;
	size_t	split_num;

	i = 1;
	while (i < argc)
	{
		if (check_for_space(argv[i]))
		{
			ft_printf("space found -> must call split() function\n");			
			split_result = ft_split(argv[i], ' ');
			split_num = (sizeof(split_result));
			printf("sizeof(array of strings) %lu\n", split_num);
			printf("%p\n", split_result[30]);
			size_t j = 0;
			while (j < 40)
			{
				printf("split_result[%lu] = %s\n", j, split_result[j]);
				j++;
			}
		}	
		else
			printf("No space\n");
		i++;
	}
	return (0);
}