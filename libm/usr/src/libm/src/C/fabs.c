/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#pragma ident	"@(#)fabs.c	1.13	06/01/31 SMI"

#pragma weak fabs = __fabs

#include "libm.h"
#include "libm_synonyms.h"
#include <math.h>

#if defined(__sparc)
#define	HIWORD	0
#define	LOWORD	1
#elif defined(__i386)
#define	HIWORD	1
#define	LOWORD	0
#else
#error Unknown architecture
#endif

double
fabs(double x) {
	int *px = (int *) &x;

	px[HIWORD] &= ~0x80000000;
	return x;
}