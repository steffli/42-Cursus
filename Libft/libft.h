/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:01:16 by stliu             #+#    #+#             */
/*   Updated: 2025/03/10 19:01:18 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
//remove stdio.h at the end when handing in
# include <stdio.h>

void	*ft_memset(void *ptr, int val, size_t num);
void	ft_bzero(void *ptr, size_t num);

#endif
