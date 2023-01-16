int check_if_flag(char *str)
{
    int i;

    i = 0;
    if (str[i++] != '-')
        return (-1);
    while (str[i])
    {
        if (str[i] == 'n')
            i++;
        else
            return (-1);
    }
    return (0);
}