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
#ifndef OPENPAL_FLOAT_BYTE_ORDER_H
#define OPENPAL_FLOAT_BYTE_ORDER_H

#include "openpal/util/Uncopyable.h"

#include <cstdint>

namespace openpal
{

struct FloatByteOrder : private StaticOnly
{
    enum class Value : uint8_t
    {
        NORMAL,
        REVERSE,
        UNSUPPORTED
    };

    static const Value ORDER;

private:
    static Value GetByteOrder();

    static bool IsNormalByteOrder();
    static bool IsReverseByteOrder();
};

} // namespace openpal

#endif
