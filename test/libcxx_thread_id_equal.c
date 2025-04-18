/* This file is part of MCF Gthread.
 * Copyright (C) 2022-2025 LH_Mouse. All wrongs reserved.
 *
 * MCF Gthread is free software. Licensing information is included in
 * LICENSE.TXT as a whole. The GCC Runtime Library Exception applies
 * to this file.  */

#include "../mcfgthread/libcxx.h"
#include <assert.h>
#include <stdio.h>

static __libcpp_thread_t thrd;
static _MCF_mutex mtx = __MCF_0_INIT;

static
void*
thread_proc(void* param)
  {
    (void) param;
    _MCF_mutex_lock(&mtx, __MCF_nullptr);
    assert(__libcpp_thread_id_equal(__MCF_libcxx_thread_get_current_id(), __libcpp_thread_get_id(&thrd)));
    assert(__libcpp_thread_id_equal(__MCF_libcxx_thread_get_current_id(), _MCF_thread_self_tid()));

    fprintf(stderr, "thread %d quitting\n", (int) _MCF_thread_self_tid());
    return __MCF_nullptr;
  }

int
main(void)
  {
    _MCF_mutex_lock(&mtx, __MCF_nullptr);
    int r = __libcpp_thread_create(&thrd, thread_proc, __MCF_nullptr);
    _MCF_mutex_unlock(&mtx);
    assert(r == 0);
    assert(thrd);

    assert(!__libcpp_thread_id_equal(__MCF_libcxx_thread_get_current_id(), __libcpp_thread_get_id(&thrd)));

    fprintf(stderr, "main waiting\n");
    r = __libcpp_thread_join(&thrd);
    assert(r == 0);
    fprintf(stderr, "main wait finished\n");
  }
