/*
tinyTLS project

Copyright 2014 Nesterov A.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/* PKCS1.H
 * Header file for RSA cryptosystem (PKCS #1)
 */

#ifndef TINYTLS_PKCS1_H_
#define TINYTLS_PKCS1_H_

#include "../mlib/binary.h"

/* Signature type */
enum
{
	SIGTYPE_UNKNOWN = 0,

	PKCS1_RSAES,

	PKCS1_SSA_MD5,
	PKCS1_SSA_SHA1,
	PKCS1_SSA_SHA256
};

struct PKCS1_RSA_PublicKey{
	Binary exponent;
	Binary modulus;
};

void EncryptRSA(struct TinyTLSContext * ctx, Binary & out, unsigned int size, const Binary & Modulus, const Binary & Exponent, const uint8_t * data, unsigned length);

int GetRSAAlgorithmType(const uint8_t * oid, uint32_t length);
int VerifyRSASignature(struct TinyTLSContext * ctx, const Binary & signature, unsigned int size, const Binary & Modulus, const Binary & Exponent, int sigtype, const uint8_t * data, unsigned length);

#endif