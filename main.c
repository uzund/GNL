/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:01:33 by duzun             #+#    #+#             */
/*   Updated: 2022/08/24 06:32:07 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*satir;
	char	*satir2;
	int		fd1;
	//int		fd2;
	//int		fd3;

	(void) ac;
	fd1 = open(av[1], O_RDONLY);
	//fd2 = open(av[2], O_RDONLY);
	//fd3 = open(av[3], O_RDONLY);
	 printf("file descriptor: %d \n", fd1);
	satir = get_next_line(fd1);
	satir2 = get_next_line(fd1);
	printf("%s", satir);
	free(satir);
	printf("%s", satir2);
	free(satir2);

	//printf("%s", get_next_line(fd1)); // Bu satırları açarsanız 
	//printf("%s", get_next_line(fd1)); // free etmeyi unutmayınız.
	//printf("\n");

	//printf("file descriptor: %d \n", fd2);
	//printf("%s", get_next_line(fd2));
	//printf("%s", get_next_line(fd2));
	//printf("%s", get_next_line(fd2));
	//printf("%s", get_next_line(fd2));
	//printf("%s", get_next_line(fd2));
	//printf("\n");

	//printf("file descriptor: %d \n", fd3);
	//printf("%s", get_next_line(fd3));
	//printf("%s", get_next_line(fd3));
	//printf("%s", get_next_line(fd3));
	//printf("%s", get_next_line(fd3));
	//printf("%s", get_next_line(fd3));
	//printf("%s", get_next_line(fd3));
	//printf("%s", get_next_line(fd3));
	system("leaks a.out");
	return (0);
}
