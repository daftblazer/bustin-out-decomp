/* C-compiled helpers inside the Flash player's interpreter unit (8014A18C),
   -O0, see tools/tu_ui_c.sh. URL-query decoding for loadVariables/getURL. */

extern long fn_80111AB0(const char* s, char** end, int base);   /* strtol */
extern unsigned long fn_80111FF8(const char* s);                /* strlen */
extern int fn_80112210(const char* a, const char* b, unsigned long n); /* strncmp */
extern char* fn_801122F0(char* d, const char* s, unsigned long n);     /* strncpy */

/* two hex digits to a byte */
char fn_8014E9F0(const char* p)
{
    char buf[3];
    long v;
    buf[0] = p[0];
    buf[1] = p[1];
    buf[2] = 0;
    v = fn_80111AB0(buf, 0, 16);
    return v;
}

/* decode '+' and %XX in place */
void fn_8014EA70(char* s)
{
    int j = 0;
    int i = 0;
    while (s[i] != 0) {
        if (s[i] == '+') {
            s[j] = ' ';
        } else if (s[i] == '%') {
            s[j] = fn_8014E9F0(&s[i + 1]);
            i += 2;
        } else {
            s[j] = s[i];
        }
        j++;
        i++;
    }
    s[j] = 0;
}

/* split one "name=value&" pair off the query string; returns the rest, or 0 */
char* fn_8014EBAC(register void* unused, char* query, char* name, char* value)
{
    char* p = query;
    char* eq = 0;
    while (p && *p && *p != '&') {
        if (*p == '=')
            eq = p;
        p++;
    }
    if (eq) {
        fn_801122F0(name, query, eq - query);
        name[eq - query] = 0;
        fn_8014EA70(name);
        eq++;
        fn_801122F0(value, eq, p - eq);
        value[p - eq] = 0;
        fn_8014EA70(value);
        if (*p == '&')
            p++;
    } else {
        p = 0;
    }
    return p;
}

extern char* lbl_8037BF70;                                   /* "FSCommand:" */
extern void (*lbl_8033D1E0[16])(const char*, const char*);   /* host callbacks */

/* does the URL start with "FSCommand:" ? */
int fn_8014ED30(register void* self, const char* url)
{
    if (fn_80112210(url, lbl_8037BF70, fn_80111FF8(lbl_8037BF70)) == 0)
        return 1;
    return 0;
}

/* pass "FSCommand:command" and its argument to the host */
int fn_8014ED9C(register void* self, const char* url, const char* arg)
{
    url += fn_80111FF8(lbl_8037BF70);
    lbl_8033D1E0[11](url, arg);
    return 1;
}

extern int fn_8012C7C8(void* obj);   /* type tag */
extern int fn_8012C8A4(void* obj);

void* fn_8014EF7C(register void* p)
{
    do { return p; } while (0);
}

int fn_8014EFDC(register void* p)
{
    register int r = 0;
    do {
        if (fn_8012C7C8(p) == 8 && fn_8012C8A4(p) == 0)
            r = 1;
        return r;
    } while (0);
}
