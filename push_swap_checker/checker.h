/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:44:57 by jhotchki          #+#    #+#             */
/*   Updated: 2023/10/23 18:56:43 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include <stddef.h>
# include <fcntl.h>

size_t	ft_strlen_g(char *s);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_strchr_g(char *s, int c);
char	*get_next_line(int fd);

#endif
