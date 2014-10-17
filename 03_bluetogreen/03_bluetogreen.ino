#include <PolychrHAUM.h>

/** In this example, the led strip is colored with a gradient from blue to green
 **
 ** At each animation frame, a loop colorizes every led. In left half, blue is
 ** always 100% while green increases from left to right. In right half, green
 ** is always 100% and blue is decreasing.
 ** There are thus 2 gradiants, from blue to cyan and from cyan to green, which
 ** form a larger gradiant from blue to green.
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
	for (int i = -hsize; i <= hsize; ++i) {
		unsigned char blue, green;
		if (i <= 0) {
			blue = 255;
			green = 255 * (1 + (float(i) / hsize));
		} else {
			blue = 255 * (1 - (float(i) / hsize));
			green = 255;
		}
		khroma.leds.set_rgb(i, 0x00, green, blue);
	}
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
