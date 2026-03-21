#include <iostream> 

int main() 
{
	static const int N=10;
	double arr[N] = {0.4, 3.2, 4.6, 4.1, 6.7, 8.1, 0.1, 5.5, 9.7, 6.2};
	bool finito = false;
	
	while (not finito) 
	{
		finito = true;
		for (int i=0; i<N-1; i++)
		{
			if (arr[i] > arr[i+1])
			{
				double val = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = val;
				finito = false;
			}
		}
	}
	for (int i=0; i<N; i++) {
		std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	return 0;
}
