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
// Copyright 2016 Automatak LLC
// 
// Automatak LLC (www.automatak.com) licenses this file
// to you under the the Apache License Version 2.0 (the "License"):
// 
// http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef OPENDNP3JAVA_JNIANALOGOUTPUTINT16_H
#define OPENDNP3JAVA_JNIANALOGOUTPUTINT16_H

#include <jni.h>

namespace jni
{
    class AnalogOutputInt16
    {
        friend struct JCache;

        bool init(JNIEnv* env);
        void cleanup(JNIEnv* env);

        public:

        // field getter methods
        jshort getvalue(JNIEnv* env, jobject instance);
        jobject getstatus(JNIEnv* env, jobject instance);

        private:

        jclass clazz = nullptr;

        // field ids
        jfieldID valueField = nullptr;
        jfieldID statusField = nullptr;
    };
}

#endif