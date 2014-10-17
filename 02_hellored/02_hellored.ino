#include <PolychrHAUM.h>

/** In this example, the entire led strip is colored in red
 **
 ** At each animation frame, a loop colorizes every led in
 ** red, so that the whole led strip becomes red.
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

void animate() {
	int hsize = khroma.get_halfsize();
	for (int i = -hsize; i <= hsize; ++i)
		khroma.leds.set_rgb(i, 0xFF, 0x00, 0x00);
}

void setup() {
	khroma.config_buttons(PIN__BTN1, PIN__BTN2);
	khroma.config_power(PIN__POWER_CMD, PIN__POWER_STATUS, PIN__POWER_BTN);
	khroma.config_light_ctrl(PIN__POTAR_LIGHT);
	khroma.config_speed_ctrl(PIN__POTAR_SPEED);
	khroma.config_animate(animate);
	khroma.setup();
}

void loop() {
	khroma.loop_step();
}
