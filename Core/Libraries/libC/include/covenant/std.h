/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2022 Diego Magdaleno
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Utopia$
 */

#define __NEED_size
#define __NEED_u32
#define __NEED_i32
#define __NEED_ushort
#define __NEED_uintptr
#define __NEED_ctype_status
#define __NEED_intptr
#define __NEED_ulong
#define __NEED_ctype_rune
#define __NEED_ctype_error
#define __NEED_uvlong
#define __NEED_u64
#define __NEED_vlong
#include <covenant/bits/everytype.h>
#include <covenant/kernel/basic.h>
#include <covenant/fn.h>
#include <covenant/dat.h>

#define nil ((void *)0)

/* Default functions in the std */
void *c_std_bsearch(const void *, const void *, size, size, ctype_cmpfn);
void *c_std_realloc(void*, usize, usize);
void *c_std_alloc(usize, usize);
void c_std_setalloc(ctype_allocfn);
void c_std_exit(i32);
char *c_std_getsyserr(void);
char *c_std_strerror(i32, char*, usize);
void c_std_errstr(char *, usize);
void *c_std_free_(void *);

// TODO: Should this stay as a macro?
#define c_std_offsetof(a, b) (ulong)(&(((a *)0)->b))

// Stay as a macro?
#define c_std_free(a) a = c_std_free_((a))

/* Array manipulation */
void *c_arr_data(ctype_arr *);
usize c_arr_len(ctype_arr *, usize);
usize c_arr_avail(ctype_arr *);
usize c_arr_bytes(ctype_arr *);
ctype_status c_arr_trunc(ctype_arr*, usize, usize);

/* Dynamic */
ctype_status c_dyn_cat(ctype_arr*, void*, usize, usize);
ctype_status c_dyn_ready(ctype_arr*, usize, usize);
void* c_dyn_alloc(ctype_arr*, usize, usize);
ctype_status c_dyn_idxcat(ctype_arr*, usize, void *, usize, usize);

/* Operations on memory */
void *c_mem_cpy(void*, usize, void*);
void *c_mem_chr(const void*, size, i32);
void *c_mem_set(void*, usize, i32);

/* fmt */
ctype_status c_fmt_install(i32, ctype_fmtfn);
size c_fmt_fmt(ctype_fmt*, char*);
void c_fmt_init(ctype_fmt*, void*, ctype_arr*, ctype_fmtopfn);
ctype_status c_fmt_nput(ctype_fmt*, char*, usize);
ctype_status c_fmt_put(ctype_fmt*, char*);

/* utf8 */
ctype_status c_utf8_checkrune(ctype_rune);
i32 c_utf8_charntorune(ctype_rune*, char*, usize);
i32 c_utf8_chartorune(ctype_rune*, char*);

/* ioq */
ctype_status c_ioq_flush(ctype_ioq *);
ctype_status c_ioq_nput(ctype_ioq *, char*, usize);
size c_ioq_vfmt(ctype_ioq *, char*, va_list);
size c_ioq_fmt(ctype_ioq *, char *, ...);

/* str */
usize c_str_len(char*, usize);
i32 c_str_cmp(char*, usize, char*);