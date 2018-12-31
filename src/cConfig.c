#include "cConfig.h"

static cConfig *config_list = NULL;

/**
 * @brief: Create a new option entity and attach to the list
 *
 * @param[in] key: Key string
 * @param[in] value: Value string
 *
 * @returns: -1\Error or The number of current config options
 *
 */
 static int cConfig_Create_New_Node(char *key, char *value) {
    int count = 0;
    cConfig *c = config_list;
    cConfig *p = (cConfig *)malloc(NODE_LEN);
    strcpy(p->key, key);
    strcpy(p->value, value);
    p->next = NULL;
    if (config_list == NULL){
        config_list = p;
        return 1;
    }
    else{
        while( NULL != c->next ){
            count++;
            c = c->next;
        }
        c->next = p;
        return count+2;
    }
 }

/**
 * @brief: Create a new option entity and attach to the list
 *
 * @param[in] line: One line from config.ini
 * @param[out] key: Key string
 * @param[out] value: Value string
 *
 * @returns: 0\Not valid 1\valid
 *
 */
static int cConfig_Parse_Line(char *line,  char *key, char *value) {
    char *p, *q;
    if(*line == '#')
        return 0;
    p = strchr(line, '=');
    q = strchr(line, '\0');
    if (p == NULL || q == NULL)
        return 0;
    q = strchr(line, '\n');
    if (q)
        *q = '\0';
    strncpy(key, line, p - line);
    strcpy(value, p+1);
    return 1;
}

/**
 * @brief: Free the memory for saving options
 *
 * @returns: 0\Done -1\Error
 *
 */
void cConfig_Delete_List(void) {
    cConfig *p = config_list;
    cConfig *q = p->next;

    while ( p == config_list && q != NULL ) {
        while ( NULL != q->next ) {
            p = q;
            q = p->next;
        }
        free(q);
        p->next = NULL;
        p = config_list;
        q = p->next;
    }
    free(p);
}

/**
 * @brief: Load a config file
 *
 * @param[in] DIR: Config file
 *
 * @returns: -1\Error or The number of loaded config items
 */
int cConfig_Parse_Config(const char *DIR){
    int i;
    FILE *fd;
    char *temp;
    char buf[ KEY_BUF_LEN + VAL_BUF_LEN ]="";
    char key[KEY_BUF_LEN]="";
    char value[VAL_BUF_LEN]="";

    fd = fopen(DIR, "r");
    if (fd == NULL){
        perror("[Error] Can not open config file");
        return -1;
    }

    do {
        temp = fgets(buf, KEY_BUF_LEN + VAL_BUF_LEN, fd);
        if (cConfig_Parse_Line(buf, key, value))
            cConfig_Create_New_Node(key, value);
        memset(key, 0, strlen(key));
        memset(value, 0, strlen(key));
        memset(buf, 0, strlen(key));
    } while(!feof(fd));
    fclose(fd);
}

/**
 * @brief: Get a value by key (string)
 *
 * @param[in] key: Config key
 *
 * @returns: NULL\No correspond value or The pointer of target string
 */
const char *cConfig_Value_Raw(const char *key){

}

/**
 * @brief: Check if value is true by key
 *
 * @param[in] key: Config key
 *
 * @returns: -1\No correspond value or not true/false string \0 False \1 True
 */
int cConfig_Value_Is_True(const char *key){

}