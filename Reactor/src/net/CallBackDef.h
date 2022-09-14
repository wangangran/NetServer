#ifndef _CALLBACKDEF_H_
#define _CALLBACKDEF_H_

#include <functional>

namespace sunwar {

namespace net {
    using AcceptHandleRead = std::function<void ()>;
    using EventCallback = std::function<void ()>;
    using NewConnectCallback = std::function<void (int)>;
}

}

#endif