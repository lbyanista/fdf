#include "fdf.h"

int key_press(int key, void *data)
{
    printf("%d", key);
    return (0);
}

int main(int ac, char **av)
{
    t_fdf *data;
    int i,j;

    data = (t_fdf*)malloc(sizeof(t_fdf));
    read_file(av[1], data);
    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            printf("%3d", data->zmatrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    
    return 0;
}