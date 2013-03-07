/* vim: set ts=2 expandtab: */
/**
 *       @file  olsrd.h
 *      @brief  OLSRd configuration and process management
 *
 *     @author  Josh King (jheretic), jking@chambana.net
 *
 *   @internal
 *     Created  03/07/2013
 *    Revision  $Id: doxygen.commotion.templates,v 0.1 2013/01/01 09:00:00 jheretic Exp $
 *    Compiler  gcc/g++
 *     Company  The Open Technology Institute
 *   Copyright  Copyright (c) 2013, Josh King
 *
 * This file is part of Commotion, Copyright (c) 2013, Josh King 
 * 
 * Commotion is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published 
 * by the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 * 
 * Commotion is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Commotion.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include "process.h"
#include "util.h"

#define OLSR_HNA4 (1 << 0)
#define OLSR_HNA6 (1 << 1)
#define OLSR_IFACE_MESH (1 << 0)
#define OLSR_IFACE_ETHER (1 << 1)

typedef struct {
  co_process_t proto;
} co_olsrd_process_t;

typedef struct {
  char *key;
  char *value;
} co_olsrd_conf_item_t;

typedef struct {
  char *name; 
  co_olsrd_conf_item_t **attr;
  int num_attr;
} co_olsrd_conf_plugin_t;

typedef struct {
  char *ifname;
  int mode;
  char *Ipv4Broadcast;
} co_olsrd_conf_iface_t;

typedef struct {
  int family;
  char *address;
  char *netmask;
} co_olsrd_conf_hna_t;

int co_olsrd_add_iface(const char* name, int mode, const char *Ipv4Broadcast);

int co_olsrd_remove_iface(char* name, int mode, char *Ipv4Broadcast);

int co_olsrd_add_hna(const int family, const char *address, const char *netmask);

int co_olsrd_remove_hna(int family, char *address, char *netmask);

int co_olsrd_print_conf(const char *filename);

int co_olsrd_init(void *self);
