#include "kmint/ufo/tank.hpp"
#include "kmint/graphics.hpp"
#include "kmint/ufo/node_algorithm.hpp"
#include "kmint/random.hpp"
#include <iostream>
#include <kmint/ufo/states/tank/roamTankState.h>

namespace kmint::ufo {

namespace {
graphics::image tank_image(tank_type t) {
  constexpr scalar scale = 0.35;
  switch (t) {
  case tank_type::red:
    return graphics::image{"resources/tank_red.png", scale};
  case tank_type::green:
    return graphics::image{"resources/tank_green.png", scale};
  }
  return graphics::image{"resources/tank_green.png", scale};
}


} // namespace

tank::tank(map::map_graph& g, map::map_node& initial_node, tank_type t)
	: play::map_bound_actor{ initial_node }, type_{t},
	drawable_{ *this, graphics::image{tank_image(t)} } {
    this->stateString = "default";
    this->tankBaseFactory->registerState("default", std::make_unique<roamTankState>());
}

void tank::act(delta_time dt) {
	t_since_move_ += dt;
	if (to_seconds(t_since_move_) >= 1) {
		// pick random edge
        this->tankBaseFactory->callTick(this->stateString, *this);
		t_since_move_ = from_seconds(0);
	}
	// laat ook zien wat hij ziet
	for (auto i = begin_perceived(); i != end_perceived(); ++i) {
		auto const& a = *i;
		//std::cout << "Saw something at " << a.location().x() << ", "
		//	<< a.location().y() << "\n";
	}
}

void tank::changeState(const std::string& newState)
{
    this->stateString = newState;
}

void tank::setCurrentNode(int nodeId)
{
    this->node(node()[nodeId].to());
}

play::graph_bound_actor<graph::basic_graph<map::map_node_info>>::node_type& tank::getCurrentNode(){
    return node();
}

} // namespace kmint::ufo
