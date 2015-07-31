/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef OPENPAL_UINT48BE_H
#define OPENPAL_UINT48BE_H

#include <cstdint>
#include <cstring>

#include "UInt48Type.h"

#include "openpal/container/WriteBufferView.h"
#include "openpal/container/ReadBufferView.h"

namespace openpal
{

class UInt48BE
{
public:

	static UInt48Type Read(const uint8_t* pStart);

	static void Write(uint8_t* apStart, UInt48Type aValue);

	inline static UInt48Type ReadBuffer(ReadBufferView& buffer)
	{
		auto ret = Read(buffer);
		buffer.Advance(SIZE);
		return ret;
	}

	static void WriteBuffer(WriteBufferView& buffer, UInt48Type aValue)
	{
		Write(buffer, aValue);
		buffer.Advance(SIZE);
	}

	const static uint64_t MAX = 281474976710655ULL; // 2^48 -1
	const static size_t SIZE = 6;
	typedef UInt48Type Type;
};

}

#endif