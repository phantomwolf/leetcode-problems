#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    void *handle;
    void (*func)(char *);
    char *error;
    
    handle = dlopen("lib/libmysharedlib.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();    /* Clear any existing error */

    /* first function */
    fprintf(stderr, "Loading: first_func...\n");
    func = (void (*)(char *))dlsym(handle, "first_func");
    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    (*func)("baka");

    /* close handle */
    dlclose(handle);
    return 0;
}
