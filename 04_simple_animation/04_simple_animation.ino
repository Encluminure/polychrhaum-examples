#include <PolychrHAUM.h>

/** In this example, two purple points travel from middle to extremities
 **
 ** A linear animator is started on setup. Position of each point is
 ** computed from animator value. Since animator values changes with
 ** time, position is updated and finally colored point seems to travel.
 **/

#ifdef BUILD_PC
#define A0 0
#define A1 1
#endif

#define PIN__BTN1          2
#define PIN__BTN2          3
#define PIN__POWER_BTN     4
#define PIN__POWER_CMD     5
#define PIN__POWER_STATUS  6
#define PIN__LEDSTRIP_DATA 10
#define PIN__POTAR_LIGHT   A0
#define PIN__POTAR_SPEED   A1

PolychrHAUM <150, PIN__LEDSTRIP_DATA> khroma;
LinearAnimator animator;

void animate() {
	animator.animate();
	int hsize = khroma.get_halfsize();
	int pos = animator * (hsize + 1); // +1 is to counter rounding
	khroma.leds.set_rgb(-pos, 0xFF, 0, 0xFF);
	khroma.leds.set_rgb(+pos, 0xFF, 0, 0xFF);
}

void setup() {
	khroma.config_buttons(PIN__BTN1, PIN__BTN2);
	khroma.config_power(PIN__POWER_CMD, PIN__POWER_STATUS, PIN__POWER_BTN);
	khroma.config_light_ctrl(PIN__POTAR_LIGHT);
	khroma.config_speed_ctrl(PIN__POTAR_SPEED);
	khroma.config_animate(animate);
	khroma.setup();

	animator.set_duration(3000);
	animator.loop(true);
	animator.start();
}

void loop() {
	khroma.loop_step();
}
