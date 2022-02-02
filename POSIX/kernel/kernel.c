#include "bootparam.h"

bootparam_t *bootp;

/* Scalable Screen Font (https://gitlab.com/bztsrc/scalable-font2) */
typedef struct {
    unsigned char  magic[4];
    unsigned int   size;
    unsigned char  type;
    unsigned char  features;
    unsigned char  width;
    unsigned char  height;
    unsigned char  baseline;
    unsigned char  underline;
    unsigned short fragments_offs;
    unsigned int   characters_offs;
    unsigned int   ligature_offs;
    unsigned int   kerning_offs;
    unsigned int   cmap_offs;
} __attribute__((packed)) ssfn_font_t;

/* font to be used */
unsigned char font_data[8283] = { 83,70,78,50,91,32,0,0,3,0,16,16,12,13,125,0,104,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,86,103,97,32,85,110,105,99,111,100,101,0,86,71,65,0,77,101,100,105,117,109,0,0,66,111,108,107,104,111,118,0,67,111,112,121,114,105,103,104,116,32,40,99,41,32,50,48,48,48,32,68,109,105,116,114,121,32,66,111,108,107,104,111,118,105,116,121,97,110,111,118,44,32,98,111,108,107,104,111,118,64,105,110,112,46,110,115,107,46,115,117,0,128,1,54,54,128,1,54,28,128,1,24,24,128,9,99,99,99,99,99,99,126,96,48,31,128,6,62,99,127,3,3,99,62,128,6,99,115,123,127,111,103,99,128,6,30,48,62,51,51,51,110,128,6,62,99,99,99,99,99,62,128,1,48,24,128,8,99,99,99,99,126,96,96,99,62,128,0,62,128,1,102,102,128,9,60,24,24,24,24,24,24,24,24,60,128,6,28,24,24,24,24,24,60,128,1,102,51,128,8,127,102,70,22,30,22,70,102,127,128,8,99,99,115,123,127,111,103,99,99,128,6,107,107,107,62,107,107,107,128,6,54,99,107,107,107,127,54,128,6,62,99,99,127,99,99,62,128,0,126,128,9,8,28,54,99,99,127,99,99,99,99,128,9,63,102,102,102,62,102,102,102,102,63,128,9,60,102,67,3,3,3,3,67,102,60,128,9,127,102,70,22,30,22,6,70,102,127,128,9,99,99,99,99,127,99,99,99,99,99,128,9,120,48,48,48,48,48,51,51,51,30,128,9,103,102,102,54,30,30,54,102,102,103,128,9,99,119,127,127,107,99,99,99,99,99,128,9,62,99,99,99,99,99,99,99,99,62,128,9,63,102,102,102,62,6,6,6,6,15,128,9,62,99,99,6,28,48,96,99,99,62,128,9,126,126,90,24,24,24,24,24,24,60,128,9,99,99,54,62,28,28,62,54,99,99,128,9,102,102,102,102,60,24,24,24,24,60,128,6,62,99,3,3,3,99,62,128,1,96,96,128,9,112,96,96,96,96,96,96,102,102,60,128,9,59,102,102,102,102,102,62,6,6,15,128,6,62,99,6,28,48,99,62,128,6,51,51,51,51,51,51,110,128,6,99,54,28,28,28,54,99,128,1,12,24,128,6,127,102,70,6,6,6,15,128,6,62,99,96,60,96,99,62,128,6,103,54,30,30,54,102,103,128,6,99,99,99,126,96,96,96,128,6,195,195,195,207,219,219,207,128,6,62,99,96,124,96,99,62,128,1,6,12,128,9,62,99,99,99,127,99,99,99,99,62,128,6,67,99,38,54,28,28,8,128,1,51,102,128,2,32,62,2,128,1,62,42,128,11,99,99,99,99,127,99,99,99,99,227,192,128,128,8,99,99,99,127,99,99,227,192,128,128,8,8,28,54,99,99,127,99,99,99,128,6,62,99,96,96,127,99,62,129,0,252,31,128,9,91,64,1,65,64,1,65,64,1,109,128,9,126,129,165,129,129,189,153,129,129,126,128,9,126,255,219,255,255,195,231,255,255,126,128,7,54,127,127,127,127,62,28,8,128,6,8,28,62,127,62,28,8,128,8,24,60,60,231,231,231,24,24,60,128,8,24,60,126,255,255,126,24,24,60,128,3,24,60,60,24,128,15,255,255,255,255,255,255,231,195,195,231,255,255,255,255,255,255,128,5,60,102,66,66,102,60,128,15,255,255,255,255,255,195,153,189,189,153,195,255,255,255,255,255,128,9,120,112,88,76,30,51,51,51,51,30,128,9,60,102,102,102,102,60,24,126,24,24,128,9,252,204,252,12,12,12,12,14,15,7,128,10,254,198,254,198,198,198,198,230,231,103,3,128,8,24,24,219,60,231,60,219,24,24,128,10,1,3,7,15,31,127,31,15,7,3,1,128,10,64,96,112,120,124,127,124,120,112,96,64,128,8,24,60,126,24,24,24,126,60,24,128,6,102,102,102,102,102,102,102,128,9,254,219,219,219,222,216,216,216,216,216,128,11,62,99,6,28,54,99,99,54,28,48,99,62,128,3,127,127,127,127,128,9,24,60,126,24,24,24,126,60,24,126,128,9,24,60,126,24,24,24,24,24,24,24,128,9,24,24,24,24,24,24,24,126,60,24,128,4,24,48,127,48,24,128,4,12,6,127,6,12,128,3,3,3,3,127,128,4,20,54,127,54,20,128,6,8,28,28,62,62,127,127,128,6,127,127,62,62,28,28,8,128,6,24,60,60,60,24,24,24,128,3,102,102,102,36,128,8,54,54,127,54,54,54,127,54,54,128,13,24,24,62,99,67,3,62,96,96,97,99,62,24,24,128,7,67,99,48,24,12,6,99,97,128,9,28,54,54,28,110,59,51,51,51,110,128,3,12,12,12,4,128,9,48,24,12,12,12,12,12,12,24,48,128,9,12,24,48,48,48,48,48,48,24,12,128,4,102,60,255,60,102,128,4,24,24,126,24,24,128,3,24,24,24,12,128,0,127,128,7,64,96,48,24,12,6,3,1,128,9,28,54,99,99,107,107,99,99,54,28,128,9,24,28,30,24,24,24,24,24,24,126,128,9,62,99,96,48,24,12,6,3,99,127,128,9,62,99,96,96,60,96,96,96,99,62,128,9,48,56,60,54,51,127,48,48,48,120,128,9,127,3,3,3,63,96,96,96,99,62,128,9,28,6,3,3,63,99,99,99,99,62,128,9,127,99,96,96,48,24,12,12,12,12,128,9,62,99,99,99,62,99,99,99,99,62,128,9,62,99,99,99,126,96,96,96,48,30,128,2,24,24,12,128,8,96,48,24,12,6,12,24,48,96,128,8,6,12,24,48,96,48,24,12,6,128,6,62,99,99,48,24,24,24,128,8,62,99,99,123,123,123,59,3,62,128,9,31,54,102,102,102,102,102,102,54,31,128,9,127,102,70,22,30,22,6,6,6,15,128,9,60,102,67,3,3,123,99,99,102,92,128,9,15,6,6,6,6,6,6,70,102,127,128,9,99,103,111,127,123,115,99,99,99,99,128,11,62,99,99,99,99,99,99,107,123,62,48,112,128,9,63,102,102,102,62,54,102,102,102,103,128,9,99,99,99,99,99,99,99,99,99,62,128,9,99,99,99,99,99,99,99,54,28,8,128,9,99,99,99,99,107,107,107,127,119,54,128,9,127,99,97,48,24,12,6,67,99,127,128,9,60,12,12,12,12,12,12,12,12,60,128,8,1,3,7,14,28,56,112,96,64,128,9,60,48,48,48,48,48,48,48,48,60,128,3,8,28,54,99,128,0,255,128,2,12,12,24,128,9,7,6,6,30,54,102,102,102,102,62,128,9,56,48,48,60,54,51,51,51,51,110,128,9,28,54,38,6,15,6,6,6,6,15,128,9,110,51,51,51,51,51,62,48,51,30,128,9,7,6,6,54,110,102,102,102,102,103,128,9,7,6,6,102,54,30,30,54,102,103,128,9,28,24,24,24,24,24,24,24,24,60,128,6,55,127,107,107,107,107,99,128,6,59,102,102,102,102,102,102,128,9,110,51,51,51,51,51,62,48,48,120,128,6,59,110,102,6,6,6,15,128,9,8,12,12,63,12,12,12,12,108,56,128,6,102,102,102,102,102,60,24,128,6,99,99,107,107,107,127,54,128,6,127,51,24,12,6,99,127,128,9,112,24,24,24,14,24,24,24,24,112,128,11,24,24,24,24,24,24,24,24,24,24,24,24,128,9,14,24,24,24,112,24,24,24,24,14,128,1,110,59,128,6,8,28,54,99,99,99,127,128,11,127,77,12,124,204,204,204,204,204,204,192,96,128,8,127,102,70,6,6,6,6,6,15,128,9,60,102,67,3,31,3,3,67,102,60,128,8,60,24,24,24,24,24,24,24,60,128,9,30,27,27,27,123,219,219,219,219,123,128,9,27,27,27,27,127,219,219,219,219,123,128,9,127,77,12,124,204,204,204,204,204,204,128,8,103,102,102,54,30,54,102,102,103,128,12,99,99,99,99,99,99,99,99,99,127,28,8,8,128,9,127,102,70,6,62,102,102,102,102,63,128,9,127,102,70,6,6,6,6,6,6,15,128,11,60,54,54,54,54,54,54,54,54,127,99,65,128,9,107,107,107,62,28,62,107,107,107,107,128,9,62,99,97,96,60,96,96,97,99,62,128,9,99,99,99,115,123,127,111,103,99,99,128,11,54,28,99,99,99,115,123,127,111,103,99,99,128,9,124,102,102,102,102,102,102,102,102,99,128,9,127,99,99,99,99,99,99,99,99,99,128,9,99,99,99,99,99,126,96,96,99,62,128,9,8,62,107,107,107,107,107,62,8,8,128,11,51,51,51,51,51,51,51,51,51,127,96,64,128,9,99,99,99,99,99,126,96,96,96,96,128,9,99,107,107,107,107,107,107,107,107,127,128,11,99,107,107,107,107,107,107,107,107,255,192,128,128,9,31,13,13,12,60,108,108,108,108,62,128,9,195,195,195,195,207,219,219,219,219,207,128,9,15,6,6,6,62,102,102,102,102,63,128,9,30,51,97,96,124,96,96,97,51,30,128,9,57,109,109,109,111,109,109,109,109,57,128,9,126,51,51,51,62,54,54,54,54,115,128,9,96,62,3,3,63,99,99,99,99,62,128,6,63,102,102,62,102,102,63,128,8,60,54,54,54,54,54,127,99,65,128,6,124,102,102,102,102,102,99,128,6,99,119,127,127,107,99,99,128,6,99,99,99,127,99,99,99,128,6,127,99,99,99,99,99,99,128,6,126,90,24,24,24,24,60,128,10,8,62,107,107,107,107,107,62,8,8,8,128,8,51,51,51,51,51,51,127,96,64,128,6,99,107,107,107,107,107,127,128,8,99,107,107,107,107,107,255,192,128,128,6,31,13,12,60,108,108,62,128,6,15,6,6,62,102,102,63,128,6,57,109,109,111,109,109,57,128,6,126,51,51,62,54,54,115,128,12,6,31,6,54,110,102,102,102,102,103,96,96,56,128,6,62,99,3,31,3,99,62,128,6,30,27,27,123,219,219,123,128,6,27,27,27,127,219,219,123,128,9,6,31,6,54,110,102,102,102,102,103,128,9,99,99,99,99,99,99,127,28,8,8,128,9,54,99,99,107,107,107,107,107,127,54,128,9,12,63,45,12,60,108,108,108,108,62,128,9,12,12,12,63,45,12,60,108,108,62,128,9,115,219,155,27,127,27,27,155,219,115,128,6,115,219,27,127,27,219,115,128,9,8,28,28,54,54,54,127,107,107,107,128,6,8,28,28,54,62,107,107,128,9,17,49,57,105,111,109,253,213,215,215,128,6,17,49,57,111,125,213,215,128,9,127,99,54,54,28,62,107,107,107,107,128,6,127,99,54,62,107,107,107,128,9,255,197,77,105,63,57,125,85,213,215,128,6,253,197,105,127,213,213,215,128,13,54,28,8,62,99,96,96,62,96,96,96,62,3,62,128,2,54,28,8,128,8,62,97,96,62,96,96,62,3,62,128,9,8,105,107,107,107,107,107,62,8,8,128,12,8,8,8,105,107,107,107,107,107,62,8,8,8,128,9,67,99,99,35,51,54,22,30,28,12,128,8,67,99,35,35,54,22,30,28,12,128,12,14,27,27,219,219,219,219,219,219,246,192,96,56,128,9,206,219,219,219,219,219,246,192,96,56,128,11,8,62,107,99,99,99,99,99,99,107,62,8,128,8,8,62,107,99,99,99,107,62,8,128,11,32,62,2,54,99,99,107,107,107,107,127,54,128,8,54,99,99,107,107,107,107,127,54,128,12,60,102,67,3,3,3,3,3,6,60,48,48,48,128,8,62,99,3,3,3,3,30,24,24,128,9,96,96,60,240,24,24,15,60,6,6,128,2,24,36,34,128,2,2,62,2,128,2,32,62,32,128,1,24,102,128,0,195,128,1,102,24,128,2,16,10,98,128,1,65,130,128,2,70,80,8,128,13,54,28,99,99,99,115,123,127,111,103,99,227,192,128,128,8,99,115,123,127,111,103,227,192,128,128,10,6,15,6,6,6,62,102,102,102,102,63,128,7,6,15,6,6,62,102,102,63,128,9,63,102,118,38,94,6,6,6,6,15,128,9,59,102,102,102,118,38,94,6,6,15,128,11,64,96,127,6,6,6,6,6,6,6,6,15,128,8,64,96,127,6,6,6,6,6,15,128,9,127,102,70,6,31,6,6,6,6,15,128,6,127,102,70,31,6,6,15,128,12,127,102,70,6,62,102,102,102,102,111,96,104,48,128,9,127,102,70,30,54,102,111,96,104,48,128,11,107,107,107,62,28,62,107,107,107,235,192,128,128,8,107,107,107,62,107,107,235,192,128,128,12,62,99,97,96,60,96,96,97,99,62,12,6,28,128,9,62,99,96,60,96,99,62,12,6,28,128,11,103,102,102,54,30,30,54,102,102,231,192,128,128,8,103,54,30,30,54,102,231,192,128,128,9,99,107,107,59,31,59,107,107,99,99,128,6,99,107,59,31,59,107,99,128,9,103,102,111,54,30,30,54,102,102,103,128,9,7,6,15,102,54,30,30,54,102,103,128,9,207,205,205,108,60,60,108,204,204,206,128,6,207,109,61,60,108,204,206,128,9,251,219,155,27,31,27,27,27,27,27,128,6,251,219,155,31,27,27,27,128,12,31,27,27,27,123,219,219,219,219,219,192,208,96,128,9,27,27,27,127,219,219,219,192,208,96,128,9,62,67,51,107,107,107,107,107,51,94,128,6,62,67,51,107,107,51,94,128,12,60,102,67,3,3,3,3,67,102,60,24,48,28,128,9,62,99,3,3,3,99,62,24,48,28,128,11,126,126,90,24,24,24,24,24,24,60,48,32,128,8,126,90,24,24,24,24,60,48,32,128,9,102,102,102,102,102,60,24,24,24,60,128,9,102,102,102,102,60,24,126,24,24,60,128,9,102,102,102,102,102,60,24,126,24,60,128,11,99,99,54,62,28,28,62,54,99,227,192,128,128,8,99,54,28,28,28,54,227,192,128,128,11,111,102,102,102,102,102,102,102,102,254,192,128,128,8,111,102,102,102,102,102,254,192,128,128,11,99,99,99,99,99,126,96,96,96,224,192,128,128,8,99,99,99,126,96,96,224,192,128,128,9,99,99,99,107,107,126,104,104,96,96,128,6,99,107,107,126,104,104,96,128,9,3,3,3,3,63,99,99,99,99,99,128,6,3,3,3,63,99,99,99,128,9,120,204,205,205,254,12,12,12,204,120,128,6,121,205,254,12,12,204,120,128,12,120,204,205,205,254,12,12,12,204,120,48,24,112,128,9,121,205,254,12,12,204,120,48,24,112,128,11,54,28,107,107,107,62,28,62,107,107,107,107,128,12,103,102,102,54,30,30,54,102,102,103,96,104,48,128,9,103,54,30,30,54,102,103,96,104,48,128,11,124,102,102,102,102,102,102,102,102,227,192,128,128,8,124,102,102,102,102,102,227,192,128,128,12,99,99,99,99,127,99,99,99,99,99,96,104,48,128,9,99,99,99,127,99,99,99,96,104,48,128,11,99,99,99,99,99,126,96,96,96,112,48,16,128,8,99,99,99,126,96,96,112,48,16,128,11,99,119,127,127,107,99,99,99,99,227,192,128,128,8,99,119,127,127,107,99,227,192,128,128,9,124,54,51,51,127,51,51,51,51,115,128,6,51,110,108,126,27,27,118,128,9,62,99,96,96,96,127,99,99,99,62,128,8,62,99,96,96,127,99,99,99,62,128,8,107,107,107,62,28,62,107,107,107,128,8,62,99,97,96,60,96,97,99,62,128,9,127,96,48,24,60,96,96,97,99,62,128,9,127,96,48,24,60,96,96,96,99,62,128,8,62,99,99,99,99,99,99,99,62,128,8,62,99,99,99,127,99,99,99,62,128,8,30,51,97,96,124,96,97,51,30,128,8,99,99,99,99,126,96,96,96,96,128,8,195,195,195,207,219,219,219,219,207,129,15,64,0,64,0,224,15,16,4,28,2,32,1,192,2,48,1,142,31,64,16,48,8,76,4,128,2,128,1,112,0,14,0,129,15,16,4,56,4,15,4,8,4,136,63,191,36,136,36,140,36,156,36,170,63,170,36,9,4,8,4,8,4,8,4,8,4,129,2,64,0,128,0,255,127,129,4,252,31,4,16,4,16,252,31,4,16,129,14,226,63,4,2,4,2,192,31,0,17,7,17,228,127,4,0,4,0,196,31,68,16,84,16,76,16,196,31,64,16,0,1,8,16,8,0,0,2,149,2,0,0,1,8,16,8,0,0,2,161,2,0,0,1,8,16,8,0,0,2,173,2,0,0,1,8,16,8,0,0,4,185,2,0,0,1,8,16,8,0,0,4,195,2,0,0,1,8,16,8,0,0,3,204,2,0,0,1,8,16,8,0,0,3,215,2,0,0,1,8,16,8,0,0,6,226,2,0,0,1,8,16,8,0,0,0,232,2,0,0,1,8,16,8,0,0,5,250,2,0,0,1,8,16,8,0,0,0,2,3,0,0,1,8,16,8,0,0,2,20,3,0,0,1,8,16,8,0,0,2,32,3,0,0,1,8,16,8,0,0,2,44,3,0,0,1,8,16,8,0,0,2,56,3,0,0,1,8,16,8,0,0,3,69,3,0,0,1,8,16,8,0,0,1,80,3,0,0,1,8,16,8,0,0,1,93,3,0,0,1,8,16,8,0,0,2,106,3,0,0,2,8,16,8,0,0,2,117,3,0,0,10,203,0,0,0,1,8,16,8,0,0,2,126,3,0,0,1,8,16,8,0,0,1,138,3,0,0,1,8,16,8,0,0,8,152,3,0,0,1,8,16,8,0,0,2,158,3,0,0,1,8,16,8,0,0,2,170,3,0,0,1,8,16,8,0,0,2,182,3,0,0,1,8,16,8,0,0,5,194,3,0,0,1,8,16,8,0,0,5,201,3,0,0,1,8,16,8,0,0,6,208,3,0,0,1,8,16,8,0,0,5,214,3,0,0,1,8,16,8,0,0,4,221,3,0,0,1,8,16,8,0,0,4,230,3,0,0,0,8,16,8,0,0,2,8,16,8,0,0,2,239,3,0,0,10,133,0,0,0,1,8,16,8,0,0,1,248,3,0,0,1,8,16,8,0,0,3,254,3,0,0,1,8,16,8,0,0,0,9,4,0,0,1,8,16,8,0,0,4,25,4,0,0,1,8,16,8,0,0,2,35,4,0,0,1,8,16,8,0,0,1,47,4,0,0,1,8,16,8,0,0,2,53,4,0,0,1,8,16,8,0,0,2,65,4,0,0,1,8,16,8,0,0,5,77,4,0,0,1,8,16,8,0,0,5,84,4,0,0,1,8,16,8,0,0,9,91,4,0,0,1,8,16,8,0,0,7,97,4,0,0,1,8,16,8,0,0,10,133,0,0,0,1,8,16,8,0,0,4,100,4,0,0,1,8,16,8,0,0,2,110,4,0,0,1,8,16,8,0,0,2,122,4,0,0,1,8,16,8,0,0,2,134,4,0,0,1,8,16,8,0,0,2,146,4,0,0,1,8,16,8,0,0,2,158,4,0,0,1,8,16,8,0,0,2,170,4,0,0,1,8,16,8,0,0,2,182,4,0,0,1,8,16,8,0,0,2,194,4,0,0,1,8,16,8,0,0,2,206,4,0,0,1,8,16,8,0,0,2,218,4,0,0,2,8,16,8,0,0,4,133,0,0,0,9,133,0,0,0,2,8,16,8,0,0,4,133,0,0,0,9,230,4,0,0,1,8,16,8,0,0,3,235,4,0,0,2,8,16,8,0,0,5,25,1,0,0,8,25,1,0,0,1,8,16,8,0,0,3,246,4,0,0,2,8,16,8,0,0,2,1,5,0,0,10,133,0,0,0,1,8,16,8,0,0,3,10,5,0,0,1,8,16,8,0,0,2,28,1,0,0,1,8,16,8,0,0,2,40,1,0,0,1,8,16,8,0,0,2,52,1,0,0,1,8,16,8,0,0,2,21,5,0,0,1,8,16,8,0,0,2,64,1,0,0,1,8,16,8,0,0,2,33,5,0,0,1,8,16,8,0,0,2,45,5,0,0,1,8,16,8,0,0,2,76,1,0,0,1,8,16,8,0,0,2,207,0,0,0,1,8,16,8,0,0,2,88,1,0,0,1,8,16,8,0,0,2,100,1,0,0,1,8,16,8,0,0,2,57,5,0,0,1,8,16,8,0,0,2,112,1,0,0,1,8,16,8,0,0,2,69,5,0,0,1,8,16,8,0,0,2,124,1,0,0,1,8,16,8,0,0,2,136,1,0,0,1,8,16,8,0,0,2,81,5,0,0,1,8,16,8,0,0,2,95,5,0,0,1,8,16,8,0,0,2,148,1,0,0,1,8,16,8,0,0,2,160,1,0,0,1,8,16,8,0,0,2,107,5,0,0,1,8,16,8,0,0,2,119,5,0,0,1,8,16,8,0,0,2,131,5,0,0,1,8,16,8,0,0,2,172,1,0,0,1,8,16,8,0,0,2,184,1,0,0,1,8,16,8,0,0,2,143,5,0,0,1,8,16,8,0,0,2,155,5,0,0,1,8,16,8,0,0,3,167,5,0,0,1,8,16,8,0,0,2,178,5,0,0,1,8,16,8,0,0,0,190,5,0,0,1,8,16,8,0,0,13,196,5,0,0,1,8,16,8,0,0,0,199,5,0,0,1,8,16,8,0,0,5,167,0,0,0,1,8,16,8,0,0,2,204,5,0,0,1,8,16,8,0,0,5,196,1,0,0,1,8,16,8,0,0,2,216,5,0,0,1,8,16,8,0,0,5,149,0,0,0,1,8,16,8,0,0,2,228,5,0,0,1,8,16,8,0,0,5,240,5,0,0,1,8,16,8,0,0,2,252,5,0,0,2,8,16,8,0,0,2,133,0,0,0,5,219,0,0,0,2,8,16,8,0,0,2,205,1,0,0,5,209,1,0,0,1,8,16,8,0,0,2,8,6,0,0,1,8,16,8,0,0,2,20,6,0,0,1,8,16,8,0,0,5,32,6,0,0,1,8,16,8,0,0,5,41,6,0,0,1,8,16,8,0,0,5,176,0,0,0,1,8,16,8,0,0,5,221,1,0,0,1,8,16,8,0,0,5,50,6,0,0,1,8,16,8,0,0,5,62,6,0,0,1,8,16,8,0,0,5,233,1,0,0,1,8,16,8,0,0,2,71,6,0,0,1,8,16,8,0,0,5,242,1,0,0,1,8,16,8,0,0,5,83,6,0,0,1,8,16,8,0,0,5,92,6,0,0,1,8,16,8,0,0,5,251,1,0,0,1,8,16,8,0,0,5,137,0,0,0,1,8,16,8,0,0,5,101,6,0,0,1,8,16,8,0,0,2,110,6,0,0,1,8,16,8,0,0,2,122,6,0,0,1,8,16,8,0,0,2,136,6,0,0,1,8,16,8,0,0,2,148,6,0,0,1,8,16,8,0,0,4,152,6,0,159,0,0,0,0,0,16,192,84,0,2,8,16,8,0,0,2,125,0,0,0,5,176,0,0,192,121,0,2,8,16,8,0,0,2,228,0,0,0,5,242,1,0,194,141,0,2,8,16,8,0,0,0,4,2,0,0,3,232,0,0,0,2,8,16,8,0,0,0,125,0,0,0,3,232,0,0,0,1,8,16,8,0,0,2,161,6,0,0,2,8,16,8,0,0,0,185,0,0,0,3,175,6,0,0,1,8,16,8,0,0,2,186,6,0,0,1,8,16,8,0,0,2,148,1,0,0,1,8,16,8,0,0,2,207,0,0,0,2,8,16,8,0,0,0,203,0,0,0,3,198,6,0,0,1,8,16,8,0,0,2,88,1,0,0,1,8,16,8,0,0,2,209,6,0,0,1,8,16,8,0,0,2,221,6,0,0,1,8,16,8,0,0,2,233,6,0,0,2,8,16,8,0,0,0,185,0,0,0,3,245,6,0,0,2,8,16,8,0,0,0,4,2,0,0,3,243,0,0,0,2,8,16,8,0,0,0,129,0,0,0,3,189,0,0,0,1,8,16,8,0,0,2,0,7,0,0,1,8,16,8,0,0,2,28,1,0,0,1,8,16,8,0,0,2,15,7,0,0,1,8,16,8,0,0,2,40,1,0,0,1,8,16,8,0,0,2,27,7,0,0,1,8,16,8,0,0,2,39,7,0,0,1,8,16,8,0,0,2,64,1,0,0,1,8,16,8,0,0,2,53,7,0,0,1,8,16,8,0,0,2,65,7,0,0,1,8,16,8,0,0,2,77,7,0,0,1,8,16,8,0,0,0,89,7,0,0,1,8,16,8,0,0,2,100,1,0,0,1,8,16,8,0,0,2,103,7,0,0,1,8,16,8,0,0,2,112,1,0,0,1,8,16,8,0,0,2,76,1,0,0,1,8,16,8,0,0,2,124,1,0,0,1,8,16,8,0,0,2,115,7,0,0,1,8,16,8,0,0,2,136,1,0,0,1,8,16,8,0,0,2,52,1,0,0,1,8,16,8,0,0,2,160,1,0,0,1,8,16,8,0,0,2,127,7,0,0,1,8,16,8,0,0,2,139,7,0,0,1,8,16,8,0,0,2,172,1,0,0,1,8,16,8,0,0,2,151,7,0,0,1,8,16,8,0,0,2,165,7,0,0,1,8,16,8,0,0,2,177,7,0,0,1,8,16,8,0,0,2,189,7,0,0,1,8,16,8,0,0,2,203,7,0,0,1,8,16,8,0,0,2,215,7,0,0,1,8,16,8,0,0,2,227,7,0,0,1,8,16,8,0,0,2,239,7,0,0,1,8,16,8,0,0,2,251,7,0,0,1,8,16,8,0,0,2,7,8,0,0,1,8,16,8,0,0,5,167,0,0,0,1,8,16,8,0,0,2,19,8,0,0,1,8,16,8,0,0,5,31,8,0,0,1,8,16,8,0,0,5,8,2,0,0,1,8,16,8,0,0,5,40,8,0,0,1,8,16,8,0,0,5,149,0,0,0,1,8,16,8,0,0,5,254,0,0,0,1,8,16,8,0,0,5,17,2,0,0,1,8,16,8,0,0,5,158,0,0,0,2,8,16,8,0,0,2,129,0,0,0,5,158,0,0,0,1,8,16,8,0,0,5,26,2,0,0,1,8,16,8,0,0,5,51,8,0,0,1,8,16,8,0,0,5,60,8,0,0,1,8,16,8,0,0,5,69,8,0,0,1,8,16,8,0,0,5,176,0,0,0,1,8,16,8,0,0,5,78,8,0,0,1,8,16,8,0,0,5,221,1,0,0,1,8,16,8,0,0,5,196,1,0,0,1,8,16,8,0,0,5,87,8,0,0,1,8,16,8,0,0,5,137,0,0,0,1,8,16,8,0,0,4,96,8,0,0,1,8,16,8,0,0,5,251,1,0,0,1,8,16,8,0,0,5,109,8,0,0,1,8,16,8,0,0,5,35,2,0,0,1,8,16,8,0,0,5,120,8,0,0,1,8,16,8,0,0,5,129,8,0,0,1,8,16,8,0,0,5,140,8,0,0,1,8,16,8,0,0,5,44,2,0,0,1,8,16,8,0,0,5,149,8,0,0,1,8,16,8,0,0,5,53,2,0,0,1,8,16,8,0,0,5,158,8,0,0,1,8,16,8,0,0,5,167,8,0,0,2,8,16,8,0,0,2,62,2,0,0,5,149,0,0,0,2,8,16,8,0,0,2,125,0,0,0,5,149,0,0,0,1,8,16,8,0,0,2,176,8,0,0,2,8,16,8,0,0,2,185,0,0,0,5,8,2,0,0,1,8,16,8,0,0,5,191,8,0,0,1,8,16,8,0,0,5,233,1,0,0,2,8,16,8,0,0,2,133,0,0,0,5,219,0,0,0,2,8,16,8,0,0,2,203,0,0,0,5,219,0,0,0,2,8,16,8,0,0,2,205,1,0,0,5,209,1,0,0,1,8,16,8,0,0,5,200,8,0,0,1,8,16,8,0,0,5,209,8,0,0,1,8,16,8,0,0,2,218,8,0,0,2,8,16,8,0,0,2,185,0,0,0,5,26,2,0,0,2,8,16,8,0,0,2,62,2,0,0,5,158,0,0,0,2,8,16,8,0,0,2,129,0,0,0,5,137,0,0,0,1,8,16,8,0,0,5,230,8,0,0,1,8,16,8,0,0,2,242,8,0,0,1,8,16,8,0,0,5,7,1,0,0,1,8,16,8,0,0,2,254,8,0,0,1,8,16,8,0,0,2,10,9,0,0,1,8,16,8,0,0,2,22,9,0,0,1,8,16,8,0,0,5,34,9,0,0,1,8,16,8,0,0,2,43,9,0,0,1,8,16,8,0,0,5,55,9,0,0,1,8,16,8,0,0,2,64,9,0,0,1,8,16,8,0,0,5,76,9,0,0,1,8,16,8,0,0,2,85,9,0,0,1,8,16,8,0,0,5,97,9,0,0,1,8,16,8,0,0,2,106,9,0,0,1,8,16,8,0,0,5,118,9,0,0,1,8,16,8,0,0,0,127,9,0,0,2,8,16,8,0,0,1,143,9,0,0,5,148,9,0,0,1,8,16,8,0,0,2,159,9,0,0,1,8,16,8,0,0,2,171,9,0,0,1,8,16,8,0,0,2,66,2,0,0,1,8,16,8,0,0,5,16,1,0,0,1,8,16,8,0,0,2,186,9,0,0,1,8,16,8,0,0,5,78,2,0,0,2,8,16,8,0,0,0,87,2,0,0,3,198,9,0,0,2,8,16,8,0,0,2,87,2,0,0,5,78,2,0,0,1,8,16,8,0,0,2,209,9,0,0,1,8,16,8,0,0,5,224,9,0,0,1,8,16,8,0,0,1,236,9,0,0,1,8,16,8,0,0,4,250,9,0,0,1,8,16,8,0,0,0,5,10,0,0,2,8,16,8,0,0,1,91,2,0,0,5,7,1,0,0,2,8,16,8,0,0,0,96,2,0,0,3,19,10,0,0,2,8,16,8,0,0,2,96,2,0,0,5,7,1,0,0,1,8,16,8,0,0,2,30,10,0,0,1,8,16,8,0,0,5,45,10,0,0,1,8,16,8,0,0,2,56,10,0,0,1,8,16,8,0,0,1,91,2,0,0,1,8,16,8,0,0,1,68,10,0,0,1,8,16,8,0,0,1,73,10,0,0,1,8,16,8,0,0,1,78,10,0,128,0,3,8,16,8,0,0,3,83,10,0,0,6,87,10,0,0,8,90,10,0,0,3,8,16,8,0,0,2,94,10,0,0,6,99,10,0,0,9,103,10,0,0,1,8,16,8,0,0,0,108,10,0,0,2,8,16,8,0,0,2,129,0,0,0,5,124,10,0,0,1,8,16,8,0,0,1,135,10,0,0,1,8,16,8,0,0,4,148,10,0,0,1,8,16,8,0,0,2,158,10,0,0,1,8,16,8,0,0,5,170,10,0,0,1,8,16,8,0,0,0,182,10,0,0,1,8,16,8,0,0,3,196,10,0,0,1,8,16,8,0,0,2,207,10,0,0,1,8,16,8,0,0,5,219,10,0,0,1,8,16,8,0,0,2,228,10,0,0,1,8,16,8,0,0,5,243,10,0,0,1,8,16,8,0,0,2,255,10,0,0,1,8,16,8,0,0,5,13,11,0,0,1,8,16,8,0,0,2,24,11,0,0,1,8,16,8,0,0,5,39,11,0,0,1,8,16,8,0,0,2,51,11,0,0,1,8,16,8,0,0,5,65,11,0,0,1,8,16,8,0,0,2,76,11,0,0,1,8,16,8,0,0,5,88,11,0,0,1,8,16,8,0,0,2,97,11,0,0,1,8,16,8,0,0,2,109,11,0,0,1,8,16,8,0,0,2,121,11,0,0,1,8,16,8,0,0,5,133,11,0,0,1,8,16,8,0,0,2,100,2,0,0,1,8,16,8,0,0,5,114,2,0,0,1,8,16,8,0,0,2,142,11,0,0,1,8,16,8,0,0,5,154,11,0,0,1,8,16,8,0,0,2,163,11,0,0,1,8,16,8,0,0,5,178,11,0,0,1,8,16,8,0,0,2,190,11,0,0,1,8,16,8,0,0,5,202,11,0,0,1,8,16,8,0,0,2,211,11,0,0,1,8,16,8,0,0,5,226,11,0,0,1,8,16,8,0,0,2,238,11,0,0,1,8,16,8,0,0,5,252,11,0,0,1,8,16,8,0,0,2,184,1,0,0,1,8,16,8,0,0,5,7,12,0,0,1,8,16,8,0,0,2,19,12,0,0,1,8,16,8,0,0,5,31,12,0,0,1,8,16,8,0,0,2,43,12,0,0,1,8,16,8,0,0,5,57,12,0,0,1,8,16,8,0,0,2,68,12,0,0,1,8,16,8,0,0,5,82,12,0,0,1,8,16,8,0,0,2,93,12,0,0,1,8,16,8,0,0,5,107,12,0,0,1,8,16,8,0,0,2,118,12,0,0,1,8,16,8,0,0,5,130,12,0,0,1,8,16,8,0,0,2,139,12,0,0,1,8,16,8,0,0,5,151,12,0,0,1,8,16,8,0,0,2,160,12,0,0,1,8,16,8,0,0,5,172,12,0,0,1,8,16,8,0,0,2,181,12,0,0,1,8,16,8,0,0,5,196,12,0,0,1,8,16,8,0,0,2,207,0,0,0,1,8,16,8,0,0,0,208,12,0,0,2,8,16,8,0,0,2,129,0,0,0,5,254,0,0,0,1,8,16,8,0,0,2,222,12,0,0,1,8,16,8,0,0,5,237,12,0,0,1,8,16,8,0,0,2,249,12,0,0,1,8,16,8,0,0,5,7,13,0,0,1,8,16,8,0,0,2,18,13,0,0,1,8,16,8,0,0,5,33,13,0,0,1,8,16,8,0,0,2,100,2,0,0,1,8,16,8,0,0,5,114,2,0,0,1,8,16,8,0,0,2,45,13,0,0,1,8,16,8,0,0,5,59,13,0,0,1,8,16,8,0,0,2,70,13,0,0,1,8,16,8,0,0,5,84,13,0,128,0,2,8,16,8,0,0,0,129,0,0,0,3,125,2,0,0,2,8,16,8,0,0,2,129,0,0,0,5,167,0,0,0,2,8,16,8,0,0,0,125,0,0,0,3,125,2,0,0,2,8,16,8,0,0,2,125,0,0,0,5,167,0,0,0,1,8,16,8,0,0,2,95,13,0,0,1,8,16,8,0,0,5,107,13,0,0,2,8,16,8,0,0,0,129,0,0,0,3,232,0,0,0,2,8,16,8,0,0,2,129,0,0,0,5,149,0,0,0,1,8,16,8,0,0,2,116,13,0,0,1,8,16,8,0,0,5,136,2,0,0,2,8,16,8,0,0,0,125,0,0,0,3,128,13,0,0,2,8,16,8,0,0,2,125,0,0,0,5,136,2,0,0,2,8,16,8,0,0,0,125,0,0,0,3,139,13,0,0,2,8,16,8,0,0,2,125,0,0,0,5,254,0,0,0,2,8,16,8,0,0,0,125,0,0,0,3,150,13,0,0,2,8,16,8,0,0,2,125,0,0,0,5,17,2,0,0,1,8,16,8,0,0,2,161,13,0,0,1,8,16,8,0,0,5,173,13,0,0,2,8,16,8,0,0,1,200,0,0,0,3,243,0,0,0,2,8,16,8,0,0,3,200,0,0,0,5,158,0,0,0,2,8,16,8,0,0,0,125,0,0,0,3,243,0,0,0,2,8,16,8,0,0,2,125,0,0,0,5,158,0,0,0,2,8,16,8,0,0,0,125,0,0,0,3,185,13,0,0,2,8,16,8,0,0,2,125,0,0,0,5,176,0,0,0,1,8,16,8,0,0,2,66,2,0,0,1,8,16,8,0,0,5,16,1,0,0,2,8,16,8,0,0,0,125,0,0,0,3,196,13,0,0,2,8,16,8,0,0,2,125,0,0,0,5,16,1,0,0,2,8,16,8,0,0,0,125,0,0,0,3,207,13,0,0,2,8,16,8,0,0,2,125,0,0,0,5,53,2,0,0,2,8,16,8,0,0,1,200,0,0,0,3,189,0,0,0,2,8,16,8,0,0,3,200,0,0,0,5,137,0,0,0,2,8,16,8,0,0,0,125,0,0,0,3,189,0,0,0,2,8,16,8,0,0,2,125,0,0,0,5,137,0,0,0,2,8,16,8,0,0,0,228,0,0,0,3,189,0,0,0,2,8,16,8,0,0,2,228,0,0,0,5,137,0,0,0,2,8,16,8,0,0,0,125,0,0,0,3,218,13,0,0,2,8,16,8,0,0,2,125,0,0,0,5,35,2,0,129,0,2,8,16,8,0,0,0,125,0,0,0,3,229,13,0,0,2,8,16,8,0,0,2,125,0,0,0,5,44,2,0,254,255,213,31,0,1,16,16,16,0,0,0,240,13,0,224,177,0,1,16,16,16,0,0,0,18,14,0,208,49,0,4,16,16,16,0,0,0,52,14,0,0,5,145,2,0,0,8,145,2,0,0,11,60,14,0,193,235,0,1,16,16,16,0,0,1,72,14,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,255,245,18,50,78,70,83 };
ssfn_font_t *font = (ssfn_font_t*)&font_data;

/**
 * Display string using a bitmap font without the SSFN library
 */
void printString(int x, int y, char *s)
{
    unsigned char *ptr, *chr, *frg;
    unsigned int c;
    unsigned long long int o, p;
    int i, j, k, l, m, n;
    while(*s) {
        if((*s & 128) != 0) {
            if(!(*s & 32)) { c = ((*s & 0x1F)<<6)|(*(s+1) & 0x3F); s += 1; } else
            if(!(*s & 16)) { c = ((*s & 0xF)<<12)|((*(s+1) & 0x3F)<<6)|(*(s+2) & 0x3F); s += 2; } else
            if(!(*s & 8)) { c = ((*s & 0x7)<<18)|((*(s+1) & 0x3F)<<12)|((*(s+2) & 0x3F)<<6)|(*(s+3) & 0x3F); s += 3; }
            else c = 0;
        } else c = *s;
        s++;
        if(c == '\r') { x = 0; continue; } else
        if(c == '\n') { x = 0; y += font->height; continue; }
        for(ptr = (unsigned char*)font + font->characters_offs, chr = 0, i = 0; i < 0x110000; i++) {
            if(ptr[0] == 0xFF) { i += 65535; ptr++; }
            else if((ptr[0] & 0xC0) == 0xC0) { j = (((ptr[0] & 0x3F) << 8) | ptr[1]); i += j; ptr += 2; }
            else if((ptr[0] & 0xC0) == 0x80) { j = (ptr[0] & 0x3F); i += j; ptr++; }
            else { if((unsigned int)i == c) { chr = ptr; break; } ptr += 6 + ptr[1] * (ptr[0] & 0x40 ? 6 : 5); }
        }
        if(!chr) continue;
        ptr = chr + 6; o = (unsigned long long int)bootp->framebuffer + y * bootp->pitch + x * 4;
        for(i = n = 0; i < chr[1]; i++, ptr += chr[0] & 0x40 ? 6 : 5) {
            if(ptr[0] == 255 && ptr[1] == 255) continue;
            frg = (unsigned char*)font + (chr[0] & 0x40 ? ((ptr[5] << 24) | (ptr[4] << 16) | (ptr[3] << 8) | ptr[2]) :
                ((ptr[4] << 16) | (ptr[3] << 8) | ptr[2]));
            if((frg[0] & 0xE0) != 0x80) continue;
            o += (int)(ptr[1] - n) * bootp->pitch; n = ptr[1];
            k = ((frg[0] & 0x1F) + 1) << 3; j = frg[1] + 1; frg += 2;
            for(m = 1; j; j--, n++, o += bootp->pitch)
                for(p = o, l = 0; l < k; l++, p += 4, m <<= 1) {
                    if(m > 0x80) { frg++; m = 1; }
                    if(*frg & m) *((unsigned int*)p) = 0xFFFFFF;
                }
        }
        x += chr[4]+1; y += chr[5];
    }
}

/**
 * Example "kernel"
 */
void _start(bootparam_t *bootpar)
{
    int i;
    bootp = bootpar;
    for(i = 0; i < bootp->width * bootp->height; i++)
        bootp->framebuffer[i] = 0x000008;

    printString(10, 10, "Hello from \"kernel\". I got arguments:");
    for(i = 0; i < bootp->argc; i++)
        printString(20, 10 + (i + 1) * font->height, bootp->argv[i]);

    /* there's nowhere to return to, hang */
    while(1);
}