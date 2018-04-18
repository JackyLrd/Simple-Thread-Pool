/*
 * @Author: JackyLrd 
 * @Date: 2018-04-18 03:28:35 
 * @Last Modified by: JackyLrd
 * @Last Modified time: 2018-04-18 14:51:56
 */
#ifndef Thread_H_
#define Thread_H_
#include <pthread.h>
#include <list>
#include <assert.h>
#include <cstdio>
#include "Job.hpp"

const int THREAD_IDLE = 0;
const int THREAD_WORKING = 1;
const int THREAD_WAITING = 2;
const int THREAD_EXIT = 3;

class Thread
{
	public:
		Thread();
		void set_id(int id);
		const int get_id();
		const pthread_t get_tid();
		void lock();
		void unlock();
		void signal();
		void wait();
		void add_job(Job* job);
		void run();
		const int get_state();
		const int get_job_count();
		void set_abort();
		static void* start_routine(void* args);
		void execute();
	private:
		pthread_mutex_t queue_lock;
		pthread_cond_t queue_ready;
		std::list<Job*> job_queue;
		int state;
		int job_count;
		bool is_abort;
		pthread_t tid;
		int thread_id;
};

#endif