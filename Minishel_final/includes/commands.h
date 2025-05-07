/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:20:22 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 11:09:54 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

typedef struct s_tmp
{
	int	i;
	int	j;
	int	k;
}		t_tmp;

int		init_data2(t_data *data);
int		ft_nb_args(t_token *token);
int		*malloc_fd_redirections(t_data *data);
int		fill_pipe_indexes(t_data *data);

int		build_tab_exe(t_data *data);
int		process_tokens(t_data *data, t_tmp *tmp, t_token **token_ptr);
void	pipe_fill_fd_command(t_data *data, t_tmp *tmp);
int		init_cmd(t_data *data, t_tmp *tmp);
int		check_file(char *str);

int		append_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr);
int		here_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr);
int		out_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr);
int		in_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr);
int		cmd_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr);

int		create_here_doc_file(char *lim, t_data *data);
int		here_doc_loop(char *lim, int fd_w, t_data *data);
char	*var_and_nl(char *line, t_data *data);
char	*randomize_file(char *file);
void	error_eof(char *lim);

char	*get_path(char *command, char **env);
char	*check_path(char *command, char *path);
int		check_access(char *tab_path, char *command, char **command_path);

#endif