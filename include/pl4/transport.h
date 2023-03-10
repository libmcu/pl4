/*
 * SPDX-FileCopyrightText: 2022 Kyunghwan Kwon <k@mononn.com>
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef PL4_H
#define PL4_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

enum transport_event {
	TRANSPORT_EVT_UNKNOWN,
	TRANSPORT_EVT_CONNECTED,
	TRANSPORT_EVT_DISCONNECTED,
};

struct transport_conn_param {
	const char *endpoint;
	size_t endpoint_len;

	uint16_t port;
	uint16_t timeout_ms;

	const void *ca_cert;
	size_t ca_cert_len;
	const void *client_cert;
	size_t client_cert_len;
	const void *client_key;
	size_t client_key_len;
};

struct transport;
struct transport_api {
	int (*connect)(struct transport *self);
	int (*disconnect)(struct transport *self);
	int (*write)(struct transport *self,
			const void *data, size_t data_len);
	int (*read)(struct transport *self, void *buf, size_t bufsize);
};

#include "pl4/transport_interface.h"

#if defined(__cplusplus)
}
#endif

#endif /* PL4_H */
