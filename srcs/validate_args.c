#include "../push_swap.h"

int	validate_args(int argc, char **argv) // if return 1 means inputs are all valid, if retunrs 0 means an invalid input has been found
{
	int		i;
	char	**split_result;
	char	delimiter;
	int		split_result_length;
	int		result;
	char	**copy;
	int		has_minus_or_plus;
	char	***

	i = 1;
	delimiter = ' ';
	split_result = NULL;
	has_minus_or_plus = 0;
	copy = (char **)ft_calloc(argc, sizeof(char *));
	if (!copy)
		exit(0);
	while (i < argc)
	{
		copy[i - 1] = ft_strdup(argv[i]);
		if (check_for_space(copy[i - 1]))
		{
			ft_printf("space found -> must call split() function\n");			
			split_result_length = strings_num(copy[i - 1], delimiter);
			split_result = ft_split(copy[i - 1], delimiter); 
			result = check_for_digits(split_result_length, split_result, copy[i - 1], 0, &has_minus_or_plus);
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
			result = check_for_digits(0, NULL, copy[i - 1], 1, &has_minus_or_plus); 
			if (result)
				ft_printf("copy[i - 1]: OK: All the characters of this current copy[i - 1] are digits\n");
			else
				ft_printf("copy[i - 1]: Error\n");
		}
		i++;
	}
	printf("---i: %d\n", i);
	return (free_double_pointer(copy, i - 2), free_double_pointer(split_result, split_result_length), result);
}
