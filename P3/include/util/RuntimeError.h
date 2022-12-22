
#define RUNTIME_ERROR(description, parameter)\
            RuntimeError(description, parameter, __FILE__, __LINE__)

extern void RuntimeError(const char* mesage, int parameter, const char* file, int line);