

#include <covenant/std.h>

ctype_status
c_fmt_put(ctype_fmt *p, char *s)
{
    usize len;
    len = 0;
    if (s) {
        len = c_str_len(s, -1);
    }
    return c_fmt_nput(p, s, len);
}