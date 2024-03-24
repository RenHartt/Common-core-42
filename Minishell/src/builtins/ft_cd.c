/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:22:55 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 16:23:07 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*get_env_value(char *name, t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name - 1)) == 0)
			return (env->value[0]);
		env = env->next;
	}
	return (NULL);
}

t_env	*get_env(char *name, t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name + 1)) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	ft_cd(char *path, t_env **env)
{
	char	*oldpwd;
	char	*newpwd;
	t_env	*pwd;
	t_env	*old_pwd;

	if (!path)
		path = get_env_value("HOME", *env);
	if (chdir(path) == -1)
	{
		perror("cd");
		return ;
	}
	oldpwd = get_env_value("PWD", *env);
	newpwd = getcwd(NULL, 0);
	pwd = get_env("PWD", *env);
	old_pwd = get_env("OLDPWD", *env);
	if (pwd)
		pwd->value[0] = newpwd;
	else
	{
		add_env(env, new_env("PWD", ft_split(newpwd, ':')));
		free(newpwd);
	}
	if (old_pwd)
		old_pwd->value[0] = oldpwd;
	else if (oldpwd)
	{
		add_env(env, new_env("OLDPWD", ft_split(oldpwd, ':')));
		free(oldpwd);
	}
}
