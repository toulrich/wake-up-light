# wake-up-light
Wake Up Light Project based on a NodeMCU

## Elements needed
- NodeMCU
- TM1637 4 Bits Digital LED Display Module For arduino 7 Segment
- Digital LED Strip
- Switch
- Potentiometer

## Functionality
- Wake up dimmer based on alarm set on smartphone (parameters: alarm time, dimmer duration)
- Switch and dimmer for normal nightstand light usage
- Display time on TM1637

## Pseudo code
```
if(D1 == HIGH) //switch is ON
  v_pot = analog.read(A0)
  D0 = PWM(v_pot) //proportional to v_pot

else
  D0 = PWM(v_smartphone) //proportional to smartphone input
```
