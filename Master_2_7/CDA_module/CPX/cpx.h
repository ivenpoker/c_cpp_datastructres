//
// Created by deathshot on 6/24/18.
//

#ifndef MASTER_2_7_CPX_H
#define MASTER_2_7_CPX_H

/**
 * COMPLEX NUMBER MODULE
 */

typedef struct cpx_num_s {
    double real;
    double img;
} CPX_NUM_t, *CPX_NUM_p_t;

/**
 * Computes the sum of two complex numbers
 * @param cpx1 Pointer to first complex number
 * @param cpx2 Pointer to second complex number.
 * @return A Pointer to a complex number which is the sum of
 *         the two previous complex numbers (parameters).
 */
CPX_NUM_p_t CPX_compute_sum(CPX_NUM_p_t cpx1, CPX_NUM_p_t cpx2);

/**
 * Computes the difference of two complex numbers
 * @param cpx1 Pointer to first complex number
 * @param cpx2 Pointer to second complex number
 * @return A pointer to a complex number which is the sum of
 *         the two previous complex numbers (parameters).
 */
CPX_NUM_p_t CPX_compute_dff(CPX_NUM_p_t cpx1, CPX_NUM_p_t cpx2);

/**
 * Negates the complex number
 * @param cpx Complex number to negate
 * @return A negated complex number
 */
CPX_NUM_p_t CPX_compute_neg(CPX_NUM_p_t cpx);

/**
 * Computes the product of two complex numbers
 * @param cpx1 Pointer to first complex number
 * @param cpx2 Pointer to second complex number
 * @return A pointer to a complex number which is the product of
 *         the two previous complex numbers.
 */
CPX_NUM_p_t CPX_compute_prod(CPX_NUM_p_t cpx1, CPX_NUM_p_t cpx2);

/**
 * Divides two complex number
 * @param cpx1 Pointer to first complex number
 * @param cpx2 Pointer to second complex number
 * @return A pointer to a complex number which is results of the
 *         division of the two previous complex numbers (parameters).
 */
CPX_NUM_p_t CPX_compute_quot(CPX_NUM_p_t cpx1, CPX_NUM_p_t cpx2);

#endif //MASTER_2_7_CPX_H
