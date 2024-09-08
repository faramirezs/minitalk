# include "include/minitalk.h"


void print_id (void)
{
	int pid;

	pid = getpid();
	ft_printf("El pid %i\n", pid);
}


void handle_sigusr(int sig)
{
	static int bit_position = 7;
	static char received_char = 0;

	if (sig == SIGUSR1)
	{
    	received_char |= (1 << bit_position);
    	bit_position--;
	}
	else if (sig == SIGUSR2)
	{
		received_char &= ~(1 << bit_position);
    	bit_position--;
	}
	if(bit_position == -1)
	{
		if (received_char == 0)
		{
			ft_printf("\n");
		}
		ft_printf("%c", received_char);
		bit_position = 7;
		received_char = 0;
	}
}


int main()
{

	print_id();
	printf("Waiting to receive a message...\n");

	while(1)
	{
		signal(SIGUSR1, handle_sigusr);
		signal(SIGUSR2, handle_sigusr);
		pause();
	}
	return 0;
}
