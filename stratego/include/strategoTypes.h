#ifndef STRATEGO_STRATEGOTYPES_H
#define STRATEGO_STRATEGOTYPES_H

#include <memory>
#include <SDL.h>

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

    struct sdl_deleter {
        void operator()(SDL_Window* p) const { SDL_DestroyWindow(p); }

        void operator()(SDL_Renderer* p) const { SDL_DestroyRenderer(p); }

        void operator()(SDL_Texture* p) const { SDL_DestroyTexture(p); }
    };

    struct coord {
        int x, y;

        coord(int x, int y) : x(x), y(y) {}
    };
}

#endif //STRATEGO_STRATEGOTYPES_H
