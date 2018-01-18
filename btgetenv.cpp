/*--- made by SKA -----------------------------------------------------------*
 *--- akdotvokchusatgmaildotcom ---------------------------------------------*
 *---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <ctype.h>
#include "btgetenv.h"

int Http_proxy_analyse(const char *url,char *host,int *port)
{
  if (url == NULL) return -1;

  const char *p;
  int r;
  *port = 3128;	/* default proxy port 3128 */
  p = url;
  /* host */
  for(; *p && (isalnum(*p) || *p == '.' || *p == '-'); p++, host++) 
    *host = *p;
  *host = '\0';

  if( *p == ':' ){
    /* port */
    p++;
    for( r = 0; p[r] >= '0' && p[r] <= '9' && r < 6; r++) ;

    if( !r ) return -1;
    *port = atoi(p);
    if(*port > 65536) return -1;
    p += r;
  }
  return 0;
}

