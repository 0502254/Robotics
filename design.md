# Design Document

## Smart Device Theme

>I'm creating an AI controlled helicopter by having most parts of a normal helicopter controlled by AI like the helicopter blades, lights, leaning left and right 


## Behaviours

> Add Behaviours here. Delete this comment.

1. Behaviour 1

## Logic 1

```mermaid
flowchart TD
    Start ([horn])
    getButtonStatus(Get Button Status)
    checkButton{has button been pressed}
    soundHorn(play Sound)
    finish([End])

    Start-->getButtonStatus-->checkButton
    checkButton-->|Yes|soundHorn
    checkButton-->|No|finish
    soundHorn-->finish
```