/*
 * =====================================================================================
 *
 *       Filename:  test_vector.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月17日 11时02分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct FetchStats
{
        uint64_t TxBytes;
        uint64_t RxBytes;
        int32_t RxPages;
        int32_t ErrorPages;

        //FetchStats()
        //    :TxBytes(0), RxBytes(0), RxPages(0), ErrorPages(0)
        //{}  
};

#include <iostream>

/**
 * CounterTrait class should confirm:
 * class CounterTrait{
 * public:
 * enum CounterType{
 * ...
 *
 * __COUNTER_TYPE_NUMBER;
 * }; 
 *
 * static const char *getCounterName(CounterType e);
 * }
 */
template <typename CounterTrait>
class StaticCounters{
    private:
	typedef typename CounterTrait::CounterType CounterType;
    public:
	/// Increment counter c by 1;
	void incrementCounter(CounterType c, size_t inc = 1){counters_[c]+= inc;}

	/// Decrement counter c by 1;
	void decrementCounter(CounterType c, size_t dec = 1){counters_[c]-= dec;}

	/// Set value of counter c to val
	void setCounter(CounterType c, long val){counters_[c] = val;}

	/// Set value of counter c to 0;
	void clearCounter(CounterType c){setCounter(c, 0);}

	/// Get current value of counter c.
	long getCounterVal(CounterType c) const {return counters_[c].value();}

	/// Print statistic to os.
	void outputStatistic(std::ostream &os);

    protected:
	typedef long long AtomicLong_t;
	AtomicLong_t counters_[CounterTrait::__COUNTER_TYPE_NUMBER];

	/// value of counters saved at last outputStatistic call.
	AtomicLong_t last_counters_val_[CounterTrait::__COUNTER_TYPE_NUMBER]; 
};

/// Print statistic to os.
    template <typename CounterTrait>
void StaticCounters<CounterTrait>::outputStatistic(std::ostream &os)
{
    os << "counter(cur/inc): ";
    for(unsigned int i = 0; i < CounterTrait::__COUNTER_TYPE_NUMBER; ++i){
	os << CounterTrait::getCounterName((CounterType)i) << "("
	    << counters_[i].value() << "/" << counters_[i].value() - last_counters_val_[i].value()
	    << ")";

	if(i + 1 < CounterTrait::__COUNTER_TYPE_NUMBER){
	    os << ", ";
	}
    }

    for(int i = 0; i < CounterTrait::__COUNTER_TYPE_NUMBER; ++i){
	last_counters_val_[i] = counters_[i];
    }
}

struct SysCounterTrait{
    enum CounterType{
        COUNTER_RECV_CTRL = 0,
        COUNTER_RECV_DIRECT_RESULT,
        COUNTER_RECV_DELIVER,
        COUNTER_RECV_URLLIB,
        
        COUNTER_FEEDBACK_UNFETCH,
        COUNTER_FEEDBACK_FILTER,
        COUNTER_FEEDBACK_RESULT,
        COUNTER_FEEDBACK_DIRECT_RESULT,

        COUNTER_NEWURL_TOTAL,
        COUNTER_NEWURL_FILTER,
        
        COUNTER_DELIVER_SENT,
        COUNTER_DELIVER_DROP_RESULT_MSG,
        COUNTER_DELIVER_DROP_REQUEST_MSG,
        
        __COUNTER_TYPE_NUMBER
    };  

    static const char * getCounterName(CounterType c)
    {
        if(c < 0 || c >= __COUNTER_TYPE_NUMBER){
            return NULL;
        }

        return counter_names_[c];
    }

    static const char *counter_names_[__COUNTER_TYPE_NUMBER];
};

const char * SysCounterTrait::counter_names_[__COUNTER_TYPE_NUMBER]
= {
    "RecvCtrl",
    "RecvDirectResult",
    "RecvDeliver",
    "RecvUrllib",

    "FeedbackUnfetch",
    "FeedbackFilter",
    "FeedbackResult",
    "FeedbackDirectResult",

    "NewUrl",
    "NewUrlFilter",

    "DeliverSent",
    "DeliverDropResult",
    "DeliverDropRequest",
};

struct SpiderStats
{
    FetchStats LastFetchStats;
    FetchStats TotalFetchStats;
    struct timeval LastSampleTime;
    int RxSpeed;
    int TxSpeed;

    StaticCounters<SysCounterTrait> Counters;

    SpiderStats():
        RxSpeed(0), TxSpeed(0)
    {   
        LastSampleTime.tv_sec = LastSampleTime.tv_usec = 0;
    }   
};

class A
{
    public:
    A()
	:s()
    {}
	SpiderStats s;
};

int main(int argc, char **argv)
{
        if(argc != 3){
                printf("usage: %s test_str resize_len\n", argv[0]);
                return 1;
        }

        const char *test_str = argv[1];
        size_t len = strlen(test_str);
        size_t resize_len = atoi(argv[2]);

        using namespace std;
        vector<char> buf;

        buf.insert(buf.end(), test_str, test_str + len);

        printf("buf=%.*s\n", buf.size(), &buf[0]);

        buf.resize(resize_len, 'X');
        printf("after resize: buf=%.*s\n", buf.size(), &buf[0]);

	A a;
	printf("a.s.RxSpeed=%d a.s.LastSampleTime.TxBytes=%lu\n",
		a.s.RxSpeed, a.s.TotalFetchStats.TxBytes);
        return 0;
}
