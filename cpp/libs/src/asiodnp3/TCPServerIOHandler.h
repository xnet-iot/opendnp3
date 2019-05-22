/*
 * Copyright 2013-2019 Automatak, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
 * LLC (www.automatak.com) under one or more contributor license agreements. 
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Automatak LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ASIOPAL_TCPSERVERIOHANDLER_H
#define ASIOPAL_TCPSERVERIOHANDLER_H

#include "openpal/executor/TimerRef.h"

#include "asiopal/ChannelRetry.h"
#include "asiopal/IPEndpoint.h"
#include "asiopal/TCPServer.h"

#include "opendnp3/gen/ServerAcceptMode.h"

#include "asiodnp3/IOHandler.h"

namespace asiodnp3
{

class TCPServerIOHandler final : public IOHandler
{
    class Server final : public asiopal::TCPServer
    {
    public:
        typedef std::function<void(const std::shared_ptr<asiopal::Executor>& executor, asio::ip::tcp::socket)>
            callback_t;

        Server(const openpal::Logger& logger,
               const std::shared_ptr<asiopal::Executor>& executor,
               const asiopal::IPEndpoint& endpoint,
               std::error_code& ec)
            : TCPServer(logger, executor, endpoint, ec)
        {
        }

        void StartAcceptingConnection(const callback_t& callback)
        {
            this->callback = callback;
            this->StartAccept();
        }

    private:
        callback_t callback;

        virtual void OnShutdown() override {}

        virtual void AcceptConnection(uint64_t sessionid,
                                      const std::shared_ptr<asiopal::Executor>& executor,
                                      asio::ip::tcp::socket) override;
    };

public:
    static std::shared_ptr<TCPServerIOHandler> Create(const openpal::Logger& logger,
                                                      opendnp3::ServerAcceptMode accept_mode,
                                                      const std::shared_ptr<IChannelListener>& listener,
                                                      const std::shared_ptr<asiopal::Executor>& executor,
                                                      const asiopal::IPEndpoint& endpoint,
                                                      std::error_code& ec)
    {
        return std::make_shared<TCPServerIOHandler>(logger, accept_mode, listener, executor, endpoint, ec);
    }

    TCPServerIOHandler(const openpal::Logger& logger,
                       opendnp3::ServerAcceptMode accept_mode,
                       const std::shared_ptr<IChannelListener>& listener,
                       const std::shared_ptr<asiopal::Executor>& executor,
                       const asiopal::IPEndpoint& endpoint,
                       std::error_code& ec);

protected:
    virtual void ShutdownImpl() override;
    virtual void BeginChannelAccept() override;
    virtual void SuspendChannelAccept() override;
    virtual void OnChannelShutdown() override {} // do nothing, always accepting new connections

private:
    const std::shared_ptr<asiopal::Executor> executor;
    const asiopal::IPEndpoint endpoint;
    std::shared_ptr<Server> server;
};

} // namespace asiodnp3

#endif
