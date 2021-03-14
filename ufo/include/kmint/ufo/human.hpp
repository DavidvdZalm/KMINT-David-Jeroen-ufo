#ifndef KMINT_UFO_HUMAN_HPP
#define KMINT_UFO_HUMAN_HPP

#include "kmint/play.hpp"
#include <tuple>
#include <vector>

namespace kmint::ufo {

class human : public kmint::play::free_roaming_actor {
public:
  human();
  const ui::drawable& drawable() const override { return drawable_; }
  void act(delta_time dt) override;
  // participates in collisions
  bool incorporeal() const override { return false; }



private:
  play::image_drawable drawable_;
	const int maxSteeringForce = 0.3;
    math::vector2d velocity{};
    math::vector2d acceleration{};
    double perceptionRadius = 100;
	math::vector2d Seperate();
	math::vector2d cehere();
	math::vector2d align();

	float distance(int x1, int y1, int x2, int y2);
};

} // namespace kmint::ufo

#endif /* KMINT_UFO_HUMAN_HPP */
