#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    printf("+main()\n");

    void *lh = dlopen("/home/meln1337/Documents/os/lab11/lab11/libdll.so", RTLD_LAZY);
    if (!lh)
    {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        exit(1);
    }
    printf("libdll.so is loaded\n");

    int (*fn)() = dlsym(lh, "dll");
    char *error = dlerror();
    if (error)
    {
        fprintf(stderr, "dlsym error: %s\n", error);
        exit(1);
    }
    printf("dll() function is found\n");

    (*fn)();

    printf("unloading libdll.so\n");
    dlclose(lh);

    printf("-main()\n");
    return 0;
}
