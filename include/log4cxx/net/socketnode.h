/***************************************************************************
                          socketnode.h  -  class SocketNode
                             -------------------
    begin                : ven mai 9 2003
    copyright            : (C) 2003 by Michael CATANZARITI
    email                : mcatan@free.fr
 ***************************************************************************/

/***************************************************************************
 * Copyright (C) The Apache Software Foundation. All rights reserved.      *
 *                                                                         *
 * This software is published under the terms of the Apache Software       *
 * License version 1.1, a copy of which has been included with this        *
 * distribution in the LICENSE.txt file.                                   *
 ***************************************************************************/

#ifndef _LOG4CXX_NET_SOCKET_NODE_H
#define _LOG4CXX_NET_SOCKET_NODE_H

#include <log4cxx/helpers/thread.h>
#include <log4cxx/helpers/objectptr.h>
#include <log4cxx/helpers/objectimpl.h>

namespace log4cxx
{
	namespace helpers
	{
		class Socket;
		typedef ObjectPtrT<Socket> SocketPtr;

		class SocketInputStream;
		typedef ObjectPtrT<SocketInputStream> SocketInputStreamPtr;
	};
	
	namespace spi
	{
		class LoggerRepository;
		typedef helpers::ObjectPtrT<LoggerRepository> LoggerRepositoryPtr;
	};

	namespace net
	{
		class SocketNode;
		typedef helpers::ObjectPtrT<SocketNode> SocketNodePtr;
        
		/**
        Read {@link spi::LoggingEvent LoggingEvent} objects sent from a remote
		client using Sockets (TCP). These logging events are logged according
		to local policy, as if they were generated locally.

        <p>For example, the socket node might decide to log events to a
        local file and also resent them to a second socket node.
        */
        class LOG4CXX_EXPORT SocketNode :
			public virtual helpers::Runnable,
				public virtual helpers::ObjectImpl
		{
		protected:
			helpers::SocketInputStreamPtr is;
			spi::LoggerRepositoryPtr hierarchy;

		public:
			DECLARE_ABSTRACT_LOG4CXX_OBJECT(SocketNode)
			BEGIN_LOG4CXX_CAST_MAP()
				LOG4CXX_CAST_ENTRY(SocketNode)
				LOG4CXX_CAST_ENTRY(helpers::Runnable)
			END_LOG4CXX_CAST_MAP()

			SocketNode(helpers::SocketPtr& socket, 
				spi::LoggerRepositoryPtr& hierarchy);
			virtual void run();
		};
	}; // namespace net
}; // namespace log4cxx

#endif // _LOG4CXX_NET_SOCKET_NODE_H
