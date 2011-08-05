/**
 *    \file   DNSResolverThread.hpp
 *    \brief  
 *    \date   2011Äê08ÔÂ05ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <queue>
#include <string>

#include "DNSResolver.hpp"

/**
 * Start a thread to do resolve jobs.
 */
class DNSResolverThread
{
    public:

	bool init(size_t max_concurrency);

	bool start();

	void notify_stop();
	
	int join();

	/**
	 * Submit 'req' to input queue, never block.
	 * If padding_req_num > max_concurrency, submit fail.
	 */
	bool submit(const char *domain, void *user_data);

	/**
	 *
	 * Get DNSResult, 'result' is set properly if 'get_result' return true.
	 */
	bool get_result(DNSResult &result, struct timeval *timeout);

    private:
	void run();

    private:
	DNSResolver resolver_;

	bool stop_;

	struct Req{
	    std::string domain;
	    void * user_data;
	};

	size_t padding_req_num_;

	std::queue<Req > padding_req_queue_;
	std::queue<DNSResult * > result_queue_;
};
