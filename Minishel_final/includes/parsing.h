/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 04:08:21 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/07 18:13:09 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

int		parsing(t_data *data);
int		parse_var(t_data *data);
void	redefine_token_types(t_data *data);
int		check_token(t_data *data, int count);

#endif