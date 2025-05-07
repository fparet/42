/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:12:57 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/21 11:39:50 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

extern volatile sig_atomic_t	g_signal_received;

typedef struct s_cmd
{
	char						*cmd;
	char						**arg;
	int							fd_in;
	int							fd_out;
}								t_cmd;

typedef enum e_state
{
	NOTHING,
	QUOTE,
	DQUOTE,
}								t_state;

typedef enum e_type
{
	CMD,
	PIPE,
	IN,
	OUT,
	APPEND,
	HERE,
	ARG,
	FILES,
	LIM,
	END
}								t_type;

typedef struct s_env
{
	char						*key;
	char						*value;
	struct s_env				*next;
}								t_env;

typedef struct s_token
{
	bool						var;
	bool						space;
	int							index;
	t_type						type;
	t_state						state;
	char						*value;
	struct s_token				*next;
	struct s_token				*prev;
}								t_token;

typedef struct s_data
{
	int							*index_pipe;
	char						*line;
	char						**env;
	t_token						*token;
	t_cmd						**commands;
	int							nb_pipes;
	int							*fd_redirections;
	t_env						*envp;
	int							fd_redir_size;
	int							cmd;
	int							return_value;
	int							exit;
	struct termios				orig_term;
}								t_data;

#endif
