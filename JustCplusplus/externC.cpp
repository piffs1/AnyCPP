/* EXTERN C FUNCTIONS */

#include <iostream>
#include <string>
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus
char* strcpy(char*,const char*);
int strcmp(const char*,const char*);
int strlen(const char*);

#ifdef __cplusplus
}
#endif // __cplusplus
using namespace std;

int main(){
    cout << __cplusplus;
	return 0;
}
