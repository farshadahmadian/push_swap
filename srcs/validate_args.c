#include "../push_swap.h"

int	validate_args(int argc, char **argv)
{
	int		i;
	char	**split_result;
	char	delimiter;
	int		split_result_length;
	int		result;

	i = 1;
	delimiter = ' ';
	while (i < argc)
	{
		if (check_for_space(argv[i]))
		{	
			split_result_length = strings_num(argv[i], delimiter); 
			split_result = ft_split(argv[i], delimiter); 
			result = check_for_digits(split_result_length, split_result, argv[i], 0);
			if (result)
				ft_printf("split_result: OK: All the characters of all the splited strings are digits\n");
			else
			{
				ft_printf("split_result: Error\n");
				return (0);
			}
		}	
		else
		{
			printf("No space\n");
			result = check_for_digits(0, NULL, argv[i], 1);
			if (result)
				ft_printf("argv[i]: OK: All the characters of this current argv[i] are digits\n");
			else
				ft_printf("argv[i]: Error\n");
		}
		i++;
	}
	return (result);
}