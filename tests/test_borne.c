#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

#include "test_borne.h"


int testBorne(){
    BorneElectrique tableauBornes[] = {
        {1, 2, 5, 48.8566, 2.3522},
        {2, 1, 3, 49.1833, -0.3594},
        {3, 0, 4, 45.7640, 4.8357},
        {4, 2, 2, 43.2965, 5.3698},
        {5, 1, 3, 48.1173, -1.6778}
    };

    printf("%d", distance(tableauBornes, 0, 0));
    return EXIT_SUCCESS;
}

