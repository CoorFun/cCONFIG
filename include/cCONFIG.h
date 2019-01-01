#ifndef __cCONFIG_H__
#define __cCONFIG_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_BUF_LEN 20
#define VAL_BUF_LEN 50

typedef struct CONFIG_LIST{
    char key[KEY_BUF_LEN];
    char value[VAL_BUF_LEN];
    struct CONFIG_LIST *next;
}cCONFIG;
#define NODE_LEN sizeof(cCONFIG)

/**
 * @brief: Load a config file
 *
 * @param[in] DIR: Config file
 *
 * @returns: int\ The number of loaded config options
 *            -1\ Error
 */
int cCONFIG_Parse_Config(const char *DIR);

/**
 * @brief: Get a value by key (string)
 *
 * @param[in] key: Config key
 *
 * @returns: const char *\ The pointer of the result string
 *                   NULL\ No correspond value
 */
const char *cCONFIG_Value_Raw(const char *key);

/**
 * @brief: Check if value is true
 *
 * @param[in] key: Config key
 *
 * @returns:  0\ False
 *            1\ True
 *           -1\ No correspond value or it's not a true/false string
 */
int cCONFIG_Value_Is_True(const char *key);

/**
 * @brief: Print all the config options
 */
void cCONFIG_Dump(void);

/**
 * @brief: Free the memory where the loaded config options saved
 */
void cCONFIG_Delete_List(void);
#endif