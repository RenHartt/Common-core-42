/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:22:55 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/25 14:19:35 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*get_env_value(char *name, t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name)) == 0)
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

void	update_pwd(t_env **env, char *newpwd)
{
	t_env	*pwd;
	char	**tab;

	pwd = get_env("PWD", *env);
	if (pwd)
		pwd->value[0] = newpwd;
	else
	{
		tab = ft_split(newpwd, ':');
		add_env(env, new_env("PWD", tab));
		free(newpwd);
		ft_free_tab((void *)tab);
	}
}

void	update_oldpwd(t_env **env, char *oldpwd)
{
	t_env	*old_pwd;
	char	**tab;

	old_pwd = get_env("OLDPWD", *env);
	if (old_pwd)
	{
		free(old_pwd->value[0]);
		old_pwd->value[0] = oldpwd;
	}
	else if (oldpwd)
	{
		tab = ft_split(oldpwd, ':');
		add_env(env, new_env("OLDPWD", tab));
		free(oldpwd);
		ft_free_tab((void *)tab);
	}
}

void	ft_cd(char *path, t_env **env)
{
	char	*oldpwd;
	char	*newpwd;

	if (path == NULL)
		path = get_env_value("HOME", *env);
	else if (ft_strncmp(path, "-", 1) == 0)
	{
		path = get_env_value("OLDPWD", *env);
		if (path)
			printf("%s\n", path);
		else
		{
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
			return ;
		}
	}
	if (chdir(path) == -1)
	{
		perror("cd");
		return ;
	}
	oldpwd = get_env_value("PWD", *env);
	newpwd = getcwd(NULL, 0);
	update_pwd(env, newpwd);
	update_oldpwd(env, oldpwd);
}
