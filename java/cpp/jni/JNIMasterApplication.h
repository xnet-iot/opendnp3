//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013-2019 Automatak, LLC
// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
// LLC (www.automatak.com) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Automatak LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef OPENDNP3JAVA_JNIMASTERAPPLICATION_H
#define OPENDNP3JAVA_JNIMASTERAPPLICATION_H

#include <jni.h>

#include "../adapters/LocalRef.h"

namespace jni
{
    struct JCache;

    namespace cache
    {
        class MasterApplication
        {
            friend struct jni::JCache;

            bool init(JNIEnv* env);
            void cleanup(JNIEnv* env);

            public:

            // methods
            jboolean assignClassDuringStartup(JNIEnv* env, jobject instance);
            LocalRef<jobject> getClassAssignments(JNIEnv* env, jobject instance);
            jlong getMillisecondsSinceEpoch(JNIEnv* env, jobject instance);
            void onClose(JNIEnv* env, jobject instance);
            void onOpen(JNIEnv* env, jobject instance);
            void onReceiveIIN(JNIEnv* env, jobject instance, jobject arg0);
            void onTaskComplete(JNIEnv* env, jobject instance, jobject arg0);
            void onTaskStart(JNIEnv* env, jobject instance, jobject arg0, jobject arg1);

            private:

            jclass clazz = nullptr;

            // method ids
            jmethodID assignClassDuringStartupMethod = nullptr;
            jmethodID getClassAssignmentsMethod = nullptr;
            jmethodID getMillisecondsSinceEpochMethod = nullptr;
            jmethodID onCloseMethod = nullptr;
            jmethodID onOpenMethod = nullptr;
            jmethodID onReceiveIINMethod = nullptr;
            jmethodID onTaskCompleteMethod = nullptr;
            jmethodID onTaskStartMethod = nullptr;
        };
    }
}

#endif
