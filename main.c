/*
 * Copyright (C) 2011 Instituto Nokia de Tecnologia
 *
 * Author:
 *     Paulo Alcantara <paulo.alcantara@openbossa.org>
 *     Aloisio Almeida Jr <aloisio.almeida@openbossa.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA 02111EXIT_FAILURE307, USA.
*/

#include <stdio.h>
#include <string.h>

#include "nfcctl.h"

extern int verbose;

#define printerr(s, ...)					\
	fprintf(stderr, "%s:%d %s: " s "\n",  __FILE__,		\
			__LINE__, __func__, ##__VA_ARGS__);	\

#define printdbg(s, ...)				\
	do {						\
		if (verbose)				\
			printerr(s, ##__VA_ARGS__);	\
	} while (0)

int main(void)
{
	struct nfcctl ctx;
	int rc;

	verbose = 1;

	rc = nfcctl_init(&ctx);
	if (rc) {
		printdbg("%s", strerror(rc));
		return rc;
	}

	nfcctl_deinit(&ctx);

	return rc;
}
