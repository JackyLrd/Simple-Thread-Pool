#include "../include/ThreadPool.hpp"

ThreadPool::ThreadPool(int thread_num)
{
	state = POOL_INIT;
	max_thread_num = thread_num;
	threads = new Thread[thread_num];
	for (int i = 0; i < max_thread_num; ++i)
	{
		threads[i].set_id(i);
		threads[i].run();
	}
	state = POOL_RUNNING;
}

void ThreadPool::add_job(Job* job)
{
	int id = rand() % max_thread_num;
	threads[id].add_job(job);
}

void ThreadPool::terminate()
{
	state = POOL_TERMINATING;

	for (unsigned long long i = 0; i < max_thread_num; ++i)
	{
		threads[i].set_abort();
		threads[i].signal();
		pthread_join(threads[i].get_tid(), NULL);
	}
	
	printf("all threads exit.\n");
	show_thread_state();

	if (threads)
		delete[] threads;

	state = POOL_TERMINATED;
}

void ThreadPool::show_thread_state()
{
	int count = 0;
	for (int i = 0; i < max_thread_num; ++i)
	{
		count += threads[i].get_job_count();
		printf("thread %d finished %d jobs\n", threads[i].get_id(), threads[i].get_job_count());
	}
	printf("%d jobs finished.\n", count);
}