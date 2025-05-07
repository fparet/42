/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 04:08:52 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/05 20:53:39 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_ENV_H
# define VAR_ENV_H

# include "minishell.h"

int		expand_token_var(t_data *data, char *str, char **line, bool *var);
int		check_var(char *str, t_data *data);
char	*check_env(char *str, t_data *data);
char	*add_var(char *line, int *j, char *var, char c);

void	increment_both(int *i, int *j);
char	*fill_pid_str(char *buffer, int fd);
char	*get_pid(void);

#endif