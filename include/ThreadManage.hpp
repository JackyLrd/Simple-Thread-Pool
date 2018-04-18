/*
 * @Author: JackyLrd 
 * @Date: 2018-04-18 03:28:21 
 * @Last Modified by: JackyLrd
 * @Last Modified time: 2018-04-18 11:20:04
 */
#ifndef ThreadManage_H_
#define ThreadManage_H_

#include "Job.hpp"
#include "ThreadPool.hpp"

class ThreadManage
{
	public:
		ThreadManage();
		ThreadManage(int num);
		void run(Job* job);
		void show_thread_state();
		void terminate();
		virtual ~ThreadManage();
	private:
		int num_of_thread;
		ThreadPool* pool;
};

#endif