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
#ifndef ASIOPAL_TLSCLIENT_H
#define ASIOPAL_TLSCLIENT_H

#include "asiopal/Executor.h"
#include "asiopal/IPEndpoint.h"
#include "asiopal/LoggingConnectionCondition.h"
#include "asiopal/TLSConfig.h"
#include "asiopal/tls/SSLContext.h"

#include <asio/ssl.hpp>

namespace asiopal
{

class TLSClient final : public std::enable_shared_from_this<TLSClient>, private openpal::Uncopyable
{

public:
    typedef std::function<void(const std::shared_ptr<Executor>& executor,
                               const std::shared_ptr<asio::ssl::stream<asio::ip::tcp::socket>>& stream,
                               const std::error_code& ec)>
        connect_callback_t;

    static std::shared_ptr<TLSClient> Create(const openpal::Logger& logger,
                                             const std::shared_ptr<Executor>& executor,
                                             const std::string& adapter,
                                             const TLSConfig& config,
                                             std::error_code& ec)
    {
        auto ret = std::make_shared<TLSClient>(logger, executor, adapter, config, ec);
        return ec ? nullptr : ret;
    }

    TLSClient(const openpal::Logger& logger,
              const std::shared_ptr<Executor>& executor,
              const std::string& adapter,
              const TLSConfig& config,
              std::error_code& ec);

    bool Cancel();

    bool BeginConnect(const IPEndpoint& remote, const connect_callback_t& callback);

private:
    void LogVerifyCallback(bool preverified, asio::ssl::verify_context& ctx);

    void HandleResolveResult(const connect_callback_t& callback,
                             const std::shared_ptr<asio::ssl::stream<asio::ip::tcp::socket>>& stream,
                             const asio::ip::tcp::resolver::iterator& endpoints,
                             const std::error_code& ec);

    void HandleConnectResult(const connect_callback_t& callback,
                             const std::shared_ptr<asio::ssl::stream<asio::ip::tcp::socket>>& stream,
                             const std::error_code& ec);

    bool canceled = false;

    openpal::Logger logger;
    LoggingConnectionCondition condition;
    const std::shared_ptr<Executor> executor;
    const std::string adapter;
    SSLContext ctx;
    asio::ip::tcp::endpoint localEndpoint;
    asio::ip::tcp::resolver resolver;
};

} // namespace asiopal

#endif
