#include "cCONFIG.h"

int main(int argc, char const *argv[]) {
    const char *temp = NULL;
    int res;
    /* Load the config.ini file */
    res = cCONFIG_Parse_Config("example/config.ini.example");
    if (-1 == res)
        exit(0);

    /* Display the loaded config options*/
    cCONFIG_Dump();

    /* Try to get the value by key 'led_model' */
    temp = cCONFIG_Value_Raw("led_model");
    if (temp)
        printf("[Success] value is : <%s>\n", temp);
    else
        printf("[Faild] No result found \n");

    /* Try to get a value with a wrong key*/
    temp = cCONFIG_Value_Raw("abc");
    if (temp)
        printf("[Success] value is : <%s>\n", temp);
    else
        printf("[Faild] No result found \n");

    /* Try to check a boolen value */
    res = cCONFIG_Value_Is_True("on_idle");
    printf("Result is %s \n", res ? "true" : "false");

    /* [Important] Delete before exit */
    cCONFIG_Delete_List();
    return 0;
}