#include "../push_swap.h"

int	validate_args(int argc, char **argv) 
{
	int		i;
	char	**split_result;
	char	delimiter;
	int		split_result_length;
	int		result;
	char	**copy;

	i = 1;
	delimiter = ' ';
	copy = (char **)ft_calloc(argc + 1, sizeof(char *)); 
	while (i < argc)
	{
		copy[i - 1] = ft_strdup(argv[i]);
		if (check_for_space(copy[i - 1]))
		{
			ft_printf("space found -> must call split() function\n");			
			split_result_length = strings_num(copy[i - 1], delimiter); 
			split_result = ft_split(copy[i - 1], delimiter); 
			result = check_for_digits(split_result_length, split_result, copy[i - 1], 0);
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
			result = check_for_digits(0, NULL, copy[i - 1], 1);
			if (result)
				ft_printf("copy[i - 1]: OK: All the characters of this current copy[i - 1] are digits\n");
			else
				ft_printf("copy[i - 1]: Error\n");
		}
		i++;
	}
	return (result);
}