#include "Timer.h"
#include "common.h"
#include "log.h"
struct event_base* gEventBase=NULL;
float DiffTime(timeval &v1, timeval &v2)
{
	float diff_sec = v1.tv_sec - v2.tv_sec;
	float diff_usec = (v1.tv_usec - v2.tv_usec) / 1000000.0f;
	return diff_sec + diff_usec;
}
Timer::Timer():
	m_Stop(true),
	m_TimerEvent(NULL)
{
}

Timer::~Timer()
{
	if (!m_Stop)Stop();
	if (m_TimerEvent)
	{
		event_free(m_TimerEvent);
		m_TimerEvent = NULL;
	}
}

void Timer::Init(float time, TimerCallBack call_back, void * arg, bool loop)
{
	m_Stop = true;
	m_Loop = loop;
	m_Time = time;
	m_CallBack = call_back;
	m_Arg = arg;
	
}

void Timer::Begin()
{
	if (NULL == GetEventBase())return;
	m_Stop = false;
	if (NULL == m_TimerEvent)
	{
		m_TimerEvent = evtimer_new(GetEventBase(), timeout_cb, this);
	}
	evutil_timerclear(&m_LastTime);
	long sec = (long)m_Time;
	long usec = (long)((m_Time - sec) * 1000 * 1000);
	m_Tv.tv_sec = sec;
	m_Tv.tv_usec = usec;
	evutil_gettimeofday(&m_LastTime, NULL);
	int ret = event_add(m_TimerEvent, &m_Tv);
	if (ret != 0)
	{
		log_error("%s", "event_add error");
	}
}

void Timer::Stop()
{
	if (!m_Stop)
	{
		m_Stop = true;
		evtimer_del(m_TimerEvent);
		
	}
	

}

int Timer::Loop()
{
	int ret = event_base_dispatch(GetEventBase());
	event_base_free(gEventBase);
	gEventBase = NULL;
	return ret;
}

void Timer::ExitLoop()
{
	if(NULL != gEventBase)event_base_loopexit(gEventBase, NULL);
}

event_base * Timer::GetEventBase()
{
	if (NULL == gEventBase)
	{
		gEventBase= event_base_new();
	}
	return gEventBase;
}

void Timer::timeout_cb(evutil_socket_t fd, short event, void * arg)
{
	Timer *t = static_cast<Timer*>(arg);
	if (t)
	{
		
		if (!t->m_Stop)
		{
			timeval current;
			evutil_gettimeofday(&current, NULL);
			float d_time = DiffTime(current, t->m_LastTime);
#ifdef _DEBUG
			//下断点时跳过本次计时
			if (d_time > t->m_Time * 10)
			{
				if (t->m_Loop)
				{
					t->Begin();
				}
				return;
			}
#endif // _DEBUG

			t->m_CallBack(d_time, t->m_Arg);
			//evutil_gettimeofday(&t->m_LastTime, NULL);
			if (t->m_Loop)
			{
				t->Begin();
			}
		}
		else
		{
			//if(t->m_Loop)evtimer_del(&t->m_TimeOut);
			log_error("%s", "timer stop");
		}
	}
	else
	{
		log_error("%s", "timer arg null");
	}
}
