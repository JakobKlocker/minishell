#include "minishell.h"

void    acess_env(t_info *info, int id)
{
    char *buf;
    t_envlst *temp;

    temp = info->envp;
    while (temp->next && id == 1)
    {
        if (ft_strncmp(temp->var, "OLDPWD", 6) == 0)
        {
            buf = getcwd(NULL, 0);
            temp->var = ft_strjoin("OLDPWD=", buf);
        }
        temp = temp->next;
    }
    while (temp->next && id == 0)
    {
        if (ft_strncmp(temp->var, "PWD", 3) == 0)
        {
            buf = getcwd(NULL, 0);
            temp->var = ft_strjoin("PWD=", buf);
        }
        temp = temp->next;
    }
}

static int	getlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*check_malloc(char const *s1, char const *s2)
{
	char	*ret;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = getlen((char *)s1) + getlen((char *)s2);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	ret = check_malloc(s1, s2);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if ((size_t)-1 / nmemb < size)
		return (NULL);
	if (size == 0 || nmemb == 0)
		return (NULL);
	ret = malloc(nmemb * size);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, nmemb * size);
	return (ret);
}


