/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <iostream>
#include <dlfcn.h>
#include <cstring>

#ifdef __linux__
    #define LIB_EXTENSION ".so"
#elif _WIN32
    #define LIB_EXTENSION ".dll"

#endif

template<typename T>
class DLLoader {
    public:
        DLLoader() {};
        T *getInstance(const char *lib, void **handler)
        {
            char *name = addExtension(lib);
            void *handle = dlopen(name, RTLD_LAZY);
            if (!handle) {
                std::cerr << "Erreur ouverture de la lib : " << name << std::endl << dlerror() << std::endl;
                //exit(84);
                return (NULL);
            }
            T *(*func)();
            *(void **) (&func) = dlsym(handle, "entryPoint");
            if (func == NULL) {
                std::cerr << "Erreur lecture de la lib : " << name << std::endl << dlerror() << std::endl;
                //exit(84);
                return (NULL);
            }
            (*handler) = handle;
            return (func());
        };

    protected:
        char *addExtension(const char *name)
        {
            char *res = (char *)malloc(std::strlen(name) + std::strlen(LIB_EXTENSION) + 1);
            size_t i = 0;
            size_t j = 0;

            while (i < std::strlen(name)) {
                res[i] = name[i];
                i++;
            }
            while (j < std::strlen(LIB_EXTENSION)) {
                res[i] = LIB_EXTENSION[j];
                i++;
                j++;
            }
            res[i] = 0;
            return (res);
        }
};

#endif /* !DLLOADER_HPP_ */
