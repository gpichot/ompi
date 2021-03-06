/*
 * Copyright (c) 2013      Mellanox Technologies, Inc.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "params.h"
#include "runtime.h"
#include "oshmem/constants.h"


bool oshmem_shmem_abort_print_stack = false;
int oshmem_shmem_abort_delay = 0;
int oshmem_shmem_lock_recursive = 0;
int oshmem_shmem_api_verbose = 0;
int oshmem_preconnect_all = 0;

int oshmem_shmem_register_params(void)
{
    oshmem_shmem_abort_delay = 0;
    (void) mca_base_var_register("oshmem",
                                 "oshmem",
                                 NULL,
                                 "abort_delay",
                                "If nonzero, print out an identifying message when abort is invoked (hostname, PID of the process that called abort operation) and delay for that many seconds before exiting (a negative delay value means to never abort).  This allows attaching of a debugger before quitting the job.",
                                 MCA_BASE_VAR_TYPE_INT, NULL, 0, 0,
                                 OPAL_INFO_LVL_9,
                                 MCA_BASE_VAR_SCOPE_READONLY,
                                 &oshmem_shmem_abort_delay);

    oshmem_shmem_abort_print_stack = false;
    (void) mca_base_var_register("oshmem",
                                 "oshmem",
                                 NULL,
                                 "abort_print_stack",
                                 "If nonzero, print out a stack trace when abort is invoked",
                                 MCA_BASE_VAR_TYPE_BOOL, NULL, 0,
                                 0,
                                 OPAL_INFO_LVL_9,
                                 MCA_BASE_VAR_SCOPE_READONLY,
                                 &oshmem_shmem_abort_print_stack);

    (void) mca_base_var_register("oshmem",
                                 "oshmem",
                                 NULL,
                                 "lock_recursive",
                                 "Whether or not distributed locking support recursive calls (default = no)",
                                 MCA_BASE_VAR_TYPE_INT,
                                 NULL,
                                 0,
                                 MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_9,
                                 MCA_BASE_VAR_SCOPE_READONLY,
                                 &oshmem_shmem_lock_recursive);

    (void) mca_base_var_register("oshmem",
                                 "oshmem",
                                 NULL,
                                 "api_verbose",
                                 "Verbosity level of the shmem c functions (default = 0)",
                                 MCA_BASE_VAR_TYPE_INT,
                                 NULL,
                                 0,
                                 MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_9,
                                 MCA_BASE_VAR_SCOPE_READONLY,
                                 &oshmem_shmem_api_verbose);

    (void) mca_base_var_register("oshmem",
                                 "oshmem",
                                 NULL,
                                 "preconnect_all",
                                 "Whether to force SHMEM processes to fully "
                                 "wire-up the connections between SHMEM "
                                 "processes during "
                                 "initialization (vs. making connections lazily -- "
                                 "upon the first SHMEM traffic between each "
                                 "process peer pair)",
                                 MCA_BASE_VAR_TYPE_INT,
                                 NULL,
                                 0,
                                 MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_9,
                                 MCA_BASE_VAR_SCOPE_READONLY,
                                 &oshmem_preconnect_all);

    return OSHMEM_SUCCESS;
}
