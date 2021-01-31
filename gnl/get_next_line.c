#include "get_next_line.h"

int		exception(int read_size, char *backup, char **line)
{
	if (read_size == -1)
		return (-1);
	else
		*line = ft_strdup(backup);
	free(backup);
	return (0);
}

char	*gnl_strjoin(char *backup, char *buf, int read_size)
{
	char			*s;
	size_t			backup_len;

	backup_len = ft_strlen(backup);
	if (!(s = malloc(sizeof(char) * (backup_len + read_size + 1))))
		return (NULL);
	ft_memset(s, 0, backup_len + read_size + 1);
	ft_strlcat(s, backup, backup_len + 1);
	ft_strlcat(s, buf, read_size + 1);
	return (s);
}

int		newlinefind(char *backup)
{
	int		i;

	i = 0;
	while (*(backup + i))
	{
		if (*(backup + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}



int		get_next_line(int fd, char **line)
{
	static char		*backup; // newline 만나고 나서 뒤에 문자열 저장
	char			buf[BUFFER_SIZE + 1]; // read 하고 나서 저장할 공간
	int				read_size;
	char			*find;
	int				len;

	backup == NULL;
	while ((len = newlinefind(backup)) < 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			return (exception(read_size, backup, line));
		backup = gnl_strjoin(backup, buf, read_size);
	}

	int i = 0;
	line = malloc(sizeof(char) * len);
	while (i < len)
	{
		*(line + i) = *(backup + i);
		i++;
	}
	char *tmp;

	tmp = ft_strdup(backup);
	free(backup);
	backup = malloc(sizeof(char) * (ft_strlen(backup) - len + 1));
	i = 0;
	while (i < len)
		backup[i++] = tmp[len + i];
	free(tmp);
	// \n index 받아서 backup에 있는 것을 line에 넣기
	// 그 다음 어떻게 참고해서 read 하는지..?
	return (1);
}
