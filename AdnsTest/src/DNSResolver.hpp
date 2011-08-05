/**
 *    \file   DNSResolver.hpp
 *    \brief  A high concurrecy DNS Resolver.
 *    \date   2011Äê08ÔÂ05ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <adns.h>

/**
 * Input and output:
 *
 * Memory Managment:
 *
 * Timeout Control:
 *
 * Concurrcey Num:
 *
 * Error process:
 *
 * Config:
 *
 * Coding Style:
 */

struct DNSRequest
{
    public:
	unsigned int timeout_sec;
	void *user_data;

    private:
	DNSRequest():user_data(NULL),
	timeout_sec(0)
    {}

    public:
	/**
	 * Create one DNSRequest.
	 *
	 * \param domain The domain name to resolve, it is copyed, so you can free it any time.
	 * \param user_data Anything you want me to hold.
	 * \param timeout_sec Max seconds num before DNS server send reponse. It's reletive time.
	 */
	static DNSRequest * CreateRequest(const char *domain, unsigned int timeout_sec, void *user_data);

    private:
};

class DNSResolver
{
    public:
	enum ResolveError{
	    RE_OK,
	    RE_NOTFOUND,
	    RE_TIMEOUT,

	    __RE_NUM,
	};

	typedef boost::function<DNSRequest * (ResolveError, struct addrinfo)> DNSResultCallback_t;

	static const char * strerror(ResolveError re);

    public:
	/**
	 * \param max_concurrency Max number of concurrent DNS request we can send.
	 */
	bool init(size_t max_concurrency, DNSResultCallback_t cb);

	/**
	 * \brief Submit 'req' to reolver.
	 *
	 * \param req The pointer is hold by resolver, you CANNOT free it before resolve finished.
	 */
	bool submit(DNSRequest *req);

	size_t padding_req_num() const;

	/**
	 * Give a chance to do the real IO jobs.
	 * If a req complete, succeed or not, the cb given in 'init' method will be called.
	 *
	 * \param timeout Max block time.
	 */
	void poll(struct timeval *timeout);

    private:
	size_t padding_req_num_;
	DNSResultCallback_t cb_;
};

struct DNSResult
{
    DNSRequest *req;
    struct addrinfo *ai;
};

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
	bool submit(DNSRequest *req);

	/**
	 *
	 * Get DNSResult, 'result' is set properly if 'get_result' return true.
	 */
	bool get_result(DNSResult &result, struct timeval *timeout);
};
