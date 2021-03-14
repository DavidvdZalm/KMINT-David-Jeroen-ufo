#include "kmint/ufo/human.hpp"
#include "kmint/random.hpp"
#include <string>

namespace kmint::ufo {

    namespace {
        constexpr char const *image_path = "resources/human.png";

        graphics::image human_image() { return graphics::image{image_path}; }

        math::vector2d random_location() {
            return {random_scalar(60, 900), random_scalar(60, 700)};
        }



    } // namespace
    human::human()
            : play::free_roaming_actor{ random_location() },
              drawable_{ *this, human_image() } {
    }

    void human::act(delta_time dt) {


        location(location() + velocity * to_seconds(dt));

    }

	math::vector2d human::Seperate() {

    	const std::vector<actor> actors;

		for (auto &actor : actors)
		{
			if (attack->m_num == input)
			{
				attack->makeDamage();
			}
		}

		math::vector2d difference {this->location(). }
    }

	math::vector2d human::cehere() {

    }

	math::vector2d human::align() {

//        for (auto const& e : std::as_const(v)) {
//
//
//		}

    }

    // Calculating distance
	float human::distance(int x1, int y1, int x2, int y2)
	{
		return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
	}

} // namespace kmint::ufo
