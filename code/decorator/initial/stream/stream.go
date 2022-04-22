package stream

type Stream interface {
	Read() string
	Write()
	Seak()
}
