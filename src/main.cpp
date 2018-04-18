#include "../include/ThreadManage.hpp"
#include <cstdio>
#include <ctime>

// example job
class MyJob: public Job
{
	public:
		MyJob(int a, int b): a(a), b(b) {}
		void run()
		{
			int ret = a + b;
			//printf("result: %d\n", ret);
		}
		int a;
		int b;
};

int main()
{
	auto start = clock();
	auto manager = ThreadManage(4);
	for (int i = 0; i < 100000; ++i)
	{
		manager.run(new MyJob(rand() % 100, rand() % 100));
	}
	manager.terminate();
	auto end = clock();
	printf("running time is: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}