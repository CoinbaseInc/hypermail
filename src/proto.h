#ifndef __PROTO_H_
#define __PROTO_H_ 1

#include "hypermail.h"

/*
** Date functions - date.c
*/

long convtoyearsecs(char *);
char *getlocaltime(void);
void gettimezone(void);
void getthisyear(void);
char *getdatestr(time_t);
char *secs_to_iso(time_t);
time_t iso_to_secs(char *);
int year_of_datenum(time_t);
int month_of_datenum(time_t);

/*
** domains.c
*/
int valid_root_domain(char *);


/*
** file.c functions
*/

int isdir(char *);
int isfile(char *);
void check1dir(char *);
void checkdir(char *);
char *getfilecontents(char *);
char *add_char(char *, char);
char *add_string(char *, char *);
char *dirpath(char *);

void readconfigs(char *, int);

int find_max_msgnum(void);
int is_empty_archive(void);
void symlink_latest(void);
struct emailsubdir *msg_subdir(int, time_t);
char *msg_href(struct emailinfo *, struct emailinfo *);
char *articlehtmlfilename(struct emailinfo *);
char *htmlfilename(const char *, struct emailinfo *, const char *);
int matches_existing(int);

/*
** hypermail.c functions
*/
void version(void);
void progerr(char *);
void cmderr(char *);
void usage(void);

/*
** lang.c function
*/
char **valid_language(char *);

/*
** lock.c functions
*/
void lock_archive(char *);
void unlock_archive(void);

/*
** mem.c function
*/
void *emalloc(int);

/*
** setup.c functions
*/
#ifdef DEBUG
void dump_config(void);
#endif

/*
** string.c functions
*/
char *PushByte(struct Push *, char);
char *PushString(struct Push *, const char *);
char *PushNString(struct Push *, const char *, int);

char *strsav(const char *);
char *strreplace(char *, char *);
void strcpymax(char *, const char *, int);
char *strcasestr(char *, const char *);
char *stripzone(char *);
int numstrchr(char *, char);
char *getvalue(char *);
char *getconfvalue(char *, char *, char *);
char *unre(char *);
char *oneunre(char *);
int isquote(const char *);
char *replace(char *, char *, char *);
char *replacechar(char *, char, char *);
char *convchars(char *);
char *unconvchars(char *);
char *makemailcommand(char *, char *, char *, char *);
char *parseemail(char *, char *, char *);
char *parseurl(char *);

char *hm_strchr(const char *, int);
void iso2022_state(const char *str, int *state, int *esc);

/*
** quotes.c
*/
const char *get_quote_prefix(void);
const char *find_quote_prefix(struct body *bp, int is_reply);
char *unquote(char *line);
char *remove_hypermail_tags(char *line);
int compute_quoted_percent(struct body *bp);
int is_sig_start(const char *line);

#ifdef lint
int isspace(int);
int isalpha(int);
int isalnum(int);
int isxdigit(int);
#endif

#endif
