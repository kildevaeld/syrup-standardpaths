#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  sy_stdpath_user_domain,
  sy_stdpath_local_domain
} sy_stdpath_domain;

typedef enum {
  sy_stdpath_config_dir,
  sy_stdpath_data_dir,
  sy_stdpath_cache_dir
} sy_stdpath_dir;

char *sy_getcwd(char *buffer, size_t maxlen);
char *sy_gethomedir(char *buffer, size_t maxlen);
char *sy_getconfigdir(char *buffer, size_t maxlen);
char *sy_getdatadir(char *buffer, size_t maxlen);
char *sy_getcachedir(char *buffer, size_t maxlen);
char *sy_gettmpdir(char *buffer, size_t maxlen);

char *sy_path_for_dir(sy_stdpath_dir dir, sy_stdpath_domain domain);

#ifdef __cplusplus
}
#endif