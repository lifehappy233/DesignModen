package main

import "fmt"

type Command interface {
	Run()
}

type Say struct {
	Msg string
}

func (s *Say) Run() {
	fmt.Println("Say", s.Msg)
}

type Do struct {
	Msg string
}

func (d *Do) Run() {
	fmt.Println("Do", d.Msg)
}

type SeqCommand struct {
	Commands []Command
}

func (s *SeqCommand) Run() {
	for _, it := range s.Commands {
		it.Run()
	}
}

func (s *SeqCommand) Addcommand(command Command) {
	s.Commands = append(s.Commands, command)
}

func main() {
	command1 := &Say{"command1"}
	command2 := &Do{"command2"}

	command1.Run()
	command2.Run()

	command3 := &SeqCommand{[]Command{}}
	command3.Addcommand(command1)
	command3.Addcommand(command2)
	command3.Run()
}
