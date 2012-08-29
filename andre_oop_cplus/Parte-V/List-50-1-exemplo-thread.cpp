/**  @file List-50-1-exemplo-thread.cpp */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "pthread.h"

volatile double pi = 0.0;			// Inicializa vari�veis globais compartilhadas
volatile double intervalos;	
volatile int nproc = 2;
pthread_mutex_t pi_lock;	

// Define a fun��o thread (com c�digo paralelizado)
void * funcao_thread_parcial_pi (void *arg) 	
{
  register double	largura		= 1.0 / intervalos;
  register double	parcial_pi	= 0;
  register int iproc = (*((char *) arg) - '0'); //ou atoi((char*)arg);
  for ( register int i = iproc; i < intervalos; i += nproc )
    {
      register double x = (i + 0.5) * largura;
      parcial_pi += 4.0 / (1.0 + x * x);
    }
  parcial_pi *= largura;
  pthread_mutex_lock (&pi_lock);		// Trava o acesso a esta parte do c�digo
  pi += parcial_pi;				// Altera pi
  pthread_mutex_unlock (&pi_lock);		// Destrava acesso a esta parte do c�digo
  return (NULL);
}

int main (int argc, char *argv[])
{
  pthread_t thread0, thread1;			// Cria duas threads
  void *retval;
  std::cout << "Comando: "<< argv[0] << " numeroIntervalos " << std::endl;
  intervalos = atoi ( argv[1] );	
  pthread_mutex_init (&pi_lock, NULL);		// Inicializa a vari�vel mutex

  // Executa as duas threads em paralelo
  if( pthread_create(&thread0, NULL, funcao_thread_parcial_pi,(void*)"0")  ||
      pthread_create(&thread1, NULL, funcao_thread_parcial_pi,(void*)"1"))
    {
      std::cout << argv[0] << " n�o foi poss�vel criar a thread.";
      exit (1);
    }

  // Join espera as threads terminarem, o retorno � armazenado em retval 
  if (pthread_join (thread0, &retval) 	 || pthread_join (thread1, &retval))
    {
      std::cerr << argv[0] << " thread join falhou" << std::endl;
      exit (1);
    }
  std::cout << "Estimativa de pi � " << pi << std::endl;
  return 0;
}
