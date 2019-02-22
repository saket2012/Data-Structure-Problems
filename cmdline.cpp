
#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

void *task1(void *x)
{

	int *temp;
	temp = static_cast<int *>(x);
	for (int count = 0; count < *temp; count++)
	{

		cout << "\nWork from thread" << count;
	}
	cout << "\nThread complete \n";
	return (NULL);
}

int main(int argc, char *argv[])

{
	int N;
	pthread_t Mythreads[10];
	if (argc != 2)
	{
		cout << "errr" << endl;

		exit(1);
	}

	N = atoi(argv[1]);
	if (N > 10)
	{
		N = 10;
	}

	for (int count = 0; count < N; count++)
	{
		pthread_create(&Mythreads[count], NULL, task1, &N);
	}

	for (int count = 0; count < N; count++)
	{
		pthread_join(Mythreads[count], NULL);
	}

	return 0;
}