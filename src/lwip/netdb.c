/*
 *  The MIT License (MIT)
 *  Copyright (C) 2020  Seeed Technology Co.,Ltd.
 */

#define TAG "WIFI LWIP"
#include "rpc_wifi_lwip_utils.h"

#include <stdbool.h>
#include <errno.h>
#include "netdb.h"
#include "erpc/erpc_shim_unified.h"
#include "erpc/erpc_port.h"

err_t netconn_gethostbyname(const char * name, ip_addr_t * addr)
{
    FUNC_ENTRY;
    binary_t ip_addr;

    err_t ret = rpc_netconn_gethostbyname(name, &ip_addr);

    memcpy(addr, ip_addr.data, sizeof(ip_addr_t));

    if(ip_addr.data != NULL)
    {
        erpc_free(ip_addr.data);
    }
    return ret;
}

/**
 * Returns an entry containing addresses of address family AF_INET
 * for the host with name name.
 * Due to dns_gethostbyname limitations, only one address is returned.
 *
 * @param name the hostname to resolve
 * @return an entry containing addresses of address family AF_INET
 *         for the host with name name
 */
struct hostent*
lwip_gethostbyname(const char *name)
{
  err_t err;
  ip_addr_t addr;

  /* buffer variables for lwip_gethostbyname() */
  static struct hostent s_hostent;
  static char *s_aliases;
  static ip_addr_t s_hostent_addr;
  static ip_addr_t *s_phostent_addr[2];
  static char s_hostname[DNS_MAX_NAME_LENGTH + 1];

  /* query host IP address */
  err = netconn_gethostbyname(name, &addr);
  if (err != ERR_OK) {
    h_errno = HOST_NOT_FOUND;
    return NULL;
  }

  /* fill hostent */
  s_hostent_addr = addr;
  s_phostent_addr[0] = &s_hostent_addr;
  s_phostent_addr[1] = NULL;
  strncpy(s_hostname, name, DNS_MAX_NAME_LENGTH);
  s_hostname[DNS_MAX_NAME_LENGTH] = 0;
  s_hostent.h_name = s_hostname;
  s_aliases = NULL;
  s_hostent.h_aliases = &s_aliases;
  s_hostent.h_addrtype = AF_INET;
  s_hostent.h_length = sizeof(ip_addr_t);
  s_hostent.h_addr_list = (char**)&s_phostent_addr;

#if DNS_DEBUG
  /* dump hostent */
  LWIP_DEBUGF(DNS_DEBUG, ("hostent.h_name           == %s\n", s_hostent.h_name));
  LWIP_DEBUGF(DNS_DEBUG, ("hostent.h_aliases        == %p\n", (void*)s_hostent.h_aliases));
  /* h_aliases are always empty */
  LWIP_DEBUGF(DNS_DEBUG, ("hostent.h_addrtype       == %d\n", s_hostent.h_addrtype));
  LWIP_DEBUGF(DNS_DEBUG, ("hostent.h_length         == %d\n", s_hostent.h_length));
  LWIP_DEBUGF(DNS_DEBUG, ("hostent.h_addr_list      == %p\n", (void*)s_hostent.h_addr_list));
  if (s_hostent.h_addr_list != NULL) {
    u8_t idx;
    for (idx=0; s_hostent.h_addr_list[idx]; idx++) {
      LWIP_DEBUGF(DNS_DEBUG, ("hostent.h_addr_list[%i]   == %p\n", idx, s_hostent.h_addr_list[idx]));
      LWIP_DEBUGF(DNS_DEBUG, ("hostent.h_addr_list[%i]-> == %s\n", idx, ipaddr_ntoa((ip_addr_t*)s_hostent.h_addr_list[idx])));
    }
  }
#endif /* DNS_DEBUG */

#if LWIP_DNS_API_HOSTENT_STORAGE
  /* this function should return the "per-thread" hostent after copy from s_hostent */
  return sys_thread_hostent(&s_hostent);
#else
  return &s_hostent;
#endif /* LWIP_DNS_API_HOSTENT_STORAGE */
}

