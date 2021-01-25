#include "get_next_line.h"

unsigned int		mylen(char *s1, char *s2)
{
	unsigned int		len;

	len = 0;
	while (*s1++ != *s2)
		len++;
	return (len++);
}

char			*ft_strncpy(char *dest, char *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		*(dest + i) = *(s + i);
	*(dest + i) = 0;
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	int				res; // read() function return value
	static char		*backup; // newline 만나고 나서 뒤에 문자열 저장
	char			buf[BUFFER_SIZE + 1]; // read 하고 나서 저장할 공간
	char			*find; // strchr로 저장할 곳
	int				len;

	res = read(fd, buf, BUFFER_SIZE); // 멀라 일단 read 호출해서 buf에 때려 박음 담에 res에 eof 확인차 저장해뒀어.
	if (res == 0) return (0); // EOF 시  return 0

	find = ft_strchr(buf, '\n'); // buf에서 newline 찾기
	len = mylen(buf, find); // malloc과 strncpy를 위한 길이 구함
	backup = find++; // find는 '\n'부터이니 그 다음 주소부터 backup에 저장

	*line = malloc(sizeof(char) * len); // line에 malloc
	if (line == NULL) // malloc valid
		return (-1);

	*line = ft_strncpy(*line, buf, len); // line strncpy

	return (1);
}
