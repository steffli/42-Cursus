/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:05:10 by stliu             #+#    #+#             */
/*   Updated: 2025/03/16 19:04:04 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c && *s != '\0')
			s++;
		else
		{
			while (*s != c && *s != '\0')
				s++;
			count++;
		}
	}
	return (count);
}

static char	*get_word(const char *s, int str_start, int str_len)
{
	char	*str;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	str = malloc((str_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (j < str_len)
	{
		str[j] = s[str_start + j];
		j++;
	}
	str[str_len] = '\0';
	return (str);
}

// char	**get_matrix(char *s, int str_start, int str_end)
// {
// 	if (!arr[arr_index])
// 	{
// 		while (arr_index > 0)
// 		{
// 			free(arr[arr_index]);
// 			arr_index--;
// 		}
// 		free(arr);
// 	}
// 	return (NULL);
// }

char	**ft_split(char const *s, char c)
{
	int		i;
	int		str_start;
	int		str_len;
	int		arr_index;
	char	**arr;

	i = 0;
	arr_index = 0;
	arr = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		str_start = i--;
		str_len = 0;
		while (s[++i] != c && s[i] != '\0')
			str_len++;
		if (str_len)
			arr[arr_index++] = get_word(s, str_start, str_len);
	}
	arr[arr_index] = NULL;
	return (arr);
}

// int	main(void)
// {
// 	char	**result1;
// 	char	**result2;
// 	char	**result3;
// 	char	**result4;
// 	char	**result5;
// 	char	**result6;
// 	char	**result7;
// 	char	**result8;
// 	char	**result9;
// 	char	**result10;

// 	// Test case 1: Basic test with no consecutive delimiters
// 	result1 = ft_split("Hello,world,here,we,are", ',');
// 	printf("Test Case 1:\n");
// 	for (int i = 0; result1[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result1[i]);
// 		free(result1[i]); // Free each string after using it
// 	}
// 	free(result1); // Free the array of string pointers
// 	// Test case 2: Input with leading and trailing delimiters
// 	result2 = ft_split(",Hello,world,", ',');
// 	printf("\nTest Case 2:\n");
// 	for (int i = 0; result2[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result2[i]);
// 		free(result2[i]); // Free each string after using it
// 	}
// 	free(result2);
// 	// Test case 3: Input with multiple consecutive delimiters
// 	result3 = ft_split("One,,Two,,,Three", ',');
// 	printf("\nTest Case 3:\n");
// 	for (int i = 0; result3[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result3[i]);
// 		free(result3[i]); // Free each string after using it
// 	}
// 	free(result3);
// 	// Test case 4: Input with only delimiters
// 	result4 = ft_split(",,,,", ',');
// 	printf("\nTest Case 4:\n");
// 	for (int i = 0; result4[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result4[i]);
// 		free(result4[i]); // Free each string after using it
// 	}
// 	free(result4);
// 	// Test case 5: Empty string input
// 	result5 = ft_split("", ',');
// 	printf("\nTest Case 5:\n");
// 	if (result5[0] == NULL)
// 	{
// 		printf("Result: (empty array)\n");
// 	}
// 	free(result5);
// 	// Test case 6: Single word with no delimiters
// 	result6 = ft_split("Hello", ',');
// 	printf("\nTest Case 6:\n");
// 	for (int i = 0; result6[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result6[i]);
// 		free(result6[i]); // Free each string after using it
// 	}
// 	free(result6);
// 	// Test case 7: Input with no delimiters (spaces)
// 	result7 = ft_split("Hello world here", ' ');
// 	printf("\nTest Case 7:\n");
// 	for (int i = 0; result7[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result7[i]);
// 		free(result7[i]); // Free each string after using it
// 	}
// 	free(result7);
// 	// Test case 8: Delimiters at the end of the string
// 	result8 = ft_split("apple,banana,", ',');
// 	printf("\nTest Case 8:\n");
// 	for (int i = 0; result8[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result8[i]);
// 		free(result8[i]); // Free each string after using it
// 	}
// 	free(result8);
// 	// Test case 9: Delimiters at the beginning of the string
// 	result9 = ft_split(",apple,banana", ',');
// 	printf("\nTest Case 9:\n");
// 	for (int i = 0; result9[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result9[i]);
// 		free(result9[i]); // Free each string after using it
// 	}
// 	free(result9);
// 	// Test case 10: String with multiple spaces
// 	result10 = ft_split("  space  test  string ", ' ');
// 	printf("\nTest Case 10:\n");
// 	for (int i = 0; result10[i] != NULL; i++)
// 	{
// 		printf("Result[%d]: %s\n", i, result10[i]);
// 		free(result10[i]); // Free each string after using it
// 	}
// 	free(result10);
// 	return (0);
// }
