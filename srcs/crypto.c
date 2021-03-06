#include <woody.h>

void	print_key(unsigned char	*buffer)
{
	int	i;

	printf("key : ");
	i = 0;
	while (i < KEY_SIZE)
	{
		printf("%02X", (unsigned)(buffer[i]));
		i++;
	}
	printf("\n");
}

unsigned char	*get_key(void)
{
	int		fd;
	unsigned char	*buffer;

	buffer = malloc(KEY_SIZE);
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, buffer, KEY_SIZE);
	print_key(buffer);
	return (buffer);
}

void	crypt_xor(char	*addr, size_t size, unsigned char *key)
{
	size_t	i;

	// printf("Before : \n");
	// print_memory(addr, size);
	i = 0;
	while (i < size)
	{
		addr[i] = addr[i] ^ key[i % KEY_SIZE];
		i++;
	}
	// printf("After : \n");
	// print_memory(addr, size);
}
