#include "documentation_module.h"
#include <stdarg.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

//  int* check_available_documentation_module(int (*validate) (char*), int document_count, ...) {
//
//    int error = 0;
//
//    va_list document;
//
//    va_start (document, document_count);
//
//    if(document_count > 4) {
//        error = 1;
//    }
//    if (error == 0) {
//        while (document_count--) {
//            char* data = va_arg(document, int);
//
//        }
//    }
//
//    va_end (document);
//    return 0;
//}
