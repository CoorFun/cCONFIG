#ifndef __cConfig_H__
#define __cConfig_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_BUF_LEN 20
#define VAL_BUF_LEN 50

typedef struct{
    char key[KEY_BUF_LEN];
    char value[VAL_BUF_LEN];
    cConfig *next;
}cConfig;
#define NODE_LEN sizeof(cConfig)

/**
 * @brief: Load a config file
 *
 * @param[in] DIR: Config file
 *
 * @returns: -1\Error or The number of loaded config items
 */
int cConfig_Parse_Config(const char *DIR);

/**
 * @brief: Get a value by key (string)
 *
 * @param[in] key: Config key
 *
 * @returns: NULL\No correspond value or The pointer of target string
 */
const char *cConfig_Value_Raw(const char *key);

/**
 * @brief: Check if value is true by key
 *
 * @param[in] key: Config key
 *
 * @returns: -1\No correspond value or not true/false string \0 False \1 True
 */
int cConfig_Value_Is_True(const char *key);

/**
 * @brief: Free the memory for saving options
 *
 * @returns: 0\Done -1\Error
 *
 */
void cConfig_Delete_List(void);

#endif