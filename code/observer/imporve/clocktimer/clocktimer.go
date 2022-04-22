package clocktimer

import "time"

type Clock interface {
	Show(hour, minute, second int)
	String() string
}

type ClockTimer struct {
	Hour, Minute, Second int
	Observer             map[string]Clock
}

func (c *ClockTimer) AddClock(it Clock) {
	c.Observer[it.String()] = it
}

func (c *ClockTimer) DelClock(it Clock) {
	delete(c.Observer, it.String())
}

func (c *ClockTimer) Ticker() {
	for {
		time.Sleep(time.Second * 1)
		c.Second++
		for _, val := range c.Observer {
			val.Show(c.Hour, c.Minute, c.Second)
		}
	}
}
