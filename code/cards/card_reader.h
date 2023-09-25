#ifndef MISC_CARD_READER_H
#define MISC_CARD_READER_H

typedef struct register_s {
    topology_t *tp;
    uint64_t    address;
    uint32_t    bits;
} register_t;

typedef struct card_s {
    topology_t *tps;
    register_t *regs;
} card_t;

#endif //MISC_CARD_READER_H