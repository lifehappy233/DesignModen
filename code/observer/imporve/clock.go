package main

import (
	"fmt"
	"time"

	"design.model/observer/imporve/clocktimer"
)

type PointClock struct {
}

func (p *PointClock) Show(hour, minute, second int) {
	fmt.Println("PointClock Show: ", hour, minute, second)
}

func (P *PointClock) String() string {
	return "PointClock"
}

type DigitalClock struct {
}

func (d *DigitalClock) Show(hour, minute, second int) {
	fmt.Println("DigitalClock Show: ", hour, minute, second)
}

func (d *DigitalClock) String() string {
	return "DigitalClock"
}

func main() {
	timer := clocktimer.ClockTimer{
		Observer: make(map[string]clocktimer.Clock),
	}

	digitalClock := DigitalClock{}
	pointClock := PointClock{}

	timer.AddClock(&digitalClock)
	timer.AddClock(&pointClock)

	go timer.Ticker()
	time.Sleep(10 * time.Second)
}
