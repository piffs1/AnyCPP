/* operator goto */

#include <iostream>

int main(){

    while(true)
    {
        while(true)
            goto lnk;
    }
    lnk:
	return 0;
}
