#ifndef KMINT_UFO_TANK_HPP
#define KMINT_UFO_TANK_HPP

#include <kmint/ufo/states/tank/tankBaseState.h>
#include <kmint/ufo/states/tank/tankStateFactory.h>
#include "kmint/map/map.hpp"
#include "kmint/play.hpp"
#include "kmint/primitives.hpp"

namespace kmint {
namespace ufo {

enum class tank_type { red, green };

class tank : public play::map_bound_actor {
public:
  tank(map::map_graph& g, map::map_node& initial_node, tank_type t);
  // wordt elke game tick aangeroepen
  void act(delta_time dt) override;
  ui::drawable const& drawable() const override { return drawable_; }
  // als incorporeal false is, doet de actor mee aan collision detection
  bool incorporeal() const override { return false; }
  // geeft de lengte van een zijde van de collision box van deze actor terug.
  // Belangrijk voor collision detection
  scalar collision_range() const override { return 16.0; }
  // geeft aan dat de tank andere actors kan zien
  bool perceptive() const override { return true; }
  // geeft het bereik aan waarbinnen een tank
  // andere actors kan waarnemen.
  scalar perception_range() const override { return 200.f; }
  void changeState(const std::string& newState);
  void setCurrentNode(int nodeId);
  play::graph_bound_actor<graph::basic_graph<map::map_node_info>>::node_type& getCurrentNode();

private:
  play::image_drawable drawable_;
  delta_time t_since_move_{};
  tank_type type_;
  std::unique_ptr<tankStateFactory> tankBaseFactory {std::make_unique<tankStateFactory>()};
  std::string stateString;
};

} // namespace ufo
} // namespace kmint

#endif /* KMINT_UFO_TANK_HPP */
