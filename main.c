#include <stdio.h>
#include <pthread.h>

int numero = 0;

void zig();
void zag();

int main(void)
{
	pthread_t hilo0, hilo1;

	// pongo a ejecutar los hilos
	pthread_create(&hilo0, NULL, (void *)&zig, NULL);
	pthread_create(&hilo1, NULL, (void *)&zag, NULL);

	// espero a que terminen
	pthread_join(hilo0, NULL);
	pthread_join(hilo1, NULL);

	// saco un modulo para que el numero quede mas lindo
	numero = numero % 100;
	printf("%i\n", numero);
	return 0;
}

void zig()
{
	// suma 1 10 millones de veces
	int i = 0;
	for (i = 0; i < 10000000; i++)
	{
		numero = (numero + 1) % 100;
	}
	return;
}

void zag()
{
	// multiplica por si mismo 10 millones de veces
	int i = 0;
	for (i = 0; i < 10000000; i++)
	{
		numero = (numero * numero) % 100;
	}
	return;
}
