package main

import (
	"fmt"
	"time"
)

type DigitalClock struct {
}

func (d *DigitalClock) Show(hour, minute, second int) {
	fmt.Println("DigitalClock Show: ", hour, minute, second)
}

type PointClock struct {
}

func (p *PointClock) Show(hour, minute, second int) {
	fmt.Println("PointClock Show: ", hour, minute, second)
}

type ClockTimer struct {
	hour, minute, second int

	digitalClock *DigitalClock

	pointClock *PointClock
}

func (c *ClockTimer) Ticker() {
	for {
		time.Sleep(time.Second)
		c.second++
		c.digitalClock.Show(c.hour, c.minute, c.second)
		c.pointClock.Show(c.hour, c.minute, c.second)
	}
}

func main() {
	digitalClock := DigitalClock{}
	pointClock := PointClock{}
	timer := ClockTimer{
		digitalClock: &digitalClock,
		pointClock:   &pointClock,
	}

	go timer.Ticker()

	time.Sleep(time.Second * 10)
}
