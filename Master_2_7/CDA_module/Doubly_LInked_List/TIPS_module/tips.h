//
// Created by deathshot on 6/23/18.
//

#ifndef MASTER_2_7_TIPS_H
#define MASTER_2_7_TIPS_H

/**
 * Adds a receipt to internal data structure
 * @param waitress Name of waitress
 * @param check check associated to waitress
 * @param tip tip associated to waitress
 */
void TIPS_add_receipt(const char *waitress, double check, double tip);

/**
 * Close TIPS module.
 */
void TIPS_close(void);

/**
 * Initializes the TIPS module
 */
void TIPS_init(void);

/**
 * Prints all receipts found in the TIPS module in alphabetical order
 */
void TIPS_print_receipts(void);

#endif //MASTER_2_7_TIPS_H
