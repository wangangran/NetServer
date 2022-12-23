# gcc -fPIC -shared -o libhookMalloc.so HookMalloc.c -ldl
# 运行时LD_PRELOAD=./libhookMalloc.so ./xxx
set(SRC_LIST
 HookMalloc.c
)

add_library(hookMalloc SHARED ${SRC_LIST})
install(TARGETS hookMalloc DESTINATION ${PROJECT_SOURCE_DIR}/lib)