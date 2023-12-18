#include <ylt/coro_rpc/coro_rpc_server.hpp>

inline std::string_view echo(std::string_view str) { return str; }

int main() {
    coro_rpc::coro_rpc_server server(10, 9000);
    server.register_handler<echo>();
    server.start();
}