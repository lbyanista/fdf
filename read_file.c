#include "fdf.h"

int get_height(char *file_name)
{
    char *line;
    int fd;
    int height;

    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int			count_word(char *str, char c)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\0')
			j = 1;
		else if (j == 1)
		{
			k++;
			j = 0;
		}
		i++;
	}
	return (k);
}

int get_width(char *file_name)
{
    int width;
    int fd;
    char *line;

    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = count_word(line, ' ');
    close(fd);
    free(line);
    return (width);
}

void filling_matrix(int *zline, char *line)
{
    char **numbers;
    int i = 0;
    
    numbers = ft_split(line, ' ');
    while (numbers[i])
    {
        zline[i] = ft_atoi(numbers[i]);
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

void read_file(char *file_name, t_fdf *data)
{
    int fd;
    char *line;
    int i;

    i = 0;
    data->height = get_height(file_name);
    data->width = get_width(file_name);
    data->zmatrix = (int**)malloc(sizeof(int*) * (data->height + 1));
    while (i <= data->height)
        data->zmatrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        filling_matrix(data->zmatrix[i], line);
        free(line);        
        i++;
    }
    close(fd); 
    data->zmatrix[i] = NULL;
}