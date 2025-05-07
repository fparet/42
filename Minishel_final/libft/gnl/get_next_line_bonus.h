/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:36:48 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 04:20:55 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd, bool *fail);
char	*get_line1(int fd, char *temp, int byte, bool *fail);
char	*get_line_2(char *temp);
char	*ft_join_and_strchr(char *temp, char *buff, int c, int event);
char	*ft_strjoingnl(char *s1, char *s2);
void	clear_static(char **tmp);
void	destroy(void) __attribute__((destructor));

#endif