/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:43:42 by fparet            #+#    #+#             */
/*   Updated: 2025/03/20 11:43:44 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

# include "minishell.h"

void	ft_cd(t_env *env_list, char *path, t_data *data);
void	ft_echo(char **args, int fd);
t_env	*create_env_node(char *key, char *value);
t_env	*init_env_list(char **envp);
t_env	*find_env_var(t_env *env_list, const char *key);
void	free_env_list(t_env *env_list);
void	ft_env(t_env *env_list, int fd);
void	handle_exit_command(t_data *data, char **args);
void	ft_add_env(t_env **env, char *key, char *value);
void	ft_export(t_env **env, char *arg);
void	ft_pwd(int fd);
void	ft_unset(t_env **env_list, char *key);
char	*ft_strndupbis(const char *s, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
bool	ft_verif_bultins(t_cmd *command, t_data *data);
char	*ft_join_args(char **args);
bool	ft_handle_builtin(char *cmd, char *args, t_env *env_list);
bool	ft_verif_is_bultins(t_cmd *command);
bool	ft_handle_is_builtin(char *cmd);
int		ft_strcmpsize(char *s1, char *s2);
char	*get_cd_target(t_env *env_list, char *path, int *add);
void	update_env_var(t_env *env_list, char *key, char *value);
void	update_pwd(t_env *env_list);
t_env	*find_env_var(t_env *env_list, const char *key);
void	print_exported_variables(t_env *env_list);
char	*get_key(char *arg);
void	print_exported_variables(t_env *env_list);
char	*get_value(char *arg);
void	ft_exit(t_cmd *command, t_data *data);
int		ft_verif_nb(char *str);
bool	verif_unset(t_cmd *command, t_data *data);
bool	verif_cmd_export(t_cmd *command, t_data *data);
void	while_verif_cmd(t_cmd *command, t_data *data);
bool	verif_cd(t_cmd *command, t_data *data);
bool	verif_pwd(t_cmd *command, t_data *data);
bool	verif_env(t_cmd *command, t_data *data);
bool	exit_verif(t_cmd *command, t_data *data);
bool	verif_export(char *str);
bool	verif_option(char *str);
bool	echo_verif(t_cmd *command, t_data *data);
bool	exit_verif(t_cmd *command, t_data *data);
char	*cd_add(t_env *env_list, char *path);
void	ft_export_plus(t_env **env, char *arg);
t_env	*cd_tiret(t_env *env_list);

#endif
