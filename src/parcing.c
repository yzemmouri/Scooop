#include "../include/scop.h"

void	error_exit(char *msg)
{
	ft_putendl(msg);
	exit(1);
}
int		num_elems_splited(char	**splited_line)
{
	int i;

	i = 0;
	while (splited_line[i])
		i++;
	return (i);
}

void	model_stock_data(t_scopenv *env)
{
	char	**splited_line;
	int		num;

	// printf("%s\n", env->rd_line);
	printf("%d ", env->v);
	if (env->rd_line[0] == 'v' && env->rd_line[1] == ' ')
	{
		splited_line = ft_strsplit(env->rd_line, ' ');
		// printf("%f %f %f\n", ft_atof(splited_line[1]), ft_atof(splited_line[2]), ft_atof(splited_line[3]));
		num = num_elems_splited(splited_line);
		if (num != 4)
			error_exit("error vertice format");
		env->vertices[3 * env->v] = ft_atof(splited_line[1]);
		env->vertices[3 * env->v + 1] = ft_atof(splited_line[2]);
		env->vertices[3 * env->v + 2] = ft_atof(splited_line[3]);
		env->v++;
		// printf("%s, %s, %s, %s\n", splited_line[0], splited_line[1], splited_line[2], splited_line[3]);
	}
	if (env->rd_line[0] == 'f' && env->rd_line[1] == ' ')
	{
		splited_line = ft_strsplit(env->rd_line, ' ');
		// printf("%s, %s, %s, %s\n", splited_line[0], splited_line[1], splited_line[2], splited_line[3]);
		env->f++;
	}
	free(env->rd_line);
	
}

void	count_vertice_faces(t_scopenv *env, char **av)
{
	env->fd = open(av[1], O_RDONLY);
	if (env->fd == -1)
		error_exit("model file cant be opened");
	while (get_next_line(env->fd, &env->rd_line) > 0)
	{
		if (env->rd_line[0] == 'v' && env->rd_line[1] == ' ')
			env->num_vertices++;
		if (env->rd_line[0] == 'f' && env->rd_line[1] == ' ')
			env->num_indices++;
		env->num_lines++;
	}
	if (env->num_lines == 0)
		error_exit("file is empty");
	if (env->num_vertices == 0)
		error_exit("no vertices in file");
	if (env->num_indices == 0)
		error_exit("no faces in file");
}

void model_parcing (t_scopenv *env, int ac, char **av)
{
    if (ac < 2)
        error_exit("error num args");
    // printf("%d\n", env->num_vertices);
	// printf("%d\n", env->num_indices);
	count_vertice_faces(env, av);
    env->fd = open(av[1], O_RDONLY);
	if (env->fd == -1)
		error_exit("model file cant be opened");
	printf("%d\n", env->num_vertices * 3);
	env->vertices = (float*)malloc(env->num_vertices * 3 * sizeof(float));
    while (get_next_line(env->fd, &env->rd_line) > 0)
	{
		model_stock_data(env);
		
	}
}