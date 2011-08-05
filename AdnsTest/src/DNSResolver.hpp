/**
 *    \file   DNSResolver.hpp
 *    \brief  A high concurrecy DNS Resolver.
 *    \date   2011Äê08ÔÂ05ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <string>
#include <boost/function.hpp>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

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
	 */
	static DNSRequest * CreateRequest(const char *domain, void *user_data);
	void * FreeRequest(DNSRequest *req);

    private:
};

struct DNSResult
{
    public:
	std::string domain;
	DNSResolver::ResolveError error;
	struct addrinfo *ai;

	void * user_data;
	DNSResult():
	    error(DNSResolver::RE_OK), ai(NULL), user_data(NULL),done_(false)
    {}

    private:
	bool done_;
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

	typedef boost::function<DNSRequest * (DNSResult *)> DNSResultCallback_t;

	static const char * strerror(ResolveError re);

    public:
	DNSResolver();
	~DNSResolver();

	/**
	 * \param max_concurrency Max number of concurrent DNS request we can send.
	 * \param req_timeout_sec Max seconds num before DNS server send reponse. It's reletive time.
	 */
	bool init(size_t max_concurrency, unsigned int req_timeout_sec, DNSResultCallback_t cb);

	/**
	 * \brief Submit 'req' to reolver.
	 *
	 * \param req The pointer is hold by resolver, you CANNOT free it before resolve finished.
	 */
	bool submit(std::string &domain, void *user_data);

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
	time_t req_timeout_;
	DNSResultCallback_t cb_;
};
