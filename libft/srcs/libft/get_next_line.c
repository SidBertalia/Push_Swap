#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

static int	outputs(int n, char **buff, char **line)
{
	char	*temp;

	if (n < 0)
		return (-1);
	*line = ft_substr(*buff, 0, ft_strclen(*buff, '\n'));
	if (!line)
		return (-1);
	if (ft_strchr(*buff, '\n'))
	{
		temp = ft_strdup(ft_strchr(*buff, '\n') + 1);
		ft_strdel(&*buff);
		*buff = temp;
		return (1);
	}
	ft_strdel(&*buff);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff_line[MAX_FILE_DESCRIPTOR];
	char		*new_line;
	int			nbytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FILE_DESCRIPTOR || !line)
		return (-1);
	if (!(buff_line[fd]))
	{
		buff_line[fd] = ft_strdup("");
		if (!(buff_line[fd]))
			return (-1);
	}
	new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_line)
		return (-1);
	nbytes = read(fd, new_line, BUFFER_SIZE);
	while (nbytes && nbytes > 0)
	{
		new_line[nbytes] = '\0';
		buff_line[fd] = ft_strjoin_free(buff_line[fd], new_line);
		if (ft_strchr(buff_line[fd], '\n'))
			break ;
	}
	ft_strdel(&new_line);
	return (outputs(nbytes, &buff_line[fd], line));
}
