#include <Arduino.h>

#include <WS2812FX.h>

#define LED_COUNT 5
#define LED_PIN PB3

#define TIMER_MS 5000

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB);




void setup()
{
  ws2812fx.init();
  ws2812fx.setBrightness(255);
  ws2812fx.setSpeed(1000);
  ws2812fx.setColor(GREEN);
  ws2812fx.setMode(FX_MODE_BREATH);
  ws2812fx.start();
}


void led_task()
{
  static unsigned long now = 0;
  static unsigned long last_change = 0;
  now = millis();
  if (now - last_change > TIMER_MS)
  {
    ws2812fx.setMode((ws2812fx.getMode() + 1) % ws2812fx.getModeCount());
    last_change = now;
  }
}

void loop()
{
  ws2812fx.service();
}
