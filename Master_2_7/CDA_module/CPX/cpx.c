//
// Created by deathshot on 6/24/18.
//

#include "cpx_p.h"

CPX_NUM_p_t CPX_compute_sum(CPX_NUM_p_t cpx1, CPX_NUM_p_t cpx2) {
    if (cpx1 == NULL) return cpx2;
    if (cpx2 == NULL) return cpx1;

    CPX_NUM_p_t cpx_sum = CDA_NEW(CPX_NUM_t);
    CDA_ASSERT(cpx_sum != NULL);
    cpx_sum->real = cpx1->real + cpx2->real;
    cpx_sum->img  = cpx1->img  + cpx2->img;

    return cpx_sum;
}

CPX_NUM_p_t CPX_compute_dff(CPX_NUM_p_t cpx1, CPX_NUM_p_t cpx2) {
    if (cpx1 == NULL && cpx2 == NULL) return NULL;
    if (cpx1 == NULL) return cpx2;
    if (cpx2 == NULL) return cpx2;

    CPX_NUM_p_t cpx_diff = CDA_NEW(CPX_NUM_t);
    CDA_ASSERT(cpx_diff != NULL);
    cpx_diff->real = cpx1->real - cpx2->real;
    cpx_diff->img  = cpx1->img  - cpx2->img;
}

CPX_NUM_p_t CPX_compute_neg(CPX_NUM_p_t cpx) {
    if (cpx == NULL) return NULL;
    cpx->real = -cpx->real;
    cpx->img  = -cpx->img;
    return cpx;
}

CPX_NUM_p_t CPX_compute_prod(CPX_NUM_p_t cpx1, CPX_NUM_p_t cpx2) {
    if (cpx1 == NULL && cpx2 == NULL) return NULL;
    if (cpx1 == NULL) return cpx2;
    if (cpx2 == NULL) return cpx1;

    CPX_NUM_p_t cpx_prod = CDA_NEW(CPX_NUM_t);
    CDA_ASSERT(cpx_prod != NULL);

    cpx_prod->real = (cpx1->real * cpx2->real) - (cpx1->img * cpx2->img);
    cpx_prod->img  = (cpx1->real * cpx2->img) + (cpx1->img * cpx2->real);

    return cpx_prod;
}

CPX_NUM_p_t CPX_compute_quot(CPX_NUM_p_t cpx1, CPX_NUM_p_t cpx2) {
    if (cpx1 == NULL &&& cpx2 == NULL) return NULL;
    if (cpx1 == NULL) return cpx2;
    if (cpx2 == NULL) return cpx1;

    CPX_NUM_p_t cpx_quot = CDA_NEW(CPX_NUM_t);
    CDA_ASSERT(cpx_quot != NULL);

    cpx_quot->real = cpx1->real / cpx2->real;
    cpx_quot->img  = cpx1->img  / cpx2->img;
}



