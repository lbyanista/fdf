#ifndef FDF_H
#define FDF_H

#include "mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "gnl/get_next_line.h"

typedef struct s_fdf
{
    int height;
    int width;
    int **zmatrix;
    void *mlx_ptr;
    void *win_ptr;

}               t_fdf;

void read_file(char *file_name, t_fdf *data);
char		**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *c);

#endif