/*
 * Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2008 Free Software Foundation
 *
 * Author: Nikos Mavrogiannopoulos
 *
 * This file is part of GNUTLS.
 *
 * The GNUTLS library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA
 *
 */

#ifndef GNUTLS_HASH_INT_H
# define GNUTLS_HASH_INT_H

#include <gnutls_int.h>
#include <gnutls/crypto.h>
#include <crypto.h>

/* for message digests */

extern int crypto_mac_prio;
extern gnutls_crypto_digest_st _gnutls_mac_ops;

typedef struct {
  const gnutls_crypto_digest_st* cc;
  void* ctx;
} digest_reg_hd;

typedef struct
{
  int registered; /* true or false(0) */
  union {
    void* gc; /* when not registered */
    digest_reg_hd rh; /* when registered */
  } hd;
  gnutls_digest_algorithm_t algorithm;
  const void *key;
  int keysize;
  int active;
} hash_hd_st;

/* basic functions */
int _gnutls_hash_init (hash_hd_st*, gnutls_digest_algorithm_t algorithm,
			    const void *key, int keylen);
int _gnutls_hash_get_algo_len (gnutls_digest_algorithm_t algorithm);
int _gnutls_hash (hash_hd_st * handle, const void *text, size_t textlen);
int _gnutls_hash_fast( gnutls_digest_algorithm_t algorithm, const void* key, int keylen, 
	const void* text, size_t textlen, void* digest);

void _gnutls_hash_deinit (hash_hd_st* handle, void *digest);
void _gnutls_hash_output (hash_hd_st* handle, void *digest);
void _gnutls_hash_reset (hash_hd_st * handle);

/* help functions */
int _gnutls_mac_init_ssl3 (hash_hd_st*, gnutls_digest_algorithm_t algorithm, void *key,
				int keylen);
void _gnutls_mac_deinit_ssl3 (hash_hd_st* handle, void *digest);

int _gnutls_ssl3_generate_random (void *secret, int secret_len,
				  void *rnd, int random_len, int bytes,
				  opaque * ret);
int _gnutls_ssl3_hash_md5 (const void *first, int first_len,
			   const void *second, int second_len,
			   int ret_len, opaque * ret);

void _gnutls_mac_deinit_ssl3_handshake (hash_hd_st* handle, void *digest,
					opaque * key, uint32_t key_size);

int _gnutls_hash_copy (hash_hd_st* dst_handle, hash_hd_st * src_handle);

#endif /* GNUTLS_HASH_INT_H */
