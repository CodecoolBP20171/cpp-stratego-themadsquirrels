#ifndef STRATEGO_STRATEGOTYPES_H
#define STRATEGO_STRATEGOTYPES_H

#include <memory>

namespace stratego {
    // TODO: remove
    class PieceContainer;
    class Resources;
    class Board;
    class DisplayMatrix;
    // TODO: end remove

    template<typename T>
    using sptr = std::shared_ptr<T>;
    template<typename T>
    using uptr = std::unique_ptr<T>;
    template<typename T>
    using wptr = std::weak_ptr<T>;
}

#endif //STRATEGO_STRATEGOTYPES_H
