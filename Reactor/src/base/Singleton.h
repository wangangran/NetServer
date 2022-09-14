#include "base/NonCopyable.h"

namespace sunwar {

namespace base {

template<typename T>
class Singleton : NonCopyable {
public:
    static T* instance() {
        static T v;
        return &v;
    }
};

}

}