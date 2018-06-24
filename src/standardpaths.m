#include <Cocoa/Cocoa.h>
#include <string.h>
#include <syrup/standardpaths.h>

char * osx_get_path(char *buffer, size_t len) {
    NSArray<NSURL*> *urls = [
        [NSFileManager defaultManager] 
        URLsForDirectory:NSApplicationSupportDirectory 
        inDomains:NSUserDomainMask
    ];

    if ([urls count] == 0) return NULL;

    NSURL *url = urls.firstObject;

    NSString *url_s = [url absoluteString];

    size_t slen =[url_s length];

    if (slen > len) return NULL;

    if (buffer == NULL)
        buffer = malloc(sizeof(char)*slen);
    
    memcpy(buffer, url_s, slen);

    return buffer;
}

static NSSearchPathDirectory sy_stdpath_dir_to_nssearchpath(sy_stdpath_dir dir) {
    switch (dir) {
    case sy_stdpath_data_dir:return NSApplicationSupportDirectory;
    case sy_stdpath_cache_dir: return NSCachesDirectory;
    }
    return 0;
}

static NSSearchPathDomainMask sy_stdpath_domain_to_nssearchpath(sy_stdpath_domain domain) {
    switch (domain) {
    case sy_stdpath_user_domain: return NSUserDomainMask;
    case sy_stdpath_local_domain: return NSLocalDomainMask;
    }
}

char *get_path_osx(char *buffer, size_t len, sy_stdpath_dir dir, sy_stdpath_domain domain) {
    NSArray<NSURL*> *urls = [
        [NSFileManager defaultManager] 
        URLsForDirectory:NSApplicationSupportDirectory 
        inDomains:NSUserDomainMask
    ];

    if ([urls count] == 0) return NULL;

    NSSearchPathDirectory d = sy_stdpath_dir_to_nssearchpath(dir);

    NSString *path = nil;

    if (d == 0) {
        path = [NSHomeDirectory() stringByAppendingPathComponent:@"/Library/Preferences"];
    } else {
        NSArray<NSURL*> *urls = [
            [NSFileManager defaultManager] 
            URLsForDirectory:NSApplicationSupportDirectory 
            inDomains:NSUserDomainMask
        ];

        if ([urls count] == 0) return NULL;

        path = [urls.firstObject absoluteString];
    }

    size_t slen = [path length];

    if (slen > len) return NULL;

    if (buffer == NULL)
        buffer = malloc(sizeof(char)*slen);
    
    memcpy(buffer, path.UTF8String, slen);

    return buffer;

}