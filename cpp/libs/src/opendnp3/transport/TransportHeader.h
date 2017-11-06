/*
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
#ifndef OPENDNP3_TRANSPORTHEADER_H
#define OPENDNP3_TRANSPORTHEADER_H

#include <cstdint>

namespace opendnp3
{

class TransportHeader
{

private:

	static const uint8_t FIN_MASK = 0x80;
	static const uint8_t FIR_MASK = 0x40;
	static const uint8_t SEQ_MASK = 0x3F;

public:
	static uint8_t ToByte(bool fir, bool fin, uint8_t seq);

	TransportHeader() = delete;
	TransportHeader(uint8_t byte);

	const bool fir;
	const bool fin;
	const uint8_t seq;
};


}

#endif

