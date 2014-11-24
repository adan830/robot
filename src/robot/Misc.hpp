#ifndef __MISC_HPP__
#define __MISC_HPP__

/**
 * unsigned int 10 进制转成 16 进制
 */
int dectohex(char * hex, unsigned int dec) {
    char hexnums[16] = {'0', '1', '2', '3',
                        '4', '5', '6', '7',
                        '8', '9', 'A', 'B',
                        'C', 'D', 'E', 'F'};

    char ret[16] = {0};
    char * p = ret;
    while (dec > 0) {
        *p++ = hexnums[dec & 0xF];
        dec = dec >> 4;
    }

    if (p == ret)
        *p++ = '0';

    *p++ = 'x';
    *p   = '0';
    
    while (p >= ret) {
        *hex++ = *p--;
    }

    *hex = 0;
    
    return 0;
}

#endif

