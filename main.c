#include <stdio.h>
#include <pthread.h>
 
int numero = 0;
 
void zig();
void zag();
 
int main(void)
{
 pthread_t hilo0, hilo1;
 
 pthread_create(&hilo0, NULL, (void *) &zig, NULL); 
 pthread_create(&hilo1, NULL, (void *) &zag, NULL); 
  
 pthread_join(hilo0, NULL);
 pthread_join(hilo1, NULL);
 numero = numero % 100;
 printf("%i\n",numero);
 return 0;
}
 
void zig() {
 int i=0;
 for(i=0; i < 10000000; i++){
     numero = (numero+1) % 100;
 }
 return;
}

void zag() {
 int i=0;
 for(i=0; i < 10000000; i++){
     numero = (numero*numero) % 100;
 }
 return;
}
