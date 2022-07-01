/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:57 by jihong            #+#    #+#             */
/*   Updated: 2022/07/01 16:09:37 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>


char	*get_next_line(int fd);
size_t	ft_strlenn(const char *c);
char	*ft_strnndup(char *str, size_t n);
int		check_newline(char *str);
char	*ft_strjoin_free(char *str1, char *str2);

#endif
