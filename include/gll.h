/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL
*/

#ifndef GLL
    #define GLL

typedef struct gll_node_s {
    void *data;
    struct gll_node_s *prev;
    struct gll_node_s *next;
} gll_node_t;

typedef struct {
    int size;
    gll_node_t *first;
    gll_node_t *last;
} gll_t;

gll_node_t *gll_find_node(gll_t *list, int pos);
gll_node_t *gll_init_node(void *);
gll_t *gll_init(void);

void *gll_get(gll_t *, int);
void *gll_first(gll_t *);
void *gll_last(gll_t *);

int gll_add(gll_t *, void *, int);
void *gll_set(gll_t *, void *, int);
int gll_push(gll_t *, void *);
int gll_push_back(gll_t *, void *);

void *gll_remove(gll_t *, int);
void *gll_pop(gll_t *);
void *gll_pop_back(gll_t *);

void gll_each(gll_t *, void (*f)(void *));
void gll_each_reverse(gll_t *, void (*f)(void *));

void gll_clear(gll_t *);
void gll_destroy(gll_t *);

#endif /* !GLL */
