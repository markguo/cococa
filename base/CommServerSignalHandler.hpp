/**
 *    \file   CommServerSignalHandler.hpp
 *    \brief  
 *    \date   05/03/11
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#ifndef  COMMSERVERSIGNALHANDLER_INC
#define  COMMSERVERSIGNALHANDLER_INC

#include <signal.h>
#include <string.h>
#include "debug.h"

/**
 * \brief Handle SIGUSR2 SIGTERM in normal using style in server apps.
 *
 * SIGTERM: Stop the server.
 * SIGUSR2: Reload config.
 */

template <typename Server>
class CommServerSignalHandler
{
    public:
	CommServerSignalHandler(Server * server_raw_ptr)
	{
	    server = server_raw_ptr;
	}

	~CommServerSignalHandler(){server = NULL;}

	/**
	 * \brief Registor SIGUSR2 SIGTERM.
	 */
	void active()
	{
	    signal(SIGTERM, sigterm_handler);
	    signal(SIGINT, sigterm_handler);
	    signal(SIGUSR2, sigusr2_handler);
	}


    private:
	static void sigusr2_handler(int signal)
	{
	    if(server){
		server->notify_reconfig();
	    }
	}

	static void sigterm_handler(int signal)
	{
	    if(server){
		LOG_INFO("STOP on signal %d: %s\n", signal, strsignal(signal));
		server->stop();
	    }
	}

    private:
	static  Server *server;
};

template<typename Server>
Server *CommServerSignalHandler<Server>::server = NULL;
#endif   /* ----- #ifndef COMMSERVERSIGNALHANDLER_INC  ----- */
