/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 04:08:38 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/22 14:05:34 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "parsing.h"

int		cmd_token(t_data *data, int *i, char *str);
int		get_cmd_token(t_data *data, int start, int i, t_state state);
char	*remove_quote(char *str);
int		d_quote_token(t_data *data, int *i, char *str);
int		quote_token(t_data *data, int *i, char *str);

int		parse_token(t_data *data);

void	copy_inner_quote_content(char *str, char *tmp, int *i, int *j);
int		count_quote(char *str);
int		add_token(t_token **token, t_token *new);
t_token	*new_token(t_type type, t_state state, char *value, bool space);
void	free_list(t_token *token);

int		redir_token(t_data *data, int *i);
int		out_append_token(t_data *data, int *i);
int		in_here_token(t_data *data, int *i);
int		pipe_token(t_data *data, int *i);

int		concat_token(t_data *data);
void	redifine_index_token(t_data *data);
int		concat(t_token *token, t_token *token_next);

#endif