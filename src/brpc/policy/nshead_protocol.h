// Copyright (c) 2015 Baidu, Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Authors: Ge,Jun (gejun@baidu.com)

#ifndef BRPC_POLICY_NSHEAD_PROTOCOL_H
#define BRPC_POLICY_NSHEAD_PROTOCOL_H

#include "brpc/protocol.h"


namespace brpc {
namespace policy {

// Parse binary format of nshead
ParseResult ParseNsheadMessage(butil::IOBuf* source, Socket* socket, bool read_eof, const void *arg);

// Actions to a (client) request in nshead format
void ProcessNsheadRequest(InputMessageBase* msg);

// Actions to a (server) response in nshead format
void ProcessNsheadResponse(InputMessageBase* msg);

void SerializeNsheadRequest(butil::IOBuf* request_buf, Controller* controller,
                            const google::protobuf::Message* request);

void PackNsheadRequest(
    butil::IOBuf* packet_buf,
    SocketMessage**,
    uint64_t correlation_id,
    const google::protobuf::MethodDescriptor*,
    Controller* controller,
    const butil::IOBuf&,
    const Authenticator*);

// Verify authentication information in nshead format
bool VerifyNsheadRequest(const InputMessageBase *msg);

} // namespace policy
} // namespace brpc


#endif // BRPC_POLICY_NSHEAD_PROTOCOL_H
