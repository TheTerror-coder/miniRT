#include "preprocss.h"
#include <stdio.h>

int	main(int argc, char** argv)
{
	if (argc != 2)
		return (printf("arg fault\n"), 1);
	printf ("value : %.20F\n", ft_atod(argv[1]));
	return (0);
}
