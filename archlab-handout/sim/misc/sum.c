// Chet Taylor  netID: tchested
// 24 Feb 2021
// gcc -S sum.c -Og
// ./yas sum.ys
// ./yis sum.yo
// bash handin_archlab.sh to
// collect/pack solution files
// git add archlab-handout
// git commit -m "message"
// git push -u origin main
//

/* linked list element */
typedef struct ELE {
    long val;
    struct ELE *next;
} * list_ptr;

/* sum_list - Sum the elements of a linked list */
long sum_list(list_ptr ls) {
    long val = 0;
    while (ls) {
        val += ls->val;
        ls = ls->next;
    }
    return val;
}

/* rsum_list - Recursive version of sum_list */
long rsum_list(list_ptr ls) {
    if (!ls)
        return 0;
    else {
        long val = ls->val;
        long rest = rsum_list(ls->next);
        return val + rest;
    }
}

/* copy_block - Copy src to dest and return xor checksum of src */
long copy_block(long *src, long *dest, long len) {
    long result = 0;
    while (len > 0) {
        long val = *src++;
        *dest++ = val;
        result ^= val;
        len--;
    }
    return result;
}
