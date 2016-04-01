/****************************************************************
 *
 *        Copyright 2013, Big Switch Networks, Inc.
 *
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *        http://www.eclipse.org/legal/epl-v10.html
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 ****************************************************************/

/**************************************************************************//**
 *
 * OFConnectionManager Generic uCli Interfaces.
 *
 * Available for Query, Status, and Debug.
 *
 *****************************************************************************/
#include <OFConnectionManager/ofconnectionmanager_config.h>


#if OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI == 1

#include <uCli/ucli.h>
#include <uCli/ucli_argparse.h>
#include <uCli/ucli_handler_macros.h>

#include "ofconnectionmanager_int.h"


static ucli_status_t
ofconnectionmanager_ucli_ucli__config__(ucli_context_t* uc)
{
    UCLI_COMMAND_INFO(uc,
                      "config", 0,
                      "$summary#config command.");
    ucli_printf(uc, "todo: support config command\n");

    return UCLI_STATUS_OK;
}

static ucli_status_t
ofconnectionmanager_ucli_ucli__stats__(ucli_context_t *uc)
{
    char *str;
    int details = 0;

    UCLI_COMMAND_INFO(uc,
                      "stats", -1,
                      "$summary#Show connection stats.");
    if (uc->pargs->count == 1) {
        UCLI_ARGPARSE_OR_RETURN(uc, "s", &str);
        if (!strncmp(str, "detail", 6)) { /* Allow detail or details */
            details = 1;
        } else {
            return UCLI_STATUS_E_ARG;
        }
    } else if (uc->pargs->count > 1) {
        return UCLI_STATUS_E_ARG;
    }

    ind_cxn_stats_show(&uc->pvs, details);

    return UCLI_STATUS_OK;
}

static ucli_status_t
ofconnectionmanager_ucli_ucli__tls__(ucli_context_t *uc)
{
    UCLI_COMMAND_INFO(uc,
                      "tls", 0,
                      "$summary#Show TLS configuration.");

    ind_cxn_tls_config_show(&uc->pvs);

    return UCLI_STATUS_OK;
}


/* <auto.ucli.handlers.start> */
/******************************************************************************
 *
 * These handler table(s) were autogenerated from the symbols in this
 * source file.
 *
 *****************************************************************************/
static ucli_command_handler_f ofconnectionmanager_ucli_ucli_handlers__[] =
{
    ofconnectionmanager_ucli_ucli__config__,
    ofconnectionmanager_ucli_ucli__stats__,
    ofconnectionmanager_ucli_ucli__tls__,
    NULL
};
/******************************************************************************/
/* <auto.ucli.handlers.end> */

static ucli_module_t
ofconnectionmanager_ucli_module__ =
    {
        "ofconnectionmanager_ucli",
        NULL,
        ofconnectionmanager_ucli_ucli_handlers__,
        NULL,
        NULL,
    };


ucli_node_t*
ofconnectionmanager_ucli_node_create(void)
{
    ucli_node_t* n;
    ucli_module_init(&ofconnectionmanager_ucli_module__);
    n = ucli_node_create("ofconnectionmanager", NULL,
                         &ofconnectionmanager_ucli_module__);
    ucli_node_subnode_add(n,
                          ucli_module_log_node_create("ofconnectionmanager"));
    return n;
}

#else
void*
ofconnectionmanager_ucli_node_create(void)
{
    return NULL;
}
#endif