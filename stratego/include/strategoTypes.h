#ifndef STRATEGO_STRATEGOTYPES_H
#define STRATEGO_STRATEGOTYPES_H

#include <memory>

namespace stratego {
    // TODO: remove
    class Resources;
    // TODO: end remove

    template<typename T>
    using sptr = std::shared_ptr<T>;
    template<typename T>
    using uptr = std::unique_ptr<T>;
    template<typename T>
    using wptr = std::weak_ptr<T>;

    struct coord {
        int x, y;

        coord(int x=0, int y=0) : x(x), y(y) {}
    };
}

#endif //STRATEGO_STRATEGOTYPES_H
