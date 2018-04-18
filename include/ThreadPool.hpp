/*
 * @Author: JackyLrd 
 * @Date: 2018-04-18 03:28:17 
 * @Last Modified by: JackyLrd
 * @Last Modified time: 2018-04-18 14:38:30
 */
#ifndef ThreadPool_H_
#define ThreadPool_H_

#include <pthread.h>
#include <cstdio>
#include <assert.h>
#include <cstdlib>
#include "Job.hpp"
#include "Thread.hpp"

const int POOL_INIT = 0;
const int POOL_RUNNING = 1;
const int POOL_TERMINATING = 2;
const int POOL_TERMINATED = 3;

class ThreadPool
{
	public:
		ThreadPool() = delete;
		ThreadPool(const ThreadPool&) = delete;
		ThreadPool& operator=(const ThreadPool&) = delete;
		ThreadPool(int thread_num);
		void add_job(Job* job);
		void terminate();
		void show_thread_state();
	private:
		Thread* threads;
		int max_thread_num;
		int state;
};

#endif