/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 06:31:12 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/24 08:59:57 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
// #include "env_list.h"
#include "signaux.h"
#include "free_etc.h"
#include "var_env.h"

void	error_eof(char *lim)
{
	ft_putstr_fd("\nwarning: here-document delimited by end-of-file (wanted `",
		2);
	ft_putstr_fd(lim, 2);
	ft_putstr_fd("')\n", 2);
}

char	*randomize_file(char *file)
{
	int				fd;
	unsigned int	rdm;
	char			*tmp;

	while (access(file, F_OK) == 0)
	{
		ft_free(file);
		fd = open("/dev/urandom", O_RDONLY);
		if (fd < 0)
			return (NULL);
		if (read(fd, &rdm, sizeof(unsigned int)) < 0)
			return (ft_free(file), ft_close(fd), NULL);
		ft_close(fd);
		tmp = ft_ltoa(rdm);
		if (!tmp)
			return (ft_free(file), NULL);
		file = ft_strjoin("/tmp/Here_doc_", tmp);
		ft_free(tmp);
		if (!file)
			return (NULL);
	}
	return (file);
}

char	*var_and_nl(char *line, t_data *data)
{
	int		len;
	char	*temp;

	len = check_var(line, data);
	temp = ft_calloc(len + 2, sizeof(char));
	if (!temp)
		return (NULL);
	if (data->env)
		if (expand_token_var(data, line, &temp, 0))
			return (ft_free(temp), NULL);
	temp[len] = '\n';
	ft_free(line);
	return (temp);
}

int	here_doc_loop(char *lim, int fd_w, t_data *data)
{
	char	*line;
	bool	fail;

	fail = true;
	while (1)
	{
		if (g_signal_received == 130)
			restore_terminal_settings(data);
		write(1, "Here_doc> ", 10);
		line = get_next_line(STDIN_FILENO, &fail);
		if (fail == true || g_signal_received == 130)
			return (-3);
		if (!line)
			return (error_eof(lim), ft_free(line), 0);
		if (ft_strncmp(line, lim, ft_strlen(lim) + 1) == 0)
			break ;
		line = var_and_nl(line, data);
		if (!line)
			return (-4);
		write(fd_w, line, ft_strlen(line));
		ft_free(line);
	}
	return (ft_free(line), 0);
}

int	create_here_doc_file(char *lim, t_data *data)
{
	int		fd_write;
	int		fd_read;
	char	*file;

	file = ft_strdup("/tmp/Here_doc_1");
	if (!file)
		return (-10);
	file = randomize_file(file);
	if (!file)
		return (-10);
	fd_write = open(file, O_CREAT | O_WRONLY, 0644);
	if (fd_write < 0)
		return (ft_free(file), fd_write);
	fd_read = open(file, O_RDONLY);
	if (fd_read < 0)
		return (ft_free(file), ft_close(fd_write), fd_read);
	unlink(file);
	signal_change(1);
	disable_echoctl();
	if (here_doc_loop(lim, fd_write, data))
		return (ft_free(file), ft_close(fd_read), ft_close(fd_write), -2);
	ft_close(fd_write);
	ft_free(file);
	return (fd_read);
}

// int	main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;
// 	int fd;
// 	char buff[2];

// 	fd = create_here_doc_file("eof", env);
// 	while (read(fd, buff, 1))
// 	{
// 		buff[1] = '\0';
// 		printf("%s", buff);
// 	}
// 	close(fd);
// }
