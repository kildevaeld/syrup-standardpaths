#include <syrup/features.h>

static const char *_sy_platform_name = SY_PLATFORM_NAME;

const char *sy_platform_name() { return _sy_platform_name; }