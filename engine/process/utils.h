#define DLL_EXPORT

#ifdef _DEBUG
#define LOG(fmt, ...) \
    do { \
        printf("[LOG] - "fmt"\n", ##__VA_ARGS__); \
    } while (0)
#else
#define LOG(fmt, ...) do {} while (0)
#endif


#ifdef _WIN32
    #ifdef DLL_EXPORT
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#else
    #define ENGINE_API
#endif

#ifdef _DEBUG
#define JZ(x) if(x == 0) printf("[ERROR] - %s returned 0 on file %s at line %d \n",#x,__FILE__,__LINE__)
#else 
#define JZ(x) if(x == 0) return x;
#endif
